#import "@preview/codly:1.3.0": *
#import "@preview/codly-languages:0.1.10": *
#import "@preview/numbly:0.1.0": *

#let fonts = (
    main: "IBM Plex Serif",
    mono: "JetBrains Mono",
    cjk: "Noto Serif CJK SC",
    emph-cjk: "Noto Serif CJK SC",
    math: "New Computer Modern Math",
    math-cjk: "Noto Serif CJK SC",
)

#set text(
    font: (fonts.main, fonts.mono, fonts.cjk, fonts.emph-cjk, fonts.math, fonts.math-cjk),
    size: 11pt,
    lang: "zh",
    region: "cn",
)
#set page(paper: "a4", margin: 20pt)
#set heading(numbering: numbly("", "{2:1}. ", "{3:I}. ", "{4:A}. "))
#show heading.where(level: 1): set align(center)
#show heading: set block(spacing: .4em)
#show raw: set text(font: (fonts.mono, fonts.cjk))
#show raw.where(block: false): box.with(
    fill: luma(240),
    inset: (x: .3em, y: 0em),
    outset: (x: 0em, y: .3em),
    radius: .2em,
)
#show: codly-init
#codly(
    languages: codly-languages,
    zebra-fill: none,
    fill: luma(90.2%),
    stroke: .5pt + rgb("bfbfbf"),
    radius: 8pt,
)
#{
    set page(numbering: "I")
    columns(2, gutter: 1em, {
        set outline.entry(fill: repeat(gap: 0.15em, move(dy: -0.25em)[.]))
        outline(title: none)
    })
    pagebreak()
}
#counter(page).update(1)
#set page(footer: context align(center, counter(page).display("1 / 1", both: true)))

#let (ll, rr) = (
    sym.lt.eq.slant,
    sym.gt.eq.slant,
)
#let (dr, dp, mex) = ("dr", "dp", "mex").map(name => math.op(name))
#let complexity(..bodies) = codly(
    header: math.equation(block: true, eval(
        mode: "math",
        bodies.pos().map(body => "Omicron(" + body + ")").join(", "),
    )),
    header-cell-args: (
        fill: luma(96%),
        inset: (x: 0.65em, y: 0.45em),
        stroke: (bottom: 0.5pt + rgb("bfbfbf")),
    ),
)
#let code-block(path, lang: "cpp") = raw(read(path), block: true, lang: lang)

= Basic
== IO
=== Fast Read
#code-block("code/01-basic/fast-read.cpp")
=== Fread Buffer
#code-block("code/01-basic/fread-buffer.cpp")
== 排序与离散化
=== Quick Sort
#complexity("n log n")
#code-block("code/01-basic/quick-sort.cpp")
=== Merge Sort Inversion
#complexity("n log n")
#code-block("code/01-basic/merge-sort-inversion.cpp")
=== Coordinate Compression
#complexity("n log n")
#code-block("code/01-basic/coordinate-compress.cpp")
== 位运算
=== Brian Kernighan
#complexity("k")
#code-block("code/01-basic/brian-kernighan.cpp")
=== Subset Enumeration
#complexity("3^n")
#code-block("code/01-basic/subset-enumeration.cpp")
== Search
=== Binary Search
#complexity("log V")
#code-block("code/01-basic/binary-search.cpp")
=== Ternary Search
单峰最大值；最小值反向比较。
#code-block("code/01-basic/ternary-search.cpp")

= 数据结构
== DSU
#complexity("alpha(n)")
#code-block("code/02-data-structure/dsu.cpp")
== Fenwick Tree
单点加、区间和；```cpp kth(k)``` 查最小前缀使和 $rr k$。
#complexity("log n")
#code-block("code/02-data-structure/fenwick.cpp")
== Segment Tree
区间加、区间和；`1` base。
#complexity("n", "log n")
#code-block("code/02-data-structure/segment-tree.cpp")
== Sparse Table
幂等律信息。
#complexity("n log n", "1")
#code-block("code/02-data-structure/sparse-table.cpp")
== Monotonic Queue
定长滑动窗口最小值。
#complexity("n")
#code-block("code/02-data-structure/monotonic-queue.cpp")
== Monotonic Stack
#complexity("n")
#code-block("code/02-data-structure/monotonic-stack.cpp")

