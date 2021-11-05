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
#include"leetcode_easy_head.h"
using namespace std;


class Leetcode1  // Two Sum
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


class Leetcode2  // Reverse Integer
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


class Leetcode3  // Palindrome Number
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


class Leetcode4  // Roman to Integer
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


class Leetcode5  // Longest Common Prefix
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


class Leetcode6  // Judge the legitimacy of the brackets
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


class Leetcode7  // Combine sorted linked list(recursion)
{
public:
    class Solution {
    public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if (!l1) {return l2;}
        if (!l2) {return l1;}
        if (l1->val > l2->val) { return mergeTwoLists(l2, l1); }
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }


    Solution()
    {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    l1->next = l2;
    ListNode *l3 = new ListNode(4);
    l2->next = l3;
    ListNode *l4 = new ListNode(1);
    ListNode *l5 = new ListNode(3);
    l4->next = l5;
    ListNode *l6 = new ListNode(4);
    l5->next = l6;
    ListNode* lst = mergeTwoLists(l1, l4);
    cout << lst->val << endl;
    cout << lst->next->val << endl;
    cout << lst->next->next->val << endl;
    cout << lst->next->next->next->val << endl;
    cout << lst->next->next->next->next->val << endl;
    cout << lst->next->next->next->next->next->val << endl;
    }
};
};


class Leetcode8  // Remove duplicate elements of the sorted array
{
public:
    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) 
        {
	        if (nums.size() < 2) return nums.size();
	        int j = 0;
	        for (int i = 1; i < nums.size(); i++)
		    if (nums[j] != nums[i]) nums[++j] = nums[i];
	        return ++j;
        }


        Solution()
        {
            vector<int> nums;
            nums.push_back(1);
            nums.push_back(1);
            nums.push_back(2);
            nums.push_back(2);
            nums.push_back(2);
            nums.push_back(3);
            nums.push_back(4);
            nums.push_back(5);
            nums.push_back(6);
            nums.push_back(8);
            nums.push_back(8);
            nums.push_back(8);
            nums.push_back(9);
            int j = removeDuplicates(nums);
            for (int m = 0; m <j; m++)
            {
                cout << nums[m] << endl;
            }  
        }
};
};


class Leetcode9  // Remove element
{
public:
    class Solution {
    public:
        int removeElement(vector<int>& nums, int val) 
        {
            /*  垃圾牄1�71ￄ1�77
            int length = nums.size();
            for (int i = 0; i < nums.size()-1; i++)
            {
                if (nums[i] == val) 
                {
                    for (int j = i; j < nums.size()-1; j++)
                    {   
                        nums[j] = nums[j+1];
                    }
                    length--;
                    if (nums[i] == val) 
                    {
                        i--;
                    }
                }
            }
            return length;
            */


           // 正向判断的好方法
           int k = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] != val) 
                {
                    nums[k++] = nums[i];
                }
            }
            return k;
            }   


        Solution()
        {
            vector<int> nums;
            nums.push_back(3);
            nums.push_back(2);
            nums.push_back(2);
            nums.push_back(3);
            nums.push_back(2);
            nums.push_back(3);
            nums.push_back(4);
            nums.push_back(5);
            nums.push_back(6);
            nums.push_back(8);
            nums.push_back(8);
            nums.push_back(8);
            nums.push_back(9);
            int j = removeElement(nums, 3);
            cout << j<< endl;
            for (int i = 0; i < j; i++) {
                cout << nums[i]<< endl;
            }            
        }
};
};


class Leetcode10  // Find substr's position
{
public:
    class Solution 
    {
    public:
        int strStr(string haystack, string needle) {
        if(!needle.size()) return 0;
        for(int i = 0; i + needle.size() <= haystack.size(); i ++)
            if(haystack.substr(i, needle.size()) == needle) return i;  // substr函数做了丢�个切片复制的功能
        return -1;
    }


        Solution()
        {
            string source = "apple";
            string target = "ppl";
            int pos = strStr(source, target);
            cout << pos << endl;
        }
    };
};


class Leetcode11  // Find element's position
{
public:
    class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) 
        {
            int i = -1;
            for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
            {
                i++;
                if (target < *it)  {return 0;}
                if (*it==target)
                {
                    return i;
                }
                if (it+1 != nums.end())
                {
                    if (target > (*it) && target < (*(it + 1)))
                    {
                    return i+1;
                    }
                }  
            }
            return i + 1;
        }


        Solution()
        {
            vector<int>nums = {1, 2, 3, 4, 5};
            int pos = searchInsert(nums, 2);
            cout << pos << endl;
        }
    };
};


class Leetcode12  // Look for the sum of the largest subsequences
{
public:
    class Solution {
    public:
        int maxSubArray(vector<int>& nums) 
        {
            int max = INT_MIN;
            if (nums.size() == 1){return nums[0];}
            for (vector<int>::iterator it = (nums.begin()+1); it != nums.end(); it++)
            {
                if (*(it-1) < 0){continue;}
                else
                {
                    *it += (*(it-1));
                }
            }
            return *max_element(nums.begin(), nums.end());
        }


        Solution()
        {
            vector<int> nums = {-1, 2, 3,  -4,  5, 7, -3, 4, 6};
            int max_num = maxSubArray(nums);
            cout << max_num << endl;
        }
    };
};


class Leetcode13  // Figure out the length of the last word
{
public:
    class Solution 
    {
    public:
        int lengthOfLastWord(string s) 
        {
            int count = 0, j = 0;
            for (j = s.length() - 1; s[j] == ' '; j--);
            s = s.substr(0, j);
            for (int i = s.length(); i != 0; i--)
            {
                if (s[i] != ' ' && s[i - 1] != ' ')
                {
                    count++;
                }
                else if(s[i] != ' ' && s[i-1] == ' '){break;}
            }
            return count+1;
        }


        Solution()
        {
            string ss = "world  ";
            int len = lengthOfLastWord(ss);
            cout <<  len << endl;
        }
    };
};


class Leetcode14  // Plus 1
{
public:
    class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int count = 0;
            vector<int>::iterator it = digits.end();
            vector<int>::iterator iter = it;
            if (*(it-1) != 9)
            {
            *(it-1) += 1;
            return digits;
            }
            for (vector<int>::iterator i = digits.begin(); i != digits.end(); i++)
            {
                if (*i == 9){ count++;}
            }
            if (count == digits.size())
            {
                digits[0] = 1;
                for (int i=1; i < digits.size(); i++)
                {
                    digits[i] = 0;
                }
                digits.push_back(0);
            }
            else
            {
            for (iter = digits.end(); *(iter - 1) == 9; iter--);
            *(iter-1) += 1;
            for (; iter != digits.end(); iter++)
            {*iter = 0;}
            }
            return digits;
        }


        Solution()
        {
            vector<int>nums = {1, 9, 9};
            nums = plusOne(nums);
            for (vector<int>::iterator it = nums.begin(); it !=nums.end(); it++)
            {
                cout << *it << " ";
            }
        }
    };
};


