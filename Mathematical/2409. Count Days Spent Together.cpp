Alice and Bob are traveling to Rome for separate business meetings.

You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.

Return the total number of days that Alice and Bob are in Rome together.

You can assume that all dates occur in the same calendar year, which is not a leap year. Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].

 

Example 1:

Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
Output: 3
Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.
Example 2:

Input: arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
Output: 0
Explanation: There is no day when Alice and Bob are in Rome together, so we return 0.
 

Constraints:

All dates are provided in the format "MM-DD".
Alice and Bob's arrival dates are earlier than or equal to their leaving dates.
The given dates are valid dates of a non-leap year.


 //solution
 class Solution {
public:

    int findDayOfYear(const string& day, const vector<int>& cumMonthDays) {
        int month = stoi(day.substr(0, 2));
        int date  = stoi(day.substr(3));
        return cumMonthDays[month - 1] + date;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int> cumMonthDays(13, 0);
        cumMonthDays[1] = 31;
        for(int i = 1; i <= 12; i++) {
            cumMonthDays[i] = cumMonthDays[i-1] + monthDays[i-1];
        }

        int arriveAliceDay  = findDayOfYear(arriveAlice, cumMonthDays);
        int leaveAliceDay   = findDayOfYear(leaveAlice, cumMonthDays);
        int arriveBobDay    = findDayOfYear(arriveBob, cumMonthDays);
        int leaveBobDay     = findDayOfYear(leaveBob, cumMonthDays);

        int overLapDays = min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay) + 1;

        return overLapDays < 0 ? 0 : overLapDays;
    }
};
