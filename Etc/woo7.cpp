#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<string> solution(vector<string> grid, bool clockwise) {
    vector<string> answer;
    vector<deque<char>> vq;
    int h = grid.size()-1;
    for(int i=0; i<grid.size(); i++){
        deque<char> tmp;
        for(int j=0; j<grid[i].size(); j++){
            tmp.push_back(grid[i][j]);
        }
        vq.push_back(tmp);
    }
    if(clockwise==true){//120도 시계방향
        string str="";
        int cnt =0;
        while(cnt!=grid.size()){
            str="";
            for(int i=0; i<cnt; i++){
                string tmp = "";
                for(int j=0; j<2; j++){
                    tmp+=vq[h-i].front();
                    vq[h-i].pop_front();
                }
                for(int j=1; j>=0; j--){
                    str+=tmp[j];
                }
            }
            str+=vq[h-cnt].front();
            vq[h-cnt].pop_front();
            answer.push_back(str);
            cnt++;
        }
    }else{
        string str="";
        int cnt =0;
        while(cnt!=grid.size()){
            str="";
            str+=vq[h-cnt].back();
            vq[h-cnt].pop_back();

            for(int i=cnt-1; i>=0; i--){
                for(int j=0; j<2; j++){
                    str+=vq[h-i].back();
                    vq[h-i].pop_back();
                }
            }
            answer.push_back(str);
            cnt++;
        }
    }
    return answer;
}

/*
{"1","234","56789"},true -> {"5","762","98431"}
{"A","MAN","DRINK","WATER11"},false -> {"1","K1R","NNIET","AAMRDAW"}
*/