// 講解：https://tw.saowen.com/a/75296b0c98efbeee8b4efe2ac925548e9e25de5485752aab8f469818d8fd8bf8
夜深人靜系列(7)：https://blog.csdn.net/WhereIsHeroFrom/article/details/78969718
(1) 空間估計：SegmentTree的空間數等於zkw式線段樹，換句話說用 zkw 式的線段樹做空間預估
    假設原始資料的個數是 N ，最少需要 4N 的空間
    準確的估計方式(zkw式空間的計算方法)：
    找到比n大的最小的二次幂再套用等比數列求和公式= (1<<(__lg(N)+1))<<1|1
(2) 建樹與單點更新：
    可以做映射表加速『單點更新』時直接由BottomUp的形式，
    而映射表可以在建樹時找到葉節點後紀錄在陣列中即可
(3) 經典案例：
    1. 區間極值查詢：單點時可搭配映射表實現BottomUp更新
       ZJ-d539
    2. 區間求和：問題出現在『lazy-update』時，文中舉例是先更新(1,4)時只會更新區段(1,3)+(4,4)
                 接著做區間(3,4)的總和查詢，會發現(3,3)這個點的加總值是0而出現錯誤。
                 正確做法是更新該點前先確認 lazy-update 的值是否清空，
                 沒有就把 lazy-update 往下面兩個子結點傳遞以保障該節點是最新的資訊
       ZJ-d799
    3. 區間染色問題：搭配狀態壓縮(題目說明中會提到顏色的總數是多少)
                     區間遞迴合併時採用位元運算(seg[Lson].clr|seg[Rson].clr)

    4. 矩形面積和(所有矩形街平行於X/Y軸)：(參考連結圖片較容易理解)
       核心想法是降維＋掃描線 ＝ 一維以線段樹維護，一維枚舉
       將矩形『拆為』兩條線，並附入邊權值和出邊權值(+1/-1)
       假設掃描線是Y軸，則所有線段依照 X 座標排序後由左而右掃描一次，
       遇到時就根據出入邊的權重把該線段的區段更新到SegmentTree內

       當兩個維度的座標點分布極大時可以分別做離散化
       TIOJ-1224
       UVa-11983 注意PushUp和空間需求

    5. 依序插入數字並詢問該數字是目前區間內第 K 大(此題最佳解是BIT)
       ZJ-d788
       (變形) Dynamic Programming 時查詢比目前數字大的數量和比現在數字小的個數
       ZJ-a596

    6. 實戰問題
       整除問題轉換成餘數加總 => SegmentTree決定怎麼拆成區間，紀錄每個節點的餘數狀態
       需要支援：單點修改＋區間查詢
       ZJ-c265

(4) 搭配技巧：
    1. 離散化
       ZJ-d794

    2. 懶散標記
        ZJ-c259 (解法很巧妙無法直接想出來)

    1+2.離散化＋懶散標記
        UVa-11983 zkw式維護

(5) 函數式的線段樹(主席樹)
    經典例題：ZJ-a331
    一題三解(主席樹/歸併樹/劃分樹)
