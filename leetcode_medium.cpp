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


class Leetcode29  // 两数相除（暴力方法超时了，用的官方题解）
{
public:
    class Solution 
    {
    public:
        int divide(int dividend, int divisor) 
        {
            // 考虑被除数为最小值的情况
            if (dividend == INT_MIN) 
            {
                if (divisor == 1) return INT_MIN;
                if (divisor == -1) return INT_MAX;
            }
            // 考虑除数为最小值的情况
            if (divisor == INT_MIN) return dividend == INT_MIN ? 1 : 0;

            // 考虑被除数为 0 的情况
            if (dividend == 0) return 0;
            
            // 一般情况，使用类二分查找
            // 将所有的正数取相反数，这样就只需要考虑一种情况
            bool rev = false;
            if (dividend > 0) 
            {
                dividend = -dividend;
                rev = !rev;
            }
            if (divisor > 0) 
            {
                divisor = -divisor;
                rev = !rev;
            }

            vector<int> candidates = {divisor};
            // 注意溢出
            while (candidates.back() >= dividend - candidates.back()) 
            {
                candidates.push_back(candidates.back() + candidates.back());
            }
            int ans = 0;
            for (int i = candidates.size() - 1; i >= 0; --i) 
            {
                if (candidates[i] >= dividend) 
                {
                    ans += (1 << i);
                    dividend -= candidates[i];
                }
            }

            return rev ? -ans : ans;
        }


        Solution()
        {
            cout << divide(7, -3) << endl;
        }
    };
};


class Leetcode31  // 下一个排列 (没做出来，用的官方题解)
{
public:
    class Solution {
    public:
        void nextPermutation(vector<int>& nums) 
        {
            int i = nums.size() - 2;
            while (i >= 0 && nums[i] >= nums[i + 1]) i--;
            if (i >= 0) 
            {
                int j = nums.size() - 1;
                while (j >= 0 && nums[i] >= nums[j]) j--;
                swap(nums[i], nums[j]);
            }
            reverse(nums.begin() + i + 1, nums.end());
        }

        Solution()
        {
            vector<int> nums = {9, 8 ,9};
            nextPermutation(nums);
            for (int i : nums)
            {
                cout << i << " ";
            }
        }
    };
};


class Leetcode33  // 搜索旋转排序数组 (二分+递归)
{
public:
    class Solution 
    {
    public:
        int search(vector<int>& nums, int target)  // 二分
        {
        int len = nums.size();
        if (len == 0) return -1;
        if (len == 1 && target == nums[0]) return 0;
        if (len == 1 && target != nums[0]) return -1;
        if (target == nums[0]) return 0;
        if (target == nums[len - 1]) return len - 1;
        return helpSearch(nums, 0, len - 1, target);
        }


        int helpSearch(vector<int>& nums, int left, int right, int target)
        {
            if (left >= right) return -1;
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target) return mid;
            if (nums[left] < nums[mid])
            {
                if (nums[mid] > target && target > nums[left])
                {
                    right = mid;
                    return helpSearch(nums, left, right, target);
                }
                else
                {
                    left = mid;
                    return helpSearch(nums, left, right, target);
                }
            }
            else if (left == mid) 
            {
                if (nums[left + 1] == target) return left + 1;
                return -1;
            }
            else
            {
                if (nums[mid] < target && target < nums[right])
                {
                    left = mid;
                    return helpSearch(nums, left, right, target);
                }
                else
                {
                    right = mid;
                    return helpSearch(nums, left, right, target);
                }
            }
        }


        Solution()
        {
            vector<int> nums = {4,5,6,7,0,1,2};
            cout << search(nums, 0) << endl;
        }
    };
};


class Leetcode34  // 在排序数组中查找元素的第一个和最后一个位置
{
public:
    class Solution 
    {
    public:
        vector<int> searchRange(vector<int>& nums, int target) 
        {
            int leftBorder = findPosL(nums, target);
            int rightBorder = findPosR(nums, target);
            if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
            if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};
            return {-1, -1};
        }


        int findPosR(vector<int>& nums, int target)
        {
            int left = 0, right = nums.size() - 1, mid = 0, posR = -2;
            while (left <= right)
            {
                mid = left + (right - left) / 2;
                if (nums[mid] > target) 
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                    posR = left;
                }
            }
            return posR;
        }


        int findPosL(vector<int>& nums, int target)
        {
            int left = 0, right = nums.size() - 1, mid = 0, posL = -2;
            while (left <= right)
            {
                mid = left + (right - left) / 2;
                if (nums[mid] < target) 
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                    posL = right;
                }
            }
            return posL;
        }


        Solution()
        {
            vector<int> rst;
            vector<int> nums = {1, 2, 2, 3, 3, 4};
            rst = searchRange(nums, 3);
            for (int i : rst)
            {
                cout << i << endl;
            }
        }
    };
};


