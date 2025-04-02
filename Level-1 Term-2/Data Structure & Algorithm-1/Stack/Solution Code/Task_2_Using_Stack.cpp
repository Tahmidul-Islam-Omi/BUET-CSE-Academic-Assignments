#include <iostream>
#include "Stack_Header_File.h"

using namespace std;

class Solution
{
    Stack<double> nums;
    Stack<char> ops;
    bool hasPrevNum = false;

public:

    Solution(int numsSize, int opsSize) : nums(numsSize, 0), ops(opsSize, 0), hasPrevNum(false)
    {
    }

    bool precedes(char prevOp, char currOp)
    {
        if (prevOp == '(')
            return false;
        return prevOp == '*' || prevOp == '/' || currOp == '+' || currOp == '-';
    }

    void calc()
    {
        double b = nums.topValue();
        nums.pop();
        double a = nums.topValue();
        nums.pop();
        char op = ops.topValue();
        ops.pop();
        if (op == '+')
        {
            nums.push(a + b);
        }
        else if (op == '-')
        {
            nums.push(a - b);
        }
        else if (op == '*')
        {
            nums.push(a * b);
        }
        else
        {
            nums.push(a / b);
        }
    }

    double calculate(string s)
    {
        for (int i = 0; i < s.length(); ++i)
        {
            char c = s[i];

            if (isdigit(c))
            {
                double num = c - '0';
                while (i < (s.length() - 1) && isdigit(s[i + 1]))
                {
                    num = num * 10 + (s[i++ + 1] - '0');
                }

                nums.push(num);
                hasPrevNum = true;
            }

            else if (c == '(')
            {
                ops.push('(');
                hasPrevNum = false;

            }
            else if (c == ')')
            {
                while (ops.topValue() != '(')
                {
                    calc();
                }
                ops.pop();
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/')
            {
                if (!hasPrevNum)
                {
                    nums.push(0);
                }
                while (!ops.isEmpty() && precedes(ops.topValue(), c))
                {
                    calc();
                }

                ops.push(c);
            }
        }

        while (!ops.isEmpty())
        {
            calc();
        }

        return nums.topValue();
    }
};

int main()
{
    int t= 100;
    while(t--)
    {

        string expression;
        cin >> expression;

        Stack<char>st( expression.size(), expression.size());

        st.clear();

        int curr_size = 0;
        int valid = 0;
        int flag = 0;

        for(int i=0; i<expression.size()-1 ; i++ )
        {
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' )
            {
                if(!isdigit(expression[i+1]) && expression[i+1] == ')')
                {

                    flag = 1;
                    break;
                }

                else if( expression[i+1] == '+' || expression[i+1] == '-' || expression[i+1] == '*' || expression[i+1] == '/') {
                    flag = 1;
                    break;
                }

            }
        }

        for(int i=0; i<expression.size()-1; i++)
        {
            if( isdigit(expression[i]) && expression[i+1] == '(' )
            {
                flag = 1;
                break;
            }
        }


        for(int i=0; i<expression.size() ; i++)
        {
            if(expression[i] == '(')
            {
                st.push(expression[i]);
                curr_size++;
            }

            else if( expression[i] == ')')
            {
                st.pop();
                curr_size--;
            }
        }


        if( st.isEmpty() == false )
        {
            flag = 1;
        }


        if(flag == 1)
        {
            cout << "Not valid." << endl;
        }

        else
        {
            cout << "Valid expression." << endl;
            valid=1;
        }



        if(valid == 1)
        {

            Solution st(100, 100);
            cout << st.calculate(expression) << endl;
        }

    }



}




/*



#include <iostream>
#include <string>
#include "Stack_Header_File.h"

using namespace std;

class Solution
{
private:
    Stack<int> nums;
    Stack<char> ops;

    bool hasPrevNum;

public:

    Solution(int numsSize, int opsSize) : nums(numsSize, 0), ops(opsSize, 0), hasPrevNum(false)
    {
    }


    bool precedes(char prevOp, char currOp)
    {
        if (prevOp == '(')
            return false;
        return prevOp == '*' || prevOp == '/' || currOp == '+' || currOp == '-';
    }

    void calc()
    {
        int b = nums.topValue();
        nums.pop();
        int a = nums.topValue();
        nums.pop();
        char op = ops.topValue();
        ops.pop();
        if (op == '+')
        {
            nums.push(a + b);
        }
        else if (op == '-')
        {
            nums.push(a - b);
        }
        else if (op == '*')
        {
            nums.push(a * b);
        }
        else
        {
            nums.push(a / b);
        }
    }

    int calculate(string s)
    {
        for (int i = 0; i < s.length(); ++i)
        {
            char c = s[i];

            if (isdigit(c))
            {
                int num = c - '0';
                while (i < (s.length() - 1) && isdigit(s[i + 1]))
                {
                    num = num * 10 + (s[i++ + 1] - '0');
                }

                nums.push(num);
                hasPrevNum = true;
            }
            else if (c == '(')
            {
                ops.push('(');
                hasPrevNum = false;
            }
            else if (c == ')')
            {
                while (ops.topValue() != '(')
                {
                    calc();
                }
                ops.pop();
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/')
            {
                if (!hasPrevNum)
                {
                    nums.push(0);
                }
                while (!ops.isEmpty() && precedes(ops.topValue(), c))
                {
                    calc();
                }

                ops.push(c);
            }
        }

        while (!ops.isEmpty())
        {
            calc();
        }

        return nums.topValue();
    }
};

int main()
{
    string expression;
    cin >> expression;

    Stack<char> st(expression.size(), expression.size());

    st.clear();

    int curr_size = 0;
    int valid = 0;

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '(')
        {
            st.push(expression[i]);
            curr_size++;
        }
        else if (expression[i] == ')')
        {
            st.pop();
            curr_size--;
        }
    }

    st.setK(curr_size);

    if (!st.isEmpty())
    {
        cout << "Not Valid" << endl;
    }
    else
    {
        int flag = 0;

        for (int i = 0; i < expression.size() - 1; i++)
        {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
            {
                if (expression[i + 1] == '+' || expression[i + 1] == '-' || expression[i + 1] == '*' || expression[i + 1] == '/')
                {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 1)
        {
            cout << "Not Valid" << endl;
        }
        else
        {
            cout << "Valid Expression" << endl;
            valid = 1;
        }
    }

    if (valid == 1)
    {
        Solution st(100, 100);
        cout << st.calculate(expression) << endl;
    }

    return 0;
}

*/

