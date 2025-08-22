#ifndef EMPRESTIMOFACADE_H
#define EMPRESTIMOFACADE_H
#pragma once

#include <vector>
#include <optional>
#include <string>
#include "../facades/UsuarioFacade.h"
#include "../facades/LivroFacade.h"
#include "../repositories/EmprestimoRepository.h"

class EmprestimoFacade {
public:
    EmprestimoFacade(UsuarioFacade& usuarios, LivroFacade& livros);

    // consultas
    std::vector<Emprestimo> listarTodos() const;
    std::vector<Emprestimo> listarAtivos() const;
    std::vector<Emprestimo> listarPorUsuario(int usuarioId, bool apenasAtivos) const;
    std::optional<Emprestimo> buscarPorId(int id) const;

    // comandos
    // dataDevolucaoPrevista no formato "YYYY-MM-DD"
    // retorna id do empréstimo criado ou -1 em erro de validação
    int registrarEmprestimo(int usuarioId, const std::string& isbn, const std::string& dataDevolucaoPrevista);

    // registrar devolução; true se OK
    bool registrarDevolucao(int emprestimoId, const std::string& dataDevolucaoReal);

private:
    UsuarioFacade& usuarioFacade;
    LivroFacade& livroFacade;
    EmprestimoRepository repository;

    static std::string hojeYYYYMMDD(); // helper simples de data
};

#endif