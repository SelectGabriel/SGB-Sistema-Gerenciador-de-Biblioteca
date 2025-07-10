#include <iostream>
using namespace std;

void mensagemEscolhaMenu();

int main() {
    //Menu princiapal do gerenciador de biblioteca
    string operacaoDesejada = "";
    string mensagemLocalAtualLivros = "Você está no gerenciamento de Livros \n";
    string localAtualEmprestimos = "Você está no gerenciamento de Emprestimos \n";
    string localAtualUsuarios = "Você está no gerenciamento de usuários \n";
    int menuPrincipalAtual = 0;

    cout << "Olá, seja bem vindo ao sistema de Biblioteca! \n";
    cout << "************************************************ \n";

    mensagemEscolhaMenu();

    cin >> operacaoDesejada;

    while (operacaoDesejada != "sair")
    {
        //Switch case com String não é possível sem uma engenharia adicional, portanto usarei IFs
        if (operacaoDesejada == "1"){
            cout << mensagemLocalAtualLivros;
            menuPrincipalAtual = 1;
        }

        if (operacaoDesejada == "2"){
            cout << localAtualEmprestimos;
            menuPrincipalAtual = 3;
        }

        if (operacaoDesejada == "3"){
            cout << localAtualUsuarios;
            menuPrincipalAtual = 3;
        }

        mensagemEscolhaMenu();
        cin >> operacaoDesejada;
    }

    return 0;
}

void mensagemEscolhaMenu(){
    cout << "************************************************ \n";
    cout << "o que deseja fazer? \n";
    cout << "************************************************ \n";
    cout << "1. Gerenciar livros \n";
    cout << "2. Gerenciar emprestimos \n";
    cout << "3. Gerenciar usuários \n";
}