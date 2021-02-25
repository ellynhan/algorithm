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
    int minNum, maxNum, total=0, Min=maxNum;
    cin >> minNum >> maxNum;
    for(int i=minNum; i<maxNum; i++){
        if(isPrime(i)==true){
            total+=i;
            if(Min>i){
                Min = i;
            }
        }
    }
    if(total==0){
        cout<<-1;
    }else{
        cout<<total<<'\n'<<Min;
    }
}
