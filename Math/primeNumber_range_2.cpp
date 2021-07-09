#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool prime[246913];
    fill_n(prime, 246913, true);
    while(n){
        for(int i=2; i*i<=2*n; i++){
            if(prime[i]==true){
                for(int j=i*i; j<=2*n; j+=i){
                    prime[j]=false;
                }
            }
        }
        int cnt = 0;
        for(int i=n+1; i<=2*n; i++){
            if(prime[i]){
                cnt++;
            }
        }

        cout<<cnt<<'\n';
        cin >> n;
    }
}