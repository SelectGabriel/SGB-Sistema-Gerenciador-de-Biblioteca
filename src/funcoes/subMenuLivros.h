#ifndef SUBMENULIVROS_H
#define SUBMENULIVROS_H

#include "../classes/Livro.h"
#include <vector>
#include <string>

void exibirTodosOsLivros(int pagina){}
std::vector<Livro> pesquisarLivros(std::string titulo, std::string isbn){}
Livro editarLivro(std::string isbn, Livro livroEditado){}
void removerLivro(std::string isbn){}
std::string exibirDisponibilidadeDoLivro(std::string isbn){}

#endif