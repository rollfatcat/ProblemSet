// 比較規則和輸出的格式都複雜許多
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

map<string,int> Table[2];
struct Obj{
  string name;
  int kind, color, level;
} data[40];
int CharToInt(char c){
  if(c<='Z')  return 2*(c-'A');
  return 2*(c-'a')+1;
}
bool compare(Obj a, Obj b){
  if(a.kind!=b.kind)  return a.kind<b.kind;
  if(10<=a.kind and a.kind<=13){ // 『sword』『bow』『bastinado』『targe』只比等級
    if(a.color!=b.color)
      return a.color<b.color;
  } else { // 其餘有顏色的裝備只比顏色, 由第二筆測資中"HPHX"的順序可推測知道等級對於有顏色的裝備無效
    if(a.level!=b.level)
      return a.level<b.level;
  }
  if(a.name.length() !=b.name.length())return a.name.length()<b.name.length();
  for(int i=0;i<a.name.length();i++)
    if(a.name[i]!=b.name[i])
      return CharToInt(a.name[i])<CharToInt(b.name[i]);
  return 0;
}

int main(){
  Table[0]["hat"]=00,     Table[0]["earring"]=01,
  Table[0]["sword"]=10,   Table[0]["bow"]=11,     Table[0]["bastinado"]=12, Table[0]["targe"]=13, Table[0]["glove"]=14;
  Table[0]["clothes"]=20, Table[0]["cape"]=21,
  Table[0]["pant"]=30,    Table[0]["skirt"]=31;
  Table[0]["shoe"]=40;

  Table[1]["W"]=0,  Table[1]["P"]=1,  Table[1]["B"]=2,  Table[1]["R"]=3,  Table[1]["Y"]=4,  Table[1]["G"]=5,  Table[1]["K"]=6,  Table[1]["U"]=-1;

  int caseNum, N;
  string kind, color;
  cin>>caseNum;
  while(caseNum--){
    cin>>N;
    for(int i=0;i<N;i++)
      cin>>data[i].name>>kind>>color>>data[i].level,
      data[i].kind=Table[0][kind],  data[i].color=Table[1][color];
    sort(data,data+N,compare);
    int space[4]={0,3,2,1};
    int k=data[0].kind/10, idxC, idxN;
    for(idxN=0, idxC=0; idxN<N; )
      if(data[idxN].kind/10==k){
        for(int j=0, n=0;j<data[idxN].name.length() and n<2;j++)
          if(data[idxN].name[j]<='Z')
            cout<<data[idxN].name[j],  n++;
        if(idxC%4==3) cout<<endl;
        idxN++, idxC++;
      }
      else{
        k=data[idxN].kind/10;
        for(int j=0;j<space[idxC%4];j++)
          cout<<"__";
        cout<<endl;
        idxC+=space[idxC%4];
      }
    if(idxC>0){
      for(int j=0;j<space[idxC%4];j++)
        cout<<"__";
      cout<<endl;
    }
    cout<<"--------"<<endl;
  }
}