﻿// App29_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int k = 0;
	char str1[256],str2[256];
	printf_s("Введите текст первого предложения \n");
	fgets(str1, 256, stdin);
	printf_s("Введите текст второго предложения \n");
	fgets(str2, 256, stdin);
	int strLength1 = strlen(str1);
	int strLength2 = strlen(str2);
	str2[strLength2-1] = '\0';
	strLength2 = strLength2 - 1;
	char* ind = strstr(str1, str2);
	while (ind != NULL) {
		int index = ind - str1;
		for (int j = index; str1[j] != 0; j++) {
				str1[j] = str1[j + strLength2];
			}
			strLength1-=strLength2;
			k++;
		ind = strstr(str1, str2);
	}
	printf_s("Количество вхождений 2 предложения в 1 равно %d \n", k);
	//printf_s("%d \n", index);
	//printf_s("Количество вхождений второго предложения в первое равно %d", k);
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