#include <iostream>
using namespace std;

long long dp[100][100]={0,};
int board[100][100];

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            int value = board[i][j];
        }
    }
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==n-1&&j==n-1)break;
            int value = board[i][j];
            if(dp[i][j]!=0){
                if(i+value<n){
                    dp[i+value][j]+=dp[i][j];
                }
                if(j+value<n){
                    dp[i][j+value]+=dp[i][j];
                }
            }
        }

    }
    cout<<dp[n-1][n-1];
}
