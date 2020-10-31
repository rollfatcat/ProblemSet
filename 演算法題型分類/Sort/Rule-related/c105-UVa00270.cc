#include<bits/stdc++.h>
using namespace std;

const int MaxN=7e2;
int node[MaxN][2];
long dxy[MaxN][2];
int ord[MaxN];
/* 斜率約分時先排除水平線和垂直線問題，GCD的正負值和分母同號 */
void reduction(int num){
	if(dxy[num][0]==0){ dxy[num][1]=1; return; }
	if(dxy[num][1]==0){ dxy[num][0]=1; return; }
	int GCD=__gcd(dxy[num][0],dxy[num][1]);
	dxy[num][0]/=GCD;
	dxy[num][1]/=GCD;
}
bool compare(int a,int b){ return dxy[a][0]*dxy[b][1] > dxy[a][1]*dxy[b][0]; }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int caseQ, idx, N;
	bool sign=0;
	string ss;
	
	cin>>caseQ>>ws;
	while(caseQ-->0){
		/* 讀取整行轉換為Ｎ個點的二維座標，字串轉換成數字時要考慮到座標值包含負數 */
		for(N=0;getline(cin,ss) and ss.length()>0;N++){
			node[N][0]=node[N][1]=0;
			sign=ss[0]=='-';
			for(idx=sign;ss[idx]!=' ';idx++)
				node[N][0]=10*node[N][0]+ss[idx]-'0';
			if(sign) node[N][0]=-node[N][0];
			sign=ss[++idx]=='-';
			for(idx+=sign;ss[idx]!='\0';idx++)
				node[N][1]=10*node[N][1]+ss[idx]-'0';
			if(sign) node[N][1]=-node[N][1];
		}
		/* 枚舉每個點作為基礎，計算其他點和目前基礎點形成的斜率
		 * 斜率相同的線段＝該兩點和基礎點屬於共線，故相同斜率的數量+1(需包含基礎點)＝共線點數  
		 */
		int ans=0;
		for(int i=0;i<N;i++){
			int Dcnt=0;
			for(int j=0;j<i;j++){
				dxy[j][0]=node[j][0]-node[i][0];
				dxy[j][1]=node[j][1]-node[i][1];
				reduction(j);
				ord[Dcnt++]=j;
			}
			for(int j=i+1;j<N;j++){
				dxy[j][0]=node[j][0]-node[i][0];
				dxy[j][1]=node[j][1]-node[i][1];
				reduction(j);
				ord[Dcnt++]=j;
			}
			/* (1) map<pair<dx,dy>,cnt> 
			 * (2) 排序解：依斜率排序 或是 先依照Ｘ座標再依照Ｙ座標(同 map<> 的實作方式)
			 * 為了讓"相同斜率"的線段放在相鄰的位置
			 * 需要依照"斜率"由小到大排序，掃描一遍，過程中統計相同斜率的線段個數並更新答案的最大值個數。
			 */
			sort(ord,ord+Dcnt,compare);
			int cxy=1;
			for(int j=1;j<Dcnt;j++)
				if(dxy[ord[j-1]][0]*dxy[ord[j]][1] == dxy[ord[j]][0]*dxy[ord[j-1]][1])
				  cxy++;
				else{
					ans=max(ans,cxy); 
					cxy=1;
				}
			ans=max(ans,cxy);
		}
		
		cout<<ans+1<<'\n';
		if(caseQ) cout<<'\n';
	}
}