/*
Day 69 - Add Number Represented by Linked Lists

Problem Name:
Add Two Numbers Represented by Linked Lists

Problem Statement:
Given two numbers represented by two non-empty linked lists `num1` and `num2`,
where each node contains a single digit. The digits are stored in forward order.
Return the sum as a new linked list (also in forward order).

Approach:
- Step 1: Reverse both input lists to simplify addition from least significant digit.
- Step 2: Perform digit-by-digit addition using a carry, like column-wise addition.
- Step 3: Create new nodes for each digit of the result and link them.
- Step 4: Reverse the resulting list to restore the forward order.
- Step 5: Skip any leading zeros in the result before returning the final list.

Time Complexity: O(max(m, n)) where m and n are lengths of the two lists.
Space Complexity: O(max(m, n)) for the result list.


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        Node* curr = head, *prev = NULL, *next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = reverseList(num1);
        num2 = reverseList(num2);

        int carry = 0;
        Node* ans = new Node(0); // Dummy head
        Node* first = ans;

        while (num1 || num2 || carry) {
            int sum = carry;
            if (num1) {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2) {
                sum += num2->data;
                num2 = num2->next;
            }
            ans->data = sum % 10;
            carry = sum / 10;

            if (num1 || num2 || carry) {
                ans->next = new Node(0);
                ans = ans->next;
            }
        }

        reverseList(first);
        while (ans->data == 0 && ans->next) ans = ans->next;  // Skip leading zero
        return ans;
    }
};


