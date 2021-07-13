#include <iostream>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    int notPrime[10001]={0,};
    while(testCase--){
        int n;
        cin >> n;
        for(int i=2; i*i<n; i++){
            if(notPrime[i]==0){
                for(int j=i*i; j<n; j+=i){
                    notPrime[j]=1;
                }
            }
        }

        int min = n;
        int num;
        for(int i=2; i<n/2+1; i++){
            if(notPrime[i]==0&&notPrime[n-i]==0){
                if(min>n-2*i){
                    min = n-2*i;
                    num = i;
                }
            }
        }
        cout<<num<<" "<<n-num<<'\n';
    }
}