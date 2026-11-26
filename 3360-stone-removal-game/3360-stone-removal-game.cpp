class Solution {
public:
    bool canAliceWin(int n) {
        int stonesToRemove = 10;
        int turns = 0;

        // Continue while there are enough stones for the current turn
        while (n >= stonesToRemove && stonesToRemove > 0) {
            n -= stonesToRemove;
            stonesToRemove--;
            turns++;
        }

        // Alice plays on odd turns (1st, 3rd, 5th, ...), so she wins if total turns are odd
        return turns % 2 == 1;
    }
};
