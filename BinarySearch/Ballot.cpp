#include<bits/stdc++.h>
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define inf 5000005

using namespace std;

ll n,k;
ll a[inf];

ll BinarySearch(ll a[],ll n,ll k)
{
	ll l = 0,r = a[n-1];
	while(l<=r)
	{
		ll mid = (l+r)/2;
		ll cnt=0;
		for(ll i=0;i<n;i++)
		{
			if(a[i]>mid)
			{
				cnt+=(a[i]/mid);
				if(a[i]%mid>0)
					cnt++;
			}
			else
				cnt++;
		}
		if(cnt<=k)
			r = mid-1;
		else
			l = mid+1;
	}
	return l;
}
int main()
{
	fastio;
	ll t;
	t=1;
	//scanf("%lld",&t);
	while(true)
	{		
		scanf("%lld %lld",&n,&k);
		if(n==-1&&k==-1)
			break;
		for(ll i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		printf("%lld\n",BinarySearch(a,n,k));
	}	
	return 0;
}