#include <iostream>
#include <string>

using namespace std;

// 方法1，利用字符串反转来判断。
// 如果一个数字是回文数，则后半部分反转后等于前半部分。
// 例如 1221 ，反转数字为 12 ，相等
class Solution {
public:
    bool isPalindrome(int x) {
    	// 如果x等于0，或者末尾数字等于0且x不等于0
    	if(x < 0 || (x%10 == 0 && x != 0))
    		return false;
    	int reversalNum = 0;
    	while(x > reversalNum) {
    		reversalNum = reversalNum *10 + x%10;
    		x = x/10;
    	}

    	// 如果位数是奇数的话。比如12321,reversalNum = 123
    	return x == reversalNum || x == reversalNum/10;
    }
};

// 方法2，转换为字符串遍历。
// 缺点：额外的占用了空间。
class Solution_1 {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        	return false;
        else if (x < 10)	// x 为个位数 
        	return true;
        else {
        	string tmp;
        	tmp = to_string(x);
        	// 使用stl方式，还是遍历数组的方式？

        	// auto it_begin=tmp.begin(),it_end=tmp.end()-1;
        	// for(;it_begin < it_end;it_begin++,it_end--) {
        	// 	if(*it_begin != *it_end)
        	// 		return false;
        	// }
        	// if(it_begin >= it_end)
        	// 	return true;
        	// else
        	// 	return false;

        	size_t len = tmp.length();
        	int start = 0, end = len-1;
        	for(;start < end; start++,end--) {
        		if(tmp[start] != tmp[end])
        			return false;
        	}
        	if(start >= end)
        		return true;
        	else 
        		return false;
        }
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}