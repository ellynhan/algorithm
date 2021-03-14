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
// 밑에 맞은 코드와 비교해서 정답 이유 알아 낼 것.!!!!!!!!!
#include <iostream>
using namespace std;
long long cnt =0;
void merge(long long* A,int begin, int mid, int end, long long* B){
    int i,j,k;
    i=begin;
    j=mid;
    for(k=begin; k<=end; k++){
        if (i<mid&&(j>end||A[i]<=A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            cnt += k>j ? k-j : j-k;
            B[k] = A[j];
            j = j + 1;
        }
    }
    for(k=begin; k<=end; k++){ // update
        A[k]=B[k];
    }
}

void split(long long* A, int begin, int end, long long* B){
    int mid;
    
    if(end-begin<1) return; //두 조각 남음
    mid=begin+(end-begin)/2;
    split(A,begin,mid,B);
    split(A,mid+1,end,B);
    merge(A,begin,mid+1,end,B);
}



int main(){
    int N; // 수열의 길이
    cin>>N;
    long long* A = new long long[N];
    long long* B = new long long[N];
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    split(A,0,N-1,B);
    cout<<cnt;
}
