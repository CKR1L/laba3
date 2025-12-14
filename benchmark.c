#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"
#include "file.h"
void benchmark_sorting(){
    int sizes[] = {100, 500, 1000, 5000, 10000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    printf("Выборочная сортировка/Быстрая сортировка");
    for (int i = 0; i < num_sizes; i++){
        char data[50];
        sprintf(data, "test_data.txt", sizes[i]);
        int size;
        int* arr = read_array_from_file(data, &size);
        if (arr == NULL) continue;
        int* arr_copy = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++){
            arr_copy[j] = arr[j];
        }
        clock_t start = clock();
        selection_sort(arr, size);
        clock_t end = clock();
        double selection_time = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        start = clock();
        quick_sort(arr_copy, 0, size - 1);
        end = clock();
        double quick_time = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
        printf("%d\t%.2f", sizes[i], selection_time, quick_time);
        free(arr);
        free(arr_copy);
    }
}