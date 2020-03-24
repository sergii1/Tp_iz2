//
// Created by sergiy on 24.03.2020.
//
#include "find_sum.h"
#include "stdio.h"
int find_sum(const int* arr, int k, int i, int len){
  if(arr == NULL)
    return 0;
  int sum=0;

  for(int j = 0; j<len && j<(k+10*i); ++j){
    sum+=arr[j];
  }
  return sum;
}
