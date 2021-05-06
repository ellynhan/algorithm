#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

vector<int> db[3][2][2][2];

void divide1(string str){
    int pos = str.find(" ");
    vector<string> v;
    int cv[4];
    while(pos!=string::npos){
        v.push_back(str.substr(0, pos));
        str = str.substr(pos+1,str.length()-pos);
        pos = str.find(" ");
    }
    if(v[0]=="cpp"){
        cv[0]=0;
    }else if(v[0]=="java"){
        cv[0]=1;
    }else{
        cv[0]=2;
    }

    if(v[1]=="backend"){
        cv[1]=0;
    }else{
        cv[1]=1;
    }

    if(v[2]=="junior"){
        cv[2]=0;
    }else{
        cv[2]=1;
    }

    if(v[3]=="chicken"){
        cv[3]=0;
    }else{
        cv[3]=1;
    }
    db[cv[0]][cv[1]][cv[2]][cv[3]].push_back(stoi(str));
}

vector<int> divide2(string str){
    int pos = str.find(" and ");
    vector<string> v;
    vector<int> cv;
    cv.resize(5);
    while(pos!=string::npos){
        v.push_back(str.substr(0, pos));
        str = str.substr(pos+5,str.length()-pos-4);
        pos = str.find(" and ");
    }
    while(str[pos]!=' '){
        pos++;
    }
    v.push_back(str.substr(0, pos));
    str = str.substr(pos+1,str.length()-pos);
    if(v[0]=="-"){
        cv[0]=-1;
    }else if(v[0]=="cpp"){
        cv[0]=0;
    }else if(v[0]=="java"){
        cv[0]=1;
    }else{
        cv[0]=2;
    }

    if(v[1]=="-"){
        cv[1]=-1;
    }else if(v[1]=="backend"){
        cv[1]=0;
    }else{
        cv[1]=1;
    }

    if(v[2]=="-"){
        cv[2]=-1;
    }else if(v[2]=="junior"){
        cv[2]=0;
    }else{
        cv[2]=1;
    }

    if(v[3]=="-"){
        cv[3]=-1;
    }else if(v[3]=="chicken"){
        cv[3]=0;
    }else{
        cv[3]=1;
    }
    cv[4]=stoi(str);
    return cv;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(int i=0; i<info.size(); i++){
        divide1(info[i]);
    }
    
    for(int i=0; i<query.size(); i++){
        vector<int> q = divide2(query[i]);
        int ja=0,jb=2,ka=0,kb=1,ma=0,mb=1,na=0,nb=1;
        if(q[0]!=-1)ja=jb=q[0];
        if(q[1]!=-1)ka=kb=q[1];
        if(q[2]!=-1)ma=mb=q[2];
        if(q[3]!=-1)na=nb=q[3];
        int total = 0;
        for(int j=ja; j<=jb; j++){
            for(int k=ka; k<=kb; k++){
                for(int m=ma; m<=mb; m++){
                    for(int n=na; n<=nb; n++){
                        for(int l=0; l<db[j][k][m][n].size(); l++){
                            if(db[j][k][m][n][l]>=q[4]){
                                total ++;
                            }   
                        }
                    }
                }
            }
        }
        answer.push_back(total);
    }
    return answer;
}


int main(){
    solution({"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"},{"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"});
}
