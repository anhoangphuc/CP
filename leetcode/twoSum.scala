object Solution {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    nums.zipWithIndex.map{
    case (value, ind2) => (ind2, nums.lastIndexOf(target - value))}
  }.filter(x => x._2 >= 0 && x._2 > x._1).flatMap(x => Array(x._1, x._2))
  def main(args: Array[String]): Unit = {
    twoSum(Array(1, 2, 3, 5), 4);
  }
}
