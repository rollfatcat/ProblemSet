/* 給定Ｎ個方塊(最多３０個)的長、寬、高，輸出能夠"疊加"的最大高度？
 * 疊加：下層方塊的長必須都大於上層的長 且 下層方塊的寬必須都大於上層的寬
 * 解題關鍵：疊加(LIS 進階題)＝二維(長×寬)的偏維排序
 * 狀態轉移時需考量到順序性：更新某個方塊時必須將"該方塊可以疊加上去"的其他方塊都更新完成。
 * 依據長(ｗ)排序後對小於寬(ｈ)的方塊做更新，故每個方塊有３種不同的擺法(長＜寬的限制)
 *      長＜寬的限制：避免更新時只要轉向(長寬互換)導致更新的順序性出問題
 *		偏維排序：可以透過 CDQ＋RMQ 實現Ｎ㏒Ｎ的查詢。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=30;
struct CUBE{
	int w, h, l;
	CUBE(int w=0,int h=0,int l=0):w(w),h(h),l(l){}
	bool operator<(const CUBE &rhs)const{ return w==rhs.w? h<rhs.h: w<rhs.w; }
}  cube[3*MaxN];
int dpv[3*MaxN];

int main(){
	int N, tot, W, H, L;
	for(int caseI=1;scanf("%d\n",&N) and N>0;caseI++){
		for(tot=0;N-->0;){
			scanf("%d %d %d\n",&W,&H,&L);
			cube[tot++]=(W<H)? CUBE(W,H,L): CUBE(H,W,L);
			cube[tot++]=(W<L)? CUBE(W,L,H): CUBE(L,W,H);
			cube[tot++]=(L<H)? CUBE(L,H,W): CUBE(H,L,W);
		}
		sort(cube,cube+tot);
		int ans=0;
		for(int i=0;i<tot;i++){
			dpv[i]=0;
			for(int j=0;j<i;j++)
				if(cube[j].w<cube[i].w and cube[j].h<cube[i].h)
					dpv[i]=max(dpv[i],dpv[j]);
			dpv[i]+=cube[i].l;
			ans=max(ans,dpv[i]);
		}
		printf("Case %d: maximum height = %d\n",caseI,ans);
	}
	
}