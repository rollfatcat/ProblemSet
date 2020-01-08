/* 依照題意模擬過程：
 * 每個人都會有一張順位清單，當目前的候選人被淘汰時就往下選
 * 每一輪會淘汰掉得票數最少的候選人(可能不只一位)
 * 重複上述流程直到下述兩種情況停止：
 * (1) 存在一位候選人的得票率超過50%(只會有一位)
 * (2) 目前尚未淘汰的候選人得票數都相同(且皆未超過50%)
 * 將這一輪淘汰的候選人標記狀態為已經淘汰，且將投給他們的人依照順位清單選擇下一個尚未淘汰的候選人，注意需要先將這輪淘汰的候選者標記完後才處理『轉投』的人。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=20+1;
const int MaxL=80+2;
const int MaxM=1000;
const int INF=1<<30;

string names[MaxN];
queue<int> nums[MaxM];
queue<int> team[MaxN];

int main(){
	ios::sync_with_stdio(0),
	cin.tie(0), cout.tie(0);
	
	int caseT, N, M, v;
	for(cin>>caseT; caseT; caseT--){
	  // 輸入讀取，邊初始化邊紀錄測資
		cin>>N;
		for(int i=0;i<=N;i++)
			for(getline(cin,names[i]);!team[i].empty();team[i].pop());
		for(M=0;getline(cin,names[0]) and names[0]!="";M++){
			for(v=0;nums[M].empty()==0;nums[M].pop());
			for(char ch:names[0])
				if(ch==' ') nums[M].push(v), v=0;
				else v=10*v+ch-'0';
			nums[M].push(v);
		}
		// 依照規則模擬
		vector<bool> on(N+1,true);
		for(int i=0;i<M;i++)
			team[ nums[i].front() ].push(i);
		bool HasWinner=false, AllSame=true;
		int winner=0;
		while(true){
			// 從『還未被淘汰』的候選名單中選取『票數最低』的人，偵測是否存在一位候選人的得票率『超過』50%
			int minv=INF;
			for(int i=1;i<=N;i++)
				if(on[i]){
					minv=(minv>team[i].size())? team[i].size(): minv;
					if((team[i].size()<<1)>M)
						HasWinner=true, winner=i;
				}
			// 存在一位候選人的得票率超過50%
			if(HasWinner){ cout<<names[winner]<<'\n'<<'\n'; break; }
			// 確認『還未淘汰』的候選人得票數都相同時則輸出現在的名單
			AllSame=true;
			for(int i=1;i<=N;i++)
				if(on[i])
					AllSame&= team[i].size()==minv;
			if(AllSame){
				for(int i=1;i<=N;i++)
					if(on[i])
						cout<<names[i]<<'\n';
				cout<<'\n';
				break;
			}
			// 每一輪淘汰的候選人可能不只一位，所以需要先把這輪『淘汰』的狀態標記完後才可以根據投給『淘汰者』的號碼中根據他們的順位名單投給下一個『還未被淘汰者』。
			for(int i=1;i<=N;i++)
				if(team[i].size()==minv)
					on[i]=false;
			for(int i=1;i<=N;i++)
				if(team[i].size()==minv)
				for(;team[i].empty()==0;team[i].pop()){
						for(v=team[i].front(),nums[v].pop();on[nums[v].front()]==0;nums[v].pop());
						team[ nums[v].front() ].push(v);
					}
		
		}
	}
}