#include <bits/stdc++.h>
using namespace std;

const int MaxLen=101; // 1 ≤ N ≤ 2e100
char Nss[MaxLen+2];
int memo[100]={0,1,5,2,8,3,9,2,8,7};
int main() {
	//
	for(int i=10;i<100;i+=10){
		memo[i+0]=(memo[i-1]+0)%10;
		memo[i+1]=(memo[i+0]+1)%10;
		memo[i+2]=(i&3)? (memo[i+1]+6)%10 : (memo[i+1]+4)%10;
		memo[i+3]=(i&3)? (memo[i+2]+3)%10 : (memo[i+2]+7)%10;
		memo[i+4]=(memo[i+3]+6)%10;
		memo[i+5]=(memo[i+4]+5)%10;
		memo[i+6]=(memo[i+5]+6)%10;
		memo[i+7]=(i&3)? (memo[i+6]+7)%10 : (memo[i+6]+3)%10;
		memo[i+8]=(i&3)? (memo[i+7]+4)%10 : (memo[i+7]+6)%10;
		memo[i+9]=(memo[i+8]+9)%10;
	}
	//
	while(scanf("%s",Nss) and Nss[0]!='0'){
		int L=strlen(Nss);
		int x=(L>=2)? (10*(Nss[L-2]-'0')+Nss[L-1]-'0'):(Nss[0]-'0');
		printf("%d\n",memo[x]);
	}
}
/* 規律觀察找循環規律：
 * 0: {0}        ＞ {0}
 * 1：{1}				 ＞ {1}
 * 2：{2,4,8,6}	 ＞ {4,6}
 * 3: {3,9,7,1}	 ＞ {7,3}
 * 4: {4,6}			 ＞ {6}
 * 5: {5}				 ＞ {5}
 * 6：{6}				 ＞ {6}
 * 7：{7,9,3,1}	 ＞ {3,7}
 * 8: {8,4,2,6}	 ＞ {6,4}
 * 9: {9,1}			 ＞ {9}
 */