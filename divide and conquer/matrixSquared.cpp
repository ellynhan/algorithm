#include <iostream>
using namespace std;

int matrix[5][5];
int current[5][5];
int n;
long long b;

void multiply(int isJustOne){
    int result[5][5];
    if(isJustOne){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                result[i][j]=0;
                for(int k=0; k<n; k++){
                    result[i][j]+=current[i][k]*matrix[k][j]%1000;
                }
            }
        }
    }else{
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                result[i][j]=0;
                for(int k=0; k<n; k++){
                    result[i][j]+=current[i][k]*current[k][j]%1000;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            current[i][j]=result[i][j]%1000;
        }
    }
}

void divide(long long cnt){
    if(cnt==1){
        return ;
    }else if(cnt%2==0){
        divide(cnt/2);
        multiply(0);
    }else{
        cnt-=1;
        divide(cnt/2);
        multiply(0);
        multiply(1);
    }
}

int main(){
    cin >> n >> b;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
            current[i][j]=matrix[i][j];
        }
    }
    divide(b);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<current[i][j]%1000;
            if(j!=n-1){
                cout<<" ";
            }
        }
        if(i!=n-1){
            cout<<"\n";
        }
    }
}

//2n제곱은 n제곱*n제곱
//(2n-1)제곱은 n제곱*(n-1)제곱 아니면 (n-1)제곱*(n-1)제곱*한번 곱하기
