/* 給定Ｎ個飲料塔高度、每瓶飲料的單位高度、容許的落差高度值，保證相鄰的高度差在容許值內輸出最少要移除的飲料罐數？
 * 解題關鍵：更新順序
 * 根據題目的移除規則，高度最低的飲料塔不可能被更動，所以優先更新該飲料塔"周圍"。
 * 同樣的邏輯，最低飲料塔的狀態確保成立後再接著處理第二低的...，因此更新順序是依據高度低到高排序。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e6;
int hgt[MaxN];
int ord[MaxN];
 
inline bool compare(int a,int b){ return hgt[a]<hgt[b]; }
int main(){
	int N, unit, DIF;
	scanf("%d %d %d\n",&N,&unit,&DIF);
    DIF= DIF/unit;
    for(int i=0;i<N;i++){
        scanf("%d",&hgt[i]);
        hgt[i]/=unit;
        ord[i]=i;
    }
    /* 從最低的開始往左右更新，移除數個飲料確保相鄰的高度差在容許範圍內 */
    sort(ord,ord+N,compare);
    long ans=0;
    for(int i=0;i<N;i++){
        int pvt=ord[i];
        for(int i=pvt-1;0<=i and hgt[i]>hgt[i+1]+DIF; i--){
            ans+= hgt[i]-hgt[i+1]-DIF;
            hgt[i]=hgt[i+1]+DIF;
        }
        for(int i=pvt+1;i<N and hgt[i-1]+DIF<hgt[i]; i++){
            ans+= hgt[i]-hgt[i-1]-DIF;
            hgt[i]=hgt[i-1]+DIF;
        }
    }
    printf("%ld\n",ans);
}