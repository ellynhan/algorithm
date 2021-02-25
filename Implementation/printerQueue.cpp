#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

typedef struct File{
    int order;
    int prior;
}files;

int main(){
    
    int testCase;
    cin >> testCase;
    while(testCase--){
        priority_queue<int> priors;
        deque<files*> f;
        int p[9]={0,};
        int n, curious;
        cin >> n >> curious;
        for(int i=0; i<n; i++){
            int important;
            cin >>important;
            files* tmp = new files;
            tmp->order = i;
            tmp->prior = important;
            f.push_back(tmp);

            if(p[important-1]==0){
                priors.push(important);
                p[important-1]=1;
            }
            
        }
        int cnt = 0;
        bool getAnswer = false;
        while(!getAnswer){
            while(!getAnswer&&f.front()->prior == priors.top()){
                cnt++;
                if(f.front()->order == curious){
                    cout<<cnt<<endl;
                    getAnswer = true;
                    break;
                }
                f.pop_front();
                priors.pop();
            }
            while(!getAnswer&&f.front()->prior != priors.top()){
                f.push_back(f.front());
                f.pop_front();
            }
        }
        
    }
}
