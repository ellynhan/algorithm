#include <iostream>
using namespace std;

int main() {
	int price, exchange, i, j, sum = 0;
	cin >> price;
	exchange = 1000 - price;
	int money[6] = { 500,100,50,10,5,1 };
	int num[6] = { 0, };
	for (i = 0; i < 6; i++) {
		for (j = 0; money[i] * j <= exchange; j++) {}
		num[i] = j - 1;
		exchange -= money[i] * num[i];
		sum += num[i];
	}
	cout << sum;
}