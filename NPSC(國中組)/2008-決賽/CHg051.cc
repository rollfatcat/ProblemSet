// 複雜的模擬題(世界難寫,超浪費時間)
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;

int cp[2][2];
struct Card{
  int num, kind;
  bool operator<(const Card &other)const{
    return(num==other.num)?(kind<other.kind):(num<other.num); }
}cards[10];
int Level(int base);
int main(){
  int caseNum;
  string ss;

  map<char,int> ToCard;
  ToCard['C']=0,  ToCard['D']=1,  ToCard['H']=2,  ToCard['S']=3;
  ToCard['T']=10, ToCard['J']=11, ToCard['Q']=12, ToCard['K']=13, ToCard['A']=14;

  cin>>caseNum;
  while(caseNum--){
    for(int i=0;i<5;i++)
      cin>>ss,
      cards[i].num=(ss[0]<='9')?(ss[0]-'0'):ToCard[ss[0]],
      cards[i].kind=ToCard[ss[1]];
    sort(cards,cards+5);
    for(int i=5;i<10;i++)
      cin>>ss,
      cards[i].num=(ss[0]<='9')?(ss[0]-'0'):ToCard[ss[0]],
      cards[i].kind=ToCard[ss[1]];
    sort(cards+5,cards+10);
    if(Level(0)>Level(1))       cout<<"Win"<<endl;
    else if(Level(0)<Level(1))  cout<<"Lose"<<endl;
    else{
      if(Level(0)==8 or Level(0)==4) // 同花順/順子要注意 A2345 => 比最大的牌即可
        cout<<((cards[4].num>cards[9].num)?"Win":"Lose")<<endl;
      else if(Level(0)==7 or Level(0)==6 or Level(0)==3) // 四條/葫蘆/三條 => 只比關鍵牌
        cout<<((cp[0][0]>cp[1][0])?"Win":"Lose")<<endl;
      else if(Level(0)==2){ // 二對子 => 對子一樣時不需要特別挑出對子比
        if((cp[0][0]==cp[1][0])){
          if((cp[0][1]==cp[1][1])){
            int idx;
            for(idx=4;idx>=0 and cards[idx].num==cards[idx+5].num;idx--);
            cout<<((cards[idx].num>cards[idx+5].num)?"Win":"Lose")<<endl;
          } else
            cout<<((cp[0][1]>cp[1][1])?"Win":"Lose")<<endl;
        } else
          cout<<((cp[0][0]>cp[1][0])?"Win":"Lose")<<endl;
      }
      else if(Level(0)==1){ // 單對子, 對子一樣時不需要特別挑出對子比
        if((cp[0][0]==cp[1][0])){
          int idx;
          for(idx=4;idx>=0 and cards[idx].num==cards[idx+5].num;idx--);
          cout<<((cards[idx].num>cards[idx+5].num)?"Win":"Lose")<<endl;
        }
        else
          cout<<((cp[0][0]>cp[1][0])?"Win":"Lose")<<endl;
      }
      else{  // 單張/同花的判斷方式相同, 只比點數不管花色
        int idx;
        for(idx=4;idx>=0 and cards[idx].num==cards[idx+5].num;idx--);
        cout<<((cards[idx].num>cards[idx+5].num)?"Win":"Lose")<<endl;
      }
    }
  }
}
int Level(int player){
  int kind[4],  num[15], base=(player==1)?5:0;
  memset(kind,0,sizeof(kind));
  memset(num,0,sizeof(num));
  // 一邊判斷順子, 一邊算每種花色和每種數字的數量
  bool ContiCards=true;
  num[cards[base+0].num]++,  kind[cards[base+0].kind]++;
  for(int i=base+1;i<base+5;i++){
    num[cards[i].num]++,  kind[cards[i].kind]++;
    if((cards[i-1].num+1)!=cards[i].num)
      ContiCards=false;
  }
  if(cards[base+0].num==2 and cards[base+1].num==3 and cards[base+2].num==4 and cards[base+3].num==5 and cards[base+4].num==14){
    ContiCards=true,  cards[base+4].num=1,  sort(cards+base,cards+5+base);
  };
  // 判斷同花
  int SameKind=0;
  for(int i=0;i<=3;i++)
    if(kind[i]>SameKind)
      SameKind=kind[i];
  SameKind=(SameKind==5);

  if(SameKind==1 and ContiCards==1) return 8;
  else if(ContiCards==1) return 4;
  else if(SameKind==1) return 5;

  int NumCnt[5]={0,0,0,0,0};
  for(int i=2;i<=14;i++)
    NumCnt[num[i]]++;
  if(NumCnt[4]==1){
    for(int i=2;i<=14;i++)
      if(num[i]==4)
        cp[player][0]=i;
    return 7;
  } else if(NumCnt[3]==1) {
    for(int i=2;i<=14;i++)
      if(num[i]==3)
        cp[player][0]=i;
    return (NumCnt[2]==1)?6:3;
  }
  int k=0;
  for(int i=14;i>=2;i--)
    if(num[i]==2)
      cp[player][k++]=i;
  return NumCnt[2]; // 2 1 0 由對子的數量決定
}