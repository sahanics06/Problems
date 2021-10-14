/*
Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.
Your Task:
Complete the function search() which takes two strings pat, txt, as input parameters and returns an integer denoting the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(26) or O(256)

Constraints:
1 <= |pat| <= |txt| <= 105
Both string contains lowercase english letters.

*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int ans=0;
	    int k=pat.size();
	    unordered_map <char, int> m;
        for(auto i: pat)
            m[i]++;
	    int j=0,i=0;
	    int count =m.size();
	    while(j<txt.size())
	    {
	        if(m.find(txt[j])!=m.end())
                {
                    m[txt[j]]--;
                	
                    if(m[txt[j]]==0)
                        count--;
                }
	        if(j-i+1<k)
	        {
	           
	            j++;
	        }
	        else if(j-i+1==k)
	        {
	            if(count==0)
	            {
	                ans++;
	            }
	        
	        if(m.find(txt[i])!=m.end())
	        {
	            m[txt[i]]++;
	        
	        if(m[txt[i]]==1)
	        count++;
	        }
	        i++;
	        j++;
	        }
	    }
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
