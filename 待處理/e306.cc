#include<bits/stdc++.h>
using namespace std;

int main(){
    int ans_cnt=0;
    int x=2;
    for(int i=0;i<=x;i++)
        for(int j=x-i;j>=0;j--)
            if((i+j)==(i^j))
                ans_cnt++;
    printf("%d\n",ans_cnt);
}
/* 1000

   0001
   0010
   0011
   0100
   0101
   0110
   0111
   1000
 */