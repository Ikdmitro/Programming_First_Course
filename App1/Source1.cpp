#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	long double number = 0;
	long int square = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			squre = (i * i) + (j * j);
			number = pow(square, 1.0 / 2);
			if (floor(number) == number) {
				cout << i << ' ' << j << endl;
			}
		}
	}
	return 0;
}