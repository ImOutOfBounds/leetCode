/*
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        std::string r = "";
        int biggestStr = 0;

        for (char c : s){
            size_t pos = r.find(c);
            if (pos != std::string::npos) {
                r = r.substr(pos + 1);
            }  
            r += c;
            if (r.size() > biggestStr){
                biggestStr = r.size();
            }
            
            
        }

        return biggestStr;
    }
};

int main() {
    Solution sol;
    int res = sol.lengthOfLongestSubstring("abcd");
    std::cout << res << " ";
    return 0;
}
