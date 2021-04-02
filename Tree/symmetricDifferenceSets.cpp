#include <iostream>
#include <map>
using namespace std;


int main(){
    int  numOfA, numOfB;
    cin >> numOfA >> numOfB;
    map<int,int> m;
    for(int i=0; i<numOfA+numOfB; i++){
        int tmp;
        cin >> tmp;
        if(m.count(tmp-1)>0){
            m.erase(tmp-1);
        }else{
            m[tmp-1]=1;
        }
    }
    cout<<m.size();
}  
