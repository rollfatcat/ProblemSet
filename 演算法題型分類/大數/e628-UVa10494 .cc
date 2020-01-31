/* (偽)大數除法和取餘數，除數＜2^31
 * 模擬建構式過程
 */
#include<bits/stdc++.h>
using namespace std;

char ss[1002];
int main(){
	char opt;
	int idx, num;
	while(scanf("%s %c %d",ss,&opt,&num)==3){
		long now=0;
		int L=strlen(ss);
		if(opt=='%'){
			for(idx=0;idx<L;idx++)
				now=(now*10+ss[idx]-'0')%num;
			printf("%ld\n",now);
		}else{ 
			/* 商數的開頭不得為０, 除非商數＝0 */
			for(idx=0;idx<L and now<num;idx++)
				now=now*10+ss[idx]-'0';
			putchar(now/num+'0'), now%=num;
			for(;idx<L;idx++)
				now=(10*now+ss[idx]-'0'),
				putchar(now/num+'0'), 
				now%=num;
			putchar('\n');
		}
	}
}