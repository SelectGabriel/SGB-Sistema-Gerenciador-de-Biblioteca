#include <iostream>
#include <string>
#include "facades/LivroFacade.h"
#include "handlers/livrosHandler.h"
#include "handlers/emprestimosHandler.h"
#include "handlers/usuariosHandler.h"

using namespace std;

static inline void exibirMensagemMenu(){
    cout << "************************************************ \n";
    cout << "O que deseja fazer? \n";
    cout << "************************************************ \n";
    cout << "1. Gerenciar livros \n";
    cout << "2. Gerenciar emprestimos \n";
    cout << "3. Gerenciar usuários \n";
    cout << "************************************************ \n";
}

int main(){
    cout << "Olá, seja bem vindo ao sistema de Biblioteca! \n";
    cout << "************************************************ \n";

    LivroFacade livroFacade;
    UsuarioFacade usuarioFacade;
    EmprestimoFacade emprestimoFacade(usuarioFacade, livroFacade);

    string operacaoDesejada;
    int menuPrincipalAtual = 0;

    while (operacaoDesejada != "sair" && menuPrincipalAtual != 99){
        exibirMensagemMenu();
        cin >> operacaoDesejada;
        if (operacaoDesejada == "sair") break;

        int escolha = -1;
        try { escolha = stoi(operacaoDesejada); } catch (...) { escolha = -1; }

        switch (escolha){
            case 1:
                menuPrincipalAtual = handleLivros(livroFacade);
                break;
            case 2:
                menuPrincipalAtual = handleEmprestimos(emprestimoFacade);
                break;
            case 3:
                menuPrincipalAtual = handleUsuarios(usuarioFacade);
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
                menuPrincipalAtual = 0;
                break;
        }
    }

    cout << "Até logo! \n";
    return 0;
}