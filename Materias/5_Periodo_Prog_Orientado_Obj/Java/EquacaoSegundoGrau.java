import java.util.Scanner;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.SystemMenuBar;

public class EquacaoSegundoGrau{
    public static void main(String[] args) {
        //Declarar Variaveis:
        int a, b, c, delta, d = -4, b2, v2;
        double r1, r2;

        //Importar um Scanner para ler nossas variaveis;
        Scanner scan = new Scanner(System.in);

        System.out.println("Digite o valor de 'a': ");
        a = scan.nextInt();
        while(a==0){
            System.out.println("O valor da 'a' não pode ser igual a 0");
            System.out.println("Digite novamente um valor para 'a': ");
            a = scan.nextInt();
        }
        System.out.println("Digite o valor de 'b': ");
        b = scan.nextInt();

        System.out.println("Digite o valor de 'c': ");
        c = scan.nextInt();

        System.out.println("Resolvendo o valor de Delta");

        System.out.println("A formula de Delta é: b^2-4.a.c");
        System.out.println("Substituindo na formula, temos: "+ b + "^2"+d+"."+a+"."+c);

        b2 = b*b;
        v2 = ((d) *(a)*(c));

        delta = (b2)+(v2);

        System.out.println(" ");

        System.out.println("O valor de Delta é: "+delta);

        if(delta < 0){
            System.out.println("A equação não possui raizes reais");
        }else{
            r1 = (-b + Math.sqrt(delta))/(2*a);
            r2 = (-b - Math.sqrt(delta))/(2*a);
            System.out.println(" ");
            System.out.println("A raíz 1 de x' :" +r1 );
            System.out.println("A raíz 1 de x'' :" +r2 );
        }
    }
}