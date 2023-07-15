class animal {

  String nome = "cachorro";
  String cor;

  animal() {
    System.out.println("constructor");
  }
  
  public void grito(String nome) {
    System.out.println(nome);
  }

}

public class invokevirtual {
  public static void main(String[] args) {
    animal a = new animal();
    a.grito(a.nome);

    animal b = new animal();
    b.nome = "gato";
    b.grito(b.nome);
  }
}
