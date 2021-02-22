#include <iostream>
using namespace std;
int scores[301]={0,};
int maxs[301]={0,};
int N;

int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> scores[i];
    }
    maxs[1]=scores[1];
    maxs[2]=maxs[1]+scores[2];
    for(int i=1; i<=N; i++){
        maxs[i]=max(maxs[i-2]+scores[i], maxs[i-3]+scores[i-1]+scores[i]);
    }
    cout<<maxs[N];
}