class Leetcode15  // Binary addition
{
public:
    class Solution {
    public:
        string addBinary(string a, string b) 
        {
            string res="";
            int la=a.length(),lb=b.length(),lm=max(la,lb);
            //加前导零对齐
            for(int i=la;i<lm;i++) a="0"+a;
            for(int i=lb;i<lm;i++) b="0"+b;
            //进位
            int carry=0;
            //模拟全加器，分别计算结果和进位�ￄ1�71ￄ1�77
            for(int i=lm-1;i>=0;i--)
            {
                /*两位是a,b,上一位进位是c0,这一位进位是c,结果是s
                **s=a^b^c0
                **c=a&b|(c0&(a^b))
                */
                char temp=(a[i]-'0')^(b[i]-'0')^(carry)+'0';
                carry=((a[i]-'0')&(b[i]-'0'))|(carry&((a[i]-'0')^(b[i]-'0')));
                res=temp+res;
            }
            //如果算完还有进位，需要补丄1�71ￄ1�771
            if(carry==1)
                res="1"+res;
            return res;
        }


        Solution()
        {
            string a = "10111";
            string b = "100111001";
            string out = addBinary(a, b);
            cout << out <<endl;
        }
    };
};


class Leetcode16  // Square root (Newton iterative method)
{                 //https://www.zhihu.com/question/20690553/answer/543620219
public:
    class Solution {
    public:
        int mySqrt(int x) 
        {
            if (x <= 1) return x;
            long r = x;  // 当x达到INT_MAX时会发生数��溢出，故将原来的int r改为long r
            while (r > x / r)
            {
                r = (r + x / r) / 2;
            }
            return int(r);
        }


        Solution()
        {
            int test = 105;
            int rst = mySqrt(test);
            cout << rst << endl;
        }
    };
};


class Leetcode17  // Jump the steps
{
public:
    class Solution {
    public:
        /* 递归方法可以运行但是不够快捷，超出了力扣的时间要汄1�71ￄ1�77
        int climbStairs(int n) 
        {
            if (n == 1) return 1;
            if (n == 2) return 2;
            else
            {
            return climbStairs(n - 1) + climbStairs(n - 2);
            }
        }
        */


        int climbStairs(int n) 
        {
            if (n <= 1) return n;
            int dp[3];
            dp[1] = 1;
            dp[2] = 2;
            for (int i = 3; i <= n; i++) 
            {
                int sum = dp[1] + dp[2];
                dp[1] = dp[2];
                dp[2] = sum;
            }
            return dp[2];
        }


        Solution()
        {
            int num =10;
            int ways = climbStairs(num);
            cout << ways << endl;
        }
    };
};


class Leetcode18  // Remove duplicate elements of the sorted list
{
public:
    class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) 
        {
            if (!head) {return head;}
            ListNode *p = head;
            while (p->next)
            {
                if (p->next->next)
                {
                    if (p->val == p->next->val)
                    {
                        p->next = p->next->next;
                    }
                    else {p = p->next;}
                }
                else if (!p->next->next)
                {
                    if (p->val == p->next->val)
                    {
                        p->next = nullptr;
                    }
                    else break;
                }
            }
            return head;
        }


        Solution()
        {
            ListNode l1(2);
            ListNode l2(1);
            ListNode l3(1);
            ListNode l4(3);
            ListNode l5(3);
            l3.next = &l2;
            l2.next = &l1;
            l1.next = &l4;
            l4.next = &l5;
            ListNode* lst = deleteDuplicates(&l3);
            cout << lst->val << endl;
            cout << lst->next->val << endl;
            cout << lst->next->next->val << endl;
        }
};
};


class Leetcode19  // Combine arrays
{
public:
    class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
        {
            if (m == 0) nums1 = nums2;
            if (n == 0) nums1 = nums1;
            int k = 0;
            for (int i = m; i < (m + n); i++)
            {
                nums1[i] = 513;
            }
            for (int i = 0; i < m + n; i++)
            {
                if (nums1[i] > nums2[k])
                {
                    for (int j = m + n - 1; j > i; j--)
                    {
                        nums1[j] = nums1[j - 1];
                    }
                    nums1[i] = nums2[k++];
                    if (k == n) { break; }
                }
                else
                {
                    for (i = i; nums1[i] <= nums2[k]; i++);
                    i--;
                }
            }
        }


        Solution()
        {
            vector<int>nums1 = {1, 2, 3, 0, 0, 0};
            vector<int>nums2 = {2, 4, 6};
            merge(nums1, 3, nums2, 3);
            for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++)
            {
                cout << *it << endl;
            } 
        }
    };
};


class Leetcode20  // Inorder traverse
{
public:
    class Solution {
    public:
        /*垃圾递归
        void inorderTraversal(TreeNode* root, vector<int>& nums)
        {
            if (root->left)
            {
                inorderTraversal(root->left, nums);
            }
            nums.push_back(root->val);
            if (root->right)
            {
                inorderTraversal(root->right, nums);
            }
        }
        */


        // 直接遍历
        vector<int> inorderTraversal(TreeNode* root) 
        {
            vector<int> res;
            stack<TreeNode*> st;
            auto p = root;    // 自动匹配类型
            while (p || !st.empty())  
            {
                while (p) 
                {
                    st.push(p);
                    p = p->left;
                }
                auto node = st.top();
                st.pop();
                res.emplace_back(node->val);  // 功能和push_back丢�样但是更高效
                p = node->right;
            }   
            return res;
        }


        Solution()
        {
            TreeNode t0(0);
            TreeNode t1(1);
            TreeNode t2(2);
            TreeNode t3(3);
            TreeNode t4(4);
            TreeNode t5(5);
            TreeNode t6(6);
            TreeNode t7(7);
            t0.left = &t1;
            t0.right = &t2;
            t1.left = &t3;
            t1.right = &t4;
            t2.left = &t5;
            t2.right = &t6;
            t4.left = &t7;
            vector<int> order;
            //  inorderTraversal(&t0, order);  //  递归方式调用
            order = inorderTraversal(&t0);
            for (vector<int>::iterator it = order.begin(); it != order.end(); it++)
            {
                cout << *it << endl;
            }
        }
    };
};


class Leetcode21  // Same tree
{
public:
    class Solution 
    {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) 
        {
            if (!p && !q) {return true;}
            if (!p || !q) {return false;}
            if (p->val != q->val) {return false;}
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }


        Solution()
        {
            TreeNode* t0 = nullptr;
            TreeNode* t1 = nullptr;
            cout << isSameTree(t0, t1) << endl;
        }
    };
};


class Leetcode22  // Symmetric tree
{
public:
    class Solution 
    {
    public:
        bool isSymmetric(TreeNode* root) 
        {
            if(!root) {return true;}
            if (root->left && root->right)
            {
                bool out = judge(root->left, root->right);
                return out;
            }
            else if (!root->left && !root->right) return true;
            else {return false;}
        }


