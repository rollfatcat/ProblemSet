// Greedy
/* 網址：http://www3.tcgs.tc.edu.tw/npsc/index.php?topic=318.0
對於每一集動畫所在的硬碟，有以下幾種情形：
1.如果該硬碟已經插在USB上，則不需要插入或拔走任何硬碟。
2.如果該硬碟沒有插上去，而且有空的USB接頭，就把它接上去。
3.如果該硬碟沒有插上去，而且全部的USB接頭都有接硬碟的話，則比較每一顆在USB上的硬碟下一次要看的影片的順序，找最後一個才需要看的，把它換成接下來要看的這一顆，並把次數加1。
第1種情形，可以用一個陣列來記錄每一個硬碟是不是在使用中，這樣就可以做到O(1)，
至於第2、3種情形，則可以用一些樹狀的資料結構來加速，可以做到O(lgN)，下面的程式碼則是沒有使用資料結構的，搭配優化輸入可以在1秒內跑完。
*/
#include<iostream>
using namespace std;

#define MaxUSBNum 100
#define MaxDiskNum 10001
#define MaxEpNum 1000000


struct Episode { int disk, next; } E[MaxEpNum];
struct USB { int disk, used, next; } U[100];
int USBno[MaxDiskNum];

int T,N,M;
int main(){
  cin>>T;
  while(T--){
    cin>>N>>M;
    fill(USBno,USBno+MaxDiskNum,-1);
    for(int i=0;i<N;i++){
      cin>>E[i].disk;
      E[i].next=MaxEpNum;
      if(USBno[E[i].disk]>=0)
        E[ USBno[E[i].disk] ].next=i;
      USBno[E[i].disk]=i;
    }
    fill(USBno,USBno+MaxDiskNum,-1);
    for(int i=0;i<M;i++)
      U[i].disk=-1, U[i].used=0;
    int empty_usb[100], empty_usbLen=0;
    for(int i=1;i<=M;i++)
      empty_usb[empty_usbLen++]=M-i;

    int times=0;
    for(int i=0;i<N;i++){
      int now_disk=E[i].disk;
      if( USBno[now_disk]>=0 )  // 硬碟已經插上則更新下一次會用到的時候
        U[ USBno[now_disk] ].next=E[i].next;
      else{   // 硬碟沒有插上就考慮 (2)有空著的USB (3)都插好插滿了
        int targetUSB=-1;
        // 有USB還是空著的
        if(empty_usbLen>0){
          targetUSB=empty_usb[--empty_usbLen];
          U[targetUSB].disk=now_disk;
          U[targetUSB].used=1;
          U[targetUSB].next=E[i].next;
          USBno[now_disk]=targetUSB;
        } else{ // 有USB都插著硬碟則比較每一顆在USB上的硬碟下一次要看的影片的順序，找最後一個才需要看的，把它換成接下來要看的這一顆
          for(int j=0, tmp_next=-1;j<M;j++)
            if(tmp_next<U[j].next){
              tmp_next=U[j].next;
              targetUSB=j;
            }
          USBno[ U[targetUSB].disk ]=-1;
          U[targetUSB].disk=now_disk;
          U[targetUSB].next=E[i].next;
          USBno[now_disk]=targetUSB;
          times++;
        }
      }
    }
    cout<<times<<endl;
  }
}