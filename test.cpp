#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
template<typename T>
void pr(T&v)
{
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
void solve()
{
int n,m,x;;
cin>>n>>m;
multiset<int>mst;
for(int i=0;i<n;i++)
{
    cin>>x;
    mst.insert(x);
}
int i=0;
auto m_itr=mst.begin();
while(i<(n-1)/2)
{
m_itr++;
i++;
}

 i=0;
 while(i<m)
 {
   // cout<<i<<endl;
   auto  e_itr=mst.rbegin();
   auto b_itr=mst.begin();
   auto e_ele=*e_itr,b_ele=*b_itr,m_ele=*m_itr;
   int next_m=-1;
   if(e_ele/2>m_ele)
   {
    mst.erase(mst.find(e_ele));
    mst.insert(e_ele/2);
    mst.insert(e_ele-e_ele/2);
    m_itr++;
   }
   else
   {
    if(m_itr!=mst.begin())
    {
        
        m_itr--;
        next_m=*m_itr;
        m_itr++;

    }
    if(e_ele/2<=next_m)
    {
         mst.erase(b_itr);
        mst.insert(b_ele/2);
        mst.insert(b_ele-b_ele/2);
    }
    else
    {
     mst.erase(mst.find(e_ele));
    mst.insert(e_ele/2);
    mst.insert(e_ele-e_ele/2);

    }
    // else if(b_ele>1)
    // {
       
    // }
    // else
    // {
    // mst.erase(mst.find(e_ele));
    // mst.insert(e_ele/2);
    // mst.insert(e_ele-e_ele/2);
    // }
        m_itr--;

   }
    i++;
 }

cout<<*m_itr<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    {      solve();  }

}
