#include <iostream>
using namespace std;
int N[10]={0,};
int n;

int getN(int n){
    int N_1 =0, N_2 =0, N_3 = 0;
    if(n>=1){
        N_1 = N[n-1] == 0 ? getN(n-1) : N[n-1];
    }
    if(n>=2){
        N_2 = N[n-2] == 0 ? getN(n-2) : N[n-2];
    }
    if(n>=3){
        N_3 = N[n-3] == 0 ? getN(n-3) : N[n-3];
    }
    return N_1 + N_2 + N_3;
}


int main(){
    int testCase;
    cin >> testCase;
    N[0]=1;
    N[1]=2;
    N[2]=4;
    while(testCase--){
        cin >> n;
        if(n<4){
            cout<<N[n-1]<<endl;
        }else{
            if(N[n-1]==0){
                cout<< getN(n-1) <<endl;
            }else{
                cout<<N[n-1]<<endl;
            }
        }
    }
}
