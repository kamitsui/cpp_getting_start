# プログラムの処理時間やメモリ使用量を調べる方法

## `/usr/bin/time` command

LinuxやmacOSでプログラムの実行時間や使用メモリ、CPU命令数などを調べることができるツール。

(以下は、macOSにて確認。)

```sh
/usr/bin/time -l -h -p  ./a.out
処理時間: 0.001764 秒
real 0.00
user 0.00
sys 0.00
     1163264  maximum resident set size
           0  average shared memory size
           0  average unshared data size
           0  average unshared stack size
         189  page reclaims
           2  page faults
           0  swaps
           0  block input operations
           0  block output operations
           0  messages sent
           0  messages received
           0  signals received
           0  voluntary context switches
           3  involuntary context switches
    17569648  instructions retired
     5529903  cycles elapsed
     1033088  peak memory footprint
```
> * `1163264 maximum resident set size` : 物理メモリ1.1MB程度
> * 処理時間 : 0.001764 sec
> * `17569648  instructions retired` : CPU命令総数
> * `5529903  cycles elapsed` : CPU クロックサイクル数
> * `1033088  peak memory footprint` : 仮想メモリの最大量を示します（単位はバイト） macOS固有

---

## clock() (\<ctime>ライブラリ) を使った例

[clock.cpp](clock.cpp) を参照

（Ubuntuにて確認）

---

## valgrind の Massif ツールを使った例

```sh
# massif toolの使用、stack領域もヒープとして扱う。
valgrind --tool=massif --pages-as-heap=yes ./a.out
# or 1命令毎にメモリの使用状況を解析する。（データが大きくなるので注意）
valgrind --tool=massif --pages-as-heap=yes --time-unit=i --detailed-freq=1 ./a.out

# トレース結果のプレビュー : メモリ＊命令のXYグラフ、キャプチャ時の命令n番目のメモリ使用状況
ms_print massif.out.XXXX
```
