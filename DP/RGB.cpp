#include <iostream>
using namespace std;

int rgb[1000][3];
int dp[1001][3]={0,};
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> rgb[i][0];
        cin >> rgb[i][1];
        cin >> rgb[i][2];
    }
    
    for(int i=1; i<=n; i++){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2])+rgb[i-1][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2])+rgb[i-1][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1])+rgb[i-1][2];
    }

    cout<< min(dp[n][0],min(dp[n][1],dp[n][2]));
}
