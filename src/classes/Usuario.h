#ifndef USUARIO_H
#define USUARIO_H
#pragma once

#include <string>

class Usuario {
private:
    int id;                 // identificador simples (em memória)
    std::string nome;
    std::string email;
    bool ativo;

public:
    Usuario();
    Usuario(int id, std::string nome, std::string email, bool ativo = true);

    int getId() const;
    const std::string& getNome() const;
    const std::string& getEmail() const;
    bool isAtivo() const;

    void setId(int id);
    void setNome(const std::string& nome);
    void setEmail(const std::string& email);
    void setAtivo(bool ativo);
};

#endif
