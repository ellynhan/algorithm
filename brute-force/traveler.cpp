//
//  main.cpp
//  algo
//
//  Created by Jaewon Han on 13/02/2020.
//  Copyright © 2020 Jaewon Han. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#define MAX 80
#define INF INT_MAX
using namespace std;

int n; //도시의 수
double dist[MAX][MAX]; //두 도시 간의 거리를 저장하는 배열
//Path: 지금까지 만든 경로
//visit: 각 도시의 방문 여부
//currentLength: 지금까지 만든 경로의 길이
// 나머지 도시들을 모두 방문하는 경로들 중 가장 짧은 것의 길이를 반환한다.
double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength){
    //기저사례: 모든 도시를 다 방문했을 때는 시작 도시로 돌아가고 종료한다.
    if(path.size() == n )
        return currentLength + dist[path[0]][path.back()];
    double ret = INF; //매우 큰 값으로 초기화
    //다음 방문할 도시를 전부 시도해 본다
    for(int next = 0; next <n; next++){
        if(visited[next]) continue;
        int here = path.back();
        path.push_back(next);
        visited[next] = true;
        //나머지 경로를 재귀 호출을 통해 완성하고 가장 짧은 경로의 길이를 얻는 다
        double cand = shortestPath(path, visited, currentLength+dist[here][next]);
        ret = min(ret, cand);
        visited[next]=false;
        path.pop_back();
    }
    return ret;
}

int main(){
    ifstream read("input.inp");
    ofstream out("output.out");
    //set here later.
    
}

