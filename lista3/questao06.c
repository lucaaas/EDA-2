#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

const int SIZE_NUMBERS = 10003;

// sorts a small group with insertion sort
// group has 5 itens or less
void sort_group(int *numbers, int i, int group_size) {

	for (int j = i + 1; j < i + group_size; j++) {
		int k = j;
		while ((k > i) && (numbers[k] < numbers[k-1])) {
			int aux = numbers[k-1];
			numbers[k-1] = numbers[k];
			numbers[k] = aux;
			k--;
		}
	}
}

// breaks numbers into groups of five itens
// last group may be not complete
void divide_groups(int *numbers, int size) {

	int i = 0;

	/*  if size = 14
	 *  two groups of 5 itens
	 *  last group has 4 itens
	 */

	for (i = 0; i <= (size - 7); i = i + 7) {
		sort_group(numbers, i, 7);
	}

	int last_size = size % 7; // last group size

	if (last_size > 0) {
		sort_group(numbers, i, last_size);
	}
	else {
		// do nothing, there is no incomplete group
	}

}

// prints numbers in groups of five itens
// each line is a group
// last line may be incomplete
void print_numbers(int *numbers, int size) {

	for (int i = 0; i < size; i = i + 7) {
		for (int j = 0; (j < 7) && (i + j < size); j++) {
			printf("%d ", numbers[i + j]);
		}
		printf("\n");
	}

	printf("\n");
}

// initiates a array with random numbers
// guarantees only different numbers
void randomize_input(int *input_numbers, int size){

	// numbers are generated from 0 to MAX_NUMBER-1
	const int MAX_NUMBER = SIZE_NUMBERS * 5;

	// array to mark already generated numbers
	int generated[MAX_NUMBER];

	// marks all numbers as "not generated"
	for (int i = 0; i < MAX_NUMBER; i++) {
		generated[i] = FALSE;
	}

	// generates a different number for each position
	for (int i = 0; i < size; i++) {

        int is_different = FALSE;
        int rand_number = 0;

		// wait for a different number
		do {
			rand_number = rand() % MAX_NUMBER;

			if (generated[rand_number] == FALSE) {
				is_different = TRUE;
				generated[rand_number] = TRUE;
			}
		} while (!is_different);

		// finally initiates position with different number
		input_numbers[i] = rand_number;
	}
}

// copy median of each group to a second array
// caution with last group
void medians_copy(int *source, int source_size, int *destiny, int destiny_size) {

	int number_of_complete_groups = source_size / 7;
    int i = 0;

	// copy medians of complete groups
	for (i = 0; i < number_of_complete_groups; i++) {
		destiny[i] = source[i * 7 + 2];
	}

	// from now on, deals with last group

	int last_group_size = source_size % 7;

	if (last_group_size > 0) {

	    // last group first position
	    int first_position = i * 7;

		int last_median = 0;

		// defines position of last median accordingly to group size
		// extract its value
		switch (last_group_size) {
			case 1:
			case 2:
				last_median = source[first_position];
				break;
			case 3:
			case 4:
				last_median = source[first_position + 1];
				break;
			case 5:
			case 6:
				last_median = source[first_position + 2];
				break;
			default: // last group is not bigger than 6 itens
				assert(FALSE);
				break;
		}

		// copy last median to second array
		destiny[destiny_size - 1] = last_median;
	}
	else {
		// do nothing, has only complete groups
	}
}

// copies left or right partition to a new array
int* partition_copy(int *source, int start, int end) {

	int destiny_size = (end + 1) - start;
	int *destiny = (int*) malloc(sizeof(int)*(destiny_size));

	for (int i = start; i <= end; i++) {
		destiny[i - start] = source[i];
	}

	return destiny;
}

// simple swap of two numbers of array
void swap(int *input, int first_index, int second_index) {
	int aux = input[first_index];
	input[first_index] = input[second_index];
	input[second_index] = aux;
}

// finds first occurence of value
int find_index(int *input, int size, int value) {

	int value_index = -1;

	for (int i = 0; i < size; i++) {
		if (input[i] == value) {
			value_index = i;
			break;
		}
	}

	return value_index;
}

// smallers numbers to the left, bigger numbers to the right
// [small numbers][mom][bigger numbers]
// has problems with very small input, 1 or 2 itens
void partition_numbers_around_mom (int *input_numbers,
                                   int input_numbers_size,
								   int median_of_medians) {

    // short-circuit, fix me!
	if (input_numbers_size == 2) {
		if (input_numbers[0] > input_numbers[1]) {
			swap(input_numbers, 0, 1);
		}
		return;
	}
	else if (input_numbers_size == 1) {
		return;
	}

	int mom_index = find_index(input_numbers, input_numbers_size, median_of_medians);
	swap(input_numbers, 0, mom_index);

	int i = 1;
	int j = input_numbers_size - 1;

	while (i < j) {

		// finds a greater in the left side
		while (input_numbers[i] < median_of_medians) {
			i++;
		}

		// finds a smaller in the right side
		while (input_numbers[j] > median_of_medians) {
			j--;
		}

		swap(input_numbers, i, j);
	}

	// both numbers on the middle are inverted
	// mom is at index 0
	swap(input_numbers, 0, i-1);
	swap(input_numbers, 0, i);

	print_numbers(input_numbers, input_numbers_size);
}

