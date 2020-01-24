//  친구끼리 짝궁을 만들어주는 함수. 재귀호출의 중요성..
//  picnic.cpp
//  algo
//
//  Created by Jaewon Han on 23/01/2020.
//  Copyright © 2020 Jaewon Han. All rights reserved.
//
//  input 
//  3
//  2 1 
//  0 1
//  4 2
//  0 1 2 3
//  6 10
//  0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
//
//  output
//  1  
//  1
//  4

#include <iostream>
using namespace std;
bool areFriend[10][10]={0,};
int pairing(int taken[],int n){
    int ptr=-1; // 짝 안지어진 친구 선택하는 포인터
    int ret=0;
    for(int i=0; i<n; i++){
        if(taken[i]==0){
            ptr=i;
            break;
        }
    }
    if(ptr==-1){
        return 1;
    } //짝 다 지어짐
    
    for(int pairWith=ptr+1; pairWith<n; pairWith++){
        if(taken[pairWith]==0&&areFriend[ptr][pairWith]){
            taken[pairWith]=taken[ptr]=1;
            ret+=pairing(taken, n);
            taken[pairWith]=taken[ptr]=0;
        }
    }
    return ret;
}

int main() {
    int taken[10]={0,};
    int c, n, m; //c는 케이스 수, n은 학생 수, m은 친구 관계 수
    int result=0;
    cin>>c;
    while(c--){
        cin>>n>>m;
        while(m--){
            int st, nd;
            cin>>st>>nd;
            areFriend[st][nd]=areFriend[nd][st]=true;
        }
        result=pairing(taken,n);
        cout<<result<<endl;
    }
}
