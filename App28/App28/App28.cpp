#include <iostream>
#include <conio.h>
#include <stdio.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[256];
	int countNumber = 0,c, strLength=0;
	printf_s("Введите текст \n");
	fgets(str,256,stdin);
	for (int i = 0; str[i] != '\0'; i++) {
		strLength++;
	}
	for (int i = 0;str[i]!='\0'; i++) {
		if (str[i] >='0' && str[i] <='9') {
			for (int j = i; j < strLength; j++) {
				str[j] = str[j + 1];
			}
			strLength--;
			i--;
			countNumber++;
		}
	}
	printf("Строка без цифр \n");
	printf_s("%s \n",str);
	printf_s("Количество удаленных цифр %d", countNumber);
}
