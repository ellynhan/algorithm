//0340 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Node{
    int first = 0;
    int second = 0;
    vector<int> children;
}node;

int weights[10000][10000];
node nodes[10000];


int dfs(int parent){
    if( nodes[parent].children.size()==0){
        return 0;
    }else{
        int M=0;
        for(int i=0; i<nodes[parent].children.size(); i++){
            int child = nodes[parent].children[i];
            int result = dfs(child);
            int next = weights[parent][child]+result;
            if(nodes[parent].first < next){
                nodes[parent].second = nodes[parent].first;
                nodes[parent].first = next;
            }else if(nodes[parent].second < next){
                nodes[parent].second = next;
            }
        }
    }
    return nodes[parent].first;
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int parent, child, weight;
        cin >> parent >> child >> weight;
        nodes[parent].children.push_back(child);
        weights[parent][child]=weight;
    }

    dfs(1);

    int max = 0;
    for(int i=1; i<n; i++){
        if(max < nodes[i].first + nodes[i].second){
            max = nodes[i].first + nodes[i].second;
        }
    }
    cout<<max;
}
