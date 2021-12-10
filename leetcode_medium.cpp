#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<limits.h>
#include<ctype.h>
#include<numeric>
#include<bitset>
#include<random>
#include<time.h>
#include"leetcode_medium_head.h"

using namespace std;

// 此文件按照leetocde中等题题号排序

class Leetcode2  // 两数相加
{
public:
    class Solution 
    {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {
            ListNode *head = nullptr, *tail = nullptr;
            int carry = 0;
            while (l1 || l2) {
                int n1 = l1 ? l1->val: 0;
                int n2 = l2 ? l2->val: 0;
                int sum = n1 + n2 + carry;
                if (!head) 
                {
                    head = tail = new ListNode(sum % 10);
                } else 
                {
                    tail->next = new ListNode(sum % 10);
                    tail = tail->next;
                }
                carry = sum / 10;
                if (l1) 
                {
                    l1 = l1->next;
                }
                if (l2) 
                {
                    l2 = l2->next;
                }
            }
            if (carry > 0) 
            {
                tail->next = new ListNode(carry);
            }
            return head;
        }


        Solution()
        {
            ListNode* l3 = new ListNode(3);
            ListNode* l2 = new ListNode(4, l3);
            ListNode* l1 = new ListNode(2, l2);
            ListNode* l6 = new ListNode(4);
            ListNode* l5 = new ListNode(6, l6);
            ListNode* l4 = new ListNode(5, l5);
            ListNode* l = addTwoNumbers(l1, l4);
            while (l)
            {
                cout << l->val << endl;
                l = l->next;
            }
        }
    };
};


class Leetcode3  // 无重复字符的最长子串
{
public:
    class Solution 
    {
    public:
        int lengthOfLongestSubstring(string s)  // 滑动窗口+队列
        {
            if (s == "") return 0;
            deque<char> window;
            int right = 0, max = 0;
            while (right <= s.size() - 1)
            {
                deque<char>::iterator it = find(window.begin(), window.end(), s[right]), itt = window.begin();
                if (it == window.end())  // 如果没找到元素，就把元素从尾巴插入队列window
                {
                    window.push_back(s[right++]);
                }
                else
                {
                    while(*itt != *it)  // 如果找到了元素，就把队列中该元素前面（包括它本身）都删掉，再把新元素插入
                    {
                        itt = window.erase(itt);
                    }
                    window.erase(itt);
                    window.push_back(s[right++]);
                }
                max = (window.size() > max ? window.size() : max);  // 每轮循环都记录下当前最大值
            }
            return max;
        }



        int lengthOfLongestSubstringMy(string s)  // 我的滑动窗口，慢且占内存
        {
            int max = 0;
            int window = 1;
            for (; window <= s.size(); window++)
            {
                max = (exist(s, window) == true ? window : max);
                if (exist(s, window) == false) break;
            }
            return max;
        }


        bool exist(string s, int window)
        {
            for (int k = 0; k < s.size() - window + 1; k++)
            {
                vector<char> array;
                for (int j = k; j < window + k; j++)
                {
                    if (find(array.begin(), array.end(), s[j]) != array.end()) break;
                    else array.push_back(s[j]);
                }
                if (array.size() == window) return true;
            }
            return false;
        }


        Solution()
        {
            cout << lengthOfLongestSubstring("qwert") << endl;
        }
    };
};


class Leetcode5  // 最长回文子串
{
public:
    class Solution {
    public:
        string longestPalindrome(string s) 
        {
            int window = 2;
            vector<string> ss;
            string out;
            out += s[0];
            for (; window <= s.size(); window++)
            {
                for (int i = 0; i < s.size() - window + 1; i++)
                {
                    int left = i;
                    int right = i + window - 1;
                    while (left < right)
                    {
                        if (s[left] == s[right]) left++, right--;
                        else break;
                    }
                    if (left >= right) 
                    {
                        ss.push_back(s.substr(i, window));
                        break;
                    }         
                }
            }
            int max = 0, max_len = 0;
            for (int i = 0; i < ss.size(); i++)
            {
                max = (ss[i].size() > max_len ? i : max);
            }
            return (ss.size() == 0 ? out : ss[max]);
        }


