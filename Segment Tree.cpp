
#include<bits/stdc++.h>
using namespace std ;

#define ll long long

struct tree
{
    vector<ll> t ;

    tree(int a[] , int low , int n)
    {
        t = vector<ll> (4*n + 4 , 0) ;
        build(a,1,low,n) ;
    }

    void build(int a[] , int node , int low , int high)
    {
        if(low==high) t[node] = a[low] ;
        else
        {
            int mid = (low+high)>>1 , left = node<<1 , right = left|1 ;
            build(a,left,low,mid) ;
            build(a,right,mid+1,high) ;
            t[node] = t[left] + t[right] ;
        }
    }

    void update(int node , int low , int high , int ind , ll val)
    {
        if(high<ind ||low>ind) return ;

        if(low==high && high==ind)
        {
            t[node] = val ;
            return ;
        }

        int mid = (low+high)>>1 , left = node<<1 , right = left|1 ;
        update(left,low,mid,ind,val) ;
        update(right,mid+1,high,ind,val) ;
        t[node] = t[left] + t[right] ;
    }

    ll sum(int node , int low , int high , int l , int r)
    {
        if(l>r) return 0 ;
        if(l>high || r<low) return 0 ;
        if(l<=low && high<=r) return t[node] ;
        int mid = (low+high)>>1 , left = node<<1 , right = left|1 ;
        return sum(left,low,mid,l,r) + sum(right,mid+1,high,l,r) ;
    }
} ;
