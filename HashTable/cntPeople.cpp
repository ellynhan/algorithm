#include<iostream>
#include<set>
using namespace std;

int main() {
	int T; cin >> T;
	set<string> s;
	while (T--) {
		string a, b;
		cin >> a >> b;
		if (b == "enter")s.insert(a);
		else s.erase(a);
	}
	for (auto it = s.rbegin(); it != s.rend(); it++)
		cout << *it << "\n";
	return 0;
}