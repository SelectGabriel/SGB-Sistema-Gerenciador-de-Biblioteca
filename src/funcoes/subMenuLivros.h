#ifndef SUBMENULIVROS_H
#define SUBMENULIVROS_H

#include "../classes/Livro.h"
#include <vector>
#include <string>

void exibirTodosOsLivros(int pagina){}
void exibirLivrosFiltrados(std::string titulo, std::string isbn){}
void enviarLivroParaEdicao(Livro livroEditado){}
void enviarLivroParaRemocao(std::string isbn){}
void exibirDisponibilidadeDoLivro(std::string isbn){}

#endif