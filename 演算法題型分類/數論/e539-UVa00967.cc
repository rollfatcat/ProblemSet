/* 循環質數：當每個最左邊的數字(最高有效數字)又移到右側時，仍保持質數的性質。
 * 例如，數字19937是循環質數，因為序列19937、99371、93719、37199、71993中的所有數字皆是質數。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxNum=1e6;
const int SqrtN=1e3;
bool vis[MaxNum]={};
bool NotP[MaxNum]={1,1};

vector<int> memo;
inline void DFS(int now,int depth){
	if(3<=depth and vis[now]==0){ // 若是3位數且該數字循環未拜訪過
		int base=pow(10,depth-1);
		vector<int> menu={now};
		bool flag=0;
		do{
			vis[menu.back()]=1,   	// 循環鍊包含的所有數字都標記為拜訪過
			flag|=NotP[menu.back()],// 且確認是否是質數
			menu.push_back(menu.back()%base*10+menu.back()/base);
		}while(menu.back()!=now);
		menu.pop_back(); // 多一個 now 必須將他丟棄
		if(flag==0)
			for(int x:menu)
				memo.push_back(x);
	}
	if(depth==6) return; // 只需要計算到6位數即可
	DFS(10*now+1,depth+1);
	DFS(10*now+3,depth+1);
	DFS(10*now+7,depth+1);
	DFS(10*now+9,depth+1);
}
int main(){
	// seive
	for(int i=4;i<MaxNum;i+=2)
		NotP[i]=1;
	for(int i=3;i<SqrtN;i+=2)
		if(NotP[i]==0)
			for(int j=3; i*j<MaxNum; j+=2)
				NotP[i*j]=1;
	/* 計算循環質數：位元中包含"0,2,4,5,6,8"因為循環的關係必定不會是『循環質數』
	 * 利用暴力法枚舉由"1,3,7,9"構成的3-6位數, 並確認是否為循環質數即可。
	 */
	DFS(0,0);
	sort(memo.begin(),memo.end());
	// 讀取輸入, 根據前綴和算出區間內的個數
	for(int L,R; scanf("%d %d",&L,&R)==2; ){
		int cnt=lower_bound(memo.begin(),memo.end(),R+1)-lower_bound(memo.begin(),memo.end(),L);
		if(cnt>1) printf("%d Circular Primes.\n",cnt);
		else if(cnt==1) puts("1 Circular Prime.");
		else puts("No Circular Primes."); 
	}
}