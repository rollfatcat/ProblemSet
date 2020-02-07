/* 二維陣列的模擬轉換題(難)，給定漲跌的字串後輸出股市的走向
 * 一般來說座標系是左下為(0,0)但輸出時是Col By Col所以左上才是(0,0)。
 * 且印出來的陣列從第０列開始但股市的最低限可以為負數，需要調整最低底線。
 * 以上兩點需要做一次座標的重新定位。
 * 根據漲跌的字串印出對應的漲跌字元，注意'R''C'和'F'的『執行順序』不同。
 * 輸出時需要判斷第０列是不是都是space，若是則直接pass
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxSz=50+5;
char mapss[MaxSz][MaxSz];
char inss [MaxSz];
inline int CharToInt(char c){ return (c=='R')?1:(c=='C')?0:-1; }
inline char CharToChar(char c){ return (c=='R')?'/':(c=='C')?'_':'\\'; }
inline bool IsSpace(int L){
	for(int i=1;i<L;i++)
		if(mapss[0][i]!=' ')
			return false;
	return true;
}

int main(){
	int caseN, L, maxH, minH, nowH; 
	scanf("%d\n",&caseN);
	for(int caseI=1;caseI<=caseN;caseI++){
		scanf("%s\n",inss), L=strlen(inss);
		nowH=maxH=minH=0;
		for(int i=0;inss[i]!='\0';i++)
			nowH+=CharToInt(inss[i]),
			minH=min(minH,nowH),
			maxH=max(maxH,nowH);
		memset(mapss,' ',sizeof(mapss));
		for(int i=0;i<=maxH-minH;i++)
			mapss[i][0]='|',
			mapss[i][L+2]='\0';
		nowH=maxH;
		for(int i=0;i<L;i++){
			if(inss[i]=='F')
				nowH-=CharToInt(inss[i]),
				mapss[nowH][i+2]=CharToChar(inss[i]);
			else
				mapss[nowH][i+2]=CharToChar(inss[i]),
				nowH-=CharToInt(inss[i]);
		}
		printf("Case #%d:\n",caseI);
		for(int i=IsSpace(L+2);i<=maxH-minH;i++)
			printf("%s\n",mapss[i]);
		putchar('+');
		for(int i=0;i<L+2;i++)
			putchar('-');
		putchar('\n');
	}
}