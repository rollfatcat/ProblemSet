#include<bits/stdc++.h>
using namespace std;

const int MaxT=10;
const int N=10;
int cnt;
bool org[N][N];
bool tmp[N][N];

void push(int r,int c){
	if(0<r) tmp[r-1][c]^=1; // Up
	if(0<c) tmp[r][c-1]^=1; // Left
	tmp[r][c]^=1;           // Mid
	if(c<9) tmp[r][c+1]^=1; // Right
	if(r<9) tmp[r+1][c]^=1; // Down
}
bool func(int r,int c){
	if( r==10 ){
		for(int c=0; c<=9; c++)
			if( tmp[9][c] )
				return false;
		return true;
	}
	if( tmp[r-1][c] ){
		push(r,c);
		cnt+=1;
	}
	return (c==9)? func(r+1,0): func(r,c+1);
}
int main(){
	int caseT;
	string ss;
	
	cin>>caseT;
	while( caseT-->0 ){
		for(int r=0; r<N; r++){
			cin>>ss;
			for(int c=0; c<N; c++)
				org[r][c]= ss[c]=='O';
		}
		int ans_c=1<<30;
		for(int s=0; s<(1<<N); s++){
			// copy board from input 
			for(int r=0; r<N; r++)
				for(int c=0; c<N; c++)
					tmp[r][c]=org[r][c];
			cnt=0;
			for(int p, t=s; 0<t; t-=p){
				p= t&-t; // p is lowbit
				push( 0,__lg(p) );
				cnt++;
			}
			if( func(1,0) )
				ans_c=min(ans_c,cnt);
		}
		// output
		cout<<ans_c<<'\n';
	}
}