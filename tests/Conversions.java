public class Conversions {
  public static void main(String[] args) {

    int i = -2147483647;
    long i2l = i;
    float i2f = i;
    double i2d = i;
    byte i2b = (byte) i;
    char i2c = (char) i;
    short i2s = (short) i;

    long l = -9223372036854775000L;
    int l2i = (int) l;
    float l2f = l;
    double l2d = l;

    float f = -3.123456789123456789f;
    int f2i = (int) f;
    long f2l = (long) f;
    double f2d = f;

    double d = -123.123456789123456789;
    int d2i = (int) d;
    long d2l = (long) d;
    float d2f = (float) d;

  }
}
