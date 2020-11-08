#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
 
int main(){
    
    int N;
    cin>>N;
    
    //'A'=65
    int alphabet[26]={0};
    string s;
    for(int i=0;i<N;i++){
        cin>>s;
        for(int j=0;j<s.length();j++){
            alphabet[s[j]-65]+=(int)pow(10,s.length()-j-1);
        }
    }
    
    int ans=0;
    vector<int> vec; //존재하는 알파벳 담는 배열
    for(int i=0;i<26;i++){
        if(alphabet[i]){
            vec.push_back(alphabet[i]);
        }
    }
    
    int cnt=9;
    sort(vec.begin(),vec.end(),greater<int>()); //내림차순 정렬
    for(int i=0;i<vec.size();i++){
        ans+=vec[i]*(cnt--);
    }
    cout<<ans<<endl;
    return 0;
}
 
