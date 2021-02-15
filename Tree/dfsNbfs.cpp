
#include <iostream>
#include <queue>
using namespace std;

typedef struct Node{
    priority_queue<int, vector<int>, greater<int>> adj;
}node;

// int adj[1001][1001];
node nodes[1001];
int visited[1001]={0,};


void dfs(int vertex){
    cout << vertex <<" ";
    visited[vertex] = 1;
    cout<<"시작"<<endl;
    while(!nodes[vertex].adj.empty()){

        int next = nodes[vertex].adj.top();
        nodes[vertex].adj.pop();
        while(visited[next]!=0){
            next = nodes[vertex].adj.top();
            nodes[vertex].adj.pop();
        }
        dfs(next);
    }
    cout<<"종료"<<endl;
    return ;
}

 
void bfs(int vertex){ 

}

int main(){
   int M, N, start;
   cin >> N >> M >> start;
   for(int i=0; i<M; i++){
    int index, child;
    cin >> index >> child;
    nodes[index].adj.push(child);
    nodes[child].adj.push(index);
   }
   dfs(start);
}

