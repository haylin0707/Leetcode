/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

思路：采用“快慢指针”查检查链表是否含有环。让一个指针一次走一步，另一个一次走两步，如果链表中含有环，快的指针会再次和慢的指针相遇。

这里需要注意的一点是算法中循环的条件，这是一个很容易被忽略的细节。

1）因为fast指针比slow指针走得快，所以只要判断fast指针是否为空就好。由于fast指针一次走两步（走得太快了，就容易跌倒！），fast.next可能已经为空（当fast为尾结点时），fast.next.next将会导致NullPointerException异常，所以在while循环中我们要判断fast.next是否为空；

2）考虑一个特殊情况，当输入的链表为空时，算法应该返回false，空链表肯定是不含有环的。如果没有fast != null，也会导致fast.next抛出NullPointerException异常。

TIPS：时刻记着考虑算法的健壮性，当算法的输入为null时会怎样？
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;//slow指针每次走一步
            fast=fast->next->next;//fast指针每次走两步
            if(slow==fast){
                //fast指针赶上了slow指针，说明有环
                return true;
            }
        }
        return false;
    }
};