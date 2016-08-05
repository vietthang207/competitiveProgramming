#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef map<int, int> mii;

const double EP=1e-6;
const ll MAX31 = 2147483647;
const ll MIN31 = -2147483648;

int main(){
    double cow, car, show;
    while (cin>>cow>>car>>show){
    	double res = (cow/(car+cow))*(car)/(car+cow-show-1);
    	res+= (car/(car+cow)) * (car-1)/(car+cow-show-1);
    	printf("%.5f\n", res);
    }
}
