#include <iostream>
using namespace std;

int candy[1000][1000];
int dp[1000][1000]={0};

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> candy[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j]+=candy[i][j];
            if(j<m-1){
                dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
            }
            if(j<m-1&&i<n-1){
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
            }
            if(i<n-1){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            }
        }
    }
    cout<<dp[n-1][m-1];
}
