// 邏輯推理題
#include<stdio.h>
#include<stdlib.h>
int main(){
  puts("     House     Color    Nation     Drink Cigarette       Pet");
  puts("        H1         4         9        15        20        23");
  puts("        H2         5         8        11        17        24");
  puts("        H3         1         6        13        16        22");
  puts("        H4         2        10        12        19        25");
  puts("        H5         3         7        14        18        21");
}
/////////
   以下是推理過程：
   根據 8. 中間那棟房子(第3棟)的主人喝牛奶。
        9. 挪威人住在第1棟房子。
       14. 挪威人住在藍色房子的隔壁。
=> 此時的表格狀態：
House     Color    Nation     Drink Cigarette       Pet
   H1  <填數字>  (9)挪威人 <填數字>  <填數字>  <填數字>
   H2   (5)藍色  <填數字>  <填數字>  <填數字>  <填數字>
   H3  <填數字>  <填數字>  (13)牛奶  <填數字>  <填數字>
   H4  <填數字>  <填數字>  <填數字>  <填數字>  <填數字>
   H5  <填數字>  <填數字>  <填數字>  <填數字>  <填數字>


   這時根據 4. 綠色房子在白色房子的左邊。
            5. 綠色房子的主人喝咖啡。
   可以發現(綠,白)=(H3,H4) or (H4,H5)
   搭配 1. 英國人住在紅色的房子。
=> 得到結論：H1一定是黃色。
   這時根據 7. 黃色房子的主人抽七星香菸。
           11.養馬的人住在抽七星香菸的人的隔壁。
=> 此時的表格狀態：
House     Color    Nation     Drink Cigarette       Pet
   H1   (4)黃色  (9)挪威人 <填數字>  (20)七星  <填數字>
   H2   (5)藍色  <填數字>  <填數字>  <填數字>    (24)馬
   H3  <填數字>  <填數字>  (13)牛奶  <填數字>  <填數字>
   H4  <填數字>  <填數字>  <填數字>  <填數字>  <填數字>
   H5  <填數字>  <填數字>  <填數字>  <填數字>  <填數字>


   這時根據 4. 綠色房子在白色房子的左邊。
            5. 綠色房子的主人喝咖啡。
=> 得到結論：因為H3的人喝牛奶，H4一定是綠色(這房子的主人會喝咖啡)。
   這時根據 1. 英國人住在紅色的房子。
=> 此時的表格狀態：
House     Color    Nation     Drink Cigarette       Pet
   H1   (4)黃色  (9)挪威人 <填數字>  (20)七星  <填數字>
   H2   (5)藍色  <填數字>  <填數字>  <填數字>    (24)馬
   H3   (1)紅色  (6)英國人 (13)牛奶  <填數字>  <填數字>
   H4   (2)綠色  <填數字>  (12)咖啡  <填數字>  <填數字>
   H5   (3)白色  <填數字>  <填數字>  <填數字>  <填數字>


   這時根據 2. 瑞典人養狗。
=> 得到結論：  瑞典人只可能是 H4 or H5(正解)
   分兩個情況討論(A)瑞典人是 H5，從61行開始
                 (B)瑞典人是 H4，從90行開始
=> 收斂在105行，不管上述兩種選擇，都可以得到 H2 = 3. 丹麥人喝茶。

   (A)瑞典人是 H5(正解)
House     Color    Nation     Drink Cigarette       Pet
   H1   (4)黃色  (9)挪威人 <填數字>  (20)七星  <填數字>
   H2   (5)藍色  <填數字>  <填數字>  <填數字>    (24)馬
   H3   (1)紅色  (6)英國人 (13)牛奶  <填數字>  <填數字>
   H4   (2)綠色  <填數字>  (12)咖啡  <填數字>  <填數字>
   H5   (3)白色  (7)瑞典人 <填數字>  <填數字>    (21)狗

   這時根據 3. 丹麥人喝茶。
           13. 德國人抽Dunhill香菸。
           15. 抽長壽香菸的人有一個喝水的鄰居。
=> 此時的表格狀態：
House     Color    Nation     Drink Cigarette       Pet
   H1   (4)黃色  (9)挪威人 (15)  水  (20)七星  <填數字>
   H2   (5)藍色  (8)丹麥人 (11)  茶  (17)長壽    (24)馬
   H3   (1)紅色  (6)英國人 (13)牛奶  <填數字>  <填數字>
   H4   (2)綠色 (10)德國人 (12)咖啡  (19)Dunh  <填數字>
   H5   (3)白色  (7)瑞典人 (14)啤酒  <填數字>    (21)狗

   這時根據 6. 抽寶馬香菸的人養鳥
           其他填空補滿即可結束
