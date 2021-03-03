#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int num){
    if(num<2){
        return false;
    }else{
        int max = int(sqrt(num));
        for(int i=2; i<=max; i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
}


int main() {
    int N;
    cin>>N;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1){
        string str = to_string(N);
        int i=0;
        for(i=0; i<str.length()/2; i++){
            if(str[i]!=str[str.length()-1-i]){
                break;
            }
        }
        if(i==str.length()/2&&isPrime(N)){
            cout<<N;
            break;
        }
        N++;
    }
}
