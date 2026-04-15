#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums1 int整型vector 
     * @param nums2 int整型vector 
     * @return int整型vector
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a;
        unordered_set<int> b;
        for (auto x : nums1) {
            a.emplace(x);
        }
        for (auto x : nums2) {
            if (a.count(x)) {
                b.emplace(x);
            }
        }
        vector<int> ret;
        for (auto x : b) {
            ret.emplace_back(x);
        }
        return ret;
    }
};
