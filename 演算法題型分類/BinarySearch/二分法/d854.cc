/* 勘根定理：f(x1)*f(x2)<0,則在(x1,x2)之間至少存在有一根。
 * 根于根之差的绝对值≧１，以１為單位對每個區間做勘根。
 * 若根存在某個區間後，對該區間做二分法找根(精確度問題)。
 */
#include<bits/stdc++.h>
using namespace std;

const double ESP=1e-6;
double a, b, c, d;
inline double Func(double x){
	return a*x*x*x+b*x*x+c*x+d; } 
inline int Sign(double x){ return (x<-ESP)? -1: (x>ESP); }
inline double InStep(double nL,double nR,int Lsign){
	while(nR-nL>=ESP){
		double nM=(nR+nL)/2.0;
		int Msign=Sign( Func(nM) );
		if(Msign==0) return nM;
		else if(Msign==Lsign) nL=nM+ESP;
		else nR=nM-ESP;
	}
	return nL;
}
int main(){
	scanf("%lf %lf %lf %lf\n",&a,&b,&c,&d);
	for(double pivot=-100.00; pivot<100.00; pivot+=1.00){
		int Lsign=Sign(Func(pivot));
		int Rsign=Sign(Func(pivot+1.00-ESP));
		if(Lsign==0){ printf("%.2lf ",pivot); continue; }
		if(Rsign==0){ printf("%.2lf ",pivot+1.00-ESP); continue; }
		if(Lsign!=Rsign)
			printf("%.2lf ",InStep(pivot,pivot+1.00-ESP,Lsign));
	}
	if( Sign( Func(100.00) )==0 ) printf("100.00");
	putchar('\n');
}

