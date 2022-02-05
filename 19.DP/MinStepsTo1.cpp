/* 
Reduce a given number n to 1 where 3 operations are allowed
1. n/3 if(n%3 == 0 )
2. n/2 if(n%2 == 0 )
3. n-1
Everyone one operation is counted as 1 step.
*/
#include "iostream"
#include "math.h"
#include "vector"
using namespace std;
// Brute Force :-
int minSteps(int n){
    if(n == 1 || n == 2 || n ==3) return 1;
    int ans1 = n;
    if(n%3 == 0){
        ans1 = minSteps(n/3);
    }
    int ans2 = n;
    if(n%2 == 0){
        ans2 = minSteps(n/2);
    }
    int ans3 = minSteps(n-1);
    return min(ans1,min(ans2,ans3))+1;
}
// Memoization:-
int minSteps(int n, int * dp){
    if(n==1 || n == 2 || n==3) return 1;
    if(dp[n] != -1) return dp[n];
    int ans1 = n;
    if(n%3 == 0){
        if(dp[n/3]!=-1){
            ans1 = dp[n/3];
        }else{
            ans1 = minSteps(n/3,dp);
            dp[n/3] = ans1;
        }
    }
    int ans2 = n;
    if(n%2 == 0){
        if(dp[n/2] != -1){
            ans2 = dp[n/2];
        }else{
            ans2 = minSteps(n/2,dp);
            dp[n/2] = ans2;
        }
    }
    int ans3 = n;
    if(dp[n-1]!=-1){
        ans3 = dp[n-1];
    }else{
        ans3 = minSteps(n-1,dp);
        dp[n-1] = ans3;
    }
    int ans = min(ans1,min(ans2,ans3))+1;
    dp[n] = ans;
    return ans;
}
// Iterative DP:- (Best Solution)
int minStepsto1(int n){
    int *dp = new int[n+1];
    for(int i = 0;i<=n;i++){
        dp[i] = -1;
    }
    dp[0] = dp[1] = dp[2] = dp[3] = 1;
    for(int i = 4;i<=n;i++){
        int ans1 = i%3 == 0 ? dp[i/3] : n;
        int ans2 = i%2 == 0 ? dp[i/2] : n;
        int ans3 = dp[i-1];
        dp[i] = min(ans1,min(ans2,ans3))+1;
    }
    return dp[n];
}

int main(){
    int n = 100000000;
    cout << minStepsto1(n)<<endl;
}