class Leetcode36  // 有效的数独
{
public:
    class Solution 
    {
    public:
        bool isValidSudoku(vector<vector<char>>& board) 
        {
            vector<vector<int>> rows(9, vector<int>(9, 0));
            vector<vector<int>> columns(9, vector<int>(9, 0));
            vector<vector<vector<int>>> subboxes(3, vector<vector<int>>(3, vector<int>(9, 0)));
            for (int i = 0; i < 9; i++) 
            {
                for (int j = 0; j < 9; j++) 
                {
                    char c = board[i][j];
                    if (c != '.') 
                    {
                        int index = c - '0' - 1;
                        rows[i][index]++;
                        columns[j][index]++;
                        subboxes[i / 3][j / 3][index]++;
                        if (rows[i][index] > 1 || columns[j][index] > 1 || subboxes[i / 3][j / 3][index] > 1) 
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }


        Solution()
        {
            cout << "No examples." <<endl;
        }
    };
};


class Leetcode38  // 外观数列
{
public:
    class Solution 
    {
    public:
        string countAndSay(int n)   // 迭代
        {
            if (n == 1) return "1";
            if (n == 2) return "11";
            string rst = "";
            if (n > 1)
            {
                string cmp = countAndSay(n - 1);
                int count = 1;                            //  循环计数
                for (int i = 1; i < cmp.size(); i++)
                {
                    if (cmp[i] != cmp[i - 1])
                    {
                        rst += to_string(count);
                        rst += cmp[i - 1];
                        count  = 1;
                    }
                    else count++;
                    if (i == cmp.size() - 1)
                    {
                        rst += to_string(count);
                        rst += cmp[i];  
                    }
                }     
            }
            return rst;
        }


        Solution()
        {
            cout << countAndSay(2) << endl;
        }
    };
};


class Leetcode39  // 组合总和（回溯经典题）
{
public:
    class Solution 
    {
    public:
        vector<vector<int>> rst;
        vector<int> path;
        void backTracking(vector<int>& candidates, int target, int sum, int start)
        {
            if (sum > target) return;
            if (sum == target) { rst.emplace_back(path); return; }
            for (int i = start; i < candidates.size() && sum + candidates[i] <= target; i++)  // 横向for循环
            {
                sum += candidates[i];
                path.emplace_back(candidates[i]);
                backTracking(candidates, target, sum, i);  // 纵向靠递归
                sum -= candidates[i];
                path.pop_back();
            }
        }


        vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
        {
            sort(candidates.begin(), candidates.end());
            backTracking(candidates, target, 0, 0);
            return rst;
        }


        Solution()
        {
            vector<int> nums = {2, 3, 6, 7};
            vector<vector<int>> rst = combinationSum(nums, 7);
            for (int i = 0; i < rst.size(); i++)
            {
                for (int j = 0; j < rst[i].size(); j++)
                {
                    cout << rst[i][j] << " ";
                }
                cout << endl;
            }
        }
    };
};


class Leetcode40  // 组合总和2
{
public:
    class Solution 
    {
    public:
        vector<vector<int>> rst;
        vector<int> path;
        void backTracking(vector<int>& candidates, int target, int sum, int start)
        {
            if (sum == target) rst.emplace_back(path);
            if (sum > target) return;
            for (int i = start; i < candidates.size() && sum + candidates[i] <= target; i++)
            {
                if (i > start && candidates[i] == candidates[i - 1]) continue;
                sum += candidates[i];
                path.emplace_back(candidates[i]);
                backTracking(candidates, target, sum, i + 1);
                sum -= candidates[i];
                path.pop_back();
            }
        }


        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
        {
            sort(candidates.begin(), candidates.end());
            backTracking(candidates, target, 0, 0);
            return rst;
        }


        Solution()
        {
            vector<int> nums = {2, 3, 6, 7};
            vector<vector<int>> rst = combinationSum2(nums, 7);
            for (int i = 0; i < rst.size(); i++)
            {
                for (int j = 0; j < rst[i].size(); j++)
                {
                    cout << rst[i][j] << " ";
                }
                cout << endl;
            }
        }
    };
};


class Leetcode43  // 字符串相乘
{
public:
    class Solution 
    {
    public:
        string multiply(string num1, string num2) 
        {
            if (num1 == "0" || num2 == "0") return "0";
            if (num1 == "1") return num2;
            if (num2 == "1") return num1;
            int len1 = num1.size(), len2 = num2.size();
            vector<int> temp (len1 + len2 - 1, 0);
            for (int i = 0; i < len1; i++)
            {
                for (int j = 0; j < len2; j++)
                {
                    temp[i + j] += (num1[i] - '0') * (num2[j] - '0');
                }
            }
            for (int i = temp.size() - 1; i != 0; i--)
            {
                temp[i - 1] += temp[i] / 10;
                temp[i] = temp[i] % 10;
            }
            string ans;
            for (int i : temp) ans += to_string(i);
            return ans;
        }


        Solution()
        {
            string num1 = "44654654651321354684";
            string num2 = "119849898481313561648";
            cout << multiply(num1, num2) << endl;
        }
    };
};


class Leetcode45  // 跳跃游戏II
{
public:
    class Solution {
    public:
    int jump(vector<int>& nums) {  // 贪心算法，每次寻找从当前位置开始能到达的最远位置
        if (nums.size() == 1) return 0;
        if (nums[0] >= nums.size() - 1) return 1;
        int len = nums.size();
        int sum = 0, pos = 0, maxpos = 0, maxnum = 0;
        while (pos + nums[pos] < len - 1) {
            int p = pos;
            for (int i = p + 1; i <= p + nums[p] && i < len; i++){
                if (nums[i] + i> maxnum){
                    pos = i;
                    maxnum = nums[i] + i;
                }
            }
            sum += 1;
            maxnum = 0;
        }
        return ++sum;
    }


        Solution()
        {
            vector<int> nums = {2,3,1,1,4,5,2,4,2,3,6,1};
            cout << jump(nums) << endl;
        }
    };
};


class Leetcode46 {  // 全排列（回溯）
public:
    class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> rst;
            vector<int> path;
            backTracking(rst, path, nums);
            return rst;
        }


        void backTracking(vector<vector<int>>& rst, vector<int>& path, vector<int>& nums) {
            if (path.size() == nums.size()) {
                rst.push_back(path);
                return;
            }
            for (int num : nums) {
                if (find(path.begin(), path.end(), num) == path.end()) {
                    path.push_back(num);
                    backTracking(rst, path, nums);
                    path.pop_back();
                }
            }
        }


        Solution() {
            vector<int> num = {1, 2, 3};
            vector<vector<int>> rst = permute(num);
            for (vector<int> i : rst) {
                for (int j : i) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }


        /* 回溯模板 */
        /*
        result = []
        def backtrack(路径, 选择列表):
            if 满足结束条件:
                result.add(路径)
                return
            
            for 选择 in 选择列表:
                做选择
                backtrack(路径, 选择列表)
                撤销选择
        */



    };
};


class Leetcode47 {  // 全排列II（剪枝）
public:
    class Solution {
    public:
        void backTracking(vector<int>& nums, vector<int>& path, vector<vector<int>>& rst, vector<bool>& used) {
            if (path.size() == nums.size()) {
                rst.emplace_back(path);
                return;
            } 
            for (int i = 0; i < nums.size(); i++) {
                if (i != 0 && nums[i - 1] == nums[i] && used[i - 1] == false) {
                    continue;
                } 
                if (used[i] == false) {
                    used[i] = true;
                    path.emplace_back(nums[i]);
                    backTracking(nums, path, rst, used);
                    path.pop_back();
                    used[i] = false;
                }
            }
        }


        vector<vector<int>> permuteUnique(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<int> path;
            vector<vector<int>> rst;
            vector<bool> used(nums.size(), false);
            backTracking(nums, path, rst, used);
            return rst;
        }


        Solution() {
            vector<int> nums = {1, 1, 2};
            vector<vector<int>> rst = permuteUnique(nums);
            for (vector<int> num : rst) {
                for (int i : num) {
                    cout << i << " ";
                }
                cout << endl;
            }
        }
    };
};


class Leetcode48 {  // 旋转图像
public:
    class Solution {
        public:
            void rotate(vector<vector<int>>& matrix) {
                for (int i = 0; i < matrix.size(); i ++) {
                    for (int j  = i;  j < matrix[i].size(); j ++) {
                        swap(matrix[i][j], matrix[j][i]);
                    }
                }
                for (int i = 0; i < matrix.size(); i++) {
                    int left = 0, right = matrix[i].size() - 1;
                    while (left < right) {
                        swap(matrix[i][left++], matrix[i][right--]);
                    }
                }
            }


