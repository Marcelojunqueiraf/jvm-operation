class polymClass {

  String nome = "cachorro";
  long idade = 10;

  polymClass() {
    System.out.println("construtor");
  }

  polymClass(String nome, long idade) {
    this.nome = nome;
    this.idade = idade;
  }

  public void grito() {
    System.out.println(nome);
    System.out.println(idade);
  }

  public void grito(String nome) {
    System.out.println(nome);
    System.out.println(idade);
  }

  public void grito(String nome, long idade) {
    System.out.println(nome);
    System.out.println(idade);
  }
}

public class polym {
  public static void main(String[] args) {
    polymClass a = new polymClass(); // construtor
    a.grito(); // cachorro 10
    a.grito("custom gato"); // custom gato 10
    a.grito("custom gato", 123123); // custom gato 123123

    polymClass b = new polymClass("custom cachorro", 123123);
    b.grito(); // custom cachorro 123123
  }
}
