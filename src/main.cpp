#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "classes/Livro.h"
using namespace std;

//structs
struct subMenuStruct{
    string nome;
    string mensagem;
    vector<string> opcoes;
};

//mensagens
const string MENSAGEM_LOCAL_ATUAL_LIVROS = "Você está no gerenciamento de Livros \n";
const string MENSAGEM_LOCAL_ATUAL_EMPRESTIMOS = "Você está no gerenciamento de Emprestimos \n";
const string MENSAGEM_LOCAL_ATUAL_USUARIOS = "Você está no gerenciamento de usuários \n";
const string MENSAGEM_ADEUS = "Até logo! \n";

//opções dos menus
const vector<string> OPCOES_SUB_MENU_LIVROS = {
    "1. Adicionar novo livro",
    "2. Mostrar todos os livros",
    "3. Buscar livro",
    "4. Atualizar informações de um livro",
    "5. Definir um livro como não disponível"
};
const vector<string> OPCOES_SUB_MENU_EMPRESTIMOS = {
    "1. Registrar um empréstimo",
    "2. Registrar uma devolução",
    "3. Mostrar todos os livros emprestados de uma pessoa",
    "4. Mostrar todos os empréstimos ativos",
};
const vector<string> OPCOES_SUB_MENU_USUARIOS = {
    "1. Cadastrar um novo usuário",
    "2. Mostrar todos os usuários",
    "3. Buscar um usuário",
    "4. Inativar um usuário",
};

//menus
const map<int, subMenuStruct> SUB_MENUS = {
    {1, {"Livros", MENSAGEM_LOCAL_ATUAL_LIVROS, OPCOES_SUB_MENU_LIVROS}},
    {2, {"Emprestimos", MENSAGEM_LOCAL_ATUAL_EMPRESTIMOS, OPCOES_SUB_MENU_EMPRESTIMOS}},
    {3, {"Usuarios", MENSAGEM_LOCAL_ATUAL_USUARIOS, OPCOES_SUB_MENU_USUARIOS}},
};

//funcoes
void exibirMensagemMenu();
int iniciarSubmenu(const string& subMenu);
subMenuStruct carregarSubMenu(const string& subMenu);

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

int iniciarSubmenu(const string& subMenu){
    string operacaoDesejada;
    subMenuStruct subMenuCarregado;
    Livro livro("LIVRO","1233123213","12/12/2012","132312312",0);
    //Lambda ftw
    auto message = [](subMenuStruct& subMenuCarregado,
         std::string operacaoDesejada) {
        cout << "o que deseja fazer?\n";
        cout << "voce pode:\n";
        for (const string& opcoes : subMenuCarregado.opcoes) {
            cout << opcoes << "\n";
        }
        cout << "voltar. ao menu anterior \n";
        cout << "sair. do sistema \n";
    };

    subMenuCarregado = carregarSubMenu(subMenu);
    if (subMenuCarregado.nome == ""){return 0;} //exibe as opções novamente;
    cout << subMenuCarregado.mensagem;

    message(subMenuCarregado, operacaoDesejada);

    while (operacaoDesejada != "voltar" && operacaoDesejada != "sair")
    {
        // if(operacaoDesejada == "0"){
        //     message(subMenuCarregado, operacaoDesejada);
        // }

        cin >> operacaoDesejada;
    }

    if (operacaoDesejada == "sair"){
        return 99;
    }
    return 0;
}

subMenuStruct carregarSubMenu(const string& subMenu){
    subMenuStruct subMenuCarregado; 
    int subMenuInt;
    try {
        subMenuInt = stoi(subMenu);
        return SUB_MENUS.at(subMenuInt);
    } catch (const std::invalid_argument& e) {
        subMenuCarregado = subMenuStruct{};
        return subMenuCarregado;
    } catch (const std::out_of_range& e) {
        subMenuCarregado = subMenuStruct{};
        return subMenuCarregado;
    }
}

void exibirMensagemMenu(){
    cout << "************************************************ \n";
    cout << "o que deseja fazer? \n";
    cout << "************************************************ \n";
    cout << "1. Gerenciar livros \n";
    cout << "2. Gerenciar emprestimos \n";
    cout << "3. Gerenciar usuários \n";
    cout << "************************************************ \n";
}