            Solution() {
                vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
                rotate(nums);
                for (vector<int> v : nums) {
                    for (int i : v) {
                        cout << i << " ";
                    }
                    cout << endl;
                }
            }
        };
};


class Leetcode49 {  // 字母异位词分组
public:
    class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {  // 只用数组做映射，耗时长但是需要的空间小
            vector<string> type;
            vector<vector<string>> rst(strs.size());
            vector<string> copy = strs;
            for (int i = 0; i < copy.size(); i++) {
                sort(copy[i].begin(), copy[i].end());
                if (find(type.begin(), type.end(), copy[i]) == type.end()) {
                    type.emplace_back(copy[i]);
                    rst[type.size() - 1].emplace_back(strs[i]);
                } else {
                    for (int j = 0; j < type.size(); j++) {
                        if (copy[i] == type[j]) {
                            rst[j].emplace_back(strs[i]);
                        }
                    }
                }
            }
            while (rst[rst.size() - 1].size() == 0) rst.pop_back();
            return rst;
        }


        /* 官方题解，和我的原理相同，只是用了map*/
        vector<vector<string>> groupAnagramsOfficial(vector<string>& strs) {
            unordered_map<string, vector<string>> mp;
            for (string& str: strs) {
                string key = str;
                sort(key.begin(), key.end());
                mp[key].emplace_back(str);
            }
            vector<vector<string>> ans;
            for (auto it = mp.begin(); it != mp.end(); ++it) {
                ans.emplace_back(it->second);
            }
            return ans;
        }


        Solution() {
            vector<string> strs = {"asd", "dsa", "SAD"};
            for (vector<string>i : groupAnagrams(strs)) {
                for (string j : i) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }

    };
};


class Leetcode50 {  // Pow(x, n) （没做出来，用的官方题解，这道题值得背一下）
public:
    class Solution {  
    public:
        double quickMul(double x, long long N) {
            if (N == 0) {
                return 1.0;
            }
            double y = quickMul(x, N / 2);
            return N % 2 == 0 ? y * y : y * y * x;
        }

        double myPow(double x, int n) {
            long long N = n;
            return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
        }


        Solution() {
            cout << myPow(2, 5);
        }
    };
};


class Leetcode54 {  // 螺旋矩阵
public:
    class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            if (matrix.empty() || matrix[0].empty()) return {};
            vector<int> res;
            int m = matrix.size(), n = matrix[0].size();
            int up = 0, down = m - 1, left = 0, right = n - 1;
            while (true) {
                for (int i = left; i <= right; i++) res.emplace_back(matrix[up][i]);
                if (++up > down) break;
                for (int i = up; i <= down; i++) res.emplace_back(matrix[i][right]);
                if (--right < left) break;
                for (int i = right; i >= left; i--) res.emplace_back(matrix[down][i]);
                if (--down < up) break;
                for (int i = down; i >= up; i--) res.emplace_back(matrix[i][left]);
                if (++left >right) break;
            }
            return res;
        }


        Solution() {
            vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}};
            for (int i : spiralOrder(nums)) cout << i << " ";
        }
    };
};


class Leetcode55 {  // 跳跃游戏
public:
    class Solution {
    public:
public:
        bool canJump(vector<int>& nums) {
            int n = nums.size();
            int rightmost = 0;
            for (int i = 0; i < n; ++i) {
                if (i <= rightmost) {
                    rightmost = max(rightmost, i + nums[i]);
                    if (rightmost >= n - 1) {
                        return true;
                    }
                }
            }
            return false;
        }


        Solution() {
            vector<int> nums = {1,1,1,0};
            cout << canJump(nums) << endl;
        }
    };
};


class Leetcode56 {  // 合并区间
public:
    class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            if (intervals.size() == 0) {
                return {};
            }
            sort(intervals.begin(), intervals.end());
            vector<vector<int>> merged;
            for (int i = 0; i < intervals.size(); ++i) {
                int L = intervals[i][0], R = intervals[i][1];
                if (!merged.size() || merged.back()[1] < L) {
                    merged.push_back({L, R});
                }
                else {
                    merged.back()[1] = max(merged.back()[1], R);
                }
            }
            return merged;
        }


        Solution() {
            cout << "Too lazy to generate an array";
        }
    };
};


class Leetcode57 {  // 插入区间
public:
    class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            if (intervals.size() == 0) return {newInterval};
            vector<vector<int>> rst;
            int i = 0, length = intervals.size();
            while (i < length && intervals[i][1] < newInterval[0]) {
                rst.push_back(intervals[i]);
                i++;
            }
            while (i < length && intervals[i][0] <= newInterval[1]) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                i++;
            }
            rst.push_back(newInterval);
            while (i < length) {
                rst.push_back(intervals[i]);
                i++;
            }
            return rst;
        }


        Solution() {
            cout << "Too lazy to generate an array";
        }
    };
};


class Leetcode59 {  // 螺旋矩阵II
public:
    class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> rst(n, vector<int>(n));
            int up = 0, down = n - 1, left = 0, right = n - 1;
            int count = 1;
            while (true) {
                for (int i = left; i <= right; i++) { 
                    rst[up][i] = count++;
                }
                for (int i = up + 1; i <= down; i++) { 
                    rst[i][right] = count++;
                }
                for (int i = right - 1; i >= left; i--) { 
                    rst[down][i] = count++;
                }
                for (int i = down - 1; i > up; i--) { 
                    rst[i][left] = count++;
                }
                up++, down--, left++, right--;
                if (count == (n * n) + 1) break;
            }
            return rst;
        }


        Solution() {
            for (vector<int> nums : generateMatrix(4)) {
                for (int i : nums) {
                    cout << i << " ";
                }
                cout << endl;
            }
        }
    };
};