        bool judge(TreeNode* p, TreeNode* q)
        {
            if(!p&&!q) return true;
            if(!p||!q) return false;
            if(p->val==q->val) return judge(p->left,q->right) && judge(p->right,q->left);
            return false;
        }


        Solution()
        {
            TreeNode* t0 = nullptr;
            cout << isSymmetric(t0) << endl;
        }
    };
};


class Leetcode23  // Max depth of a binary tree
{
public:
    class Solution 
    {
    public:

        int maxDepth(TreeNode* root) 
        {
            if (!root) {return 0;}
            int m = 0, n = 0;
            m = maxDepth(root->left);
            n = maxDepth(root->right);
            return m > n ? m + 1 : n + 1;
        }


        Solution()
        {
            TreeNode* t0 = nullptr;
            cout << maxDepth(t0) << endl;
        }
    };
};


class Leetcode24  // Convert Sorted Array to Binary Search Tree
{
public:
    class Solution 
    {
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums) 
        {
            return build(nums, 0, nums.size()-1);
        }


        TreeNode* build(vector<int>& nums, int begin, int end)
        {
            if (begin > end) {return nullptr; }
            int middle = begin + (end - begin) / 2;
            TreeNode* root = new TreeNode(nums[middle]);
            root->left = build(nums, begin, middle - 1);
            root->right = build(nums, middle + 1, end);
            return root;
        }


        Solution()
        {
            vector<int>nums = {-15, -9, -3, -1, 2, 5, 9, 13};
            TreeNode* root = sortedArrayToBST(nums);
        }
    };
};


class Leetcode25  // Balanced Binary Tree
{
public:
    class Solution 
    {
    public:
        bool isBalanced(TreeNode* root) 
        {
            return inorderTraversal(root);
        }


        bool inorderTraversal(TreeNode* root)
        {
            if (root && root->left && root->right)
            {
                int dl = maxDepth(root->left);
                int dr = maxDepth(root->right);
                if (abs(dl - dr) > 1)  return false;
                return inorderTraversal(root->left) && inorderTraversal(root->right);
            }
            if(root && root->left && !root->right)
            {
                int dl = maxDepth(root->left);
                if (dl > 1) return false;
                return true;
            }
            if(root && !root->left && root->right)
            {
                int dr = maxDepth(root->right);
                if (dr > 1) return false;
                return true;
            }
            if(root && !root->left && !root->right) return true;
            else return true;
        }


        int maxDepth(TreeNode* root) 
        {
            if (!root) {return 0;}
            int m = 0, n = 0;
            m = maxDepth(root->left);
            n = maxDepth(root->right);
            return m > n ? m + 1 : n + 1;
        }


        Solution()
        {
            cout << "Too lazy to generate an example." << endl;
        }
    };
};


class Leetcode26  // Minimum Depth of Binary Tree
{
public:
    class Solution 
    {
    public:
        int minDepth(TreeNode* root) 
        {
            if (!root) return 0;
            if (!root->left && root->right) {return minDepth(root->right);}
            if (root->left && !root->right) {return minDepth(root->left);}
            if (!root->left && !root->right) {return 1;}
            else {return min(minDepth(root->left), minDepth(root->right));}
        }


        Solution()
        {
            cout << "Too lazy to generate an example." << endl;
        }
    };
};


class Leetcode27  // Path Sum
{
public:
    class Solution 
    {
    public:
        bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if (!root) return false;
        if (root && !root->left && !root->right && root->val == targetSum) return true;
        if (targetSum == root->val && (root->left || root->right)) return hasPathSum(root->left, 0) || hasPathSum(root->right, 0);
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }


        Solution()
        {
            cout << "Too lazy to generate an example." << endl;
        }
    };
};


class Leetcode28  // Pascal's Triangle
{
public:
    class Solution 
    {
    public:
        vector<vector<int>> generate(int numRows) 
        {
            vector<vector<int>> nums;
            for (int i = 0; i < numRows; i++)
            {
                vector<int>array(i+1, 1);  // Generate 1 with an amount of i.
                nums.emplace_back(array);
                for (int j = 1; j < i; j++)
                {
                    nums[i][j] = nums[i-1][j-1] + nums[i-1][j];
                }
            }
            return nums;
        }


        Solution()
        {
            vector<vector<int>> piscal = generate(4);
        }
    };
};


class Leetcode29  // Best Time to Buy and Sell Stock
{
public:
    class Solution 
    {
    public:
        int maxProfit(vector<int>& prices)  
        {
            int max_money = 0;
            for (int i = 0; i < prices.size() - 1; i++)
            {
                int least = min(prices[i], prices[i+1]);
                int flag = prices[i+1] - least;
                if (flag >= max_money) max_money = flag;
                prices[i+1] = (prices[i]==least? prices[i]: prices[i+1]);
            }
            return max_money;
        }


        Solution()
        {
            vector<int> stock = {3, 4, 2, 1, 5, 7, 3, 9, 4};
            cout << maxProfit(stock) <<endl;
        }
    };
};


class Leetcode30  // Valid Palindrome
{
public:
    class Solution 
    {
    public:
        bool isPalindrome(string s) 
        {
            string ss;
            for (int i = 0; i < s.size(); i++)
            {
                if (isalnum(s[i])) ss += tolower(s[i]);
            }
            for (int i = 0; i < (ss.size() / 2); i++)
            {
                if (ss[i] != ss[ss.size()-1-i]) return false;
            }
            return true;
        }


        Solution()
        {
            cout << isPalindrome("woaininiaow") << endl;
        }
    };
};


class Leetcode31  // Single Number
{
public:
    class Solution 
    {
    public:
        int singleNumber(vector<int>& nums) 
        {
            int len = nums.size();
            int result=0;
            for(int i=0;i<len;i++) { result ^=nums[i];} 
            return result;
        }


        Solution()
        {
            vector<int> num = {1, 2, 3, 4, 5, 3, 4, 1, 2};
            cout << singleNumber(num) << endl;
        }
    };
};


class Leetcode32  // Linked List Cycle
{
public:
    class Solution 
    {
    public:
        /* Trash algorithm
        bool hasCycle(ListNode *head) 
        {
            if (!head) return false;
            vector<ListNode*> ox;
            while (head)
            {
                ox.emplace_back(head);
                head = head->next;
                for (int i = 0; i < ox.size(); i++)
                {
                    if (head == ox[i]) return true;
                }
            }
            return false;
        }
        */

       // fast & slow pointer
       bool hasCycle(ListNode *head) 
       {
            if(!head)return false;
            ListNode* fast=head->next;
            ListNode* slow=head;
            while(fast != slow)
            {
                if(!fast||!fast->next) return false;
                fast=fast->next->next;
                slow=slow->next;
            } 
            return true; 
        }


