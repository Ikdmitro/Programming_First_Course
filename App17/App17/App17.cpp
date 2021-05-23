#include <iostream>
#include <stdio.h>
#include <math.h>
struct mas {
	int array[100][100];
	int lengthColumn;
	int lengthRow;
};
void pr_str(mas array) {
	int f = 0, i, j, pr = 1, minPr=0;
	for (i = 0; i < array.lengthRow; i++) {
		for (j = 0; j < array.lengthColumn; j++) {
			pr *= array.array[i][j];
		}
		printf_s("Произведение %d строчки равно %d \n", i + 1, pr);
		if (minPr > pr && f == 1) {
			minPr = pr;
		}
		else if (f == 0) {
			minPr = pr;
			f = 1;
		}
		pr = 1;
	}
		printf_s("Минимальное произведение равно %d \n", minPr);
}
void write_on_display(mas array) {
	int i, j;
	printf_s("Массив выведен на экран \n");
	for (i = 0; i < array.lengthRow; i++) {
		for (j = 0; j < array.lengthColumn; j++) {
			printf_s("%d ", array.array[i][j]);
		}
		printf_s("\n");
	}
}
void write_on_binary(mas array) {
	int i, j;
	FILE* output = fopen("output.bin", "wb");
	fwrite(&array.lengthRow, sizeof(int), 1, output);
	fwrite(&array.lengthColumn, sizeof(int), 1, output);
	for (i = 0; i < array.lengthRow; i++) {
		for (j = 0; j < array.lengthColumn; j++) {
			fwrite(&array.array[i][j], sizeof(int), 1, output);
		}
	}
	fclose(output);
	printf_s("Данные записаны \n");
}
mas write_keyboard(mas array) {
	int N1, N2, i, j;
	do {
		printf_s("Введите количество строк и столбцов в массиве (нат число, меньшее 100)\n");
		scanf_s("%d%d", &N1, &N2);
	} while ((N1 <= 0 || N1 > 100) || (N2 <= 0 || N2 > 100));
	array.lengthRow = N1;
	array.lengthColumn = N2;
	for (i = 0; i < array.lengthRow; i++) {
		for (j = 0; j < array.lengthColumn; j++) {
			printf_s("Введите элемент %d строки и %d столбца \n", j+1, i+1);
			scanf_s("%d", &array.array[i][j]);
		}
	}
	return array;
}
mas write_formula(mas array) {
	int N1, N2, i, j;
	do {
		printf_s("Введите количество строк и столбцов в массиве (нат число, меньшее 100)\n");
		scanf_s("%d%d", &N1, &N2);
	} while ((N1 <= 0 || N1 > 100) || (N2 <= 0 || N2 > 100));
	array.lengthRow = N1;
	array.lengthColumn = N2;
	for (i = 0; i < array.lengthRow; i++) {
		for (j = 0; j < array.lengthColumn; j++) {
			if (i > j) {
				array.array[i][j] = i - 2 * j;
			}
			else if (i == j) {
				array.array[i][j] = i * j;
			}
			else {
				array.array[i][j] = 3 * i + j;
			}
		}
	}
	printf_s("Данные введены при помощи формулы");
	return array;
}
void output_elems(mas array) {
	int f;
	printf_s("Вывести массив на экран (нажмите 1) \n");
	printf_s("Вывести массив в бинарный файл (любое другое число) \n");
	scanf_s("%d", &f);
	switch (f) {
	case 1: write_on_display(array);
		break;
	default: write_on_binary(array);
	}
}
mas write_from_binary(mas array) {
	int i,j;
	FILE* input = fopen("input.bin", "rb");
	fread(&array.lengthRow, sizeof(int), 1, input);
	fread(&array.lengthColumn, sizeof(int), 1, input);
	for (i = 0; i < array.lengthRow; i++) {
		for (j = 0; j < array.lengthColumn; j++) {
			fread(&array.array[i][j], sizeof(int), 1, input);
		}
	}
	printf_s("Данные получены \n");
	fclose(input);
	return array;
}
mas write_random(mas array) {
	int left, right,N1,N2,i,j;
	do {
		printf_s("Введите количество строк и столбцов в массиве (нат число, меньшее 100)\n");
		scanf_s("%d%d", &N1, &N2);
	} while ((N1 <= 0 || N1 > 100) || (N2 <= 0 || N2 > 100));
	array.lengthRow = N1;
	array.lengthColumn = N2;
	printf_s("Введите диапазон значений массива \n");
	scanf_s("%d%d", &left, &right);
	if (left > right) {
		int t = left;
		left = right;
		right = t;
	}
	for (i = 0; i < array.lengthRow; i++) {
		for (j = 0; j < array.lengthColumn; j++) {
			array.array[i][j] = rand() % (right - left + 1) + left;
		}
	}
	return array;
}
mas write_elems() {
	mas array;
	int f;
	printf_s("Ввести массив с клавиатуры (нажмите 1) \n");
	printf_s("Получить массив из бинарного файла (нажмите 2) \n");
	printf_s("Заполнить массив случайными числами из диапазона (нажмите 3) \n");
	printf_s("Получить массив с помощью формулы (любое другое число) \n");
	scanf_s("%d", &f);
	switch (f) {
	case 1:  array = write_keyboard(array);
		break;
	case 2: array = write_from_binary(array);
		break;
	case 3: array = write_random(array);
		break;
	default: array = write_formula(array);
	}
	return array;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	mas array = write_elems();
	output_elems(array);
	pr_str(array);
}
