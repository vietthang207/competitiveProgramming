#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main(){
    int n, m ;
    int count=1;
    cin>>n>>m;
    while (n!=0 || m!=0){
        bitset<1000010> sche;
        bool flag = false;
        for (int i=0; i<n; i++){
            int s,e;
            cin>>s>>e;
            if (s>e){
                flag = true;

            }
            for (int j=s; j<e; j++){
                if (sche[j]) {
                    flag = true;
                    break;
                }
                else {
                    sche[j] = true;
                }
            }
            //cout<<s<<" "<<e<<endl;
        }

        for (int i=0; i<m; i++){
            int s,e, in;
            cin>>s>>e>>in;
            if (in<e-s || s>e){
                flag = true;

            }
            while (s<1000001){
                for (int j=s; j<e&& j<1000001; j++){
                    if (sche[j]) {
                        flag = true;

                        s  = 10000100;
                        break;
                    }
                    else {
                        sche[j] = true;
                    }
                }
                s+=in;
                e+=in;
                if (in==0) {
                    i = m;
                    break;
                }
                //cout<<s<<" "<<e<<" "<<in<<endl;
            }

        }

        if (flag) cout<<"CONFLICT"<<endl;
        else cout<<"NO CONFLICT"<<endl;
        cin>>n>>m;
        //cout<<n<<" "<<m<<endl;
    }
}
