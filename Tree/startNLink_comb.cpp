#include <iostream>
#include <vector>
using namespace std;

int s[20][20]={0};
int taken[20]={0};
int n, minValue = 20000;
vector<int> ourTeam;
void dfs(int cnt, int sel){
    if(cnt == n/2){
        vector<int> otherTeam;
        int ourValue = 0;
        int otherValue = 0;
        for(int i=0; i<n; i++){
            if(taken[i]==0){otherTeam.push_back(i);}
        }
        for(int i=0; i<n/2; i++){
            for(int j=i+1; j<n/2; j++){
                ourValue += s[ourTeam[i]][ourTeam[j]]+s[ourTeam[j]][ourTeam[i]];
                otherValue += s[otherTeam[i]][otherTeam[j]]+s[otherTeam[j]][otherTeam[i]];
            }
        }
        int diff = ourValue - otherValue;
        if(diff<0)diff*=-1;
        minValue = min(minValue, diff);
    }
    for(int i=sel; i<n; i++){
        if(taken[i]==1)continue;
        taken[i]=1;
        ourTeam.push_back(i);
        dfs(cnt+1,i+1);
        ourTeam.pop_back();
        taken[i]=0;
    }
}

int main(){ 
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> s[i][j];
        }
    }
    dfs(0,0);
    cout<< minValue ;
}

