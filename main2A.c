#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int choice; // Змінна для зберігання вибору користувача

    do {
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

        int arr[n];

        // Введення елементів масиву з перевіркою
        printf("Введіть елементи масиву:\n");
        for (int i = 0; i < n; i++) {
            while (1) {
                if (scanf("%d", &arr[i]) == 1) {  // Перевірка коректного введення
                    break;
                } else {
                    printf("Некоректне значення. Будь ласка, введіть ціле число.\n");
                    while (getchar() != '\n');  // Очищаємо буфер
                }
            }
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
        } else {
            printf("Немає жодного нульового значення в елементах масиву.\n");
        }

        // Вивід результатів
        printf("Максимальний за модулем елемент: %d\n", max_abs);
        if (last_zero_index != -1) {
            printf("Сума елементів після останнього нульового: %d\n", sum_after_last_zero);
        }

        // Виведення меню
        printf("Запустити ще раз? (1 - так, 0 - вийти): ");
        while (1) {
            if (scanf("%d", &choice) == 1 && (choice == 0 || choice == 1)) {
                break;
            } else {
                printf("Некоректний вибір. Введіть 1 або 0: ");
                while (getchar() != '\n');  // Очищення буфера
            }
        }
    } while (choice != 0);  // Продовжуємо виконання, поки користувач не вибере 0

    return 0;
}
