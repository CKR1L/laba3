#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "sorting.h"
#include "file.h"
#include "benchmark.h"
int main(int args, char* argv[]){
    if(strcmp(argv[1], "--file") == 0 && argv == 3){
        const char* data = argv[2];
        int size;
        int* arr = read_array_from_file(data, &size);
        if(arr == NULL){
            printf("Ошибка при чтении файла", data);
            return 1;
        }
        printf("Исходный массив в файле", data);
        for(int i = 0; i < size; i++){
            printf("%d", arr[i]);
        }
        printf("\n");
        Queue* p = array_to_queue(arr, size);
        printf("Создание очереди из списка:\n");
        print_queue(p);
        write_array_to_file(arr, size, "orig.txt");
        printf("Исходный массив в 'orig.txt");
        selection_sort(arr, size);
        printf("Выборочная сортировка:\n");
        for(int i = 0; i < size; i++){
            printf("%d", arr[i]);
        }
        printf("\n");
        write_array_to_file(arr, size, "sorted_selection.txt");
        printf("Выборочная сортировка записана в 'sorted_selection.txt'\n");
        int arr_quick = read_array_from_file(data, &size);
        quick_sort(arr_quick, 0, size - 1);
        write_array_to_file(arr_quick, size, "sorted_quick.txt");
        printf("Быстрая сортировка записана в 'sorted_quick.txt'\n");
        free(arr);
        free(arr_quick);
        free_queue(p);
    }else if(strcmp(argv[1], "--benchmark") == 0){
        benchmark_sorting();
    }else if(strcmp(argv[1], "--generate") == 0){
        generate_test_files();
    }else{
        return 1;
    }
    return 0;
}