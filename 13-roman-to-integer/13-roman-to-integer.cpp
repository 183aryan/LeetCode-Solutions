class Solution {
public:
    int romanToInt(string s) {
    int temp = 0;

    for (int i = 0; i < s.size();)
    {
        if (s[i] == 'I')
        {
            if (s[i + 1] == 'V')
            {
                temp += 4;
                i += 2;
            }
            else if (s[i + 1] == 'X')
            {
                temp += 9;
                i += 2;
            }
            else
            {
                temp++;
                i++;
            }
        }
        else if (s[i] == 'V')
        {
            temp += 5;
            i++;
        }
        else if (s[i] == 'X')
        {
            if (s[i + 1] == 'L')
            {
                temp += 40;
                i += 2;
            }
            else if (s[i + 1] == 'C')
            {
                temp += 90;
                i += 2;
            }
            else
            {
                temp += 10;
                i++;
            }
        }
        else if (s[i] == 'L')
        {
            temp += 50;
            i++;
        }
        else if (s[i] == 'C')
        {
            if (s[i + 1] == 'D')
            {
                temp += 400;
                i += 2;
            }
            else if (s[i + 1] == 'M')
            {
                temp += 900;
                i += 2;
            }
            else
            {
                temp += 100;
                i++;
            }
        }
        else if (s[i] == 'D')
        {
            temp += 500;
            i++;
        }
        else if (s[i] == 'M')
        {
            temp += 1000;
            i++;
        }
    }

     return temp;   
    }
};