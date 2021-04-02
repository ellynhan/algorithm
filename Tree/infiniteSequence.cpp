#include <iostream>
#include <map>
using namespace std;
map<long long, long long> m;
long long n,p,q;
long long checkNext(long long N){
    if(N==0)return 1;
    if(m.count(N)>0){
        return m[N];
    }else{
        long long t1 = N/p;
        long long t2 = N/q;
        long long left = checkNext(t1);
        long long right = checkNext(t2);
        m[N]=left+right;
        return m[N];
    }
}

int main(){
    cin >> n >> p >> q;
    cout<<checkNext(n);
} 
