//1112 1127
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int visited[1001];
vector<int> v[1001];
int total = 0 ;
void bfs(int country){
    queue<int> q;
    q.push(country);
    visited[country]=1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i=0; i<v[curr].size(); i++){
            if(visited[v[curr][i]]==0){
                q.push(v[curr][i]);
                visited[v[curr][i]]=1;
                total ++;
            }
        }
    }
}

int main(){
    int testCase,n,m;
    cin >> testCase;
    while(testCase--){
        cin >> n >> m;
        for(int i=1; i<=n; i++){
            visited[i]=0;
            v[i].clear();
        }
        for(int i=0; i<m; i++){
            int c1, c2;
            cin >> c1 >> c2;
            v[c1].push_back(c2);
            v[c2].push_back(c1);
        }
        total = 0;
        bfs(1);
        cout<<total<<endl;
    }
} 