        Solution()
        {
            cout << "To lazy to give an example." << endl;
        }
    };
};


class Leetcode33  // Pre-order traverse
{
public:
    class Solution 
    {
    public:
        /* trash recursion
        vector<int> preorderTraversal(TreeNode* root) 
        {
            vector<int> nums;
            traverse(root, nums);
            return nums;
        }


        void traverse(TreeNode* root, vector<int>& nums)
        {
            if (root) 
            {
                nums.emplace_back(root->val);
                traverse(root->left, nums);
                traverse(root->right, nums);
            }
        }
        */


       vector<int> preorderTraversal(TreeNode* root)
       {
           vector<int> nums;
           stack<TreeNode*> rec;
           rec.emplace(root);
           while(!rec.empty())
           {
               TreeNode* node = rec.top();
               rec.pop();
               if (!node) continue;
               nums.emplace_back(node->val);
               rec.emplace(node->right);
               rec.emplace(node->left);
           }    
           return nums;
       }


       Solution()
       {
           cout  << "Too lazy to generate a tree." << endl;
       }
    };
};


class Leetcode34  // Post-order traverse
{
    class Solution 
    {
    public:
        vector<int> postorderTraversal(TreeNode *root) 
        {
            vector<int> res;
            if (root == nullptr) {
                return res;
            }

            stack<TreeNode *> stk;
            TreeNode *prev = nullptr;
            while (root != nullptr || !stk.empty()) {
                while (root != nullptr) {
                    stk.emplace(root);
                    root = root->left;
                }
                root = stk.top();
                stk.pop();
                if (root->right == nullptr || root->right == prev) {
                    res.emplace_back(root->val);
                    prev = root;
                    root = nullptr;
                } else {
                    stk.emplace(root);
                    root = root->right;
                }
            }
            return res;
        }


        Solution()
        {
            cout  << "Too lazy to generate a tree." << endl;
        }
    };
};


class Leetcode35  // Minimam stack
{
public:
    class Solution
    {
    public:
        class MinStack 
        {
        public:
            vector<int> sta;
        public:            
            void push(int val) 
            {
                sta.emplace_back(val);
            }
            

            void pop() 
            {
                sta.pop_back();
            }
            

            int top() 
            {
                return sta[sta.size()-1];
            }
            

            int getMin() 
            {
                if(sta.size()==1) return sta[0];
                int min = INT_MAX;
                for (vector<int>::iterator it = sta.begin(); it != sta.end(); it++)
                {
                    min = (*it <= min ? *it : min); 
                }
                return min;
            }
        };


        Solution()
        {
            MinStack mst;
            mst.push(1); 
            mst.push(2); 
            mst.push(4); 
            mst.push(-3); 
            mst.push(5); 
            mst.push(6); 
            cout << mst.getMin() << endl;
        }
    };
};


class Leetcode36  // Intersection of Two Linked Lists
{
public:
    // Method1->time: O(n * n); space: O(n)
    class Solution 
    {
    public:
        ListNode *getIntersectionNodeEasy(ListNode *headA, ListNode *headB) 
        {
            vector<ListNode*> nodes;
            ListNode* p1 = headA, * p2 = headB;
            while(p1 || p2)
            {
                if (p1 == p2) return p1;
                for (vector<ListNode*>::iterator it = nodes.begin(); it != nodes.end(); it++)
                {
                    if (*it == p1) return p1;
                    if (*it == p2) return p2;
                }
                if (p1) 
                {
                    nodes.emplace_back(p1); 
                    p1 = p1->next;
                }
                if (p2) 
                {
                    nodes.emplace_back(p2); 
                    p2 = p2->next;
                }
            }
            return nullptr;
        }


        //Method2->time: O(n); space: O(1)
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
        {
            if (headA == nullptr || headB == nullptr) {return nullptr;}
            ListNode *pA = headA, *pB = headB;
            while (pA != pB) 
            {
                pA = pA == nullptr ? headB : pA->next;
                pB = pB == nullptr ? headA : pB->next;
            }
            return pA;
        }

        Solution()
        {
            ListNode l1 = ListNode(1);
            ListNode l2 = ListNode(3);
            ListNode l3 = ListNode(5);
            ListNode l4 = ListNode(7);
            ListNode l5 = ListNode(9);
            ListNode l6 = ListNode(30);
            ListNode l7 = ListNode(31);
            ListNode l8 = ListNode(32);
            l1.next = &l2;
            l2.next = &l3;
            l3.next = &l4;
            l4.next = &l5;
            l5.next = &l6;
            l6.next = &l7;
            l7.next = &l8;
            ListNode* lst = getIntersectionNodeEasy(&l1, &l6);
            string ss = (lst == nullptr? "nullptr": to_string(lst->val));
            cout << ss << endl;
        }
    };
};


class Leetcode37  // Two sum II
{
public:
    class Solution 
    {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) 
        {
            int l = 0, r = numbers.size() - 1;
            vector<int> rec;
            while (l < r)
            {
                if (numbers[l] + numbers[r] == target) 
                {
                    rec.emplace_back(l+1);
                    rec.emplace_back(r+1);
                    return rec;
                }
                else if (numbers[l] + numbers[r] < target)  l++; 
                else r--;
            }
            return rec;
        }


        Solution()
        {
            vector<int>nums  = {1, 2, 3, 4, 5, 6};
            vector<int>output = twoSum(nums, 11);
            cout << nums[0] << " " << nums[1] << endl;
        }
    };
};


class Leetcode38  // Excel Sheet Column Title
{
public:
    class Solution 
    {
    public:
        string convertToTitle(int columnNumber) 
        {
            vector<char> table;
            string ss;
            for (int i = 0; i < 27; i++)
            {
                table.emplace_back((i + 64));
            }
            table[0] = 'Z';
            while (columnNumber)
            {
                int quotient = columnNumber / 26;
                int remainder = columnNumber % 26;
                if (columnNumber  % 26 == 0) 
                {
                    quotient--;
                }
                ss += table[remainder];
                if (!quotient) break;
                columnNumber = quotient;
            }
            reverse(ss.begin(), ss.end());  // Pay attention to reversing a string.
            return ss;
        }

    
        Solution()
        {
            string ss = convertToTitle(701);
            cout << ss << endl;
        }
    };
};


class Leetcode39  // Majority Element
{
public:
    class Solution 
    {
    public:
        /*  My method: count numbers. But uses sort().
        int majorityElement(vector<int>& nums) 
        {
            sort(nums.begin(), nums.end());
            int turn = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                int flag = nums[i];
                if( (i != 0) && (flag != nums[i-1])) turn = 1;
                else turn++;
                if (turn > (nums.size() / 2)) return nums[i];
            }
            return 0;
        }
        */


        /*  Simplest way with sort: if a snake hides in a tube which is not longer than twice of the snake, 
        /*  you can cut the snake by cutting the middle of the tube
        int majorityElement(vector<int>& nums) 
        {
            sort(nums.begin(), nums.end());
            return nums[nums.size() / 2];
        }
        */


