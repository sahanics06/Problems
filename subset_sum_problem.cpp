/*
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum
Example 1:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function isSubsetSum() which takes the array arr[], 
its size N and an integer sum as input parameters and returns boolean value true if there exists a subset with given sum and false otherwise.
The driver code itself prints 1, if returned value is true and prints 0 if returned value is false.
 

Expected Time Complexity: O(sum*N)
Expected Auxiliary Space: O(sum*N)
 

Constraints:
1 <= N <= 100
1<= arr[i] <= 100
1<= sum <= 105
  
  */



// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
       int t[N+1][sum+1];
       for(int i=0;i<N+1;i++)
       {
           for(int j=0;j<sum+1;j++)
           {
               if(i==0)
               t[i][j]=false;
               if(j==0)
               t[i][j]=true;
           }
       }
       for(int i=1;i<N+1;i++)
       {
           for(int j=1;j<sum+1;j++)
           {
               if(arr[i-1] < sum)
               {
                   t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
               }
               else
               {
                   t[i][j]= t[i-1][j];
               }
           }
       }
       return t[N][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
