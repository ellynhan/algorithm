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
    vector<int> score;
    for(int i=0; i<info.size(); i++){
        istringstream buf(info[i]);
        string word;
        for(int j=0; j<4; j++){
            buf >> word;
            if(m.count(word)>0){
                m[word].push_back(i);
            }else{
                vector<int> v = {i};
                m[word]=v;
            }
        }
        buf >> word;
        score.push_back(stoi(word));
    }
    
    for(int i=0; i<query.size(); i++){
        int total = 0;
        istringstream buf(query[i]);
        string word;
        map<int, int> check;
        for(int j=0; j<info.size(); j++){
            check[j]=0;
        }
        int checkNum = 4;
        for(int j=0; j<4; j++){
            buf >> word;
            if(word=="-"){
                checkNum --;
            }else{
                if(m[word].size()==0){
                    break;
                }else{
                    for(int k=0; k<m[word].size(); k++){
                        check[m[word][k]] ++;
                    }
                }
            }
            buf >> word;
        }
        buf >> word;
        map<int, int>::iterator it;
        for(it=check.begin(); it!=check.end(); it++){
            if(it->second == checkNum && score[it->first]>=stoi(word)){
                total++;
            }
            
        }
        answer.push_back(total);
    }
    return answer;
}

int main(){
    solution({"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"},{"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"});

}
