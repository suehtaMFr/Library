#include <bits/stdc++.h>
 
using namespace std;
 
//bem gay
#define mid ((l+r)>>1)
#define sz(x) ((int)x.size())
#define fin freopen ("input.txt","w",stdout);
#define fout freopen ("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
//chup chup
#define ff first
#define ss second
#define pb push_back

int main () {
	
	fast;
	int tc,x1,x2,y1,y2;
	cin >> tc;
	while(tc--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1<x2&&y1==y2) cout << "right\n";
		else if(x1==x2&&y1<y2)	cout << "up\n";
		else if(x1>x2&&y1==y2) cout << "left\n";
		else if(x1==x2&&y1>y2) cout << "down\n";
		else cout << "sad\n";
	}
}
