//0558
#include <iostream>
using namespace std;

int dp[501]={0,};
int timeAndPrev[501][2]={0,};

void build(int i){
    int prev = timeAndPrev[i][1];
    if(dp[prev]==0&&prev!=0){
        build(prev);
    }
    dp[i] = dp[prev] + timeAndPrev[i][0];
}

int main(){
    int N;
    cin >> N;

    for(int i=1; i<=N; i++){
        int value, j=0;
        cin >> value;
        while(value!=-1){
            timeAndPrev[i][j]=value;
            j++;
            cin >> value;
        }
    }

    for(int i=1; i<=N; i++){
        if(dp[i]==0){
            build(i);
        }
        cout<<dp[i]<<endl;
    }
}
