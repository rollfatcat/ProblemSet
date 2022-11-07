/* 題解：https://home.gamer.com.tw/creationDetail.php?sn=4338361
 * 觀察數列中每個數字翻轉 180 度後，仍是同樣的數字。
 * 三位數是由兩位數剖半，中間加上「0」、「1」或是「8」。
 * 即 101、111、181、609、619、689、808、818、888、906、916、986。
 * 四位數也是由兩位數剖半，中間加上「00」、「11」、「69」、「88」、「96」。
 * 即 1001、1111、1691、1881、1961、6009、……
 * 而同理，五位數為四位數剖半，中間加上「0」、「1」或是「8」；
 * 六位數為四位數剖半，中間加上「00」、「11」、「69」、「88」、「96」。
 * 遞迴推導前1000000項
 */
#include<bits/stdc++.h>
using namespace std;

vector<string> sequence(1000006);
int main(){
  sequence[0]="00";
  sequence[1]="0";
  sequence[2]="1";
  sequence[3]="8";
  sequence[4]="11";
  sequence[5]="69";
  sequence[6]="88";
  sequence[7]="96";
  int preL=4, preR=7, nowL, cnt=7;
  for(int L=3;cnt<=1000000;L++){
    if(L&1)
      for(int i=preL; i<=preR and cnt<=1000000; i++)
				sequence[++cnt]=sequence[i].substr(0,sequence[i].size()>>1)+"0"+sequence[i].substr(sequence[i].size()>>1),
				sequence[++cnt]=sequence[i].substr(0,sequence[i].size()>>1)+"1"+sequence[i].substr(sequence[i].size()>>1),
				sequence[++cnt]=sequence[i].substr(0,sequence[i].size()>>1)+"8"+sequence[i].substr(sequence[i].size()>>1);
    else{ // 當現在長度是偶數時要紀錄現在產生的字串範圍
      nowL=cnt+1;
      for(int i=preL; i<=preR and cnt<=1000000; i++)
				sequence[++cnt]=sequence[i].substr(0,sequence[i].size()>>1)+"00"+sequence[i].substr(sequence[i].size()>>1),
				sequence[++cnt]=sequence[i].substr(0,sequence[i].size()>>1)+"11"+sequence[i].substr(sequence[i].size()>>1),
				sequence[++cnt]=sequence[i].substr(0,sequence[i].size()>>1)+"69"+sequence[i].substr(sequence[i].size()>>1),
				sequence[++cnt]=sequence[i].substr(0,sequence[i].size()>>1)+"88"+sequence[i].substr(sequence[i].size()>>1),
        sequence[++cnt]=sequence[i].substr(0,sequence[i].size()>>1)+"96"+sequence[i].substr(sequence[i].size()>>1);
      preL=nowL, preR=cnt;
    }
  }

  // Main
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(int N; cin>>N and N;)
    cout<<sequence[N]<<endl;
}