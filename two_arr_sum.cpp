//
// Created by bai on 2020/9/12.
/**
     * 2. 两数相加
    给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

    如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

    您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

    示例：

    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807
 */
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
public:
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 使用prenode而不需要单独考虑头节点，以简化代码
        auto *prenode = new ListNode(0);
        ListNode *lastnode = prenode;
        int val = 0;
        while(val || l1 || l2) {
            val = val + (l1?l1->val:0) + (l2?l2->val:0);
            lastnode->next = new ListNode(val % 10);
            lastnode = lastnode->next;
            val = val / 10;
            l1 = l1?l1->next:nullptr;
            l2 = l2?l2->next:nullptr;
        }
        ListNode *res = prenode->next;
        delete prenode; // 释放额外引入的prenode
        return res;
    }
};

ListNode *generateListNode(const std::vector<int>& vals);
void freeListNode(ListNode *head);
void printListNode(ListNode *head);

int main() {
    ListNode *pNode1 = generateListNode({1, 4, 6}); // 641
    ListNode *pNode2 = generateListNode({9,4,6,9}); // 9649 res = 10290
    printListNode(pNode1);
    printListNode(pNode2);

    ListNode *res = Solution::addTwoNumbers(pNode1, pNode2);
    printListNode(res);

    freeListNode(res);
    freeListNode(pNode1);
    freeListNode(pNode2);
    return 0;
}

ListNode *generateListNode(const std::vector<int>& vals) {
    ListNode *res = nullptr;
    ListNode *last = nullptr;
    for (auto val : vals) {
        if (last) {
            last->next = new ListNode(val);
            last = last->next;
        } else {
            res = new ListNode(val);
            last = res;
        }
    }
    return res;
}

void freeListNode(ListNode *head) {
    ListNode *node = head;
    while (node) {
        auto temp = node->next;
        delete node;
        node = temp;
    }
}

void printListNode(ListNode *head) {
    ListNode *node = head;
    while (node) {
        std::cout << node->val << ", ";
        node = node->next;
    }
    std::cout << std::endl;
}


