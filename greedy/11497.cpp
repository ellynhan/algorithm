//5시 5분 시작
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int testCase;
    int numberOfLog;
    vector<int> logHeights;
    vector<int> tempVector;
    cin>>testCase;
    for(int caseNum = 0; caseNum <testCase; caseNum++){
        cin >> numberOfLog;
        logHeights.resize(numberOfLog+2);
        tempVector.resize(numberOfLog);

        for(int log = 0; log<numberOfLog; log++){
            int heightTmp;
            cin >> heightTmp;
            tempVector[log] = heightTmp;
        }
        sort(tempVector.begin(), tempVector.end());
        
        for(int log = 0; log<numberOfLog; log++){
            if(log%2==0){
                logHeights[log+1] = tempVector[log];
            }else{
                logHeights[numberOfLog+1-log] = tempVector[log];
            }
        }
        
        logHeights[0] = logHeights[numberOfLog];
        logHeights[numberOfLog+1] = logHeights[1];

        cout<<"height vector ======";
        
        cout<<endl;
        for(int i=0; i<numberOfLog+2; i++){
            cout<<logHeights[i]<<" ";
        }
        cout<<endl;
        cout<<"height vector ======";
        cout<<endl;
        cout<<endl;
        cout<<endl;

        int minLevel = 0;
        int minTmp1 = 0;
        int minTmp2 = 0;
        int level = 0;
        for(int i=1; i<numberOfLog+1; i++){
            minTmp1 = abs(logHeights[i-1] - logHeights[i]);
            minTmp2 = abs(logHeights[i+1] - logHeights[i]);
            level = minTmp1 > minTmp2 ? minTmp1 : minTmp2;
            if(level<minLevel) minLevel = level;
        }
        cout<< minLevel <<endl;
    }

}
