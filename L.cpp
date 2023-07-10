#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

#define pb	push_back
#define ff	first
#define ss	second
#define all(x) x.begin(), x.end()
#define SZ(x) (int)(x).size()
#define clr(v, n) memset(v, n, sizeof(v))
#define lb lower_bound
#define ub upper_bound

#define lpv(i, v) for(int i=0;i<sz(v);++i)
#define lp(i, j, n) for(int i=(j);i<(int)(n);++i)
#define lpr(i, j, n) for(int i=(j);i>=(int)(n);--i)




const ll OO = INT_MAX;
const double EPS = (1e-7);
const int MOD = 1e9 + 7;
const char nl = '\n';
const ll MAX = 200009;

//u-d-r-l
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const ll N = 200009;



/*
vector<int>pathsNo(N, 0);
vector<vector<int>>adj(N);
vector<int>vis(N, 0);
*/

vi xes;
vector<pii> bounds;
int m, n;
void clrr() {
    bounds.clear();
    xes.clear();
    //pathsNo = vector<int>(n + 9, 0);
    //vis= vector<int>(n + 9, 0);
    //adj = vector<vector<int>>(n + 9, vector<int>());
}

bool isOddOnesNo(int  mid) {
    int pre[m+1] = {0};
    lp(i, 0, mid) {
        pre[xes[i]] = 1;
    }

    lp(i, 0, m) {
        pre[i + 1] += pre[i] ;
    }

    lp(i, 0, n) {
        auto [l, r] = bounds[i];
        //cout << (pre[r] - pre[l - 1])  << ' ' << (r - l + 1)/2 << nl;
        if ((pre[r] - pre[l - 1]) > (r - l + 1)/2 )
            return 1;
    }
    return 0;

}
void binSearch(int q) {
    int l = 1, r = q, mid = 0, ans = -1;
    while(l <= r) {
        mid = l + (r - l) / 2;

        if(isOddOnesNo(mid)) {
            //cout << mid << ':' << ' ';
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans << nl;
}
bool isNum(string s) {
    int n = s.size();
    lp(i, 0, n) {
        if(!(s[i] >= '0' && s[i] <= '9')){
            return false;
        }
    }
    return true;
}
void solve() {
    //clrr();
    
    int n;
    cin >> n;
    int x;
    ll cnt = 0;
    lp(i, 0, n) {
        cin >> x;
        if(x&1)
            ++cnt;
        
    }
    if(cnt&1) 
        cout << "Lose";
    else 
        cout << "Win";
    cout << nl;


}

int main()
{   //o:
    fast();

    int T = 1;
    cin>>T;

    while(T--){

        solve();

    }


    //goto o;
    return 0;
}
