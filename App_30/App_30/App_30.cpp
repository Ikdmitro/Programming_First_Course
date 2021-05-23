// App_30.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Header.h"
struct stackNumbers {
    int *arrNum;
    int length;
    int top;
};
void initStack(stackNumbers* stack,int length) {
    if (stack->arrNum = (int*)malloc(sizeof(int) * length))
    {
        stack->length = length;
    }
    else stack->length = -1;
    stack->top = -1;
}
void pushInStack(stackNumbers* stack, int value) 
{
    stack->top++;
    stack->arrNum[stack->top] = value;
}
int getDegFromStack(stackNumbers* stack)
{
    return stack->arrNum[stack->length-1-stack->top--];
}
void destructStack(stackNumbers* stack)
{
    if (stack->arrNum) {
        free(stack->arrNum);
        stack->length = -1;
        stack->top = -1;
    }
}
int main()
{
    setlocale(LC_ALL, "Ru");
    int n,d,count = 0;
    printf_s("Введите число:\n");
    scanf_s("%d", &n);
    d = n;
    while (d) {
        d /= 10;
        count++;
    }
    stackNumbers stack;
    initStack(&stack, count);
    while (n) {
        d = n%10;
        pushInStack(&stack, d);
        n /= 10;
    }
    printf_s("Число, записанное наоборот: ");
    while (count--) {
        printf_s("%d", getDegFromStack(&stack));
    }
    destructStack(&stack);
    system("pause");
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
