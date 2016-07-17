# Editor:
Codeblocks config file is 5791 lines long.

# Frequent bugs

* Short circuit: res=true; res= res|| dfs(x,y); dfs(x,y) never run.
* floating point: int money; money= money/1.1; should be money=(double)money/1.1+1e-6;
* Negative integer modulo
* reset variable after every iteration
* Dp memo table limit, e.g. uva10819 must have limit 14000 (10000 + 4000)

# Minor bugs

* Second best MST: after temporarily remove 1 edge from MST, and run Kruskal again, the result tree may not be a spanning tree (since we remove a bridge). Fix, maintain a counter to make sure Kruskal really return a spanning tree.
