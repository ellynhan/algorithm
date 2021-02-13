#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    char curr = s[0];
    for(int i=0; i<s.size(); i++){
        if(curr==s[i]){
            cnt ++;
        }else{
            curr=s[i];
            answer.push_back(cnt);
            cnt=1;
        }
    }
    answer.push_back(cnt);
    if(s[0]==s[s.size()-1]){
        answer[0]+=answer[answer.size()-1];
        answer.pop_back();
    }
    sort(answer.begin(), answer.end());
    return answer;
}

/*
"aaabbaaa" -> {2,6}
"wowwow" ->{1,1,2,2}
*/