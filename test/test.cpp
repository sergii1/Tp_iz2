//
// Created by sergiy on 06.03.2020.
//
#include "gtest/gtest.h"
#include "find_sum.h"
#include "time.h"

TEST(test_functional_part, Test1) {
  int* arr = (int *)calloc(10, sizeof(int));
  for(int i = 0; i<10; ++i){
    arr[i] = 1;
  }

  clock_t begin_1 = clock();
  int sum1 = find_sum(arr, 10, 0, 10);
  clock_t end_1 = clock();
  double time_spent_1 = (double)(end_1 - begin_1) / CLOCKS_PER_SEC;

  clock_t begin_2 = clock();
  int sum2 = parallel_sum(arr, 10, 0, 10);
  clock_t end_2 = clock();
  double time_spent_2 = (double)(end_2 - begin_2) / CLOCKS_PER_SEC;

  ASSERT_EQ(sum1, sum2);
  ASSERT_EQ(sum1, 10);
  ASSERT_EQ(sum2, 10);
  free(arr);
  printf("Common realization %f Parallel realization %f\n\n\n", time_spent_1, time_spent_2);
}


TEST(test_functional_part, Test2) {
  int* arr = (int *)calloc(100000, sizeof(int));
  int t = -1;
  for(int i = 0; i<100000; ++i){
    arr[i] = t;
    t*=-1;
  }
  clock_t begin_1 = clock();
  int sum1 = find_sum(arr, 0, 10000, 100000);
  clock_t end_1 = clock();
  double time_spent_1 = (double)(end_1 - begin_1) / CLOCKS_PER_SEC;

  clock_t begin_2 = clock();
  int sum2 = parallel_sum(arr, 0, 10000, 100000);
  clock_t end_2 = clock();
  double time_spent_2 = (double)(end_2 - begin_2) / CLOCKS_PER_SEC;

  ASSERT_EQ(sum1, sum2);
  ASSERT_EQ(sum1, 0);
  ASSERT_EQ(sum2, 0);
  printf("Common realization %f Parallel realization %f\n\n\n", time_spent_1, time_spent_2);
  free(arr);
}


TEST(test_functional_part, Test3) {
  int* arr = (int *)calloc(100000, sizeof(int));
  int s = 0;
  for(int i = 0; i<100000; ++i){
    arr[i] = rand()%100 - 20;
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

  ASSERT_EQ(sum1, sum2);
  ASSERT_EQ(sum1, s);
  ASSERT_EQ(sum2, s);
  free(arr);
  printf("Common realization %f Parallel realization %f\n\n\n", time_spent_1, time_spent_2);

}


TEST(test_functional_part, Test4) {
  int* arr = (int *)calloc(100000000, sizeof(int));
  int s = 0;
  for(int i = 0; i<100000000; ++i){
    arr[i] = rand()%100 - 20;
    s+=arr[i];
  }
  clock_t begin_1 = clock();
  int sum1 = find_sum(arr, 0, 10000000, 100000000);
  clock_t end_1 = clock();
  double time_spent_1 = (double)(end_1 - begin_1) / CLOCKS_PER_SEC;

  clock_t begin_2 = clock();
  int sum2 = parallel_sum(arr, 0, 10000000, 100000000);
  clock_t end_2 = clock();
  double time_spent_2 = (double)(end_2 - begin_2) / CLOCKS_PER_SEC;

  ASSERT_EQ(sum1, sum2);
  ASSERT_EQ(sum1, s);
  ASSERT_EQ(sum2, s);
  free(arr);
  printf("Common realization %f Parallel realization %f\n\n\n", time_spent_1, time_spent_2);

}