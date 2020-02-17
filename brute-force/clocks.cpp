//
//  main.cpp
//  MyWorkspace
//
//  Created by 한재원 on 2020/02/17.
//  Copyright © 2020 한재원. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int switchs[10][5]={
    {0,1,2,16,16},
    {3,7,9,11,16},
    {4,10,12,15,16},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15,16},
    {3,14,15,16,16},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}
};

int PushSwitchs(int* clocks, int callCount, int* clkCount,int ret){
    cout<<"asdfasdf"<<endl;
    int sum=0;
    for(int i=0; i<16; i++)sum+=clocks[i];
    if(sum==0)return callCount; //시계가 모두 12시를 가리키고 있음
    //스위치10개 반복
    for(int i=0; i<10; i++){
        if(clkCount[i]!=4)return -1;//한 스위치당 4번 반복은 의미가 없음
        int tmp[5]={0,};
        for(int j=0; j<5&&switchs[i][j]!=16; j++){
            tmp[j] = clocks[switchs[i][j]];
            clocks[switchs[i][j]]=(tmp[j]+1)%3;
        }
        clkCount[i]++;
        int tmp_ret=PushSwitchs(clocks, callCount+1, clkCount, ret);
        if(tmp_ret==-1)return -1;
        ret= ret<tmp_ret?ret:tmp_ret;
        
        for(int j=0; j<5&&switchs[i][j]!=16; j++){ //시계 원래대로 돌려놓기
            clocks[switchs[i][j]]=tmp[j];
        }
        clkCount[i]--;
        
    }
    
    return ret;
}

int main() {
    int clocks[17]={0,};
    int clocks_counts[16]={0,};
    //int time[4]={0,3,6,9}; // 0 1 2 3
    ifstream read("input.txt");
    string a;
    if(read.is_open()){
        for(int i=0; i<16; i++){
            read>>a;
            if(a=="0"){
                clocks[i]=0;
            }else if(a=="3"){
                clocks[i]=1;
            }else if(a=="6"){
                clocks[i]=2;
            }else{
                clocks[i]=3;
            }
        }
    }else{
        cout<<"cannot open the file"<<endl;
    }
    cout<<PushSwitchs(clocks,0,clocks_counts,31);
    return 0;
}
