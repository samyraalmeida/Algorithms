// Persistent Segment Tree
// Build: O(n)
// K-th: O(log n)
// Query: O(log n)
// Update: O(log n)
// Memory(n + q log n)
// By Samyra Vitória

#include <bits/stdc++.h>
     
using namespace std;
     
const int maxn=1e5+10;
    
struct Node
{
    Node *l, *r;  int v;
   	
	Node(){
   		l = r = NULL;
   		v = 0;
   	}
};

Node *version[maxn];
     
int n, q;
    
void build(Node *node, int l, int r)
{     
  	if(l == r) return;
  
   	int mid = (l + r) >> 1;
    
   	node->l = new Node(); node->r = new Node();
    
   	build(node->l, l, mid); build(node->r, mid+1, r);
    
   	node->v = node->l->v + node->r->v;
}
    
void upd(Node *prev, Node *node, int l, int r, int pos, int v)
{    
   	if(l == r)
	{
   		node->v = v;  return;
   	}

   	int mid = (l+r) >> 1;
    
   	if(pos <= mid)
	{
   		node->r = prev->r;
    
   		if(node->l == NULL) node->l = new Node();
    
   		upd(prev->l, node->l, l, mid, pos, v);
   	}
	else
	{
    	node->l = prev->l;
    
   		if(node->r == NULL) node->r = new Node();
   
   		upd(prev->r, node->r, mid+1, r, pos, v);
   	}
     
  	node->v = node->l->v + node->r->v;
}

int query(Node *node, int l, int r, int a, int b)
{
	if(r < a || l > b) return 0;

	if(a <= l && b <= r) return node->v;

	int mid = (l + r) >> 1;
	int p1 = 0, p2 = 0;
	
	if(b <= mid) 	  return p1 = query(node->l, l, mid, a, b);
	else if(a > mid)  return p2 = query(node->r, mid+1, r, a, b);
	
	return (p1 + p2);
}

int kth(Node *prev, Node *node, int l, int r, int k)
{    	
   	if(l == r) return l;

   	int mid = (l + r) >> 1, x = (node->l->v - prev->l->v);
   	
   	if(x >= k) 	return kth(prev->l, node->l, l, mid, k);
  	else 		return kth(prev->r, node->r, mid + 1, r, k - x);
}
     
int main()
{   
    // Read the input 

   	version[0] = new Node();
    
   	build(version[0], 1, n);
    	
   	// Remember that for each update you need to start the root of the seg
   	// for i-th update: version[i] = new Node();

   	return 0;
}