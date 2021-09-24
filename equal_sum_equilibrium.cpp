/*
Given an array Arr of length N. Determine if there exists an element in the array such that the sum of the elements on its left is equal to the sum of the elements on its right. If there are no elements to the left/right, then the sum is considered to be zero. 
Formally, find an i, such that, Arr1 + Arr2 ... Arri-1 = Arri+1 + Arri+2 ... ArrN.

Example 1:

Input:
N = 4
Arr[] = {1, 2, 3, 3}
Output: YES
Explanation: Consider i = 3, for [1, 2] 
sum is 3 and for [3] sum is also 3.
Example 2:

Input:
N = 2
Arr[] = {1, 5}
Output: NO
Explanation: No such index present.
Your Task:
Complete the function equilibrium() which takes array arr and size n, as input parameters and returns a string representing the answer(YES or NO). You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ N ≤ 105 
1 ≤ Arr[i] ≤ 106

*/

// { Driver Code Starts
// Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
// User function Template for C

char* equilibrium(int* arr, int n) {
    int s=0,l=0,r=0;
    for(int i=0;i<n;i++)
    r= r+arr[i];
    for(int i=0;i<n;i++)
    {
        if(l==r-arr[i])
        return "YES";
        l=l+arr[i];
        r=r-arr[i];
    }
    return "NO";
}


// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, i;
        scanf("%d", &n);
        int a[n];
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        char *ans;
        ans = equilibrium(a, n);
        printf("%s \n", ans);
    }
    return 0;
}  // } Driver Code Ends
