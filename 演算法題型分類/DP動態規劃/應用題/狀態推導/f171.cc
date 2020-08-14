/* 給定Ｎ個查詢，長度Ｐ時結尾是Ｑ的"快樂數字"數量？
 * 快樂數字的定義：(1)必須包含１-９每個字元且不包含０ (2)相鄰位數的差不超過２
 * 解題關鍵：離線處理＋狀態壓縮的動態規劃(現在的結尾字元只與前一個結尾字元相關)
 *      離線處理：從長度最小的到最大的做一次就好，過程中將先算出來的答案存起來
 *      狀態壓縮的動態規劃
 *          只需要紀錄１-９是否出現過(９個位元的二進位代表)
 *          現在結尾字元只和前一個結尾字元有關：滾動陣列
 *          接新字元時需要注意狀態是否有改變(本來沒有的字元變成有，取OR)
 */
#include<bits/stdc++.h>
using namespace std;

const int M=1e9+7;
const int MaxQ=1e4;
const int MaxP=1e3;
const int MaxS=1<<9;

int dp[2][MaxS][9]={};
int qry[MaxQ][2];
int ord[MaxQ];
int ans[MaxQ];

bool compare(int a,int b){ return qry[a][0]<qry[b][0]; }
int main(){
	int Q, Qid;
	scanf("%d\n",&Q);
	/* 離線查詢 */
	for(int i=0;i<Q;i++)
		scanf("%d %d\n",&qry[i][0],&qry[i][1]), ord[i]=i;
	sort(ord,ord+Q,compare);
	/* 建立結尾位數的狀態轉移的新狀態 */
	vector<int> link[9];
	link[0]={0,1,2};
	link[1]={0,1,2,3};
	link[2]={0,1,2,3,4};
	link[3]={1,2,3,4,5};
	link[4]={2,3,4,5,6};
	link[5]={3,4,5,6,7};
	link[6]={4,5,6,7,8};
	link[7]={5,6,7,8};
	link[8]={6,7,8};
	/* 初始化：長度１時，１-９結尾的個數＝1 ，且當長度＝1的所有查詢答案數一定＝０*/
	for(int i=0;i<9;i++)
		dp[1][1<<i][i]=1;
	for(Qid=0;Qid<Q and qry[ord[Qid]][0]==1;Qid++)
		ans[ ord[Qid] ]=0;

	bool now=0, pre=1;
	for(int L=2; Qid<Q; L++,swap(pre,now)){
		/* 狀態轉移+滾動陣列 */
		memset(dp[now],0,sizeof(dp[now]));
		for(int fr=0;fr<9;fr++)
			for(int to:link[fr])
				for(int iS=1;iS<MaxS;iS++){
					int toS=iS|(1<<to);
					dp[now][toS][to]+=dp[pre][iS][fr];
					if(dp[now][toS][to]>=M)  dp[now][toS][to]-=M;
				}
		/* 輸出長度＝Ｌ時的所有查詢 */
		while(Qid<Q and L==qry[ord[Qid]][0])
			ans[ ord[Qid++] ]=dp[now][511][ qry[ord[Qid]][1]-1 ];
	}
	for(int Qid=0;Qid<Q;Qid++)
		printf("%d\n",ans[Qid]);
}