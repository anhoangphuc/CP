import java.math.BigInteger;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import java.util.List;

public class StringToInteger {
    public int myAtoi(String str) {
        int res = 0; 
        System.out.println(str);
        str = str.strip();
        List<String> firstPart = str.chars().mapToObj(i -> (char)i + "").takeWhile(i -> "0123456789-+".contains(i)).collect(Collectors.toList());
        String secondPart = Stream.concat(firstPart.stream().limit(1), firstPart.stream().skip(1).takeWhile(i -> "0123456789".contains(i))).collect(Collectors.joining(""));
        System.out.println(secondPart);
        try {
            var tmpNumber = new BigInteger(secondPart);
            tmpNumber = tmpNumber.min(BigInteger.valueOf(Integer.MAX_VALUE));
            tmpNumber = tmpNumber.max(BigInteger.valueOf(Integer.MIN_VALUE));
            res = tmpNumber.intValue();
        } catch (Exception ex) {
            res = 0;
        } finally {
            return res;
        }
    }  
    public static void main(String[] args) {
        var myClass = new StringToInteger();
        System.out.println(myClass.myAtoi("abcd "));
        System.out.println(myClass.myAtoi("1234 345 "));
        System.out.println(myClass.myAtoi("a1234 345 "));
        System.out.println(myClass.myAtoi("1234d 345 "));
        System.out.println(myClass.myAtoi("999999999999999 aa"));
        System.out.println(myClass.myAtoi("-5-"));
    }
}