        // Good method: moore vote
        int majorityElement(vector<int>& nums) 
        {
            int count=1;
            int temp=nums[0];
            int n=nums.size();
            for(int i=1;i<n;i++)
            {
                if(nums[i]==temp) count++;
                else count--;
                if(count==0)
                {
                    temp=nums[i+1];
                    i++;
                    count=1;
                }

            }
            return temp;
        }
        

        Solution()
        {
            vector<int>nums = {1, 1, 2 ,2, 2};
            cout << majorityElement(nums) << endl;
        }
    };
};


class Leetcode40  // Excel Sheet Column Number
{
public:
    class Solution 
    {
    public:
        int titleToNumber(string columnTitle) 
        {
            int num = 0;
            long power = 1;
            for (int i = columnTitle.size() - 1; i >= 0; i--)
            {
                num += (int(columnTitle[i]) - 64) * power;
                power *= 26;
            }
            return num;
        }


        Solution()
        {
            cout << titleToNumber("AB") <<endl;
        }
    };
};


class Leetcode41  // reverseBits
{
public:
    class Solution
    {
    public:
        uint32_t reverseBits(uint32_t n) 
        {
            uint32_t ans=0;
            int i=32;
            while(i--)
            {
                ans<<=1;
                ans+=n&1;
                n>>=1;
            }
            return ans;
        }


        Solution()
        {
            uint32_t num = 43261596;
            cout <<  bitset<32>(reverseBits(num)) << endl;
        }
    };
};


class Leetcode42  // Happy number
{
public:
    class Solution 
    {
    public:
        bool isHappy(int n) 
        {
            int m = 0;
            int sum = 0;
            int length = to_string(n).size(); 
            while (sum != 1)
            {
                while (n)
                {
                    int flag = pow(10, (length--) - 1);
                    m = n / flag;
                    n -= flag * m;
                    sum += pow(m, 2);
                }
                if (sum == 4) return false;
                if (sum == 1) return true;
                n = sum;
                sum = 0;
                length = to_string(n).size(); 
            }
            return true;
        }


        Solution()
        {
            cout << isHappy(19) << endl;
        }
    };
};


class Leetcode43  // Remove Linked List Elements
{
public:
    class Solution 
    {
    public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        struct ListNode* dummyHead = new ListNode(0, head);
        // 这里是直接创建了丢�个初始化了的ListNode的指针，与下面先生成结点ListNode l1(7)，再设置内容的方法不同��加不加struct好像没有区别〄1�7
        struct ListNode* temp = dummyHead;
        while (temp->next != NULL) {
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return dummyHead->next;
    }


        Solution()
        {
            ListNode l1(7);
            ListNode l2(7);
            ListNode l3(7);
            ListNode l4(7);
            l1.next = &l2;
            l2.next = &l3;
            l3.next = &l4;
            ListNode* lst = removeElements(&l1, 7);
            while (lst)
            {
                cout << lst->val << endl;
                lst = lst->next;
            }
        }
    };
};


class Leetcode44  // Isomorphic Strings
{
public:
    class Solution 
    {
    public:
        bool isIsomorphic(string s, string t) // my method
        {
            map<char, char> dict;
            for (int i = 0; i < s.size(); i++)
            {
                if (!dict.count(s[i])) 
                {
                    for(map<char,char>::iterator it = dict.begin(); it != dict.end(); it++) 
                    {
                        if( it->second == t[i]) return false;
                    } 
                    dict.insert(make_pair(s[i], t[i]));
                }
                else 
                {
                    if ((*(dict.find(s[i]))).second == t[i]) continue;
                    else return false;
                }
            }
            return true;
        }


        bool isIsomorphicOther(string s, string t)  // other method
        {
            for(int i = 0; i < s.size(); ++i)
            {
                if(s.find(s[i]) != t.find(t[i])) return false;
            }
            return true;
        }


        Solution()
        {
            cout << isIsomorphic("badc", "baba") << endl;
        }
    };
};


class Leetcode45  // Reverse Linked List
{
public:
    class Solution 
    {
    public:
        ListNode* reverseListIteration(ListNode* head)   // iteration, a little bit slow
        {
            if (!head) return nullptr;
            ListNode* root = new ListNode(head->val);
            while (head->next)
            {
                ListNode* newNode = new ListNode(head->next->val, root);
                root = newNode;
                head = head->next;
            }
            return root;
            delete(root);
        }


        ListNode* reverseList(ListNode* head) 
        {
            if (!head || !head->next) {
                return head;
            }
            ListNode* newHead = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            return newHead;
        }


        Solution()
        {
            ListNode* head = new ListNode(5);
            head = reverseList(head);
            cout << head->val << endl;
            delete head;
        }
    };
};


class Leetcode46  // Contains Duplicate I
{
public:
    class Solution 
    {
    public:
        /* simple way
        bool containsDuplicate(vector<int>& nums) 
        {
            return set<int>(nums.begin(), nums.end()).size() != nums.size();

        }
        */


        bool containsDuplicate(vector<int>& nums) 
        {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i]== nums[i+1]) return true;
            }
            return false;
        }


        Solution()
        {
            vector<int>number = {1, 2, 3, 4, 5, 6};
            cout << containsDuplicate(number) << endl;
        }
    };
};


class Leetcode47  // Contains Duplicate II
{
public:
    class Solution 
    {
    public:
        bool containsNearbyDuplicateBrutal(vector<int>& nums, int k)   // Runtime overflow
        {
            if (nums.size() == 0 || nums.size() == 1) return false;
            for (int i = 0; i < nums.size() - 1; i++)
            {
                for (int j = i + 1; j <= i + k; j++)
                {
                        if ( j < nums.size() && nums[i] == nums[j] ) return true;
                }
            }
            return false;
        } 


        bool containsNearbyDuplicate(vector<int>& nums, int k) 
        {
            unordered_set<int> existed;
            int n = nums.size();
            int curr = 0;
            for (int i = 0; i < n; ++i)
            {
                curr = nums[i];
                if (existed.find(curr) == existed.end())
                {
                    existed.insert(curr);
                    if (existed.size() > k)  existed.erase(nums[i-k]);
                }
                else return true;
            }
            return false;
        }


        Solution()
        {
            vector<int>nums = {12, 23, 1, 2, 3};
            cout << containsNearbyDuplicate(nums, 5) << endl;
        }
    };
};


class Leetcode48  // Implement Stack using Queues
{
public:
    class MyStack 
    {
    public:
        queue<int> q1;
        queue<int> q2;


    public:
        void push(int x) 
        {
            q1.push(x);
        }
        

        int pop() 
        {
            int flag = 0;
            int num = q1.size() - 1;
            while (flag != num - 1)
            {
                q2.push(q1.front());
                q1.pop();
                flag++;
            }
            int rec = q1.front();
            q1.pop();
            q1 = q2;
            q2 = {};
            return rec;
        }
        

