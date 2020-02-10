//
//  main.cpp
//  algo
//
//  Created by Jaewon Han on 23/01/2020.
//  Copyright © 2020 Jaewon Han. All rights reserved.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int coverType[4][3][2]{ //x, y
    { {0,0},{0,1},{1,1} }, //ㄴ
    { {0,0},{1,0},{1,1} }, //ㄱ
    { {0,0},{0,1},{1,0} }, //T
    { {0,0},{0,1},{-1,1} }  //J
};
//delta=1이면 덮고, -1이면 덮었던 블록을 없앤다
bool set(vector<vector<int> >& board,int x, int y, int type, int delta){
    bool ok=true;
    for(int i=0; i<3&&ok; i++){
        const int nx = x+coverType[type][i][0];
        const int ny = y+coverType[type][i][1];
        if(ny<0||ny>=board.size()||nx<0||nx>=board[0].size()){ //맵을 벗어난 경우
            ok=false;
        }
        else if((board[ny][nx]+=delta)>1){ // 덮기&블록이 겹친 경우
            ok=false;
        }
    }
    return ok;
}

int cover(vector<vector<int> >& board){
    int x=-1, y=-1;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j]==0){
                y=i;
                x=j;
                break;
                //빈칸 있다! 나가자!
            }
        }
        if(y!=-1)break; //빈칸있다 나가자! (근데 이걸 굳이 2번해야하는건가?)
    }
    if(y==-1)return 1; //빈칸 없다 다 채워졌다!
    int ret=0;
    for(int type=0; type<4; type++){
        if(set(board,x,y,type,1)){
            ret += cover(board);
        }
        //덮었던 블록 치우기
        set(board,x,y,type,-1);
    }
    return ret;
}

int main(){
    int Case, y, x;
    int whiteCount=0;
    string row;
    cin>>Case;
    while(Case--){
        cin>>y>>x;
        vector<vector<int> > board(y,vector<int> (x,0));
        for(int i=0; i<y; i++){
            cin>>row;
            for(int j=0; j<x; j++){
                int tmp;
                if(row[j]=='#'){
                    tmp=1;
                }else{
                    tmp=0;
                    whiteCount++;
                }
                board[i][j]=tmp;
            }
        }
        if(whiteCount!=0&&whiteCount%3==0){
            cout<<cover(board);
        }
        else{
            cout<<0;
        }
//        for(int i=0; i<y; i++){
//            for(int j=0; j<x; j++){
//                cout<<board[i][j]<<" ";
//            }
//            cout<<endl;
//        }
    }
}
