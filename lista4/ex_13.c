/* Fabiola Malta Fleury 15/0009275
*  Lucas Oliveira Silva 15/0016018
*  This program reads a sequence of jobs and order them to minimize the weighted
*  sum of the completion times
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGHT_NAME 30

typedef struct job {
  char name_customer [MAX_LENGHT_NAME];
  int time_to_complete;
  int importance_job;
  double order_factor;
} Job;

Job* order_jobs (Job *jobs, int number_of_jobs){
  for (int id_job = 0; id_job < number_of_jobs; id_job++) {
    int j = id_job;
    int smallest_order_factor = id_job;
    while (j < number_of_jobs) {
      if(jobs[j].order_factor > jobs[smallest_order_factor].order_factor){
        smallest_order_factor = j;
      }
      else {
        // do nothing
      }

      j++;
    }

    Job aux_job = jobs[id_job];
    jobs[id_job] = jobs[smallest_order_factor];
    jobs[smallest_order_factor] = aux_job;
  }

  return jobs;
}
void show_jobs(Job *jobs, int number_of_jobs) {
  for (int id_job = 0; id_job < number_of_jobs; id_job++) {
    printf("%s\n", jobs[id_job].name_customer);
  }
}

int main (int argc, char const *argv[]) {
  printf("Digite o numero de tarefas: ");
  int number_of_jobs = 0;
  scanf ("%d", &number_of_jobs);

  Job *jobs = (Job*) malloc (number_of_jobs * sizeof (Job));

  for (int id_job = 0; id_job < number_of_jobs; id_job++) {
    printf("=====================\n");
    printf("Tarefa %2d\n", id_job+1);
    printf("=====================\n");

    printf("Digite o nome do cliente %d: ", id_job+1);
    scanf("%s", jobs[id_job].name_customer);

    printf("Digite o tempo que a tarefa leva para terminar: ");
    scanf("%d", &jobs[id_job].time_to_complete);

    printf("Digite a importancia da tarefa: ");
    scanf("%d", &jobs[id_job].importance_job);

    jobs[id_job].order_factor = jobs[id_job].importance_job / jobs[id_job].time_to_complete;
    printf("\n\n\n\n");
  }

  jobs = order_jobs(jobs, number_of_jobs);

  printf("O shedule ideal é: \n");
  show_jobs(jobs, number_of_jobs);
  return 0;
}
