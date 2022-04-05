#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxT=1e4;
const double ESP=1e-9;

int N, M;
bool ans[MaxN];
bool pck[MaxN];
int data[MaxN][2];
int  ord[MaxN];
double t[MaxN];

bool compareX(int a,int b){ return t[a]>t[b]; }
bool compareY(int a,int b){ return t[a]<t[b]; }
bool check(double G,bool type){
	for(int i=0; i<N; i+=1){
		t[i]=data[i][0]-G*(data[i][0]+data[i][1]);
		ord[i]=i;
		pck[i]=0;
	}
	sort(ord,ord+N,(type)? compareX: compareY);
	double sum=0.0;
	for(int i=0; i<M; i+=1){
		sum+=t[ord[i]];
		pck[ord[i]]=1;
	}
	return sum>=0.0;
}
void output(bool type){
	int ansX=0;
	int ansY=0;
	for(int i=0; i<N; i+=1)
		if( ans[i] ){
			ansX+=data[i][0];
			ansY+=data[i][1];
		}
	if(ansX==0){ puts("0"); return; }
	if(ansY==0){ puts("1"); return; }
	// 約分
	int gcd=__gcd(ansX,ansY);
	ansX/=gcd; 
	ansY/=gcd;
	printf("%d/%d\n",(type)? ansX: ansY,ansX+ansY);
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i+=1)
		scanf("%d %d",&data[i][0],&data[i][1]);

	double nL=0.0;
	double nR=1.0;
	while(nR-nL>=ESP){
		double nM=(nL+nR)/2.0;
		if( check(nM,1) ){
			for(int i=0; i<N; i+=1)
				ans[i]=pck[i];
			nL=nM+ESP;
		}else
			nR=nM-ESP;
	}
	output(1);
	
	nL=0.0;
	nR=1.0;
	while(nR-nL>=ESP){
		double nM=(nL+nR)/2.0;
		if( check(nM,0) ){
			nL=nM+ESP;
		}else{
			for(int i=0; i<N; i+=1)
				ans[i]=pck[i];
			nR=nM-ESP;
		}
	}
	output(0);
}