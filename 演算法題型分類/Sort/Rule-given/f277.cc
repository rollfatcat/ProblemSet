/* 給定Ｎ位同學的姓名、班級、座號、自介，依照班級和座號排序後參照格式輸出。
 * 解題關鍵：sort by origin data
 * 每位同學的姓名和自介雖然不包含空格但題目並沒有保證字串長度。
 * 排序時需要交換兩位同學的資訊太浪費時間，所以產生一個新的陣列紀錄"資料編號"，排序資料編號即可。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e5;
string name[MaxN];
string intr[MaxN];
int clas[MaxN];
int seat[MaxN];
int ord[MaxN];
 
bool compare(int a,int b){ return (clas[a]==clas[b])? seat[a]<seat[b]: clas[a]<clas[b]; }
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int N;
	while(cin>>N){
		for(int i=0;i<N;i++)
			cin>>name[i]>>clas[i]>>seat[i]>>intr[i],
			ord[i]=i;
		sort(ord,ord+N,compare);
		for(int i=0;i<N;i++)
			cout<<clas[ord[i]]<<' '<<seat[ord[i]]<<' '<<name[ord[i]]<<'\n',
			cout<<intr[ord[i]]<<'\n';
	}
}