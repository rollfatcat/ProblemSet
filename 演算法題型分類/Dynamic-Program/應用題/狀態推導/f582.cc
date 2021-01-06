/* 給定Ｎ個基因(字串由'A'/'C'/'G'/'U'/'@'組成)，只採計兩組"演化關係"的基因之間的漢明距離最小化總和？
 * '@'可以是'A'/'C'/'G'/'U'當中擇一但只能是其一。
 * 解題關鍵：樹形動態規劃( Dynamic-Programming TopDown version )
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
const int MaxM=80;
const int INF=INT_MAX;

char ss[MaxN+1][MaxM+2];
vector<int> chd[MaxN+1];
int dp[MaxN+1][MaxM][4];

/* Top-Down版本， Buttom-Up版本＝Topology Sort 實作
 * 遞迴到最底層的葉節點後才開始做狀態轉移，狀態轉移只需要考慮 parent 和 children 的關聯
 * 不同位置的字元可以分開處理 ... 迴圈枚舉所有的字元。
 * 狀態定義： dp[第ａ個基因字串][第ｉ個位置][字元為'A'/'C'/'G'/'U']＝從葉節點累計的漢明距離
 * 狀態轉移：若字元為'@'時需要枚舉４種可能的狀態，考量 parent 和 children 的字元對應關係分開討論
 *         parent is  '@' and  children is  '@'，枚舉４x４
 *         parent is  '@' and  children not '@'，枚舉４x１
 *         parent not '@' and  children is  '@'，枚舉１x４
 *         parent not '@' and  children not '@'，枚舉１x１
 * 狀態轉移時從子字串同個位置的"可能選項"當中選擇距離最小的字元
 */
void TreeDP(int now,int& M){
	for(int nxt:chd[now]){
        // Divide First to check its' children's states all are ready.
		TreeDP(nxt,M);
		for(int i=0;i<M;i++){
			int rhs, ths=ss[now][i];
			if(ths<=3){ // parent not '@'
				rhs=ss[nxt][i];
				if(rhs<=3){ // children not '@'
					dp[now][i][ths]+= dp[nxt][i][rhs]+(ths!=rhs);
				}else{      // children is  '@'
					int tmp=dp[nxt][i][0]+(ths!=0);
					for(int j=1;j<=3;j++)
						tmp=min(tmp,dp[nxt][i][j]+(ths!=j));
					dp[now][i][ths]+= tmp;
				}
			}else{      // parent is '@'
				rhs=ss[nxt][i];
				if(rhs<=3){ // children not '@'
					for(int j=0;j<=3;j++)
						dp[now][i][j]+= dp[nxt][i][rhs]+(j!=rhs);
				}else{      // children is '@'
					for(int j=0;j<=3;j++){
						int tmp=dp[nxt][i][0]+(j!=0);
						for(int k=1;k<=3;k++)
							tmp=min(tmp,dp[nxt][i][k]+(j!=k));
						dp[now][i][j]+= tmp;
					}
				}
			}
		}
	}
}

int main(){
	char dict[128]={};
	dict['A']=0; dict['C']=1; 
	dict['G']=2; dict['U']=3; dict['@']=4;
	
	int N, M;
	scanf("%d %d\n",&N,&M);
	int a, b, org=-1;
	while(N-->0){
		scanf("%d %d ",&a,&b);
		scanf("%s\n",ss[a]);
        // 將字元" A U C G "轉換為對應的號碼，並設定這個節點的狀態只有對應的字元為０，其餘都是 INF
		for(int i=0;i<M;i++){
			ss[a][i]=dict[ ss[a][i] ];
			for(int j=0;j<=3;j++)
				dp[a][i][j]=(ss[a][i]==4 or j==ss[a][i])? 0: INF;
		}
        // 尋找 root 並建立整棵樹的架構： parent 儲存可以抵達的 children 
		if(a==b) 
			org=a;
		else 
			chd[b].push_back(a);
	}
	TreeDP(org,M);
	int ans=0;
	for(int i=0;i<M;i++){
		if(ss[org][i]<=3)
			ans+= dp[org][i][ss[org][i]];
		else{ // ss[org][i]=4
			ans+= min(min(dp[org][i][0],dp[org][i][1]),
			          min(dp[org][i][2],dp[org][i][3]));
		}
	}
	printf("%d\n",ans);
}