/* 題目本身不難, 但需要思考特殊情況(第一次就猜中)
 */
#include<bits/stdc++.h>
using namespace std;

char ss[10];
int main(){
	int x, ans;
	while(scanf("%d\n",&x) and x>0){
		scanf("%s %s\n",ss,ss);
		// 特殊情況：第一次就猜中答案則直接輸出"Stan may be honest"
		if(ss[0]=='o'){ puts("Stan may be honest"); continue; }
		
		queue<int> guess;
		queue<bool> rsp;
		guess.push(x), rsp.push(ss[0]=='h');
		while(scanf("%d\n%s %s\n",&x,ss,ss) and ss[0]!='o')
			guess.push(x), rsp.push(ss[0]=='h');
		bool IsHonest=true;
		for(ans=x;!guess.empty() and IsHonest;guess.pop(),rsp.pop())
			IsHonest=((guess.front()>ans)==rsp.front());
		puts((IsHonest)?"Stan may be honest":"Stan is dishonest");
	}
}