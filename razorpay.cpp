// sum=0, count=0;


// sum+=coins[i]
// count++;
// mini
// if(sum==amount){
//     count<mini
//     mini
// }


// int mini=INT_MAX;
#include<iostream>
#include<vector>
using namespace std;

int solve(int sum, vector<int> coins, int amount, vector<int> &dp){
    if(sum==0){
        return 0;
    }
    if(sum<0)  return -1;
    if(dp[sum]!=-1)  return dp[sum];
    int mini=INT_MAX;
    for(int c:coins){
        int curr=solve(sum-c, coins, amount, dp);
        if(curr!=-1)
            mini=min(mini, 1+curr);
    }
    if(mini==INT_MAX)   return dp[sum]=-1;
    dp[sum]=mini;
    return dp[sum];
}

int minimumCoins(vector<int> coins, int amount){
    vector<int> dp(amount+1, -1);
    int mini=solve(amount, coins, amount, dp);
    
    if(dp[amount]==INT_MAX )   return -1;
    else return dp[amount];
}

int main(){
    int n;
    cin>>n;
    int amount;
    cin>>amount;
    vector<int> a(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    cout<<minimumCoins(a, amount)<<endl;
}

// dp -1 -1 -1 -1
// 0
// 5 
//     5+5
//     5+7 

//     5+2
//     5+8