/* 給定Ｎ個號碼建立雙向鏈結，經過Ｍ次的操作後，輸出Ｑ次查詢。
 * 解題核心：雙向鏈結。UVa12657(簡易版)
 * 操作 ＣＡＢ
 *      Ｃ=Ｆ時編號Ａ放在編號Ｂ的順時針方向(前) 
 *      Ｃ=Ｒ時編號Ａ放在編號Ｂ的順時逆方向(後)
 * 查詢時Ａ：輸出編號Ａ的前後號碼是多少？
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e5;
const int MaxM=1e3;
const int MaxQ=30;
struct NODE{
	int val;
	NODE* pre;
	NODE* nxt;
  NODE(int x):val(x),pre(nullptr),nxt(nullptr) {}
  NODE(int x,NODE *pre,NODE *nxt):val(x),pre(pre),nxt(nxt) {}
};
NODE* ball[MaxN];


int main(){
	int N, M, Q, A, B;
	char ch;
	
	scanf("%d %d %d\n",&N,&M,&Q);
	/* 初始化：雙向環狀鏈結 */
	ball[0]=new NODE(0);
	for(int i=1;i<N;i++){
		ball[i]=new NODE(i);
		ball[i]->pre=ball[i-1];
		ball[i-1]->nxt=ball[i];
	}
	ball[0]->pre=ball[N-1];
	ball[N-1]->nxt=ball[0];
	/*  根據操作 */
	for(int i=0;i<M;i++){
		scanf("%c %d %d\n",&ch,&A,&B);
		/* ＡＢ編號相同時則不移動小球 */
		if(A==B) continue;
		/* 移除Ａ */
		ball[A]->pre->nxt=ball[A]->nxt;
		ball[A]->nxt->pre=ball[A]->pre;
		/* 將Ａ放到Ｂ的逆時針方向(前面) */
		if(ch=='R'){ 
			ball[A]->pre=ball[B]->pre;
			ball[B]->pre->nxt=ball[A];
			ball[A]->nxt=ball[B];
			ball[B]->pre=ball[A];
		}else{ /* 將Ａ放到Ｂ的順時針方向(後面) */
			ball[A]->nxt=ball[B]->nxt;
			ball[B]->nxt->pre=ball[A];
			ball[A]->pre=ball[B];
			ball[B]->nxt=ball[A];
		}
	}
	for(int i=0;i<Q;i++)
		scanf("%d",&A),
		printf("%d %d ",ball[A]->pre->val,ball[A]->nxt->val);
	putchar('\n');
}

