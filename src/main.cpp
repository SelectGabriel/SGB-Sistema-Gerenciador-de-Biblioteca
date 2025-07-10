#include <iostream>
using namespace std;

#define mensagemLocalAtualLivros "Você está no gerenciamento de Livros \n";
#define localAtualEmprestimos "Você está no gerenciamento de Emprestimos \n";
#define localAtualUsuarios "Você está no gerenciamento de usuários \n";
#define mensagemAdeus "até logo! \n"

void mensagemEscolhaMenu();
void menuLivros();
void menuEmprestimos();
void menuUsuarios();

int escolhaMenu(string menuEscolhido);

int main() {
    //Menu princiapal do gerenciador de biblioteca
    string operacaoDesejada = "";
    int menuPrincipalAtual = 0;

    cout << "Olá, seja bem vindo ao sistema de Biblioteca! \n";
    cout << "************************************************ \n";

    while (operacaoDesejada != "sair"){
        mensagemEscolhaMenu();
        cin >> operacaoDesejada;
        menuPrincipalAtual = escolhaMenu(operacaoDesejada);

        switch (menuPrincipalAtual)
        {
        case 1:
            menuLivros();
            break;
        case 2:
            menuEmprestimos();
            break;
        case 3:
            menuUsuarios();
            break;
        case 99:
            return 0;

        default:
            cout << "não entendi sua requisição";
            break;
        }
    }
}

void mensagemEscolhaMenu(){
    cout << "************************************************ \n";
    cout << "o que deseja fazer? \n";
    cout << "************************************************ \n";
    cout << "1. Gerenciar livros \n";
    cout << "2. Gerenciar emprestimos \n";
    cout << "3. Gerenciar usuários \n";
    cout << "sair. Sair do sistema \n";
}

int escolhaMenu(string menuEscolhido){
    string operacaoDesejada;
    int menu;

    //Switch case com String não é possível sem uma engenharia adicional, portanto usarei IFs
    if (menuEscolhido == "1"){
        menu = 1;
    }

    if (menuEscolhido == "2"){
        cout << localAtualEmprestimos;
        menu = 3;
    }

    if (menuEscolhido == "3"){
        cout << localAtualUsuarios;
        menu = 3;
    }

    if (menuEscolhido == "sair"){
        cout << mensagemAdeus;
        menu = 99;
    }
    return menu;
}

void menuLivros(){
    string operacaoDesejada;

    cout << mensagemLocalAtualLivros;
    while (operacaoDesejada != "voltar")
    {
        cout << "o que deseja fazer?\n";
        cout << "Voce pode:\n";
        cout << "1. Adicionar novo livro \n";
        cout << "2. Listar todos os livros \n";
        cout << "3. Buscar livro \n";
        cout << "4. Atualizar informações de um livro \n";
        cout << "5. Definir um livro como não disponível \n";

        cin >> operacaoDesejada;
    }
}

void menuEmprestimos(){
    string operacaoDesejada;

    cout << localAtualEmprestimos;
    while (operacaoDesejada != "voltar")
    {
        cout << "o que deseja fazer?\n";
        cout << "Voce pode:\n";
        cout << "1. Registrar um empréstimo \n";
        cout << "2. Registrar uma devolução \n";
        cout << "3. Mostrar todos os livros emprestados de uma pessoa \n";
        cout << "4. Mostrar todos os empréstimos ativos \n";

        cin >> operacaoDesejada;
    }
}

void menuUsuarios(){
    string operacaoDesejada;

    cout << localAtualUsuarios;
    while (operacaoDesejada != "voltar")
    {
        cout << "o que deseja fazer?\n";
        cout << "Voce pode:\n";
        cout << "1. Cadastrar um novo usuário \n";
        cout << "2. Mostrar todos os usuários \n";
        cout << "3. Buscar usuário \n";
        cout << "4. Definir um usuário como inativo \n";

        cin >> operacaoDesejada;
    }
}