= DP
== LIS
严格递增用 `lower_bound`，非降序用 `upper_bound`。
#complexity("n log n")
#code-block("code/03-dp/lis.cpp")
== LCS
#complexity("n m")
#code-block("code/03-dp/lcs.cpp")
== 01 Knapsack
每件至多选一次，容量倒序。
#complexity("n W")
#code-block("code/03-dp/01-knapsack.cpp")
== Complete Knapsack
每件可选无限次，容量正序。
#complexity("n W")
#code-block("code/03-dp/complete-knapsack.cpp")
== Multiple Knapsack
=== Binary Splitting
#complexity("W sum_(i = 1)^n log m_i")
#code-block("code/03-dp/multiple-knapsack-binary.cpp")
=== Monotonic Queue
#complexity("n W")
#code-block("code/03-dp/multiple-knapsack-monotonic-queue.cpp")
== Group Knapsack
每组最多选一件。
#complexity("W sum_i G_i")
#code-block("code/03-dp/group-knapsack.cpp")
== Huge Knapsack
容量大、物品少时折半枚举。
#complexity("n 2^(n / 2)")
#code-block("code/03-dp/huge-knapsack-meet-in-middle.cpp")
== Digit DP
统计 $[0, n]$ 中数位和模 `mod` 为 `0` 的数。
#complexity("D S")
#code-block("code/03-dp/digit-dp.cpp")
== SOS DP
高维前缀和；`subsetZeta` 后 $ f[S] = sum_(T subset.eq S) f[T] $
#complexity("n 2^n")
#code-block("code/03-dp/sos-dp.cpp")

= String
== KMP
#complexity("n + m")
#code-block("code/04-string/kmp.cpp")
== Z Function
#complexity("n")
#code-block("code/04-string/z-function.cpp")
== Manacher
奇回文半径 `d1` 与偶回文半径 `d2`。
#complexity("n")
#code-block("code/04-string/manacher.cpp")
== String Hash
`get(l, r)` 为 `1` base闭区间。
#complexity("n", "1")
#code-block("code/04-string/string-hash.cpp")
== Trie
#complexity("sum_i L_i")
#code-block("code/04-string/trie.cpp")
== Aho-Corasick
统计文本中出现的模式串总次数。
#complexity("sum_i L_i + T")
#code-block("code/04-string/aho-corasick.cpp")
== Suffix Array
`height[i]` 为 `sa[i - 1]` 与 `sa[i]` 的 LCP。
#complexity("n log n")
#code-block("code/04-string/suffix-array.cpp")
== Suffix Automaton
小写字母；不同子串数为 $ sum_(i gt 0) "len"[i] - "len"["link"[i]] $
#complexity("n")
#code-block("code/04-string/suffix-automaton.cpp")

