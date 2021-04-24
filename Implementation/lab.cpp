#include <iostream>
#include <map>
#include <queue>
#include <stack>
using namespace std;

int n, m;
int lab[10][10]={0};
int xx[4]={-1,0,1,0}; //왼 위 오 아
int yy[4]={0,-1,0,1};
int blanc = -3;
int maxi = 0;
vector<pair<int, int>> virus;

void bfs(){
    queue<pair<int, int>> q;
    int visit[10][10]={0,};
    int total = 0;
    for(int i=0; i<virus.size(); i++){
        q.push(virus[i]);
        visit[virus[i].first][virus[i].second]=1;
    }
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int Y = y+yy[i];
            int X = x+xx[i];
            if(lab[Y][X]==0 && visit[Y][X]==0){
                visit[Y][X]=1;
                q.push({Y,X});
                total ++;
            }
        }
    }
    if(maxi<blanc - total){
        maxi = blanc - total;
    }
}


void fillBlock(pair<int, int> curr, int nums){
    if(nums == 3){
        bfs();
    }else{
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
               if(((curr.first==i&&curr.second<j)||(curr.first<i))&&lab[i][j]==0){
                    lab[i][j]=1;
                    fillBlock({i,j},nums+1);
                    lab[i][j]=0;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m; //y, x
    for(int i=0; i<n+2; i++){
        if(i==0 || i==n+1){
            for(int j=1; j<m+1; j++){
                lab[i][j]=1;
            }
        }else{
            for(int j=0; j<m+2; j++){
                if(j==0 || j==m+1){
                    lab[i][j]=1;
                }else{
                    cin >> lab[i][j];
                    if(lab[i][j]==2){
                        virus.push_back({i,j});
                    }else if(lab[i][j]==0){
                        blanc ++;
                    }
                }
            }
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(lab[i][j]==0){
                lab[i][j]=1;
                fillBlock({i,j}, 1);
                lab[i][j]=0;
            }
        }
    } 
    cout<<maxi;
}
