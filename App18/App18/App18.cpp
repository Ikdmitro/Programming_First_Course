#include <iostream>
void max_min_num(int pNum,int *maxNum,int *minNum) {
    int num = pNum,d;
    *maxNum = 10;
    *minNum = -1;
    while (num > 0) {
        d = num  % 10;
        if (d < *maxNum) {
           *maxNum = d;
        }
        if (d > *minNum) {
            *minNum = d;
        }
        num /= 10;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int num,minNum,maxNum;
    printf_s("Введите число\n");
    scanf_s("%d", &num);
    max_min_num(num,&minNum,&maxNum);
    printf_s("Наибольшая цифра %d \n", maxNum);
    printf_s("Наименьшая цифра %d \n", minNum);
}

