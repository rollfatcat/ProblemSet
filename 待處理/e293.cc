#include<bits/stdc++.h>
using namespace std;

int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
inline void prInt(__int128 x,int L=0){
    char ss[40];
    for(;x;ss[L++]=x%10+'0',x/=10);
    while(L--) putchar(ss[L]);
    puts("");
}
int main(){
    __int128 mul_ret=1, x=1;
    for(int i=0;i<25;i++)
        mul_ret*=prime[i];

    int caseT, L;
    char ss[5002];
    scanf("%d\n",&caseT);
    while(caseT--){
        scanf("%s",ss);
        __int128 mul_now=0;
        for(int i=0;i<strlen(ss);i++)
            mul_now=((mul_now<<3)+(mul_now<<1)+ss[i]-'0')%mul_ret;
        bool getOne=false;
        for(int i=0;i<25;i++)
            if(mul_now%prime[i]==0)
                printf("%d ",prime[i]),
                getOne=true;
         
        puts( (getOne)?"":"Terrible Silence...");
    }
}
// 2305567963945518424753102147331756070