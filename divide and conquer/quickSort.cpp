//
//  quickSort.cpp
//  MyWorkspace
//
//  Created by 한재원 on 2020/02/20.
//  Copyright © 2020 한재원. All rights reserved.
//  
#include <iostream>
using namespace std;
void swap(int& a, int& b){ // pivot을 int&으로 선언해야하는 이유. 그렇지않으면 값만 복사하기때문에 실제 값이 변하지 않는다.
    int t=a; a=b; b=t;
}

void partition(int* A, int low, int high){
    if(low>=high) return;
    int& pivot=A[high]; //가장 오른쪽에 있는 수를 pivot으로 설정
    int i=low-1, j=low; //i는 pivot이 들어갈 자리를 정해주는 포인터역할, j는 값 비교를 위한 포인터역할
    for(; j<high; j++){
        if(A[j]<pivot){
            swap(A[++i],A[j]);
        }
    }
    swap(A[++i],pivot);
    partition(A, low, i-1);
    partition(A,i+1,high);
        
}


int main(){
    int N;
    cin>>N; // 수열의 길이
    int* A= new int[N];
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    partition(A,0,N-1);
    for(int i=0; i<N; i++){
        cout<<A[i]<<" ";
    }
}
