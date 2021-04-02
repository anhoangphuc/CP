<<<<<<< HEAD

public class PalindromeNumber {
    public boolean isPalindrome(int x) {
        var tmpX = String.valueOf(x);
        return tmpX.equals(new StringBuilder(tmpX).reverse().toString());
    }

    public static void main(String[] args) {
        var palindrome = new PalindromeNumber();
        System.out.println(palindrome.isPalindrome(121));
        System.out.println(palindrome.isPalindrome(-121));
        System.out.println(palindrome.isPalindrome(10));
    }
=======
public class PalindromeNumber {
    public static void main(String[] args) {
    }
>>>>>>> ab9b0d586098bc648496ece1c2e6bb61f2dcf16d
}