#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

int position(int n,int r, int c){
    int k=0;
    int pos = pow(2,n);
    if(r<pos&&c<pos){//1
        k=1;
    }
    else if(r<pos&&c>=pos){//3
        k=3;
    }
    else if(c<pos){//2
        k=2;
    }
    else{//4
        k=4;
    }
    return k;
}

int main()
{
    int N,r,c;
    cin>>N>>c>>r;
    queue<int> order;
    int num=1;
    int tmp=0,R=r,C=c;
    while(N-num>=0){
        switch(tmp){
        case 2:
            R-=(int)pow(2,N-num+1);
            break;
        case 3:
            C-=(int)pow(2,N-num+1);
            break;
        case 4:
            R-=(int)pow(2,N-num+1);
            C-=(int)pow(2,N-num+1);
            break;
        }
        tmp=position(N-num,R,C);
        order.push(tmp);
        num++;
    }
    tmp=pow(2,N)*pow(2,N);
    int low=0,up=tmp,low_=0;
    int m;
    while(!order.empty()){
        m=(up-low)/4;
        low=m*(order.front()-1);
        up=m*(order.front());
        order.pop();
        low_+=low;
    }
    cout<<low_;
}
