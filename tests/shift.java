public class shift {
    public static void main(String args[]) {
        int x = 10;
        int y = 2;
        long z = 100L;
        int res = x << y;
        long res2 = z << y;
        res = x >> y;
        res2 = z >> y;
        res = x >>> y;
        res2 = z >>> y;
        x = -10;
        z = -100L;
        res = x << y;
        res2 = z << y;
        res = x >> y;
        res2 = z >> y;
        res = x >>> y;
        res2 = z >>> y; 
        System.out.println(res);
    }
}