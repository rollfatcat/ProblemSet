// d105的加強版本，
// (X)快速幂次方解(這次的結果只和前一次的狀態相關) => 狀態轉移陣列的大小會是10^6*10^6個(過大)
// (?)帕斯卡三角形解法

1
1 1
1 2  1
1 3  3  1
1 4  6  4  1
1 5 10 10  5 1
1 6 15 20 15 6 1

 1  0  0
 1  1  0
 1  2  1
 2  3  3
 5  5  6
11 10 11
22 21 21

 1  0  0  0  0  0
 0  1  0  0  0  1
 2  0  1  0  1  0
 0  3  0  2  0  3
 6  0  5  0  5  0
 0 11  0 10  0 11
22  0 21  0 21  0

1 0  0  0  0
1 1  0  0  0
1 2  1  0  0
1 3  3  1  0
1 4  6  4  1
2 5 10 10  5
7 7 15 20 15

 1  0  0  0  0  0  0  0  0
 0  1  0  0  0  0  0  0  1
 2  0  1  0  0  0  0  1  0
 0  3  0  1  0  0  1  0  3
 6  0  4  0  1  1  0  4  0
 0 10  0  5  1  1  5  0 10
20  0 15  1  6  6  1 15  0