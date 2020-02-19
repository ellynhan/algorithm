//
//  MyWorkspace
//
//  Created by 한재원 on 2020/02/19.
//  Copyright © 2020 한재원. All rights reserved.
//  Merge Sort
#include <iostream>
using namespace std;

void merge(int* A,int begin, int mid, int end, int* B){
    int i,j,k;
    i=begin;
    j=mid;
    for(k=begin; k<=end; k++){
        if (i<mid&&(j>end||A[i]<=A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;
        }
    }
    for(k=begin; k<=end; k++){ // update
        A[k]=B[k];
    }
}

void split(int* A, int begin, int end, int* B){
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
    int* A = new int[N];
    int* B = new int[N];
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    split(A,0,N-1,B);
    for(int i=0; i<N; i++){
        cout<<A[i]<<" ";
    }
}
