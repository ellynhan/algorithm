#include <iostream>
using namespace std;
int main(void) {
	int N, M, K, sum = 0;
	cin >> N >> M >> K;
	while ((M + N >= K) && (N >= 0) && (M >= 0)) {
		N -= 2;
		M -= 1;
		sum += 1;
	}
	cout << sum - 1;
}