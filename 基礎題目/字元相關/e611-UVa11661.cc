/* 給定一個字串只包含4種字元('R''D''Z''.')
 * 若字串中包含'Z'直接輸出０
 * 否則輸出字串中'R''D'的最短間隔距離，利用兩個指標移動
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=2e6;
char ss[MaxL+2];
int main(){
    for(int L;scanf("%d\n",&L) and L;){
        scanf("%s",ss);
        
        int idx=0, dis=1<<30;
        for(;ss[idx]=='.';idx++);
        char ch=ss[idx]; // 找到第一個字元(R/D/Z), Ｚ時即不須討論
        if(ch=='Z'){ printf("%d\n",dis); continue; }
        /* 
         */
        for(int pivot=idx++;ss[idx]!='\0';idx++){
            if(ss[idx]=='Z'){ dis=0; break; }
            if(ss[idx]=='.') continue;
            if(ss[idx]!=ch) 
                dis=min(dis,idx-pivot), ch=ss[idx];
            pivot=idx;
        }
        printf("%d\n",dis);
    }
}