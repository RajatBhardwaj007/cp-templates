/*
A company has n employees with certain salaries. Your task is to keep track of the salaries and process queries.

Input

The first input line contains two integers n and q: the number of employees and queries. The employees are numbered 1,2,…,n.

The next line has n integers p1,p2,…,pn: each employee's salary.

After this, there are q lines describing the queries. Each line has one of the following forms:
! k x: change the salary of employee k to x
? a b: count the number of employees whose salary is between a…b


*/

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

// ---------------------------------------------- Policy Based Ds ------------------------------------------------------

#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
using namespace __gnu_pbds;

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
 

//-----------------------------------------------------------paindi aa fer dhakk champion!!--------------------------------------------------------------------------------


int main() {
	ios_base::sync_with_stdio(0);
	 cin.tie(0); cout.tie(0);
	ll n,q;
	cin>>n>>q;
	
	vector<ll> v(n+1);
	ordered_set_pairs s;
	
	for(ll i=1; i<=n; i++)
	{
	    cin>>v[i];
	    s.insert({v[i],i});
	}
    
    while(q--)
    {
        char x;
        cin>>x;
        if(x=='!')
        {
            ll a,b;
            cin>>a>>b;
            //a--;
            pll p = {v[a],a};
            auto it = s.find(p);
            s.erase(it);
			v[a]=b;
            s.insert({b,a});
        }
        else
        {
            ll a,b;
            cin>>a>>b;
            cout<<s.order_of_key({b,n+1}) - s.order_of_key({a-1,n+1})<<endl;// ye dhyaan rkhna
        }
    }


	return 0;
}