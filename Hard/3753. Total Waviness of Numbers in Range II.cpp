You are given two integers num1 and num2 representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:

A digit is a peak if it is strictly greater than both of its immediate neighbors.
A digit is a valley if it is strictly less than both of its immediate neighbors.
The first and last digits of a number cannot be peaks or valleys.
Any number with fewer than 3 digits has a waviness of 0.
Return the total sum of waviness for all numbers in the range [num1, num2].
 

Example 1:

Input: num1 = 120, num2 = 130

Output: 3

Explanation:

In the range [120, 130]:

120: middle digit 2 is a peak, waviness = 1.
121: middle digit 2 is a peak, waviness = 1.
130: middle digit 3 is a peak, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.

Example 2:

Input: num1 = 198, num2 = 202

Output: 3

Explanation:

In the range [198, 202]:

198: middle digit 9 is a peak, waviness = 1.
201: middle digit 0 is a valley, waviness = 1.
202: middle digit 0 is a valley, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.

Example 3:

Input: num1 = 4848, num2 = 4848

Output: 2

Explanation:

Number 4848: the second digit 8 is a peak, and the third digit 4 is a valley, giving a waviness of 2.

 

Constraints:

1 <= num1 <= num2 <= 1015
 
 
​​​​//solution
 //Approach-1 (Digit DP - Counting waviness contribution per position)
//T.C : O(n * 10 * 10 * 10) where n = number of digits ~ O(1) since n <= 15
//S.C : O(n * 10 * 10) for memoization
class Solution {
public:
    typedef long long ll;
    string s;
    int n;

    ll dpTotalNumbers[16][10][10];
    ll dpTotalWaviness[16][10][10];

    pair<ll, ll> solve(int curr, int prevPrev, int prev, bool isLimitedWithActualNumber, bool isLeadingZero) {
        if (curr == n) {
            return {1, 0}; // no more score can be generated and we found one last number
        }

        if (!isLimitedWithActualNumber && !isLeadingZero && prevPrev >= 0 && prev >= 0) {
            if (dpTotalNumbers[curr][prevPrev][prev] != -1) {
                return {dpTotalNumbers[curr][prevPrev][prev], dpTotalWaviness[curr][prevPrev][prev]};
            }
        }

        ll totalNumbers   = 0;
        ll totalWaveScore = 0;

        int limitDigit = isLimitedWithActualNumber ? (s[curr] - '0') : 9;

        for (int digit = 0; digit <= limitDigit; digit++) {
            bool newIsLeadingZero = isLeadingZero && (digit == 0);

            int newPrevPrev = prev;
            int newPrev     = newIsLeadingZero ? -1 : digit;
            auto [remainTotalNumbers, remainTotalWaveScore] = solve(
                curr + 1, newPrevPrev, newPrev,
                isLimitedWithActualNumber && (digit == limitDigit),
                newIsLeadingZero
            );
            if (!newIsLeadingZero && prevPrev >= 0 && prev >= 0) {
                bool isPeak   = (prevPrev < prev && prev > digit);
                bool isValley = (prevPrev > prev && prev < digit);
                if (isPeak || isValley) {
                    totalWaveScore += remainTotalNumbers;
                }
            }
            totalNumbers   += remainTotalNumbers;
            totalWaveScore += remainTotalWaveScore;
        }
        if (!isLimitedWithActualNumber && !isLeadingZero && prevPrev >= 0 && prev >= 0) {
            dpTotalNumbers[curr][prevPrev][prev]  = totalNumbers;
            dpTotalWaviness[curr][prevPrev][prev] = totalWaveScore;
        }
        return {totalNumbers, totalWaveScore};
    }
    ll func(ll num) {
        if (num < 100) { 
            return 0;
        }
        memset(dpTotalNumbers, -1, sizeof(dpTotalNumbers));
        memset(dpTotalWaviness, -1, sizeof(dpTotalWaviness));
        s = to_string(num);
        n = s.length();
        auto [totalNumbers, totalWaveScore] = solve(0, -1, -1, true, true);
        return totalWaveScore;
    }
    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1 - 1);
    }
};
​​​
