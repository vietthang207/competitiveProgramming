# cpp
Codeblocks config file is 5791 lines long.

#Frequent bug

* Short circuit: res=true; res= res|| dfs(x,y); dfs(x,y) never run.
* floating point: int money; money= money/1.1; should be money=(double)money/1.1+1e-6;
* Negative integer modulo
* reset variable after every iteration
* lower_bound can return item less or equal than needed value, so need double check
* Dp memo table limit, e.g. uva10819 must have limit 14000 (10000 + 4000)
