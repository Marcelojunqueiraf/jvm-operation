
interface control {
    public void end_alert();
};


interface animals_actions {
    public void animal_sound();
    public void animal_run();
};  

abstract class animal {
    public String cor_pelo;
    public static String planeta = "terra";

  String getCorPelo() {
    return cor_pelo;
  }

};  

class lion extends animal implements animals_actions{
    
    public lion(String cor_pelo){
        super.cor_pelo = cor_pelo;
    };
    
    public void animal_sound(){
        System.out.println("ROAARRR!");
    }
    
    public void animal_run(){
        System.out.println("leão correndo.");
    }
    
}

class cat extends animal implements animals_actions{
    
    public cat(String cor_pelo){
        super.cor_pelo = cor_pelo;
    };
    
    public void animal_sound(){
        System.out.println("MIAUUUU!");
    }

    public void animal_run(){
        System.out.println("gato andando.");
    }

}

public class zoo implements control{
    
    static {int x = 10; System.out.println("Dentro do bloco estático animal!");};
    
    public void end_alert(){
        System.out.println("zooooooo");
    };
    
    String nome_zelador = "José"; 
    int idade_zelador = 72;
    double altura_zelador = 1.75;
    
    // attribute final 
    // qual a diferença entre essas duas?
    // uma é de classe e a outra de instância 
    // ambas vão para a constant pool
    static final int numero_favorito = 20;
    final int ano_nascimento = 1923;
    final long teste_long = 18;
    final char teste_char = 'a';
    final boolean teste_bool = true;
    final float teste_float = 1.5f;
    final double teste_double = 50.89;
    final String teste_string = "teste";
    static int numero_favorito_mae = 20;

    public void teste() throws Exception {
        int local = 0;
    }


    public static void main(String[] args){
        zoo zoologico = new zoo(); // Dentro do bloco estático animal!
        zoologico.end_alert(); // zooooooo
        String cor_pelo_gatinho = "azul";
        String cor_pelo_leao = "preto";

        cat gatinho = new cat(cor_pelo_gatinho);
        lion leao = new lion(cor_pelo_leao);
        
        System.out.println(cat.planeta); // terra
        System.out.println(gatinho.planeta); // terra

        System.out.println(leao.getCorPelo()); // preto

        gatinho.animal_sound(); // MIAUUUU!
        leao.animal_sound(); // ROAARRR!

        // System.out.println("cor pelo leao = " + leao.cor_pelo); // cor pelo leao = preto
        // System.out.println("cor pelo gato = " + gatinho.cor_pelo);  // cor pelo gato = azul
    };

}