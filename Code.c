#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

void task11();
void task14();
void task16();

int main() {
    system("chcp 1251");
    srand(time(NULL));
    puts("Лабораторные работы 11, 14, 16\n");

    task11();
    task14();
    task16();

    return 0;
}

void task11() {
    puts("=== Лабораторная 11 ===");

    int n;
    double A;

    printf("Введите размер массива: ");
    scanf("%d", &n);

    double* array = (double*)malloc(n * sizeof(double));

    input_array(array, n);
    print_array(array, n);

    printf("Введите число A: ");
    scanf("%lf", &A);

    int count = count_greater_than_A(array, n, A);
    printf("Элементов больше %.2f: %d\n", A, count);

    free(array);
}

void task14() {
    puts("\n=== Лабораторная 14 ===");

    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    double* array = (double*)malloc(n * sizeof(double));

    fill_with_func(array, n);
    print_array(array, n);

    double avg = average_between_min_max(array, n);
    printf("Среднее между мин и макс: %.3f\n", avg);

    free(array);
}

void task16() {
    puts("\n=== Лабораторная 16 ===");

    double* d = create_array_d();
    if (d) {
        printf("\nМассив d:\n");
        print_array(d, 0);
        free(d);
    }
}