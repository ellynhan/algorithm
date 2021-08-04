#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int, int> m; //num, cnt
    map<int, int>::iterator it;
    int* answer = new int[n];
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        m[tmp]=0;
        answer[i]=tmp;
    }
    int cnt = 0;
    for(it=m.begin(); it!=m.end(); it++){
        it->second=cnt;
        cnt ++;
    }
    for(int i=0; i<n; i++){
        cout<<m[answer[i]]<<" ";
    }
}
