#include <iostream>
#include <vector>
using namespace std;
int tri[500][500]={0};
vector<vector<int>> v;
vector<vector<int>> dp;

void getMax(int height, int row){
    for(int i=0; i<height+1; i++){
        dp[height+1][i]=max(dp[height+1][i], dp[height][i]+v[height+1][i]);
        dp[height+1][i+1]=max(dp[height+1][i], dp[height][i]+v[height+1][i+1]);
    }
}

int main(){
    int height;
    cin >> height;
    v.resize(height);
    dp.resize(height);
    for(int i=0; i<height; i++){
        v[i].resize(i+1);
        dp[i].resize(i+1);
        for(int j=0; j<i+1; j++){
            cin >> v[i][j];
        }
    }
    
    dp[0][0]=v[0][0];
    for(int i=0; i<height-1; i++){
        for(int j=0; j<=i; j++){
            dp[i+1][j]=max(dp[i+1][j], dp[i][j]+v[i+1][j]);
            dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]+v[i+1][j+1]);
        }
    }
    int maxValue = 0;
    for(int i=0; i<height; i++){
        maxValue = max(maxValue, dp[height-1][i]);
    }
    cout<<maxValue;
}