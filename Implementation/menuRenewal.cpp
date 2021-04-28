#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
map<string, int> m;
int minLen, maxLen;
void powerset(string str)
{
    int n = str.length();
    int max = 1<<n;
    for(int i=0;i<max;i++){
        string sub="";
        for(int j=0;j<n;j++){
            if(i & (1<<j)) sub+=str[j];
        }
        sort(sub.begin(), sub.end());
        if(sub.length()>=minLen&&sub.length()<=maxLen){
            if(m.count(sub)>0){
                m[sub]+=1;
            }else{
                m[sub]=1;
            }
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    map<int, vector<string> > cmp;
    int best[21]={0};
    
    //str길이별, 개수별.
    vector<string> answer;
    minLen = course[0];
    maxLen = course[course.size()-1];

    //가능한 부분 집합들 모음
    for(int i=0; i<orders.size(); i++){
        powerset(orders[i]);
    }

    map<string, int>::iterator it;
    for(it=m.begin(); it!=m.end(); it++){
        int len = (it->first).length();
        if(best[len]<it->second&&it->second>1){
            best[len]=it->second;
            cmp[len].clear();
            cmp[len].push_back(it->first);
        }else if(best[len]==it->second){
            cmp[len].push_back(it->first);
            best[len] = it->second;
        }
    }

    for(int i=0; i<course.size(); i++){
        vector<string> tmp = cmp[course[i]];
        for(int j=0; j<tmp.size(); j++){
            answer.push_back(tmp[j]);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
    
}
