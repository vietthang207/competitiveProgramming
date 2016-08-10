#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef map<int, int> mii;

const double EPS=1e-9;
const ll MAX31 = 2147483647;
const ll MIN31 = -2147483648;

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
  bool operator < (point other) const { // override less than operator
    if (fabs(x - other.x) > EPS)return x < other.x;          // first criteria , by x-coordinate
    return y < other.y; 
  }          // second criteria, by y-coordinate
  // use EPS (1e-9) when testing equality of two floating points
  bool operator == (point other) const {
   return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); 
  } 
};

double dist(point p1, point p2) {                // Euclidean distance
                      // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
  return hypot(p1.x - p2.x, p1.y - p2.y); 
}           
int n, a;
point pts[4];

int main(){
	while (cin>>n>>a){
		if (n==0) break;
		pts[0] = point(0,a);
		pts[1] = point(a,0);
		pts[2] = point(0,0);
		pts[3] = point(a,a);
		int res = 0;
		for (int i=0; i<n; i++){
			double x,y;
			cin>>x>>y;
			point tmp = point(x,y);
			bool flag = true;
			for (int j=0; j<4; j++){
				if (dist(pts[j], tmp)>a) flag = false;
			}
			if (flag) res++;
		}
		printf("%.5f\n", 1.0*res*a*a/n);
	}
}
