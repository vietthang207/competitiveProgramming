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
#define MAX_N 2000100

char T[MAX_N], P[MAX_N]; // T = text, P = pattern
int b[MAX_N], n, m, coun; // b = back table, n = length of T, m = length of P

void kmpPreprocess() { // call this before calling kmpSearch()
  int i = 0, j = -1; b[0] = -1; // starting values
  while (i < m) { // pre-process the pattern string P
    while (j >= 0 && P[i] != P[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
} }           // in the example of P = "SEVENTY SEVEN" above

void kmpSearch() { // this is similar as kmpPreprocess(), but on string T
  int i = 0, j = 0; // starting values
  while (i < n) { // search through string T
    while (j >= 0 && T[i] != P[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    if (j == m) { // a match found when j == m
      // printf("P is found at index %d in T\n", i - j);
    	coun++;
      j = b[j]; // prepare j for the next possible match
} } }

int main(){
    string s;
    getline(cin, s);
    while (s!="."){
    	coun = 0;
    	m = s.size();
    	n = m*2;
    	for (int i=0; i<m ;i++){
    		P[i] = s[i];
    		T[i] = s[i];
    		T[i+m] = s[i];
    	}
    	kmpPreprocess();
    	kmpSearch();
    	cout<<coun-1<<endl;
    	getline(cin, s);
    }
}
