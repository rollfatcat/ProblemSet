// 不知道整張地圖的大小,所以得用 vector<string>map
// 走過的字元改成'.', DFS展開時需要檢查字元有沒有一樣
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int r, c;
vector<string> map;
struct Data{ char ch; int cnt;
  bool operator<(const Data &other)const{ return(cnt==other.cnt)?(ch<other.ch):(cnt>other.cnt); }
} Book[26];

void DFS(int x, int y, char target){
  if(x<0 or x>=r or y<0 or y>= c or map[x][y]!=target)
    return;
  map[x][y]=' ';
  DFS(x-1,y,target);
  DFS(x+1,y,target);
  DFS(x,y-1,target);
  DFS(x,y+1,target);
}
int main(){
  int T;
  string ss;

  cin>>T;
  for(int caseNum=1;caseNum<=T;caseNum++){
    cin>>r>>c;
    map.clear();
    for(int i=0;i<26;i++)
      Book[i]={(char)('a'+i),0};
    for(int i=0;i<r;i++)
      cin>>ss,  map.push_back(ss);
    for(int i=0;i<r;i++)
      for(int j=0;j<c;j++)
        if(map[i][j]>='a')
          Book[ map[i][j]-'a' ].cnt++,
          DFS(i,j,map[i][j]);
    sort(Book,Book+26);
    cout<<"World #"<<caseNum<<endl;
    for(int i=0;i<26;i++)
      if(Book[i].cnt>0)
        cout<<Book[i].ch<<": "<<Book[i].cnt<<endl;
  }
}