You are given a string num which represents a positive integer, and an integer t.

A number is called zero-free if none of its digits are 0.

Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".

 

Example 1:

Input: num = "1234", t = 256

Output: "1488"

Explanation:

The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.

Example 2:

Input: num = "12355", t = 50

Output: "12355"

Explanation:

12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.

Example 3:

Input: num = "11111", t = 26

Output: "-1"

Explanation:

No number greater than 11111 has the product of its digits divisible by 26.

 

Constraints:

2 <= num.length <= 2 * 105
num consists only of digits in the range ['0', '9'].
num does not contain leading zeros.
1 <= t <= 1014
//solution


class Solution {
public:
    typedef long long ll;

    string freeSlotsFiller(ll required, int length) {
        string str;

        for(int digit = 9; digit >= 2; digit--) {
            while(required % digit == 0) {
                str.push_back(digit + '0');
                required /= digit;
            }
        }

        while(str.length() < length) {
            str.push_back('1');
        }

        reverse(begin(str), end(str));

        return str;
    }

    string smallestNumber(string num, long long t) {
        int n = num.length();

        ll temp = t;
        for(int primeFact : {2, 3, 5, 7}) {
            while(temp % primeFact == 0) {
                temp /= primeFact;
            }
        }

        if(temp != 1) {
            return "-1";
        }
        vector<ll> remainingFactor(n+1, t);
        for(int i = 0; i < n; i++) {
            int digit = num[i] - '0';

            if(digit == 0) {
                break;
            }
            remainingFactor[i+1] = remainingFactor[i]/gcd(remainingFactor[i], (ll)digit);
        }
        if(remainingFactor[n] == 1) { 
            return num;
        }
        int zeroPos = num.find('0');
        int zeroIdx = n-1;
        if(zeroPos != -1) {
            zeroIdx = zeroPos;
        }

        for(int i = zeroIdx; i >= 0; i--) {
            ll required = remainingFactor[i];
            int freeSlots = n - 1 - i;

            for(int digit = (num[i] - '0')+1; digit <= 9; digit++) {
                ll furtherRequired = required / gcd(required, digit);
                string requiredNumber = freeSlotsFiller(furtherRequired, freeSlots);

                if(requiredNumber.length() == freeSlots) {
                    return num.substr(0, i) + char(digit + '0') + requiredNumber;
                }
            }
        }
        return freeSlotsFiller(t, n+1); 
    }
};



t.c. = O(n x log(t))
