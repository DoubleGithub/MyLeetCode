
#include <iostream>
#include <string>
#include <assert.h>
#include <algorithm>

using namespace std;

//使用hash函数，优化find速度？

class Solution_12ms {
public:
    int lengthOfLongestSubstring(string s) {
        char hash[128]={0};
        int start = 0,point = 0,lmax = 0;
        while(point<s.size())
        {
           hash[s[point]]>0?--hash[s[start++]]:++hash[s[point++]];
           lmax = max(lmax,point-start);
        }
        return lmax;

    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unsigned int maxlen = 0;
        string temp;
        int index;
        for(unsigned int i=0;i<s.size();i++) {
            if( (index = temp.find_first_of(s[i])) >= 0) {              //找到第一个重复字符s[i]的位置
                maxlen = (maxlen < temp.size()) ? temp.size(): maxlen;
                //maxlen = max(maxlen,(unsigned int)temp.size());       //使用max耗时更长？？
                temp.erase(0, index+1);                                 //从头开始删除到第一个重复字符位置
            }
            temp.push_back(s[i]);
        }
        maxlen = (maxlen < temp.size()) ? temp.size(): maxlen;
        //maxlen = max(maxlen,(unsigned int)temp.size());
        return maxlen;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (unsigned int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}