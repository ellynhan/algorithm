//12시 4분 시작 30분 종료
#include <iostream>
using namespace std;

//숫자보고 방향고르고 고른방향으로 숫자만큼움직임. 중간에 구멍은 무시
//구멍에 빠지거나 보드 바깥으로 가면 게임 종료
int N, M; //세로 가로
char board[50][50];
//상하좌우
int xx[4] = {0,0,-1,1};
int yy[4] = {1,-1,0,0};
int visited[50][50]={0,}; // 1나왔던 곳에 도착하면 -1
int maxValue = 0;

int dfs(pair<int, int> root, int depth){
    for(int i=0; i<4; i++){
        int value = board[root.first][root.second]-'0';
        int x = root.second + xx[i]*value;
        int y = root.first + yy[i]*value;
        if(x<0 || y<0 || x>=M || y>=N || board[y][x]=='H'){
            if(maxValue < depth){
                maxValue = depth;
            }
        }
        else{
            if(visited[y][x] == 1){
                return -1;
            }else{
                visited[y][x] = 1;
                if(dfs({y,x}, depth + 1) == -1){
                    return -1;
                }
                visited[y][x] = 0;
            }
            
        }
    }
    return 0;
}

int main(){
    cin >>N>>M;
    int result;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        for(int j=0; j<M; j++){
            board[i][j] = str[j];
        }
    }
    visited[0][0] = 1;
    result = dfs({0,0},1);
    if(result == -1){
        cout<< -1;
    }else{
        cout<<maxValue;
    }
}
