#include <iostream>
using namespace std;


int main(){
    int len;
    cin >> len;
    int* seq = new int[len];
    for(int i=0; i<len; i++){
        cin >> seq[i];
    }
    int* dp_left = new int[len];
    int* dp_right= new int[len];
    for(int i=1; i<len; i++){
        for(int j=0; j<i; j++){
            if(seq[i]>seq[j]){
                dp_left[i] = max(dp_left[i], dp_left[j]+1);
            }
        }
    }
    for(int i=len-2; i>=0; i--){
        for(int j=i; j<len; j++){
            if(seq[i]>seq[j]){
                dp_right[i]= max(dp_right[i], dp_right[j]+1);
            }
        }
    }
    int answer = 0;
    for(int i=0; i<len; i++){
        answer = max(answer, dp_left[i] + dp_right[i]);
    }
    cout<<answer + 1;
}