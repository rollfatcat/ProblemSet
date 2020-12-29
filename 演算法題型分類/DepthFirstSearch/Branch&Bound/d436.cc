/* 給定一個字串(長度不超過10)，依照 ASCii 輸出這些字所有的排列方式(不重複)？
 * 解題關鍵：Permutation + Branch & Bound
 * 問題盲點：70ms(Branch & Bound) vs 1.5s(set to check copy one)
 * 紀錄「同一層遞迴」的字元在選擇時避免選到同一個，所以需要記錄這一層使用到的前一個字元
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=10;
int L;
char ans[MaxN+2];
char ord[MaxN+2];
bool use[MaxN];
void PickChar(int depth){
  // 停止條件：已經全部選取完，輸出字串
	if(depth==L){ puts(ans); return; }
  // 紀錄「同一層遞迴」的字元在選擇時避免選到同一個，所以需要記錄這一層使用到的前一個字元
	char pre=' ';
	for(int i=0;i<L;i++)
		if(use[i]==0 and pre!=ord[i]){
    	pre=ans[depth]=ord[i];
    	use[i]=1;
    	PickChar(depth+1);
    	use[i]=0;
    }
}
 
int main(){
  int caseT;
 
  scanf("%d\n",&caseT);
  while(caseT-->0){
    scanf("%s\n",ord);
    L=strlen(ord);
    ans[L]='\0';
    /* 需要依照 ASCii 順序輸出，所以預先排序 */
    sort(ord,ord+L);
    fill(use,use+L,0);
 
    PickChar(0);
    putchar('\n');
  }
}