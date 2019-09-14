#include <iostream>
#include <vector>
using namespace std;

void func(int N,int M, vector<int>& m,int pos,vector<int>& p){
    int i,j,k,block,n=N/3;
    bool judge=true;
    for(i=0; i<9; i++){ //divide in 9
        for(j=0; j<n&&judge; j++){
            block=pos+M*j;
            for(k=0; k<n; k++){
                if(m[pos]!=m[block+k]){
                    judge=false;
                    break;
                }
            }
        }
        if(j==n&&k==n){
            p.push_back(m[pos]);
        }
        else{
            judge=true;
            func(N/3,M,m,pos,p);
        }
        if(i%3==2){
            pos+=M*n-2*n;
        }else{
            pos+=n;
        }
     }
}

int main()
{
    int N,i;
    cin>>N;
    bool same=true;
    vector<int> metrix(N*N,0);
    vector<int> paper;
    int result[3]={0,0,0};

    for(i=0; i<N*N; i++){
        cin>>metrix[i];
        if(metrix[0]!=metrix[i])
            same=false;
    }
    if(same==false){
       func(N,N,metrix,0,paper);
    }
    else
        paper.push_back(metrix[0]);

    for(i=0; i<paper.size(); i++){
        if(paper[i]==-1){
            result[0]++;
        }else if(paper[i]==0){
            result[1]++;
        }else if(paper[i]==1){
            result[2]++;
        }
    }
    for(i=0; i<3; i++){
        cout<<result[i]<<endl;
    }

}
