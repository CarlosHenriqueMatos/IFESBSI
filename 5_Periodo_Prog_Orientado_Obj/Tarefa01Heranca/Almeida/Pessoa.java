public class Pessoa extends Object{
    String nome;
    int idade;

    Pessoa(String nome, int idade){
        this.nome = nome;
        this.idade = idade;
    }

    String dizerNome(){
        return "Meu nome é " + nome + " e possuo " +
            this.idade + " anos";
    }

}
