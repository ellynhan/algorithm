//1131~
#include <iostream>
#include <vector>
using namespace std;
int board[9][9];
vector<pair<int, int>> v;
int blank = 0;
int getAnswer = 0;

void fill(int curr, int cnt){
    if(getAnswer==1)return ;
    if(cnt == blank){
        getAnswer = 1;
        return ;
    }
    int x = v[curr].second;
    int y = v[curr].first;
    int check[10]={0};
    for(int k=0; k<9; k++){
        check[board[y][k]]=1;
        check[board[k][x]]=1;
    }
    int startY = y/3;
    int startX = x/3;

    for(int m=startY*3; m<(startY+1)*3; m++){
        for(int n=startX*3; n<(startX+1)*3; n++){
            check[board[m][n]]=1;
        }
    }
    for(int k=1; k<10; k++){
        if(check[k]==0){
            board[y][x]=k;
            fill(curr+1, cnt+1);
            if(getAnswer==0){
                board[y][x]=0;
            }else{
                return ;
            }
        }
    }
    return ;
}

int main(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> board[i][j];
            if(board[i][j]==0){
                blank ++;
                v.push_back({i,j});
            }
        }
    }
    if(v.size()>0){
        fill(0,0);
    }
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<'\n';
    }
}