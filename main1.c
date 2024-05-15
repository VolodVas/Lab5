#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int choice; // Змінна для зберігання вибору користувача

    do {
        int n;

        // Введення кількості елементів масиву з перевіркою на коректність
        while (1) {
            printf("Введіть кількість елементів масиву: ");
            if (scanf("%d", &n) == 1 && n > 0) {
                break;
            } else {
                printf("Некоректне значення. Введіть позитивне ціле число.\n");
                while (getchar() != '\n');  // Очищення буфера
            }
        }

        float arr[n];
        float modified_arr[n];
        int negative_count = 0; // Лічильник введених від'ємних чисел

        // Введення значень масиву з перевіркою на коректність
        printf("Введіть елементи масиву:\n");
        for (int i = 0; i < n; i++) {
            while (1) {
                if (scanf("%f", &arr[i]) == 1) {  // Перевірка успішного зчитування
                    break;
                } else {
                    printf("Некоректне значення. Введіть дійсне число.\n");
                    while (getchar() != '\n');  // Очищення буфера
                }
            }
            // Перевірка на від'ємність та обчислення квадратів від'ємних чисел
            if (arr[i] < 0) {
                modified_arr[i] = arr[i] * arr[i];  // Заміна на квадрат
                negative_count++; // Збільшення лічильника
            } else {
                modified_arr[i] = arr[i];  // Позитивні значення залишаються
            }
        }

        // Виведення введених від'ємних чисел та їх квадратів
        if (negative_count > 0) {
            printf("Введені від'ємні числа та їх квадрати:\n");
            for (int i = 0; i < n; i++) {
                if (arr[i] < 0) {
                    printf("%.2f --> %.2f\n", arr[i], modified_arr[i]);
                }
            }
        } else {
            printf("Не було введено жодного від'ємного числа.\n");
        }

        // Перевірка, чи масив не зростає
        bool not_zbilschuetsa = true;
        for (int i = 1; i < n; i++) {
            if (modified_arr[i] > modified_arr[i - 1]) {  // Якщо масив зростає
                not_zbilschuetsa = false;
                break;
            }
        }

        // Обчислення результату
        if (not_zbilschuetsa) {
            // Якщо масив не зростає, обчислюємо суму елементів вихідного масиву
            float sum = 0;
            for (int i = 0; i < n; i++) {
                sum += arr[i];
            }
            printf("Сума елементів вихідного масиву: %.2f\n", sum);
        } else {
            // Якщо масив зростає, обчислюємо добуток
            float product = 1;
            for (int i = 0; i < n; i++) {
                product *= arr[i];
            }
            printf("Добуток елементів вихідного масиву: %.2f\n", product);
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
