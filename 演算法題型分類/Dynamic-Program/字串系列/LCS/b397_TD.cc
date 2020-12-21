// 只用遞迴做的話第3/第4筆測資會TLE
#include<iostream>
#include<set>
using namespace std;

string s1, s2;
char ans[35];
int LCS[35][35]={0};
int dir[35][35][3]={0};
set<string> collect;
void BackTrack(int x,int y,int pos){
  if(pos==-1 and collect.count(ans)==0)  collect.insert(ans);
  if(x<=0 or y<=0 or pos==-1) return;
  for(int i=1;i<=dir[x][y][0];i++)
    if(dir[x][y][i]==1) ans[pos]=s1[x-1], BackTrack(x-1,y-1,pos-1);
    else if(dir[x][y][i]==2) BackTrack(x,y-1,pos);
    else if(dir[x][y][i]==3) BackTrack(x-1,y,pos);
}
int main(){
  int T;

  cin>>T;
  for(int caseNum=1;caseNum<=T;caseNum++){
    cin>>s1>>s2;
    for(int i=0;i<s1.length();i++)
      for(int j=0;j<s2.length();j++){
        if(s1[i]==s2[j])
          LCS[i+1][j+1]=LCS[i][j]+1,
          dir[i+1][j+1][0]=1,
          dir[i+1][j+1][1]=1;
        else{
          if(LCS[i+1][j]>LCS[i][j+1])
            LCS[i+1][j+1]=LCS[i+1][j],
            dir[i+1][j+1][0]=1,
            dir[i+1][j+1][1]=2;
          else if((LCS[i+1][j]<LCS[i][j+1]))
            LCS[i+1][j+1]=LCS[i][j+1],
            dir[i+1][j+1][0]=1,
            dir[i+1][j+1][1]=3;
          else
            LCS[i+1][j+1]=LCS[i][j+1],
            dir[i+1][j+1][0]=2,
            dir[i+1][j+1][1]=2, dir[i+1][j+1][2]=3;
        }
      }
    int len=LCS[s1.length()][s2.length()];
    collect.clear();
    ans[len]='\0';
    BackTrack(s1.length(),s2.length(),len-1);
    cout<<"Case #"<<caseNum<<": "<<collect.size()<<endl;
    for(set<string>::iterator it=collect.begin(); it!=collect.end(); it++)
      cout<<*it<<endl;
  }
}