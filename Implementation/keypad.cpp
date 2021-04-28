
#include <string>
#include <vector>
#include <map>
using namespace std;

int xx[4] = {0,0,-1,1};
int yy[4] = {-1,1,0,0};
int getDistance(pair<int, int> target, pair<int, int> from){
    int X = target.first - from.first;
    int Y = target.second - from.second;
    if(X<0)X*=-1;
    if(Y<0)Y*=-1;
    return X+Y;
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> leftPos={3,0};
    pair<int, int> rightPos={3,2};
    map<int, pair<int, int>> m;
    int num = 1;
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            m[num] = {i,j};
            num++;
        }
    }
    m[0]=m[11];
    for(int i=0; i<numbers.size(); i++){
        int btn = numbers[i];
        if(btn==1||btn==4||btn==7){
            answer+='L';
            leftPos = m[btn];
        }else if(btn==3||btn==6||btn==9){
            answer+='R';
            rightPos = m[btn];
        }else{
            pair<int, int> target = m[btn];
            int right = getDistance(target, rightPos);
            int left = getDistance(target, leftPos);
            if(right<left || (right == left && hand == "right")){
                answer+='R';
                rightPos = m[btn];
            }else{
                answer+='L';
                leftPos = m[btn];
          }
        }
    }
    return answer;
}
