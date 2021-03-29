#include <iostream>
using namespace std;

int height[500][500];
long long dp[500][500];
int m,n;

int xx[4]={0,0,-1,1}; //상, 하, 좌, 우
int yy[4]={-1,1,0,0};

long long dfs(pair<int, int> curr){
    int y = curr.first;
    int x = curr.second;
    if(y==m-1 && x==n-1){
        return 1;
    }
    if(dp[y][x]==-1){
        dp[y][x]=0;
        for(int i=0; i<4; i++){
            int y_next = y+yy[i];
            int x_next = x+xx[i];
            if(y_next<0 || x_next<0 || y_next>=m || x_next>=n)continue;
            if(height[y_next][x_next]<height[y][x]){
                dp[y][x]+=dfs({y_next,x_next});
            }
        }
    }
    return dp[y][x];
}

int main(){
    cin >> m >> n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            dp[i][j]=-1;
            cin >> height[i][j];
        }
    }
    dfs({0,0});
    cout<<dp[0][0];
}  
