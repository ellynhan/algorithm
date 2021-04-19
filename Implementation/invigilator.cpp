#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> people;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        people.push_back(tmp);
    }
    int b, c;
    cin >> b >> c;
    //총 감독관은 없어도 되는건가? -> 예제 입력 4를 보니 그렇지 않음. 꼭 포함해야함.
    long long total=0;
    for(int i=0; i<n; i++){
        int gamdok = 1;
        if(people[i]-b>0){
            people[i]-=b;
            if(people[i]%c!=0){
                gamdok+=1;
            }
            gamdok += people[i]/c;
        }
        total+=gamdok;
    }
    cout<<total;
}
