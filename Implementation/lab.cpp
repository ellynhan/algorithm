//11시30분
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lab[10][10];
int xx[4]={-1,0,1,0};// 왼 위 오 아
int yy[4]={0,-1,0,1};
vector<pair<int, int>> virus;
int affected[100]={0};
int safe=0;

void bfs(int v){
    int visited[10][10]={0};
    queue<pair<int, int>> q;
    q.push(virus[v]);
    visited[virus[v].first][virus[v].second]=1;
    while(!q.empty()){
        int nextX = q.front().second;
        int nextY = q.front().first;
        if(q.size()==1&&affected[v]!=0){
            break;
        }
        q.pop();
        for(int i=0; i<4; i++){
            if(lab[nextY+yy[i]][nextX+xx[i]]==0&&visited[nextY+yy[i]][nextX+xx[i]]==0){
                q.push({nextX+xx[i],nextY+yy[i]});
                visited[nextY+yy[i]][nextX+xx[i]]=1;
                affected[v]++;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >>  m;
    int nums=0;
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(j==0||j==n||i==0||i==n){
                lab[i][j]=1;
            }else{
                cin>>lab[i][j];
                if(lab[i][j]==2){
                    virus.push_back({i,j});
                }else if(lab[i][j]==0){
                    safe++;
                }
            }
        }
    }
    cout<<"safezoon: "<< safe<<endl;
    for(int i=0; i<virus.size(); i++){
        bfs(i);
        cout<<affected[i]<<" ";
    }

    for(int i=0; i<virus.size(); i++){
        int x = virus[i].second;
        int y = virus[i].first;
        
    }

}
