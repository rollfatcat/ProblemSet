/* 給定一個算式列, 最多由12個數字組成，每個數字介於1到20之間且運算符號只有＋和×
 * 問最大化和最小化的運算結果。
 * 最小化＝先乘後加, 最大化＝先加後乘, 改變運算的權重
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	char ss[300]; // 最多由12個數字組成，每個數字介於1到20之間
	int caseT;
	
	scanf("%d",&caseT);
	while(caseT--){
		scanf("%s",ss);
		stack<long> maxS;
		stack<long> minS;
		
		int i=0;
		long number=0;
		while('0'<=ss[i] and ss[i]<='9')
			number=10*number+ss[i++]-'0';
		maxS.push(number);
		minS.push(number);
		if(ss[i]=='\0'){  // 若 算式列只有一個數字時則直接輸出
			printf("The maximum and minimum are %ld and %ld.\n",number,number);
			continue;
		}
		bool opt=(ss[i++]=='*');
		for(number=0;ss[i]!='\0';i++)
			if(ss[i]=='+' or ss[i]=='*'){
				if(opt) 
					minS.top()*=number,
					maxS.push(number); 
				else 
					minS.push(number),
					maxS.top()+=number;
				number=0;
				opt=ss[i]=='*';
			}else
				number=10*number+ss[i]-'0';
		
		if(opt) 
			minS.top()*=number,
			maxS.push(number); 
		else 
			minS.push(number),
			maxS.top()+=number;
		
		for(number=1;maxS.empty()==0;maxS.pop())
			number*=maxS.top();
		printf("The maximum and minimum are %ld",number);
		for(number=0;minS.empty()==0;minS.pop())
			number+=minS.top();
		printf(" and %ld.\n",number);
	}
}