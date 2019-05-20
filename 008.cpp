/*
    思路就是先用long long来存储数字。
    因为是32位的数字。而long long是64位的，溢出也不怕。
*/

#include <iostream>
#include <string>
#include <assert.h>
#include <sstream>

using namespace std;

// 极速模式。。。。
class Solution {
public:
    int myAtoi(string str) {
        while(*str.begin() == ' ') str.erase(str.begin());
        if(str == "") return 0;
        stringstream ss;
        ss<<str;
        int n;
        ss>>n;
        return n;
    }
};

class Solution_1 {
public:
    int myAtoi(string str) {
        long long res = 0;
        char *c = &str[0];
        char firstNotEmptyChar = ' ';
        while(*c != '\0') {
            if(*c == ' ') {     // 跳过空格
                c++;
                continue;
            }
            if(firstNotEmptyChar==' ') {    //找到第一个符合的数字或者符号
                if( isdigit(*c) )
                    firstNotEmptyChar = *c;
                else if( *c == '-' || *c == '+') {
                    if( !isdigit(*(c+1)))
                        return 0;
                    firstNotEmptyChar = *c;
                    continue;
                }
                else
                    return 0;
            }

            if(isdigit(*c)) {   
                res = res * 10 + *c - 48;
                // if(res < INT_MIN || res > INT_MAX)  //判断是否溢出
                if(res > INT_MAX)  //判断是否溢出,此处的res只是正数
                    break;
                if( !isdigit(*(c+1)) )
                    break;
            }
            c++;
        }
        if(firstNotEmptyChar == '-') {
            res = -res;
        }
        if(res < INT_MIN )
            res = INT_MIN;
        else if(res > INT_MAX)
            res = INT_MAX;

        return res!=0?(int)res:0;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
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
        string str = stringToString(line);
        
        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}