// 完成後接著 c661
#include<iostream>
using namespace std;

int main(){
    long long int n;
    while(cin>>n){
        int cnt;
        for(cnt=0;n>0;n/=5)
            cnt+=(n/5);
        cout<<cnt<<endl;
    }
}