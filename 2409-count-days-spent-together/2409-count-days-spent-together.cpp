class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        // Convert each MM-DD date into a number MMDD
        int a1 = stoi(arriveAlice.substr(0, 2)) * 100
                 + stoi(arriveAlice.substr(3, 2));

        int a2 = stoi(leaveAlice.substr(0, 2)) * 100
                 + stoi(leaveAlice.substr(3, 2));

        int b1 = stoi(arriveBob.substr(0, 2)) * 100
                 + stoi(arriveBob.substr(3, 2));

        int b2 = stoi(leaveBob.substr(0, 2)) * 100
                 + stoi(leaveBob.substr(3, 2));

        // The overlap starts at the later arrival date
        int start = max(a1, b1);

        // The overlap ends at the earlier leaving date
        int end = min(a2, b2);

        // No overlap
        if(start > end) {
            return 0;
        }

        // Number of days in each month (not a leap year)
        int days[] = {
            0, 31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        // Extract month and day from the start date
        int startMonth = start / 100;
        int startDay = start % 100;

        // Extract month and day from the end date
        int endMonth = end / 100;
        int endDay = end % 100;

        // Convert start date into day number of the year
        int startTotal = startDay;
        for(int i = 1; i < startMonth; i++) {
            startTotal += days[i];
        }

        // Convert end date into day number of the year
        int endTotal = endDay;
        for(int i = 1; i < endMonth; i++) {
            endTotal += days[i];
        }

        // +1 because both dates are inclusive
        return endTotal - startTotal + 1;
    }
};