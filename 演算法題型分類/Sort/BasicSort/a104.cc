/* 給定Ｎ個數字的數列，輸出由小到大排序後的數列
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
int num[MaxN];
int main(){
    int N;
    while(scanf("%d\n",&N)!=EOF){
        for(int i=0;i<N;i++){
            scanf("%d",&num[i]);
            for(int j=i-1;j>=0 and num[j]>num[j+1];j--)
                swap(num[j],num[j+1]);
        }
        for(int i=0;i<N;i++)
            printf("%d ",num[i]);
        putchar('\n');
    }
}