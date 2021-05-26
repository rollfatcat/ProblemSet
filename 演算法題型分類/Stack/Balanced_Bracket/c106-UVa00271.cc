/* 每次給定字串後，根據「規則」判斷該字串是否合法？
 * (0) 這個語言中僅有 p 到 z，還有 N，C，D，E，I 這幾個字母。 
 * (1) 從 p 到 z 中，任何一個字母都是一個正確的句子。 
 * (2) 如果 s 是一個正確的句子，那麼 Ns 也是。 
 * (3) 如果 s 及 t 都是正確的句子，那麼 Cst, Dst, Est 還有 Ist 也都是正確的句子。
 * 解題關鍵：Stack 的判斷方式＋從現在的狀態反推規則
 * 字元是最小的合法字串單位，檢查 Stack 內的狀態來判斷是否合法。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=256;
char ss[MaxL+2];

int main(){
	while(scanf("%s\n",ss)!=EOF){
		bool legal=1;
		stack<int> S;
		for(int i=0;ss[i]!='\0' and legal;i++)
			/* "CDEI" : 需要對後面"兩個合法字串"做合併判斷：先存入堆疊 
             * "N"    : 需要貼在"一個合法字串"前面：先存入堆疊
             * "pqrstuvwxyz" : 目前是合法的字串(單位字元一定是合法)
             *                 依序檢查堆疊最上層的"狀態" (若存在，所以要再判斷堆疊是否為空)
             *                   (1) Stack.top()==1 代表可以直接把Ｎ貼在這個合法字串形成合法字串，接著判斷。
             *                   (2) Stack.top()==2 代表後續需要再一個合法字串，所以先存入堆疊。
             *                   (2) Stack.top()==0 代表目前有２個合法字串，此時需要檢查堆疊最上方的下一個是否為"CDEI"
             *                                          若不符合則一定非法
             *  other : 非法字元，不合法直接結束迴圈判斷
             */
            if(ss[i]=='C' or ss[i]=='D' or ss[i]=='E' or ss[i]=='I'){
				S.push(2);
			}else if(ss[i]=='N'){ 
				S.push(1);
			}else if('p'<=ss[i] and ss[i]<='z'){
				while(S.empty()==0 and S.top()<2){ 
					if(S.top()==1)
						S.pop();
					else{ //(S.top()==0)
						S.pop();
						if(S.empty()==0 and S.top()==2)
							S.pop();
						else
							legal=0;
					}
				}
				S.push(0);
			}else{
				legal=0;
			}
		puts( (legal and S.size()==1 and S.top()==0)? "YES": "NO");
	}
}