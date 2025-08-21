#include "usuariosHandler.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

static inline int leiaOpcaoInt(){
    string s; 
    if (!(cin >> s)) return -1;
    try { return stoi(s); } catch (...) { return -1; }
}

static const string MENSAGEM_LOCAL_ATUAL_USUARIOS = "Você está no gerenciamento de usuários \n";
static const vector<string> OPCOES_SUB_MENU_USUARIOS = {
    "1. Cadastrar um novo usuário",
    "2. Mostrar todos os usuários",
    "3. Buscar um usuário",
    "4. Inativar um usuário",
};

int handleUsuarios(){
    cout << MENSAGEM_LOCAL_ATUAL_USUARIOS;
    for (const auto& op : OPCOES_SUB_MENU_USUARIOS) cout << op << "\n";
    cout << "0. Voltar\n99. Sair\n";
    while (true){
        cout << "\nEscolha: ";
        int opc = leiaOpcaoInt();
        if (opc == 0)  return 0;
        if (opc == 99) return 99;
        cout << "Funcionalidades de usuários ainda em desenvolvimento.\n";
    }
}