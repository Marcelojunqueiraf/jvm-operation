public class print{
  public static void main(String[] args){
    
    System.out.println("EMPTY");
    System.out.println();

    System.out.println("BOOL");
    System.out.println(true);
    
    char myChar = 'M';
    System.out.println("CHAR");
    System.out.println(myChar);

    // TODO: array not supported
    // char[] myChars = {'A', 'W', 'P'};
    // System.out.println("CHAR[]");
    // System.out.println(myChars);
    
    System.out.println("DOUBLE");
    System.out.println(3.14159265358979323846);
    
    System.out.println("FLOAT");
    System.out.println(3.14159265358979323846f);
    
    System.out.println("INT");
    System.out.println(2147483647);
    
    System.out.println("LONG");
    System.out.println(9223372036854775807l);
    
    System.out.println("OBJECT");
    System.out.println("// TODO:");

    System.out.println("BYTE");
    System.out.println((byte) 127); // jvm converts to int

    System.out.println("STRING");
    System.out.println("Hello World!"); // STRING
    
    System.out.println("SHORT");
    System.out.println((short) 32767); // jvm converts to int

  }
}