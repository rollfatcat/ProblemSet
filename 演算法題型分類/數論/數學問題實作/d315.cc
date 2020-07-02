/* 給定ｎ和ｘ求 sinｘ+sin２x+sin３x+sin４x+……+sinｎx？
 * Σ sinｋx, １≦ｋ≦ｎ，四捨五入到小數點第四位。
 * 解題關鍵：三角函數的和差化積推導
 *	cos(Ａ+Ｂ)＝cosＡcosＢ-sinＡsinＢ
 *	cos(Ａ-Ｂ)＝cosＡcosＢ+sinＡsinＢ
 *	cos(Ａ+Ｂ)-cos(Ａ-Ｂ)＝-２sinＡsinＢ, Ａ=0.5x Ｂ=kx
 *  cos1.5x-cos0.5x+cos2.5x-cos1.5x+....+cos(n+0.5)x-cos(n-0.5)x
 *  ＝cos(n+0.5)x-cos0.5x＝-２sin0.5x Σ sinｋx
 *  Σ sinｋx＝ (cos(n+0.5)x-cos0.5x) / -２sin0.5x
 * 實作細節：
 *   (1) PI=3.1415926 ≠ acos(-1), 第２筆測資會因為精確度出問題
 *   (2) 呼叫sin(ｘ)和cos(ｘ)時ｘ單位是弧度(π)，但數學式單位是度
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxX=(1<<31)-1;   // max_int
const __int128 MaxN=1e31-1; // 1e31-1
const double PI=3.1415926;  // PI=acos(-1)

inline int StrToNum(char *ss,__int128 N=0){
	for(int i=0;ss[i]!='\0';i++)
		N=(N<<3)+(N<<1)+ss[i]-'0';
	return N%360;
}
int main(){
	int Dx, N;
	double Rx;
	char Nss[35];
	
	while(scanf("%s %d\n",Nss,&Dx) and Dx){
		Dx%=360, N=StrToNum(Nss);
		if(Dx==0){ puts("0.0000"); continue; }
		Rx=Dx*PI/180.0;
		printf("%.4lf\n",-(cos( (N+0.5)*Rx )-cos( Rx/2.0 ))/sin( Rx/2.0 )/2.0);
	}
}