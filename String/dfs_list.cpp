#include <iostream>
using namespace std;
int check[8]={0};
int n, m;
void dfs(int cnt, string ans){
    if(cnt == m){
        cout<<ans<<'\n';
        return ;
    };
    for(int i=0; i<n; i++){
        if(check[i]==0){
            check[i]=1;
            dfs(cnt+1, ans+to_string(i+1)+" ");
            check[i]=0;
        }
    }
}

int main(){
    cin >> n >> m;
    dfs(0, "");
}