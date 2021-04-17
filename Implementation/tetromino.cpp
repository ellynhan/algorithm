#include <iostream>
using namespace std;

int n,m;
int board[500][500];
//이어진 4개의 블록을 덮어서 얻을 수 있는 수의 최대값. 
//dfs로 depth=4까지 내려가서 그 최대값을 비교하면 될 것 같으나
//중복을 없도록 하는 것이 관건이라고 생각이 된다.
//y,x
int dp[500][500]={0};
pair<int, int> middle[4][3]={
    {{1,0},{2,0},{1,1}}, //ㅏ
    {{1,0},{2,0},{1,-1}},//ㅓ
    {{0,1},{0,2},{-1,1}},//ㅗ
    {{0,1},{0,2},{1,1}}  //ㅜ
};

int dfs(int y, int x, int depth,int isRight){
    int b1=-4000,b2=-4000,b3=-4000;
    if(y<0||x<0||y>=n||x>=m){
        return -4000;
    }
    if(depth==4){
        return board[y][x];
    }
    b1 = dfs(y+1,x,depth+1,0);
    if(isRight!=-1){
        b2 = dfs(y,x+1,depth+1,1);
    }
    if(isRight!=1){
        b3 = dfs(y,x-1,depth+1,-1);
    }
    
    return max(max(b1,b2),b3)+board[y][x];
}

int middleCheck(int y, int x){
    int maxValue =0;
    for(int i=0; i<4; i++){
        int total = board[y][x];
        for(int j=0; j<3; j++){
            int yy=y+middle[i][j].first;
            int xx=x+middle[i][j].second;
            if(yy<0||xx<0||yy>=n||xx>=m){
                break;
            }
            total += board[yy][xx];
        } 
        maxValue = max(maxValue, total);
    }
    return maxValue;
}

int main(){
    cin >> n >> m;
    int maxValue = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j]=dfs(i,j,1,0);
            dp[i][j]=max(middleCheck(i,j),dp[i][j]);
            maxValue=max(maxValue,dp[i][j]);
        }
    }
    cout<<maxValue;
}
