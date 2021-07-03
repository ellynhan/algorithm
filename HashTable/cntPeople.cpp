#include<iostream>
#include<set>
using namespace std;

int main() {
	int len; cin >> len;
	set<string> s;
	while (len--) {
		string name, state;
		cin >> name >> state;
		if (state == "enter")s.insert(name);
		else s.erase(name);
	}
	for (auto it = s.rbegin(); it != s.rend(); it++)
		cout << *it << "\n";
	return 0;
}

//해쉬 이용해서 다시풀기. 