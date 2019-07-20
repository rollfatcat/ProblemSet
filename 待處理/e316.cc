/* Ｎ和Ｑ最多是1e3個，可以暴力法匹配
 * 暴力法：將輸入的數字由小到大排序後，對每個數字都嘗試是否餘數是可以被輸入的除數
 */
#include<bits/stdc++.h>
using namespace std;

// 1 ≤ Ｎ ≤ 1e3，1 ≤ Ｑ ≤ 1e3，所有的图书编码和需求码均不超过 1e7。
const int MAXN=1000;
const int MAXQ=1000;

int main(){
    int N, Q, x, ten_power;
    scanf("%d %d\n",&N,&Q);

    vector<int> number(N);
    for(int i=0;i<N;i++)
        scanf("%d",&number[i]);
    sort(number.begin(),number.end());
    int ten_base[]={1,10,100,1000,10000,100000,1000000,10000000};
    while(Q--){
        scanf("%d %d\n",&ten_power,&x);
        ten_power=ten_base[ten_power];
        bool has_ans=false;
        for(int v:number)
            if(v%ten_power==x){
                has_ans=true,
                printf("%d\n",v);
                break;
            }
        if(has_ans==0) // 若找不到任何匹配的數字則輸出-1
            puts("-1");
    }

}