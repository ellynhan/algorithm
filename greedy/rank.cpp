#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int LLI;
int main(void) {
	LLI N, tmp, sum = 0;
	cin >> N;
	vector<LLI> r;
	for (LLI i = 0; i < N; i++) {
		cin >> tmp;
		r.push_back(tmp);
	}
	sort(r.begin(), r.end());
	for (LLI i = 0; i <N; i++) {
		if (r[i] - i > 1)
			sum += r[i] - i - 1;
		else if (r[i] - i < 1)
			sum -= r[i] - i - 1;
	}
	cout << sum;
}