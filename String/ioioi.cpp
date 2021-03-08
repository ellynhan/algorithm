#include <iostream>
#include <string>
#include <stack>

using namespace std;
int main(){
    int N, M;
    string S;
    cin >> N >> M >> S;
    stack<char> s;
    int cnt =0;
    for(int i=0; i<M; i++){
        if(s.empty() && S[i]=='I'){
            s.push(S[i]);
        }
        if(!s.empty() && s.top()!=S[i]){
            s.push(S[i]);
        }else{
            while(!s.empty()){s.pop();}
            if(S[i]=='I')s.push(S[i]);
        }
        if(s.size()%2!=0 && s.size()>=2*N+1){
            cnt++;
        }
    }
    cout<<cnt;
}
