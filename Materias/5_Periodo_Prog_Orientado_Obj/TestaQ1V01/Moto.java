import java.util.Scanner;

public class Moto extends atributosIniciais {

        //Entrada de dados
        Scanner ler = new Scanner(System.in);
        private boolean bagageiro;
        private boolean mata_cachorro;
    
        //Construtor
        public Moto(){
            super();
        }//default
    
        //sobrecarregado
        public Moto(boolean bagageiro,boolean mata_cachorro,String placa, float peso, int passageiros, float cargas,
            float pesoTotal){
            super(placa, peso, passageiros, cargas, pesoTotal);
            this.bagageiro = bagageiro;
            this.mata_cachorro = mata_cachorro;
        }
        boolean atributosMoto(){
            System.out.printf("Bagageiro? (true/false): \n");
            this.bagageiro = ler.nextBoolean();
            if(bagageiro == true){
                this.setPesoTotal(this.getPesoTotal() + 2);    
            }
            System.out.printf("Mata_cachorro? (true/false): \n");
            this.mata_cachorro = ler.nextBoolean();
            if(mata_cachorro == true){
                this.setPesoTotal(this.getPesoTotal() + 3);    
            }
            return this.bagageiro;
        }

    public boolean isBagageiro() {
        return bagageiro;
    }

    public void setBagageiro(boolean bagageiro) {
        this.bagageiro = bagageiro;
    }

    public boolean isMata_cachorro() {
        return mata_cachorro;
    }

    public void setMata_cachorro(boolean mata_cachorro) {
        this.mata_cachorro = mata_cachorro;
    }

}