class Leetcode61 {  // 旋转链表
public:
    class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if (!head) return nullptr;
            vector<ListNode*> array;
            ListNode* p = head;
            while (p) {
                array.push_back(p);
                p = p->next;
            }
            int n = array.size();
            vector<ListNode*> copy(n);
            for (int i = 0; i < n; i++) {
                copy[i] = array[(n + (i - (k % n))) % n];
            }
            for (int i = 0; i < n; i++) {
                if (i != n - 1) {
                    copy[i]->next = copy[i + 1];                    
                } else {
                    copy[i]->next = nullptr;
                }
            }
            return copy[0];
        }


        ListNode* rotateRightII(ListNode* head, int k) {  // 更好的方法
            if (!head) return nullptr;
            int count = 1;
            ListNode* p = head;
            while (p->next) {
                count++;
                p = p->next;
            }
            k %= count;
            p->next = head;
            for (int i = 0; i < count - k; i++) {
                p = p->next;
            }
            ListNode* rst = p->next;
            p->next = nullptr;
            return rst;
        }


        Solution() {
            ListNode* l1 = new ListNode(0);
            ListNode* l2 = new ListNode(1);
            ListNode* l3 = new ListNode(2);
            l1->next = l2;
            l2->next = l3;
            l1 = rotateRight(l1, 4);
            while (l1) {
                cout << l1->val << endl;
                l1 = l1->next;
            }
            delete(l1, l2, l3);
        }
    };
};


class Leetcode62 {  // 不同路径
public:
    class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m, vector<int>(n, 0));
            for (int i = 0;  i < n; i++) {
                dp[0][i] = 1;
            }
            for (int i = 0;  i < m; i++) {
                dp[i][0] = 1;
            }
            for (int j = 1; j < n; j++) {
                for (int i = 1; i < m; i++) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
            return dp[m - 1][n - 1];
        }


        Solution() {
            cout << uniquePaths(3, 7) << endl;
        }
    };
};


class Leetcode63 {  // 不同路径II
public:
    class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            if (obstacleGrid[0][0] == 1) return 0;
            int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
            if (obstacleGrid[rows - 1][cols - 1] == 1) return 0;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (obstacleGrid[i][j] == 1) obstacleGrid[i][j] = -1;
                }
            }
            obstacleGrid[0][0] = 1;
            for (int i = 0; i < rows; i++) {
                if (obstacleGrid[i][0] == -1) continue;
                if (i != 0 && obstacleGrid[i - 1][0] == 1) {
                    obstacleGrid[i][0] = 1;                
                }
            }
            for (int i = 0; i < cols; i++) {
                if (obstacleGrid[0][i] == -1) continue;
                if (i != 0 && obstacleGrid[0][i - 1] == 1) {
                    obstacleGrid[0][i] = 1;
                }
            }
            for (int i = 1; i < rows; i++) {
                for (int j = 1; j < cols; j++) {
                    if (obstacleGrid[i][j] == -1) continue;
                    if (obstacleGrid[i - 1][j] == -1 && obstacleGrid[i][j - 1] == -1) {
                        continue;
                    } else if (obstacleGrid[i - 1][j] == -1) {
                        obstacleGrid[i][j] = obstacleGrid[i][j - 1];
                    } else if (obstacleGrid[i][j - 1] == -1) {
                        obstacleGrid[i][j] = obstacleGrid[i - 1][j];
                    } else {
                        obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                    }
                }
            }
            return obstacleGrid[rows - 1][cols - 1];
        }
    };
};


class Leetcode64 {  // 最小路径和
public:
    class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            for (int i = 1; i < n; i++) {
                grid[0][i] += grid[0][i - 1];
            }
            for (int i = 1; i < m; i++) {
                grid[i][0] += grid[i - 1][0];
            }
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    grid[j][i] += min(grid[j - 1][i], grid[j][i - 1]);
                }
            }
            return grid[m - 1][n - 1];
        }


        Solution() {
            vector<vector<int>> nums = {{1, 2}, {3, 4}};
            cout << minPathSum(nums) << endl;
        }
    };
};


class Leetcode71 {  // 矩阵置零
public:
    class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            if (matrix.size() == 0 || matrix[0].size() == 0) return;
            int m = matrix.size(), n = matrix[0].size();
            bool row = false, column = false;
            for (int i = 0;  i < n; i++) {
                if (matrix[0][i] == 0) {
                    row = true;
                    break;
                }
            }
            for (int i = 0; i < m; i++) {
                if (matrix[i][0] == 0) {
                    column = true;
                    break;
                }
            }
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    if (matrix[j][i] == 0) {
                        matrix[0][i] = 0;
                        matrix[j][0] = 0;
                    }
                }
            }
            for (int i = 1; i < n; i++) {
                if (matrix[0][i] == 0) {
                    for (int j = 1; j < m; j++) {
                        matrix[j][i] = 0;
                    }
                }
            }
            for (int i = 1; i < m; i++) {
                if (matrix[i][0] == 0) {
                    for (int j = 1; j < n; j++) {
                        matrix[i][j] = 0;
                    }
                }
            }
            if (row) {
                for (int i = 0; i < n; i++) {
                    matrix[0][i] = 0;
                }
            }
            if (column) {
                for (int i = 0; i < m; i++) {
                    matrix[i][0] = 0;
                }
            }
        }


        Solution() {
            vector<vector<int>> nums = {{1, 0}};
            setZeroes(nums);
            for (vector<int> i : nums) {
                for (int j : i) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }
    };
};


class Leetcode72 {  // 搜索二维矩阵
public:
    class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix.size(), n = matrix[0].size();
            int low = 0, high = m * n - 1;
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if(target == matrix[mid / n][mid % n])
                    return true;
                else if(target > matrix[mid / n][mid % n])
                    low = mid + 1;
                else if(target < matrix[mid / n][mid % n])
                    high = mid - 1;
            }
            return false;
        }


        Solution() {
            vector<vector<int>> nums = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
            cout << searchMatrix(nums, 3) << endl;
        }
    };
};


class Leetcode75 {  // 颜色分类
public:
    class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int n = nums.size();
            int p0 = 0, p1 = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == 1) {
                    swap(nums[i], nums[p1]);
                    ++p1;
                } else if (nums[i] == 0) {
                    swap(nums[i], nums[p0]);
                    if (p0 < p1) {
                        swap(nums[i], nums[p1]);
                    }
                    ++p0;
                    ++p1;
                }
            }
        }


        Solution() {
            vector<int> nums = {2, 0, 0, 1, 2, 0};
            sortColors(nums);
            for (int i : nums) {
                cout << i << " ";
            }
        }
    };
};


class Leetcode77 {  // 组合
public:
    class Solution {
    public:
        void backTracking(vector<vector<int>>& rst, vector<int>& path, int n, int k, int pos) {
            if (path.size() == k) {
                rst.emplace_back(path);
                return;
            }
            for (int i = pos; i <= n; i++) {
                if (find(path.begin(), path.end(), i) == path.end()) {
                    if (path.size() != k - 1 && i == n ) return;
                    path.emplace_back(i);
                    backTracking(rst, path, n, k, i + 1);
                    path.pop_back();                
                }
            }
        }



        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> rst;
            vector<int> path;
            backTracking(rst, path, n, k, 1);
            return rst;
        }


