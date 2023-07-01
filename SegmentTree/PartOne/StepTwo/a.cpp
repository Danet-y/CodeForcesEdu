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
const int N=1e5,MX=2e4+23,mod=1e9+7;
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
struct seg
{
	int suf,pref,ans,sum;
};
seg comb(seg a,seg b)
{
	seg t={max(b.suf,b.sum+a.suf),max(a.pref,a.sum+b.pref),max(max(a.ans,b.ans),a.suf+b.pref),a.sum+b.sum};
	return t;
}
vector<seg> t(4*N);

void build(int a[], int v, int tl, int tr) 
{
    if (tl == tr) 
	{
		if(a[tl]>0)
			t[v] = {a[tl],a[tl],a[tl],a[tl]};
		else
			t[v] = {0,0,0,a[tl]};
    } else 
	{
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] =comb(t[v*2],t[v*2+1]);
    }
}
void update(int v, int tl, int tr, int pos, int new_val) 
{
	if(pos>tr || pos<tl)
		return;
    if (tl == tr) 
	{
		if(new_val>0)
			t[v] = {new_val,new_val,new_val,new_val};
		else
			t[v] = {0,0,0,new_val};
    }
	else 
	{
        int tm = (tl + tr) / 2;
		update(v*2, tl, tm, pos, new_val);
		update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = comb(t[v*2],t[v*2+1]);
    }
}
int32_t main()
{
	Tof_Io;
	int n,m;
	cin >> n >> m;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	build(arr,1, 0, n-1);
	cout<< t[1].ans <<endl;
	while(m--)
	{
		int i,v;
		cin >> i >> v;
		update(1,0, n-1, i ,v);
		cout<<t[1].ans <<endl;
	}
}