= Graph
== 遍历
=== DFS
#complexity("V + E")
#code-block("code/05-graph/dfs.cpp")
=== BFS
#complexity("V + E")
#code-block("code/05-graph/bfs.cpp")
== Topological Sort
返回空数组表示有环。
#complexity("V + E")
#code-block("code/05-graph/topological-sort.cpp")
== MST
=== Kruskal
断开图返回 `-1`。
#complexity("E log E")
#code-block("code/05-graph/kruskal.cpp")
== Shortest Path
=== Dijkstra
非负边权。
#complexity("(V + E) log V")
#code-block("code/05-graph/dijkstra.cpp")
=== 0-1 BFS
边权仅为 `0` 或 `1`。
#complexity("V + E")
#code-block("code/05-graph/zero-one-bfs.cpp")
=== Bellman-Ford
返回 `false` 表示存在从源点可达的负环。
#complexity("V E")
#code-block("code/05-graph/bellman-ford.cpp")
=== SPFA
返回 `false` 表示存在从源点可达的负环。
#complexity("k E")
#code-block("code/05-graph/spfa.cpp")
=== Floyd-Warshall
小规模全源最短路。
#complexity("V^3")
#code-block("code/05-graph/floyd-warshall.cpp")
== Difference Constraints
约束 $x_v ll x_u + w$；无解返回 `false`。
#complexity("k E")
#code-block("code/05-graph/difference-constraints.cpp")
== 连通性
=== Tarjan SCC
#complexity("V + E")
#code-block("code/05-graph/tarjan-scc.cpp")
=== 2-SAT
变量从 `0` 开始；`addOr(x, xv, y, yv)` 表示 `x == xv || y == yv`。
#complexity("V + E")
#code-block("code/05-graph/two-sat.cpp")
=== Articulation Point
简单无向图割点。
#complexity("V + E")
#code-block("code/05-graph/articulation-point.cpp")
=== Vertex BCC
点双连通分量；`cut` 标记割点。
#complexity("V + E")
#code-block("code/05-graph/vertex-bcc.cpp")
=== Bridge
无向图边需带唯一编号。
#complexity("V + E")
#code-block("code/05-graph/bridge.cpp")
=== Edge BCC
边双连通分量；重边用边编号处理。
#complexity("V + E")
#code-block("code/05-graph/edge-bcc.cpp")
== LCA
=== Binary Lifting
#complexity("n log n", "log n")
#code-block("code/05-graph/lca-binary-lifting.cpp")
=== Heavy-Light Decomposition
`dfn` 为 `1` base；`path` 将路径拆成若干连续区间。
#complexity("n", "log n")
#code-block("code/05-graph/hld.cpp")
== Bipartite Matching
=== Kuhn
#complexity("V E")
#code-block("code/05-graph/bipartite-kuhn.cpp")
=== Hopcroft-Karp
#complexity("sqrt(V) E")
#code-block("code/05-graph/hopcroft-karp.cpp")
== Weighted Perfect Matching
=== Kuhn-Munkres
最小权完美匹配；最大权可取相反数。
#complexity("n^3")
#code-block("code/05-graph/kuhn-munkres.cpp")
== Network Flow
=== Dinic
#complexity("V^2 E")
#code-block("code/05-graph/dinic.cpp")
=== Min Cost Max Flow
SPFA 增广；允许负费用边，不允许负费用环。
#complexity("F V E")
#code-block("code/05-graph/min-cost-max-flow.cpp")
== Eulerian Trail
无向图欧拉路；返回空数组表示不连通或未覆盖所有边。
#complexity("V + E")
#code-block("code/05-graph/euler-trail.cpp")

= Math
== GCD
=== Euclidean
#complexity("log min(a, b)")
#code-block("code/06-math/euclidean-gcd.cpp")
=== Extended
#complexity("log min(a, b)")
#code-block("code/06-math/extended-gcd.cpp")
=== Binary GCD
#complexity("log max(a, b)")
#code-block("code/06-math/binary-gcd.cpp")
== Prime Sieve
=== Eratosthenes
#complexity("n log log n")
#code-block("code/06-math/eratosthenes-sieve.cpp")
=== Linear
#complexity("n")
#code-block("code/06-math/linear-sieve.cpp")
=== Segmented
筛区间 `[l, r]` 内素数。
#complexity("(r - l + 1) log log r")
#code-block("code/06-math/segmented-sieve.cpp")
== Mobius
线性筛莫比乌斯函数。
#complexity("n")
#code-block("code/06-math/mobius.cpp")
== Euler Phi
#complexity("sqrt(n)")
#code-block("code/06-math/euler-phi.cpp")
== Modular Arithmetic
=== Fast Power
#complexity("log b")
#code-block("code/06-math/mod-pow.cpp")
=== Modular Inverse
返回 `-1` 表示逆元不存在。
#complexity("log min(a, mod)")
#code-block("code/06-math/mod-inverse.cpp")
=== Combination
模数为素数。
#complexity("n", "1")
#code-block("code/06-math/combination.cpp")
=== Lucas
要求已初始化 `0..mod-1` 的组合数。
#complexity("log n")
#code-block("code/06-math/lucas.cpp")
=== CRT
返回 `{x, mod}`；无解返回 `{-1, -1}`。
#complexity("k log M")
#code-block("code/06-math/crt.cpp")
== Primality & Factorization
=== Miller-Rabin
`long long` 范围确定性素性测试。
#complexity("log n")
#code-block("code/06-math/miller-rabin.cpp")
=== Pollard-Rho
依赖 Miller-Rabin 与 `mulMod`。
#complexity("n^(1 / 4)")
#code-block("code/06-math/pollard-rho.cpp")
== Polynomial
=== NTT
模数 `998244353`，原根 `3`。
#complexity("n log n")
#code-block("code/06-math/ntt.cpp")
== Divisor Block
$floor(n / i)$ 相同的一段为 `[l, r]`。
#complexity("sqrt(n)")
#code-block("code/06-math/divisor-block.cpp")
== Matrix Power
#complexity("n^3 log k")
#code-block("code/06-math/matrix-power.cpp")
== Linear Basis
维护异或线性基。
#complexity("log V")
#code-block("code/06-math/linear-basis.cpp")

