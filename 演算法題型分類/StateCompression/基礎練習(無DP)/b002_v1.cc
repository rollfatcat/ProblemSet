// 關燈的狀態壓縮版本
// Non-Cut-Branch:每展開一次就記錄最小次數，展開過程中超過最少次數時即可break
#include<iostream>
using namespace std;

const int bit_mask=(1<<11)-2;
const int INF=1<<30;
struct data_map{
  int status[12]={};
  int MatchPre(int row,int cnt){
    for(int preR=row-1,onS; status[preR]; status[preR]^=onS){
      cnt++;
      onS=status[preR]&(-status[preR]);
      int on_pos=__lg(onS);
      status[row]^=(7<<(on_pos-1)),
      status[row+1]^=(1<<on_pos);
    }
    status[row]&=bit_mask;
    if(row==10) return (status[10])?INF:cnt;
    return MatchPre(row+1,cnt);
  }
  // 枚舉 1st Row 開關的全部組合
  int TryRow(int col,int cnt){
    // 複製現在的物件，改動狀態時變更複製的物件
    data_map copy_one=*this;
    // 模擬 col-st 開關按下去，複製物件的狀態改變且 用bit_mask濾除最左/右邊的bit變回0
    copy_one.status[1]^=(7<<(col-1)),
    copy_one.status[2]^=(1<<col);
    copy_one.status[1]&=bit_mask;
    // 當col到底時就往下個Row遞迴，根據上一層Row的狀態把值燈的狀態
    if(col==10) return min(MatchPre(2,cnt),copy_one.MatchPre(2,cnt+1));
    else  return min(TryRow(col+1,cnt),copy_one.TryRow(col+1,cnt+1));
  }
};
int main(){
  int T;
  char ch;
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(cin>>T;T--;){
    data_map org;
    for(int i=1;i<=10;i++)
      for(int j=1;j<=10;j++)
        cin>>ch, org.status[i]+=((ch=='O')<<j);
    cout<<org.TryRow(1,0)<<'\n';
  }
}