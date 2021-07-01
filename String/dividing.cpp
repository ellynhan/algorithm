#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		string str;
        cin >> str;
        string pre = "";
        string curr = "";
        int answer = 0;
        for(int i=0; i<str.length(); i++){
        	curr += str[i];
            if(curr != pre){
                answer ++;
                pre = curr;
                curr = "";
            }
        }
		cout<<"#"<<test_case<<" "<<answer<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}