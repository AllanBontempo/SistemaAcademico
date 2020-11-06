abstract class Mamífero {
    public abstract double obterAltura();
  }
  
  class Baleia extends Mamífero {
    public double obterAltura(){
      return 800.0;
    }
  }
  
  class Rato extends Mamifero {
    public double obterAltura() {
      return 5.0;
    }
  }
  
  class Aplicativo {
    public static void main(String args[]){
      System.out.println("Polimorfismo\n");
      Mamifero mamifero1 = new Elefante();
      System.out.println("Altura da baleia em cm: " + mamifero1.obterAltura());
      Mamifero mamifero2 = new Rato();
      System.out.println("Altura do rato em cm: " + mamifero2.obterAltura());
    }
  }
  