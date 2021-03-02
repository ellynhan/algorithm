//1009
#include <iostream>
#include <queue>
using namespace std;

int w=1, h=1;
int y[8] = {-1,-1,-1,0,0,1,1,1};
int x[8] = {-1,0,1,-1,1,-1,0,1};
int M[50][50];
int V[50][50]={0,};

void bfs(pair<int, int> pos){
    queue<pair<int, int> > q;
    q.push(pos);
    V[pos.first][pos.second]=1;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        for(int i=0; i<8; i++){
            int xx = p.second + x[i];
            int yy = p.first + y[i];
            if(xx>=0 && y>=0 && xx<w && yy<h && M[yy][xx]==1 && V[yy][xx]==0){
                q.push({yy,xx});
                V[yy][xx]=1;
            }
        }
    }
}

int main(){
    while(w!=0&&h!=0){
        cin >> w >> h;
        if(w==0 && h==0)break;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> M[i][j];
                V[i][j]=0;
            }
        }
        int total =0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(M[i][j]==1 && V[i][j]==0){
                    bfs({i,j});
                    total++;
                }
            }
        }
        cout<<total<<endl;
    }
}
