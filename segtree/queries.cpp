#include<bits/stdc++.h>
/*
constructor ki beech k value ha

it is basically a value 'e' the identity element such that combine(x,e) = combine(e,x) = x, here combine is the function used to combine the answers of left and right child nodes of a node to derive answer for parent node.

So for function sum: sum(x,0) = sum(0,x) = x
for function min: min(x,infinity) = min(infinity,x) = x
for function product: product(x,1) = product(1,x) = x


*/
 // ----------------------------------------- sum query k lie (0 indexed chlega)-------------------------------------------------------------
int sum(int x, int y)
{
	return x+y;
}

int main()
{
	vector<int> v={1,2,3,4}; // 0 indexed chlega. iss pr query krenge
	
	SegmentTree<int> seg(v,0,sum);
	
	cout<<seg.query(0,3)<<endl; // sum from [v[l], v[r]] 
	// output: 1+2+3+4 = 10
	
	seg.update(3,0);
	cout<<seg.query(0,3)<<endl; // sum from [v[l], v[r]] 
	// output: 1+2+3+0 = 6
}

// --------------------------------------------- range min. query k lie --------------------------------------------------------
int mini(int x, int y) // mini hi rkhna, min mt rkhna
{
	return min(x,y);
}

int main()
{
	vector<int> v={1,2,3,4}; // 0 indexed chlega. iss pr query krenge
	
	SegmentTree<int> seg(v,INT_MAX,mini);
	
	cout<<seg.query(0,3)<<endl; // sum from [v[l], v[r]] 
	// output: 1+2+3+4 = 10
	
	seg.update(3,0);
	cout<<seg.query(0,3)<<endl; // sum from [v[l], v[r]] 
	// output: 1+2+3+0 = 6
}
// -------------------khud ka data type bna kr koi query ho, usse solve krne k lie -----------------------------------------------------

/*
Question : You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.

*/
struct node
{
    int ans; int tot;
    int pref;
    int suf;
    node(){}
    node(int val){tot=ans=pref=suf=val;}
};
node combine(node x,node y)
{
    node *ptr = new node();
    ptr->ans = max(x.ans,y.ans);
    ptr->ans = max(ptr->ans,y.pref+x.suf);
    ptr->pref = max(x.tot+y.pref,x.pref);
    ptr->suf = max(y.tot+x.suf,y.suf);
    ptr->tot = x.tot+y.tot;
    return *ptr;
}
int main()
{
    int t,i,j,n,ans;
    cin>>n;
    vector<node> v(n);
    for(i=0;i<n;i++)
    {
        cin>>j;
        v[i] = node(j);
    }
    SegmentTree<node> sg(v,node(-20000),combine);
    cin>>n;
    while(n--)
    {
        cin>>i>>j;
        node as = sg.query(i-1,j-1);
        cout<<(as.ans)<<endl;
    }
    return 0;
}
 

















