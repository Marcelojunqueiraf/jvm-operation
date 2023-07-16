public class Conversions {
  public static void main(String[] args) {

    int i = -2147483647;
    System.out.println(i);
    long i2l = i;
    System.out.println(i2l);
    float i2f = i;
    System.out.println(i2f);
    double i2d = i;
    System.out.println(i2d);
    byte i2b = (byte) i;
    System.out.println(i2b);
    char i2c = (char) i;
    System.out.println(i2c);
    short i2s = (short) i;
    System.out.println(i2s);

    long l = -9223372036854775000L;
    System.out.println(l);
    int l2i = (int) l;
    System.out.println(l2i);
    float l2f = l;
    System.out.println(l2f);
    double l2d = l;
    System.out.println(l2d);

    float f = -3.123456789123456789f;
    System.out.println(f);
    int f2i = (int) f;
    System.out.println(f2i);
    long f2l = (long) f;
    System.out.println(f2l);
    double f2d = f;
    System.out.println(f2d);

    double d = -123.123456789123456789;
    System.out.println(d);
    int d2i = (int) d;
    System.out.println(d2i);
    long d2l = (long) d;
    System.out.println(d2l);
    float d2f = (float) d;
    System.out.println(d2f);

  }
}
