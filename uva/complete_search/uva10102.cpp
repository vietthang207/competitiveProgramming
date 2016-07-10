#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main(){
    int n=-1 ;
    int coun=1;
    cin>>n;
    while (n!=-1){

        int a[n][n];
        for (int i=0; i<n; i++){
            string tmp;
            cin>>tmp;
            for (int j=0; j<n; j++){
                a[i][j] = tmp[j]-'0';
            }
        }

        int res=-1;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (a[i][j]==1){
                    int m =9999999;
                    for (int k=0; k<n; k++){
                        for (int l=0; l<n; l++){
                            if (a[k][l]==3){
                                int dist = abs(k-i)+abs(l-j);
                                if (dist<m) m = dist;
                            }
                        }
                    }
                    if (m>res) res = m;
                }
            }
        }

        cout<<res<<endl;
        coun ++;
        n=-1;
        cin>>n;
    }
}