        int top() 
        {
            return q1.back();
        }
        

        bool empty() 
        {
            if (q1.size() == 0) return true;
            return false;
        }
    };


    class Solution
    {
    public:
        Solution()
        {
            MyStack mst;
            mst.push(1);
            mst.push(2);
            int l1 = mst.top();
            int l2 = mst.pop();
            int l4 = mst.empty();
            cout << l1 << endl;
            cout << l2 << endl;
            cout << l4 << endl;
        }
    };
};


class Leetcode49  // Invert a binary tree
{
public: 
    class Solution 
    {
    public:
        TreeNode* invertTree(TreeNode* root) 
        {
            if (root == nullptr) return nullptr;
            TreeNode* left = invertTree(root->left);
            TreeNode* right = invertTree(root->right);
            root->left = right;
            root->right = left;
            return root;
        }


        Solution()
        {
            cout << "Too lazy to generate a binary tree." << endl;
        }
    };
};


class Leetcode50  // Summary Ranges
{
public:
    class Solution 
    {
    public:
        vector<string> summaryRangesMyMethod(vector<int>& nums)  // My method: works on vscode but can't work on leetcode(time over flow)
        {
            if (nums.empty()) return {};
            if (nums.size() == 1) return {to_string(nums[0])};
            int flag = 0;
            vector<int>rec;
            vector<string>output;
            for (int i = 0; i < nums.size(); i++)
            {
                int flag = nums[i];
                rec.emplace_back(nums[i]);
                // while ( (nums[i++]) == (nums[i]++) );
                while (nums[i + 1] && nums[i + 1] == nums[i] + 1) 
                {
                    i++;
                }
                if (nums[i] == flag) output.emplace_back(to_string(flag));
                else
                {
                    if (i != nums.size() - 1)
                    {
                        rec.emplace_back(nums[i]);
                        output.emplace_back(to_string(rec[rec.size() - 2]) + "->" + to_string(rec[rec.size() - 1]));
                        rec.emplace_back(nums[i + 1]);
                    }
                    else 
                    {
                        rec.emplace_back(nums[i]);
                        output.emplace_back(to_string(rec[rec.size() - 2]) + "->" + to_string(rec[rec.size() - 1]));
                    }
                }
            }
            return output;
        }


        vector<string> summaryRanges(vector<int>& nums)   // official answer
        {
            vector<string> ret;
            int i = 0;
            int n = nums.size();
            while (i < n) 
            {
                int low = i;
                i++;
                while (i < n && nums[i] == nums[i - 1] + 1) 
                {
                    i++;
                }
                int high = i - 1;
                string temp = to_string(nums[low]);
                if (low < high) 
                {
                    temp.append("->");
                    temp.append(to_string(nums[high]));
                }
                ret.push_back(move(temp));
            }
            return ret;
        }


        Solution()
        {
            vector<int> nums = {0, 1};
            vector<string> out = summaryRanges(nums);
            for (int i = 0; i < out.size(); i++)
            {
                cout << out[i] << endl;
            }
        }
    };
};


class Leetcode51  // Power of two
{
public:
    class Solution 
    {
    public:
        bool isPowerOfTwoRecursion(int n)  // recursion
        {
            if (n == 0) return false;
            if (n == 1) return true;
            if (n % 2 == 1) return false;
            else return isPowerOfTwoRecursion(n / 2);
        }


        bool isPowerOfTwo(int n)  // solve it without loops/recursion
        {
            if (n < 1) return false;
            return (n & n-1) == 0;  // 8(1000) & 7(0111) == 0(0000)
        }


        Solution()
        {
            cout << isPowerOfTwo(3738) << endl;
        }
    };
};


class Leetcode52  // Implement Queue using Stacks
{
public:
    class MyQueue
    {
    private:
        stack<int> a;
        stack<int> b;


    public:
        void push(int x) {a.push(x);}
        

        int pop()
        {
            int num = 0;
            if (b.empty())
            {
                while(!a.empty())
                {
                    b.push(a.top());
                    a.pop();
                }
            }
            if (!b.empty())
            {
                num = b.top();
                b.pop();
            }

            return num;
        }
        

        int peek()
        {
            int num = 0;
            if (b.empty())
            {
                while(!a.empty())
                {
                    b.push(a.top());
                    a.pop();
                }
            }
            if (!b.empty())
                num = b.top();
            
            return num;
        }
        

        bool empty()
        {
            if (a.empty() && b.empty())
                return true;
            return false;
        }
    };


    class Solution
    {
        Solution()
        {
            cout << "No example here." << endl;
        }
    };
};


class Leetcode53  // Palindrome Linked List
{
public:
    class Solution 
    {
    public:
        bool isPalindromeMethodSector(ListNode* head)  // not the best answer. Time complex = Space complex = O(n)
        {
            vector<int> rec;
            ListNode* p = head;
            while (p)
            {
                rec.emplace_back(p->val);
                p = p->next;
            }
            for (int i = 0; i <= rec.size() / 2; i++)
            {
                if (rec[i] != rec[rec.size() - 1 - i]) return false;
            }
            return true;
        }


        bool isPalindrome(ListNode* head)  // official answer
        {
            if (head == nullptr || head->next == nullptr) return true;
            ListNode* slow = head; // 慢指针，找到链表中间分位置，作为分割
            ListNode* fast = head;
            ListNode* pre = head; // 记录慢指针的前一个节点，用来分割链表
            while (fast && fast->next) 
            {
                pre = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            pre->next = nullptr; // 分割链表

            ListNode* cur1 = head;  // 前半部分
            ListNode* cur2 = reverseList(slow); // 反转后半部分，��链表长度如果是奇数，cur2比cur1多一个节炄1�7

            // 弢�始两个链表的比较
            while (cur1) 
            {
                if (cur1->val != cur2->val) return false;
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return true;
        }
    // 反转链表
        ListNode* reverseList(ListNode* head) 
        {
            ListNode* temp; // 保存cur的下丢�个节炄1�7
            ListNode* cur = head;
            ListNode* pre = nullptr;
            while(cur) 
            {
                temp = cur->next;  // 保存丢�丄1�7 cur的下丢�个节点，因为接下来要改变cur->next
                cur->next = pre; // 翻转操作
                // 更新pre 咄1�7 cur指针
                pre = cur;
                cur = temp;
            }
            return pre;
        }


        Solution()
        {
            ListNode l1(1);
            ListNode l2(2);
            ListNode l3(3);
            l1.next = &l2;
            l2.next = &l3;
            cout << isPalindrome(&l1) << endl;
        }
    };
};


class Leetcode54  // Lowest Common Ancestor of a Binary Search Tree
{
public:
    class Solution 
    {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
        {
            if (root == p || root == q) return root;
            if (root->val > p->val && root->val < q->val) return root;
            else if (root->val > p->val && root->val > q->val)
            {
                return lowestCommonAncestor(root->left, p, q);
            }
            else if (root->val < p->val && root->val < q->val)
            {
                return lowestCommonAncestor(root->right, p, q);
            }
            return root;
        }


