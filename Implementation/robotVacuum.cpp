#include <iostream>
#include <vector>
using namespace std;
int n, m;
int house[50][50]={0};
int cnt = 0;
int xx[4] = {0,1,0,-1};
int yy[4] = {-1,0,1,0};

void steps(int r, int c, int d, int checkCnt){
    int newY = r+yy[(d+3)%4];
    int newX = c+xx[(d+3)%4];
    int newD = (d+3)%4;
    if(house[newY][newX]==0){
        cnt ++;
        house[newY][newX]=2;
        steps(newY, newX, newD,0);
    }else{
        if(checkCnt==3){
            int backY = r+yy[(newD+2)%4];
            int backX = c+xx[(newD+2)%4];
            if(house[backY][backX]!=1){
                steps(backY, backX, newD, 0);
            }else{
                return ;
            }
        }else{
            steps(r,c,newD, checkCnt+1);
        }
    }
}

int main(){ 
    cin >> n >> m;
    int r, c, d; //d 0 위 1 오 2 아래 3 왼  // 왼쪽3, 0위쪽, 1오른쪽, 2아래쪽 i+3%4 
    cin >> r >> c >> d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> house[i][j];
        }
    }
    house[r][c]=2;
    cnt ++;
    steps(r,c,d,0);
    
    
    cout<<cnt;
    
}

//바라보는 방향에서 왼쪽에 청소 x -> 그 방향으로 이동하고 청소
//왼쪽에 청소되어있으면 그냥 회전만. 왼 -> 아 -> 오 -> 위
//네 방향 모두 청소가 되어있거나 벽인경우 후진. 왼 -> 아 -> 오 -> 위 확인후 아래로 감

