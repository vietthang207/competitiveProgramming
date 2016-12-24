#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const long long MOD_CONST= 1000000007;

int T,N,M;
long long memo1d[102][102][302];
long long memoNchooseK[302][302];

long long oneD(int coor,int bound,int steps){
    if (steps==0) return 1;
    if (memo1d[coor][bound][steps]!=-1){return memo1d[coor][bound][steps];}
    long long r=0;
    if (coor>1){
        r=(r+oneD(coor-1,bound,steps-1))%MOD_CONST;
    }
    if (coor<bound) {
        r=(r+oneD(coor+1,bound, steps-1))%MOD_CONST;
    }
    memo1d[coor][bound][steps]=r;
//    cout<<"1D "<<r<<endl;
    return r;
}
long long nChooseK(int n, int k){
    if (k==0) return 1;
    if (n==k) return 1;
    if (memoNchooseK[n][k]!=-1) return memoNchooseK[n][k];
    long long r=(nChooseK(n-1,k-1)+nChooseK(n-1,k))%MOD_CONST;
    memoNchooseK[n][k]=r;
    return r;
}
long long memoWalk[302][12];
long long walk(vi& coor,vi& bound,int steps,int startDimen){
    if (memoWalk[steps][startDimen]!=-1) return memoWalk[steps][startDimen];
    if (steps==0) return 1;
    long long r=0;
    if (startDimen==bound.size()-1) {
        r= oneD(coor[startDimen],bound[startDimen],steps);
        memoWalk[steps][startDimen]=r;
        return r;
    }
    for (int i=0; i<=steps; i++){
        long long temp=(oneD(coor[startDimen],bound[startDimen],i)*nChooseK(steps,i))%MOD_CONST;
        temp=(temp*walk(coor,bound,steps-i,startDimen+1))%MOD_CONST;
        r=(r+temp)%MOD_CONST;
//        if (startDimen==0&&i==0)cout<<walk(coor,bound,steps-i,startDimen+1)<<endl;
    }
    memoWalk[steps][startDimen]=r;
//    cout<<steps<<" "<<startDimen<<" "<<r<<endl;
    return r;
}

int main(){
    cin>>T;
    memset(memo1d, -1, sizeof memo1d);
    memset(memoNchooseK,-1, sizeof memoNchooseK);
    for (int i=0; i<T; i++){
        //if (i==7) cout<<N<<" "<<M<<" "<<endl;
        cin>>N>>M;
        //if (i==7) cout<<N<<" "<<M<<" "<<endl;
        memset(memoWalk,-1,sizeof memoWalk);
        int temp;
        vi coor, bound;
        //if(i==7)  cout<<"i=8 "<<endl;
        for (int j=0; j<N; j++){
            cin>>temp;
        //    if(i==7) cout<<temp<<" ";
            coor.push_back(temp);
        }
        //if(i==7)cout<<endl;
        for (int j=0; j<N; j++){
            cin>>temp;
        //    if(i==7) cout<<temp<<" ";
            bound.push_back(temp);
        }
        //if(i==7)cout<<endl;
        //if(i==7)
            cout<<walk(coor,bound,M,0)<<endl;
        //if(i==7)cout<<"end"<<endl;
    }
}