        Solution() {
            vector<vector<int>> nums = combine(4, 3);
            for (vector<int> i : nums) {
                for (int j : i) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }
    };
};


class Leetcode78 {  // 子集
public:
    class Solution {
    public:
        vector<vector<int>> result;
        vector<int> path;
        void backtracking(vector<int>& nums, int startIndex) {  // 回溯
            result.push_back(path); 
            for (int i = startIndex; i < nums.size(); i++) {
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
            }
        }
        vector<vector<int>> subsets(vector<int>& nums) {  // 一次遍历
            vector<vector<int>> rst;
            rst.push_back({});
            for (int i = 0; i < nums.size(); i++) {
                int len = rst.size();
                for (int j = 0; j < len; j++) {
                    vector<int> path1 = rst[j];
                    path1.push_back(nums[i]);
                    rst.push_back(path1);
                }
            }
            return rst;
        }
        vector<vector<int>> subsetsRecursion(vector<int>& nums) {
            result.clear();
            path.clear();
            backtracking(nums, 0);
            return result;
        }


        Solution() {
            vector<int> nums = {1, 2, 3};
            for (vector<int> i : subsets(nums)) {
                for (int j : i) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }
    };
};


class Leetcode79 {  // 单词搜索(没懂)
public:
    class Solution {
    public:
        bool searchSlowOne(vector<vector<char>>& board, int i, int j, vector<vector<int>>& used, string& word, int pos) {
            if (board[i][j] != word[pos]) {
                return false;
            } else if (pos == word.size() - 1) {
                return true;
            }
            used[i][j] = true;
            vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            bool result = false;
            for (const auto& dir: directions) {
                int newi = i + dir.first, newj = j + dir.second;
                if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                    if (!used[newi][newj]) {
                        bool flag = searchSlowOne(board, newi, newj, used, word, pos + 1);
                        if (flag) {
                            result = true;
                            break;
                        }
                    }
                }
            }
            used[i][j] = false;
            return result;
        }

        // 很慢的回溯
        bool existSlowOne(vector<vector<char>>& board, string word) {
            vector<vector<int>> used(board.size(), vector<int>(board[0].size()));
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                        bool flag = searchSlowOne(board, i, j, used, word, 0);
                        if (flag) return true;
                    }
                }
            return false;
        }

        // 评论区方法
        bool exist(vector<vector<char>>& board, string word) {
            int m = board.size(), n = board[0].size();
            vector<int> cnt(128, 0);
            for (auto c : word) 
                ++cnt[c];

            if (cnt[word[0]] > cnt[word[word.size()-1]])    reverse(word.begin(), word.end());

            for (auto v : board)
                for (auto c : v)
                    --cnt[c];

            for (int i = 0; i < 128; ++i)
                if (cnt[i] > 0) return false;
            
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] == word[0] && dfs(board, word, 0, i, j)) {
                        return true;
                    }
                }
            }
            return false;
        }
        bool dfs(vector<vector<char>>& m, string s, int idx, int x, int y) {
            if (x < 0 || x >= m.size() || y < 0 || y >= m[0].size() || m[x][y] != s[idx])   return false;
            if (++idx == s.size())  return true;
            
            m[x][y] += 128;
            if (dfs(m, s, idx, x, y+1)) return true;
            if (dfs(m, s, idx, x, y-1)) return true;
            if (dfs(m, s, idx, x-1, y)) return true;
            if (dfs(m, s, idx, x+1, y)) return true;
            m[x][y] -= 128;

            return false;;
        }


        Solution() {
            vector<vector<char>> list1 = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
            cout << exist(list1, "ABCCED") << endl;
        }
    };
};


class Leetcode80 {  // 删除有序数组中的重复项 II
public:
    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {        
            if (nums.size() <= 2) return nums.size();
            for (int i = 0; i < nums.size() - 2; i++) {
                int slow = i, fast = i + 2;
                if (nums[slow] == nums[fast]) {
                    nums.erase(nums.begin() + fast);
                    i--;
                }
            }
            return nums.size();
        }


        Solution() {
            vector<int> nums = {1,1,1,1,2,2,3};
            cout << removeDuplicates(nums) << endl;
        }
    };
};


class Leetcode81 {  // 搜索旋转排序数组 II
public: 
    class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int l = 0, r = nums.size()-1;
            while(l<=r){
                //处理重复数字
                while(l<r&&nums[l]==nums[l+1]) ++l;
                while(l<r&&nums[r]==nums[r-1]) --r;
                int mid = l+(r-l)/2;
                if(nums[mid]==target) return true;
                //左半部分有序
                if(nums[mid]>=nums[l]){
                    if(target<nums[mid]&&target>=nums[l]) r = mid-1;//target落在左半边
                    else l = mid+1;
                }
                else{//右半部分有序
                    if(target>nums[mid]&&target<=nums[r]) l = mid+1;//target落在右半边
                    else r = mid-1;
                }
            }
            return false;
        }


        Solution() {
            vector<int> nums = {1,1,1};
            cout << search(nums, 2) << endl;
        }
    };
};


class Leetcode82 {  // 删除排序链表中的重复元素 II
public:
    class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if (!head || !head->next) {
                return head;
            }
            ListNode* p = head;
            int temp = head->val;
            while (p && p->next && p->val == p->next->val) {
                temp = p->val;
                while (temp == p->val) {
                    p = p->next;
                    if (!p) break;
                }
            }
            head = p;
            while (p) {
                if (!p->next) break;
                if (p->next->next && (p->next->next->val == p->next->val)) {
                    temp = p->next->val;
                    if (p->next->next->next) {
                        p->next = p->next->next->next;                    
                    } else {
                        p->next = nullptr;
                    }
                } else if (p->next && p->next->val == temp) {
                    p->next = p->next->next;
                } else if ((!p->next->next && p->next) || (!p->next)) {
                    return head;
                } else {
                    p = p->next;
                }
            }
            return head;
        }

        Solution() {
            ListNode* l1 = new ListNode(4);
            ListNode* l2 = new ListNode(4);
            ListNode* l3 = new ListNode(4);
            ListNode* l4 = new ListNode(5);
            ListNode* l5 = new ListNode(6);
            ListNode* l6 = new ListNode(7);
            l1->next = l2;
            l2->next = l3;
            l3->next = l4;
            l4->next = l5;
            l5->next = l6;
            l1 = deleteDuplicates(l1);
            while (l1) {
                cout << l1->val << endl;
                l1 = l1->next;
            }
        }
    };
};


