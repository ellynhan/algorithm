#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int cnt[3] = {0};
    int maxValue = 0;
    for(int i=0; i<arr.size(); i++){
        cnt[arr[i]-1]++;
    }
    for(int i=0; i<3; i++){
        maxValue = max(cnt[i],maxValue);
    }
    
    vector<int> answer;
    
    for(int i=0; i<3; i++){
        answer.push_back(maxValue-cnt[i]);
    }
    
    return answer;
}

/*
{2,1,3,1,2,1} -> {0,1,2}
{3,3,3,3,3,3} -> {6,6,0}
{1,2,3} -> {0,0,0}
*/