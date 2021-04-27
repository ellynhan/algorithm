#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> basket;
    int answer = 0;
    for(int i=0; i<moves.size(); i++){
        int pos = moves[i]-1;
        for(int j=0; j<board.size(); j++){
            if(board[j][pos]!=0){
                if(!basket.empty() && basket.top()==board[j][pos]){
                    basket.pop();
                    answer +=2;
                }else{
                    basket.push(board[j][pos]);
                }
                board[j][pos]=0;
                break;
            }
        }
    }
    return answer;
}
