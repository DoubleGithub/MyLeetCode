/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/


#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;
 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1 = l1;       //用于遍历l1
        ListNode *head2 = l2;       //用于遍历l2
        ListNode *result = new ListNode(0);     //用于遍历head3
        ListNode *head3 = result;   //返回链表
        ListNode *node = NULL;      //临时节点
        int value;                  //当前值          fg: [1,9,9,9] + [1]
        int remainder = 0;          //当前值的余数 
        int remainder1 = 0;         //当前值加上余数的新余数
        //如果有空链表直接返回
        for(;head1!=NULL && head2!=NULL ;) {
            value = (head1->val + head2->val);
            node = new ListNode((value%10 + remainder + remainder1)%10);   
            result->next = node;
            result = result->next;      //指向当前节点
            remainder1 = (value%10 + remainder + remainder1) / 10; 
            remainder = value / 10;

            if(head1->next == NULL)     //如果已经是最后一个节点了，就不到它的next了
                head1->val = 0;
            else
                head1 = head1->next;

            if(head2->next == NULL)
                head2->val = 0;
            else
                head2 = head2->next;

            //结束条件
            if(((head1->val + head2->val) == 0) && head1->next ==NULL &&    \
                head2->next == NULL && remainder == 0 && remainder1 == 0)
                break;
        }
        return head3->next;
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}