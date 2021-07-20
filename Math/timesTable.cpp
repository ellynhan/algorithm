#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
  int dp[82]={0,};
  for(int i=1; i<10; i++){
    dp[i]=1;
  }
    
  for(int i=2; i<10; i++){
    for(int j=i; j<10; j++){
      	dp[i*j]=1;
      }
  }
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
 		int N, flag = 0;
        cin >> N;
        if(N<=81 && dp[N]==1){
        	flag = 1;
        }
        if(flag==0){
        	cout<<"#"<<test_case<<" No\n";
        }else{
        	cout<<"#"<<test_case<<" Yes\n";
        }
	}
	return 0;
}
