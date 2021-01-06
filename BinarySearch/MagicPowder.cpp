#include<bits/stdc++.h>
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define inf 200005
#define ff(i,a,b) for(ll i=a;i<=b;i++)
#define fr(i,a,b) for(ll i=b;i>=a;i--)

using namespace std;

ll n,k;
ll a[inf];
ll b[inf];

bool can(ll mid)
{
	ll x=0;
	ff(i,0,n-1)
	{
		if(a[i]*mid>=b[i])
			x+=a[i]*mid-b[i];
		if(x>k)
			return false;
	}
	//cout<<x<<endl;
	return true;
}
int main()
{
	fastio;
	ll t;
	t=1;
	//scanf("%lld",&t);
	while(t--)
	{		
		scanf("%lld %lld",&n,&k);
		ff(i,0,n-1)
			scanf("%lld",&a[i]);
		ff(i,0,n-1)
			scanf("%lld",&b[i]);		
	}
	ll l = 0;
	ll r = 2000000000;
	while(l<r)
	{
		ll mid = (l+r+1)/2;
		//cout<<l<<" "<<r<<" "<<mid<<endl;
		if(can(mid))
			l = mid;
		else
			r = mid-1;
	}
	cout<<l<<endl;
	return 0;
}
