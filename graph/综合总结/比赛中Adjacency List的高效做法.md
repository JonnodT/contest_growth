* 可以用struct，也可以用多个数组存很多参数，但是多个数组比较乱，所以这里就记一种用struct + array表示的
  * Weighted Directed Graph
    * 一般会用一个数组Edge arr[maxn]存着所有的边，这个数组没有链接关系，作用是给每一条边一个index，这样以后找predecessor或者reconstruct path的时候比较方便。在做网络流的时候也可以方便给反向边加flow（i^1）。这样比用vector[] 存更好定位某些特定的边
    * 再用一个head数组存每个节点的outward edges 的index！！！，每个边都有一个属性next，最后一条边这个值是-1，这就可以遍历从一个节点发出的所有边。
