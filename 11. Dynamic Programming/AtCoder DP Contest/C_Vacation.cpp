#include  <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define vi vector<int>
#define mod 1000000007
#define all(x) (x).begin(),(x).end()
#define endl '\n'
#define CY cout << "YES" << endl
#define CN cout << "NO" << endl
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void __print(int x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif



void solve()
{
    int n; cin >> n;
    int v[n][3];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> v[i][j];
        }
    }
    int dp[n][3];
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];

    for(int i = 1; i < n; i++){
        dp[i][0] = v[i][0] + max(dp[i - 1][1], dp[i - 1][2]);   // A today => B or C yesterday  
        dp[i][1] = v[i][1] + max(dp[i - 1][0], dp[i - 1][2]);   // B today => A or C yesterday
        dp[i][2] = v[i][2] + max(dp[i - 1][1], dp[i - 1][0]);   // C today => B or A yesterday
    }
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}