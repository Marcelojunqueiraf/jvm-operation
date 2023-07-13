public class ifzero {
  public static void main(String[] args) {

    // resultados esperados
    // <, >, >=, >=, <=, <=, ==, !=

    int i = -5;
    System.out.println(i);
    if (i < 0) {
      System.out.println("1: i < 0");
    } else {
      System.out.println("1: i >= 0");
    }
    
    i = 77;
    System.out.println(i);
    if (i > 0) {
      System.out.println("2: i > 0");
    } else {
      System.out.println("2: i <= 0");
    }
    
    i = 777;
    System.out.println(i);
    if (i >= 0) {
      System.out.println("3: i >= 0");
    } else {
      System.out.println("3: i < 0");
    }

    i = 0;
    System.out.println(i);
    if (i >= 0) {
      System.out.println("4: i >= 0");
    } else {
      System.out.println("4: i < 0");
    }
    
    i = -77;
    System.out.println(i);
    if (i <= 0) {
      System.out.println("5: i <= 0");
    } else {
      System.out.println("5: i > 0");
    }

    i = 0;
    System.out.println(i);
    if (i <= 0) {
      System.out.println("6: i <= 0");
    } else {
      System.out.println("6: i > 0");
    }

    i = 0;
    System.out.println(i);
    if (i == 0) {
      System.out.println("7: i == 0");
    } else {
      System.out.println("7: i != 0");
    }


    i = -11;
    System.out.println(i);
    if (i != 0) {
      System.out.println("8: i != 0");
    } else {
      System.out.println("8: i == 0");
    }

  }
}
