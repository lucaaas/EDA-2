
/*  Fabiola Malta Fleury 15/0009275
*   Lucas Oliveira Silva 15/0016018
*   This program schedules jobs, running jobs of decreasing finish time on pc
*   gives as result the order jobs should be schedule and the finish time of the
*   whole process
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct job{
  int id;
  int timepc;
  int timesuperpc;
  int finish_time;
}job;

int left_index(int index){
  return 2 * index;
}

int right_index(int index){
  return (2 * index) + 1;
}

job* heapify(job *jobs, int current_index){
  int left, right;

  left = left_index(current_index);
  right = right_index(current_index);

  int largest;
  if(left <= jobs[0].timepc && jobs[left].timepc > jobs[current_index].timepc){
    largest = left;
  }
  else{
    largest = current_index;
  }
  if(right <= jobs[0].timepc && jobs[right].timepc > jobs[largest].timepc){
    largest = right;
  }
  if(largest != current_index){
    job swap = jobs[current_index];
    jobs[current_index] = jobs[largest];
    jobs[largest] = swap;
    heapify(jobs, largest);
  }
  return jobs;
}


job* build_heap(job *jobs, int size){
  int i;
  for (i = size/2;i > 0; i--){
    jobs = heapify(jobs, i);
  }
  return jobs;
}

job* heap_sort(job *jobs, int size){
  int i;

  jobs = build_heap(jobs, size);

  for(i = size; i > 1; i--){
    job swap = jobs[1];
    jobs[1] = jobs[i];
    jobs[i] = swap;
    jobs[0].timepc--;
    heapify(jobs, 1);
  }
  return jobs;
}

int main(int argc, char const *argv[]) {
  int quantity = 0;
  printf("Digite a quantidade de jobs que sera realizada pelo supercomputador: ");
  scanf("%d", &quantity);
  job *jobs = malloc(sizeof(int)*(quantity+1));

  for(int i = 1; i <= quantity; i++){
    jobs[i].id = i;
    printf("\n");
    printf("Digite o tempo do trabalho %d no supercomputador: ",i);
    scanf("%d",&jobs[i].timesuperpc);
    printf("Digite o tempo do trabalho %d no computador: ",i);
    scanf("%d",&jobs[i].timepc);
  }
  jobs[0].timepc = quantity;
  jobs = heap_sort(jobs,quantity);


  printf("\nA ordem dos jobs a ser executada deve ser:  ");
  int superpc_time = 0;
  int longest = 0;
  for(int i = quantity; i > 0; i--){
    printf("%d   ",jobs[i].id);
    superpc_time += jobs[i].timesuperpc;
    jobs[i].finish_time = superpc_time + jobs[i].timepc;
    if(jobs[i].finish_time > longest){
      longest = jobs[i].finish_time;
    }
  }
  printf("\nTempo de conclusao: %d\n\n",longest);
  return 0;
}
