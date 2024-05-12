#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main() {
    int n;

    // Введення кількості елементів масиву з перевіркою
    while (1) {
        printf("Введіть кількість елементів масиву: ");
        if (scanf("%d", &n) == 1 && n > 0) {
            break;
        } else {
            printf("Некоректне значення. Будь ласка, введіть позитивне ціле число.\n");
            while (getchar() != '\n');  // Очищення буфера
        }
    }

    int arr[n];  // Масив, заповнений випадковими числами

    srand(time(NULL));  // Ініціалізація генератора випадкових чисел
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 201 - 100;  // Генерація випадкових чисел від -100 до 100
    }

    // Знаходимо максимальний за модулем елемент
    int max_abs = INT_MIN;
    for (int i = 0; i < n; i++) {
        int abs_value = abs(arr[i]);
        if (abs_value > max_abs) {
            max_abs = abs_value;
        }
    }

    // Знаходимо індекс останнього нульового елемента
    int last_zero_index = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) {
            last_zero_index = i;
            break;
        }
    }

    // Сума елементів після останнього нульового
    int sum_after_last_zero = 0;
    if (last_zero_index != -1) {
        for (int i = last_zero_index + 1; i < n; i++) {
            sum_after_last_zero += arr[i];
        }
    }

    // Вивід результатів
    printf("Максимальний за модулем елемент: %d\n", max_abs);
    printf("Сума елементів після останнього нульового: %d\n", sum_after_last_zero);

    return 0;
}
