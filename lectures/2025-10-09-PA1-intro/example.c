#include <stdio.h>
#include <stdlib.h>

typedef struct int_arr_t {
  size_t m_size;
  size_t m_last;
  int *p_data;
} int_arr_t;

int create_int_arr(int_arr_t *arr, size_t size) {
  int *ptr = (int *)malloc(size * sizeof(int));
  if (!ptr)
    return -1;

  arr->m_size = size;
  arr->m_last = 0;
  arr->p_data = ptr;

  return 0;
}

void delete_int_arr(int_arr_t *arr) {
  if (!arr)
    return;

  arr->m_size = 0;
  arr->m_last = 0;
  free(arr->p_data);
  arr->p_data = NULL;
}

int main() {
  int_arr_t arr;
  create_int_arr(&arr, 10);

  arr.p_data[0] = 1;
  arr.p_data[1] = 1;
  arr.p_data[5] = 1;
  arr.p_data[7] = 1;
  arr.p_data[9] = 1;

  delete_int_arr(&arr);
}
