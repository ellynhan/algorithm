#include <iostream>
#include <queue>

using namespace std;
int N, M;
int box[1000][1000] = {0,};
int visited[1000][1000] = {0,};
int distances[1000][1000] = {0,};
int checked = 0;
//상하좌우
int xx[4] ={0,0,-1,1};
int yy[4] ={1,-1,0,0};

 int bfs(pair<int, int> start){
    int maxDistance = 0;
    queue<pair<int, int>> q;
    q.push(start);
    while(!q.empty()){
        pair<int, int> next = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int y = next.first + yy[i];
            int x = next.second + xx[i];
            if(x>=0 && y>=0 && x<M && y<N && box[y][x] != 1 && visited[y][x] == 0){
                if(box[y][x] == 0){
                    q.push({y,x});
                    box[y][x] = 1;
                    visited[y][x] = 1;
                    distances[y][x] = distances[next.first][next.second] + 1;
                    if(maxDistance<distances[y][x]){
                        maxDistance = distances[y][x];
                    }
                }
                checked ++;
            }
        }
    }
    return maxDistance;
 }

int main(){
    cin >> M >> N; //가로, 세로
    int total = 0 ;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> box[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(box[i][j]==-1 && visited[i][j]== 0){
                visited[i][j] = 1;
            }
            if(box[i][j]==1 && visited[i][j] == 0){
                visited[i][j] = 1;
                total += bfs({i,j});
            }
        }
    }
    // cout<<"total distance sum: "<<total<<endl;
    // cout<<"total checked one: "<<checked;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(box[i][j] == 0){
                cout <<-1;
                return 0 ;
            }
        }
    }
    cout<<total;
    
}
