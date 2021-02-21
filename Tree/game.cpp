#include <iostream>
#include <algorithm>
using namespace std;

int N, M; //세로 가로
char board[50][50];

//상하좌우
int xx[4] = {0,0,-1,1};
int yy[4] = {1,-1,0,0};

int visited[50][50]={0,}; 

int dp[50][50]={0,};

int dfs(pair<int, int> root){
    int x = root.second;
    int y = root.first;
    if(x<0 || y<0 || x>=M || y>=N || board[y][x]=='H'){
        return 0;
    }
    else if(visited[y][x]==1){
        cout<<-1;
        exit(0);
    }else if(dp[y][x]==0){
        int value = board[y][x]-'0';
        visited[y][x]=1;
        for(int i=0; i<4; i++){
            dp[y][x] = max(dp[y][x],dfs({y+yy[i]*value,x+xx[i]*value})+1);
        }
        visited[y][x]=0;
    }
    return dp[root.first][root.second];
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >>N>>M;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        for(int j=0; j<M; j++){
            board[i][j] = str[j];
        }
    }
    cout<< dfs({0,0});
}
