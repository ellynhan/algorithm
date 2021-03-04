#include <iostream>
#include <queue>
using namespace std;

char m[64][64];

queue<char> answer;
int f(pair<int,int> start, int len){
    int y = start.first;
    int x = start.second;
    char value = m[y][x];
    int i,j;
    for(i=0; i<len; i++){
        for(j=0; j<len; j++){
            if(value != m[y+i][x+j])return 0;
        }
    }
    return 1;
}

void f2(pair<int, int> start, int len){
    int result = f(start, len);
    int y = start.first;
    int x = start.second;
    if(result == 0){
        answer.push('(');
        f2({y,x},len/2);
        f2({y,x+len/2}, len/2);
        f2({y+len/2,x},len/2);
        f2({y+len/2,x+len/2},len/2);
        answer.push(')');
    }else{
        answer.push(m[start.first][start.second]);
    }
}



int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        for(int j=0; j<n; j++){
            m[i][j]=tmp[j];
        }
    }

    f2({0,0},n);
    while(!answer.empty()){
        cout<<answer.front();
        answer.pop();
    }
}
