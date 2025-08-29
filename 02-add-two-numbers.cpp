/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* current1 = l1;
        ListNode* current2 = l2;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        int part1 = 0, part2 = 0, rest = 0;

        while (current1 != nullptr || current2 != nullptr || rest != 0){
            part1 = (current1 != nullptr) ? current1->val : 0;
            part2 = (current2 != nullptr) ? current2->val : 0;

            if (current1 != nullptr) current1 = current1->next;
            if (current2 != nullptr) current2 = current2->next;

            int localSum = part1 + part2 + rest;
            rest = localSum / 10;
            int digit = localSum % 10;
            ListNode* novoNo = new ListNode(digit); 

            if (head == nullptr) {
                head = novoNo;
                tail = novoNo;
            } else {
                tail->next = novoNo;
                tail = novoNo;
            }
        }

        return head;
    }
};

int main() {
    ListNode* l1_node1 = new ListNode(9);

    ListNode* l2_node11 = new ListNode(9);
    ListNode* l2_node10 = new ListNode(9, l2_node11);
    ListNode* l2_node9 = new ListNode(9, l2_node10);
    ListNode* l2_node8 = new ListNode(9, l2_node9);
    ListNode* l2_node7 = new ListNode(9, l2_node8);
    ListNode* l2_node6 = new ListNode(9, l2_node7);
    ListNode* l2_node5 = new ListNode(9, l2_node6);
    ListNode* l2_node4 = new ListNode(9, l2_node5);
    ListNode* l2_node3 = new ListNode(9, l2_node4);
    ListNode* l2_node2 = new ListNode(9, l2_node3);
    ListNode* l2_node1 = new ListNode(1, l2_node2);

    Solution sol;
    sol.addTwoNumbers(l1_node1, l2_node1);

    delete l1_node1;

    delete l2_node11;
    delete l2_node10;
    delete l2_node9;
    delete l2_node8;
    delete l2_node7;
    delete l2_node6;
    delete l2_node5;
    delete l2_node4;
    delete l2_node3;
    delete l2_node2;
    delete l2_node1;

    return 0;
}
