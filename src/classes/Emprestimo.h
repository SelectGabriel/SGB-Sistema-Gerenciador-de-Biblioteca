#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H
#pragma once

#include <string>

class Emprestimo {
private:
    int id;                           // gerado no repositório
    int usuarioId;                    // referência ao usuário
    std::string isbn;                 // referência ao livro
    std::string dataEmprestimo;       // YYYY-MM-DD
    std::string dataDevolucaoPrevista;// YYYY-MM-DD
    std::string dataDevolucaoReal;    // vazio se não devolvido
    bool ativo;                       // true enquanto não devolvido

public:
    Emprestimo();
    Emprestimo(int id, int usuarioId, std::string isbn,
               std::string dataEmprestimo,
               std::string dataDevolucaoPrevista,
               std::string dataDevolucaoReal,
               bool ativo);

    int getId() const;
    int getUsuarioId() const;
    const std::string& getIsbn() const;
    const std::string& getDataEmprestimo() const;
    const std::string& getDataDevolucaoPrevista() const;
    const std::string& getDataDevolucaoReal() const;
    bool isAtivo() const;

    void setId(int v);
    void setUsuarioId(int v);
    void setIsbn(const std::string& v);
    void setDataEmprestimo(const std::string& v);
    void setDataDevolucaoPrevista(const std::string& v);
    void setDataDevolucaoReal(const std::string& v);
    void setAtivo(bool v);
};

#endif