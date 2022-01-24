/*
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time.
Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
Output format :
Print the total possible number of ways.
*/
#include "iostream"
using namespace std;
/* Recursive */
long numberOfWays(int numberOfSteps){
    if(numberOfSteps == 1) return 1;
    if(numberOfSteps == 2) return 2;
    if(numberOfSteps == 3) return 4;
    return numberOfWays(numberOfSteps-1) + numberOfWays(numberOfSteps - 2) + numberOfWays(numberOfSteps -3);
}
/* Dynammic Programming +  Recursive */
long numberOfWays2(int numberOfSteps, long* dp){
    if(numberOfSteps == 1){
        dp[1] = 1;
        return 1;
    }
    if(numberOfSteps == 2){
        dp[2] = 2;
        return 2;
    } 
    if(numberOfSteps == 3){
        dp[3] = 4;
        return 4;
    } 
    int ans = 0;
    if(dp[numberOfSteps - 3] != -1) ans+=dp[numberOfSteps -3];
    else{
        int temp = numberOfWays2(numberOfSteps - 3,dp);
        dp[numberOfSteps - 3] = temp;
        ans+=temp;

    }
    if(dp[numberOfSteps - 2] != -1) ans+=dp[numberOfSteps -2];
    else{
        int temp = numberOfWays2(numberOfSteps - 2,dp);
        dp[numberOfSteps - 2] = temp;
        ans+=temp;
    }
    if(dp[numberOfSteps - 1] != -1) ans+=dp[numberOfSteps -1];
    else{
        int temp = numberOfWays2(numberOfSteps - 1,dp);
        dp[numberOfSteps - 1] = temp;
        ans+=temp;
    }
    dp[numberOfSteps] = ans;
    return ans;    
}
/* Iterative Dynammic Programming */
long numberOfWays3(int numberOfSteps){
    if(numberOfSteps == 1) return 1;
    if(numberOfSteps == 2) return 2;
    if(numberOfSteps == 3) return 4;
    long * dp = new long[numberOfSteps+1];
    for(int i = 0;i<=numberOfSteps;i++){
        dp[i] = -1;
    }
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4;i<numberOfSteps+1;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[numberOfSteps];
}
/* Optimal Solution */
long numberOfWays4(int numberOfSteps){
    if(numberOfSteps == 1) return 1;
    if(numberOfSteps == 2) return 2;
    if(numberOfSteps == 3) return 4;
    long first = 0;
    long second = 1;
    long third = 1;
    long ans = first + second + third;
    for(int i = 1;i<numberOfSteps;i++){
        ans = first + second + third;
        first = second;
        second = third;
        third = ans;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    // long *dp = new long[n+1];
    // for(int i = 0;i<n+1;i++){
    //     dp[i] = -1;
    // }
    // delete dp;
    // cout << numberOfWays2(n,dp) << endl;
    cout << numberOfWays4(n) << endl;

}