//
//  main.cpp
//  MyWorkspace
//
//  Created by 한재원 on 2020/02/17.
//  Copyright © 2020 한재원. All rights reserved.
//
//  Edited by ellyn on 2020/02/18
//  using vector and iterator for the clocks
//  keep in my mind that String is a kinda Array and it need one more space for the newline
//  focus on the recurssive function format
//  it's gonna be 10 10 10 and then, 9 10 10 10 , 9 9 10 10 10 , 9 9 9 10 10 10, 8 9 9 9 10 10 10 .... like this. 
//  I need more practice to get accustomed to this method. 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS+1]={//문자열 마지막에는 개행문자 공간이 필요함
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.." };

bool areAligned(vector<int>& clocks){ // 모든 시계가 12시를 가리키고 있는지 확인하는 함수
    vector<int>::iterator it;
    for(it=clocks.begin(); it!=clocks.end(); it++){
        if(*it!=12)
            return false;
    }
    return true;
}

void push(vector<int>& clocks, int swtch){ //swtch번째의 스위치를 누른다, clocks는 현재 시계들의 상태
    for(int i=0; i<CLOCKS; i++){
        if(linked[swtch][i]=='x'){
            clocks[i]+=3;
            if(clocks[i]==15)clocks[i]=3;
        }
    }
}

int solve(vector<int>& clocks, int swtch){
    if(swtch == SWITCHES)return areAligned(clocks) ? 0 : INF;
    int ret=INF;
    for(int cnt=0; cnt<4; cnt++){
        ret=min(ret, cnt+solve(clocks, swtch+1));
        push(clocks, swtch); // 누르고 되돌릴 필요없이 재귀함수를 호출해주고서 누르면 되는구나
    }
    //push가 네번 호출되었으니 clocks는 원래와 같은 상태가 된다.
    return ret;
}


int main() {
    fstream read("input.txt",fstream::in); //string으로 값을 받지않고 int로 값을 받는다.
    vector<int> clocks;
    int cs;
    read>>cs; // the number of the case
    while(cs--){
        for(int i=0; i<CLOCKS; i++){
            int tmp;
            read>>tmp;
            clocks.push_back(tmp);
        }
        cout<<solve(clocks,0)<<endl;
        clocks.clear(); // make vector empty
    }
}
