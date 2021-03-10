//1108
#include <iostream>
using namespace std;

char board[2187][2187];

void star(int y, int x, int len){
    if(len==1){
        board[y][x]='*';
        return ;
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(!(i==1 && j==1)){
                star(y+i*len/3, x+j*len/3, len/3);
            }
        }
    }
}


int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            board[i][j] = ' ';
        }
    }
    star(0,0,N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<board[i][j];
        }
        cout<<endl;

    }
}
