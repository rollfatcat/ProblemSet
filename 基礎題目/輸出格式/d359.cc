/* △ＡＢＣ 邊上各有一點(Ｆ,Ｄ,Ｅ)而 CF AD BE三邊交點形成△ＰＱＲ
 * 給定三邊的比例：ｘ＝AF/FB, ｙ＝BD/DC, ｚ＝CE/EA 和Ｓ＝△ＡＢＣ面積，求△ＰＱＲ面積？ 
 * 解題關鍵：孟氏定理
 * 本題有精確度問題，若先算出三塊小三角形後扣除會出錯：△PQR＝△ABC−△ABP−△ACR−△BCQ
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxS=5e3;
const int MaxZ=1e1;
int main(){
	int S, x, y, z;
	while(scanf("%d %d %d %d",&S,&x,&y,&z) and S){
        /* 觀察凸四邊形CAPB套上孟氏定理：(AP/PD)×(BD/BC)×(CE/EA)＝1， △ABP＝△ABD×(AP/AD) 
         * double ABP= S* y/(y+1) *(y+1)/(y*z+y+1);
         * 觀察凸四邊形CRAB套上孟氏定理：(CR/RF)×(FA/AB)×(BD/DC)＝1， △ACR＝△ACF×(CR/CF)
         * double ACR= S* x/(x+1) *(x+1)/(x*y+x+1);
         * 觀察凸四邊形CQBA套上孟氏定理：(BQ/QE)×(EC/CA)×(AF/FB)＝1， △BCQ＝△BCE×(BQ/BE)
         * double BCQ= S* z/(z+1) *(z+1)/(x*z+z+1);
         */ 
		printf("%.2lf\n",S*(1.0-y/(y*z+y+1.0)-x/(x*y+x+1.0)-z/(x*z+z+1.0) ));
	}
}