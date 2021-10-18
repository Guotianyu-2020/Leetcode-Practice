#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<stack>
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
            /*  垃圾牄1�7
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
            //模拟全加器，分别计算结果和进位��1�7
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
            //如果算完还有进位，需要补丄1�71
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
        /* 递归方法可以运行但是不够快捷，超出了力扣的时间要汄1�7
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
            if (!head) return nullptr;
            if (!head->next) return head;
            ListNode* p = head->next, * q = head;
            while (p)
            {
                if (p->val == val) 
                {
                    q->next = p->next;
                    p = q->next;
                }
                else
                {
                    p = p->next;
                    q = q->next;
                }
            }
            return head->val == val ? p : head;
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


int main()
{
    //查看题目结果格式：Leetcodex::Solution sx;
    Leetcode43::Solution s14;
    system("pause");
    return 0;
}