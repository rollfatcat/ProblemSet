/* 題目給訂Ｎ，輸出『位數相同』且大於Ｎ的『可交換質數』
 * 可交換質數：Ｎ位數的每個數字排列後形成的所有數值都屬於質數
 * 根據『可交換質數』的性質可以推得：可交換質數除了2,5以外，一定由｛ 1,3,7,9 ｝組成，則暴力法產生長度＝(1,6)的所有組合後，再暴力法產生該組合可以形成的所有數值來檢測是否都屬於質數，keep儲存某組合的所有數字而memo儲存所有可交換質數。
 * 這類題目需要考慮『數學特性』：相同思路的題目 ZJ-c658
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e7;
bool NotP[MaxN]={1,1};
bool IsAllPrime;
vector<int> keep;
vector<int> memo={2,5};
inline void Permutate(int n1,int n3,int n7,int n9,int sumn,int v){
	if(sumn==0){ 
		keep.push_back(v); 
		IsAllPrime&= NotP[v]==0; 
		return;
	} 
	if(n1>0) Permutate(n1-1,n3,n7,n9,sumn-1,10*v+1);
	if(n3>0) Permutate(n1,n3-1,n7,n9,sumn-1,10*v+3);
	if(n7>0) Permutate(n1,n3,n7-1,n9,sumn-1,10*v+7);
	if(n9>0) Permutate(n1,n3,n7,n9-1,sumn-1,10*v+9);
}
inline int LOG10(int x){ return log10(x); }
int main(){
	// 建表
	for(int i=4;i<MaxN;i+=2)  NotP[i]=1;
	for(int i=3;i<sqrt(MaxN);i+=2)
		if(NotP[i]==0)
			for(int j=(i<<1)+i;j<MaxN;j+=(i<<1))
				NotP[j]=1;
	// 利用{1,3,7,9}產生長度＝(2,6)的組合
	for(int i1=0;i1<=6;i1++)
		for(int i2=0;i2<=6-i1;i2++)
			for(int i3=0;i3<=6-i1-i2;i3++)
				for(int i4=0;i4<=6-i1-i2-i3;i4++)
					if(i1+i2+i3+i4<=6){
						IsAllPrime=true;
						keep.clear();
						Permutate(i1,i2,i3,i4,i1+i2+i3+i4,0);
						if(IsAllPrime)
							for(int x:keep)
								memo.push_back(x);
					}
	sort(memo.begin(),memo.end());
	for(int N;scanf("%d\n",&N) and N;){
		vector<int>::iterator tag=upper_bound(memo.begin(),memo.end(),N);
		printf("%d\n",(tag==memo.end() or LOG10(*tag)!=LOG10(N))? 0: *tag);
	}
}

