//1015 1103 중단 1124시작
#include <iostream>
#include <queue>
using namespace std;

int N;
int board[101][101]={0};
queue<pair<int, char>> changes;
//현재위치, 방향정보
int xx[4]={1,0,-1,0}; //오 아 왼 위
int yy[4]={0,1,0,-1}; //0,1,0,-1
int currentWay=0; //Command L면 +3 R면 +1 %4
int X=1, Y=1;
int totalTime=0;
queue<pair<int, int>> tail;


int checkBound(int x, int y){
    if(x<1||y<1||x>N||y>N){
        return -1;
    }else{
        return 1;
    }
}

int main(){
    int apple, change;
    cin >> N >> apple;

    for(int i=0; i<apple; i++){
        int row, col;
        cin >> row >> col;
        board[row][col]=1;
    }    
    
    cin >> change;
    for(int i=0; i<change; i++){
        int time;
        char command;
        cin >> time >> command;
        changes.push({time, command});
    }

    //입력 끝
    tail.push({1,1});
    board[1][1]=2;

    do{
        //방향전환하냐?
        if(!changes.empty()&&changes.front().first==totalTime){
            if(changes.front().second=='D'){
                currentWay+=1;
            }else{
                currentWay+=3;
            }
            currentWay%=4;
            changes.pop();
        }
        //이동
        X = X+xx[currentWay];
        Y = Y+yy[currentWay]; 
        
        //이동했는데 범위 벗어나나?
        if(X<1||Y<1||X>N||Y>N){
            break;
        }
        
        //몸통이 이미 있냐?
        if(board[Y][X]==2){
            break;
        }

        board[Y][X]=2;
        tail.push({X,Y});

        //사과가 없냐?
        if(board[Y][X]!=1&&board[Y][X]!=2){
            board[tail.front().second][tail.front().first]=0;
            tail.pop();
        }
        totalTime++;
    }while(true);
    cout<<totalTime+1;
}
