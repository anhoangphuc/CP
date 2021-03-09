class ListNode(var _x: Int = 0) {
  var next: ListNode = null
  var x: Int = _x
}

object Solution {
  def addTwoNumbers(ll1: ListNode, ll2: ListNode): ListNode = {
    var res = new ListNode
    var l1 = ll1
    var l2 = ll2
    var tres = res
    var x1: Int = 0
    var x2: Int = 0
    var carry = 0
    while (l1 != null || l2 != null) {
      if (l1 != null) {
        x1 = l1.x
        l1 = l1.next
      }
      else x1 = 0

      if (l2 != null) {
        x2 = l2.x
        l2 = l2.next
      }
      else x2 = 0
 
      tres.x = (x1 + x2 + carry) % 10
      carry = (x1 + x2 + carry) / 10
      if (l1 != null || l2 != null) {
        tres.next = new ListNode
        tres = tres.next
      }

    }
    
    if (carry > 0) {
      tres.next = new ListNode
      tres = tres.next
      tres.x = carry
    }
    return res
  }
  def main(args: Array[String]): Unit = {
    var l1 = new ListNode(2)
    l1.next = new ListNode(3)
    var l2 = new ListNode(8)
    l2.next = new ListNode(2)
    var res = addTwoNumbers(l1, l2)
    while (res != null) {
      println(res.x)
      res = res.next
    }
  }
}
