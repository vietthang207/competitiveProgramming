#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

vi al[30];
bool visited[30][30];

int dfs(int v){
    //cout<<"visit "<<v<<endl;
    int res = 0;
    int counter = 0;
    for (int i: al[v]){
        if (!visited[i][v]){
            visited[i][v] = visited[v][i] = true;
            int tmp = 1+dfs(i);
            visited[i][v] = visited[v][i] = false;

            if (tmp>res) res = tmp;
        }
    }
    //if (counter>1 && 1>res) res = 1;
    return res;
}

int main(){
    int n, m ;
    int coun=1;
    cin>>n>>m;
    while (n!=0){
        //cout<<n<<endl;
        for (int i=0; i<30; i++) al[i].clear();
        memset(visited, false, sizeof(visited));
        for (int i=0; i<m;i++){
            int v1,v2;
            cin>>v1>>v2;
            al[v1].push_back(v2);
            al[v2].push_back(v1);
        }

        int res = 0;

        for (int i=0; i<n; i++){
            int tmp = dfs(i);
            if (tmp>res) res = tmp;
            memset(visited, false, sizeof(visited));
        }

        cout<<res<<endl;

        coun ++;
        cin>>n>>m;
    }
}
