public class Aluno extends Pessoa {

    int matricula;

    Aluno(String nome, int idade, int matricula){
        //this.matricula = matricula;
        super(nome, idade);
        this.matricula = matricula; 
    }

    public char[] dizerNome;
    String dizerMatricula(){
        return "Minha matricula é " + this.matricula;
    }

    String dizerNome(){
        return super.dizerNome() + this.dizerMatricula();
    }
}
