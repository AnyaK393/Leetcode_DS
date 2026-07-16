#include<iostream>
#include<vector>
#include<string.h>

using namespace std;
class Solution {
public:

    int solve(string &answerKey, int k, char ch) {

        int left = 0;
        int count = 0;
        int answer = 0;

        for (int right = 0; right < answerKey.size(); right++) {

            if (answerKey[right] == ch)
                count++;

            while (count > k) {

                if (answerKey[left] == ch)
                    count--;

                left++;
            }

            answer = max(answer, right - left + 1);
        }

        return answer;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {

        return max(
            solve(answerKey, k, 'F'),
            solve(answerKey, k, 'T')
        );
    }
};