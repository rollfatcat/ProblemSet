/* 動態規劃-編輯最短距離：https://www.geeksforgeeks.org/edit-distance-dp-5/
 * 狀態轉移(類似LCS，考慮最後一個字元)：
 * ƒ(L1,L2)＝min( ƒ(L1-1,L2)+2, 插入字元到L2尾端
 *                ƒ(L1,L2-1)+2, 刪除L2尾端的字元
 *                ƒ(L1-1,L2-1)+3*(s1[L1]==s2[L2]) ) 轉變L2尾端的字元
 * 這題的Ｌ≦ 1e4，做狀態轉移時只能使用滾動陣列。
 * 需要從 TopDown 型式推導為 BottomUp
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=1e4+1;
char ss[2][MaxL];
int DP[2][MaxL]={};
inline int MIN(int a,int b,int c){ 
	if(a>b) a=b; return (a>c)? c: a; }

int main(){
	while(scanf("%s\n",ss[0])!=EOF){
		int L=strlen(ss[0]);
		int ID=0, ansL=1<<30;
		for(int t=1;t<=3;t++){
			scanf("%s\n",ss[1]);
			
			int pre=0, now=1;
			for(int i=0;i<=L;i++)
				DP[0][i]=i<<1;
			for(int i=0;ss[1][i]!='\0';i++){
				DP[now][0]=i+1<<1;
				for(int j=1;j<=L;j++)
					DP[now][j]=MIN(DP[pre][ j ]+2,
					    		   DP[now][j-1]+2,
					    		   DP[pre][j-1]+3*(ss[0][j-1]!=ss[1][i]));
				swap(pre,now);
			}
			if(DP[pre][L]<=ansL) 
				ID=t, ansL=DP[pre][L];
		}
		printf("%d %d\n",ID,ansL);
	}
}