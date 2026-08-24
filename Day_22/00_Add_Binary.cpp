// Day 22 — Binary(Bit) Manipulation
// Problem: Add Binary
//
// My notes:
// Pattern: Binary Addition / Two Pointers
// Logic: Start from the rightmost bits and add them with carry
// sum = carry + bitA + bitB
// Current bit = sum % 2
// Carry = sum / 2
// Use i and j to traverse both strings from right to left
// Continue while either string has bits left or carry exists
// Reverse the result because bits are added from right to left
// Convert char to integer using: s[i] - '0'
// Convert digit back to char using: digit + '0'
// Time: O(max(n,m))
// Space: O(max(n,m)) for the output

class Solution {
public:
    string addBinary(string a, string b) {
        string out = "";

        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';
          
            out.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        reverse(out.begin(), out.end());
        return out;
    }
};