        Solution()
        {
            cout << longestPalindrome("aacabdkacaa") << endl;
        }
    };
};


class Leetcode6  // Z 字形变换
{
public:
    class Solution 
    {
    public:
        string convert(string s, int numRows) 
        {
            if (numRows == 1) return s;
            int iter = 1, i = 0;
            vector<string> rst(numRows + 1);
            string ss;
            while (i < s.size())
            {
                rst[iter] += s[i++];
                if (iter == 1)  // 回到第一行，转为正向
                {
                    rst[0] = "forward";
                    iter++;
                    continue;
                } 
                if (iter == numRows) // 到最后一行设置为反向
                {
                    rst[0] = "backward";
                    iter--;
                    continue;
                }
                if (iter != numRows && rst[0] == "forward") iter++;
                if (iter != numRows && rst[0] == "backward") iter--;
            }
            for (int i = 1; i < rst.size(); i++) ss += rst[i];
            return ss;
        }


        Solution()
        {
            cout << convert("PAYPALISHIRING", 3) << endl;
        }
    };
};


class Leetcode8  // 字符串转换整数 (atoi)  边界条件复杂没做出来，选了评论区一个比较优秀的做法
{
public:
    class Solution 
    {
    public:
        int myAtoi(string s) {
            int size=s.size();
            bool flag=true;
            int begin=0;
            int end=size-1;
            //找数字起始的位置
            //遇到空白继续走，遇到数字当前索引，遇到正负号为下一个索引，遇到字母直接返回0
            for(int i = 0; i < size; ++i)
            {
                if(s[i] == ' ') continue;
                else if(s[i] == '-')
                {
                    flag = false;
                    begin = i+1;
                    break;
                }
                else if (s[i] == '+')
                {
                    begin = i + 1;
                    break;
                }
                else if(s[i] - '0' >= 0 && s[i] - '0' < 10)
                {
                    begin = i;
                    break;
                }
                else return 0;
            }
            //找数字终止的位置
            //遇到数字继续走，遇到其他为上一个索引
            for(int i = begin;i < size; ++i)
            {
                if(s[i] - '0' >= 0 && s[i] - '0' < 10) continue;
                else
                {
                    end = i - 1;
                    break;
                }
            }

            //计算最终结果，溢出int，正数为INT_MAX，负数为INT_MIN
            long res = 0;
            for(int j = begin;j <= end; ++j)
            {
                res = 10 * res + (s[j] - '0');
                if(flag && res >= INT_MAX) return INT_MAX;
                if(!flag && -res <= INT_MIN) return INT_MIN;
            }
            return flag ? int(res) : int(-res);
        }


        Solution()
        {
            cout << myAtoi("-342892hrd") << endl;
        }
    };
};


class Leetcode11 // 盛水最多的容器  经典面试题目
{
public:
    class Solution 
    {
    public:
        int maxArea(vector<int>& height) 
        {
            int left = 0, right = height.size() - 1, max = 0;
            while ( left < right )
            {
                int area = min(height[left], height[right]) * (right - left);
                max = (area > max ? area : max);
                if (height[left] <= height[right]) left++;
                else right--;
            }
            return max;
        }


        Solution()
        {
            vector<int> nums = {1, 2, 3, 2, 1};
            cout << maxArea(nums) << endl;
        }
    };
};


