//
//  main.cpp
//  MyWorkspace
//
//  Created by 한재원 on 2020/02/19.
//  Copyright © 2020 한재원. All rights reserved.
//  fastsum from 1 to n
#include <iostream>
using namespace std;

int fastSum(int n){
    if(n==1) return 1; // 기저사례
    if(n%2==1) return fastSum(n-1)+n;
    return 2*fastSum(n/2)+(n/2)*(n/2);
}

int main(){
    int n;
    cin>>n;
    cout<<fastSum(n);
}