class Leetcode86 {  // 分隔链表
public:
    class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            vector<ListNode*> small, big;
            ListNode* p = head;
            while (p) {
                if (p->val < x) {
                    small.push_back(p);
                } else {
                    big.push_back(p);
                }
                p = p->next;
            }
            if (small.size() == 0 || big.size() == 0) return head; 
            for (int i = 0; i < small.size() - 1; i++) {
                small[i]->next = small[i + 1];
            }
            small[small.size() - 1]->next = big[0];
            for (int i = 0; i < big.size() - 1; i++) {
                big[i]->next = big[i + 1];
            }
            big[big.size() - 1]->next = nullptr;
            return small[0];
        }


        Solution() {
            ListNode* l1 = new ListNode(1);
            ListNode* l2 = new ListNode(4);
            ListNode* l3 = new ListNode(3);
            ListNode* l4 = new ListNode(2);
            ListNode* l5 = new ListNode(5);
            ListNode* l6 = new ListNode(2);
            l1->next = l2;
            l2->next = l3;
            l3->next = l4;
            l4->next = l5;
            l5->next = l6;
            l1 = partition(l1, 0);
            while (l1) {
                cout << l1->val << endl;
                l1 = l1->next;
            }
        }
    };
};


class Leetcode89 {  // 格雷编码
public:
    class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> ret(1 << n);
            for (int i = 0; i < ret.size(); i++) {
                ret[i] = (i >> 1) ^ i;
            }
            return ret;
        }


        Solution() {
            for (int i : grayCode(3)) {
                cout << i << " ";
            }
        }
    };
};


class Leetcode90 {  // 子集 II
public:
    class Solution {
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> rst;
            vector<int> path;
            vector<bool> used(nums.size(), false);
            sort(nums.begin(), nums.end());
            trace(rst, path, nums, used, 0);
            return rst;
        }


        void trace(vector<vector<int>>& rst, vector<int>& path, vector<int>& nums, vector<bool>& used, int pos) {
            rst.emplace_back(path);
            for (int i = pos; i < nums.size(); i++) {
                if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                    continue;
                }
                path.emplace_back(nums[i]);
                used[i] = true;
                trace(rst, path, nums, used, pos + 1);
                used[i] = false;
                path.pop_back();
            }
        }


        Solution() {
            vector<int> nums = {1, 2, 2};
            vector<vector<int>> rst = subsetsWithDup(nums);
            for (vector<int> i : rst) {
                for (int j : i) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }
    };
};


class Leetcode91 {  //  解码方法
public:
    class Solution {
    public:
        int numDecodings(string s) {
            int cnt = 0;
            if(s.size() == 0 || (s.size() == 1 && s[0] == '0')) return 0;
            if(s.size() == 1) return 1;
            vector<int> dp(s.size() + 1, 0);
            dp[0] = 1;
            for(int i = 0; i < s.size(); ++i){
                dp[i+1] = s[i] == '0' ? 0 : dp[i];
                if(i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))){
                    dp[i+1] += dp[i-1];
                }
            }
            return dp.back();
        }


        Solution() {
            cout << numDecodings("101110") << endl;
        }
    };
};


class Leetcode92 {  // 反转链表II
public:
    class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if (left == right) return head;
            ListNode* dummyhead = new ListNode(0, head);
            ListNode* pleft = dummyhead;
            int counter = 1;
            stack<ListNode*> sta;
            while (counter <= left - 1) {
                pleft = pleft->next;
                counter++;
            }
            ListNode* rec = pleft->next;
            while (left <= right) {
                sta.push(rec);
                rec = rec->next;
                left++;
            }
            ListNode* pright = rec;
            while (sta.size() != 0) {
                pleft->next = sta.top();
                pleft = pleft->next;
                sta.pop();
            }
            pleft->next = pright;
            return dummyhead->next;
        }


        ListNode *reverseBetweenOfficial(ListNode *head, int left, int right) {  // 官方题解
            ListNode *dummyNode = new ListNode(-1);
            dummyNode->next = head;
            ListNode *pre = dummyNode;
            for (int i = 0; i < left - 1; i++) {
                pre = pre->next;
            }
            ListNode *cur = pre->next;
            ListNode *next;
            for (int i = 0; i < right - left; i++) {
                next = cur->next;
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
            }
            return dummyNode->next;
        }

        Solution() {
            cout << "Too lazy to generate a linked list." << endl;
        }
    };
};


class Leetcode93 {  // 复原IP地址（没做出来）
public:
    class Solution {
    private:
        vector<string> result;// 记录结果
        // startIndex: 搜索的起始位置，pointNum:添加逗点的数量
        void backtracking(string& s, int startIndex, int pointNum) {
            if (pointNum == 3) { // 逗点数量为3时，分隔结束
                // 判断第四段子字符串是否合法，如果合法就放进result中
                if (isValid(s, startIndex, s.size() - 1)) {
                    result.push_back(s);
                }
                return;
            }
            for (int i = startIndex; i < s.size(); i++) {
                if (isValid(s, startIndex, i)) { // 判断 [startIndex,i] 这个区间的子串是否合法
                    s.insert(s.begin() + i + 1 , '.');  // 在i的后面插入一个逗点
                    pointNum++;
                    backtracking(s, i + 2, pointNum);   // 插入逗点之后下一个子串的起始位置为i+2
                    pointNum--;                         // 回溯
                    s.erase(s.begin() + i + 1);         // 回溯删掉逗点
                } else break; // 不合法，直接结束本层循环
            }
        }
        // 判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
        bool isValid(const string& s, int start, int end) {
            if (start > end) {
                return false;
            }
            if (s[start] == '0' && start != end) { // 0开头的数字不合法
                    return false;
            }
            int num = 0;
            for (int i = start; i <= end; i++) {
                if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                    return false;
                }
                num = num * 10 + (s[i] - '0');
                if (num > 255) { // 如果大于255了不合法
                    return false;
                }
            }
            return true;
        }
    public:
        vector<string> restoreIpAddresses(string s) {
            result.clear();
            if (s.size() > 12) return result; // 算是剪枝了
            backtracking(s, 0, 0);
            return result;
        }


        Solution() {
            cout << "Nothing." << endl;
        }
    };
};


