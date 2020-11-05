#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    vector<int> answer;
    int testcase;
    cin>>testcase;
    vector<pair<int,int>> scores;
    for(int i=0; i<testcase; i++){
        int number;
        cin>>number;
        for(int j=0; j<number; j++){
            pair<int,int> temp;
            cin>>temp.first;
            cin>>temp.second;
            scores.push_back(temp);
        }
        sort(scores.begin(), scores.end());
        int max = scores[0].second;
        int count =0;
        for(int j=1; j<number; j++){
            if(scores[j].second<max){
                count++;
                max=scores[j].second;
            }
        }
        answer.push_back(count+1);
        scores.clear();
    }
    for(int i=0; i<testcase; i++){
        cout<<answer[i]<<endl;
    }
}
