#include <iostream>
using namespace std;

int main(){
    int a, b;
    while(true){
        if(cin.eof())break;
        cin >> a >> b;
        cout<<a+b<<endl;
    }
}