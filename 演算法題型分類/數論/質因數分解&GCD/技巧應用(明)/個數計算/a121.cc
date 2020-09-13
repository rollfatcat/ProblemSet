/* 給定ＡＢ( 保證１≦Ａ≦Ｂ≦１e８ )作為範圍，輸出範圍內的質數個數？
 * 解題關鍵：根號範圍內的質數判斷
 * 特殊案例：１不屬於質數
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e8;
const int sqrN=1e4;
vector<int> prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main(){
	/* 檢查 1e8 以內會用到的質數範圍定為 1e4
	 * 1e4 內有 1229 個質數。
	 */
	bool NotP[sqrN+1]={};
	for(int i=4;i<=sqrN;i+=2)
		NotP[i]=0;
	for(int i=1;i<25;i++)
		for(int j=3;prime[i]*j<=sqrN;j+=2)
			NotP[prime[i]*j]=1;
	for(int i=101;i<=sqrN;i+=2)
		if(NotP[i]==0)
			prime.push_back(i);
	/* main */
	int A, B;
	while(scanf("%d %d\n",&A,&B)!=EOF){
		int cnt=0;
		for(int now_v=A+(A==1); now_v<=B; now_v++){
			int idx=0;
			while(idx<prime.size() and prime[idx]*prime[idx]<=now_v and now_v%prime[idx]>0)
				idx++;
            /* 保證根號內的所有質數都測試過無法整除：
             * 若因為整除跳開迴圈，則目前測試的質數平方一定會小於等於數字
             */
			cnt+= idx==prime.size() or prime[idx]*prime[idx]>now_v;
		}
		printf("%d\n",cnt);
	}
}