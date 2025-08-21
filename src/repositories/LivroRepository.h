#ifndef LIVROREPOSITORY_H
#define LIVROREPOSITORY_H
#pragma once

#include <vector>
#include <optional>
#include <string>
#include "../classes/Livro.h"

class LivroRepository {
public:
    LivroRepository();
    ~LivroRepository() = default;

    // leitura
    const std::vector<Livro>& findAll() const noexcept;
    std::optional<Livro> findByIsbn(const std::string& isbn) const;

    // escrita (em memória)
    void add(const Livro& livro);
    bool removeByIsbn(const std::string& isbn);
    bool updateByIsbn(const std::string& isbn, const Livro& novoValor);

private:
    std::vector<Livro> livros;
};

#endif