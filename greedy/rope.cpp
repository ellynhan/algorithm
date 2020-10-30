#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N,max,num;
    cin>> N;
    priority_queue< int, vector<int>, greater<int> > pq;

    for(int i=0; i<N; i++){
        int tmp;
        cin>>tmp;
        pq.push(tmp);
    }
    max = N*pq.top();
    num=N-1;
    for(int i=0; i<N; i++){
        pq.pop();
        if(max<pq.top()*num){
            max=pq.top()*num;
        }
        num--;
    }
    cout<<max;
}
