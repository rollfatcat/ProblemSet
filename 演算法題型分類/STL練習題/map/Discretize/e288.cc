/* 給定Ｍ個角色(由Ａ-Ｚ和ａ-ｉ組成)和Ｎ組字串(包含出現過的角色)，任選２組字串剛好可以配對形成互補的組合數？
 * 互補＝兩個字串的角色聯集後剛好為所有角色，但交集時為空集合(不存在重複的角色)
 * 解題關鍵 : 狀態壓縮(BitMask)＋離散化(Discretize)
 * 狀態壓縮 : 輸入的字串只關注某個角色是否出現(次數不重要)，每個角色用一個位元代表(長度為38)
 * 離散化 : 需要搜集所有的"狀態"後做排序，之後累計該狀態的個數時找到對應的序位
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxM=38;
const int MaxN=5e5;
const int MaxL=1e3;
const long one=1;

char ss[MaxL+2];
long status[MaxN];
long ord[MaxN];
int  cnt[MaxN]={};

int bitpos(char c){
	return (c<='Z')? c-'A': c-'a'+26; }
int main(){
	int M, N, tag;
	// input
	scanf("%d %d",&M,&N);
	// all_s = 所有角色都出現的狀態
	long all_s=(one<<M)-1;
	for(int i=0;i<N;i+=1){
		scanf("%s",ss);
		status[i]=0;
		for(int j=0; ss[j]!='\0'; j+=1)
			status[i]|= one<<bitpos(ss[j]);
		ord[i]=status[i];
	}
	// 排序後刪除重複的數字
	sort(ord,ord+N);
	int uN=unique(ord,ord+N)-ord;

	long ans=0, bnd_s;
	for(int i=0;i<N;i+=1){
		// 確認互補狀態是否存在，若存在時則累加對應的個數
		bnd_s=all_s^status[i];
		tag=lower_bound(ord,ord+uN,bnd_s)-ord;
		if(tag<uN and ord[tag]==bnd_s)
			ans+= cnt[tag];
		cnt[ lower_bound(ord,ord+uN,status[i])-ord ]+=1;
	}
	printf("%ld\n",ans);
}