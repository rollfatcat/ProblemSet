/* 給定中序運算式(Infix Notation)，輸出後序運算式(Postfix Notation)？
 * 解題關鍵：Stack
 * 題目保證每個運算元和運算子都有空白間格＝抓取字串後判斷後面的字元是否為空白，是的話就繼續，否則該筆測資結束。
 */
#include<bits/stdc++.h>
using namespace std;
 
int wgt[128]={};
int main(){
	/* 設定運算符號的權重 */
    wgt['+']=wgt['-']=1;
	wgt['*']=wgt['/']=2;
 
	string var;
	while(cin>>var){
		stack<char> opt;
        /* 中序轉換後序的流程：
         * 運算子：直接輸出
         * 運算元：
         *       左括號 - 放入堆疊
         *       右括號 - Pop堆疊直到左括號出現，左括號也要 pop 掉
         *       +-×÷  - Pop堆疊直到空掉或者頂端的運算元權重低於目前的運算元。
         */
		// 判斷第一個字元是不是 '('
		if(var[0]=='(')
			opt.push('(');
		else
			cout<<var;
		while(cin.get()==' '){
			cin>>var;
			switch(var[0]){
				case '(': 
					opt.push(var[0]); 
					break;
			    case ')':
			  	    for(; opt.top()!='('; opt.pop())
			  		    cout<<' '<<opt.top();
			  	    opt.pop();
			  	    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    for(; opt.empty()==0 and wgt[opt.top()]>=wgt[var[0]]; opt.pop();)
                        cout<<' '<<opt.top();
                    opt.push(var[0]);
                    break;
                default: 
                    cout<<' '<<var;
            }
		}
        /* 清空堆疊內的運算符號 */
		for(; opt.empty()==0; opt.pop())
			cout<<' '<<opt.top();
		cout<<'\n';
	}
}