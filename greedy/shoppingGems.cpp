
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer={0,int(gems.size())-1};
    //우선 총 보석이 종류가 얼마나 있는지를 확인해봐야겠지? 
    map<string, int> kind;
    int totalSort=0;
    for(int i=0; i<gems.size(); i++){
        if(kind.count(gems[i])<=0){
            kind[gems[i]]=totalSort;
            totalSort+=1;
        }
    }//이제 kind의 사이즈가 보석의 종 종류수임.
    totalSort = kind.size();

    if(totalSort==1){
        return {1,1};
    }else if(totalSort==gems.size()){
        return {1,int(gems.size())};
    }else{
        map<string, int> loc; //보석당 위치 저장
        vector<int> total_cnt;//종류별 개수 저장
        int cnt=0;//현재까지 종류수 저장
        int i=0;
        while(i<gems.size()){
            if(loc.count(gems[i])>0){//나왔던거임
                loc[gems[i]]=i;//위치 갱신함
            }else{
                cnt ++;
                loc[gems[i]]=i;
                if(cnt == totalSort){//보석 종류 다나왔음, 길이를 재자.
                    map<string, int>::iterator it;
                    int minStart=i,secondStart;
                    for(it=loc.begin(); it!=loc.end(); it++){
                        if(it->second<minStart){
                            secondStart = minStart;
                            minStart=it->second;
                        }
                    }
                    if(answer[1]-answer[0]>i-minStart){
                        answer[1]=i;
                        answer[0]=minStart;
                    }
                    cnt --;
                    loc.erase(gems[minStart]);
                    i = secondStart;
                }
            }
            i++;
        }
    }
    return {answer[0]+1,answer[1]+1};
}

int main(){
    vector<int> s = solution({"ZZZ", "ZZZ", "TTT"});
    for(int i=0; i<s.size(); i++){
        cout<<s[i]<<" ";
    }
}
