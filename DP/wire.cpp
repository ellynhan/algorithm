#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int* wire = new int[n];
    int* dp = new int[n];
    map<int, int> conn;
    map<int, int>::iterator it;
    for(int i=0; i<n; i++){
        int A, B;
        cin >> A >> B;
        conn[A] = B;
        dp[i]=1;
    }
    int index = 0;
    for(it=conn.begin(); it!=conn.end(); it++){
        wire[index] = it->second;
        index++; 
    }

    for(int i=n-2; i>=0; i--){
        for(int j=i; j<n; j++){
            if(wire[i]<wire[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int maxValue=0;
    for(int i=0; i<n; i++){
        maxValue = max(maxValue, dp[i]);
    }
    cout<<n-maxValue;
} 

// 연결된 순서대로 나열한다음에 뒤에서부터 DP