#include <iostream>
#include <conio.h>
#include <stdio.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[256];
	int countNumber = 0, c;
	printf_s("Введите текст \n");
	fgets(str, 256, stdin);
	int strLenght = strlen(str);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			for (int j = i; j < strLenght; j++) {
				*(str + j) = *(str + j + 1);
			}
			strLenght--;
			i--;
			countNumber++;
		}
	}
	printf("Строка без цифр \n");
	printf_s("%s \n", str);
	printf_s("Количество удаленных цифр %d", countNumber);
}
