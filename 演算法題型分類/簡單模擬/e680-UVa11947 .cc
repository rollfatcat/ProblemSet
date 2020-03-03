/* 給定一個日期後，從那天往後推算280天後的日期和屬於哪個星座？
 * 本題需要考慮根據年份考慮『閏年』
 * 閏年：能被400整除 或是 能被4整除且不能被100整除
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=1e3;
char ss[10];
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline bool IsLeap(int Y){ 
	return (Y%400==0) or (Y%4==0 and Y%100); }
inline int DateToZodiacSign(int M,int D){
	if(M==1 and D<=20) return 11;
	if(M== 1 or M== 2 and D<=19) return 0;
	if(M== 2 or M== 3 and D<=20) return 1;
	if(M== 3 or M== 4 and D<=20) return 2;
	if(M== 4 or M== 5 and D<=21) return 3;
	if(M== 5 or M== 6 and D<=21) return 4;
	if(M== 6 or M== 7 and D<=22) return 5;
	if(M== 7 or M== 8 and D<=21) return 6;
	if(M== 8 or M== 9 and D<=23) return 7;
	if(M== 9 or M==10 and D<=23) return 8;
	if(M==10 or M==11 and D<=22) return 9;
	if(M==11 or M==12 and D<=22) return 10;
	return 11;
}
char ZodiacSign[12][20]={
	"aquarius","pisces","aries","taurus","gemini","cancer","leo","virgo","libra","scorpio","sagittarius","capricorn"
};
int main(){
	int caseT; scanf("%d\n",&caseT);
	for(int caseI=1;caseI<=caseT;caseI++){
		scanf("%s\n",ss); //格式：MMDDYYYY
		int M=10*(ss[0]-'0')+ss[1]-'0',
		    D=10*(ss[2]-'0')+ss[3]-'0',
		    Y=1000*(ss[4]-'0')+100*(ss[5]-'0')+10*(ss[6]-'0')+(ss[7]-'0');
		for(D+=280; D>days[M]+(M==2 and IsLeap(Y)); ){
			D-=days[M]+(M==2 and IsLeap(Y));
			M++;
			Y+= M==13;
			if(M==13) M=1;
		}
		printf("%d %02d/%02d/%04d %s\n",caseI,M,D,Y,ZodiacSign[DateToZodiacSign(M,D)]);
	}
}