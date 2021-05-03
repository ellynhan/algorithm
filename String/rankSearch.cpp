//0419
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;
vector<int> solution(vector<string> info, vector<string> query) {
    //개발언어 직군 경력 소울푸드 점수 50000개 이하
    vector<int> answer;
    map<string, vector<int>> m;
    for(int i=0; i<info.size(); i++){
        istringstream buf(info[i]);
        for(int j=0; j<4; j++){
            string word;
            buf >> word;
            if(m.count(word)>0){
                m[word].push_back(i);
            }else{
                vector<int> v = {i};
                m[word]=v;
            }
        }
    }
    
    for(int i=0; i<query.size(); i++){
        istringstream buf(query[i]);
        int num = -1;
        int total  =0;
        map<int, int> cnt;
        int checkNum = 2;
        string word;
        for(int j=0; j<4; j++){
            buf >> word;
            if(word=="-"){
                num -= 1;
                checkNum -= 1;
            }else{
                if(m[word].size()==0){
                    break;
                }
                for(int k=0; k<m[word].size(); k++){
                    if(cnt.count(m[word][k])>0){
                        if(cnt[m[word][k]]==num){
                            cnt[m[word][k]]++;
                            if(num == checkNum){
                                total ++;
                            }
                        }
                    }else{
                        cnt[m[word][k]]= 0;
                    }
                }
                num++;
            }
            buf>> word; //and
        }
        answer.push_back(total);
    }
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<" ";
    }
    return answer;
}

int main(){
    solution({"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"},{"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"});

}
