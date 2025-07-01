#define MULT_TEST
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

// TYPE
using ll	=	long long;
using llu	=	unsigned long long;
using ld	=	long double;
using vi	=	vector<int>;
using vb	=	vector<bool>;
using vvb	=	vector<vb>;
using vll	=	vector<ll>;
using vvll	=	vector<vll>;
using vllu	=	vector<llu>;
using vs	=	vector<string>;
using pii	=	pair<int, int>;
using pll	=	pair<ll, ll>;
using pllu	=	pair<llu, llu>;
using edge	=	vector<list<ll>>;

// MACRO
#define sp <<" "<<
#define pb push_back
#define pf push_front
#define eb emplace_back
#define ef emplace_front
#define fi first
#define se second
#define be begin()
#define en end()

#define dbg(x) cerr << #x << ": " << (x) << endl;
#define sz(x) ((int)x.size())
#define all(x) (x).be, (x).en
#define rall(x) (x).rbegin(), (x).rend()
#define srt(x) sort(all(x))
#define rsrt(x) sort(rall(x))
#define ub(x, v) upper_bound(all(x), v)
#define lb(x, v) lower_bound(all(x), v)
#define rev(x) reverse(all(x))

// CONST
constexpr ll MOD = 1000000007;
constexpr int INF = 1<<30;
constexpr ll LINF = 1LL<<62;

// FUNC
void yes() {cout << "Yes\n";}
void no() {cout << "No\n";}
ll gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
ll addMod(ll a, ll b) {return ((a%MOD)+(b%MOD))%MOD;}
ll subMod(ll a, ll b) {return ((a%MOD)-(b%MOD)+MOD)%MOD;}
ll mulMod(ll a, ll b) {return ((a%MOD)*(b%MOD))%MOD;}
ll powMod(ll a, ll b){if(!b)return 1;ll r=powMod(a,b/2);r=mulMod(r,r);return(b%2?mulMod(a,r):r);}

//Parse
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	for (size_t i=0;i<v.size();i++) os<<v[i]<<" \n"[i+1==v.size()];
	return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
	for (auto& e : v) is>>e;
	return is;
}

//Class
struct Graph {
	ll n;
	edge e;
	Graph(ll nVert, vvll& edg, bool oneIdx = true) {
		n = nVert;
		e.resize(n);
		for (auto& p : edg) {
			ll u = p[0], v = p[1];
			if (oneIdx)
				u--, v--;
			e[u].eb(v);
			e[v].eb(u);
		}
	}
	Graph(ll nVert, ll nEdg, bool oneIdx = true) {
		vvll edg(nEdg);
		n = nVert;
		e.resize(n);
		for (int i = 0; i < nEdg; i++) {
			ll u, v;
			cin >> u >> v;
			if (oneIdx)
				u--, v--;
			e[u].eb(v);
			e[v].eb(u);
		}
	}
};
struct DiGraph {
	ll n;
	edge ch;
	edge par;
	DiGraph(ll nVert, vvll& edg, bool oneIdx = true) {
		n = nVert;
		ch.resize(n);
		par.resize(n);
		for (auto& p : edg) {
			ll u = p[0], v = p[1];
			if (oneIdx)
				u--, v--;
			ch[u].eb(v);
			par[v].eb(u);
		}
	}
	DiGraph(ll nVert, ll nEdg, bool oneIdx = true) {
		vvll edg(nEdg);
		n = nVert;
		ch.resize(n);
		par.resize(n);
		for (int i = 0; i < nEdg; i++) {
			ll u, v;
			cin >> u >> v;
			if (oneIdx)
				u--, v--;
			ch[u].eb(v);
			par[v].eb(u);
		}
	}
};
struct Dsu {
	ll n;
	vll rep;
	ll comp;
	Dsu(ll nVert, vvll& edg, bool oneIdx = true) {
		n = nVert;
		comp = n;
		rep.resize(n);
		for (int i = 0; i < n; i++)
			rep[i] = i;
		for (auto& p : edg) {
			ll u = p[0], v = p[1];
			if (oneIdx)
				u--, v--;
			unite(u, v);
		}
	}
	Dsu(ll nVert, ll nEdg, bool oneIdx = true) {
		n = nVert;
		comp = n;
		rep.resize(n);
		for (int i = 0; i < n; i++)
			rep[i] = i;
		for (int i = 0; i < nEdg; i++) {
			ll u,v;
			cin >> u >> v;
			if (oneIdx)
				u--, v--;
			unite(u, v);
		}
	}
	ll find(ll u) {return rep[u] == u ? u : rep[u] = find(rep[u]);} 
	bool isCon(ll u, ll v) {return find(u) == find(v);}
	void unite(ll u, ll v) {if (!isCon(u, v)) comp--, rep[find(u)] = find(v);}
};

//safe hashing
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
using mapll = unordered_map<ll, ll, custom_hash>;
using setll = unordered_set<ll, custom_hash>;
using idx_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;

void runTest();

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int tc = 1;
	#ifdef MULT_TEST
	cin >> tc;
	#endif
	for(ll test=0; test<tc; test++) {
		runTest();
	}
}

void runTest()
{
	ll n;
	cin >> n;
	vll a(n);
	cin >> a;
}
