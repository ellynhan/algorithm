#include <iostream>
using namespace std;

int floors[100][100]={};
int check[100][100]={0,};
int n, m;

void dfs(int row, int col){
    check[row][col]=1;
    if(floors[row][col]=='-'){
        if(col<m&&floors[row][col+1]=='-'){
            dfs(row,col+1);
        }
    }else{
        if(row<n&&floors[row+1][col]=='|'){
            dfs(row+1, col);
        }
    }
}

int main(){
    cin >> n >> m;
    int cnt = 0;
    for(int i=0; i<n; i++){
        string tmp ;
        cin >> tmp;
        for(int j=0; j<m; j++){
            floors[i][j]=tmp[j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(check[i][j]==0){
                dfs(i,j);
                cnt ++;
            }
        }
    }
    cout<< cnt;
}