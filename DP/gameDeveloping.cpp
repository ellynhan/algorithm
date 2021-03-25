#include <iostream>
#include <queue>
using namespace std;

int numOfParents[501]={0,};
queue<int> children[501];
int buildTimes[501]={0,};
int totalTimes[501]={0,}; //dp

int main(){
    int n;
    cin >> n;
    queue<int> noParents;
    for(int i=1; i<=n; i++){
        cin >> buildTimes[i];
        int parent;
        cin >> parent;
        int cnt = 0;
        while(parent!=-1){
            cnt ++;
            children[parent].push(i);
            numOfParents[i]++;
            cin >> parent;
        }
        if(cnt==0){
            noParents.push(i);
        }
    }

    while(!noParents.empty()){
        int node = noParents.front();
        totalTimes[node]+=buildTimes[node];
        while(!children[node].empty()){
            int child = children[node].front();
            children[node].pop();
            numOfParents[child]--;
            totalTimes[child]=max(totalTimes[node],totalTimes[child]); //이 부분이 핵심.. 
            if(numOfParents[child]==0){
                noParents.push(child);
            }
        }
        noParents.pop();
    }

    for(int i=1; i<=n; i++){
        cout<<totalTimes[i];
        if(i!=n)cout<<endl;
    }
}