=> 此時的表格狀態：
House     Color    Nation     Drink Cigarette       Pet
   H1   (4)黃色  (9)挪威人 (15)  水  (20)七星    (23)貓
   H2   (5)藍色  (8)丹麥人 (11)  茶  (17)長壽    (24)馬
   H3   (1)紅色  (6)英國人 (13)牛奶  (16)寶馬    (22)鳥
   H4   (2)綠色 (10)德國人 (12)咖啡  (19)Dunh    (25)魚
   H5   (3)白色  (7)瑞典人 (14)啤酒  (18)萬寶    (21)狗

   (B)瑞典人是 H4
=> 此時的表格狀態：
House     Color    Nation     Drink Cigarette       Pet
   H1   (4)黃色  (9)挪威人 <填數字>  (20)七星  <填數字>
   H2   (5)藍色  <填數字>  <填數字>  <填數字>    (24)馬
   H3   (1)紅色  (6)英國人 (13)牛奶  <填數字>  <填數字>
   H4   (2)綠色  (7)瑞典人 (12)咖啡  <填數字>    (21)狗
   H5   (3)白色  <填數字>  <填數字>  <填數字>  <填數字>

   這時根據10.抽長壽香菸的人住在養貓的人的隔壁。
=> 只有H2和H4可能是長壽菸
=> (2)是答案就不討論，討論選擇(4)時水是H5
=> 這時根據 3. 丹麥人喝茶。也是屬於H2

=> 此時的表格狀態：
House     Color    Nation     Drink Cigarette       Pet
   H1   (4)黃色  (9)挪威人 <填數字>  (20)七星  <填數字>
   H2   (5)藍色  (8)丹麥人 (11)  茶  <填數字>    (24)馬
   H3   (1)紅色  (6)英國人 (13)牛奶  <填數字>  <填數字>
   H4   (2)綠色  <填數字>  (12)咖啡  <填數字>  <填數字>
   H5   (3)白色  <填數字>  <填數字>  <填數字>  <填數字>

   這時根據12.抽萬寶路香菸的人喝啤酒。
=> 此時的表格狀態：
House     Color    Nation     Drink Cigarette       Pet
   H1   (4)黃色  (9)挪威人 <填數字>  (20)七星  <填數字>
   H2   (5)藍色  (8)丹麥人 (11)  茶  <填數字>    (24)馬
   H3   (1)紅色  (6)英國人 (13)牛奶  <填數字>  <填數字>
   H4   (2)綠色  <填數字>  (12)咖啡  <填數字>  <填數字>
   H5   (3)白色  <填數字>  (14)啤酒  (18)萬寶  <填數字>

   這時根據13.德國人抽Dunhill香菸。
            2. 瑞典人養狗。
=> 此時的表格狀態：
House     Color    Nation     Drink Cigarette       Pet
   H1   (4)黃色  (9)挪威人 <填數字>  (20)七星  <填數字>
   H2   (5)藍色  (8)丹麥人 (11)  茶  <填數字>    (24)馬
   H3   (1)紅色  (6)英國人 (13)牛奶  <填數字>  <填數字>
   H4   (2)綠色 (10)德國人 (12)咖啡  (19)Dunh  <填數字>
   H5   (3)白色  (7)瑞典人 (14)啤酒  (18)萬寶    (21)狗

   這時根據15.抽長壽香菸的人有一個喝水的鄰居。
            6. 抽寶馬香菸的人養鳥。
            其他填空補滿即可結束，結果在82行
=> 此時的表格狀態：
House     Color    Nation     Drink Cigarette       Pet
   H1   (4)黃色  (9)挪威人 (15)  水  (20)七星  <填數字>
   H2   (5)藍色  (8)丹麥人 (11)  茶  (17)長壽    (24)馬
   H3   (1)紅色  (6)英國人 (13)牛奶  (16)寶馬    (22)鳥
   H4   (2)綠色 (10)德國人 (12)咖啡  (19)Dunh  <填數字>
   H5   (3)白色  (7)瑞典人 (14)啤酒  (18)萬寶    (21)狗