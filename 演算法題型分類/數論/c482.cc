/* 絕對多數( Boyer–Moore majority vote algorithm )
 * 直覺：統計『查詢範圍內』出現數字的個數，確認眾數的個數是否超過一半？(屬於絕對多數且是眾數的數字必定唯一)
 * 演算法：依序抓取範圍內的每個數字並紀錄『分數』，當分數＝0時就將下一個數字設定為『贏家』。贏家＝下一個數字時分數+1，贏家 ≠ 下一個數字時分數−1，直到結束贏家就是絕對多數的數字，但前提是『存在絕對多數』，所以需要『再』掃描一次來確認個數是否超過一半
 *
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e3;  // Ｎ≤ 2000
const int MaxQ=70;   // Ｓ≤ 125e5，Ｓ所有Query的面積和
int mat[MaxN][MaxN]; // Ｄ≤ 2^31-1
int main(){
	for(int N,Q; scanf("%d\n",&N) and N;){
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				scanf("%d",&mat[i][j]);
		int U, D, L, R;
		for(scanf("%d\n",&Q); Q>0; Q--){
			scanf("%d %d %d %d\n",&U,&D,&L,&R);
			if(U>D) swap(U,D);
			if(L>R) swap(L,R);
			
			int win, cnt=0;
			for(int x=U;x<=D;x++)
				for(int y=L;y<=R;y++){
					if(cnt==0) win=mat[x][y];
					(mat[x][y]==win)? cnt++: cnt--;
				}
			cnt=0;
			for(int x=U;x<=D;x++)
				for(int y=L;y<=R;y++)
					cnt+= win==mat[x][y];
			printf("%d\n",(cnt<=((R-L+1)*(D-U+1)>>1))? -1: win); 
		}
	}
}
