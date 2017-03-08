vii res;
if (n%2==1) {
    res.push_back(pii(n, n));
    n--;
    flag = 1;
}
if (n%6 != 2) {
    for (int i=1; i<=n/2; i++) {
        res.push_back(pii(i, 2*i));
        res.push_back(pii(n/2+i, 2*i-1));
    }
}
else if (n%6!=0) {
    for (int i=1; i<=n/2; i++) {
        res.push_back(pii(i, 1+(2*i+n/2-3)%n));
        res.push_back(pii(n+1-i, n-(2*i+n/2-3)%n));
    }
}
if (flag) n++;
