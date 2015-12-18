/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.
是上次判断是否有环的加强版；要判断环的开始位置

大概思路就是：两个指针slow和fast，都从链表头开始走，slow每次走一步，fast每次走两步，等两个指针重合时，就说明有环，否则没有。如果有环的话，那么让slow指向链表头，fast不动，两个指针每次都走一步，当它们重合时，所指向的节点就是环开始的节点。

证明如下：我们知道slow每次都要比fast多走一步。

              现在，假设slow需要m步第一次走到环的开始节点，那么fast应该走到了环的第m个位置（注意：这里是指环里的位置，slow在0处，fast在m处）。fast每次都比slow多走一步且它们都在环内，所以需要n-m步（n是环的大小），才能追上slow，达到重合。这个重合位置是[2*（n-m）+m-x*n]%n=n-m，这样我们就可以知道，重合的位置距离环开始节点有m步，head距离环开始节点也是m步。

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;//slow指针每次走一步
            fast=fast->next->next;//fast指针每次走两步
            if(slow==fast){
                //fast指针赶上了slow指针，说明有环
                slow=head;//slow指针又重新回到开始head
                while(slow!=fast){
                    //fast在两者相遇的位置，slow在head处，两者到环的开始地方距离相等；
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};