= 计算几何
== Basic
#code-block("code/07-geometry/basic.cpp")
== Product
#code-block("code/07-geometry/product.cpp")
== Relation
#code-block("code/07-geometry/relation.cpp")
== Distance
#code-block("code/07-geometry/distance.cpp")
== Angle
#code-block("code/07-geometry/angle.cpp")
== Polygon Area
#code-block("code/07-geometry/polygon.cpp")
== Rectangle Union Area
扫描线求矩形面积并。
#complexity("n log n")
#code-block("code/07-geometry/rectangle-union-area.cpp")
== Convex Hull
默认不保留共线点。
#complexity("n log n")
#code-block("code/07-geometry/convex-hull.cpp")
== Rotating Calipers
凸包直径平方。
#complexity("n")
#code-block("code/07-geometry/rotating-calipers.cpp")
== Half-Plane Intersection
保留有向直线左侧半平面。
#complexity("n log n")
#code-block("code/07-geometry/half-plane-intersection.cpp")

= Misc
== Int128 IO
#code-block("code/08-misc/int128-io.cpp")
== High Precision Integer
#code-block("code/08-misc/big-integer.cpp")
== Euclid's Game
#code-block("code/08-misc/euclids-game.cpp")

= Appendix
== 位运算
```cpp x = 0``` 时 ```cpp __builtin_clz``` 和 ```cpp __builtin_ctz``` 为 UB。

- ```cpp __builtin_clz(x)```：前导零数。
- ```cpp __builtin_ctz(x)```：尾随零数。
- ```cpp __builtin_popcount(x)```：二进制 `1` 数。

C++20：

- ```cpp std::bit_width(x)```
- ```cpp std::countl_zero(x)```
- ```cpp std::countr_zero(x)```
- ```cpp std::popcount(x)```
=== STL
- 小根堆：```cpp priority_queue<int, vector<int>, greater<int>> pq;```
- `lower_bound` 返回第一个 $rr x$ 的位置，`upper_bound` 返回第一个 $gt x$ 的位置。
- `set::erase(value)` 删除所有等于 `value` 的元素；`multiset` 单删用 `erase(find(value))`。
- `map[key]` 会插入默认值；只查存在性用 `find` 或 `contains`。
== 数论
=== Euler Function
$ phi(n) = n product_(p divides n) (1 - 1 / p) $

- 若 $n$ 为素数，则 $phi(n) = n - 1$。
- 若 $p$ 为素数且 $k rr 1$，则 $phi(p^k) = p^k - p^(k - 1)$。
- 若 $gcd(a, b) = 1$，则 $phi(a b) = phi(a) phi(b)$。
=== Divisor Counting Function
$ d(n) = product_(p^k divides n)(k + 1) $
=== Sum Of Divisors Function
$ sigma(n) = product_(p^k divides n)(p^(k + 1) - 1) / (p - 1) $
=== Mobius Function
- $mu(1) = 1$。
- 若 $n$ 含平方因子，则 $mu(n) = 0$。
- 若 $n$ 为 $k$ 个不同素数之积，则 $mu(n) = (-1)^k$。
- $ sum_(d divides n) mu(d) = [n = 1] $
=== Divisor Block
若 $q = floor(n / l)$，则使 $floor(n / i) = q$ 的最大 $r = floor(n / q)$。
=== Modular Inverse
模逆元存在当且仅当 $gcd(a, M) = 1$。

