# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        ans = l2    # overwrite on the same node
        temp = ans
        while l1 is not None or l2 is not None:
            left, right = 0, 0
            if l1 is not None:
                left = l1.val
                l1 = l1.next
            if l2 is not None:
                right = l2.val
                l2 = l2.next

            val = left + right + carry
            carry = 0
            if val >= 10:
                carry = 1
                val -= 10
            temp.val = val
            if l1 is not None or l2 is not None:
                temp.next = ListNode()
                temp = temp.next
        if carry:
            temp.next = ListNode(1, None)
        return ans
