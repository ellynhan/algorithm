#include <iostream>
#include <string>
using namespace std;
typedef long long LL;

bool isLastOne(string num){
    return num.back() == '1';
}

int main(){
    LL a, b;
    int cnt = 0;
    bool possible = true;
    cin >> a >> b;
    string bTostr = to_string(b);
    while(b!=a){
        if(b<a){
            possible = false;
            break;
        }
        if(isLastOne(bTostr)){
            bTostr = bTostr.substr(0, bTostr.size()-1);
            b = stoi(bTostr);
        }else if(b%2 == 0){
            b = b/2;
        }else{
            possible = false;
            break;
        }
        bTostr = to_string(b);
        cnt ++;
    }
    

    if(possible){
        cout<< cnt+1;
    }else{
        cout<< -1;
    }
}

