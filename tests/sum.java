public class sum {
  public static void main(String[] args){
    int i1 = 5, i2 = 4;
    int i3 = i1 - i2;
    i3 -= 2;
    System.out.println(i3); // -1

    int i4 = -1;
    long l1 = 21474836470l;
    long l2 = i4 + l1;
    System.out.println(l2); // 21474836469

    float f1 = 1.33f, f2 = 0.66f;
    float f3 = f1 - f2;
    System.out.println(f3); // 0.67

    double d1 = 1.7777555, d2 = 3.4444888;
    double d3 = d1 - d2;
    System.out.println(d3); // -1.66673


    System.out.println(1.0/0.0); // Infinity
  }
}