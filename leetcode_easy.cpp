#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<stack>
using namespace std;


class Leetcode1  // 从向量中找到和为指定值的两个数
{
public:
    class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = 0;
        vector<int> v;
        for (i=0; i<nums.size()-1; i++)
        {
            for (j = i+1; j<nums.size(); j++)
            {
                if (nums[i]+nums[j]==target)
                {
                    v.push_back(i);
                    v.push_back(j);
                }
                else
                {
                    continue;
                }
            }
        }
        return v;
    }


    void fun1()
{
    Solution S;
    vector<int> v;
    vector<int> o;
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    int t = 6;
    o = S.twoSum(v, t);
    for(vector<int>::iterator it = o.begin(); it != o.end(); it++)
    {
        cout << *it << endl;
    }
}
};
};


class Leetcode2 // 反转一个数字，超过范围返回零
{
public:
    class Solution {
    public:
    int reverse(int x) {
        long n = 0;
        while(x)
        {
            n = n * 10 + x % 10;
            x /= 10;
        }
        return n < (-(pow(2, 31))) || n > (pow(2, 31) - 1) ? 0 : n; 
    }


    Solution()
    {
        int  m;
        int out;
        cout << "leetcode2: input a number to reverse: ";
        cin >> m;
        out = Solution::reverse(m);
        cout << "output: " << out << endl;
    } 
    };  
};


class Leetcode3  // 判断是不是回文数
{
public:
    class Solution {
    public:
    bool isPalindrome(int x) {
        if (x<0){return false;}
        else
        {
            long n = 0;
            int flag = x;
            while (x)
            {
                n = n * 10 + x % 10;
                x /= 10;
            }
            return n == flag ? true:false;
        }
    }


    Solution()
    {
        int m;
        cout << "input a number to judge: ";
        cin >>  m;
        bool j = isPalindrome(m);
        cout << "output(1 == true; 0 == false): " << j << endl;
    }
    };
};


class Leetcode4 // 罗马数字转换，有六种特殊情况
{
public:
    class Solution {
    public:
        int romanToInt(string s) {
            int num = 0;
            if (s == "IV") {return 4;}
            else if(s == "IX"){return 9;}
            else if(s == "XL"){return 40;}
            else if(s == "XC"){return 90;}
            else if(s == "CD"){return 400;}
            else if(s == "CM"){return 900;}
            else
            {
                for (int i = 0; i <= s.size(); i++)
                {
                    switch(s[i])
                    {
                        case 'I':
                        if(s[i+1]=='V'){num += 4; i++;}
                        else if(s[i+1]=='X'){num += 9; i++;}
                        else{num += 1;}    
                        break;
                        case 'V':
                        num += 5;
                        break;
                        case 'X':
                        if(s[i+1]=='L'){num += 40; i++;}
                        else if(s[i+1]=='C'){num += 90; i++;}
                        else{num += 10;}  
                        break;
                        case 'L':
                        num += 50;
                        break;
                        case 'C':
                        if(s[i+1]=='D'){num += 400; i++;}
                        else if(s[i+1]=='M'){num += 900; i++;}
                        else{num += 100;}  
                        break;
                        case 'D':
                        num += 500;
                        break;
                        case 'M':
                        num += 1000;
                        break;
                    }
                }
            }
        return num;
        }


    Solution()
    {
        string ss;
        cout << "input roma number: ";
        cin >> ss;
        int output = romanToInt(ss);
        cout << "transfored number: " << output << endl;
    }
    };
};


class Leetcode5 // 寻找公共前缀
{
public:
    class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) 
        {
            if (strs.size() == 1){return strs[0];}
            string cp = "";
            int i = 0, j = 0;
            while (j < 200)
            {
                int count = 0;
                char flag = strs[0][j];
                for (i = 1; i < strs.size(); i++)
                {
                    if (strs[i][j]  && strs[i][j] == flag){ count++ ;}
                    else
                    {
                        return cp;
                    }
                }
                if (count + 1 == strs.size())
                {
                    cp += strs[0][j];
                }
                j++;
            }
            return cp;
        }


        Solution()
        {
            vector<string> v;
            v.push_back("a");
            v.push_back("flow");
            v.push_back("flowadwk");
            string output = longestCommonPrefix(v);
            cout << "common prefix: " << output << endl;
        }
    };
};


class Leetcode6 // 判断括号合法
{
public:
    class Solution 
    {
    public:
        bool isValid(string s) {
            if (s.length() % 2 == 1 || s[0] == ']' || s[0] == '}' ||s[0] == ')' ) {return false;}
            else
            {
                stack<char> sta;
                for (int i = 0; i < s.length(); i++)
                {
                    if (s[i] == '[' || s[i] == '{' || s[i] == '(')
                    {
                        sta.push(s[i]);
                    } 
                    else
                    {
                        if (sta.size() == 0) {return false;}
                        else
                        {
                        if ((s[i] == ']' && sta.top() == '[') || (s[i] == '}' && sta.top() == '{') || (s[i] == ')' && sta.top() == '(')){sta.pop();}
                        else {return false;}
                        }
                    }
                }
                return sta.size() == 0 ? true: false;
            }
        }

        Solution()
        {
            string comma;
            cout << "input {}[](): "; 
            cin >> comma;
            bool judge = isValid(comma);
            cout << "result: " << judge;
        }
    
    };
};


int main()
{
    //查看题目结果格式：Leetcodex::Solution sx;
    Leetcode6::Solution s6;
    system("pause");
    return 0;
} 