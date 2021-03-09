#include <iostream>
#include <vector>
using namespace std;


vector<int> MultiplyVector(vector<int>& a, vector<int>& b){
    int beforeSum[300000]={0,};
    int afterSum[300000]={0,};
    vector<int> answer;
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            beforeSum[i+j]+=a[i]*b[j];
        }
    }
    for(int i=0; i<a.size()+b.size()-2; i++){
        int c = beforeSum[i]/10;
        beforeSum[i+1] += c;
        beforeSum[i] = beforeSum[i]%10;
    }
    for(int i=0; i<a.size()+b.size()-1; i++){
        answer.push_back(beforeSum[i]);
    }
    return answer;
}

void subVector(vector<int>& a, vector<int>& b){
    for(int i=0; i<b.size(); i++){
        a[i]-=b[i];
        if(a[i]<0){
            a[i+1]-=1;
            if(i+1==a.size()-1&&a[i+1]==0){
                a.pop_back();
            }
        }
    }
}

void addVector(vector<int>& a, vector<int>& b){
    for(int i=0; i<b.size(); i++){
        a[i] = a[i]+b[i];
    }
    for(int i=0; i<a.size(); i++){
        if(a[i]>9){
            if(i == a.size()-1){
                a.push_back(a[i]/10);
                a[i]=a[i]%10;
            }else{
                a[i+1]+=a[i]/10;
                a[i]=a[i]%10;
            }
        }
    }
}

int main(){
    string a,b;
    string answer="";
    cin >> a >> b;
    
    if(b.length()>a.length()){
        a.swap(b);
    }

    vector<int> va;
    vector<int> vb;
    

    for(int i=a.length()-1; i>=0; i--){
        va.push_back(a[i]-'0');
    }
    for(int i=b.length()-1; i>=0; i--){
        vb.push_back(b[i]-'0');
    }



    if(va.size()<2||vb.size()<2){
        vector<int> tmp;
        tmp = MultiplyVector(va,vb);
        for(int i=tmp.size()-1; i>=0; i--){
            answer+=to_string(tmp[i]);
        }
        cout<<answer;
    }else{
        int half = va.size()/2;
        vector<int> a0,a1,b0,b1;
        vector<int>::iterator it_a, it_b;
        it_a = va.begin();
        it_b = vb.begin();
        a0.assign(it_a, it_a+half);
        a1.assign(it_a+half, va.end());
        b0.assign(it_b, it_b+min<int>(half, va.size()));
        b1.assign(it_b+min<int>(half, vb.size()), vb.end());
        if(a0.size()==0){
            a0.assign(a1.begin(), a1.end());
            a1.clear();
            a1.push_back(0);
        }
        if(b0.size()==0){
            b0.assign(b1.begin(), b1.end());
            b1.clear();
            b1.push_back(0);
        }
        vector<int> z0 = MultiplyVector(a0,b0);
        vector<int> z2 = MultiplyVector(a1,b1);
        addVector(a0,a1);
        addVector(b0,b1);
        vector<int> z1 = MultiplyVector(a0,b0);
        subVector(z1,z0);
        subVector(z1,z2);
        
        for(int i=0; i<z2.size(); i++){
            answer += to_string(z2[i]);
        }
        for(int i=0; i<z0.size(); i++){
            answer += to_string(z0[i]);
        }
        for(int i=0; i<z1.size(); i++){
            answer += to_string(z1[i]);
        }
        
        cout<<answer;
    }

}


