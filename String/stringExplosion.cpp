#include <iostream>
#include <deque>
#include <stack>
using namespace std;


int main(){
    string str, ex;
    cin >> str >> ex;
    if(str.length()<ex.length()){
        cout<<str;
        return 0;
    }
    deque<char> q;
    stack<int> tmp;
    int cnt =0;
    for(int i=0; i<str.length(); i++){
        q.push_back(str[i]);
        if(str[i]==ex[ex.length()-1]&&q.size()>=ex.length()){
            int j=ex.length()-1;
            for(; j>=0&&!q.empty(); j--){
                if(ex[j]==q.back()){
                    tmp.push(q.back());
                    q.pop_back();
                }else{
                    while(!tmp.empty()){
                        q.push_back(tmp.top());
                        tmp.pop();
                    }
                    break;
                }
            }
            while(!tmp.empty()){tmp.pop();}
        }
    }
    if(q.empty()){
        cout<<"FRULA";
    }else{
        while(!q.empty()){
            cout<<q.front();
            q.pop_front();
        }
    }
}
