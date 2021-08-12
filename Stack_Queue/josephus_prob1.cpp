#include <iostream>
#include <queue>
#include <vector>
using namespace std; 

int main(void) {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int n,k,cnt=1;
    cin >> n >> k;
    queue<int> q;
    vector<int> answer;
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    while(!q.empty()){
        if(cnt%k==0){
            answer.push_back(q.front());
            q.pop();
        }else{
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cnt++;
    }
    cout<<"<"<<answer[0];
    for(int i=1; i<answer.size(); i++){
        cout<<", "<<answer[i];
    }
    cout<<">";
}
