#include <iostream>
using namespace std;

int n,answer = 0;
bool v[15][15]={false,};
bool check(int y, int x){ //이 y,x자리에 queen을 놓을수 있는지 검사
    bool possi = true;
    //상하 검색
    for(int i=0; i<n; i++){
        //상하좌우검색
        if(v[i][x]==true||v[y][i]==true){
            possi = false;
            break;
        }
        
    }
    for(int i=1; possi&&i<n; i++){
        //오른쪽 위 대각선
        if(y-i>=0&&x+i<n&&v[y-i][x+i]==true){
            possi = false;
            break;
        }
        //오른쪽 아래 대각선
        if(y+i<n&&x+i<n&&v[y+i][x+i]==true){
            possi = false;
            break;
        }
        //왼쪽 위 대각선
        if(y-i>=0&&x-i>=0&&v[y-i][x-i]==true){
            possi = false;
            break;
        }
        //왼쪽 아래 대각선
        if(y+i<n&&x-i>=0&&v[y+i][x-i]==true){
            possi = false;
            break;
        }
    }
    return possi;
}

void dfs(int cnt){
    if(cnt==n){
        answer ++;
        return;
    }
    for(int i=0; i<n; i++){
        if(check(i,cnt)&&!v[i][cnt]){
            v[i][cnt]=true;
            dfs(cnt+1);
            v[i][cnt]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dfs(0);
    cout<<answer;
}
