#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int base;
    cin >> base;
    for(int i=1; i<n; i++){
        int tmp;
        cin >> tmp;
        int big = base>tmp?base:tmp;
        int small = base>tmp?tmp:base;
        int factor = 2;
        while(factor<=big || factor<=small){
            if(big%factor==0 && small%factor==0){
                big/=factor;
                small/=factor;
            }else{
                factor ++;
            }
        }
        if(base>tmp){
            cout<<big<<"/"<<small<<"\n";
        }else{
            cout<<small<<"/"<<big<<"\n";
        }
    }
}