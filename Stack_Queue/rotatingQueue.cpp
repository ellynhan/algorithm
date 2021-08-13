#include <iostream>
#include <queue>
#include <deque>
#include <vector>
using namespace std; 

int main(void) {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int len, nums;
    cin >> len >> nums;
    deque<int> dq;
    deque<int> dqR;
    deque<int> dqL;
    int answer = 0;
    for(int i=1; i<=len; i++){
        dq.push_back(i);
    }
    vector<int> v;
    for(int i=0; i<nums; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int i=0; i<nums; i++){
        if(dq.front()==v[i]){
            dq.pop_front();
        }else{
            int cntR=0, cntL=1;
            dqR = dq;
            dqL = dq;
            while(dqR.front()!=v[i]){
                dqR.push_back(dqR.front());
                dqR.pop_front();
                cntR++;
            }
            while(dqL.back()!=v[i]){
                dqL.push_front(dqL.back());
                dqL.pop_back();
                cntL++;
            }
            if(cntR<cntL){
                answer += cntR;
                dq = dqR;
                dq.pop_front();
            }else{
                answer += cntL;
                dq = dqL;
                dq.pop_back();
            }
        }
    }
    cout<<answer;
}
