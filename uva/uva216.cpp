#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int x[10], y[10];
vector<double> al[10];
int n;
vi resv;

double memo[10][1025];
bool memob[10][1025];

double tsp(int pos, int mask){
    if (memob[pos][mask]) return memo[pos][mask];
    double res = 99999999;
    if (mask == ( (1<<n)-1)) return 0;
    //cout<<pos<<" "<<mask<<endl;
    //int m;
    for (int i=0; i<n; i++){
        //cout<<"m: "<< (mask& (1<<i))<<endl;

        if ( (mask & (1<<i)) ==0){
        //cout<<"bla"<<endl;
            double tmp = al[pos][i]+tsp(i, mask | (1<<i));
            if (tmp<res){
                res = tmp;
    //            m = i;
            }
        }
    }
    //resv.push_back(m);
    memob[pos][mask] = true;
    memo[pos][mask] = res;
    return res;
}

int main(){
    int coun=1;
    cin>>n;
    while (n!=0){

        memset(memob, false, sizeof(memob));

        for (int i=0; i<n; i++){
            al[i].clear();
            cin>>x[i]>>y[i];
        }

        for (int i=0; i<n; i++){

            for (int j=0; j<n; j++){
                //cout<<x[i]<<" "<<y[i]<<" "<<x[j]<<" "<<y[j]<<endl;
                al[i].push_back(sqrt( pow((x[i]-x[j]), 2) + pow((y[i]-y[j]),2) )+16.0);
                //cout<<al[i][j]<<endl;
            }
            //cout<<endl;
        }

        double res = 999999;
        int m;

        for (int i=0; i<n; i++){
            //memset(memob, false, sizeof(memob));
            double tmp = tsp(i, 1<<i);
            if (tmp<res) {
                m = i;
                res = tmp;
            }
        }

        memset(memob, false, sizeof(memob));
        int mask = (1<<m);
        resv.clear();
        resv.push_back(m);
        tsp(m, mask);
        for (int i=0; i<n-1; i++){
            double res2 = 9999999;
            int m2;
            for(int j=0; j<n; j++){
                //cout<<mask<<" "<<j<<" "<< (mask& (1<<j))<<endl;
                if ( ((mask & (1<<j)) ==0 ) ){
                    //memset(memob, false, sizeof(memob));
                    //cout<<j<<endl;
                    double tmp = al[m][j] + tsp(j, mask | (1<<j));
                    //cout<< tmp<<endl;
                    if (tmp< res2){
                        m2 = j;
                        res2 = tmp;
                    }
                }
            }

            m = m2;
            //cout<<m2<<endl;
            resv.push_back(m);
            mask |= (1<<m);

        }
//        for(int i:resv){
//            cout<<i<<" ";
//        }
//        cout<<endl;

//        cout<<res<<endl;

        cout<<"**********************************************************"<<endl;
        printf("Network #%d\n", coun);
        for (int i=0; i<n-1; i++){
            int i1 = resv[i];
            int i2 = resv[i+1];
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", x[i1], y[i1], x[i2], y[i2], al[i1][i2]);
        }
        printf("Number of feet of cable required is %.2f.\n", res);

        coun ++;
        n=-1;
        cin>>n;
    }
}
