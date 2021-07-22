#include <iostream>
using namespace std;
int n, m;
void dfs(int cnt, string ans){
    if(cnt == m){
        cout<<ans<<'\n';
        return ;
    };
    for(int i=0; i<n; i++){
        dfs(cnt+1, ans+to_string(i+1)+" ");
    }
}

int main(){
    cin >> n >> m;
    dfs(0, "");
}