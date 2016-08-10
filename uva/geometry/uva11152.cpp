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
#define PI acos(-1.0)

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {} 
};      // constructor

double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y); 
}

double perimeter(double ab, double bc, double ca) {
  return ab + bc + ca; 
}

double area(double ab, double bc, double ca) {
  // Heron's formula, split sqrt(a * b) into sqrt(a) * sqrt(b); in implementation
  double s = 0.5 * perimeter(ab, bc, ca);
  return sqrt(s) * sqrt(s - ab) * sqrt(s - bc) * sqrt(s - ca); 
}

double rInCircle(double ab, double bc, double ca) {
  return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca)); 
}
double rCircumCircle(double ab, double bc, double ca) {
  return ab * bc * ca / (4.0 * area(ab, bc, ca)); 
}

int main(){
	double a,b,c;
	while (cin>>a>>b>>c){
		double rin = rInCircle(a,b,c);
		double rcir = rCircumCircle(a,b,c);
		double triArea = area(a,b,c);
		printf("%.4f %.4f %.4f\n", PI*rcir*rcir-triArea, triArea - PI*rin*rin, PI*rin*rin );
	}
}
