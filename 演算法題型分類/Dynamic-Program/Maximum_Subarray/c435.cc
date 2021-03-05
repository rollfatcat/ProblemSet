#include<iostream>
using namespace std;
#define MaxN 100000

int main(){
    int n, number;
    int base, dis;
    while(cin>>n){
        cin>>base;  dis=0;
        for(int i=1;i<n;i++){
            cin>>number;
            if(base>number){
                int tmp=base-number;
                if(dis<tmp)
                    dis=tmp;
            }
            else
                base=number;
        }
        cout<<dis<<endl;
    }
}