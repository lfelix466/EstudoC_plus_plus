#include <iostream>
using namespace std;

class Solution
{
private:
    bool divides(int num, int digit)
    {
        if (digit != 0)
        {
            if (num % digit == 0)
            {
                return true;
            }
        }
        return false;
    }

public:
    int countDigits(int num)
    {
        int digit = num % 10;
        int count = 0, num1 = num;

        num = (num - digit) / 10;

        if (divides(num1, digit))
        {
            count++;
        }

        while (num != 0)
        {
            digit = num % 10;

            if (divides(num1, digit))
            {
                count++;
            }
            num = (num - digit) / 10;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    int num = 1248;
    cout << sol.countDigits(num);
}