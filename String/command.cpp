#include <iostream>

#include <string>
#include <vector>
#include <set>
#include <stack>
#include <map>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    int* check = new int[n];
    int curr = k;
    stack<int> recent;
    set<int> s;
    set<int>::iterator it;
    for(int i=0; i<n; i++){
        check[i]=0;
    }
    
    for(int i=0; i<cmd.size(); i++){
        string nextCmd = cmd[i];
        int num = 0;
        int buf = 0;
        if(nextCmd[0]=='D'){
            num = nextCmd[2]-'0';
            for(it=s.begin(); it!=s.end(); it++){
                if(*it>curr&*it<=curr+num){
                    buf++;
                }
            }
            curr = curr+num+buf;
        }else if(nextCmd[0]=='C'){
            check[curr]=1;
            recent.push(curr);
            s.insert(curr);
            if(curr==n-1){
                while(check[curr-num-1]!=0&&(curr-num-1)>=0){num++;}
                curr = curr-num-1;
            }else{
                while(check[curr+num+1]!=0&&(curr+num+1)<n){num++;}
                curr = curr+num+1;
            }
            if(curr==n){
                num = 1;
                while(check[curr-num]!=0&&(curr-num)>=0){num++;}
                curr = curr-num;
            }
        }else if(nextCmd[0]=='U'){
            num = nextCmd[2]-'0';
            for(it=s.begin(); it!=s.end(); it++){
                if(*it>=curr-num&&*it<curr){
                    buf++;
                }
            }
            curr = curr-num-buf;
        }else if(nextCmd[0]=='Z'){
            int last = recent.top();
            recent.pop();
            s.erase(last);
            check[last]=0;
        }
    }
    for(int i=0; i<n; i++){
        if(check[i]==0){
            answer += "O";
        }else{
            answer += "X";
        }
    }
    return answer;
}

int main(){
    string a = solution(4,1,{"C","U 1","C","D 1","C"});
    cout<<a;
}
