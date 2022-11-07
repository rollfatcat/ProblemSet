/* 給定Ｎ個盆栽的高度和容許的最大高度落差，輸出最少需要墊高多少才能確保相鄰盆栽高度落差在容許範圍內？
 * 解題關鍵：更新順序
 * 根據題目的移除規則，高度最高的盆栽塔不可能被更動，所以優先更新該盆栽"周圍"。
 * 同樣的邏輯，最高盆栽的狀態確保成立後再接著處理第二高的...，因此更新順序是依據高度高到低排序。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=30;
int hgt[MaxN];
int ord[MaxN];
 
inline bool compare(int a,int b){ return hgt[a]>hgt[b]; }
int main(){
    int N=0, DIF;
    /* 讀取輸入：Ｎ個數字＋相鄰最大高度落差 */
    do{
        scanf("%d",&hgt[N]);
        ord[N]=N++;
    }while(getchar()==' ');
    scanf("%d\n",&DIF);
    /* 從最高的點開始向左和向右更新，提高左右點的高度確保 ≦ 最大高度落差 */
    sort(ord,ord+N,compare);
    int sum=0;
    for(int i=0;i<N;i++){
        int pvt=ord[i];
        for(int L=pvt-1; L>=0 and hgt[L]<hgt[L+1]-DIF; L--){
            sum+=hgt[L+1]-DIF-hgt[L];
            hgt[L]=hgt[L+1]-DIF;
        }
        for(int R=pvt+1; R<N  and hgt[R]<hgt[R-1]-DIF; R++){
            sum+=hgt[R-1]-DIF-hgt[R];
            hgt[R]=hgt[R-1]-DIF;
        }
    }
    printf("%d\n",sum);
}