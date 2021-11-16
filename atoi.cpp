/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/string-to-integer-atoi/
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
 

Example 1:

Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.
Example 2:

Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.
Example 3:

Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.
Example 4:

Input: s = "words and 987"
Output: 0
Explanation:
Step 1: "words and 987" (no characters read because there is no leading whitespace)
         ^
Step 2: "words and 987" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "words and 987" (reading stops immediately because there is a non-digit 'w')
         ^
The parsed integer is 0 because no digits were read.
Since 0 is in the range [-231, 231 - 1], the final result is 0.
Example 5:

Input: s = "-91283472332"
Output: -2147483648
Explanation:
Step 1: "-91283472332" (no characters read because there is no leading whitespace)
         ^
Step 2: "-91283472332" ('-' is read, so the result should be negative)
          ^
Step 3: "-91283472332" ("91283472332" is read in)
                     ^
The parsed integer is -91283472332.
Since -91283472332 is less than the lower bound of the range [-231, 231 - 1], the final result is clamped to -231 = -2147483648.
 

Constraints:

0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

Runtime: 12 ms, faster than 5.40% of C++ online submissions for String to Integer (atoi).
Memory Usage: 7 MB, less than 52.56% of C++ online submissions for String to Integer (atoi).
 */
class Solution {
public:
    int myAtoi(string s) {
        int index =0;
        while (s[index] == ' ')
        {
            index++;
        }
        //cout << "after space "<< index << endl;
        bool positive = true;
        if (s[index] == '+' || s[index] == '-')
        {
            if (s[index] == '-')
            {
                positive = false;
            }
            index++;
        }        
        //cout << "after sign "<< index << endl;

        long long int number = 0;
        bool leading_zero = true;
        bool overflow = false;
        for (; index < s.length(); index++)
        {
            if (true == leading_zero && s[index] == 0)
            {
                continue;
            }
            //cout << "after leading index = "<< index << endl;
            //cout << "char = " << s[index] << " (int)" << (int)s[index];
            leading_zero = false;
            if (s[index] >= 48 && s[index] <= 57)
            {
                if (number != 0)
                {
                    number *= 10;
                }
                number += s[index] - 48;
                if ((positive &&  (number > (0x7FFFFFFF)) )||
                    (!positive && (number > (0x80000000))) )
                {
                    overflow = true;
                    break;//over 32 bits
                }
            }
            else
            {
                break;//first non digit
            }
        }
        if (overflow)
        {
            number = 1 << 31;
            number = positive ? number - 1: number;
        }
        else
        {
            number = positive ? number: number *(-1);
        }
        return (int)(number);
        
    }
};
/*
Runtime: 6 ms, faster than 17.10% of C++ online submissions for String to Integer (atoi).
Memory Usage: 7 MB, less than 52.56% of C++ online submissions for String to Integer (atoi).
*/
class Solution {
public:
    int myAtoi(string s) {
        int index =0;
        while (s[index] == ' ')
        {
            index++;
        }
        //cout << "after space "<< index << endl;
        bool positive = true;
        if (s[index] == '+' || s[index] == '-')
        {
            if (s[index] == '-')
            {
                positive = false;
            }
            index++;
        }        
        //cout << "after sign "<< index << endl;

        long long int number = 0;
        for (; index < s.length(); index++)
        {
            if (s[index] >= 48 && s[index] <= 57)
            {
                if (number != 0)
                {
                    number *= 10;
                }
                number += s[index] - 48;
                if (number > 0x7FFFFFFF)
                {
                    number = 1 << 31;          
                    number = positive ? 0x7FFFFFFF: 0x80000000;
                    return (int)number;
                }
            }
            else
            {
                break;//first non digit
            }
        }

        return (int)(positive ? number: number *(-1));
        
    }
};

/*
Runtime: 4 ms, faster than 61.03% of C++ online submissions for String to Integer (atoi).
Memory Usage: 7.1 MB, less than 52.56% of C++ online submissions for String to Integer (atoi).
*/
class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        while (s[index] == ' ')
        {
            index++;
        }
        bool positive = true;
        if (s[index] == '+' || s[index] == '-')
        {
            if (s[index] == '-')
            {
                positive = false;
            }
            index++;
        }        

        long int number = 0;
        for (; index < s.length(); index++)
        {
            if (s[index] >= 48 && s[index] <= 57)
            {
                number = (number * 10) + s[index] - 48;
                if (number > 0x7FFFFFFF)
                {
                    number = positive ? 0x7FFFFFFF: 0x80000000;
                    return (int)number;
                }
            }
            else
            {
                break;//first non digit
            }
        }

        return (int)(positive ? number: number *(-1));
        
    }
};