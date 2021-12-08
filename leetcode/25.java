class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode endOfPreviousSegment = null, curr = head, next, startOfThisSegment = null;
        int cnt = 0;
        while (curr != null) {
            cnt += 1;
            next = curr.next; 
            curr.next = startOfThisSegment;
            if (cnt == 1)
                startOfThisSegment = curr;
            curr = next;
            if (cnt == k) {
                cnt = 0;
                endOfPreviousSegment.next = startOfThisSegment;
                endOfPreviousSegment = curr;
            }
        }
    }
}