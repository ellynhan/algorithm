
#include <iostream>
using namespace std;

int sero, garo;
int Map[20][20]={0,};
int x_RBLT[4] = {1,-1,0,0};
int y_RBLT[4] = {0,0,-1,1};

int dice_index[6] ={0,0,0,0,0,0};//위, 동/남/서/북, 아래

void rollDice(int direction){
    int bottom = dice_index[5];
    if(direction == 0){//오른쪽
        dice_index[5]=dice_index[1];
        dice_index[1]=dice_index[0];
        dice_index[0]=dice_index[3];
        dice_index[3]=bottom;
    }else if(direction == 1){//왼쪽
        dice_index[5]=dice_index[3];
        dice_index[3]=dice_index[0];
        dice_index[0]=dice_index[1];
        dice_index[1]=bottom;
    }else if(direction == 2){//북쪽
        dice_index[5]=dice_index[4];
        dice_index[4]=dice_index[0];
        dice_index[0]=dice_index[2];
        dice_index[2]=bottom;
    }else{//남쪽
        dice_index[5]=dice_index[2];
        dice_index[2]=dice_index[0];
        dice_index[0]=dice_index[4];
        dice_index[4]=bottom;
    }
}

int main(){
    int commands;
    cin >> sero >> garo;
    pair<int, int> dice;
    cin >> dice.first >> dice.second >> commands;
    for(int i=0; i<sero; i++){
        for(int j=0; j<garo; j++){
            cin >> Map[i][j];
        }
    }
    while(commands--){
        int move;
        cin >> move;
        move--;
        int x = dice.second + x_RBLT[move];
        int y = dice.first + y_RBLT[move];
        if(y<0 || x<0 || y>= sero || x>=garo){
            continue;
        }
        dice.first = y;
        dice.second = x;
        rollDice(move);
        if(Map[y][x]==0){
            Map[y][x]=dice_index[5];
        }else{
            dice_index[5]=Map[y][x];
            Map[y][x]=0;
        }
        cout<<dice_index[0]<<endl;
    }
}
