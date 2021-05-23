#include <iostream>
#include <stdio.h>
struct mas {
	int arr[100];
	int length;
};
mas write_elems() {
	mas array;
	int A, B, N, l, f;
	printf_s("Получить массив из файла (нажмите 1) или нет (любое другое число)");
	scanf_s("%d", &f);
	if (f == 1) {
		FILE* input = fopen("input.txt", "rt");
		fscanf(input, "%d", &array.length);
		for (int i = 0; i < array.length; i++) {
			fscanf(input, "%d", &array.arr[i]);
			printf_s("%d элемент массива равен %d\n", i + 1, array.arr[i]);
		}
		fclose(input);
	}
	else {
		do {
			printf_s("Введите количество элементов массива (нат число, меньшее 100)\n");
			scanf_s("%d", &N);
		} while (N <= 0 || N > 100);
		array.length = N;
		do {
			printf_s("Будете сами вводить элементы массива (намжмите 0) или заполнить случайными числами (введите любое число)\n");
			scanf_s("%d", &l);
		} while (l < 0);
		if (l != 0) {
			printf_s("Введите диапазон значений массива\n");
			scanf_s("%d%d", &A, &B);
			if (A > B) {
				int t = A;
				A = B;
				B = t;
			}
			for (int i = 0; i < array.length; i++) {
				array.arr[i] = rand() % (B - A + 1) + A;
				printf_s("%d элемент массива равен %d\n", i + 1, array.arr[i]);
			}
		}
		else {
			for (int i = 0; i < array.length; i++) {
				printf_s("Введите %d элемент массива\n", i + 1);
				scanf_s("%d", &array.arr[i]);
			}
		}
	}
	return array;
}
void min_elems(mas array) {
	int k = 0, num = 0;
	printf_s("Введите число \n");
	scanf_s("%d", &num);
	for (int i = 0; i < array.length; i++) {
		if (num > array.arr[i])
			k++;
	}
	printf_s("Количество элементов меньше %d равно %d \n", num, k);
}
void max_and_mas(mas array) {
	int max1 = 0, is_max = 0;
	for (int i = 0; i < array.length; i++) {
		if (is_max) {
			if (max1 < array.arr[i]) {
				max1 = array.arr[i];
			}
		}
		else {
			is_max = 1;
			max1 = array.arr[i];
		}
	}
	printf_s("Максимальный элемент массива равен %d \n", max1);
	FILE* output = fopen("output.txt", "w+");
	fprintf(output, "%d ", array.length);
	for (int i = 0; i < array.length; i++) {
		if (array.arr[i] < max1) {
			array.arr[i] -= max1;
		}
		printf_s("arr[%d]=%d \n", i + 1, array.arr[i]);
		fprintf(output, "%d ", array.arr[i]);
	}
	fclose(output);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	struct mas arr = write_elems();
	min_elems(arr);
	max_and_mas(arr);
}