- 费马小定理：$M$ 为素数时，$a^(-1) = a^(M - 2) mod M$。
- 欧拉定理：$a^(-1) = a^(phi(M) - 1) mod M$。
- 线性递推：$i^(-1) = (M - M mod i) (M mod i)^(-1) mod M$。
== 组合数学
=== Inclusion-Exclusion Principle
$
    lr(bar union.big_(i=1)^n S_i bar) = sum_(i=1)^n lr(bar S_i bar) - sum_(1 ll i < j ll n) lr(bar S_i inter S_j bar) + dots.c + (-1)^(n-1) lr(bar S_1 inter dots.c inter S_n bar)
$
=== Digital Root
- $dr(n) = n mod 9$，其中 $dr(0) = 0$，非零且 $9 divides n$ 时 $dr(n) = 9$。
- $dr(x + y) = dr(dr(x) + dr(y))$。
- $dr(x y) = dr(dr(x) dr(y))$。
=== Catalan Number
$ C_n = 1 / (n + 1) binom(2 n, n) = binom(2 n, n) - binom(2 n, n + 1) $
=== Burnside Lemma
$ "orbits" = 1 / (lr(bar.v) G lr(bar.v)) sum_(g in G) "fix"(g) $
Pólya 计数是在 Burnside 上按置换循环节统计染色方案。
== 博弈论
=== 单堆减法博弈
每次拿走集合 $S$ 中的数量，拿走最后一个者胜。$dp[0] = 0$，
$ dp[i] = or.big_(s in S, i rr s) (!dp[i - s]) $
=== 标准 Nim
令 $x = a_1 xor a_2 xor dots.c xor a_n$。若 $x = 0$，先手必败；否则先手必胜。
=== Misère Nim
拿走最后一个者输。

- 若所有堆大小都不超过 $1$，先手必胜当且仅当堆数为偶数。
- 否则，先手必胜当且仅当 $a_1 xor a_2 xor dots.c xor a_n eq.not 0$。
=== Sprague-Grundy 定理
$ g(x) = mex({g(y) mid(|) y in "move"(x)}) $

- $g(x) = 0$ 当且仅当状态 $x$ 为必败态。
- 独立子局面的 SG 值异或即为总局面 SG 值。
=== 图上博弈
无法移动者输；有环时可能平局。反图逆推：

- 出度为 $0$ 的点是必败态。
- 能到达必败态的点是必胜态。
- 所有后继都是必胜态的点是必败态。
- 其他点是平局态。
=== Euclid's Game
令 $a ll b$。若 $b mod a = 0$ 或 $floor(b / a) rr 2$，当前玩家必胜；否则转到 $(b mod a, a)$ 并胜负取反。
=== Wythoff Game
必败态为
$
    (floor(k phi), floor(k phi^2)), k = 0, 1, 2, ..., phi = (1 + sqrt(5)) / 2
$
== 图论结论
=== 竞赛图
$n$ 个顶点的竞赛图有 $2^(n(n - 1) / 2)$ 个，其中无环竞赛图有 $n!$ 个。
=== 欧拉路
- 无向图欧拉回路：所有非零度点连通，且所有点度数为偶数。
- 无向图欧拉通路：所有非零度点连通，且奇度点个数为 `0` 或 `2`。
- 有向图欧拉回路：所有非零度点在同一弱连通块，且每点入度等于出度。
- 有向图欧拉通路：除起终点外入度等于出度，起点出度比入度大 `1`，终点入度比出度大 `1`。
=== DAG
DAG 上可按拓扑序做最短路、最长路与 DP；有向图缩点后一定是 DAG。
=== 二分图
二分图不存在奇环。最大匹配数等于最小点覆盖数。
=== Hall 定理
左部存在匹配覆盖的充要条件：任意左部点集 $S$ 的邻点集大小 $|N(S)| rr |S|$。
