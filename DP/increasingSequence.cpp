#include <iostream>
using namespace std;

int dp[1001]={0,};
int a[1000];

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    dp[a[0]]=1;
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<i; j++){
            if(a[i]>a[j]){
                dp[a[i]]=max(dp[a[i]],dp[a[j]]+1);
                cnt ++;
            }
        }
        if(cnt == 0){
            dp[a[i]]=1;
        }
    }
    int maxValue = 0;
    for(int i=0; i<n; i++){
        if(maxValue<dp[a[i]]){
            maxValue = dp[a[i]];
        }
    }
    cout << maxValue;
}
