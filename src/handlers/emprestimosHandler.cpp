#include "../handlers/emprestimosHandler.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

static inline int leiaOpcao() {
    string s;
    if (!(cin >> s)) return -1;
    if (s == "sair")   return 99;
    if (s == "voltar") return 0;
    try { return stoi(s); } catch (...) { return -1; }
}

static const string MSG = "Você está no gerenciamento de Emprestimos \n";
static const vector<string> OPCOES = {
    "1. Registrar um empréstimo",
    "2. Registrar uma devolução",
    "3. Mostrar todos os livros emprestados de uma pessoa (ativos)",
    "4. Mostrar todos os empréstimos ativos",
    "5. Listar todos os empréstimos (inclui devolvidos)",
};

int handleEmprestimos(EmprestimoFacade& facade){
    cout << MSG;
    for (const auto& op : OPCOES) cout << op << "\n";
    cout << "0. Voltar\n99. Sair\n";

    while (true){
        cout << "\nEscolha: ";
        int opc = leiaOpcao();

        switch (opc){
            case 0:  return 0;
            case 99: return 99;

            case 1: { // Registrar empréstimo
                cout << "ID do usuário: ";
                int usuarioId = leiaOpcao();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                string isbn, dataPrevista;
                cout << "ISBN do livro: "; getline(cin, isbn);
                cout << "Data de devolução prevista (YYYY-MM-DD): "; getline(cin, dataPrevista);

                int id = facade.registrarEmprestimo(usuarioId, isbn, dataPrevista);
                if (id >= 0) cout << "Empréstimo registrado! ID = " << id << "\n";
                else         cout << "Falha (usuário inativo/inexistente, livro inexistente ou sem estoque).\n";
                break;
            }

            case 2: { // Registrar devolução
                cout << "ID do empréstimo: ";
                int empId = leiaOpcao();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                string dataReal;
                cout << "Data de devolução real (YYYY-MM-DD): ";
                getline(cin, dataReal);

                bool ok = facade.registrarDevolucao(empId, dataReal);
                cout << (ok ? "Devolução registrada e estoque atualizado.\n"
                            : "Falha (empréstimo inexistente/inativo).\n");
                break;
            }

            case 3: { // Por usuário (ativos)
                cout << "ID do usuário: ";
                int usuarioId = leiaOpcao();
                auto lista = facade.listarPorUsuario(usuarioId, /*apenasAtivos*/true);
                if (lista.empty()) { cout << "Nenhum empréstimo ativo para este usuário.\n"; break; }
                cout << "=== Empréstimos ativos do usuário #" << usuarioId << " ===\n";
                for (const auto& e : lista){
                    cout << "ID " << e.getId()
                         << " | ISBN " << e.getIsbn()
                         << " | Emp " << e.getDataEmprestimo()
                         << " | Prev " << e.getDataDevolucaoPrevista()
                         << "\n";
                }
                break;
            }

            case 4: { // Ativos (todos)
                auto lista = facade.listarAtivos();
                if (lista.empty()) { cout << "Nenhum empréstimo ativo.\n"; break; }
                cout << "=== Empréstimos ativos ===\n";
                for (const auto& e : lista){
                    cout << "ID " << e.getId()
                         << " | Usuário #" << e.getUsuarioId()
                         << " | ISBN " << e.getIsbn()
                         << " | Emp " << e.getDataEmprestimo()
                         << " | Prev " << e.getDataDevolucaoPrevista()
                         << "\n";
                }
                break;
            }

            case 5: { // Todos (inclui devolvidos)
                auto lista = facade.listarTodos();
                if (lista.empty()) { cout << "Nenhum empréstimo registrado.\n"; break; }
                cout << "=== Todos os empréstimos ===\n";
                for (const auto& e : lista){
                    cout << "ID " << e.getId()
                         << " | Usuário #" << e.getUsuarioId()
                         << " | ISBN " << e.getIsbn()
                         << " | Emp " << e.getDataEmprestimo()
                         << " | Prev " << e.getDataDevolucaoPrevista()
                         << " | Devol " << (e.getDataDevolucaoReal().empty() ? "-" : e.getDataDevolucaoReal())
                         << " | " << (e.isAtivo() ? "Ativo" : "Devolvido")
                         << "\n";
                }
                break;
            }

            default:
                cout << "Opção inválida.\n";
        }
    }
}
