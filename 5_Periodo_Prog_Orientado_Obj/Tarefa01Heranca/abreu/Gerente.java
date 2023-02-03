public class Gerente extends Funcionario{
    private int nFuncionarios;//Atributos-Variaveis de instância

    //construtores
    public Gerente(){ //default
        super();
    }
    public Gerente(int nFuncionarios, String nome, float salario){
        super(nome, salario);
        this.nFuncionarios = nFuncionarios;
    }
    //getters/setters
    //.../
    //Reescrita do metodo aumentarSalario
    @Override
    public void aumentarSalario(float perc){
        super.aumentarSalario(perc + 20);
    }

    //Reescrita do metodo imprimir
    @Override
    public String imprimir(){
        return super.imprimir() + "Numero de funcionarios que gerencia: " +
        nFuncionarios+"\n";
    }
}