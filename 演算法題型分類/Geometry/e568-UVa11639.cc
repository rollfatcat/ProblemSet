/* 給定兩個矩形, 輸出：ＡＢ交集/聯集/補集
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=100;
struct REC{
	int lx, ly, rx, ry;
	int CountArea(){ return (rx-lx)*(ry-ly); }
	int CrossArea(REC &rhs){
		// No InterSection, Area＝0
		if(lx>=rhs.rx or rx<=rhs.lx or ly>=rhs.ry or ry<=rhs.ly)
			return 0; 
		return (min(rx,rhs.rx)-max(lx,rhs.lx))*(min(ry,rhs.ry)-max(ly,rhs.ly));
	}
} A, B;

int main(){
	int caseT;
	scanf("%d",&caseT);
	for(int caseI=1;caseI<=caseT;caseI++){
		scanf("%d %d %d %d",&A.lx,&A.ly,&A.rx,&A.ry);
		scanf("%d %d %d %d",&B.lx,&B.ly,&B.rx,&B.ry);
		int crs_area=A.CrossArea(B);
		int sum_area=A.CountArea()+B.CountArea()-(crs_area<<1);
		printf("Night %d: %d %d %d\n",caseI,crs_area,sum_area,100*100-crs_area-sum_area);
	}
}