class Leetcode95 {  // 不同的二叉搜索树 II(没做出来)
public:
    class Solution {
    public:
        vector<TreeNode*> generateTrees(int start, int end) {
            if (start > end) {
                return { nullptr };
            }
            vector<TreeNode*> allTrees;
            // 枚举可行根节点
            for (int i = start; i <= end; i++) {
                // 获得所有可行的左子树集合
                vector<TreeNode*> leftTrees = generateTrees(start, i - 1);

                // 获得所有可行的右子树集合
                vector<TreeNode*> rightTrees = generateTrees(i + 1, end);

                // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
                for (auto& left : leftTrees) {
                    for (auto& right : rightTrees) {
                        TreeNode* currTree = new TreeNode(i);
                        currTree->left = left;
                        currTree->right = right;
                        allTrees.emplace_back(currTree);
                    }
                }
            }
            return allTrees;
        }

        vector<TreeNode*> generateTrees(int n) {
            if (!n) {
                return {};
            }
            return generateTrees(1, n);
        }


        Solution() {
            cout << "Too lazy to generate a tree." << endl;
        }
    };
};


class Leetcode96 {  // 不同的二叉搜索树
public:
    class Solution {
    public:
        int numTrees(int n) {
            vector<int> dp(n + 1);
            dp[0] = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    dp[i] += dp[j - 1] * dp[i - j];
                }
            }
            return dp[n];
        }


        Solution() {
            cout << numTrees(5) << endl;
        }
    };
};


class Leetcode97 {  // 交错字符串
public:
    class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            int len1 = (int) s1.size();
            int len2 = (int) s2.size();
            int len3 = (int) s3.size();
            if (len1 + len2 != len3) return false;
            vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
            dp[0][0] = true;
            for (int i = 1; i <= len1; i++) {
                dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
            }
            for (int j = 1; j <= len2; j++) {
                dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
            }
            for (int i = 1; i <= len1; i++) {
                for (int j = 1; j <= len2; j++) {
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
            return dp[len1][len2];
        }


        Solution() {
            cout << isInterleave("aabcc","dbbca","aadbbcbcac");
        }
    };
};


class Leetcode98 {  // 验证二叉搜索树
public:
    class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            vector<int> nums;
            inorderTraverse(nums, root);
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] >= nums[i + 1]) {
                    return false;
                }
            }
            return true;
        }


        void inorderTraverse(vector<int>& nums, TreeNode* root) {
            if (root->left) {
                inorderTraverse(nums, root->left);
            }
            nums.push_back(root->val);
            if (root->right) {
                inorderTraverse(nums, root->right);
            }
        }


        Solution() {
            cout << "Too lazy to generate a tree." << endl;
        }
    };
};


class Leetcode99 {  // 恢复二叉树
public:
    class Solution {
    private:
        int count = 0;
    public:
        void inorderTraverse(vector<int>& nums, TreeNode* root) {
            if (!root) return;
            if (root->left) {
                inorderTraverse(nums, root->left);
            }
            nums.push_back(root->val);
            if (root->right) {
                inorderTraverse(nums, root->right);
            }
        }

        void getTree(vector<int>& nums, TreeNode* root) {
            if (root->left) {
                getTree(nums, root->left);
            }
            root->val = nums[count++];
            if (root->right) {
                getTree(nums, root->right);
            }
        }

        void recoverTree(TreeNode* root) {
            vector<int> nums;
            int left = -1, right = -1;
            inorderTraverse(nums, root);
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1] && left == -1) {
                    left = i;
                    continue;
                }
                if (nums[i] > nums[i + 1]) {
                    right = i + 1;
                    break;
                }
            }
            right == -1 ? swap(nums[left], nums[left + 1]) : swap(nums[left], nums[right]);
            getTree(nums, root);
        }


        Solution() {
            cout << "Too lazy to generate a tree." << endl;
        }
    };
};


class Leetcode102 {  // 二叉树的层序遍历
public:
    class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            if (!root) return {};
            deque<TreeNode*> que;
            vector<vector<int>> rst;
            que.push_back(root);
            while (!que.empty()) {
                vector<int> path;
                int len = que.size();
                for (int i = 0; i < len; i++) {
                    path.push_back(que.front()->val);
                    if (que.front()->left) {
                        que.push_back(que.front()->left);
                    }
                    if (que.front()->right) {
                        que.push_back(que.front()->right);
                    }
                    que.pop_front();
                }
                rst.push_back(path);
            }
            return rst;
        }


        Solution() {
            cout << "Too lazy to generate a tree.";
        }
    };
};


class Leetcode103 {  // 二叉树的锯齿形层序遍历
public:
    class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int> > res;
            if(!root) return res;
            
            queue<TreeNode *> q;
            q.push(root);
            int flag = 0;
            while(!q.empty()) {
                vector<int> out;
                int size = q.size(); //取得每一层的长度
                for(int i = 0; i < size; i++) {
                    auto temp = q.front();
                    q.pop();
                    out.push_back(temp->val);
                    if(temp->left) {
                        q.push(temp->left);
                    }
                    if(temp->right) {
                        q.push(temp->right);
                    }
                }
                if(flag%2==1) {
                    reverse(out.begin(),out.end());
                }
                res.push_back(out);
                flag++;
            }
            return res;
        }


        Solution() {
            cout << "Too lazy to generate a tree" << endl;
        }
    };
};


class Leetcode104 {  // 从前序与中序遍历序列构造二叉树
public:
    class Solution {
    public:
        TreeNode* find(vector<int>& preorder, vector<int>& inorder) {
            int rootval = preorder[0];
            TreeNode* root = new TreeNode(rootval);
            vector<int> leftpre, rightpre, leftin, rightin;
            int flag = 0;
            for (int i = 0; i < inorder.size(); i++) {
                if (rootval != inorder[i] && flag == 0) {
                    leftin.push_back(inorder[i]);
                }
                if (rootval == inorder[i]) {
                    flag = 1;
                }
                if (rootval != inorder[i] && flag == 1) {
                    rightin.push_back(inorder[i]);
                }
            }
            for (int i = 1; i < preorder.size(); i++) {
                if (leftpre.size() != leftin.size()) {
                    leftpre.push_back(preorder[i]);
                } else {
                    rightpre.push_back(preorder[i]);
                }
            }
            if (leftpre.size() != 0) {
                root->left = find(leftpre, leftin);
            }
            if (rightpre.size() != 0) {
                root->right = find(rightpre, rightin);
            }
            return root;
        }


        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            return find(preorder, inorder);
        }


        Solution() {
            vector<int> preOrder = {3, 9, 20, 15, 7};
            vector<int> inOrder = {9, 3, 15, 20, 7};
            TreeNode* rst = buildTree(preOrder, inOrder);
        }
    };
};


