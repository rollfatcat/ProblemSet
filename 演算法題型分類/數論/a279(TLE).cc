/* 給定Ｎ個糖果試圖平均分給Ｍ個人和Ｅ個單位的能量。
 * 糖果可以放入機器增量但會消耗一個單位的能量，規則：f(x)=4x+3, g(x)=8x+7
 * 問能剛好均分給Ｍ個人的前提下最少化消耗的能量是多少？
 * 直覺：BFS展開狀態，並記錄已經找過的數字，直到找到餘數＝0時輸出最少的轉換次數。
 * 問題：Ｍ的數值極大，狀態展開和檢查時的次數會過多。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=20111021;
const int MaxE=314159;
struct NODE{
	int n, e;
	NODE(int n=0,int e=0):n(n),e(e){}
} now, nxt;
int main(){
	
	int N, M, E;
	while(scanf("%d %d %d\n",&N,&M,&E)!=EOF){
		bool GetAns=0;
		set<int> memo;
		queue<NODE> Q;
		Q.push(NODE(N%M,0));
		while(Q.empty()==0){
			now=Q.front(); Q.pop();
			if(now.n==0){ GetAns=1; printf("%d\n",now.e); break; }
			if(memo.find(now.n)!=memo.end()) 
				continue;
			memo.insert(now.n);
			nxt=NODE( ((now.n<<2)+3)%M, now.e+1);
			if(memo.find(nxt.n)==memo.end() and nxt.e<=E)	
				Q.push(nxt);
			nxt=NODE( ((now.n<<3)+7)%M, now.e+1);
			if(memo.find(nxt.n)==memo.end() and nxt.e<=E)	
				Q.push(nxt);
		}
		if(GetAns==0) puts("-1");
	}
	
}


