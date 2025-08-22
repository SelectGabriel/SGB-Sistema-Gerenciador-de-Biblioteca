#ifndef EMPRESTIMOREPOSITORY_H
#define EMPRESTIMOREPOSITORY_H
#pragma once

#include <vector>
#include <optional>
#include "classes/Emprestimo.h"

class EmprestimoRepository {
public:
    EmprestimoRepository();
    ~EmprestimoRepository() = default;

    const std::vector<Emprestimo>& findAll() const noexcept;
    std::optional<Emprestimo> findById(int id) const;

    std::vector<Emprestimo> findAtivos() const;
    std::vector<Emprestimo> findByUsuario(int usuarioId, bool apenasAtivos) const;

    // escrita
    Emprestimo add(Emprestimo e);         // gera id
    bool marcarDevolvido(int id, const std::string& dataDevolucaoReal);

private:
    std::vector<Emprestimo> emprestimos;
    int nextId;
};

#endif
