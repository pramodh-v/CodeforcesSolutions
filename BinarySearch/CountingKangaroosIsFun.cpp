#include<bits/stdc++.h>
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

ll n;

int main()
{
	fastio;
	ll t;
	t=1;
	//scanf("%lld",&t);
	while(t--)
	{		
		scanf("%lld",&n);
		vector<ll> a(n);
		for(ll i=0;i<n;i++)
			cin>>a[i];
		sort(a.begin(),a.end());
		ll x = 0;
		for(ll i=0;i<n;i++)
			if(a[x]*2<=a[i])
				x++;
		cout<<n-min(n/2,x)<<endl;
	}
	return 0;
}
