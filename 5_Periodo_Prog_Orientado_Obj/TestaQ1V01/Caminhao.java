import java.util.Scanner;

public class Caminhao extends atributosIniciais{

        //Entrada de dados
        Scanner ler = new Scanner(System.in);
        private boolean palavra;
        private boolean arcond;
        private boolean dirHidraulica;
        private boolean ExtensaoCabine;
    
        //Construtor
        public Caminhao(){
            super();
        }//default
    
        //sobrecarregado
        public Caminhao(boolean palavra,boolean arcond,boolean dirHidraulica,boolean ExtensaoCabine,String placa, float peso, int passageiros, float cargas,
            float pesoTotal){
            super(placa, peso, passageiros, cargas, pesoTotal);
            this.palavra = palavra;
            this.arcond = arcond;
            this.dirHidraulica = dirHidraulica;
            this.ExtensaoCabine = ExtensaoCabine;
        }
        boolean atributosCaminhao(){
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
            System.out.printf("Extensao de babine? (true/false): \n");
            this.ExtensaoCabine = ler.nextBoolean();
            this.setPesoTotal(this.getPesoTotal() + 87);
            //this.setPesoTotal(this.getPesoTotal() + this.Peso);
            return this.palavra;
        }

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

    public float getExtensaoCabine() {
        return ExtensaoCabine;
    }

    public void setExtensaoCabine(float ExtensaoCabine) {
        this.ExtensaoCabine = ExtensaoCabine;
    }

}
