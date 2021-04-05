#include <iostream>
#include <map>
using namespace std;

int P[250000];
long long answer = 1;

int main(){
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> P[i];
    }
    map<int, int> depth;
    map<int, int> ::iterator it;

    depth[P[0]]=1;
    for(int i=1; i<n; i++){
        depth.insert({P[i],0});
        it = depth.find(P[i]);
        long long left=0,right=0;

        if(it!=depth.begin()){
            left=(--it)->second;
            it++;
        }
        if((++it)!=depth.end()){
            right=it->second;
        }
        
        depth[P[i]]=left > right ? left+1 : right+1;

        answer += depth[P[i]];
    }
    cout<<answer;
}