        Solution()
        {
        cout << "To lazy to generate a tree."  << endl;
        }
    };
};


class Leetcode55  // Delete Node in a Linked List (not a good problem...)
{
public:
    class Solution 
    {
    public:
        void deleteNode(ListNode* node) 
        {
            node->val = node->next->val;
            node->next = node->next->next;
        }


        Solution()
        {
            cout << "This is not a good question..." << endl;
        }
    };
};


class Leetcode56  // Valid Anagram
{
public:
    class Solution
    {
        bool isAnagram(string s, string t)  // method1
        {
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            return s == t? true : false;
        }


        bool isAnagramWithMap(string s, string t)  // method2
        {
            if (s.size() != t.size()) return false;
            unordered_map<char, int> dict;
            for (int i = 0; i < s.size(); i++)
            {
                ++dict[s[i]];
                --dict[t[i]];
            }
            for(unordered_map<char,int>::iterator it = dict.begin();it != dict.end(); it++)
            {
                if(it->second != 0) return false;
            }
            return true;
        }


        Solution()
        {
            cout << isAnagram("asdsa", "dsasa") << endl;
        }
    };
};


class Leetcode57  // Binary Tree Paths (hard for me...)
{
public:
    class Solution 
    {
    public:
        vector<string> binaryTreePaths(TreeNode* root)  // recursion
        {
            vector<string> output;
            goThrough(root, output, "");
            return output;
        }


        void goThrough(TreeNode* root, vector<string>& output, string path)
        {
            if (root != nullptr) path += to_string(root->val);
            if (!root->left && !root->right) output.emplace_back(path);
            if (root->left) goThrough(root->left, output, path + "->");
            if (root->right) goThrough(root->right, output, path + "->");
        }


        Solution()
        {
            cout << "Too lazy to generate a binary tree." << endl;
        }


        /* iteration. Official answer.
        class Solution {
        public:
            vector<string> binaryTreePaths(TreeNode* root) {
                vector<string> paths;
                if (root == nullptr) {
                    return paths;
                }
                queue<TreeNode*> node_queue;
                queue<string> path_queue;

                node_queue.push(root);
                path_queue.push(to_string(root->val));

                while (!node_queue.empty()) {
                    TreeNode* node = node_queue.front(); 
                    string path = path_queue.front();
                    node_queue.pop();
                    path_queue.pop();

                    if (node->left == nullptr && node->right == nullptr) {
                        paths.push_back(path);
                    } else {
                        if (node->left != nullptr) {
                            node_queue.push(node->left);
                            path_queue.push(path + "->" + to_string(node->left->val));
                        }

                        if (node->right != nullptr) {
                            node_queue.push(node->right);
                            path_queue.push(path + "->" + to_string(node->right->val));
                        }
                    }
                }
                return paths;
            }
        };
        */
    };
};


class Leetcode58  // Add Digits
{
public:
    class Solution 
    {
    public:
        int addDigits(int num)  // recursion
        {
            if (num < 10) return num;
            return addDigits(((num / 10) + (num % 10)));
        }


        int addDigitsMath(int num)  // math
        {
            if (num == 0) return 0;
            return num % 9 == 0 ? 9 : num % 9;
        }


        Solution()
        {
            cout << addDigits(1565312) << endl;
            cout << addDigitsMath(1565312) << endl;
        }
    };
};


class Leetcode59  // Ugly Number
{
public:
    class Solution 
    {
    public:
        bool isUgly(int n) 
        {
            if (n == 0) return false;
            if (n == 1 || n == 2 || n == 3 || n == 5) return true;
            else 
            {
                if (n % 2 == 0) return isUgly(n / 2);
                if (n % 3 == 0) return isUgly(n / 3);
                if (n % 5 == 0) return isUgly(n / 5);
                return false;
            }
        }


        Solution()
        {
            cout << isUgly(113114) << endl;
        }
    };
};


class Leetcode60  // Missing Number
{
public:
    class Solution
    {
    public:
        int missingNumber(vector<int>& nums)  // My method 1
        {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] != i) return i;
            }
            return nums.size();
        }


        int missingNumber2(vector<int>& nums) // My method 2
        {
            int res = nums.size();
            for (int i = 0; i < nums.size(); ++i){
                res ^= nums[i];
                res ^= i;
            }
            return res;
        }


        // good method
        int missingNumber3(vector<int>& nums) 
        {
            int res = nums.size();
            for (int i = 0; i < nums.size(); ++i)
            {
                res ^= nums[i];
                res ^= i;
            }
            return res;
        }
        

        Solution()
        {
            vector<int>nums = {1 , 2, 3, 0};
            cout << missingNumber(nums) << endl;
        }
    };
};


class Leetcode61  // Move Zeros
{
public:
    class Solution 
    {
    public:
        void moveZeroes(vector<int>& nums) 
        {
            int n = nums.size(), left = 0, right = 0;
            while (right < n) 
            {
                if (nums[right]) 
                {
                    swap(nums[left], nums[right]);
                    left++;
                }
                right++;
            }
        }


        Solution()
        {
            vector<int>nums = {0, 1, 0};
            moveZeroes(nums);
            for (int i = 0; i < nums.size(); i++)
            {
                cout << nums[i] << endl;
            }
        }
    };
};


class Leetcode62  // Nim Game
{
public:
    class Solution 
    {
    public:
        bool canWinNim(int n) 
        {
            return n % 4 == 0 ? false : true;
        }


        Solution()
        {
            cout << canWinNim(152) << endl;
        }
    };
};


class Leetcode64  // Power Of Three
{
public:
    class Solution 
    {
    public:
        bool isPowerOfThree(int n) 
        {
            return n > 0 && 1162261467 % n == 0;
        }


        Solution()
        {
            cout << isPowerOfThree(1314) << endl;
        }
    };
};


class Leetcode65  // Count 1
{
public:
    class Solution 
    {
    public:
        vector<int> countBits(int n) 
        {
            vector<int> res(n + 1);
            for (int i = 1; i <= n; i++)
            {
                res[i] = res[i & (i - 1)] + 1;  // i & (i - 1)总会让i少一个1（最右边的一位），返回去的参照位置不同
            }
            return res;
        }


        Solution()
        {
            vector<int>nums = countBits(5);
            for (int i = 0; i < nums.size(); i++)
            {
                cout << nums[i] << endl;
            }
        }
    };
};


class Leetcode66  // Power Of 4
{
public:
    class Solution 
    {
    public:
        bool isPowerOfFour(int n) 
        {
            if (n == 0) return false;
            while (n % 4 == 0)
            {
                n >>= 2;
            }
            return n == 1 ? true : false;
        }


        Solution()
        {
            cout << isPowerOfFour(438) << endl;
        }
    };
};


