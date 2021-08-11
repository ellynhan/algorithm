#include <iostream>
#include <stack>
#include <vector>
using namespace std; 

int main(void) {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int n, num;
    cin >> n;
    stack<int> idx;
    vector<int> values;
    vector<int> answers;

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        values.push_back(num);
        answers.push_back(-1);
        while(!idx.empty()&&values[idx.top()]<num&&answers[idx.top()]==-1){
            answers[idx.top()]=num;
            idx.pop();
        }
        idx.push(i);
    }

    for(int i=0; i<n; i++){
        cout<<answers[i]<<" ";
    }
}
