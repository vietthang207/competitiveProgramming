#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

vector<string> s;
map<string, int> m;
vi al[300];
bool visited[300];
queue<pii> q;

bool check(string s1, string s2){
    if (s1.size()!=s2.size()) return false;
    int coun = 0;
    for (int i=0; i<s1.size(); i++){
        if (s1[i]!=s2[i]) coun++;
    }
    if (coun==1) return true;
    return false;
}

int main(){
    int T;
    cin>>T;
    string tmp;
    for (int t=0; t<T; t++){

        s.clear();
        m.clear();
        q = queue<pii>();
        memset(visited, false, sizeof(visited));
        for (int i=0; i<300; i++) al[i].clear();

        cin>>tmp;
        while (tmp!="*"){
            s.push_back(tmp);
            cin>>tmp;
        }

        for (int i=0; i<s.size(); i++){
            m[s[i]] = i;
        }

        for (int i=0; i<s.size(); i++){
            for (int j=0; j<s.size(); j++){
                if (check(s[i],s[j])){
                    al[i].push_back(j);
                }

            }
        }

        getline(cin,tmp);
        getline(cin,tmp);
        while (tmp!=""){
            int found = tmp.find_first_of(" ");
            string s1 = tmp.substr(0,found);
            string s2 = tmp.substr(found+1,tmp.size()-found-1);
            int v1 = m[s1];
            int v2 = m[s2];

            q = queue<pii>();
            q.push(pii(v1,0));
            visited[v1] = true;
            int res;
            bool flag = false;
            while (!q.empty()){
                pii cur =q.front();
                q.pop();
                if (cur.first == v2) {
                    res = cur.second;
                    flag = true;
                    break;
                }

                for (int i:al[cur.first]){
                    if (!visited[i]){
                        q.push(pii(i, cur.second+1));
                        visited[i] = true;
                    }
                }

            }

            if (!flag) res = -1;
            cout<<s1<<" "<<s2<<" "<<res<<endl;

            getline(cin,tmp);
        }
        if (t!=T-1) cout<<endl;
    }
}















