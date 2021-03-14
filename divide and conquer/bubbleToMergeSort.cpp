#include <iostream>
using namespace std;

long long arr[500001];
long long sorted[500001];
int N;
int cnt=0;

void splitAndMerge(int ibegin, int iend){
    if(iend-ibegin<1)return ;
    int mid = (iend+ibegin)/2;
    //divide
    splitAndMerge(ibegin, mid);
    splitAndMerge(mid+1, iend);
    //conquer

    int i=ibegin, j=mid+1, k=ibegin;
    for(; k<=iend; k++){
        if(i==mid+1&&j!=iend+1){
            sorted[k]=arr[j];
            j++;
        }else if(j==iend+1&&i!=mid+1){
            sorted[k]=arr[i];
            i++;
        }else if(arr[i]>arr[j]){
            sorted[k]=arr[j];
            cnt += iend-ibegin;
            j++;
        }else{
            sorted[k]=arr[i];
            i++;
        }
    }
    for(i=ibegin; i<=iend; i++){
        arr[i]=sorted[i];
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    splitAndMerge(0,N-1);
    
    cout<<cnt;
    
}
