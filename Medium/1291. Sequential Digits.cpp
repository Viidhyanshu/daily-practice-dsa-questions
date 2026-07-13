An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9


 //solution
 class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> que;
        for(int i = 1; i <= 8; i++) {
            que.push(i);
        }
        
        vector<int> result;
        
        while(!que.empty()) {
            int temp = que.front();
            que.pop();
            
            if(temp >= low && temp <= high) {
                result.push_back(temp);
            }
            
            int last_digit = temp%10;
            if(last_digit + 1 <= 9) {
                que.push(temp * 10 +(last_digit + 1));
            }
        }
        
        return result;
    }
};
