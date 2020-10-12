/* 給定Ｎ個字串，輸出能形成最長的接龍長度？
 * 接龍規則：每個字串最多可以使用２次(允許自己接自己)，但頭尾相接時不得是包含關係(at和attitude)。
 * 解題關鍵：字串比對＋DFS(暴力法)
 * 接龍時盡量讓重疊的長度越短越好
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=20;
string ss[MaxN];
vector<int> edge[MaxN];
vector<int> remL[MaxN];
int cnt[MaxN];
int N, maxL;
 
bool match_subss(int u,int v,int l){
	int L=ss[u].length();
	for(int i=0;i<l;i++)
		if(ss[u][L-l+i]!=ss[v][i])
			return false;
	return true;
}
void DFS(int pos,int nowL){
	bool no_path=true;
	for(int i=0;i<edge[pos].size();i++)
		if(cnt[edge[pos][i]]){
			no_path=false;
			cnt[ edge[pos][i] ]--;
			DFS(edge[pos][i],nowL+remL[pos][i]);
			cnt[ edge[pos][i] ]++;
		}
	if(no_path)
		maxL=max(maxL,nowL);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	char st_ch;
	while(cin>>N){
		for(int i=0;i<N;i++){
			cin>>ss[i];
			edge[i].clear();
			remL[i].clear();
			cnt[i]=2;
		}
		cin>>st_ch;
		/* 建立單向邊 */
		for(int u=0;u<N;u++)
			for(int v=0;v<N;v++){
				int bound=min(ss[u].length(),ss[v].length());
				for(int l=1;l<bound;l++)
					if(match_subss(u,v,l)){
						edge[u].push_back(v);
						remL[u].push_back(ss[v].length()-l);
						break;
					}
			}
        /* 暴力法嘗試每一種路徑選擇 */
        maxL=0;
        for(int u=0;u<N;u++)
            if(ss[u][0]==st_ch){
                cnt[u]--;
                DFS(u,ss[u].length());
                cnt[u]++;
            }
        printf("%d\n",maxL);
	}
}
