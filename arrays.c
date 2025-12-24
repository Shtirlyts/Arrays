#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "array.h"

// ========== ЛАБОРАТОРНАЯ 11 ==========

double* input_array(double* ptr_array, int n) {
    printf("Введите %d элементов массива:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  array[%d] = ", i);
        scanf("%lf", &ptr_array[i]);
    }
    return ptr_array;
}

int print_array(double* ptr_array, int n) {
    printf("Массив [%d элементов]: ", n);
    for (int i = 0; i < n; i++) {
        printf("%.2f ", ptr_array[i]);
    }
    printf("\n");
    return n;
}

int count_greater_than_A(double* ptr_array, int n, double A) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] > A) {
            count++;
        }
    }
    return count;
}

// ========== ЛАБОРАТОРНАЯ 14 ==========

double func(double x) {
    return sin(x);
}

double* fill_with_func(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = func(i * 0.5);
    }
    return ptr_array;
}

double average_between_min_max(double* arr, int n) {
    if (n < 3) return 0.0;

    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
    }

    if (min_index == n - 1) return 0.0;

    int max_index = min_index + 1;
    for (int i = min_index + 2; i < n; i++) {
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
    }

    double sum = 0;
    int count = 0;
    for (int i = min_index + 1; i < max_index; i++) {
        sum += arr[i];
        count++;
    }

    if (count == 0) return 0.0;
    return sum / count;
}

// ========== ЛАБОРАТОРНАЯ 16 ==========

double* create_array_d() {
    srand(time(NULL));

    int size_a = 10 + rand() % 41;
    int size_b = 10 + rand() % 41;
    int size_c = 10 + rand() % 41;

    double* a = (double*)malloc(size_a * sizeof(double));
    double* b = (double*)malloc(size_b * sizeof(double));
    double* c = (double*)malloc(size_c * sizeof(double));

    for (int i = 0; i < size_a; i++) {
        a[i] = -5.0 + 10.0 * rand() / RAND_MAX;
    }
    for (int i = 0; i < size_b; i++) {
        b[i] = -5.0 + 10.0 * rand() / RAND_MAX;
    }
    for (int i = 0; i < size_c; i++) {
        c[i] = -5.0 + 10.0 * rand() / RAND_MAX;
    }

    printf("\nМассив a (размер %d):\n", size_a);
    print_array(a, size_a);
    printf("Массив b (размер %d):\n", size_b);
    print_array(b, size_b);
    printf("Массив c (размер %d):\n", size_c);
    print_array(c, size_c);

    int first_positive = -1;
    for (int i = 0; i < size_a; i++) {
        if (a[i] > 0) {
            first_positive = i;
            break;
        }
    }

    int d_size;
    if (first_positive == -1) {
        d_size = 2;
    }
    else {
        d_size = (size_a - first_positive) + 2;
    }

    double* d = (double*)malloc(d_size * sizeof(double));

    double sum_b = 0;
    for (int i = 0; i < size_b; i++) sum_b += b[i];
    d[0] = sum_b / size_b;

    if (first_positive != -1) {
        for (int i = first_positive; i < size_a; i++) {
            if (a[i] > 1.0) {
                d[i - first_positive + 1] = a[i] - 0.5;
            }
            else {
                d[i - first_positive + 1] = a[i] + 0.5;
            }
        }
    }

    double sum_c = 0;
    for (int i = 0; i < size_c; i++) sum_c += c[i];
    d[d_size - 1] = sum_c / size_c;

    free(a);
    free(b);
    free(c);

    return d;
}