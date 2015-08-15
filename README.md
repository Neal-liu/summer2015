# summer2015
[ Homework 2 ]:

在 Intel x86 架構執行跑本週 Quiz 題目 (見下方 cache)，撰寫必要的 benchmark 系統，找出效能最佳化的策略並且實做出來。注意：我們最在意能否快速找到電話簿裡面指定的 Last name
- Cache(bit) : 32*1024 (32K)
  - 32*1024 / (16*8) = 256(只能存256筆)
  - 可以最佳化成 32*1024  / 32 = 1024 筆 (hash function)
   -可以假設 boundary 是2億，去想如何處理 PHONE_BOOK
- Pentium 4: 512K
- [Optimizing Program Performance] (http://csapp.cs.cmu.edu/2e/ch5-preview.pdf) [CSAPP ch5] 

Hint : Cache Miss
