#include <bits/stdc++.h>
using namespace std;
#define Tof_Io ios_base::sync_with_stdio(false);cin.tie(0) , cout.tie(0);
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define int long long int
#define F first
#define S second
#define tagh2(j) j>>1
#define zarb2(j) j<<1
const int N=100,MX=2e4+23,mod=229939;
int dp[N][N][N];
int pwe(int j,int p) {int ret=1;for(;p;p>>=1,j=1LL *j * j%mod) if(p&1) ret=1LL  * ret  * j % mod;return ret;}
void modplus(int &j,int y){(j+=y)>=mod && (j-=mod);}
bool isprime(int n){bool fl = 1;for (int i = 2; i <= sqrt(n)+1; i++){if(n%i==0){fl = 0;break;}}return fl;}
void printt(bool fl){if(fl==1){cout << "YES";return;}cout << "NO";}
int GCD(int a, int b) {return b?GCD(b,a%b):a;}
int LCM(int a, int b) {return a/GCD(a,b)*b;}
int lis(vector<int>& v){if (v.size() == 0) {return 0;} vector<int> tail(v.size(), 0); int szgth = 1; tail[0] = v[0]; for (int i = 1; i < v.size(); i++) {auto b = tail.begin(), e = tail.begin() + szgth; auto it = lower_bound(b, e, v[i]); if (it == tail.begin() + szgth){tail[szgth++] = v[i];}else{*it = v[i];}} return szgth;}
int MOD(int a, int b){return (a%b + b) % b;}
int sexygirl(int n){return (1ull << n);}
int cal(vector<int> arr1,vector<int> v,int sz){return memcmp(arr1.data(), v.data(), sz * sizeof(v[0])) == 0;}
int ans = -1;
int check(vector<int>& arr, long double len)
{
    int pieces = 0, n = arr.size();
    for(int i = 0 ; i < n ; i++)
    {
        pieces += floor(arr[i]/len);
    }
    return pieces;
}
int bins(int n,int k)
{
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	long double low = (long double)0;
	long double high = (long double)1e9;
	long double ans , mid;
	for (int i = 0; i < 101; i++)
	{
		mid = (long double)(low+(long double)high)/(long double)2.00;
		int pieces = check(arr,mid);
		if(pieces >= k)
		{
			ans = mid;
			low = mid;
		}
		else
		{
			high = mid;
		}
	}
	cout << fixed << setprecision(20) << ans ;
	return 0;
}
int32_t main()
{
	Tof_Io
	int n,k;
	cin >> n >> k;
	bins(n,k);
}
