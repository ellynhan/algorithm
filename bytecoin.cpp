#include <iostream>
#include <queue>
using namespace std;

int main(){
    int days,current,next,a;
    long money, coins=0;
    queue<int> prices;
    cin>>days>>money;
    for(int i=0; i<days; i++){
        int temp;
        cin>>temp;
        prices.push(temp);
    }
    //setting complete
    if(days!=1){
        current=prices.front();
        prices.pop();
        next=prices.front();
        a = current<next ? 1 : -1;
        if(a==1){
            coins=money/current;
            money-=coins*current;
        }
        while(!prices.empty()){
            current = prices.front();
            prices.pop();
            if(prices.empty()){
                money+=coins*current;
                break;
            }
            next = prices.front();
            if(a>0){
                if(current>next){
                    a=-1;
                    money+=current*coins;
                    coins=0;
                }
            }else{
                if(current<next){
                    a=1;
                    coins=money/current;
                    money-=coins*current;
                }
            }
        }
    }
    cout<<money;
    
}
