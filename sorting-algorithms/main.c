#include <stdio.h>
#include <stdlib.h>

int main() {
  int nums[10] = { 0, 2, 4, 6, 8, 9, 7, 5, 3, 1 };

  for (int i = 0; i < 10; i++) {
    printf("%d ", nums[i]);
  }

  printf("\n");

  insertionSort(nums, 10);

  for (int i = 0; i < 10; i++) {
    printf("%d ", nums[i]);
  }

  printf("\n");

  return 0;
}

void bubbleSort(int *array, int size) {
  int n = size;
  int swapped = 1; // 1 for true, 0 for false

  while (swapped == 1 && n >= 0) {
    swapped = 0;

    for (int i = 0; i < n - 1; i++) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = 1;
      }
    }

    n -= 1;
  }
}

void insertionSort(int *array, int size) {
  for (int i = 1; i < size; i++) {
    int index = i;
    int value = array[i];

    while (index > 0 && value < array[index - 1]) {
      array[index] = array[index - 1];
      index -= 1;
    }

    array[index] = value;
  }
}
