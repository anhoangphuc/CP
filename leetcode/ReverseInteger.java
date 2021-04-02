public class ReverseInteger {
    public int reverse(int x) {
        int res = 0;
        try {
            String tx = Integer.toString(Math.abs(x));
            String tx1 = new StringBuilder(tx).reverse().toString();
            res = (x / Math.abs(x)) * Integer.parseInt(tx1);
        } catch (Exception ex) { 
            res = 0;
        }
        return res;
    }

    public static void main(String[] args) {
        ReverseInteger re = new ReverseInteger();
        System.out.println(re.reverse(120));
        System.out.println(re.reverse(-120));
        System.out.println(re.reverse(2119999999));
    }
}
