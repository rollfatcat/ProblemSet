/* 給定３個幸運號碼、５個兌獎區號碼和對應的獎金，輸出彩券可獲的金額(最後輸出金額時不會少於０)？
 *   前兩個號碼：只要幸運號碼和兌獎區號碼相同時即可獲得對應的獎金。
 * 最後一個號碼：若不存在兌獎區則獎金翻倍，若有和兌獎區號碼相同時即需扣除對應的獎金
 * 注意：幸運號碼和兌獎區號碼都可以重複出現。
 */
#include<bits/stdc++.h>
using namespace std;

int pick[3];
int pool[5];
int  val[5];


int main(){
	while(scanf("%d %d %d\n",&pick[0],&pick[1],&pick[2])!=EOF){
		scanf("%d %d %d %d %d\n",&pool[0],&pool[1],&pool[2],&pool[3],&pool[4]);
		scanf("%d %d %d %d %d\n",&val[0],&val[1],&val[2],&val[3],&val[4]);
		int get=0;
		for(int i=0;i<5;i++){
			if(pool[i]==pick[0])
				get+=val[i];
			if(pool[i]==pick[1])
				get+=val[i];
		}
		int off=0;
		for(int i=0;i<5;i++)
			if(pool[i]==pick[2])
				off+=val[i];
		printf("%d\n", (off==0)? (get<<1): (get-off>0)? (get-off): 0);
	}
}