/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1
*/

#include <iostream>
#include <string>
#include <climits>

class Solution {
public:
    int reverse(int x) {
        std::string numero_str = std::to_string(x);
        std::string res = "";

        bool negativo = (x < 0);
        int startIdx = (negativo) ? 1 : 0;

        int result = 0;

        for (int i = numero_str.length() - 1; i >= startIdx; i--) {
            res += numero_str[i];
        }

        for (int i = 0; i < res.length(); ++i) {
            if (res[i] >= '0' && res[i] <= '9') {
                int digit = res[i] - '0';

                if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7))
                    return 0;
                if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8))
                    return 0;

                result = result * 10 + digit;
            } else {
                break;
            }
        }

    return negativo ? -result : result;
    }
};

int main() {
    Solution sol;
    int res = sol.reverse(-123456789);
    std::cout << res << " ";
    return 0;
}