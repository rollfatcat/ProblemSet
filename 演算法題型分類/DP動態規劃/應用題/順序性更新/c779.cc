/* 給定Ｎ個盆栽的高度和容許的最大高度落差，輸出最少需要墊高多少才能確保相鄰盆栽高度落差在容許範圍內？
 * 解題關鍵：更新順序
 * 從最高的盆栽向左右更新，墊高較低的盆栽直到容許值內。
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