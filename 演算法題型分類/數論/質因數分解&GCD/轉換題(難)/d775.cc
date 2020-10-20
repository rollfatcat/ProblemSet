/* 給定Ｎ種細胞和試管的數量(ｍ1＾ｍ2)，細胞每個每秒能分裂Ｓ個，細胞為指數成長且第０秒時為１個。
 * 解題關鍵：質因數分解，(Ｓ＾ｔ)能否被(ｍ1＾ｍ2)整除＝質因數分解後檢查所有的次方項是否都大於等於。
 * 由於試管數量的表達方式為ｍ1＾ｍ2，所以需要對 ｍ1 做質因數分解，次方項需要乘上ｍ2。
 * 某個細胞的數量在ｔ秒時數量為Ｓ＾ｔ，一樣需要做質因數分解，但判斷的目的是基於能否被整除，只需要考量 ｍ1 分解出來的質因數。
 * 若存在某個質因數(源於分解ｍ1)是Ｋ無法整除的＝Ｓ必然無法被ｍ1整除 ... Ｓ能被ｍ1整除，所有質因數對應到的次方項＞０
 * 		(Ｓ＾ｔ)能否被(ｍ1＾ｍ2)整除 ... Ｓ＾ｔ倍的次方項都大於等於ｍ1＾ｍ2分解出的次方項。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
const int MaxM1=3e4;
const int MaxM2=1e4;
const int MaxS=2e9;
const int INF=1<<30;

bool NotP[200]={};
vector<int> prime={2,3,5,7,11,13};
/* (Ｋ＾ｔ)能否被(ｍ1＾ｍ2)整除 ... 檢查Ｋ能被ｍ1整除？
 * 檢查ｍ1分解出來的質因數，若存在任一個是Ｋ無法整除＝Ｋ無法被ｍ1整除，回傳 INF
 * ｔ倍Ｓ的次方項都大於等於ｍ1＾ｍ2分解出的次方項，取所有質因數對應的ｔ當中最大者。
 */
inline int Factor(int S,vector<int> &prm,vector<int> &pwr){
	int ths_p, maxT=0;
	for(int i=0; i<prm.size(); i++){
		for(ths_p=0; S%prm[i]==0; S/=prm[i],ths_p++);
		if(ths_p==0) return INF;
		maxT=max(maxT, pwr[i]/ths_p+(pwr[i]%ths_p>0));
	}
	return maxT;
}
int main(){
	/* 題目給定 ｍ1 ≦ 3e4，只需要檢測出 sqrt(30000) 以內的所有質數。
     * 
     */
    /* {2,3,5,7,11,13} */
	for(int i= 4;i<200;i+= 2) NotP[i]=1;
	for(int i= 9;i<200;i+= 6) NotP[i]=1;
	for(int i=15;i<200;i+=10) NotP[i]=1;
	for(int i=21;i<200;i+=14) NotP[i]=1;
	for(int i=33;i<200;i+=22) NotP[i]=1;
	for(int i=39;i<200;i+=26) NotP[i]=1;
	for(int i=17;i<200;i+=2)
		if(NotP[i]==0)
			prime.push_back(i);
	
	int N, m1, m2, S, ths_p;
	while(scanf("%d\n",&N)!=EOF){
		scanf("%d %d\n",&m1,&m2);
		// Factorize m1， and caculate all the power of m1^m2  
		vector<int> m_prm;
		vector<int> m_pwr;
		for(int pv:prime){
			if(pv*pv>m1) break;
			for(ths_p=0; m1%pv==0; ths_p++,m1/=pv);
			if(ths_p>0){
				m_prm.push_back(pv);
				m_pwr.push_back(ths_p*m2);
			}
		}
		if(m1>1){
			m_prm.push_back(m1);
			m_pwr.push_back(m2);
		}
		/* 取所有細胞中，能整除當中ｔ最小的，若都無法整除 minT 維持 INF */
		int minT=INF;
		while(N-->0){
			scanf("%d",&S);
			minT=min(minT,Factor(S,m_prm,m_pwr));
		}
		printf("%d\n",(minT==INF)? -1: minT);
	}
}