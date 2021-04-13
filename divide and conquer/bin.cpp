#include <iostream>
#include <time.h>
using namespace std;

long long bin(int n, int k){
    if(k==0||n==k){
        return 1;
    }else{
        return bin(n-1,k)+bin(n-1,k-1);
    }
}

int main(int argc, char** argv){
    clock_t tStart = clock();
    cout<<bin(45,10);
    printf("\nProcess Time: %.2fs\n", (double)(clock()-tStart)/CLOCKS_PER_SEC);
    return 0;
}
