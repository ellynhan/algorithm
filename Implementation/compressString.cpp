#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(string new_id) {
    string answer = "";
    int len=0;
    for(int i=0; i<new_id.length() && answer.length()<15; i++){
        len = answer.length();
        if(new_id[i]>='A'&&new_id[i]<='Z'){
            answer += new_id[i] +'a'-'A';
        }else if((new_id[i]>='0'&&new_id[i]<='9')||(new_id[i]>='a'&&new_id[i]<='z')||new_id[i]=='-'||new_id[i]=='_'){
            answer += new_id[i];
        }else if(new_id[i]=='.'){
            if(len!=0){
                if(answer[len-1]!='.'){
                    answer+=new_id[i];
                }
            }
        }
    }
    len = answer.length();
    while(answer[len-1]=='.'){
        answer = answer.substr(0,len-1);
        len--;
    }
    if(len == -1 || len == 0){
        answer = "aaa";
    }else if(len <=2){
        while(len<=2){
            answer += answer[len-1];
            len ++;
        }
    }
    
    return answer;
}
