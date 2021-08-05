#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    int a_s[10001]={0};
    int b_s[10001]={0};
    int divider = 2;
    int big = a>b?a:b;
    while(a!=1){
        if(a%divider==0){
            a/=divider;
            a_s[divider]++;
        }else{
            divider ++;
        }
    }
    divider = 2;
    while(b!=1){
        if(b%divider==0){
            b/=divider;
            b_s[divider]++;
        }else{
            divider ++;
        }
    }
    int min=1, max=1;
    for(int i=1; i<=big; i++){
        if(a_s[i]!=0){
            if(b_s[i]!=0){
                int smaller = a_s[i]>b_s[i]?b_s[i]:a_s[i];
                int bigger = a_s[i]>b_s[i]?a_s[i]:b_s[i];
                for(int j=0; j<smaller; j++){
                    min*=i;
                }
                for(int j=0; j<bigger; j++){
                    max*=i;
                }
            }else{
                for(int j=0; j<a_s[i]; j++){
                    max*=i;
                }
            }
        }else if(b_s[i]!=0){
            for(int j=0; j<b_s[i]; j++){
                max*=i;
            }
        }
    }
    cout<<min <<'\n'<< max;
}