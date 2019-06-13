/* Manacher's Algorithm( Z algorithm )
 * 記錄每個後綴與原字串的最長共同前綴，時間複雜度跟KMP是一樣的，都是O(n)
 * 精隨在於：記錄比對到的最右界R，及比對到此右界的後綴起點L，並且可以分成三種情況討論：
 * (1) 要比的後綴根本沒被比過 -> 就去比吧
 * (2) 要比的後綴的前面部分已比過但長度未知 -> 繼續比吧
 * (3) 要比的後綴的前面部分已比過且長度已知 -> 直接記錄吧
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXS 500005

char buff[MAXS<<1];
int buff_len;
int ZA[MAXS<<1]={1};

inline void extend(int pivot,int &idx){
  while(pivot-idx>=0 and pivot+idx<buff_len and buff[pivot-idx]==buff[pivot+idx]) idx++;
}
inline void Manacher(char input[],int len){
	// 初始化設定
	buff_len=(len<<1)+1;
	// 產生的字串是原字串的每個字元間嵌入' '
	for(int i=0;i<buff_len;i++)
		buff[i]=(i&1)? input[i>>1]: ' ';
	// 演算法：Manacher
	int pivot=0, maxR=0, max_len=0;
	for(int i=1;i<buff_len;i++){
		/* 精簡寫法：
		DP[i]=(maxR>i)? min(DP[(pivot<<1)-i],maxR-i) : 1;
		while(i-DP[i]>=0 and i+DP[i]<bufferLength and buffer[i-DP[i]]==buffer[i+DP[i]])
			DP[i]++;
		if(i+DP[i]>maxR)
			pivot=i, maxR=i+DP[i];
		*/
		int ii=pivot-(i-pivot); // i的映射位置
		int n=maxR+1-i;
		if(i>maxR){
			ZA[i]=1;
			extend(i,ZA[i]);
			pivot=i, maxR=i+ZA[i]-1;
		}else if(ZA[ii]==n){
			ZA[i]=n;
			extend(i,ZA[i]);
			pivot=i, maxR=i+ZA[i]-1;
		}
		else
			ZA[i]=min(ZA[ii],n);
		// 每次計算完後更新maxlen
		max_len=max(max_len,ZA[i]);
	}
	return max_len-1;
	// 印出最長迴文子字串，記得別印特殊字元。
  for(int i=pivot-ZA[p]+1; i<=pivot+ZA[pivot]-1; i++)
    if(i&1)
      putchar(buff[i]);
}
int main(){
	char input[MAXS];
	int caseT;
	scanf("%d",&caseT);
	while(caseT--)
		scanf("%s",input),
		printf("%d\n",Manacher(input,strlen(input)));
}