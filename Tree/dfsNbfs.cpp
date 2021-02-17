#include <iostream>
#include <queue>
using namespace std;

int N, M, start;
int adj[1001][10001]={0,};
int visited[2002] = {0,};

void dfs(int vertex){
    visited[vertex] = 1;
    cout<<vertex<<" ";
    for(int i=1; i<=N; i++){
        if(adj[vertex][i] == 1 && visited[i] == 0){
            dfs(i);
        }
    }
    return ;
}

 
void bfs(int vertex){
    queue<int> q;
    q.push(vertex);
    visited[vertex + 1001] = 1;
    while(!q.empty()){
        int start = q.front();
        q.pop();
        cout<<start<<" ";
        for(int i=1; i<=N; i++){
            if(adj[start][i]== 1 && visited[i+1001] == 0){
                q.push(i);
                visited[i+1001] = 1;
            }
        }
    }
    return ;
}

int main(){
   cin >> N >> M >> start;
   for(int i=0; i<M; i++){
    int x, y;
    cin >> x >> y;
    adj[x][y] = 1;
    adj[y][x] = 1;
   }

   dfs(start);
   cout<<endl;
   bfs(start);
}
