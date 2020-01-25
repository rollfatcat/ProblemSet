/* 給定一個數字，求經過排序後所有的數字中取出兩個數字的差值最大化是多少？且該差值必須被９整除
 * 差值必須被９整除是一個無意義的條件(數學證明：10^x-10^y必定可以被９整除)
 * 最大值＝字元由大到小排列
 * 最小值＝字元由小到大排列但開頭不能是０，所以排序後找到第一個不是'0'的字元和開頭的'0'交換位置
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxNumber=2e9;
char Numss[15];
int main(){
	long maxv, minv, tenpower;
	while(scanf("%s",Numss)!=EOF){
		int idx, L=strlen(Numss);
		sort(Numss,Numss+L);
		minv=maxv=0;
		for(idx=L-1;idx>=0;idx--)
			maxv=10*maxv+Numss[idx]-'0';
		tenpower=1;
		for(idx=0;Numss[idx]=='0';idx++,tenpower*=10);
		minv=(Numss[idx]-'0')*tenpower;
		for(idx++;idx<L;idx++)
			minv=10*minv+Numss[idx]-'0';
		printf("%ld - %ld = %ld = 9 * %ld\n",maxv,minv,maxv-minv,(maxv-minv)/9);
	}
}