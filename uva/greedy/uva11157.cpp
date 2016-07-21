#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int n,d;
int a[110];
bool big[110];
bool visited[110];

int main(){
	int T;
	cin>>T;
	for (int t=0; t<T; t++){
		cin>>n>>d;
		memset(visited, false, sizeof(visited));
		big[0] = true;
		a[0] = 0;
		big[n+1] = true;
		a[n+1] = d;
		for (int i=1; i<=n; i++){
			char c;
			int x;
			scanf("\n%c-%d", &c,&x);
			a[i] = x;
			if (c=='B') big[i] = true;
			else big[i] = false;
		}

		int res = 0;
		int pos = 0;
		int cur = 0;

		while (cur<n+1){
			int next = cur+1;
			if (big[next]) {
				res = max(res, a[next]-pos);
				cur = next;
				pos = a[next];
			}
			else {
				if (big[cur]){
					res = max(res, a[next] -pos);
					cur = next;
					pos = a[next];
					visited[next] = true;
				}
				else {
					res = max(res, a[next+1]-pos);
					cur = next+1;
					pos = a[next+1];
					visited[next+1] = true;
				}
			}
		}

		while (cur>0){
			int next;
			for (int i=cur-1; i>=0; i--){
				if (big[i]) {
					next = i;
					break;
				}
				else if (!visited[i]){
					next = i;
					break;
				}
			}
			res = max(res, pos-a[next]);
			pos = a[next];
			cur = next;
		}

		printf("Case %d: %d\n", t+1, res);
	}
}











