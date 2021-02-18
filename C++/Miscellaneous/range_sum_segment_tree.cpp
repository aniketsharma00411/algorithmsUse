// Point update and range query using segment tree

#include<bits/stdc++.h>
using namespace std;
#define N 100005

// Vector to store segment tree values
vector<int> st(N);

// Building the segment tree using the given vector v
void build_st(int node, int beg, int end, vector<int> v)
{
	if(beg == end)
	{
		st[node] = v[beg];
		return;
	}
	int mid = beg + (end - beg) / 2;
	build_st(2*node+1, beg, mid, v);
	build_st(2*node+2, mid + 1, end, v);
	st[node] = st[2*node+1] + st[2*node+2];
}

// Updating the element at index pos to value x
void update(int node, int beg, int end, int pos, int x)
{
	if(beg == end)
	{
		st[node] = x;
		return;
	}
	int mid = beg + (end-beg)/2;
	if(pos<=mid)
		update(2*node+1,beg,mid,pos,x);
	else
		update(2*node+2,mid+1,end,pos,x);
	st[node] = st[2*node+1] + st[2*node+2];
}

// Range query to sum the elements present between ql to qr
int query(int node, int beg, int end, int ql, int qr)
{
	if(beg>qr || end<ql)
		return 0;
	if(beg>=ql && end<=qr)
		return st[node];
	int mid = beg + (end-beg)/2;
	return query(2*node+1,beg,mid,ql,qr) + query(2*node+2,mid+1,end,ql,qr);
}

int main() 
{
	// Input
	vector<int> v {1,2,3,4,5};

	int n = (int)v.size();
	build_st(0,0,n-1,v);						// Building the segment tree
	cout<<query(0,0,n-1,0,n-1)<<"\n";			// [1,2,3,4,5]   Output = 15
	update(0,0,n-1,1,10);						// [1,10,3,4,5]
	cout<<query(0,0,n-1,0,n-1)<<"\n";			// [1,10,3,4,5]  Output = 23
	return 0;

}