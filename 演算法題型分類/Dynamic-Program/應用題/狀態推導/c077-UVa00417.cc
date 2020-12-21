#include<bits/stdc++.h>
using namespace std;

const int MaxL=5;
int dp[6][26]={};
int sum_dp[6]={0,26};

char ss[MaxL+1];
int main(){
	/* dp[L][start] 當長度＝Ｌ且以 'a'+start 為開頭時的個數 
     * sum_dp[L]：長度＝Ｌ時的總數("不"包含Ｌ= ０,１,２,３..)
     */
    fill(dp[1],dp[1]+26,1);
	for(int L=2;L<=MaxL;L++)
		for(int start=0;start<=26-L;start++){
			for(int nxt=start+1;nxt<26;nxt++)
				dp[L][start]+=dp[L-1][nxt];
			sum_dp[L]+=dp[L][start];
		}
	/* 前綴和版本 
     * dp[L][start]：長度＝Ｌ時以從 'a' 為開頭到 'a'+start 為開頭的個數前綴和
     * sum_dp[L]：長度＝Ｌ時的前綴和(包含Ｌ= ０,１,２,３..)
     */
	for(int L=1;L<=MaxL;L++){
		for(int start=1;start<=26-L;start++)
			dp[L][start]+=dp[L][start-1];
		sum_dp[L]+=sum_dp[L-1];
	}

	while(scanf("%s",ss)!=EOF){
		int L=strlen(ss), base=ss[0]-'a';
		int number=sum_dp[L-1]+((base>0)? dp[L][base-1]:0);
		for(int i=1;ss[i]!='\0';i++){
			if(ss[i-1]>=ss[i]){
				number=-1; break;
			}
			number+=dp[L-i][ss[i]-'a'-1]-dp[L-i][base];
			base=ss[i]-'a';
		}
		printf("%d\n",number+1);		
	}
}