#include <iostream>
#include <queue>
using namespace std;

int m[128][128];
int white=0, blue=0, n;//2,4,8,16,64,128
int checkSameAndColor(pair<int,int> start, int len){
    int y = start.first;
    int x = start.second;
    int color = m[y][x];
    for(int i=y; i<y+len; i++){
        for(int j=x; j<x+len; j++){
            if(m[i][j]!=color){
                return -1;
            }
        }
    }
    return color;
}


int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> m[i][j];
        }
    }
    pair<int, int> curr = {0,0};
    queue<pair<pair<int, int>, int>> next ;
    next.push({curr,n});
    while(!next.empty()){//끝까지 다 검사 완료할 때까지.
        pair<int, int> nextStart = next.front().first;
        int len = next.front().second;
        next.pop();
        int result = checkSameAndColor(nextStart, len);
        if(result == 0){
            white ++ ;
        }else if(result == 1){
            blue ++;
        }else{
            len/=2;
            next.push({{nextStart.first, nextStart.second},len});
            next.push({{nextStart.first+len, nextStart.second},len});
            next.push({{nextStart.first, nextStart.second+len},len});
            next.push({{nextStart.first+len, nextStart.second+len},len});
        }
    }   
    cout<<white<<'\n'<<blue;
}