// oracle implements Median of Medians algorithm
int ask_oracle_for_median(int *input_numbers, int input_numbers_size) {

	divide_groups(input_numbers, input_numbers_size);
	print_numbers(input_numbers, input_numbers_size);

	int last_medians_size = input_numbers_size / 7;

	if ((input_numbers_size % 7) > 0) {
		last_medians_size = last_medians_size + 1;
	}
	else {
		// do nothing
	}

	int *last_medians = (int*) malloc(sizeof(int)*(last_medians_size));
	medians_copy(input_numbers, input_numbers_size, last_medians, last_medians_size);

	while (last_medians_size > 1) {

		printf("LastMedian\n");
		print_numbers(last_medians, last_medians_size);

		divide_groups(last_medians, last_medians_size);

		printf("Sorted LastMedian\n");
	    print_numbers(last_medians, last_medians_size);

		int current_medians_size = 0;

		if ((last_medians_size % 7) > 0) {
			current_medians_size = (last_medians_size / 7) + 1;
		}
		else {
			current_medians_size = last_medians_size / 7;
		}

	    int *current_medians = (int*) malloc(sizeof(int)*(current_medians_size));

		medians_copy(last_medians, last_medians_size, current_medians, current_medians_size);

		free(last_medians);

		last_medians = current_medians;
		last_medians_size = current_medians_size;
	}

	return last_medians[0]; // this is the Median of Medians
}

/* asks the oracle for a good candidate to be the median
   partition numbers around median
   checks if candidate is real median
   if not, select left or right partition
 */
int exoteric_select (int *input_numbers, int input_numbers_size, int k_esimo) {

	printf("Exoteric Select\n");
	printf("K_esimo: %d\n", k_esimo);

	int mom = ask_oracle_for_median(input_numbers, input_numbers_size);

	partition_numbers_around_mom(input_numbers, input_numbers_size, mom);
	int mom_index = find_index(input_numbers, input_numbers_size, mom);

	printf("Median: %d\n", mom);
	printf("Median index: %d\n\n", mom_index);

	int expected_size = k_esimo;
	int median = -1;

	if (mom_index > expected_size) {

		// oracle guessed too high

		printf("Recursive on L\n");

		int left_size = mom_index;

		int *left_partition = partition_copy(input_numbers, 0, left_size - 1);
		printf("Left partition:\n");
		print_numbers(left_partition, left_size);

		median = exoteric_select(left_partition, left_size, k_esimo);
	}
	else if (mom_index < expected_size) {

		// oracle guessed too low

		printf("Recursive on R\n");

		int right_size = (input_numbers_size - 1) - mom_index;
		int partition_start = mom_index + 1;

		int *right_partition = partition_copy(input_numbers, partition_start, input_numbers_size - 1);
		printf("Right partition:\n");
		print_numbers(right_partition, right_size);

		k_esimo = k_esimo - (mom_index + 1);
		median = exoteric_select(right_partition, (input_numbers_size - 1) - mom_index, k_esimo);
	}
	else {

		// oracle is correct!

		printf("Median is %d.\n", mom);
		printf("Index is %d.\n", mom_index);
		median = mom;
	}

	return median;
}

// runs 200 times
// compares exoteric_select/MOM with the median of sorted input
int main(int argc, char *argv[]) {

    int times_correct = 0;

	for (int i = 0; i < 200; i++) {

	    srand(time(NULL));

		int input_numbers_size = SIZE_NUMBERS;
		assert(input_numbers_size > 0);

		int *input_numbers = (int*) malloc(sizeof(int)*(input_numbers_size));

		randomize_input(input_numbers, input_numbers_size);

		// creates copy of input
		// finds median cheating - sorts the input, O(n^2)
		int *aux = partition_copy(input_numbers, 0, input_numbers_size - 1);
		sort_group(aux, 0, input_numbers_size); // sort_group also works with large groups

		printf("Input\n");
		printf("Size: %d\n", input_numbers_size);
		print_numbers(input_numbers, input_numbers_size);

		int k_esimo = (input_numbers_size - 1) / 2; // median is at middle

		// finds median in linear time, O(C.n)
		// C is a big constant, but still linear
		// uses exoteric select and median-of-medians algorithms
		int median = exoteric_select(input_numbers, input_numbers_size, k_esimo);

	    print_numbers(aux, input_numbers_size);
		printf("Expected Median: %d\n", aux[k_esimo]);
		printf("Median: %d\n", median);

		// compares O(C.n) and cheated O(n^2) solution
		if (median == aux[k_esimo]) {

			// annotates one more right solution
			times_correct++;
		}

		free(input_numbers);
		free(aux);
	}

	printf("Times correct: %d\n", times_correct);

	return 0;
}
