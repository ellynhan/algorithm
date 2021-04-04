#include <iostream>
#include <vector>
using namespace std;
int edgeCheck[501][501]={0};
int nodeCheck[501]={0};
vector<int> nodes[501];

int dfs(int root){
    int result = 0;
    nodeCheck[root]=1;
    for(int i=0; i<nodes[root].size(); i++){
        int next = nodes[root][i];
        if(nodeCheck[next]==0){
            edgeCheck[root][next]=1;
            edgeCheck[next][root]=1;
            result = dfs(next);
        }else if(nodeCheck[next]==1 && edgeCheck[root][next]==0){
            return -1;
        }
    }
    return result;
}

int main(){
    int numOfNode=1, numOfEdge=1; 
    long long testCase=0;
    while(true){
        cin >> numOfNode >> numOfEdge;
        if(numOfNode==0 && numOfEdge==0)break;
        testCase++;
        for(int i=0; i<numOfEdge; i++){
            int start, end;
            cin >> start >> end;
            nodes[start].push_back(end);
            nodes[end].push_back(start);
        }

        //do dfs and check the result
        int total = 0;
        for(int i=1; i<=numOfNode; i++){
            if(nodeCheck[i]==1)continue;
            int result = dfs(i);
            if(result != -1){
                total ++;
            }
        }

        //print
        cout<<"Case "<<testCase<<": ";
        if(total == 0){
            cout<<"No trees.\n";
        }else if(total == 1){
            cout<<"There is one tree.\n";
        }else{
            cout<<"A forest of "<<total<<" trees.\n";
        }

        //clear the memory
        for(int i=1; i<=numOfNode; i++){
            for(int j=1; j<=numOfNode; j++){
                edgeCheck[i][j]=0;
            }
            nodeCheck[i]=0;
            nodes[i].clear();
        }
    }    
}
