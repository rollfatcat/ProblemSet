// 子字串會『循環』
// 測資範圍： 1 ≤ T ≤ 30，s的⻑度⾄少為1，最⻑不超過100000。在s中只會有⼤寫英⽂字⺟。
/* 合法字串是不包含重複字母的子字串，換句話說字串長度最多26個。
 * 暴力法：枚舉終點以不存在重複字母的情況下往前找形成的子字串
 * 錨定法：將重複的字母之前的位置都設定成-1 代表未存在Set中且更新子字串
 */
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int caseT;
  string ss;
  cin>>caseT;
  while(caseT--){
    cin>>ss;
    ss+=ss.substr(0,min((int)ss.length(),26));

    vector<int> InSet(26,-1);
    string subss="";
    int  maxL=0, nowL=0;
    for(int j,i=0;i<ss.length();i++){
      int nowc=ss[i]-'A';
      if(InSet[nowc]>=0){ // 字母出現重複的情況
        maxL=max(maxL,nowL); // 結算上一次的長度
        for(j=0;subss[j]!=ss[i];j++)
          InSet[ subss[j]-'A' ]=-1;
        subss=subss.substr(j+1,nowL)+ss[i];
        nowL=subss.length();
        InSet[nowc]=i;
      }
      else {
        nowL++,
        InSet[nowc]=i,
        subss+=ss[i];
      }
    }
    cout<<maxL<<'\n';
  }
}
/*
2
XDDORZQQ
IKKZZZSSH
*/