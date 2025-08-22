#include "livrosHandler.h"
#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include <limits>

using namespace std;

static inline int leiaOpcao() {
    std::string s;
    if (!(std::cin >> s)) return -1;
    if (s == "sair")   return 99;
    if (s == "voltar") return 0;
    try { return std::stoi(s); } catch (...) { return -1; }
}

static const string MENSAGEM_LOCAL_ATUAL_LIVROS = "Você está no gerenciamento de Livros \n";
static const vector<string> OPCOES_SUB_MENU_LIVROS = {
    "1. Adicionar novo livro",
    "2. Mostrar todos os livros",
    "3. Buscar livro (por ISBN)",
    "4. Atualizar informações de um livro",
    "5. Definir um livro como não disponível"
};

int handleLivros(LivroFacade& facade){
    cout << MENSAGEM_LOCAL_ATUAL_LIVROS;
    for (const auto& op : OPCOES_SUB_MENU_LIVROS) cout << op << "\n";
    cout << "0. Voltar\n";
    cout << "99. Sair\n";

    while (true){
        cout << "\nEscolha: ";
        int opc = leiaOpcao();

        switch (opc){
            case 0:  return 0;   // voltar
            case 99: return 99;  // sair

            case 1: { // Adicionar novo livro
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string titulo, autor, isbn, ano;
                int qtd;
                cout << "Título: "; getline(cin, titulo);
                cout << "Autor: "; getline(cin, autor);
                cout << "ISBN: "; getline(cin, isbn);
                cout << "Ano de publicação: "; getline(cin, ano);
                cout << "Quantidade disponível: "; cin >> qtd;
                facade.adicionarLivro(Livro{titulo, autor, isbn, ano, qtd});
                cout << "Livro adicionado!\n";
                break;
            }

            case 2: { // Mostrar todos
                auto lista = facade.listarLivros();
                if (lista.empty()){ cout << "Nenhum livro cadastrado.\n"; break; }
                cout << "=== Livros ===\n";
                for (const auto& l : lista){
                    cout << "- " << l.getTitulo() 
                         << " | " << l.getAutor()
                         << " | ISBN: " << l.getIsbn()
                         << " | Ano: " << l.getAnoDePublicacao()
                         << " | Qtd: " << l.getQuantidadeDisponivel()
                         << "\n";
                }
                break;
            }

            case 3: { // Buscar livro (por ISBN)
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Buscar por ISBN: ";
                string isbn; getline(cin, isbn);
                auto achado = facade.buscarPorIsbn(isbn);
                if (achado){
                    cout << achado->getTitulo() << " | " << achado->getAutor()
                         << " | Ano: " << achado->getAnoDePublicacao()
                         << " | Qtd: " << achado->getQuantidadeDisponivel() << "\n";
                } else {
                    cout << "Não encontrado.\n";
                }
                break;
            }

            case 4: { // Atualizar informações
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string isbn;
                cout << "ISBN do livro a atualizar: ";
                getline(cin, isbn);

                auto atual = facade.buscarPorIsbn(isbn);
                if (!atual){ cout << "ISBN não encontrado.\n"; break; }

                string titulo = atual->getTitulo();
                string autor  = atual->getAutor();
                string ano    = atual->getAnoDePublicacao();
                int qtd       = atual->getQuantidadeDisponivel();

                string tmp;
                cout << "Novo título (Enter mantém \"" << titulo << "\"): ";
                getline(cin, tmp); if (!tmp.empty()) titulo = tmp;

                cout << "Novo autor (Enter mantém \"" << autor << "\"): ";
                getline(cin, tmp); if (!tmp.empty()) autor = tmp;

                cout << "Novo ano (Enter mantém \"" << ano << "\"): ";
                getline(cin, tmp); if (!tmp.empty()) ano = tmp;

                cout << "Nova quantidade (Enter mantém " << qtd << "): ";
                getline(cin, tmp);
                if (!tmp.empty()) {
                    try { qtd = stoi(tmp); } catch (...) {/* mantém valor antigo */}
                }

                bool ok = facade.atualizarLivro(isbn, Livro{titulo, autor, isbn, ano, qtd});
                cout << (ok ? "Atualizado!\n" : "Falha ao atualizar.\n");
                break;
            }

            case 5: { // Definir como não disponível (qtd = 0)
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ISBN do livro: ";
                string isbn; getline(cin, isbn);

                auto achado = facade.buscarPorIsbn(isbn);
                if (!achado){ cout << "ISBN não encontrado.\n"; break; }

                Livro novo = *achado;
                novo.setQuantidadeDisponivel(0);
                bool ok = facade.atualizarLivro(isbn, novo);
                cout << (ok ? "Livro marcado como indisponível.\n" : "Falha ao atualizar.\n");
                break;
            }

            default:
                cout << "Opção inválida.\n";
        }
    }
}