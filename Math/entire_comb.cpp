#include <iostream>
#include <map>
using namespace std;

int main(){
    int testCase;
    cin >> testCase;
    while(testCase--){
        int sorts;
        cin >> sorts;
        map<string,int> m;
        while(sorts--){
            string name, sort;
            cin >> name >> sort;
            m[sort]+=1;
        }
        int total = 1;
        map<string, int>::iterator it;
        for(it=m.begin(); it!=m.end(); it++){
            total *= (it->second +1);
        }
        cout<<total -1<<'\n';
    }
}