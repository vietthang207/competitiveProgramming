#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<long long,int> pii;
int t,n;
pii memo[100010];
pii play(int start, int a[]){
    //cout<<"n "<<n<<" start "<<start<<" "<<endl;
    pii r,r1,r2,r3;
    if (memo[start].first!=-1) return memo[start];
    if (start>n-4){
        for (int i=start; i<n; i++) r.first+=a[i];
        r.second=n;
        memo[start]=r;
        return r;
    }
    pii temp=play(start+1,a);
    r1= play(temp.second,a);
    r1.first+=a[start];
    r1.second=start+1;
    temp= play(start+2,a);
    r2=play(temp.second,a);
    r2.first+=a[start]+a[start+1];
    r2.second= start+2;
    temp=play(start+3,a);
    r3= play(temp.second,a);
    r3.first+= a[start]+a[start+1]+ a[start+2];
    r3.second=start+3;
    //cout<<"start "<<start<<endl;
    //cout<< r1.second<<" "<<r2.second<<" "<<r3.second<<endl;
    if (r1.first>=r2.first && r1.first>=r3.first) {memo[start]=r1; return r1;}
    else if (r2.first>=r1.first && r2.first>=r3.first) {memo[start]=r2;return r2;}
    else {memo[start]=r3;return r3;}
}

int main(){
    cin>>t;
    for (int i=0; i<t; i++){
        cin>>n;
        int a[n];
        for (int i=0; i<n; i++){
            int temp; cin>>temp;
            a[i]=temp;
            pii temp2(-1,-1);
            memo[i]=temp2;
        }
        cout<< play(0,a).first<<endl;
    }
}
