#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[10];

void counting(int i){
    if (i/10000!=0) a[i/10000%10]++;
    if (i/1000!=0) a[i/1000%10]++;
    if (i/100!=0) a[i/100%10]++;
    if (i/10!=0) a[i/10%10]++;
    if (i/1!=0) a[i/1%10]++;
}

int main(){
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        int x;
        memset (a, 0, sizeof(a));
        cin>>x;
        for (int j=1; j<=x; j++){
            counting(j);
        }
        for (int j=0; j<9; j++){
            cout<<a[j]<<" ";
        }
        cout<<a[9]<<endl;
    }
}
