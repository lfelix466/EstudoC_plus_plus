#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int biggerWord = 0, count = 0, status = 0;
        for (size_t i = 0; i < sentences.size(); i++)
        {
            count = 0;
            for (size_t j = 0; j < sentences[i].size(); j++)
            {
                if (sentences[i][j] == ' ' && status == 1)
                {
                    count++;
                    status = 0;
                }
                else if (sentences[i][j] != ' ')
                {
                    status = 1;
                }
            }
            if (biggerWord < count)
            {
                biggerWord = count;
            }
        }
        return biggerWord+1;
    }
};

int main()
{
    Solution sol;
    vector<string> sentences = {
        "please wait","continue to fight","continue to win"};

    cout << sol.mostWordsFound(sentences);
}