class Leetcode106 {  // 从中序与后序遍历序列构造二叉树
public:
    class Solution {
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int rootval = postorder[postorder.size() - 1];
            TreeNode* root = new TreeNode(rootval);
            vector<int> leftpre, rightpre, leftin, rightin;
            int flag = 0;
            for (int i = 0; i < inorder.size(); i++) {
                if (rootval != inorder[i] && flag == 0) {
                    leftin.push_back(inorder[i]);
                }
                if (rootval == inorder[i]) {
                    flag = 1;
                }
                if (rootval != inorder[i] && flag == 1) {
                    rightin.push_back(inorder[i]);
                }
            }
            for (int i = 0; i < postorder.size() - 1; i++) {
                if (leftpre.size() != leftin.size()) {
                    leftpre.push_back(postorder[i]);
                } else {
                    rightpre.push_back(postorder[i]);
                }
            }
            if (leftpre.size() != 0) {
                root->left = buildTree(leftin, leftpre);
            }
            if (rightpre.size() != 0) {
                root->right = buildTree(rightin, rightpre);
            }
            return root;
        }


        Solution() {
            vector<int> postOrder = {9, 15, 7, 20, 3};
            vector<int> inOrder = {9, 3, 15, 20, 7};
            TreeNode* rst = buildTree(inOrder, postOrder);
        }
    };
};


class Leetcode107 {  // 二叉树的层序遍历 II
public:
    class Solution {
    public:
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            if (!root) return {};
            deque<TreeNode*> que;
            vector<vector<int>> rst;
            que.push_back(root);
            while (!que.empty()) {
                vector<int> path;
                int len = que.size();
                for (int i = 0; i < len; i++) {
                    path.push_back(que.front()->val);
                    if (que.front()->left) {
                        que.push_back(que.front()->left);
                    }
                    if (que.front()->right) {
                        que.push_back(que.front()->right);
                    }
                    que.pop_front();
                }
                rst.push_back(path);
            }
            reverse(rst.begin(), rst.end());
            return rst;
        }
    };
};


class Leetcode109 {  // 有序链表转换二叉搜索树
public:
    class Solution {
    public:
        TreeNode* sortedListToBST(ListNode* head) {
            if (!head) return nullptr;
            if (!head->next) return new TreeNode(head->val);
            ListNode* fast = head,* slow = head,* mid = nullptr;
            while (fast && fast->next) {
                fast = fast->next->next;
                mid = slow;
                slow = slow->next;
            }
            mid->next = nullptr;
            ListNode* right = slow->next;
            TreeNode* root = new TreeNode(slow->val);
            root->left = sortedListToBST(head);
            root->right = sortedListToBST(right);
            return root;
        }
    };
};


class Leetcode113 {  // 路经总和
public:
    class Solution {
    public:
        void backTracking(TreeNode* node, int sum, int targetSum, vector<int>& path, vector<vector<int>>& rst) {
            if (node) {
                if (sum == targetSum && !node->left && !node->right) {
                    rst.push_back(path);
                }
            }
            if (node->left) {
                path.push_back(node->left->val);
                sum += node->left->val;
                backTracking(node->left, sum, targetSum, path, rst);
                path.pop_back();
                sum -= node->left->val;
            }
            if (node->right) {
                path.push_back(node->right->val);
                sum += node->right->val;
                backTracking(node->right, sum, targetSum, path, rst);
                path.pop_back();
                sum -= node->right->val;
            }
        }



        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            if (!root) return {};
            vector<int> path;
            vector<vector<int>> rst;
            path.push_back(root->val);
            backTracking(root, root->val, targetSum, path, rst);
            return rst;
        }


        Solution() {
            cout << "Too lazy to generate a tree." << endl;
        }
    };
};


class Leetcode114 {  // 二叉树展开为链表
public:
    class Solution {
    public:
        void flatten(TreeNode* root) {
            if (!root) return;
            if (root->left) {
                flatten(root->left);
            }
            if (root->right) {
                flatten(root->right);
            }
            TreeNode* rec = nullptr, *pleft = root;
            if (root->left && root->right) {
                rec = root->right;
                root->right = root->left;
                while (pleft->right) {
                    pleft = pleft->right;
                }
                pleft->right = rec;
                root->left = nullptr;
            } else if (root->left && !root->right) {
                root->right = root->left;
                root->left = nullptr;
            } else return;
        }


        Solution() {
            TreeNode* t1 = new TreeNode(1);
            TreeNode* t2 = new TreeNode(2);
            TreeNode* t3 = new TreeNode(3);
            t1->left = t2, t1->right = t3;
            flatten(t1);
            delete(t1, t2, t3);
        }
    };
};


class Leetcode120 {  // 三角形最小路径和
public:
    class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int len = triangle.size();
            for (int i = 1; i < len; i++) {
                for (int j = 0; j < triangle[i].size(); j++) {
                    if (j == 0) {
                        triangle[i][j] += triangle[i - 1][j];
                    } else if (j != triangle[i].size() - 1){
                        triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                    } else {
                        triangle[i][j] += triangle[i - 1][j - 1];
                    }
                }
            }
            return *min_element(triangle[len - 1].begin(), triangle[len - 1].end());
        }


        Solution() {
            vector<int> p1 = {1};
            vector<int> p2 = {2, 3};
            vector<vector<int>> nums;
            nums.push_back(p1);
            nums.push_back(p2);
            cout << minimumTotal(nums) << endl;
        }
    };
};


class Leetcode122 {  // 买卖股票的最佳时机 II
public:
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int profit = 0;
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] > prices[i - 1]) {
                    profit += (prices[i] - prices[i - 1]);
                }
            }
            return profit;
        }


        Solution() {
            vector<int> nums = {1, 2, 3, 4, 5};
            cout << maxProfit(nums) << endl;
        }
    };
};


class Leetcode129 {  // 求根节点到叶节点数字之和
public:
    class Solution {
    public:
        void backTracking(TreeNode* root, int& sum, int& path) {
            if (!root) return;
            if (!root->left && !root->right) {
                sum += path;
                sum += root->val;      
                return;      
            }
            if (root->left) {
                path += root->val;
                path *= 10;
                backTracking(root->left, sum, path);
                path /= 10;
                path -= root->val;
            }
            if (root->right) {
                path += root->val;
                path *= 10;
                backTracking(root->right, sum, path);
                path /= 10;
                path -= root->val;
            }
        }

        int sumNumbers(TreeNode* root) {
            int sum = 0, path = 0;
            backTracking(root, sum, path);
            return sum;
        }


        Solution() {
            cout << "Too lazy to generate a tree." << endl;
        }
    };
};

int main()
{
    Leetcode114::Solution s2;
    system("pause");
    return 0;
}