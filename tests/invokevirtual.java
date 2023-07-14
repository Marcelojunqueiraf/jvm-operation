class animal {

  animal() {
    System.out.println("constructor");
  }
  
  public void grito() {
    System.out.println("auuu");
  }

}

public class invokevirtual {
  public static void main(String[] args) {
    animal a = new animal();
    a.grito();
  }
}