class Leetcode12  // 整数转罗马数字
{
public:
    class Solution 
    {
    public:
        string intToRoman(int num) 
        {
            int time[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            string sep[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
            string rst;
            for (int i = 0; i < 13; i++)
            {
                while (num >= time[i])
                {
                    num -= time[i];
                    rst += sep[i];
                }
            }
            return rst;
        }


        Solution()
        {
            cout << intToRoman(1333) << endl;
        }
    };
};


class Leetcode15  // 三数之和(没做出来，用的是官方题解)
{
public:
    class Solution 
    {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) 
        {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            // 枚举 a
            for (int first = 0; first < n; ++first) {
                // 需要和上一次枚举的数不相同
                if (first > 0 && nums[first] == nums[first - 1]) {
                    continue;
                }
                // c 对应的指针初始指向数组的最右端
                int third = n - 1;
                int target = -nums[first];
                // 枚举 b
                for (int second = first + 1; second < n; ++second) {
                    // 需要和上一次枚举的数不相同
                    if (second > first + 1 && nums[second] == nums[second - 1]) {
                        continue;
                    }
                    // 需要保证 b 的指针在 c 的指针的左侧
                    while (second < third && nums[second] + nums[third] > target) {
                        --third;
                    }
                    // 如果指针重合，随着 b 后续的增加
                    // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                    if (second == third) {
                        break;
                    }
                    if (nums[second] + nums[third] == target) {
                        ans.push_back({nums[first], nums[second], nums[third]});
                    }
                }
            }
            return ans;
        }


        Solution()
        {
            vector<int> nums = {-1,0,1,2,-1,-4};
            vector<vector<int>> rst = threeSum(nums);
            for (int i = 0; i < rst.size(); i++)
            {
                for (int j = 0; j < rst[0].size(); j++)
                {
                    cout << rst[i][j] << " ";
                }
                cout << endl;
            }
        }
    };
};


class Leetcode16  // 最接近的三数之和
{
public:
    class Solution 
    {
    public:
        int threeSumClosest(vector<int>& nums, int target) 
        {
            sort(nums.begin(), nums.end());
            int min = INT_MAX, num = 0;
            vector<int> out;
            for (int i = 0; i < nums.size() - 2; i++)
            {
                int left = i + 1, right = nums.size() - 1;
                while (left < right)
                { 
                    int rst = abs(nums[i] + nums[left] + nums[right] - target);
                    if (rst == 0) return target;
                    if (rst < min) num = nums[i] + nums[left] + nums[right];
                    min = rst < min ? rst : min;
                    if (nums[i] + nums[left] + nums[right] < target) left++;
                    else right--;
                }
            }
            return num;
        }


        /* 评论区一个更加清晰的版本
        int threeSumClosest(vector<int>& nums, int target) 
        {
            sort(nums.begin(),nums.end());
            int res = nums[0] + nums[1] + nums[2];
            for(int i = 0; i < nums.size(); i++)
            {
                int left = i + 1, right = nums.size() - 1;
                while(left < right)
                {
                    int temp = nums[i] + nums[left] + nums[right];
                    if(abs(temp - target) < abs(res - target))
                        res = temp;
                    if(temp > target) right--;
                    else if(temp < target) left++;
                    else return target;
                }
            }
            return res;
        }
        */


        Solution()
        {
            vector<int>nums = {0, 2, 1, -3};
            cout <<threeSumClosest(nums, 1) << endl;
        }
    };
};


class Leetcode17  // 电话号码的字母组合(没做出来，对回溯不熟悉)
{
public:
    class Solution {
    private:
        const string letterMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno",  "pqrs", "tuv", "wxyz"};
    public:
        vector<string> result;
        string s;
        void backtracking(const string& digits, int index) 
        {
            if (index == digits.size()) 
            {
                result.push_back(s);
                return;
            }
            int digit = digits[index] - '0';        // 将index指向的数字转为int
            string letters = letterMap[digit];      // 取数字对应的字符集
            for (int i = 0; i < letters.size(); i++) 
            {
                s.push_back(letters[i]);            // 处理
                backtracking(digits, index + 1);    // 递归，注意index+1，一下层要处理下一个数字了
                s.pop_back();                       // 回溯
            }
        }
        vector<string> letterCombinations(string digits) 
        {
            if (digits.size() == 0) 
            {
                return result;
            }
            backtracking(digits, 0);
            return result;
        }


        Solution()
        {
            vector<string> out = letterCombinations("23");
            for (string i : out) cout << i << "   ";
        }
    };
};


