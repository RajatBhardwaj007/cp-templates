#include<bits/stdc++.h>
using namespace std;
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
#define FORl(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORN(i,n) for(int i=(0);i<(n);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
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


 //------------------- nCr % N------------------------------- 


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
//-------------------------------------------------
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
#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H
#define left(i) (2*i + 1)
#define right(i) (2*i + 2)
#define parent(i) ((i-1)/2)
#include <vector>

template<class T>
class SegmentTree
{
    public:
        //tree constructors.
        SegmentTree(std::vector<T> data, T value, T (*combine)(T obj1, T obj2));
        SegmentTree(T ar[], int n, T value, T (*combine)(T obj1, T obj2));
        
        //query the range l to r, 0 based array indexing.
        T query(int l, int r);
        
        //update the element at index idx to val.
        void update(int idx, T val);
        ///TODO lazy propagation
    private:
        //represents the segment tree.
        T *tree;
    
        //builds the segment tree.
        void buildTree(std::vector<T> data);
        
        //size of the segment tree array.
        int segTreeSize;
    
        //extra nodes must be added to array to make its size a power of 2
        //this is the value to be filled for the those nodes.
        T valueForExtraNodes;
    
        //specifies how to combine child node results to form parent node result.
        T (*combine)(T obj1, T obj2);
    
        //used to calculate the size of array needed to store the tree.
        int calculateSize(int n);
    
        //helps to solve a range query.
        T queryHelper(int l,int r, int st, int ed, int node);
};

template<class T> SegmentTree<T>::SegmentTree(std::vector<T> data,
                                                T value, T (*combine)(T obj1, T obj2))
{
   this->combine = combine;
   valueForExtraNodes = value;
   segTreeSize = calculateSize(data.size());
   buildTree(data);
}

template<class T> SegmentTree<T>::SegmentTree(T ar[], int n,
                                            T value, T (*combine)(T obj1, T obj2))
{
   this->combine = combine;
   valueForExtraNodes = value;
   segTreeSize = calculateSize(n);

   std::vector<T> data;
   for(int i = 0; i < n; i++)
         data.push_back(ar[i]);

   buildTree(data);
}


template<class T> int SegmentTree<T>::calculateSize(int n)
{
    int pow2 = 1;
    while( pow2 < n)
    {
        pow2 = pow2 << 1;
    }
    return 2*pow2 - 1;
}

template<class T> T SegmentTree<T>::query(int l, int r)
{
    int st = 0, ed = segTreeSize/2;
    return queryHelper(l, r, st, ed, 0);
}

template<class T> T SegmentTree<T>::queryHelper(int l,int r, int st, int ed, int node)
{
    if( (r < st) || (l > ed) || (l > r) )
        return valueForExtraNodes;
    if(st >= l && ed <= r)
        return tree[node];
    T leftVal = queryHelper(l, r, st, (st + ed)/2, left(node));
    T rightVal = queryHelper(l, r, (st+ed)/2 + 1, ed, right(node));
    return combine(leftVal, rightVal);
}

template<class T> void SegmentTree<T>::buildTree(std::vector<T> data)
{
   int n = data.size();
   tree = new T[segTreeSize];
   int extraNodes = (segTreeSize/2 + 1) - n;
   for(int i = segTreeSize - 1; i >= 0; i--)
   {
       if(extraNodes>0)
           {
               tree[i] = valueForExtraNodes;
               extraNodes--;
           }
       else if(n>0)
           {
               tree[i] = data[n-1];
               n--;
           }
       else
           tree[i] = combine(tree[left(i)], tree[right(i)]);
   }
}

template<class T> void SegmentTree<T>::update(int idx, T val)
{
    int segTreeIdx = (segTreeSize/2) + idx;
    tree[segTreeIdx] = val;
    while(parent(segTreeIdx) >= 0)
    {
        segTreeIdx = parent(segTreeIdx);
        if(right(segTreeIdx) < segTreeSize)
          tree[segTreeIdx] = combine(tree[left(segTreeIdx)], tree[right(segTreeIdx)]);
        if(segTreeIdx == 0)
            break;
    }
}

#endif 

ll maxi(ll x, ll y)
{
    return max(x,y);
}

int main() {
	ios_base::sync_with_stdio(0);
	 cin.tie(0); cout.tie(0);
	ll n,m;
	cin>>n>>m;
	
	vll v(n);
	fo(i,0,n-1)
	   cin>>v[i];
	
	SegmentTree<ll> seg(v,INT_MIN,maxi);
	
	while(m--)
	{
	    ll x;
	    cin>>x; // v mai sabse left mai pehla v[i] jiska value>=x
	    int l=0, r=n-1, pos=n;
	    
	    while(l<=r) // pos will  store basically lower bound
	    {
	        int mid = (l+r)/2;
	        
	        if(seg.query(l,mid)>=x)
	        {
	            pos = min(pos,mid);
	            r=mid-1;
	        }
	        else
	        {
	            l=mid+1;
	        }
	    }
	    
	    if(pos<n)
	    {
	        cout<<pos+1<<" ";
	        seg.update(pos,v[pos]-x);
	        v[pos]=v[pos]-x;
	    }
	    else
	    cout<<0<<" ";
	    
	}
	   
    


	return 0;
}