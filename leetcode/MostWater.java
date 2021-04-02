<<<<<<< HEAD
import java.util.stream.IntStream;

public class MostWater {
    public int maxArea(int[] height) {
        int res = 0;
        IntStream.range(0, height.length)
        .forEach(i -> {
            IntStream.range(0, height.length).forEach(j -> {res = 1;});
        });
        //.forEach(j -> res = Math.max(res, Math.abs(i - j) * Math.min(height[i], height[j]))));
        return res;
    }

    public static void main(String[] args) {
        var myClass = new MostWater();
        myClass.maxArea(IntStream.range(0, 10).toArray());
    }
=======
import java.util.stream.IntStream;

public class MostWater {
    private int res = 0;
    public int maxArea(int[] height) {
    }

    public static void main(String[] args) {
        var myClass = new MostWater();
        System.out.println(myClass.maxArea(new int[] {1,8,6,2,5,4,8,3,7 }));
    }
>>>>>>> ab9b0d586098bc648496ece1c2e6bb61f2dcf16d
}