//0442
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    return a.size()<b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> vv;
    int before=0; //num 0 notnum 1
    vector<int> tmp;
    string str="";
    for(int i=1; i<s.length()-1; i++){
        if(s[i]>='0'&&s[i]<='9'){
            str+=s[i];
            before = 0;
        }else if(before==0&&s[i]=='}'){
            tmp.push_back(stoi(str));
            vv.push_back(tmp);
            tmp.clear();
            str="";
            before = 1;
        }else if(before==0&&s[i]==','){
            tmp.push_back(stoi(str));
            str = "";
            before = 1;
        }else{
            before = 1;
        }
    }
    sort(vv.begin(), vv.end(), cmp);
    set<int> S;
    for(int i=0; i<vv.size(); i++){
        for(int j=0; j<vv[i].size(); j++){
            if(S.count(vv[i][j])==0){
              answer.push_back(vv[i][j]);
                S.insert(vv[i][j]);
            }
        }
    }
    return answer;
}
