#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;


int main(){
    int n;
    cin >> n;
    set<int> days;
    set<int>::iterator it;
    map<int, long long> dp;
    map<int, long long>::iterator it2;
    map<int, vector<pair<int,int>>> info;
    days.insert(0);
    dp[0]=0;
    for(int i=0; i<n; i++){
        int start, end, reward;
        cin >> start >> end >> reward;
        info[end].push_back({start,reward});
        days.insert(start);
        days.insert(end);
    }
    
    for(it=days.begin(); it!=days.end(); it++){
        int day = *it;
        if(!dp.count(day)){//dp 기록이 없다면 이전 기록의 값을 그대로 불러옴
            advance(it,-1);
            dp[day]=dp[*it];
            advance(it,1);
        }
        if(info.count(day)){ //해당날에 종료되는 대회가 있음
            for(int i=0; i<info[day].size(); i++){//day날에 종료하는 여러가지 대회들을 비교함
                int startDay = info[day][i].first;
                int reward = info[day][i].second;
                dp[day]=max(dp[day], dp[startDay-1]+reward);
            }
        }
    }
    it2 = dp.end();
    advance(it2,-1);
    cout<<it2->second;
}