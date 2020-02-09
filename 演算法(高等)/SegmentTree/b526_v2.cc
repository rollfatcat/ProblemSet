// 想法等同於v1版本，只是計算『線段重疊』時的判斷方式略微不同
#include<bits/stdc++.h>
using namespace std;

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main() {
	int n, m, l, r;

	scanInt(n), scanInt(m);
	vector< pair<int, int> > V;
	vector<int> X;
	for(int i=0; i<m; i++){
	  scanInt(l), scanInt(r),
		V.push_back(make_pair(l, r));
		X.push_back(l-1);
		X.push_back(l);
		X.push_back(r);
		X.push_back(r+1);
	}
	sort(X.begin(), X.end());
	sort(V.begin(), V.end());
	X.resize(unique(X.begin(), X.end())-X.begin());
	multiset<int> S;
	int ret=0;
	for(int i=1,pos=0; i<X.size(); i++){
		while(!S.empty() and *S.begin()<=X[i-1])
			S.erase(S.begin());
		while(pos<m and V[pos].first==X[i])
			S.insert(V[pos].second), pos++;
		if(S.size()&1)
			ret+=X[i]-X[i-1];
	}
	printf("%d\n",n-ret);
}
/*
10 4
2 8
3 4
5 7
6 9

10 5
1 4
2 5
3 7
5 8
6 9
*/