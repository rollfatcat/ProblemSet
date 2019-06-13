#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 51

struct Node{char v, fr;};
int main(){
  Node map[MaxN][MaxN];
  char bag[MaxN];
  string s1, s2;

  while(cin>>s1>>s2){
    memset(map,0,sizeof(map));
    for(int i=1;i<=s1.length();i++)
      for(int j=1;j<=s2.length();j++)
        if(s1[i-1]==s2[j-1])
          map[i][j].v=map[i-1][j-1].v+1, map[i][j].fr=0;
        else{
          if(map[i-1][j].v>map[i][j-1].v)
            map[i][j].v=map[i-1][j].v, map[i][j].fr=1;
          else
            map[i][j].v=map[i][j-1].v, map[i][j].fr=2;
        }

    int l=map[s1.length()][s2.length()].v;
    int i=s1.length(),  j=s2.length();
    for(bag[l--]='\0';l>=0;)
      if(map[i][j].fr==1) i--;
      else if(map[i][j].fr==2)  j--;
      else bag[l--]=s1[i-1], i--, j--;

    if(map[s1.length()][s2.length()].v==0)  cout<<"E\n";
    else  cout<<bag<<endl;
  }
}