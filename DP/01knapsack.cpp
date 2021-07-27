#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> weight_value;
int dp[101][100001]={0};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sorts, maxWeight;
    cin >> sorts >> maxWeight;
    for(int i=0; i<sorts; i++){
        int w, v;
        cin >> w >> v;
        weight_value.push_back({w,v});
    }
    for(int i=1; i<=sorts; i++){
        for(int j=1; j<=maxWeight; j++){
            int W = weight_value[i-1].first;
            int V = weight_value[i-1].second;
            if(W>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-W]+V);
            }
        }
    }
    cout<<dp[sorts][maxWeight];
} 