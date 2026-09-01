class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        int count = 0;
        queue<int> q;

        // Put indexes into the queue
        for(int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }

        // Keep buying tickets until person k has bought all
        while(tickets[k] != 0) {

            // Get the person at the front
            int i = q.front();
            q.pop();

            // This person buys one ticket
            tickets[i]--;
            count++;

            // If they still need tickets,
            // put them at the back of the queue
            if(tickets[i] > 0) {
                q.push(i);
            }
        }

        return count;
    }
};