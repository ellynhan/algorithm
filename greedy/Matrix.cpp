#include <iostream>
using namespace std;
 

class Matrix{
    private:
        int n,m;
    public:
    int mat[50][50];
    //  Matrix(){};
    Matrix(int N, int M){
         n=N;
         m=M;
    };
    void matchMat()
    {   
        for(int i=0; i<n; i++){
            string onerow;
            cin>> onerow;
            for(int j=0; j<m; j++){
                mat[i][j]=onerow[j]-48;//'0'
            }
        }
    }
    bool operator==(Matrix& ref){
        bool isSame=true;
        for(int i=0; i<n; i++){
             for(int j=0; j<m; j++){
                 if(mat[i][j]!=ref.mat[i][j]){
                     isSame=false;
                 }
             }
         }
         return isSame;
     }

    void change3x3(int column, int row){//i,j
        for(int i=column; i<column+3; i++)
        {
            for(int j=row; j<row+3; j++)
            {
                mat[i][j]=(mat[i][j]+1)%2;
            }
        }
    }
};


int main(){
    
    //N x M 행렬
    int N, M,Count=0;
    cin>>N>>M;
    Matrix A(N,M);
    Matrix B(N,M);
    A.matchMat();
    B.matchMat();
    
    for(int i=0; i<N-2; i++){
        for(int j=0; j<M-2; j++){
            if(A.mat[i][j]!=B.mat[i][j]){
                A.change3x3(i,j);
                Count++;
            }
        }
    }
    if(A==B){
        cout<<Count;
    }else{
        cout<<-1;
    }

}
 
