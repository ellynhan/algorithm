#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > durationPay;
int maxEarn[16]={0,};
int n;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int duration, pay;
        cin >> duration >> pay;
        durationPay.push_back({duration, pay});
    }

    for(int i=0; i<=n; i++){ // 각 날짜별 최대값을 얻고 싶음
        for(int j=0; j<i; j++){
            if(j+durationPay[j].first==i){
                if(maxEarn[i]<maxEarn[j]+durationPay[j].second){
                    maxEarn[i] = maxEarn[j]+durationPay[j].second;
                }
            }
        }
        if(maxEarn[i]==0&&i>0){
            maxEarn[i] = maxEarn[i-1];
        }
    }
    cout<<maxEarn[n];
}
