/* 給定３種操作方式，對應的方式？
 * １：加入該數字
 * ２：輸出數列中的最大值後刪除該數字
 * ３：輸出數列中的最小值後刪除該數字
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=INT_MAX;
int main(){
	int opt, x;
	multiset<int> memo;
	while(scanf("%d",&opt)!=EOF)
		switch(opt){
			case 1: 
				scanf("%d",&x); 
				memo.insert(x); 
				break;
			case 2: 
				printf("%d\n",*memo.rbegin()); 
				memo.erase(--memo.end()); 
				break;
			case 3: 
				printf("%d\n",*memo.begin());
				memo.erase(memo.begin());
				break;
		}
}