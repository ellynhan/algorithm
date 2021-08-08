#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int answer  = 0;
    int m=1;
    for(int i=1; i<=n; i++){
        m*=i;
        while(m%10==0){
            m/=10;
            answer ++;
        }
        m%=10000;
    }
    cout<<answer;
}