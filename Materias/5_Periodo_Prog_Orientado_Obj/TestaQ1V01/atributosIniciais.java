import java.util.Scanner;
public class atributosIniciais {
    //Variaveis
    Scanner ler = new Scanner(System.in);
    private String placa;
    private float peso;
    private int passageiros;
    private float cargas;
    private float pesoTotal;
    private float acumulado;

    public Transporte(){}

    public Transporte(String placa, float peso, int passageiros, float cargas, float pesoTotal,float acumulado){
        this.placa = placa;
        this.peso = peso;
        this.passageiros = passageiros;
        this.cargas = cargas;
        this.pesoTotal = pesoTotal;
        this.acumulado = acumulado;
    }
    
    String atributosPrincipais(){
        System.out.printf("Placa :\n");
        this.placa = ler.next();
        System.out.printf("Peso base/líquido :\n");
        this.peso = ler.nextFloat();
        this.setPesoTotal(this.getPesoTotal() + this.peso);//Soma todos os pesos//
        System.out.printf("Quantidade máxima de passageiros :\n");
        this.passageiros = ler.nextInt();
        this.setPesoTotal(this.getPesoTotal() + this.passageiros*80);//Soma todos os pesos//
        System.out.printf("capacidade máxima de cargas :\n");
        this.cargas = ler.nextFloat();
        this.setPesoTotal(this.getPesoTotal() + this.cargas);//Soma todos os pesos//
        return placa;//retornar uma lista encadeada
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public float getPeso() {
        return peso;
    }

    public void setPeso(float peso) {
        this.peso = peso;
    }

    public int getPassageiros() {
        return passageiros;
    }

    public void setPassageiros(int passageiros) {
        this.passageiros = passageiros;
    }

    public float getCargas() {
        return cargas;
    }

    public void setCargas(float cargas) {
        this.cargas = cargas;
    }

    public float getPesoTotal() {
        return pesoTotal;
    }

    public void setPesoTotal(float pesoTotal) {
        this.pesoTotal = pesoTotal;
    }

    public float getAcumulado() {
        return acumulado;
    }

    public void setAcumulado(float acumulado) {
        this.acumulado = acumulado;
    }

}
