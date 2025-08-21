#include "emprestimosHandler.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

static inline int leiaOpcaoInt(){
    string s; 
    if (!(cin >> s)) return -1;
    try { return stoi(s); } catch (...) { return -1; }
}

static const string MENSAGEM_LOCAL_ATUAL_EMPRESTIMOS = "Você está no gerenciamento de Emprestimos \n";
static const vector<string> OPCOES_SUB_MENU_EMPRESTIMOS = {
    "1. Registrar um empréstimo",
    "2. Registrar uma devolução",
    "3. Mostrar todos os livros emprestados de uma pessoa",
    "4. Mostrar todos os empréstimos ativos",
};

int handleEmprestimos(){
    cout << MENSAGEM_LOCAL_ATUAL_EMPRESTIMOS;
    for (const auto& op : OPCOES_SUB_MENU_EMPRESTIMOS) cout << op << "\n";
    cout << "0. Voltar\n99. Sair\n";
    while (true){
        cout << "\nEscolha: ";
        int opc = leiaOpcaoInt();
        if (opc == 0)  return 0;
        if (opc == 99) return 99;
        cout << "Funcionalidades de empréstimos ainda em desenvolvimento.\n";
    }
}
