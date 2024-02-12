//1 based indexing
// max W weight min V volume => print maximum price.
// print the items that were taken to create maximum price.
#include<bits/stdc++.h>
using namespace std;
int dp[100][100][100];
int wara[100];
int vara[100];
int para[100];
int parent[100][100][300];
int actVol;

int fun(int i , int w , int v){
    if(i <= 0 || w <= 0){
        if(v >= actVol)return 0; //reachable
        return INT_MIN; //not reachable
    }
    if(dp[i][w][v] != -1)return dp[i][w][v];
    int &dd = dp[i][w][v];
    int &pd = parent[i][w][v];
    if(w >= wara[i]){

        int one = fun(i - 1 , w - wara[i] , v  + vara[i]); //we have to check first, if the state is reacable.
        if(one != INT_MIN)one += para[i]; // if yes, we add our value, else it remains as INT_MIN which is unreachable

        int two = fun(i - 1 , w , v);
        //parent[i][w][v] means where we have to go next to achieve the state [i][w][v]
        //we will construct it such a way that parent[i][w][v] is 'i' only if [i][w][v] is reachable using 'i'

        if(one >= two && one != INT_MIN)pd = i;    // this means we are taking 'i' to construct this state.

        return dp[i][w][v] = max(one  , two);

    }

    return dp[i][w][v] = fun(i - 1 , w , v);


}
int main(){
    memset(dp , -1 , sizeof dp);
    int n;cin>>n;
    for(int i = 1 ; i <= n; i++){
        cin>>wara[i]>>para[i]>>vara[i];
    }
    int W , V;cin>>W>>V;
    actVol = V;
    int price = fun(n , W , 0);
    V = 0;
    if(price == INT_MIN)cout<<"NOT Reachable"<<endl;
    else{
        cout<<"PRICE: "<<price<<endl;
        int cur = n;
        cout<<"ITEMS: ";
        while(cur){
            if(cur == parent[cur][W][V]){
                cout<<cur<<" ";
                W -= wara[cur];
                V += vara[cur];
            }
            cur--;
        }
    }

}

/*
5
1 10 4
2 11 3
3 5 7
5 12 9
7 9 20
10 20
*/
#include<bits/stdc++.h>
using namespace std;
int min_vol ;
int ks(int ind , int w  , int v , vector<int> &wt , vector<int> &val , vector<int>&vol , vector<vector<vector<int>>>&dp ){

    if(ind==0){
        if(wt[0] <= w && (v > min_vol || vol[0]>min_vol)) return val[0];
        else return 0 ;
    }
//    if(ind<0|| w==0){
//            if(v>=min_vol) return 0 ;
//        return INT_MIN ;
//    }

    //if(dp[ind][w][v]!=-1) return dp[ind][w][v] ;
    int notTake =ks(ind-1 , w , v , wt , val , vol , dp) ;
    int take = INT_MIN ;
    if(wt[ind]<=w) take = val[ind] + ks(ind-1, w-wt[ind],v + vol[ind] , wt , val , vol , dp);
    return  max(take , notTake) ;


}


int main(){
    int n ; cin>>n ;
    vector<int> wt(n) , val(n) , vol(n) ;
    for(int i = 0 ; i < n ;i++){
        cin>>wt[i]>>val[i]>>vol[i] ;
    }
    int w , v ; cin>>w>>v ;
    min_vol = v ;
    cout<<endl;
    vector<vector<vector<int> > > dp(n+1 , vector<vector<int> >(n+1 , vector<int>(n+1 , -1)));
    cout<<ks(n-1 , w , 0, wt , val , vol , dp) ;
//    for(int i = 0 ; i <= n ; i++){
//        for(int j = 0 ; j <= w ; j++){
//            for(int k = 0 ; k <= v ; k++){
//                cout<<dp[i][j][k]<<" " ;
//            }
//            cout<<endl;
//        }
//        cout<<endl;
//    }


}
