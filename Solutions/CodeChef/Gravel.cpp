#include <iostream>

using namespace std;

long long int bit[10000024];

void update(int id,int val,int n){
	
	for(;id<=n;id+= id & -id)
		bit[id]+=val;
}

void up(int l,int r,int val,int n){
	
	update(l,val,n);
	update(r+1,-val,n);
}

long long int querry(int id){
    long long int ret = 0;
    for (; id > 0; id -= id & -id)
        ret += bit[id];
    return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,q,va,l,r;
	cin >> n >> q >> va;
	up(1,n,va,n);
	char c;
	for(int i=0;i<q;i++)
	{
		cin >> c >> l;
		if(c=='Q')
		{
			cout << querry(l) << "\n";
		}
		else
		{
			cin >> r >> va;
			up(l,r,va,n);
		}
	}
}
