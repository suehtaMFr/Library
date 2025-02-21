#include <bits/stdc++.h>
 
using namespace std;
 
//bem gay
#define inf 1e9+7
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
	
	int tc,n,a,b,c,d,p,q,y;
	cin >> tc;
	while(tc--)
	{
		cin >> n >> a >> b >> c >> d >> p >> q >> y;
		int v[n+1];
		long long int ans,dis=0LL,tam=0LL,tr=0LL;
		for(int i=1;i<=n;i++)
			cin >> v[i];
			
		int x1=max(a,b),y1=min(a,b)+1;
		while(y1<=x1)
		{
			dis+=v[y1]-v[y1-1];
			y1++;
		}
		ans=dis*p;
		x1=max(a,c),y1=min(a,c)+1,dis=0LL;
		while(y1<=x1)
		{
			dis+=v[y1]-v[y1-1];
			y1++;
		}
		if(dis*p<=y)
		{
			tam=abs(dis*p-y);
			x1=max(b,d),y1=min(b,d)+1;
			while(y1<=x1)
			{
				dis+=v[y1]-v[y1-1];
				y1++;
			}
			x1=max(c,d),y1=min(c,d)+1;
			while(y1<=x1)
			{
				tr+=v[y1]-v[y1-1];
				y1++;
			}
			ans=min(ans,dis*p+tr*q+tam);
		}
		cout << ans << "\n";
	}
}
