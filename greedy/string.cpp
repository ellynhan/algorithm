#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;
	int dif = B.length() - A.length();
	int* same = new int[dif + 1];
	for (int i = 0; i <= dif; i++) {
		same[i] = 0;
		for (int j = 0; j < A.length(); j++) {
			if (A[j] == B[i + j]) {
				same[i]++;
			}
		}
	}
	sort(same, same + dif + 1);
	cout << A.length() - same[dif];
}