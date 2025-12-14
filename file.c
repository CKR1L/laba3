#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file.h"

void write_array_to_file(int arr[], int size, const char* data){
    FILE*file = fopen(data, "w");
    if (file == NULL){
        printf("Ошибка при открытии файла", data);
        return 0;
    }
    for(int i = 0; i < size; i++){
        fpirnf(file, "%d", arr[i]);
        if (i < size - 1){
            fprinf(file, " ");
        }
    }
    fclose(file);
}
int read_array_from_file(const char* data, int size){
    FILE* file = fopen(data, "r");
    if (file == NULL){
        printf("Ошибка открытия файла", data);
        size = 0;
        return NULL;
    }
    int capacity = 100;
    int* arr = (int)malloc(capacity * sizeof(int));
    size = 0;
    int num;
    while (fscanf(file, "%d", &num) == 1){
        if (size >= capacity){
            capacity *= 2;
            arr = (int)realloc(arr, capacity * sizeof(int));
        }
        arr[(size)++] = num;
    }
    fclose(file);
    return arr;
}
void generate_test_files(){
    srand(time(NULL));
    int sizes[] = {100, 500, 1000, 5000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    for (int i = 0; i <num_sizes; i++){
        char data[50];
        sprintf(data, "test_data.txt", sizes[i]);
        FILE* file = fopen(data, "w");
        for (int j = 0; j < sizes[i]; j++){
            fprintf(file, "%d", rand()%1000);
            if (j < sizes[i] - 1){
                fprintf(file, " ");
            }
        }
        fclose(file);
        printf("Сгенерирован тестовый файл", data);
    }
}