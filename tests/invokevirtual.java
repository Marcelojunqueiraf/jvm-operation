class animal {

  String nome = "cachorro";
  String cor;
  long idade;
  static String country;

  animal() {
    System.out.println("animal constructor");
  }
  
  public void grito(String nome, long idade) {
    System.out.println(nome);
    System.out.println(idade);
  }

  public void printCountry() {
    System.out.println(country);
  }

}

public class invokevirtual {
  public static void main(String[] args) {
    animal a = new animal();
    a.idade = 21474836470l;
    System.out.println(a.idade);
    a.grito(a.nome, a.idade);

    animal b = new animal();
    b.nome = "gato";
    b.grito(b.nome, b.idade);

    System.out.println(b.idade); // 0
    System.out.println(b.cor); // null

    b.printCountry(); // null
    b.country = "brasil";
    b.printCountry(); // brasil
  }
}
