class animal {

  String nome = "cachorro";
  String cor;
  long idade;

  animal() {
    System.out.println("animal constructor");
  }
  
  public void grito(String nome) {
    System.out.println(nome);
  }

}

public class invokevirtual {
  public static void main(String[] args) {
    animal a = new animal();
    a.idade = 21474836470l;
    System.out.println(a.idade);
    a.grito(a.nome);

    animal b = new animal();
    b.nome = "gato";
    b.grito(b.nome);

    System.out.println(a.cor);
  }
}
