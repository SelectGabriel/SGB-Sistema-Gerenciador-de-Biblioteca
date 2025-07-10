#include <iostream>
#include <string>
using namespace std;

const string MENSAGEM_LOCAL_ATUAL_LIVROS = "Você está no gerenciamento de Livros \n";
const string MENSAGEM_LOCAL_ATUAL_EMPRESTIMOS = "Você está no gerenciamento de Emprestimos \n";
const string MENSAGEM_LOCAL_ATUAL_USUARIOS = "Você está no gerenciamento de usuários \n";
const string MENSAGEM_ADEUS = "Até logo! \n";

void exibirMensagemMenu();
int iniciarSubmenu(string subMenu);
void exibirMensagemSubMenuLivros();
void exibirMensagemSubMenuEmprestimos();
void exibirMensagemSubMenuUsuarios();

int main() {
    //Menu princiapal do gerenciador de biblioteca
    string operacaoDesejada = "";
    int menuPrincipalAtual = 0;

    cout << "Olá, seja bem vindo ao sistema de Biblioteca! \n";
    cout << "************************************************ \n";

    while (operacaoDesejada != "sair" && menuPrincipalAtual != 99){
        exibirMensagemMenu();
        cin >> operacaoDesejada;

        if (operacaoDesejada == "sair"){break;}
        menuPrincipalAtual = iniciarSubmenu(operacaoDesejada);
    }

    cout << MENSAGEM_ADEUS;
}

int iniciarSubmenu(string subMenu){
    string operacaoDesejada;

    while (operacaoDesejada != "voltar" && operacaoDesejada != "sair")
    {
        cout << "o que deseja fazer?\n";
        cout << "Voce pode:\n";
        if (subMenu == "1"){
            exibirMensagemSubMenuLivros();
        }
        if (subMenu == "2"){
            exibirMensagemSubMenuEmprestimos();
        }
        if (subMenu == "3"){
            exibirMensagemSubMenuUsuarios();
        }
        cout << "Voltar. Voltar ao menu anterior \n";
        cout << "Sair. Sair do sistema \n";

        cin >> operacaoDesejada;
    }

    if (operacaoDesejada == "sair"){
        return 99;
    }
    return 0;
}

void exibirMensagemMenu(){
    cout << "************************************************ \n";
    cout << "o que deseja fazer? \n";
    cout << "************************************************ \n";
    cout << "1. Gerenciar livros \n";
    cout << "2. Gerenciar emprestimos \n";
    cout << "3. Gerenciar usuários \n";
    cout << "Sair. Sair do sistema \n";
}

void exibirMensagemSubMenuLivros(){
    cout << "1. Adicionar novo livro \n";
    cout << "2. Listar todos os livros \n";
    cout << "3. Buscar livro \n";
    cout << "4. Atualizar informações de um livro \n";
    cout << "5. Definir um livro como não disponível \n";
}

void exibirMensagemSubMenuEmprestimos(){
    cout << "1. Registrar um empréstimo \n";
    cout << "2. Registrar uma devolução \n";
    cout << "3. Mostrar todos os livros emprestados de uma pessoa \n";
    cout << "4. Mostrar todos os empréstimos ativos \n";
}

void exibirMensagemSubMenuUsuarios(){
    cout << "1. Cadastrar um novo usuário \n";
    cout << "2. Mostrar todos os usuários \n";
    cout << "3. Buscar um usuário \n";
    cout << "4. Remover um usuário \n";
}