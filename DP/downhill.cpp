#include <iostream>
using namespace std;

int height[500][500];
long long route[500][500]={0}; //dp

int xx[4]={0,0,-1,1}; //상, 하, 좌, 우
int yy[4]={-1,1,0,0};

int main(){
    int m, n;
    cin >> m >> n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> height[i][j];
        }
    }
    route[0][0]=1;
    pair<int,int> curr = {0,0};
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(route[i][j]!=0){
                for(int k=0; k<4; k++){
                    int y = i+yy[k];
                    int x = j+xx[k];
                    if(x<0 || y<0 || x>=n || y>=n) continue;
                    if(height[y][x]<height[i][j]){
                        route[y][x]+=route[i][j];
                    }
                    if(i>0){
                        route[i][j]=max(route[i][j],route[i-1][j]);
                    }
                }
            }
        }
    }
    cout<<route[m-1][n-1];
}  
