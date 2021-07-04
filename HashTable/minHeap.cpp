#include<set>
#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	multiset<int> s; //그냥 set을 사용하면 중복이 사라진다. 
	while(N--){
		int x;
		cin >> x;
		if(x == 0){
			int answer = 0;
			if(s.size()>0){
				answer = *s.begin();
				s.erase(s.begin());
			}
			cout << answer << '\n';
		}else{
			s.insert(x);
		}
	}
}