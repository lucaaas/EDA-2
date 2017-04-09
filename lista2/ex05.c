/*  Fabiola Malta Fleury 15/0009275
*   Lucas Oliveira Silva 15/0016018
*   Implementação do quick sort
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  NUMBER_OF_ELEMENTS 10
#define  MAX_VALUE 100


typedef struct node{
  int value;
  struct node *next_node, *previous_node;
} Node;

typedef struct header{
  Node *first_node, *last_node;
} Header;

/********************************************************
              FUNCTIONS THAT CREATE A LIST
*********************************************************/
Header* init_header() {
  Header *head = malloc(sizeof(Header));

  head->first_node = NULL;
  head->last_node = NULL;

  return head;
}

Node* create_node(int value) {
  Node *node;

  node = malloc(sizeof(Node));
  node->previous_node = NULL;
  node->next_node = NULL;
  node->value = value;

  return node;
}

Header* add_node_in_list(Header *head, Node *node) {
  if (head->first_node == NULL) { // list is empty
    head->first_node = node;
    head->last_node = node;
  }
  else { // then insert node in the end
    Node *last_node = head->last_node;
    last_node->next_node = node;
    node->previous_node = last_node;
    head->last_node = node;
  }

  return head;
}

Header* create_list() {
  Header *head = init_header();

  srand((unsigned)time(NULL));

  int iterator = 0;
  for (iterator = 0; iterator < NUMBER_OF_ELEMENTS; iterator++) {
    int number = rand() % MAX_VALUE; //generate a number between 0 and MAX_VALUE

    Node *node = create_node(number);
    head = add_node_in_list(head, node);
  }

  return head;
}

/********************************************************
              FUNCTIONS THAT ORDENATE A LIST
*********************************************************/
Header* put_node_before_pivot(Header *head, Node *node, Node *pivot) {
  Node *node_next = node->next_node;
  Node *node_previous = node->previous_node;
  Node *pivot_previous = pivot->previous_node;

  // removing node
  if (node_next != NULL) {
    node_next->previous_node = node->previous_node;
  }
  else {
    head->last_node = node_previous;
  }
  node_previous->next_node = node_next;

  // putting node before pivot
  if (pivot_previous != NULL) {
    pivot_previous->next_node = node;
  }
  else {
    head->first_node = node;
  }
  node->previous_node = pivot_previous;
  node->next_node = pivot;
  pivot->previous_node = node;

  return head;
}

Header* ordanate_list(Header *head, Node *node_initial, Node *node_limit) {
  if (node_initial != node_limit && node_initial != NULL && node_limit != NULL) {
    Node *pivot = node_initial;
    Node *current_node = pivot->next_node;

    while (current_node != node_limit->next_node && current_node != NULL) {
      if (current_node->value < pivot->value) {
        Node *current_node_next = current_node->next_node;

        head = put_node_before_pivot(head, current_node, pivot);
        current_node = current_node_next;
      }
      else{
        current_node = current_node->next_node;
      }
    }
    head = ordanate_list(head, head->first_node, pivot->previous_node);
    head = ordanate_list(head, pivot->next_node, node_limit);
  }

  return head;
}

void show_list(Node *node) {
  if (node != NULL) {
    printf("%d ", node->value);
    show_list(node->next_node);
  }
  else {
    return;
  }
}

int main() {
  Header *head = create_list();

  printf("List before ordenation:\n");
  show_list(head->first_node);

  head = ordanate_list(head, head->first_node, head->last_node);

  printf("\nList after ordenation:\n");
  show_list(head->first_node);

  printf("\n\n\n");

  return 0;
}
