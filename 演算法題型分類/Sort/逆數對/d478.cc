/* 給定２個嚴格遞增的數列，輸出共同有的數字個數？
 * 解題關鍵：Merge
 * 數列本身是嚴格遞增＝數字不重複且經過排序(小到大)
 * 每次取數列當中最前端的數字比較即可。
 *      相同，答案數+1 且  兩個指標一起+1
 *      不同，指向數字較小的指標+1，因為不可能存在能夠匹配到的數字
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
int num[MaxN][2];

int main(){
    int n, m;
    scanf("%d %d\n",&n,&m);
    while(n-->0){
        for(int i=0;i<m;i++)
            scanf("%d",&num[i][0]);
        for(int i=0;i<m;i++)
            scanf("%d",&num[i][1]);
        int p0=0, p1=0, ans=0;
        while(p0<m and p1<m){
            if(num[p0][0]<num[p1][1]) 
                p0++;
            else if(num[p0][0]>num[p1][1]) 
                p1++;
            else //(num[p0][0]==num[p1][1]) 
                ans++, p0++, p1++; 
            
        }
        printf("%d\n",ans);
    }
}