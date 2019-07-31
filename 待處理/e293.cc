#include<bits/stdc++.h>
using namespace std;

unsigned int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
unsigned long mul_ret[5]={1,1,1,1,1};
int main(){
    //
    
    
    //
    int caseT, L;
    char ss[5002];
    scanf("%d\n",&caseT);
    while(caseT--){
        scanf("%s",ss);
        
        bool getOne=false;
        for(int i=0;i<25;i++)
            if(mul_now%prime[i]==0)
                printf("%d ",prime[i]),
                getOne=true;
         
        puts( (getOne)?"":"Terrible Silence...");
    }
}
