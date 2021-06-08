#include <iostream>
using namespace std;

int n, m;
char board[10][10];
int x[4]={1,-1,0,0};//오 왼 위 아래
int y[4]={0,0,-1,1};
int total = 11;
void dfs(pair<int, int> R, pair<int, int> B, int cnt){ //재귀 최대 10번
    if(cnt>10) return;
    for(int i=0; i<4; i++){
        pair<int, int> currR = R;
        pair<int, int> currB = B;
        while(board[currR.first][currR.second]=='.'){ //빈칸있을 때 쭉 굴림
            currR.first += y[i];
            currR.second += x[i];
        }
        while(board[currB.first][currB.second]=='.'){
            currB.first += y[i];
            currB.second += x[i];
        }
        if(board[currB.first][currB.second]=='O'){ //파란공 구멍
            continue;
        }
        if(board[currR.first][currR.second]=='O'){ //구멍에 들어감
            total = min(total, cnt);
        }
        currR.first -= y[i];
        currR.second -= x[i];
        currB.first -= y[i];
        currB.second -= x[i];
        if(currR == currB){ //두 공이 겹침 (그러면 안됨)
            if(i==0){ //오른쪽
                if(R.second>B.second){
                    currB.second -= x[i];
                }else{
                    currR.second -= x[i];
                }
            }else if(i==1){ // 왼쪽
                if(R.second>B.second){
                    currR.second -= x[i];
                }else{
                    currB.second -= x[i];
                }
            }else if(i==2){ // 위쪽
                if(R.first < B.first){
                    currB.first -= y[i];
                }else{
                    currR.first -= y[i];
                }
            }else if(i==3){ //아래쪽
                if(R.first < B.first){
                    currR.first -= y[i];
                }else{
                    currB.first -= y[i];
                }
            }
        }
        dfs(currR, currB, cnt+1);
    }
}

int main(){
    pair<int, int> R, B;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        for(int j=0; j<m; j++){
            board[i][j]=tmp[j];
            if(tmp[j]=='R'){
                R = {i,j};
                board[i][j] = '.';
            }else if(tmp[j] =='B'){
                B = {i,j};
                board[i][j] = '.';
            }
        }
    }
    dfs(R, B, 1);
    if(total != 11){
        cout<<total;
    }else{
        cout<<-1;
    }
}