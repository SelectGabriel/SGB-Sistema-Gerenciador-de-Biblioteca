#ifndef LIVROFACADE_H
#define LIVROFACADE_H
#pragma once

#include <vector>
#include <optional>
#include <string>
#include "../classes/Livro.h"
#include "../repositories/LivroRepository.h"

class LivroFacade {
public:
    LivroFacade();
    ~LivroFacade() = default;

    // Métodos de acesso simplificados
    std::vector<Livro> listarLivros() const;
    std::optional<Livro> buscarPorIsbn(const std::string& isbn) const;
    void adicionarLivro(const Livro& livro);
    bool removerLivro(const std::string& isbn);
    bool atualizarLivro(const std::string& isbn, const Livro& novoValor);

private:
    LivroRepository repository; // composição: a facade usa o repositório
};

#endif // LIVROFACADE_H