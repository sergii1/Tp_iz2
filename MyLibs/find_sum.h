//
// Created by sergiy on 24.03.2020.
//

#ifndef IZ2_MYLIBS_FIND_SUM_H_
#define IZ2_MYLIBS_FIND_SUM_H_

//специальная структура для данных потока
typedef struct{
  int start_pos; //первый индекс для суммирования
  int end_pos; //последний индекс для суммирования
  const int* arr; //указатель на исходную строку
} pthr_data;

int find_sum(const int* arr, int k, int i, int len);
int parallel_sum(const int* arr, int k, int i, int len);

#endif //IZ2_MYLIBS_FIND_SUM_H_
