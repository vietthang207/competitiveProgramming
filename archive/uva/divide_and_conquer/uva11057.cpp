#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int a[10100];

int main(){
    int n=-1 ;
    int coun=1;
    cin>>n;
    while (n!=-1){

        for (int i=0; i<n; i++)cin>>a[i];
        sort(a, a+n);
        //for (int i=0; i<n; i++) cout<<a[i]<<" ";
        //cout<<endl;
        int m;
        cin>>m;
        int x1 = 0,x2 = 999999;
        for (int i=0; i<n; i++){
            int pos = lower_bound(a, a+n, m-a[i]) - a;
            //cout<<i<<" "<<pos<<endl;
            if (pos == n) continue;
            if (a[i]+a[pos]!=m) continue;
            if (a[pos]==a[i]){
                //cout<<pos<<endl;
                if (pos ==n-1) continue;
                if (a[pos+1]!=a[i]) continue;

                x1 = a[i];
                x2 = a[i];
            }
            else if (a[i]<a[pos]){
                if (a[pos]-a[i] <x2-x1) {
                    x2=a[pos];
                    x1=a[i];
                }
            }
            else {
                if (a[i]-a[pos] <x2-x1) {
                    x2 = a[i];
                    x1 = a[pos];
                }
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", x1,x2);

        coun ++;
        n=-1;
        cin>>n;
    }
}
