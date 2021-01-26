#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
using namespace __gnu_pbds;
using namespace std;

#define all(x) (x).begin(),(x).end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define ull unsigned long long
#define ld long double
 #define printd(x) cout << fixed << setprecision(10) << x  // printd(0.5)<<endl; la skte ho. points k baad itne chahie, utna uski value
//#define mod 1000000007
#define EULER 2.7182818284
#define INF 1000000000
 
#define pb push_back
#define ins insert
#define IT iterator
#define PQ priority_queue
#define min_heap priority_queue<ll,vector<ll>,greater<ll>>
#define max_heap priority_queue<ll>
 
#define fi first
#define se second
#define maxe max_element
#define mine min_element
#define er erase
#define lb lower_bound
#define ub upper_bound
 
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpll vector<pair<ll,ll>>
//#define unordered_map ump 
 
#define mem(v,i) memset(v,i,sizeof(v)) // v is array. To set all elements to 0 or -1 only. mem(arr,0);
 
 
#define fo(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define bs bitset
#define bpc(a) __builtin_popcount(a)
 

ll max(ll a,ll b)
{
    if(a>b)return a;return b;
}
ll min(ll a,ll b)
{
    if(a<b)return a;return b;
}
ll msb(ll n)
{    
    ll ans;
    for(ll i=31; i>=0; i--)
     if((1LL<<i)&(n))
       {ans=i;
       break;}
     return ans;  
}

// A hash function used to hash a pair of any kind 
// declaration yaad rkhna 
// unordered_map<pll, int, hash_pair> mp;
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 



// ---------------------------------------------- Policy Based Ds ------------------------------------------------------

#define ordered_set        tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>  // object declared as " ordered_set obj;"
#define ordered_set_pairs  tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update>  // for pair of integers
/*
Additional functions in the ordered set other than the set
Along with the previous operations of the set, it supports two main important operations
1. find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
 Example: Let us assume we have a set s : {1, 5, 6, 17, 88}, then =>      *(s.find_by_order(2)) : 3rd element in the set i.e. 6 
 Note: if not present, it will "return n"
 
2.order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
Let us assume we have a set s : {1, 5, 6, 17, 88}, then           =>      s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
NOTE :As the set contains only UNIQUE elements,so to perform the operations on an array having repeated elements we can take the KEY as a pair of elements instead
of integer in which the first element is our required element of the array and only the second element of the pair must be unique so that the whole pair is unique.
i.e ordered_set_pairs   and elements are {a[i],i}
*/
 
 //---------------------------------------------------------------------------------------------------------------

// size of array and mod(in general)

const int N = 300500;
const int mod = 1000000007;
//const int mod = 998244353;
ll fact[N];
ll invFact[N];

// -----------------power(a,b)%mod -------------
ll fast_pow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = (a * a) % mod;
            p /= 2;
        } else {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}


 //------------------- nCr % mod  and fact[i] ------------------------------- 


// Now fact[i] stores factorial(n) % mod;
// and invFact[i] stores modulo_inverse(b) i.e, power(b,mod-2)

void pre()
{
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invFact[i] = fast_pow(fact[i], mod - 2);
    }
}
ll C(int n, int k) {
    if (k > n) {
        return 0;
    }
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}

ll modInverse( ll n) 
{ 
    return fast_pow(n, mod - 2); 
} 
//------------------------------------------------- Number theory----------------------------------------
vector<ll>primes;
void sieve(ll n)// n mtlb jaha tak chaiye 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    for (ll p=2; p<=n; p++) 
       if (prime[p]) 
            primes.pb(p); 
} 

vector<pair<int,int>> find_exponents(int n) // like p = 2^p1 * 3^p2....
{
	vector<pair<int,int>>exp; // prime no. and it's frequency
	for(int i=2; i<=n; i++)
	{
		if(n%i==0)
		{
			int cnt=0;
			while(n%i==0)
			{
				cnt++;
				n/=i;
			}
			exp.push_back({i,cnt});
		}
	}
	
	if(n!=1)
	exp.push_back({n,1});
    return exp;

}
// ---------------------------------BIT(1 index hi lena) ----------------------------------------
 
 // jb object create kro to main mai: BIT bit(1e5+10);     
struct BIT{
    vector<long long> nums;
    BIT(int size) : nums(size){}
    long long lowbit(long long x) { return x & -x; }
    void update(long long x, long long cnt){
        while (x < nums.size()) {
            nums[x] += cnt;
            x += lowbit(x);
        }
    }
    
    void range_update(long long l, long long r, long long val) // But point update query " bit.query(x, y-v[i]) for updating"
    {
        update(l,val);
        update(r+1,-val);
    }
	
    // sum query k lie, bit.query(r)-bit.query(l-1)
    long long query(int x) {
        long long sum = 0;
        if(x == 0) return 0;
        while(x > 0) {
            sum += nums[x];
            x -= lowbit(x);
        }
        return sum;
    }
};


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

vector<ll>adj[100001], rev[100001];
bool vis[100001],recur[100001];
void init(ll n)
{
    for(ll i=0; i<=n; i++)
    {
        adj[i].clear();
        rev[i].clear();
        vis[i]=false;
        recur[i]=false;
    }
}




//-----------------------------------------------------------paindi aa fer dhakk champion!!--------------------------------------------------------------------------------

int main() {
	ios_base::sync_with_stdio(0);
	 cin.tie(0); cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
        cin>>n;
	}
    


	return 0;
}
