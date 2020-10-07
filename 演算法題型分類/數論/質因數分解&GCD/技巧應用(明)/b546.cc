/* 給定數列的第一項Ａ，根據數列的建立規則輸出第Ｎ項的值？
 * 數列建立規則：第Ｋ項的數值＝若當前數值能被Ｋ-1整除則做相除，否則相乘。
 * 解題關鍵：質因數分解＋大數乘法
 * 題目保證Ｎ ≤ 100，只需紀錄 100 以內的質數(質因數分解會用到)
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=50;
const int BigNumber=1e7;
const int MaxA=1e2;
const int MaxN=1e2;
const int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
/* 質數Ｖ屬於第幾個質數 */
int P2P[MaxN+1]={};
vector<int> base[MaxN+1];
vector<int> powr[MaxN+1];
/* ２５個質數對應的次方項描述當前的數值。
 * 能被Ｖ整除 : 對應的次方項都大於等於Ｖ做質因數分解後所有的次方項
 * 能整除＝扣除，反之加上 
 */
int cnt[25]={};
 
int main(){
	/* PrimeToPos */
    for(int i=0;i<25;i++)
		P2P[prime[i]]=i;
	/* Prepare:２-１００做質因數分解，每ｉ組的紀錄方式為(base,power)，base代表的是第幾個質數 */
    for(int number=2; number<=MaxN; number++){
		int v=number, p;
		for(int i=0; prime[i]*prime[i]<=v; i++){
			for(p=0; v%prime[i]==0; v/=prime[i],p++);
			if(p>0) 
				base[number].push_back(i), 
				powr[number].push_back(p);
		}
		if(v>1)
			base[number].push_back(P2P[v]), 
			powr[number].push_back(1);
	}
	int A, N; 
	while(scanf("%d %d\n",&A,&N)!=EOF){
		for(int i=0;i<base[A].size();i++)
			cnt[base[A][i]]=powr[A][i];
		for(int now=2; now<N; now++){
			/* 判斷能否整除 */
            bool canDivide=1;
			for(int i=0;i<base[now].size() and canDivide;i++)
				canDivide= cnt[ base[now][i] ]>=powr[now][i];
            /* 根據能否整除決定是加上或是扣除對應的次方項 */
			if(canDivide)
				for(int i=0;i<base[now].size();i++)
					cnt[ base[now][i] ]-=powr[now][i];
			else
				for(int i=0;i<base[now].size();i++)
					cnt[ base[now][i] ]+=powr[now][i];
		}
        /* 大數乘法：輸出所有質因數的乘積
         * 加速：以 1e7 為基底，因為每次乘數不超過 1e2 
         */
		vector<int> BigNum={1}; 
		for(int i=0;i<25;i++)
			while(cnt[i]>0){
				int carry=0;
				for(int j=0;j<BigNum.size();j++)
					BigNum[j]=BigNum[j]*prime[i]+carry,
					carry=BigNum[j]/BigNumber,
					BigNum[j]%=BigNumber;
				if(carry>0)
					BigNum.push_back(carry);
				cnt[i]--;
			}
        /* 大數輸出 */
		printf("%d",BigNum.back());
		for(int i=BigNum.size()-2;i>=0;i--)
			printf("%07d",BigNum[i]);
		putchar('\n');
	}
}