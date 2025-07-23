#ifndef LIVROSCONTROLLER_H
#define LIVROSCONTROLLER_H

#include <../services/LivrosService.h>
#include <../classes/Livro.h>

#include <string>
#include <vector>

#pragma once

class LivrosController
{
private:
    LivrosService livroService;
    int tamanhoDaPagina;
public:
    LivrosController(LivrosService service, int tamanho) : livroService(service), tamanhoDaPagina(tamanho){};
    ~LivrosController();

    std::vector<Livro> buscarTodosOsLivros(int pagina);
    std::vector<Livro> buscarLivrosFiltrados(int pagina, std::string titulo, std::string isbn);
    Livro editarLivro(Livro livro);
    Livro removerLivro(std::string isbn);
    std::string buscarDisponibilidadeDoLivro(std::string isbn);

};

#endif