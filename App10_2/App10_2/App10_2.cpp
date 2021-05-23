// App6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
int counting(int elem) {
    int count = 0;
    while (elem > 0) {
        count++;
        elem /= 10;
    }
    return count;
}
void write(int elem) {
    for (int k = 0; k < elem; k++) {
        printf(" ");
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int a = 0, b = 0, count_a, count_b, count_pr, length_str = 0, length_i = 0,length_j=0,length_pr=0;
    while (a <= 0 && b <= 0) {
        printf("Введите числа A и B\n");
        scanf_s("%d", &a);
        scanf_s("%d", &b);
    }
    count_a = counting(a);
    count_b = counting(b);
    count_pr = counting(a*b);
    for (int i = 30; i <= a; i++) {
        length_i = counting(i);
        for (int j = 30; j <= b; j++) {
            write(count_a - length_i + 1);
            printf("%d X ", i);
            printf("%d = ",j);
            length_pr = counting(i * j);
            write(count_pr - length_pr + 1);
            printf("%d", i * j);
            write(1);
        }
        printf("\n");
    }

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
