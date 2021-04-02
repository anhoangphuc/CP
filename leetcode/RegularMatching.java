
public class RegularMatching {
    boolean[][] check = new boolean[1000][1000];
    public boolean isMatch(String s, String p) {
        check[0][0] = true;
        for (int i = 0; i <= s.length(); i++)
            for (int j = 1; j <= p.length(); j++) {
                if (i > 0 && s.charAt(i - 1) == p.charAt(j - 1))
                    check[i][j] = check[i][j] | check[i - 1][j - 1];
                if (i > 0 && p.charAt(j - 1) == '.')
                    check[i][j] = check[i][j] | check[i - 1][j - 1];
                if (i > 0 && p.charAt(j - 1) == '*' && j > 1 && (p.charAt(j - 2) == s.charAt(i - 1) || p.charAt(j - 2) == '.')) {
                    check[i][j] = check[i][j] | check[i - 1][j - 1];
                    check[i][j] = check[i][j] | check[i - 1][j];
                }
                if (p.charAt(j - 1) == '*')
                    check[i][j] = check[i][j] | check[i][j - 1];
                if (p.charAt(j - 1) == '*' && j > 1)
                    check[i][j] = check[i][j] | check[i][j - 2];
            }
        return check[s.length()][p.length()];
    }


    public static void main(String[] args) {
        var regular = new RegularMatching();
        System.out.println(regular.isMatch("aaa", ".*"));
    }
}