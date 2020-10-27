#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> totals;
vector<int*> times;
stack<int*> timeline;
int n;

bool compare(int* a, int* b) {
	if(a[1]<b[1]){
        return true;
    }else if(a[1]==b[1]){
        return a[0]<b[0];
    }else{
        return false;
    }
}

int main(void) {
	int maxcount = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int* tmp = new int[2];
		cin >> tmp[0] >> tmp[1];
		times.push_back(tmp);

	}
    sort(times.begin(),times.end(),compare);
    // cout<<" "<<endl<<endl;
    // for(int i=0; i<n; i++){
    //     cout<<times[i][0]<<" "<<times[i][1]<<endl;
    // }
    // cout<<endl<<endl;

    for(int i=0; i<n; i++){
        if(timeline.empty()){
            timeline.push(times[i]);
        }else{
            if(timeline.top()[1]<=times[i][0]){
                timeline.push(times[i]);
            }
        }
    }

    // cout<<timeline.size()<<endl<<endl;
    // int num = timeline.size();
    // for(int i=0; i<num; i++){
    //     cout<<timeline.top()[0]<<" "<<timeline.top()[1]<<endl;
    //     timeline.pop();
    // }
}
