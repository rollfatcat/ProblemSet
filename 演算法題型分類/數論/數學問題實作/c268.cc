// 很好的數學題(看不出來會用到費波那契數列)
// 99%(最後一筆會因為輸入檔過大TLE，請使用 cin>>ws, cin.ignore(1e9,'\n'))
/* n根磁鐵條中，有沒有任何3根可以構成一個三角形
 * 三角形組成的充分必要條件就是：兩個較短邊邊長之和＞第三邊的邊長
 * 將所有邊排序後，該集合無法構成的『邊長最短』情況為：L[n]=L[n-1]+L[n-2]
 * 當ｎ＝３，數字最小且不能組成三角形的數列為 １、１、２
 * 當ｎ＝４，數字最小且不能組成三角形的數列為 １、１、２ 、３
 * 當ｎ＝５，數字最小且不能組成三角形的數列為 １、１、２ 、３、５
 * 當ｎ＝６，數字最小且不能組成三角形的數列為 １、１、２ 、３、５、８
 * 當ｎ＝７，數字最小且不能組成三角形的數列為 １、１、２ 、３、５、８、１３
 * ……由上的趨勢，我們可以看出不能組成三角形的最小數列之規律正是費氏數列。
 * 觀察費波那契數列成長的情況，當ｎ＝45時是極限，因為當ｎ＝46時，數列最後一項為1134903170。
 * 但題目保證最長邊不超過1e9，所以根據反證法，當輸入邊長個數多於46時必定可以構成一個三角形
 */
#include<bits/stdc++.h>
using namespace std;


int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int T, N, i,len[50];
  cin>>T;
  while(T--){
    cin>>N;
    if(N<=45){
      for(i=0;i<N;i++)
        cin>>len[i];
      sort(len,len+N);
      for(i=2;i<N and len[i]>=len[i-1]+len[i-2];i++);
      cout<<((i==N or N<=2)?"NO\n":"YES\n");
    }else{
      cin>>ws; // <- 這行是必要的...
      cin.ignore(1e9,'\n');
      cout<<"YES\n";
    }
  }
}