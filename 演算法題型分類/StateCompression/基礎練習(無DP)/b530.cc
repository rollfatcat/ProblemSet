/* 給定３個０１矩陣，判斷ＡxＢ＝Ｃ？
 * ０１矩陣乘積的運算方式＝ C[i,j]= A[i,0]&Ｂ[0,j]＾A[i,1]&Ｂ[1,j] ... A[i,k]&Ｂ[k,j]
 * 解題關鍵：BitMask + builtin_popcountl
 * BitMask : 每 64 bits 壓縮為 unsigned long，因為 64 為２的次方項相關運算都可以簡化為位元運算
 *           乘法模式關係，Ａ矩陣以 row 為單位 且 Ｂ矩陣以 col 為單位
 * builtin_popcountl(x) : (unsigned long)x 包含 #bit=1
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=3e3;
const int unit=64;
unsigned long row_s[MaxN][50]={};
unsigned long col_s[50][MaxN]={};

int main(){
	int N;
	unsigned long v;
	scanf("%d\n",&N);
    //  uN=(N/64)+( (N%64)>0 );
	int uN=(N>>6)+( (N&63)>0 );
	
	for(int r=0; r<N; r+=1)
		for(int c=0; c<N; c+=1){
		    // scanf("%lu",&v) ... faster io : 改為 getchar() 讀取
            v=getchar()-'0';
              getchar();
          //row_s[r][c/64]|= v<<(c%64);
			row_s[r][c>>6]|= v<<(c&63);
		}
	
	for(int r=0; r<N; r+=1)
		for(int c=0; c<N; c+=1){
            // scanf("%lu",&v) ... faster io : 改為 getchar() 讀取
			v=getchar()-'0';
              getchar();
          //col_s[r/64][c]|= v<<(r%64);
			col_s[r>>6][c]|= v<<(r&63);
		}
	
	bool safe=true;
	for(int r=0; r<N and safe; r+=1)
		for(int c=0; c<N and safe; c+=1){
			// scanf("%lu",&v) ... faster io : 改為 getchar() 讀取
            v=getchar()-'0'; 
              getchar();
			for(int u=0; u<uN; u+=1)
				v^=__builtin_popcountl(row_s[r][u]&col_s[u][c])&1;
			// 根據計算後 #bit=1 是否為偶數 ... 偶數時 XOR的結果=0, 奇數時XOR的結果=1
            safe= v^1;
		}
    // output
	puts( safe? "YES": "NO" );
}