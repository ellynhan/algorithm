#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num,tmp,sum=0;
	vector<int> t;
	cin >> num;
	while (num--){
		cin >> tmp;
		t.push_back(tmp);
	}
	sort(t.begin(), t.end());
	for (int i = 0; i < t.size(); i++) {
		sum += (t.size()-i)*t[i];
	}
	cout << sum;
}
