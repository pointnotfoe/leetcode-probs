/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/add-strings/
*/
/*
"6913259244"
+ "71103343"
= "6984362587"

"5297"
"6019530762"
="6019536059"

"498828660196"
"840477629533"
="1339306289729"

"5297"
"6019530762"
="6019536059"

    "930047927929"
"7607999646288178"
="7608929 694216107"
~"7617299 694216107"
*/
class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        int num1_length = num1.length();
        int num2_length = num2.length();
        if (num1[0] == '0')
        {
            return num2;
        }
        if (num2[0] == '0')
        {
            return num1;
        }
        
        int num1_read_count = 0;
        int num2_read_count = 0;
        unsigned int carry = 0;
        string sum_string;
        
        while(1)
        {
            unsigned int dec1 = 0;
            unsigned int dec2 = 0;
            unsigned int sum = 0;
            int max_read_length = 0;
            int num1_read_length = 9;
            int num2_read_length = 9;
         
            //assuming int is 32 bits. length of 9 ensures that we are in range
            if (num1_read_count < num1_length)
            {
                if (num1_length - num1_read_count < 9)
                {
                    num1_read_length = num1_length - num1_read_count;
                }
                int start_index = num1_length - num1_read_count - num1_read_length;
                while (num1[start_index] == '0')
                {
                    start_index++;
                    num1_read_length--;
                }
                if (start_index < 0)
                {
                    start_index = 0;
                }
                dec1 = string_to_int(num1.substr(start_index, num1_read_length));
                //cout << "dec1 = " << dec1 << endl;
                num1_read_count += num1_read_length;
            }
            if (num2_read_count < num2_length)
            {
                if (num2_length - num2_read_count < 9)
                {
                    num2_read_length = num2_length - num2_read_count;
                }
                int start_index = num2_length - num2_read_count - num2_read_length;
                while (num2[start_index] == '0')
                {
                    start_index++;
                    num2_read_length--;
                }
                if (start_index < 0)
                {
                    start_index = 0;
                }
                dec2 = string_to_int(num2.substr(start_index, num2_read_length));
                //cout << "dec2 = " << dec2 << endl;
                num2_read_count += num2_read_length;
            }
            sum = dec1 + dec2 + carry;
            //cout << " sum = " << sum << endl;
            
            max_read_length = (num1_read_length >= num2_read_length)? num1_read_length : num2_read_length;
            //cout << "max read length " << max_read_length << endl;
            if (sum >= pow(10, max_read_length))
            {
                carry = char_to_int(to_string(sum)[0]);
                //Dont append carry
                sum_string.insert(0, to_string(sum).substr(1));
                
            }
            else
            {
                carry = 0;
                sum_string.insert(0, to_string(sum));
            }
            
            if (num1_length == num1_read_count && num2_length == num2_read_count)
            {
                break;
            }
            
        }
        if (carry > 0)
        {
            sum_string.insert(0, to_string(carry));
        }
        return sum_string;
        
    }
    
    unsigned int string_to_int(string num_string)
    {
        //cout << "----------Full string = " << num_string <<"--------" <<endl;
        int length = num_string.size();
        //cout << "String length = " << length << endl;
        unsigned int num = 0;
        if (0 == num_string[length - 1])
        {
            return num;
        }
        
        //power of 10
        int dec_power = 0;
        
        //e.g 681 => {6, 8, 1} = 6*(10^2) + 8*(10^1) + 1*(10^0)
        for (int i = length - 1; i >= 0; i--)
        {
            //convert a single character to int.
            unsigned int unit = char_to_int(num_string[i]);
            //cout << "int unit = " << unit <<endl;
            //adjust for proper power of 10
            num = num + (unit * pow(10, dec_power));
            //cout << "dec = " << num <<endl;
            dec_power++;
        }
        return num;
    }
    
    int char_to_int(char num)
    {
        //cout << "char unit = " << num <<endl;
        int unit;
        switch (num)
        {
            case '1':
                unit = 1;
                break;
            case '2':
                unit = 2;
                break;
            case '3':
                unit = 3;
                break;
            case '4':
                unit = 4;
                break;
            case '5':
                unit = 5;
                break;
            case '6':
                unit = 6;
                break;
            case '7':
                unit = 7;
                break;
            case '8':
                unit = 8;
                break;
            case '9':
                unit = 9;
                break;
            default:
                unit = 0;
                break;
        }
        return unit;
    }
};

int main()
{
    Solution two_sum;
    vector<int> test_data = {1,2,3,10,50,78,6};
    vector<int> answer = test_data.twoSum(test_data,64);

    return 0;

}