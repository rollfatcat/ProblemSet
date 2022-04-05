/* 題目給定突出的長度，至少需要多少塊疊加的木板才能超過該長度？
 * 疊加方式：疊加第ｉ塊木板的整體長度＝1/2+1/3+...+1/(i+1)
 * 解題關鍵：木板突出的除法導致精確度＋二分搜尋法STL
 */
#include<bits/stdc++.h>
using namespace std;

vector<double> len={0.0};
int main(){
	for(int i=2; len.back()<=5.2; i++)
		len.push_back(len.back()+1.0/i);
	double x;
	while(scanf("%lf\n",&x)!=EOF)
		printf("%d card(s)\n",lower_bound(len.begin(),len.end(),x)-len.begin());
}