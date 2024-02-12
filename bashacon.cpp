#include<bits/stdc++.h>
using namespace std;
bool customComparator(pair<int, int>& a,pair<int, int>& b) {
    return a.second > b.second;
}
int main()
{
    long long int t,n,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        pair<int,int>p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].first>>p[i].second;
        ans=p[0].first;
        sort(p+1,p+n,customComparator);
        int x=p[0].first;
        int y=p[1].first;
        int w=p[0].second;
        int z=p[1].second;
        if(x<=y)
        {
            if(x<y)
                cout<<-1;
            else
            {
                if(w<=z)
                    cout<<-1;
                else
                    cout<<x;
            }

        }
        else
        {
                    cout<<x;

        }
        cout<<endl;
    }
}

