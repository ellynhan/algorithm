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
/*
#include <iostream>

using namespace std;

int main(void){
    int a, b;
    while(cin >> a && cin >> b){
        cout << a + b << endl;
    }
    
    return 0;
}
*/
