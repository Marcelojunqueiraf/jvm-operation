class animal {

  String nome = "cachorro";
  
  public static void grito(String nome, long idade) {
    System.out.println(nome);
    System.out.println(idade);
  }

}

public class InvokeStatic {
  public static void main(String[] args) {
    animal.grito("cachorro estatico", 21474836470l);
  }
}
