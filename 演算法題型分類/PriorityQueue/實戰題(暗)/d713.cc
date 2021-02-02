/* c010-uva10107的加強版:輸入的數量由1e4🔝2e5個
 * 題解：https://www.ptt.cc/bbs/Prob_Solve/M.1345237843.A.E5C.html
 * priorty_queue(49ms) 有太多elements時速度會降太多
 * 分成兩個priorty_queue(qL+qR)且qL和qR接在一起時就是一個完整的priorty_queue
 * qL是由大到小而qR是小到大的順序
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxQ=2e5;
int main(){
	long x;
	priority_queue<long,vector<long>,less<long>   > qL;
	priority_queue<long,vector<long>,greater<long>> qR;
 
	scanf("%ld\n",&x);
	qL.push(x);
	printf("%ld\n",qL.top());
 
	while(scanf("%ld\n",&x)!=EOF){
		if(qL.size()==qR.size()){
     /* 當兩邊的Heap一樣多時，讓qL多一個element
      * 判斷 qR是不是空掉 或者 輸入的數字小於qR最小的數字，假若成立則直接推入qL
      * 否則取出qR最小的數字推入qL並且將輸入的數字推入qR
      */
			if(x>qR.top()){
				qL.push(qR.top());
				qR.pop();
				qR.push(x);
			}else
				qL.push(x);
			printf("%ld\n",qL.top());
		}else{ // LQ.size()-RQ.size()=1
			/* 當qL多一個element時
       * 判斷 輸入的數字大於等於qR最小的數字，假若成立則直接推入qR
       * 否則取出qL最小的數字推入qR並且將輸入的數字推入qL
       */
      if(x<=qL.top()){
				qR.push(qL.top());
				qL.pop();
				qL.push(x);
			}else{ // x>=LQ.top()
				qR.push(x);
			}
			printf("%ld\n",qL.top()+qR.top()>>1);
		}
	}
}
