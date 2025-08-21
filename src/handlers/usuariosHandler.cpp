#include "../handlers/usuariosHandler.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>

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
    "3. Buscar um usuário (por ID)",
    "4. Inativar um usuário",
    "5. Atualizar dados de um usuário"
};

int handleUsuarios(UsuarioFacade& facade){
    cout << MENSAGEM_LOCAL_ATUAL_USUARIOS;
    for (const auto& op : OPCOES_SUB_MENU_USUARIOS) cout << op << "\n";
    cout << "0. Voltar\n99. Sair\n";

    while (true){
        cout << "\nEscolha: ";
        int opc = leiaOpcaoInt();

        switch (opc){
            case 0:  return 0;
            case 99: return 99;

            case 1: { // cadastrar
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string nome, email;
                cout << "Nome: ";  getline(cin, nome);
                cout << "Email: "; getline(cin, email);
                facade.cadastrarUsuario(nome, email);
                cout << "Usuário cadastrado!\n";
                break;
            }

            case 2: { // listar
                auto lista = facade.listarUsuarios();
                if (lista.empty()){ cout << "Nenhum usuário cadastrado.\n"; break; }
                cout << "=== Usuários ===\n";
                for (const auto& u : lista){
                    cout << "#"<< u.getId() 
                         << " | " << u.getNome()
                         << " | " << u.getEmail()
                         << " | " << (u.isAtivo() ? "Ativo" : "Inativo")
                         << "\n";
                }
                break;
            }

            case 3: { // buscar por ID
                cout << "ID: ";
                int id = leiaOpcaoInt();
                auto u = facade.buscarPorId(id);
                if (u){
                    cout << "#"<< u->getId() 
                         << " | " << u->getNome()
                         << " | " << u->getEmail()
                         << " | " << (u->isAtivo() ? "Ativo" : "Inativo")
                         << "\n";
                } else {
                    cout << "Não encontrado.\n";
                }
                break;
            }

            case 4: { // inativar
                cout << "ID a inativar: ";
                int id = leiaOpcaoInt();
                bool ok = facade.inativarUsuario(id);
                cout << (ok ? "Usuário inativado.\n" : "ID não encontrado.\n");
                break;
            }

            case 5: { // atualizar
                cout << "ID a atualizar: ";
                int id = leiaOpcaoInt();
                auto u = facade.buscarPorId(id);
                if (!u){ cout << "ID não encontrado.\n"; break; }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string nome = u->getNome();
                string email = u->getEmail();
                bool ativo = u->isAtivo();

                string tmp;
                cout << "Novo nome (Enter mantém \"" << nome << "\"): ";
                getline(cin, tmp); if (!tmp.empty()) nome = tmp;

                cout << "Novo email (Enter mantém \"" << email << "\"): ";
                getline(cin, tmp); if (!tmp.empty()) email = tmp;

                cout << "Ativo? (1=sim, 0=não, Enter mantém " << (ativo?1:0) << "): ";
                getline(cin, tmp);
                if (!tmp.empty()) {
                    if (tmp == "1") ativo = true;
                    else if (tmp == "0") ativo = false;
                }

                bool ok = facade.atualizarUsuario(id, nome, email, ativo);
                cout << (ok ? "Atualizado!\n" : "Falha ao atualizar (email já utilizado?).\n");
                break;
            }

            default:
                cout << "Opção inválida.\n";
        }
    }
}
