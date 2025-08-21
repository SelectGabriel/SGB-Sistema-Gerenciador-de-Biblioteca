#ifndef USUARIOFACADE_H
#define USUARIOFACADE_H
#pragma once

#include <vector>
#include <optional>
#include <string>
#include "../repositories/UsuarioRepository.h"

class UsuarioFacade {
public:
    UsuarioFacade();
    ~UsuarioFacade() = default;

    std::vector<Usuario> listarUsuarios() const;
    std::optional<Usuario> buscarPorId(int id) const;
    std::optional<Usuario> buscarPorEmail(const std::string& email) const;

    void cadastrarUsuario(const std::string& nome, const std::string& email);
    bool atualizarUsuario(int id, const std::string& nome, const std::string& email, bool ativo);
    bool inativarUsuario(int id);

private:
    UsuarioRepository repository;
};

#endif