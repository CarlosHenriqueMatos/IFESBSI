import java.util.Scanner;
public class PrincipalPolimorfismo {
    public static void main(String[] args){
        Scanner ler = new Scanner(System.in);
        String tipo = " ";
        float acumulador;
        System.out.printf("Tipo do carro :\n");
        tipo = ler.next();

        while (tipo.equals("-") != true){
            if (((tipo.equals("c")) || tipo.equals("C"))){//Carro
                Transporte c = new Transporte();
                modeloTransporte(c);
            }
            if (((tipo.equals("t")) || tipo.equals("T"))){//Caminhao
                Caminhao t = new Caminhao();
                moverVeiculo(t);
            }
            if (((tipo.equals("m")) || tipo.equals("M"))){//Motos
                Moto m = new Moto();
                infMoto(m);
            }
            System.out.printf("Tipo do carro :\n");
            tipo = ler.next();
        }
    }
    static void modeloTransporte(Transporte tipo){
        tipo.atributosPrincipais();//Entrada dos atibutos comuns a todas classes
        tipo.atributosCarro();//pegando por herança
        System.out.println("O peso do carro: " + tipo.getPesoTotal());//informa o peso de cada carro
        System.out.println("Acumulado " + tipo.getAcumulado());
    }
    static void moverVeiculo(Caminhao trans){//dentro do () eu coloco o que eu quero chamar nesse caso eu quero chamar o veiculo
        trans.atributosPrincipais();
        trans.atributosCaminhao();
        System.out.println("O peso do Caminhao: " + trans.getPesoTotal());
    }
    static void infMoto(Moto mov){//dentro do () eu coloco o que eu quero chamar nesse caso eu quero chamar o veiculo
        mov.atributosPrincipais();
        mov.atributosMoto();
        System.out.println("O peso da moto: " + mov.getPesoTotal());
    }

}
