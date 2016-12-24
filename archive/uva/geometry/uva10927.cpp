#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef map<int, int> mii;

const double EPS=1e-11;
const ll MAX31 = 2147483647;
const ll MIN31 = -2147483648;
#define PI acos(-1.0)

int n;

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
  bool operator < (point other) const { // override less than operator
    if (fabs(x - other.x) > EPS)                 // useful for sorting
      return x < other.x;          // first criteria , by x-coordinate
    return y < other.y; }          // second criteria, by y-coordinate
  // use EPS (1e-9) when testing equality of two floating points
    bool operator == (point other) const {
    	return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); 
    } 
};

double findGrad(double x, double y){
	if (x==0 && y>0) return PI/2;
	if (x==0 && y<0) return 3*PI/2;
	if (x>0 && y==0) return 0;
	if (x<0 && y==0) return PI;
	if (x>0) return atan(y/x);
	return PI+atan(y/x);
}

point pts[110000];
int h[110000];
pair<point,int> ptsPolar[110000];

int main(){
	int coun=1;
	while (cin>>n){
		if (n==0) break;
		for (int i=0; i<n; i++){
			double x,y,z;
			cin>>x>>y>>z;
			// cout<<x<<" "<<y<<" "<<z<<endl;
			pts[i] = point(x,y);
			h[i] = z;
			point tmp(atan2(y,x), sqrt(x*x+y*y));
			ptsPolar[i] = pair<point,int>(tmp, i);
		}
		sort(ptsPolar, ptsPolar+n);
		vi res1;
		int cur = 0;
		double curGrad = ptsPolar[0].first.x;
		double curR = ptsPolar[0].first.y;
		int curH = h[ptsPolar[0].second];
			// cout<<ptsPolar[0].second<<" "<<curGrad<<" "<<curR<<" "<<curH<<endl;
		for (int i=1; i<n; i++){
			double grad = ptsPolar[i].first.x;
			double r = ptsPolar[i].first.y;
			int hei = h[ptsPolar[i].second];
			// cout<<ptsPolar[i].second<<" "<<grad<<" "<<r<<" "<<hei<<endl;
			if (fabs(curGrad-grad)<EPS){
				if (hei<=curH) {
					res1.push_back(ptsPolar[i].second);
				}
				else {
					curH = hei;
				}
			}
			else {
				curH = hei;
			}
			curGrad = grad;
			curR = r;
		}
		vector<pair<double, double>> res;
		for (int i=0; i<res1.size(); i++){
			res.push_back(pair<double,double>(pts[res1[i]].x, pts[res1[i]].y));
		}
		sort(res.begin(), res.end());
		printf("Data set %d:\n", coun);
		if (res.size()==0){
			cout<<"All the lights are visible."<<endl;
		}
		else {
			cout<<"Some lights are not visible:"<<endl;
			for (int i=0; i<res.size()-1; i++){
				printf("x = %.0f, y = %.0f;\n", res[i].first, res[i].second);
			}
			printf("x = %.0f, y = %.0f.\n", res[res.size()-1].first, res[res.size()-1].second);
		}
		coun ++;
	}
}















































