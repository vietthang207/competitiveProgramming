#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef map<int, int> mii;

const double EPS=1e-6;
const ll MAX31 = 2147483647;
const ll MIN31 = -2147483648;

struct point { 
  double x, y;
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
  bool operator < (point other) const { 
    if (fabs(x - other.x) > EPS) return x < other.x;          
    return y < other.y; 
  }
  // use EPS (1e-9) when testing equality of two floating points
  bool operator == (point other) const {
   return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); 
  } 
};

struct vec { double x, y;  // name: `vec' is different from STL vector
  vec(double _x, double _y) : x(_x), y(_y) {} };
vec toVec(point a, point b) {       // convert 2 points to vector a->b
  return vec(b.x - a.x, b.y - a.y); }
vec scale(vec v, double s) {        // nonnegative s = [<1 .. 1 .. >1]
  return vec(v.x * s, v.y * s); }               
point translate(point p, vec v) {        // translate p according to v
  return point(p.x + v.x , p.y + v.y); }
double dist(point p1, point p2) {                // Euclidean distance
                      // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
  return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
double distToLine(point p, point a, point b, point &c) {
  // formula: c = a + u * ab
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  c = translate(a, scale(ab, u));                  // translate a to c
  return dist(p, c); }           // Euclidean distance between p and c


double distToLineSegment(point p, point a, point b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) { c = point(a.x, a.y);                   // closer to a
    return dist(p, a); }         // Euclidean distance between p and a
  if (u > 1.0) { c = point(b.x, b.y);                   // closer to b
    return dist(p, b); }         // Euclidean distance between p and b
  return distToLine(p, a, b, c); }          // run distToLine as above

int n;
point s;
vector<point> rail;

int main(){
		double x,y;
	while (cin>>x>>y){
		rail.clear();
		cin>>n;
		s = point(x,y);
		for (int i=0; i<n+1; i++){
			cin>>x>>y;
			rail.push_back(point(x,y));
			// cout<<x<<" "<<y<<endl;
		}
		double mini = MAX31;
		point res;
		for (int i=0; i<n; i++){
			point tmp;
			double d = distToLineSegment(s, rail[i], rail[i+1], tmp);
			if (d<mini){
				mini = d;
				res = tmp;
			}
		}
		printf("%.4f\n%.4f\n", res.x, res.y);
	}
}
