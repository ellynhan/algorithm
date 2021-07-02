#include<map>
#include<iostream>
using namespace std;

int main() {
	int log;
	cin >> log;
	map<long long, string> hashTable;
	for(int i=0; i<log; i++){
		string name, state;
		cin >> name >> state;
		long long H = 0;
		long long power = 53*53*53*53*53;
		for(int j=0; j<name.length(); j++){
			if(name[j]<'a'){
				H += (name[j]-'A'+1)*power;
			}else{
				H += (name[j]-'a'+27)*power;
			}
			power /= 53;
		}
		if(state == "enter"){
			hashTable[H] = name;
		}else{
			hashTable.erase(H);
		}
	}
	for(auto it=hashTable.rbegin(); it!=hashTable.rend(); it++){
		cout<<it->second<<'\n';
	}
}

/* 이런 결과가 나와야한다. 소문자가 무조건 우선이고 대문자가 뒤, 알파벳 역순이 우선순위. 
6 
AA enter
Aa enter
aA enter
aa enter
aC enter
Ac enter
aa
aC
aA
Ac
Aa
AA
*/
