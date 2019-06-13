// 多組測資的意思其實是指名字查詢會出現多次但成績排名輸入只會出現一次
// 練習寫map(簡單應用)
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;

struct Student{ string name; vector<int>grade; } s[100];
bool cmp(int a, int b){ return  a>b; }
bool compare(Student a, Student b){
  int minN=min(a.grade.size(),b.grade.size());
  for(int i=0;i<minN;i++)
    if(a.grade[i]!=b.grade[i])
      return a.grade[i]>b.grade[i];
  return a.grade.size()>b.grade.size();
}
bool isEqual(Student &a,Student &b){
  if(a.grade.size()!=b.grade.size())  return false;
  for(int i=0;i<a.grade.size();i++)
    if(a.grade[i]!=b.grade[i])
      return false;
  return true;
}
int main(){
  int N, K, x;

  cin>>N;
  for(int i=0;i<N;i++){
    cin>>s[i].name>>K;
    s[i].grade.clear();
    for(int j=0;j<K;j++)
      cin>>x, s[i].grade.push_back(x);
    sort(s[i].grade.begin(),s[i].grade.end(),cmp);
  }
  sort(s,s+N,compare);
  int No[N];  No[0]=1;
  for(int i=1;i<N;i++)
    if(isEqual(s[i],s[i-1]))  No[i]=No[i-1];
    else  No[i]=No[i-1]+1;
  map<string,int> mapStudent;
  for(int i=0;i<N;i++)
    mapStudent[s[i].name]=No[i];
  for(char ss[25];scanf("%s",ss)==1;)
    cout<<mapStudent[ss]<<endl;
}