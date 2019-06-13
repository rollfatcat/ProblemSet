/* 這題沒有想象的簡單：
 * 反推x時要嘗試0~9所有可能，x可能不只一個
 * 避免字串重複且要排序 => set的STL
 */
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int main(){
  int N, R, Dsum=0, test;
  string Nss;
  set<string> Kss;

  cin>>N>>R>>Nss;
  for(int i=0;i<Nss.length();i++)
    Dsum+=Nss[i]-'0';
  for(test=0;test<=9;test++){
    int now=Dsum+test;
    for(int nxt; now>9; now=nxt)
      for(nxt=0; now; nxt+=now%10,now/=10);
    if(now==R){
      char ch=test+'0';
      for(int i=0;i<Nss.length();i++)
        Kss.insert(Nss.substr(0,i)+ch+Nss.substr(i));
      Kss.insert(Nss+ch);
    }
  }
  Kss.erase(Kss.begin());
  Kss.erase(--Kss.end());
  for(auto it:Kss)
    cout<<it<<endl;
}
/* 測資：5 5 7007
 * 輸出：70007, 70070, 70079, 70907, 79007
 */