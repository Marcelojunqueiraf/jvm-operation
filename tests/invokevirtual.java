class animal {

  String nome = "cachorro";
  String cor;

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
    a.nome = "gato1";
    a.grito();

    animal b = new animal();
    b.nome = "gato";
    b.grito();
  }
}