class Leetcode18  // 四数之和(官方题解)
{
public:
    class Solution 
    {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) 
        {
            vector<vector<int>> quadruplets;
            if (nums.size() < 4) 
            {
                return quadruplets;
            }
            sort(nums.begin(), nums.end());
            int length = nums.size();
            for (int i = 0; i < length - 3; i++) 
            {
                if (i > 0 && nums[i] == nums[i - 1]) 
                {
                    continue;
                }
                if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
                if ((long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {continue;
                for (int j = i + 1; j < length - 2; j++) 
                {
                    if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                    if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                    if ((long) nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) continue;
                    int left = j + 1, right = length - 1;
                    while (left < right) 
                    {
                        int sum = nums[i] + nums[j] + nums[left] + nums[right];
                        if (sum == target) 
                        {
                            quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                            while (left < right && nums[left] == nums[left + 1]) left++;
                            left++;
                            while (left < right && nums[right] == nums[right - 1]) right--;
                            right--;
                        } 
                        else if (sum < target) 
                        {
                            left++;
                        } else
                        {
                            right--;
                        }
                    }
                }
            }
            return quadruplets;
            }
        }


        Solution()
        {
            cout << "垃圾题" <<endl;
        }
    };
};


class Leetcode19  // 删除链表的倒数第N个节点
{
public:
    class Solution 
    {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n)  // 我的方法，遍历了两次
        {
            if (!head || !head->next) return nullptr;
            ListNode* rec = head;
            int length = 0;
            while (rec)
            {
                rec = rec->next;
                length++;
            }
            if (length == n) return head->next;
            rec = head;
            for (int i = 1; i < length - n; i++) rec = rec->next;
            rec->next = rec->next->next;
            return head;
        }


        ListNode* removeNthFromEndDoublePointers(ListNode* head, int n)  // 双指针法，快指针先走n个结点，当快指针到最后一个节点慢指针就在倒数第n个
        {
            ListNode* dummy = new ListNode(0, head);
            ListNode* first = head;
            ListNode* second = dummy;
            for (int i = 0; i < n; ++i) first = first->next;
            while (first) 
            {
                first = first->next;
                second = second->next;
            }
            second->next = second->next->next;
            ListNode* ans = dummy->next;
            delete dummy;
            return ans;
        }


        Solution()
        {
            cout << "Too lazy to generate a list" << endl;
        }
    };
};


class Leetcode22  // 括号生成
{
public:
    class Solution 
    {
    public:
        vector<string> rst;

        vector<string> generateParenthesis(int n) 
        {

            dfs(n, n, "");
            return rst;
        }


        void dfs(int left, int right, string current)
        {
            if (left == 0 && right == 0) rst.push_back(current);
            if (left > 0) dfs(left - 1, right, current + "(");
            if (right > left) dfs(left, right - 1, current + ")");
        }


        Solution()
        {
            for (string i : generateParenthesis(3)) cout << i << endl;
        }
    };
};


class Leetcode24  // 两两交换链表中的节点
{
public:
    class Solution 
    {
    public:
        ListNode* swapPairs(ListNode* head) 
        {
            if (!head) return nullptr;
            if (!head->next) return head;
            ListNode* out = head->next,* fast = head->next,* slow = head;
            while (slow->next)
            {
                slow->next = fast->next;
                fast->next = slow;
                if (slow->next && slow->next->next)
                {
                    slow = slow->next;
                    fast->next->next = slow->next;   
                    fast = slow->next;            
                }
                else break;
            } 
            return out;
        }


        Solution()
        {
            ListNode* l1 = new ListNode(1);
            ListNode* l2 = new ListNode(2);
            ListNode* l3 = new ListNode(3);
            ListNode* l4 = new ListNode(4);
            ListNode* l5 = new ListNode(5);
            l1->next = l2;
            l2->next = l3;
            l3->next = l4;
            l4->next = l5;
            l4 = swapPairs(l1);
            while (l4)
            {
                cout << l4->val << " ";
                l4 = l4->next;
            }
            delete l1, l2, l3, l4, l5;
        }
    };
};


int main()
{
    Leetcode24::Solution s2;
    system("pause");
    return 0;
}