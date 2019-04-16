#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //合并数据到multiset中
    //是否有更高效的办法？ 还是迭代效率最高？
    multiset<int> ms;
    for(auto it=nums2.begin();it!=nums2.end();it++)
        ms.insert(*it);
    for(auto it=nums1.begin();it!=nums1.end();it++)
        ms.insert(*it);

    double result = 0;          //返回值
    int count = 0;              //当前迭代到哪一个元素了
    int length = ms.size();     //是否有必要?
    bool needNextElem = (length%2 == 0) ? true : false;     //如果元素的数量是偶数，则需要两个中间数求和再求商
    for(auto it=ms.begin();it!=ms.end();it++) {
        if(count == length / 2) {
            if(needNextElem) {
                result = 1.0*(*it + *(--it)) / 2;
            }
            else
                result = 1.0*(*it);
            break;
        }
        count ++ ;
    }
        return result;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}