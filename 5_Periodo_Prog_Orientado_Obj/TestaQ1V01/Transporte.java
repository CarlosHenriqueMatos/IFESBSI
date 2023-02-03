import java.util.Scanner;

import javax.swing.text.StyledEditorKit.BoldAction;

public class Transporte extends atributosIniciais{
    //Entrada de dados
    Scanner ler = new Scanner(System.in);
    private boolean palavra;
    private boolean arcond;
    private boolean dirHidraulica;
    private float portaMalas;

    //Construtor
    public Transporte(){
        super();
    }//default

    //sobrecarregado
    public Transporte(boolean palavra,boolean arcond,boolean dirHidraulica,float portaMalas,String placa, float peso, int passageiros, float cargas,
        float pesoTotal){
        super(placa, peso, passageiros, cargas, pesoTotal);
        this.palavra = palavra;
        this.arcond = arcond;
        this.dirHidraulica = dirHidraulica;
        this.portaMalas = portaMalas;
    }
    boolean atributosCarro(){
        System.out.printf("Vidros-elétricos? (true/false): \n");
        this.palavra = ler.nextBoolean();
        if(palavra == true){
            this.setPesoTotal(this.getPesoTotal() + 20);    
        }
        System.out.printf("Ar-Condicionado? (true/false): \n");
        this.arcond = ler.nextBoolean();
        if(arcond == true){
            this.setPesoTotal(this.getPesoTotal() + 26);    
        }
        System.out.printf("Direção hidraulica? (true/false): \n");
        this.dirHidraulica = ler.nextBoolean();
        if(dirHidraulica == true){
            this.setPesoTotal(this.getPesoTotal() + 120);    
        }
        System.out.printf("Quantos quilos leva no porta-malas? \n");
        this.portaMalas = ler.nextFloat();
        this.setPesoTotal(this.getPesoTotal() + this.portaMalas);
        //this.setPesoTotal(this.getPesoTotal() + this.Peso);
        return this.palavra;
    }

    //Getters and Setters
    
    public boolean isPalavra() {
        return palavra;
    }

    public void setPalavra(boolean palavra) {
        this.palavra = palavra;
    }

    public boolean isArcond() {
        return arcond;
    }

    public void setArcond(boolean arcond) {
        this.arcond = arcond;
    }

    public boolean isDirHidraulica() {
        return dirHidraulica;
    }

    public void setDirHidraulica(boolean dirHidraulica) {
        this.dirHidraulica = dirHidraulica;
    }

    public float getPortaMalas() {
        return portaMalas;
    }

    public void setPortaMalas(float portaMalas) {
        this.portaMalas = portaMalas;
    }

}