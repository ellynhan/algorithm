#include <iostream>
using namespace std;
int main(){
    int testCase;
    cin >> testCase;
    while(testCase--){
        int a, b;
        cin >> a >> b;
        int answer = 1;
        int big = a>b?a:b;
        int small = a>b?b:a;
        if(big%small==0){
            cout<<big<<endl;
        }else{
            int factor = 2;
            while(factor<=big||factor<=small){
                if(big%factor == 0){
                    answer *= factor;
                    big/=factor;
                    if(small%factor == 0){
                        small/=factor;
                    }
                }else if(small%factor==0){
                    answer *= factor;
                    small/=factor;
                }else{
                    factor ++;
                }
            }
            cout<<answer<<endl;
        }
    }
}