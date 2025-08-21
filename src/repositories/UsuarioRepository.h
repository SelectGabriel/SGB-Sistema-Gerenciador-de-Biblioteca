#ifndef USUARIOREPOSITORY_H
#define USUARIOREPOSITORY_H
#pragma once

#include <vector>
#include <optional>
#include "../classes/Usuario.h"

class UsuarioRepository {
public:
    UsuarioRepository();
    ~UsuarioRepository() = default;

    const std::vector<Usuario>& findAll() const noexcept;
    std::optional<Usuario> findById(int id) const;
    std::optional<Usuario> findByEmail(const std::string& email) const;

    // escrita
    void add(const Usuario& usuario);       // não duplica email
    bool updateById(int id, const Usuario& novoValor);
    bool inativarById(int id);              // set ativo=false

private:
    std::vector<Usuario> usuarios;
    int nextId; // autoincrement simplão em memória

    bool emailExiste(const std::string& email) const;
};

#endif
