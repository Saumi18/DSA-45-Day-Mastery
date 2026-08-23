// Topic — Game Theory / String
// Problem: Sum Game(1927)
//
// My notes:
// Pattern: Mathematical Game Theory / Greedy
// Alice and Bob can choose any '?' and replace it with a digit from 0-9
// First calculate the known digit sums of both halves
// Also count '?' in each half
//
// If total number of '?' is odd:
// Alice gets the last move and can always force the sums to be unequal
//
// If total number of '?' is even:
// Bob can force equality only when the existing sum difference
// can be exactly compensated by the '?'s
// Each pair of '?' can create a maximum difference of 9
//
// Condition:
// aliceSum - bobSum != 9 * (bobQ - aliceQ) / 2
//
// Time: O(n) because we scan the string once
// Space: O(1) because only a few variables are used

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int aliceSum = 0, bobSum = 0;
        int aliceQ = 0, bobQ = 0;
        // Calculate known sums and '?' counts
        // for both halves
        for (int i = 0; i < n / 2; i++) {
            // Bob's half
            if (num[n - i - 1] != '?')
                bobSum += num[n - i - 1] - '0';
            else
                bobQ++;
            // Alice's half
            if (num[i] != '?')
                aliceSum += num[i] - '0';
            else
                aliceQ++;
        }
        // Odd number of '?' means Alice gets the last move
        if ((aliceQ + bobQ) % 2 == 1)
            return true;
        // Bob can force equality only if the difference
        // can be exactly compensated
        return aliceSum - bobSum != 9 * (bobQ - aliceQ) / 2;
    }
};
