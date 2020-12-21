/* 給定Ｍ個字串和長度都是Ｎ，輸出漢明距離總和最小的字串(字典序最小)以及 漢明距離總和？ 
 * 解題關鍵：字元統計
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxM=5e1;
const int MaxN=1e3;
char ss[MaxM][MaxN+2];
int cnt[4];
 
int CharToInt(char c){ return (c<='C')? (c=='C'): (c=='G')? 2: 3;  }
char IntToChar(int i){ return (i<=1)? (i==0)? 'A':'C' : (i==2)? 'G':'T';}
 
int main(){
	int caseT, N, M;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d\n",&M,&N);
		for(int i=0;i<M;i++)
			scanf("%s\n",ss[i]);
 
		int hamming =0;
		for(int i=0;i<N;i++){
			cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
			for(int j=0;j<M;j++)
				cnt[ CharToInt(ss[j][i]) ]++;
			int pvt=0;
			if(cnt[1]>cnt[pvt]) pvt=1;
			if(cnt[2]>cnt[pvt]) pvt=2;
			if(cnt[3]>cnt[pvt]) pvt=3;
			hamming+= M-cnt[pvt];
			putchar(IntToChar(pvt));
		}
		printf("\n%d\n",hamming);
	}
}