#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

bool visited[10][10];

int main(){
    int n, m, s ;

    cin>>n>>m>>s;
    while (n!=0){
        string a[n];
//        memset(a, -1, sizeof(a));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i<n; i++){
            cin>>a[i];
            //cout<<a[i]<<endl;
        }

        int x=0, y = s-1;
        int cou = 0;
        bool flag = true;
        int x0, y0;
        //cout<<x0<<" "<<y0<<endl;
        while (x>=0 && x<n && y>=0 && y<m){
            cou++;
            if (visited[x][y]){
                x0=x; y0=y;
                flag = false;
                break;
            }
            visited[x][y]=  true;
            //cout<<a[x][y]<<endl;
            if (a[x][y]=='E') y++;
            else if (a[x][y]=='W') y--;
            else if (a[x][y]=='N') x--;
            else if (a[x][y]=='S') x++;

        }
        if (flag) {
            cout<<cou<<" step(s) to exit"<<endl;
        } else {
            int cou2=0;
            x = 0;
            y = s-1;
            while (x>=0 && x<n && y>=0 && y<m){
                //cout<<x<<" "<<y<<endl;
                if (x==x0 && y==y0) break;
                if (a[x][y]=='E') y++;
            else if (a[x][y]=='W') y--;
            else if (a[x][y]=='N') x--;
            else if (a[x][y]=='S') x++;
                cou2++;

            }
            printf("%d step(s) before a loop of %d step(s)\n", cou2, cou-cou2-1);
        }

        cin>>n>>m>>s;
    }
}
