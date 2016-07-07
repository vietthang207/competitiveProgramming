#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int mv[2][8] = {
    {-1,-1,-1,0,0,1,1,1},
    {-1,0,1,-1,1,-1,0,1}
};

int main(){
    int n,m ;
    int count=1;
    cin>>n>>m;
    while (n!=0){

        string a[n];
        for (int i=0; i<n; i++){
            cin>>a[i];
        }
        int res = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                int x,y;
                if (a[i][j]=='.') continue;
                bool flag = false;
                for (int k=0; k<8; k++){
                    x = i+mv[0][k];
                    y = j+mv[1][k];
                    if (x>=0 && x<n && y>=0 && y<m && a[x][y]=='*'){
                        flag = true;
                        break;
                    }

                }
                if (!flag) res++;
            }
        }

        cout<<res<<endl;

        cin>>n>>m;
    }
}
