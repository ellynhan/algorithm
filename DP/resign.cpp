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

    for(int i=0; i<n; i++){ // 각 날짜별 최대값을 얻고 싶음
        int maxPay=i>0 ? maxEarn[i-1] : 0;
        for(int j=0; j<=i; j++){//일 시작 날짜
            if(j+durationPay[j].first==i+1){
                if(maxPay<maxEarn[j-1]+durationPay[j].second){
                    maxPay = maxEarn[j-1]+durationPay[j].second;
                }
            }
        }
        if(maxPay==0){
            maxEarn[i] = maxEarn[i-1];
        }else{
            maxEarn[i] = maxPay;
        }
    }
    cout<<maxEarn[n-1];
}
