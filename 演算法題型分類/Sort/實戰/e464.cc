/* Greedy+爬行法 */
#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int R, n, x;
	while(scanf("%d %d",&R,&n) and R>=0 and n>=0){
		vector<int> pos(n);
		for(int i=0;i<n;i++)
			scanf("%d",&pos[i]);
		sort(pos.begin(),pos.end());
		int cnt=0;
		for(int frt=0,bck=0;frt<n and bck<n;cnt++){
			for(;frt<n and pos[frt]-pos[bck]<=R;frt++);
			for(frt--;bck<n and pos[bck]-pos[frt]<=R;bck++);
		}
		printf("%d\n",cnt);
	}
}