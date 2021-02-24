#include <iostream>
#include <string>

int dp[1001][1001]={0,};
using namespace std;
int main(){
    string s1, s2, big, small;
    cin >> s1 >> s2;
    int cnt =0;
    if(s1.length()>=s2.length()){
        big = s1;
        small = s2;
    }else{
        big = s2;
        small = s1;
    }
    for(int i=0; i<small.length(); i++){
        for(int j=0; j<big.length(); j++){
            if(small[i]==big[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }else{
                dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1]);
            }

        }
    }
    cout<<dp[small.length()][big.length()];
    
}
