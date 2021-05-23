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
int main()
{
    setlocale(LC_ALL, "Russian");
    int a = 0, b = 0,count_a,count_b,count_pr,length_str=0,length_i=0,max_length;
    while (a <= 0 && b <= 0) {
        printf("Введите числа A и B\n");
    scanf_s("%d", &a);
    scanf_s("%d", &b);
}
    count_a = counting(a);
    count_b = counting(b);
    count_pr = counting(a*b);
    max_length = count_a + count_b + count_pr;
    for (int i = 1; i <=a; i++) {
        length_i = counting(i);
        for (int j = 1; j <=b; j++) {
            length_str = length_i + counting(j) + counting(i * j);
            printf("%d X %d = %d", i, j, i* j);
            for (int k = 0; k < max_length - length_str+1;k++) {
                printf(" ");
            }
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
