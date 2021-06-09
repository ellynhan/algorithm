#include <iostream>
#include <vector>
using namespace std;
long long minValue=1000000000, maxValue=-1000000000;
int n;
int op[4]={0};
vector<int> nums;

void dfs(int cnt, int* ops, long long value){
    if(cnt == n-1){
        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
    }
    for(int i=0; i<4; i++){
        if(ops[i]==0)continue;
        ops[i]=ops[i]-1;
        if(i==0){
            dfs(cnt+1, ops, value+nums[cnt+1]);
        }else if(i==1){
            dfs(cnt+1, ops, value-nums[cnt+1]);
        }else if(i==2){
            dfs(cnt+1, ops, value*nums[cnt+1]);
        }else{
            long long tmp = value;
            if(value<0)tmp*=-1;
            tmp/=nums[cnt+1];
            if(value<0)tmp*=-1;
            dfs(cnt+1, ops, tmp);
        }
        ops[i]=ops[i]+1;
    }
}


int main(){ 
    cin >> n;
    nums.resize(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    for(int i=0; i<4; i++){
        cin >> op[i];
    }
    dfs(0,op,nums[0]);
    cout<<maxValue<<"\n"<<minValue;
}

