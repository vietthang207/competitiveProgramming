#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

vi al[101];
bool visited[101];
bool off[101];
bool dom[101][101];

void dfs(int s, set<int>* res){
    if (off[s]) return;
    visited[s] = true;
    res->insert(s);
    //cout<<"visit "<<s<<endl;
    for (int i:al[s]){
        if (!visited[i]){
            //(*res).insert(i);
            dfs(i, res);
        }
    }
}

void printvec(int s){
    string bla = "+";
    for (int i = 0; i<s-1; i++){
        bla+="--";
    }
    bla+="-+";
    for (int i=0; i<s; i++){
        cout<<bla<<endl;
        for (int j=0; j<s; j++){
            if (dom[i][j]){
                cout<<"|Y";
            }
            else cout<<"|N";
        }
        cout<<"|"<<endl;
    }
    cout<<bla<<endl;
}

int main(){
    int T ;
    int count=1;
    cin>>T;

    for (int t=0; t<T; t++){
        int n;
        cin>>n;
        memset(visited, false, sizeof(visited));
        memset(dom, false, sizeof(dom));
        memset(off, false, sizeof(off));

        for (int i=0; i<n; i++){
            al[i] = vi();
            for (int j=0; j<n; j++){
                int x;
                cin>>x;
                if (x==1){
                    al[i].push_back(j);
      //              cout<<"push "<<i<<" "<<j<<endl;
                }
            }
        }


        set<int> all;
        dfs(0,&all);


        for (int i:all){
            //cout<<i<<endl;
            memset(visited, false, sizeof(visited));
            //dom[i][i] = true;
            off[i] = true;

            set<int> vec;
            dfs(0, &vec);
            //cout<<"vec"<<i<<endl;
            //for (int k:vec) cout<<k<<" ";
            //cout<<endl;
            for (int j:all){
                if (vec.find(j)==vec.end()){
                    dom[i][j] = true;
                }
            }
            off[i] = false;
        }

        printf("Case %d:\n", t+1);
        printvec(n);

    }
}
