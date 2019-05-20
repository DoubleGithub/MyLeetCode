#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long res = 0;

        while(x != 0) {
            res = res * 10 + x%10;
            x = x/10;
        }

        //if(res > pow(2, 31)-1 || res < -pow(2, 31))
        if(res > INT_MAX || res < INT_MIN)
            return 0;
        return (int)res; 
    }
};

class Solution_2 {
public:
    int reverse(int x) {
        int res = 0;

        while(x != 0) {

            if( abs(x) < 10)
                if( (res > INT_MAX/10) || (res < INT_MIN/10) )
                    return 0;
                if (  ( abs(x)>2 && (res==INT_MAX/10 || res==INT_MIN/10) ) )
                    return 0;

            res = res * 10 + x%10;
            x = x/10;
        }

        return res; 
    }
};

class Solution_1 {
public:
    int reverse(int x) {
        long long res = 0;
        string tmp;
        // 判断是否会溢出
        tmp = to_string(x);
        for(auto it=tmp.end()-1; it != tmp.begin(); it-- ) {
            res = res* 10 + ((*it)-48) ;
        }
        if(*tmp.begin() == '-') {
            res = -res;
        }
        else {
            res = res* 10 + ((*tmp.begin())-48) ;
        }
        if(res > INT_MAX || res < INT_MIN)
        // if(res > pow(2, 31)-1 || res < -pow(2, 31))
            return 0;
        return (int)res; 
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}