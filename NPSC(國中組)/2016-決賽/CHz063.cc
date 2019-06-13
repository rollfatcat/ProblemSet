// 題目要求找到PPAP(四段等長且A可以和P相等)格式的最長子字串(字典序最小)
// 輸入範圍：1 ≤ |s| ≤ 300
// 想法：先找到開頭和字串長度

#include<iostream>
#include<vector>
using namespace std;

int main(){
  string ss, ans="";
  vector<short> pos[26];

  cin>>ss;
  for(int i=0;ss[i]!='\0';i++)
    pos[ss[i]-'A'].push_back(i);
  for(int Pst=0;Pst<=25;Pst++){
    if(pos[Pst].size()<=2) continue;
    // 枚舉兩個點座標，算出子字串長度，用來檢查第三個子字串開頭位置是否也是相同字元
    for(int p1=0;p1<pos[Pst].size();p1++)
      for(int p2=p1+1;p2<pos[Pst].size();p2++){
        int len=pos[Pst][p2]-pos[Pst][p1];
        int p3=pos[Pst][p2]+(len<<1);
        if((p3+len)<=ss.length() and ss[p3]==(Pst+'A')){
          string P1=ss.substr(pos[Pst][p1],len);
          string P2=ss.substr(pos[Pst][p2],len);
          string P3=ss.substr(p3,len);
          if(P1==P2 and P2==P3){
            string tmp=P1+P2+A+P3;
            if(tmp.length()>ans.length() or tmp.length()==ans.length() and tmp<ans)
              ans=tmp;
          }
        }
      }
  }
  if(ans=="") cout<<"===>{*}(*)<==="<<endl;
  else cout<<ans<<endl;
}