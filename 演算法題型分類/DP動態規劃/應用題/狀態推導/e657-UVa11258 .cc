/* 求字串經過"適當的切割"最大的和
 * 限制：字串切割時,字串轉換後的數字不能超過"32位有號整數" 
 * 枚舉每個字元, 從現在的字元依照切割方式往(最多)回推9個字元並找出最大的和記錄在陣列中
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxCaseN=500;
const int MaxLen=200;
const int MaxNum=(1<<31)-1;

char ss[MaxLen+2];
long v[MaxLen+2]; // v[x]＝ss[0:x]時最大的和
int main(){
	int caseN;
	scanf("%d",&caseN);
	while(caseN--){
		scanf("%s",ss);
		int L=strlen(ss);
		v[0]=ss[0]-'0';
		for(int idx=1;idx<L;idx++){
			long now_v=0, base=1;
			v[idx]=0;
			for(int j=idx;j>=0;j--,base*=10){
				now_v=base*(ss[j]-'0')+now_v;
				if(now_v>MaxNum)
					break;
				v[idx]=max(v[idx],v[j-1]+now_v);
			}
		}
		printf("%ld\n",v[L-1]);
	}
}