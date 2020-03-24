//
// Created by sergiy on 24.03.2020.
//
#include <stdlib.h>
#include "stdio.h"
#include "find_sum.h"
#include <pthread.h>
#include <malloc.h>
#include <unistd.h>

int min(int a, int b){
  return a<b?a:b;
}
//вычисляет сумму элементов подмассива, индекс начала и конца подмассива указан в структуре
void *calulate_partitial_sum(void *thread_data) {
  //получаем данные переданные в поток

  pthr_data *data = (pthr_data *) thread_data;
 // printf("parititial sum calc %d \n",data->pthr_id );
  int *res = (int *) calloc(1, sizeof(int));
  *res = 0;
  for (int i = data->start_pos; i <= data->end_pos; ++i) {
    *res += data->arr[i];
  }

  return res;
}

int parallel_sum(const int *arr, int k, int i, int len) {
  if(arr == NULL)
    return 0;
  int sum = 0;
  //end последний индекс в суммировании
  int end = min(k + 10 * i, len-1);
  //определяем число потоков
  int number_of_pthreads = sysconf(_SC_NPROCESSORS_ONLN);
  //выделяем память под массив идентификаторов потоков
  pthread_t* threads = (pthread_t*) calloc(number_of_pthreads , sizeof(pthread_t));
  if(!threads){
    return 0;
  }
  //сколько потоков - столько и структур с потоковыми данными
  pthr_data* threadData = (pthr_data*) malloc(number_of_pthreads * sizeof(pthr_data));
  if(!threadData){
    free(threads);
    return 0;
  }

  int amount_of_elements_in_thread = end/number_of_pthreads;
  int start_pos = 0;
  int end_pos = amount_of_elements_in_thread;
  for(int j=0; j<number_of_pthreads-1; ++j){
    threadData[j].arr = arr;
    threadData[j].start_pos = start_pos;
    threadData[j].end_pos = end_pos;
    start_pos = end_pos + 1;
    end_pos = end_pos+amount_of_elements_in_thread;
    if(pthread_create(&(threads[j]), NULL, calulate_partitial_sum, &threadData[j])!=0){
      free(threads);
      free(threadData);
      return 0;
    }
  }
  threadData[number_of_pthreads-1].arr = arr;
  threadData[number_of_pthreads-1].start_pos = start_pos;
  threadData[number_of_pthreads-1].end_pos = end;
  if(pthread_create(&(threads[number_of_pthreads-1]), NULL, calulate_partitial_sum, &threadData[number_of_pthreads-1])!=0){
    free(threads);
    free(threadData);
    return 0;
  }

//ожидаем выполнение всех потоков
  for(int j = 0; j < number_of_pthreads; j++){
    int* a = NULL;
    if(pthread_join(threads[j], (void**)(&a))){
      free(threads);
      free(threadData);
      free(a);
      return 0;
    }
    sum+=a[0];
    free(a);
  }

  free(threads);
  free(threadData);
  return sum;
}
