#include <iostream>
#include <list>
#include <string>
using namespace std;

//mensagens
const string MENSAGEM_LOCAL_ATUAL_LIVROS = "Você está no gerenciamento de Livros \n";
const string MENSAGEM_LOCAL_ATUAL_EMPRESTIMOS = "Você está no gerenciamento de Emprestimos \n";
const string MENSAGEM_LOCAL_ATUAL_USUARIOS = "Você está no gerenciamento de usuários \n";
const string MENSAGEM_ADEUS = "Até logo! \n";

//opções dos menus
list<string> OPCOES_SUB_MENU_LIVROS = {
    "1. Adicionar novo livro",
    "2. Mostrar todos os livros",
    "3. Buscar livro",
    "4. Atualizar informações de um livro",
    "5. Definir um livro como não disponível"
};

list<string> OPCOES_SUB_MENU_EMPRESTIMOS = {
    "1. Registrar um empréstimo",
    "2. Registrar uma devolução",
    "3. Mostrar todos os livros emprestados de uma pessoa",
    "4. Mostrar todos os empréstimos ativos",
};

list<string> OPCOES_SUB_MENU_USUARIOS = {
    "1. Cadastrar um novo usuário",
    "2. Mostrar todos os usuários",
    "3. Buscar um usuário",
    "4. Inativar um usuário",
};

//structs
struct subMenuStruct{
    int identificador;
    string mensagem;
    list<string> opcoes;
};

//funcoes
void exibirMensagemMenu();
int iniciarSubmenu(string subMenu);
subMenuStruct carregarSubMenu(string subMenu);

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
    subMenuStruct subMenuCarregado;

    subMenuCarregado = carregarSubMenu(subMenu);
    cout << subMenuCarregado.mensagem;
    while (operacaoDesejada != "voltar" && operacaoDesejada != "sair")
    {
        cout << "o que deseja fazer?\n";
        cout << "Voce pode:\n";
        for (string car : subMenuCarregado.opcoes) {
            cout << car << "\n";
        }
        cout << "Voltar. ao menu anterior \n";
        cout << "Sair. do sistema \n";

        cin >> operacaoDesejada;
    }

    if (operacaoDesejada == "sair"){
        return 99;
    }
    return 0;
}

subMenuStruct carregarSubMenu(string subMenu){
    subMenuStruct subMenuCarregado; 

    if (subMenu == "1"){
        subMenuCarregado.identificador = 1;
        subMenuCarregado.mensagem = MENSAGEM_LOCAL_ATUAL_LIVROS;
        subMenuCarregado.opcoes = OPCOES_SUB_MENU_LIVROS;
        return subMenuCarregado;
    }
    if (subMenu == "2"){
        subMenuCarregado.identificador = 2;
        subMenuCarregado.mensagem = MENSAGEM_LOCAL_ATUAL_EMPRESTIMOS;
        subMenuCarregado.opcoes = OPCOES_SUB_MENU_EMPRESTIMOS;
        return subMenuCarregado;
    }
    if (subMenu == "3"){
        subMenuCarregado.identificador = 3;
        subMenuCarregado.opcoes = OPCOES_SUB_MENU_USUARIOS;
        return subMenuCarregado;
    }
    subMenuCarregado.identificador = 99;
    return subMenuCarregado;
}

void exibirMensagemMenu(){
    cout << "************************************************ \n";
    cout << "o que deseja fazer? \n";
    cout << "************************************************ \n";
    cout << "1. Gerenciar livros \n";
    cout << "2. Gerenciar emprestimos \n";
    cout << "3. Gerenciar usuários \n";
}