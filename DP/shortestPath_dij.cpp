#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map<pair<int,int> , int> edges;
map<int, vector<int> > conn;
int dp[20001];
int v,e,start;
priority_queue<pair<int, int> > pq;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e >> start;
    for(int i=0; i<e; i++){
        int from, to, w;
        cin >> from >> to >> w;
        if(edges.count({from,to})>0){
            edges[{from,to}]=min(w,edges[{from,to}]);
        }else{
            edges[{from,to}]=w;
            conn[from].push_back(to);
        }
    }

    for(int i=1; i<=v; i++){
        dp[i]=200001; //가중치 max 초기화
    }

    dp[start]=0;
    pq.push({0,start});

    while(!pq.empty()){
        int dist = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(dp[curr] < dist)continue;
        for(int i=0; i<conn[curr].size(); i++){
            int next = conn[curr][i];
            int next_dist = dist + edges[{curr,next}];
            if(next_dist < dp[next]){
                dp[next]=next_dist;
                pq.push({-next_dist,next});
            }
        }
    }

    for(int i=1; i<=v; i++){
        if(dp[i]!=200001){
            cout<<dp[i]<<'\n';
        }else{
            cout<<"INF\n";
        }
    }
}  
