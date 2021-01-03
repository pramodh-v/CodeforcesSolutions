#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans;
void solve()
{
    int n,k;
    cin>>n>>k;
    map<int,int> m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    int rep[n+1][n+1] = {0};
    for(int i=0;i<n;i++)
    {
      m.clear();
      for(int j=i;j<n;j++)
      {
        if(j==0)
          rep[i][j] = 0;
        else
          rep[i][j] = rep[i][j-1];
        if(m.count(a[j]))
        {
          if(m[a[j]]==1)
          {
            rep[i][j]++;
          }
          rep[i][j]++;
        }
        m[a[j]]++;
      }
      // for(auto i:m)
      //   cout<<i.first<<" "<<i.second<<endl;
    }
    // for(int i=0;i<n;i++)
    // {
    //   for(int j=0;j<n;j++)
    //   {
    //     cout<<rep[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
    int s = 1e9;
    int notable = 100;
    int dp[101][1001] = {0};
    for(int i=1;i<n+1;i++)
    {
      dp[1][i] = rep[0][i-1];
    }
    for(int i=1;i<=notable;i++)
    {
      dp[i][1] = 0;
    }
    for(int i=2;i<=notable;i++)
    {
      for(int j=2;j<=n;j++)
      {
        int b = 1e9;
        for(int l = 0;l<=j;l++)
        {
          b = min(b,dp[i-1][l]+rep[l][j-1]);
        }
        dp[i][j] = b;
      }
    }
  for(int x=1;x<=100;x++)
  {
    s = min(x*k+dp[x][n],s);
  }
  cout<<s<<endl;
}    
main() 
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   	solve();
   }   
   return 0;      
}