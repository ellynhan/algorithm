#include <iostream>
#include <vector>
using namespace std;
int n;
int totalMaxValue = 0;

void right(vector<vector<int> >& b){
    for(int i=1; i<=n; i++){
        int check = 0;
        for(int j=n; j>=1; j--){
            if(b[i][j]==0){
                check++;
            }else{
                if(check > 0){
                    b[i][j+check]=b[i][j];
                    b[i][j] = 0;
                }
            }
        }
        for(int j=n; b[i][j]!=0; j--){
            if(b[i][j]==b[i][j-1]){
                b[i][j]*=2;
                for(int k=j-1; k>0&&b[i][k]!=0; k--){
                    b[i][k]=b[i][k-1];
                }
            }
        }
    }
}

void left(vector<vector<int> >& b){
    for(int i=1; i<=n; i++){
        int check = 0;
        for(int j=1; j<=n; j++){
            if(b[i][j]==0){
                check++;
            }else{
                if(check > 0){
                    b[i][j-check]=b[i][j];
                    b[i][j] = 0;
                }
            }
        }
        for(int j=1; b[i][j]!=0; j++){
            if(b[i][j]==b[i][j+1]){
                b[i][j]*=2;
                for(int k=j+1; k<=n&&b[i][k]!=0; k++){
                    b[i][k]=b[i][k+1];
                }
            }
        }
    }
}

void down(vector<vector<int> >& b){
    for(int i=1; i<=n; i++){
        int check = 0;
        for(int j=n; j>=1; j--){
            if(b[j][i]==0){
                check++;
            }else{
                if(check > 0){
                    b[j+check][i]=b[j][i];
                    b[j][i] = 0;
                }
            }
        }
        for(int j=n; b[j][i]!=0; j--){
            if(b[j][i]==b[j-1][i]){
                b[j][i]*=2;
                for(int k=j-1; k>0&&b[k][i]!=0; k--){
                    b[k][i]=b[k-1][i];
                }
            }
        }
    }
}

void up(vector<vector<int> >& b){
    for(int i=1; i<=n; i++){
        int check = 0;
        for(int j=1; j<=n; j++){
            if(b[j][i]==0){
                check++;
            }else{
                if(check > 0){
                    b[j-check][i]=b[j][i];
                    b[j][i] = 0;
                }
            }
        }
        for(int j=1; b[j][i]!=0; j++){
            if(b[j][i]==b[j+1][i]){
                b[j][i]*=2;
                for(int k=j+1; k<=n&&b[k][i]!=0; k++){
                    b[k][i]=b[k+1][i];
                }
            }
        }
    }
}

void dfs(vector<vector<int> >& b, int cnt){
    if(cnt == 5){
        int maxValue = 0;
        for(int i=1; i<n+2; i++){
            for(int j=1; j<n+2; j++){
                maxValue = max(maxValue, b[i][j]);
            }
        }
        totalMaxValue = max(maxValue, totalMaxValue);
    }else{
        vector<vector<int>> tmp = b;
        right(tmp);
        dfs(tmp, cnt + 1);

        tmp = b;
        left(tmp);
        dfs(tmp, cnt + 1);

        tmp = b;
        down(tmp);
        dfs(tmp, cnt + 1);

        tmp = b;
        up(tmp);
        dfs(tmp, cnt + 1);
    }
}

int main(){
    vector<vector<int>> board;
    vector<int> tmp;
    tmp.assign(22,0);
    board.assign(22,tmp);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }

    dfs(board, 0);
    cout<<totalMaxValue;
}

