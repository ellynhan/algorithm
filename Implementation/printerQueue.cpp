#include <iostream>
#include <queue>
using namespace std;

int main(){
    int testCase;
    cin >> testCase;
    while(testCase--){
        queue<pair<int, int>> priors;
        priority_queue<int> q;
        int nums, curious;
        cin >> nums >> curious;
        for(int i=0; i<nums; i++){
            int p;
            cin >> p;
            priors.push({i,p});
            q.push(p);
        }
        int cnt = 1;
        while(!q.empty()){
            if(priors.front().second == q.top()){
                if(priors.front().first == curious){
                    cout << cnt <<endl;
                    break;
                }else{
                    priors.pop();
                    q.pop();
                    cnt++;
                }
            }else{
                priors.push(priors.front());
                priors.pop();
            }
        }
    }    
}
