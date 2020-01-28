#include<bits/stdc++.h>
using namespace std;

string subss, orgss;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    while(cin>>subss>>orgss){
        int i1=0, i2=0;
        for(;i1<subss.length() and i2<orgss.length();i1++,i2++)
            for(;i2<orgss.length() and subss[i1]!=orgss[i2];i2++);
        puts((i1==subss.length() and i2<=orgss.length())?"Yes":"No");
    }
}