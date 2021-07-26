#include <iostream>
using namespace std;

long long P[100]={0};
long long dfs(int n){
    if(P[n]==0){
        P[n]=dfs(n-2)+dfs(n-3);
    }
    return P[n];
}

int main(){
    P[0]=1;
    P[1]=1;
    P[2]=1;

    int testCase,n;
    cin >> testCase;
    while(testCase--){
        cin >> n;  
        cout<<dfs(n-1)<<'\n';
    }
}