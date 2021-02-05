#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int testCase;
    int numberOfLogs;
    int maxDiff = 0;
    int diff;
    vector<int> logHeight;
    vector<int> orderedHeight;
    cin >> testCase;
    while(testCase--){
        cin >> numberOfLogs;
        logHeight.assign(numberOfLogs, 0);
        orderedHeight.assign(numberOfLogs, 0);
        for(int i=0; i<numberOfLogs; i++)cin>>logHeight[i];
        sort(logHeight.begin(), logHeight.end());
        for(int i=0; i<numberOfLogs; i++){
            if(i%2==0){
                orderedHeight[i/2] = logHeight[i];
            }else{
                orderedHeight[numberOfLogs-i/2-1] = logHeight[i];
            }
        }
        orderedHeight.push_back(orderedHeight[0]);
        for(int i=0; i<numberOfLogs; i++){
            diff = abs(orderedHeight[i+1] - orderedHeight[i]);
            if( diff > maxDiff ) maxDiff = diff;
        }
        cout<<maxDiff<<endl;
        maxDiff = 0;
    }
}


