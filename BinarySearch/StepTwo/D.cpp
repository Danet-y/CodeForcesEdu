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
struct asst
{
	int t, z, y;
};
 
int countMaxBalloons(int t, int z, int y, int Time)
{
	int batchTime = (z * t) + y;
	int batchCount = (Time / batchTime);
	int remTime = Time % batchTime;
	int totalBalloons = 0;
	totalBalloons += (batchCount * z);
	if (remTime != 0) {
		if (remTime / t >= z) {
			totalBalloons += z;
		}
		else {
			totalBalloons += (remTime / t);
		}
	}
	return totalBalloons;
}
 
bool isBalloonPossible(int t, int z, int y, int balloons, int Time)
{
	int batchTime = (z * t) + y;
	int batches = balloons / z;
	bool ok = (balloons % z == 0) ? 1 : 0;
	int currTime = 0;
	if (ok) {
		batches -= 1;
		currTime = (batchTime * batches) + (z * t);
	}
	else {
		currTime = (batchTime * (batches)) + ((balloons % z) * t);
	}
	return (currTime <= Time);
}
 
 
bool isPossible(asst *assistant, int n, int m, int Time)
{
	int totalBalloons = 0;
	for (int i = 0; i < n; i++) {
		int t = assistant[i].t;
		int z = assistant[i].z;
		int y = assistant[i].y;
		int lo = 0, hi = (int) 1e9;
		while (hi > lo + 1) {
			int balloons = (lo + hi) >> 1;
			if (isBalloonPossible(t, z, y, balloons, Time)) {
				lo = balloons;
			}
			else {
				hi = balloons;
			}
		}
		totalBalloons += lo;
	}
	return (totalBalloons >= m);
}
int32_t main()
{
	int m, n;
	cin >> m >> n;
	asst assistant[n];
	for (int i = 0; i < n; i++) {
		cin >> assistant[i].t >> assistant[i].z >> assistant[i].y;
	}
	int minTime = -1, maxTime = (int) 1e9;
	while (maxTime > minTime + 1) {
		int Time = (minTime + maxTime) >> 1;
		if (isPossible(assistant, n, m, Time)) {
			maxTime = Time;
		}
		else {
			minTime = Time;
		}
	}
	cout << maxTime << endl;
	int count[n];
	memset(count, 0, sizeof count);
	for (int i = 0; i < n; i++) {
		int t = assistant[i].t;
		int z = assistant[i].z;
		int y = assistant[i].y;
		count[i] = countMaxBalloons(t, z, y, maxTime);
	}
	int totalBalloons = 0;
	for (int i = 0; i < n; i++) {
		if (totalBalloons + count[i] <= m) {
			cout << count[i] << " ";
			totalBalloons += count[i];
		}
		else {
			if (totalBalloons == m) {
				cout << 0 << " ";
			}
			else {
				cout << (m - totalBalloons) << " ";
				totalBalloons = m;
			}
		}
	}
	cout << endl;
 
	return 0;
}
