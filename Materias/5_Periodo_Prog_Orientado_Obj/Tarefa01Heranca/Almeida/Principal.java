public class Principal {
    public static void main(String[] args){
        Aluno aluno = new Aluno("Teste",23,123);
        //aluno.nome = "Teste";
        //aluno.idade = 23;
        //aluno.matricula = 234;
        System.out.println(aluno.dizerNome());
    }
}
