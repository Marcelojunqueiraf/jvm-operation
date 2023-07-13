public class ifcmp {
  public static void main(String[] args) {

    // resultados esperados
    // <, >, >=, >=, <=, <=, ==, !=

    int i = 5;
    int j = 10;
    System.out.println(i);
    System.out.println(j);
    if (i < j) {
      System.out.println("1: i < j");
    } else {
      System.out.println("1: i >= j");
    }
    
    i = 77;
    j = 11;
    System.out.println(i);
    System.out.println(j);
    if (i > j) {
      System.out.println("2: i > j");
    } else {
      System.out.println("2: i <= j");
    }
    
    i = 777;
    j = 11;
    System.out.println(i);
    System.out.println(j);
    if (i >= j) {
      System.out.println("3: i >= j");
    } else {
      System.out.println("3: i < j");
    }

    i = 88;
    j = 88;
    System.out.println(i);
    System.out.println(j);
    if (i >= j) {
      System.out.println("4: i >= j");
    } else {
      System.out.println("4: i < j");
    }
    
    i = -77;
    j = 11;
    System.out.println(i);
    System.out.println(j);
    if (i <= j) {
      System.out.println("5: i <= j");
    } else {
      System.out.println("5: i > j");
    }

    i = 88;
    j = 88;
    System.out.println(i);
    System.out.println(j);
    if (i <= j) {
      System.out.println("6: i <= j");
    } else {
      System.out.println("6: i > j");
    }

    i = -11;
    j = -11;
    System.out.println(i);
    System.out.println(j);
    if (i == j) {
      System.out.println("7: i == j");
    } else {
      System.out.println("7: i != j");
    }


    i = -11;
    j = 11;
    System.out.println(i);
    System.out.println(j);
    if (i != j) {
      System.out.println("8: i != j");
    } else {
      System.out.println("8: i == j");
    }

  }
}
