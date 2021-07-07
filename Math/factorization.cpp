#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int answer = 0;
    for(int i=0; i<n; i++){
        int num;
        int flag = 0;
        cin >> num;
        if(num==2)answer++;
        for(int j=2; j<num&&num%j!=0; j++){
            if(j==num-1){
                flag  = 1;
            }
        }
        if(flag == 1){
            answer += 1;
        }
    }
    cout<<answer;
}