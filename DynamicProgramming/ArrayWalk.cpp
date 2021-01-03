#include<bits/stdc++.h>
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

ll n,k,z;
ll dp[1000000][6];
ll helper(vector<ll>&a,ll i,ll k,ll z)
{
	if(k==0||i>=n||i<0)
		return 0;
	if(dp[i][z]!=-1)
		return dp[i][z];
	ll x = a[i],sum=0;
	if(i<n)
		sum = max(sum,x+helper(a,i+1,k-1,z));
	if(i>=0&&z>0)
		sum = max(sum,x+helper(a,i-1,k-1,z-1));
	return dp[i][z] = sum;
}
void solve()
{
	cin>>n>>k>>z;
	vector<ll> a(n);
	memset(dp,-1,sizeof(dp));
	for(ll i=0;i<n;i++)
		cin>>a[i];
	cout<<helper(a,1,k,z)+a[0]<<endl;
}
int main()
{
	fastio;
	ll t;
	//t=1;
	cin>>t;
	while(t--)
	{		
		solve();
	}
}
