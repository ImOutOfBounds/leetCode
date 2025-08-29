/*
Given an integer x, return true if x is a palindrome, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
 
*/




#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string currentStr = "";
        string finalStr = "";
        int i = 0;
        std::string s = std::to_string(x);

        while (i <= s.length() - 1){
            currentStr = s[i] + currentStr;  
            finalStr = currentStr;
            i++;
        }

        return finalStr == s;
    }
};

int main() {
    Solution sol;
    bool res = sol.isPalindrome(121);
    std::cout << res << " ";
    return 0;
}
