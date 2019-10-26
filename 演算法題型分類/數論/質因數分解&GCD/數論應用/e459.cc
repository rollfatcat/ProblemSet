/* 給你兩個點，座標為(x1,y1)和(x2,y2)
 * 請你求出此兩點連出的線段上有幾個x和y都為整數的點(包含兩點)
 */
#include<bits/stdc++.h>
using namespace std;
 
struct POINT{ long x, y; } st, ed;
int main(){
	int caseT;
	for(scanf("%d",&caseT); caseT--;){
		scanf("%ld %ld %ld %ld",&st.x,&st.y,&ed.x,&ed.y);
		long dx=st.x-ed.x;
		long dy=st.y-ed.y;
		printf("%ld\n",abs(dx/__gcd(dx,dy))+1);
	}
}