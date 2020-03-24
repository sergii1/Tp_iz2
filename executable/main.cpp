#include <iostream>
/*Условие ИЗ №2:
В вашем распоряжении — массив из 100 млн. чисел. Составьте наивный алгоритм подсчета суммы [k+ 10_i_]-х элементов
 для k = 1, 10 и i = 0, 1000000, после чего реализуйте параллельный алгоритм на нескольких потоках с учетом оптимизации
 работы с кэш-памятью.*/
#include "find_sum.h"
int min(int a, int b){
  return a<b?a:b;
}

int main() {
  ulong s = 0;
  int* arr = (int *)calloc(100000, sizeof(int));
  for(int i = 0; i<100000; ++i){
    arr[i] = 1;
    s+=arr[i];
  }

  clock_t begin_1 = clock();
  int sum1 = find_sum(arr, 0, 10000, 100000);
  clock_t end_1 = clock();
  double time_spent_1 = (double)(end_1 - begin_1) / CLOCKS_PER_SEC;

  clock_t begin_2 = clock();
  int sum2 = parallel_sum(arr, 0, 10000, 100000);
  clock_t end_2 = clock();
  double time_spent_2 = (double)(end_2 - begin_2) / CLOCKS_PER_SEC;
  free(arr);
  printf("sum is %d Common realization %f Parallel realization %f\n\n\n",sum1 ,time_spent_1, time_spent_2);
}