class Leetcode67  // Reverse a string
{
public:
    class Solution 
    {
    public:
        void reverseString(vector<char>& s) 
        {
            for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
            {
                swap(s[i], s[j]);
            }
        }


        Solution()
        {
            vector<char> s = {'a', 's', 'k'};
            reverseString(s);
            cout << s[0] << s[1] << s[2] << endl;
        }
    };
};


class Leetcode68  // Reverse Vowels of a String
{
public:
    class Solution 
    {
    public:
        string reverseVowels(string s) 
        {
            int left = 0, right = s.size() - 1;
            vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
            while (left < right)
            {
                vector<char>::iterator it_left = find(vowels.begin(), vowels.end(), s[left]);
                vector<char>::iterator it_right = find(vowels.begin(), vowels.end(), s[right]);
                if (it_left != vowels.end() && it_right != vowels.end()) {swap(s[left], s[right]); right--; left++;}
                else if (it_left == vowels.end() && it_right != vowels.end()) left++;
                else if (it_left != vowels.end() && it_right == vowels.end()) right--;
                else {right--; left++;}
            }
            return s;
        }


        Solution()
        {
            string ss = reverseVowels("hello");
            cout << ss << endl;
        }
    };
};


class Leetcode69  // Intersection of Two Arrays(I)
{
public:
    class Solution 
    {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
        {
            unordered_set<int> output;
            unordered_set<int> nums(nums1.begin(), nums1.end());  // 把nums1去重
            for (int i : nums2)
            {
                if (nums.find(i) != nums.end()) output.insert(i);  // 插入时把nums2去重
            }
            return vector<int>(output.begin(), output.end());
        }


        Solution()
        {
            vector<int>a {1, 2, 3, 3};
            vector<int>b {2, 3, 3, 4};
            vector<int> num = intersection(a, b);
            for (int i : num)
            {
                cout << i << endl;
            }
        }
    };
};


class Leetcode70  // Intersection of Two Arrays(II)
{
public:
    class Solution 
    {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
        {
            vector<int> rst;
            for (int i : nums1)
            {
                vector<int>::iterator it = find(nums2.begin(), nums2.end(), i);
                if (it != nums2.end())
                {
                    rst.emplace_back(i);
                    nums2.erase(it);
                }
            }
            return rst;
        }


        Solution()
        {
            vector<int>n1 = {1, 2, 3, 6, 5, 2, 3, 2, 3, 2, 21, 2, 3};
            vector<int>n2 = {1, 3, 4, 5, 3, 2, 1};
            vector<int>n3 = intersect(n1, n2);
            for (int i : n3)
            {
                cout << i << endl;
            }
        }
    };
};


class Leetcode71  // Valid Perfect Square
{
public:
    class Solution 
    {
    public:
        bool isPerfectSquare(int num) 
        {
            if (num == 1) return true;
            long sum = 0;
            for (int i = 1; i <= num - 1; i += 2) 
            {
                sum += i;
                if (sum == num) return true;
                if (sum > num) return false;
            }
            return num == sum ? true : false;
        }


        Solution()
        {
            cout << isPerfectSquare(314159) << endl;
        }
    };
};


class Leetcode72  // Ransom Note
{
public:
    class Solution 
    {
    public:
        bool canConstruct(string ransomNote, string magazine) 
        {
            unordered_map<char, int> table;
            for (int i = 0; i < ransomNote.size(); i++)
            {
                if (table.find(ransomNote[i]) == table.end())
                {
                    table.emplace(ransomNote[i], 1);
                }
                else 
                {
                    table.find(ransomNote[i])->second++;
                }
            }
            for (int i = 0; i < magazine.size(); i++)
            {
                if (table.find(magazine[i]) != table.end())
                {
                    ((table.find(magazine[i]))->second)--;
                }
            }
            for (unordered_map<char, int>::iterator it = table.begin(); it != table.end(); it++)
            {
                if (it->second > 0) return false;
            }
            return true;
        }


        /* 简化版
        bool canConstruct(string ransomNote, string magazine) 
        {
            unordered_map<char,int> mag;
            for(char c : magazine)
            {
                mag[c]++;
            }
            for(char c : ransomNote)
            {
                mag[c]--;
                if(mag[c] < 0) return false;
            }
            return true;
        }
        */


        Solution()
        {
            cout << canConstruct("bg", "bgg") << endl;
        }
    };
};


class Leetcode73  // First Unique Character in a String
{
public:
    class Solution 
    {
    public:
        int firstUniqChar(string s) 
        {
            unordered_map<char, int> rst;
            for (char i : s)
            {
                rst[i]++;
            }
            for (int i = 0; i < s.size(); i++)
            {
                if (rst[s[i]] == 1) return i;
            }
            return -1;
        }


        Solution()
        {
            cout << firstUniqChar("leetcode") << endl;
        }
    };
};


class Leetcode74  // Find the Difference
{
public:
    class Solution 
    {
    public:
        char findTheDifference(string s, string t) 
        {
            int sum = 0;
            for (auto i : t)
                sum += i;
            for (auto i : s)
                sum -= i;
            return sum;
        }


        Solution()
        {
            cout << findTheDifference("abbcd", "cbbgad") << endl;
        }
    };
};


class Leetcode75  // Is Subsequence
{
public:
    class Solution 
    {
    public:
        bool isSubsequence(string s, string t) 
        {
            int flag = 0;
            for (int i = 0; i < t.size(); i++)
            {
                if (t[i] == s[flag])
                {
                    flag++;
                }
            }
            return flag == s.size() ? true : false;
        }


        Solution()
        {
            cout << isSubsequence("asd","asaooodpjkofenod") << endl;
        }
    };
};


class Leetcode76  // Binary Watch
{
public:
    class Solution {
    public:
        vector<string> readBinaryWatch(int turnedOn) 
        {
            vector<string> rst;
            for (int i = 0; i <= 11; i++)
            {
                for (int j = 0; j <= 59; j++)
                {
                    if (__builtin_popcount(i) + __builtin_popcount(j) == turnedOn)
                    {
                        rst.emplace_back(to_string(i) + ":" + + (j < 10 ? "0" : "") + to_string(j));
                    }
                }
            }
            return rst;
        }


        Solution()
        {
            vector<string> out = readBinaryWatch(2);
            for(string i: out)
            {
                cout << i << endl;
            }
        }
    };
};


class Leetcode77  // Sum of Left Leaves
{
public:
    class Solution 
    {
    public:
        int sumOfLeftLeaves(TreeNode* root) 
        {
            if (!root) return 0;
            int res = 0;
            if (root->left && !root->left->left && !root->left->right) res += root->left->val;
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + res;
        }


        Solution()
        {
            cout << "Too lazy to generate a tree." << endl;
        }
    };
};


int main()
{
    //查看题目结果格式：Leetcodex::Solution sx;
    Leetcode76::Solution s14;
    system("pause");
    return 0;
}