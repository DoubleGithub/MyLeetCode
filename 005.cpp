/**
	@Author	:	DoubleHH
	@Date	:	2019年4月18日14:06:40
	@Version:	1.0	
 */
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>
#include <assert.h>

using namespace std;

//使用动态规划的方法，算是用空间交换时间吧
//  dp[i,j] = 1 表示s[i..j]是回文串
//  |dp[i,j] = dp[i+1,j-1] , if s[i] = s[j]
//  |dp[i,j] = 0 ,           if s[i] != s[j]
//时间复杂度为O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        if(length == 0)
            return "";
        else if(length == 1) 
            return s;
        else if (length == 2) {
            if(s[0] == s[1])
                return s;
        }
        int longest = 1;
        unsigned short dp[length][length] = {0};     //最长为1000
        //std::vector<std::vector<short>> dp(length,std::vector<short> (length));   //耗时又耗内存
        int start = 0;
        //初始化dp
        for(int i=0;i<length;i++) {
            dp[i][i] = 1;
            if(i < length-1) {
                if(s[i] == s[i+1]) {
                    start = i;
                    longest = 2;
                    dp[i][i+1] = 1;
                }
            }
        }
        for(int len = 3; len<=length; len++) {      //回文串的长度
            for(int i = 0; i+len-1<length; i++) {   //起始位置
                int j = len+i-1;                    //end位置
                if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                    dp[i][j] = 1;
                    longest = len;
                    start = i;
                }
            }
        }
        return s.substr(start,longest);
    }
};

//暴力法会超时，虽然进行了优化了。 时间复杂度为O(n^3)
class Solution_1 {
public:
    string longestPalindrome(string s) {
        // s是两个字符以上的字符串
        string temp;
        string longestPalindrome = "";
        int length = s.size();
        int start,end;
        int temp_start;
        int temp_end;
        for(int i=0;i<length;i++) {			
        	start = i ;							//当前元素位置
        	end = s.find_last_of(s[i],(length - 1));	//当前元素出现的最后位置
        	if(end == -1)                      //没有找到
        		continue;
            else if (end == start)
                if(longestPalindrome.size() <= 1)
                    longestPalindrome = s[start];   //如果当前字符在s中只出现过一次
            temp_start = start;                 //遍历的起始位置
            temp_end = end;                     //遍历的终止位置
            while( (temp_end != -1) ) {         //遍历所有位置
                while( temp_start < temp_end  ) {   //验证某子串是否是回文串
                    if( s[temp_start] == s[temp_end] ) {
                        temp_start ++ ;
                        temp_end --;
                    }
                    else 
                        break;
                }
                if ( (temp_start == temp_end) || (temp_start == (temp_end+1) )  ) {     //如果是回文串
                    temp = s.substr(start,end-start+1);
                    longestPalindrome = (temp.size() > longestPalindrome.size()) ? temp : longestPalindrome;
                }
                temp_start = start;             //重新设置起始、终止位置。
                end = s.find_last_of(s[start],(end-1));
                temp_end = end;    
                if(end == start)                //如果end已经到了start的位置了，跳出
                    break;
            }
        }
        return longestPalindrome;
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
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}