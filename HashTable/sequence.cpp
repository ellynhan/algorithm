#include <iostream>
using namespace std;

int main(){
    int l;
    long long H=0;
    string str;
    cin >> l >> str;
    long power = 1;
    for(int i=0; i<l; i++){
        H += (str[i]-'a'+1)*power%1234567891;
        power*=31;
        H%=1234567891;
        power%=1234567891;
    }
    cout<< H;

}