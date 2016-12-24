#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int n, e;
vi al[110];
int color[110];

vi cs(int s){
    //cout<<s<<endl;
    if (s==n+1) return vi();
    bool flag = false;
    for (int i:al[s]) {
        if (color[i]==1) flag = true;
    }
    if (flag) {
        color[s] = 0;
        vi res = cs(s+1);
        color[s] = -1;
        return res;
    }
    color[s] = 0;
    vi res1 = cs(s+1);
    color[s] = 1;
    vi res2 =cs(s+1);
    res2.push_back(s);
    color[s]= -1;
    if (res1.size()>res2.size()) return res1;
    return res2;

}

int main(){
    //cout<<"bla";
    int T;
    cin>>T;
    //cout<<T;
    for (int t=0; t<T; t++){
        for (int i=0; i<110; i++) al[i].clear();
        memset(color, -1, sizeof(-1));
        cin>>n>>e;
    //    cout<<n<<" "<<e<<endl;
        for (int i=0; i<e; i++){
            int v1, v2;
            cin>>v1>>v2;
            al[v1].push_back(v2);
            al[v2].push_back(v1);
      //      cout<<v1<<" "<<v2<<endl;
        }

    vi res = cs(1);
    cout<<res.size()<<endl;
    for (int i=res.size()-1; i>0; i--) cout<<res[i]<<" ";
    cout<<res[0]<<endl;
    }
}
