#include <iostream>
#include <stdio.h>
#include <math.h>
struct otr {
	int otr[100];
	int length;
};
otr write_elems() {
	otr array;
	int x1, x2, y1, y2, f, N;
	printf_s("Получить массив из файла (нажмите 1) или нет (любое другое число)");
	scanf_s("%d", &f);
	if (f == 1) {
		FILE* input = fopen("input.txt", "rt");
		fscanf(input, "%d", &array.length);
		for (int i = 0; i < array.length; i++) {
				fscanf(input, "%d%d%d%d", &x1, &y1, &x2, &y2);
			printf_s("Координаты точек %d отрезка (%d;%d) и (%d;%d) \n", i + 1, x1, y1, x2, y2);
			array.otr[i] = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		}
		fclose(input);
	}
	else {
		do {
			printf_s("Введите количество элементов массива (нат число, меньшее 100)\n");
			scanf_s("%d", &N);
		} while (N <= 0 || N > 100);
		array.length = N;
		for (int i = 0; i < array.length; i++) {
			printf_s("Введите координаты вершин %d отрезка \n", i + 1);
			scanf_s("%d%d%d%d", &x1, &y1, &x2, &y2);
			array.otr[i] = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		}
	}
	return array;
}
void middle(otr array) {
	double sum = 0;
	for (int i = 0; i < array.length; i++) {
		sum += array.otr[i];
	}
	double sr = sum /array.length;
	printf_s("Средняя длина равна %f \n\n",sr);
	for (int i = 0; i < array.length; i++) {
		if (array.otr[i] > sr) {
			printf("Отрезок %d больше среднего значения \n", i + 1);
		}
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	otr arr_otr = write_elems();
	middle(arr_otr);
}
