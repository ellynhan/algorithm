#include <iostream>
using namespace std;

int main() {
	int N, K, top, i, j, sum = 0;
	cin >> N >> K;
	int* v = new int[N];
	for (i = 0; i<N; i++) {
		cin >> v[i];
		if (v[i] < K) {
			top = i + 1;
		}
	}
	for (i = top - 1; i >= 0; i--) {
		for (j = 0; v[i] * j <= K; j++) {}
		sum += j - 1;
		K -= v[i] * (j - 1);
	}
	cout << sum;
}