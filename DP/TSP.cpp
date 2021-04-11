//0444
#include <iostream>
using namespace std;

int way[16][16]={0};
int visited[16]={0};
int dp[16][17];//city, num of visited
int n;

void dfs(int curr, int total, int cost){
    for(int i=0; i<=n; i++){
        if(way[curr][i]>0 && visited[i]==0){
            //방문가능
            visited[i]=1;
            dp[i][total+1]=min(dp[i][total+1], cost+way[curr][i]);
            dfs(i,total+1,cost+way[curr][i]);
            visited[i]=0;
        }   
    }
}


int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> way[i][j];
            dp[i][j]=n*1000000;
        }
        dp[i][n]=n*1000000;
    }
    dfs(0,0,0);
    cout<<dp[0][n];
}
