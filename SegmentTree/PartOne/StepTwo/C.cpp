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
const int N=1e6+23,MX=2e4+23,mod=1e9+7;
int fct[N],inv[N];
int pwe(int x,int y){int a=1;while(y){if(y&1)a=a*x%mod;x=x*x%mod;y/=2;}return a;}
int C(int n,int r){return r<0||n<r?0:fct[n]*inv[r]%mod*inv[n-r]%mod;}
void modplus(int &j,int y){(j+=y)>=mod && (j-=mod);}
bool isprime(int n){bool fl = 1;for (int i = 2; i <= sqrt(n)+1; i++){if(n%i==0){fl = 0;break;}}return fl;}
void printt(bool fl){if(fl==1){cout << "YES";return;}cout << "NO";}
int GCD(int a, int b) {return b?GCD(b,a%b):a;}
void rape(int &a) {if(a <0) a += 10 * mod;a %= mod;}
int LCM(int a, int b) {return a/GCD(a,b)*b;}
int lis(vector<int>& v){if (v.size() == 0) {return 0;} vector<int> tail(v.size(), 0); int szgth = 1; tail[0] = v[0]; for (int i = 1; i < v.size(); i++) {auto b = tail.begin(), e = tail.begin() + szgth; auto it = lower_bound(b, e, v[i]); if (it == tail.begin() + szgth){tail[szgth++] = v[i];}else{*it = v[i];}} return szgth;}
int MOD(int a, int b){return (a%b + b) % b;}
int sexygirl(int n){return (1ull << n);}
int cal(vector<int> arr1,vector<int> v,int sz){return memcmp(arr1.data(), v.data(), sz * sizeof(v[0])) == 0;}
int t[4*N];
int ans = -1;
void build(int a[], int v, int tl, int tr) 
{
    if (tl == tr) 
	{
		v[t] = a[tl];
    } else 
	{
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2],t[v*2+1]);
    }
}
void least(int v,int tl,int tr,int x)
{
	if(t[v]<x)
		return;
	if(ans>=0)
		return;
	if(tl==tr)
	{
		if(t[v]>=x)
		ans=tl;
		return;
	}
	int mid = (tl + tr)/2;
	least(2*v,tl,mid,x);
	least(2*v+1,mid+1,tr,x);
	return;
}
void update(int v, int tl, int tr, int pos, int new_val) 
{
	if(pos>tr || pos<tl)
		return;
    if (tl == tr) 
	{
		t[v] = new_val;
    }
	else 
	{
        int tm = (tl + tr) / 2;
		update(v*2, tl, tm, pos, new_val);
		update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2],t[v*2+1]);
    }
}

int32_t main()
{
	int n,m;
	cin >> n >> m;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	build(arr,1, 0, n-1);
	while(m--)
	{
		int q;
		cin >> q;
		if(q==1)
		{
			int i,new_val;
			cin >> i >> new_val;
			update(1,0, n-1, i ,new_val);
		}
		if(q==2)
		{
			int x;
			cin >>x;
			ans=-1;
			least(1,0,n-1,x);
			cout << ans << endl;
		}
	}
}
