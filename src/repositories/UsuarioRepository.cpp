#include "repositories/UsuarioRepository.h"

UsuarioRepository::UsuarioRepository() : nextId(1) {
    // seeds
    usuarios.emplace_back(nextId++, "Alice", "alice@exemplo.com", true);
    usuarios.emplace_back(nextId++, "Bruno", "bruno@exemplo.com", true);
    usuarios.emplace_back(nextId++, "Carla", "carla@exemplo.com", false);
}

const std::vector<Usuario>& UsuarioRepository::findAll() const noexcept {
    return usuarios;
}

std::optional<Usuario> UsuarioRepository::findById(int id) const {
    for (const auto& u : usuarios) if (u.getId() == id) return u;
    return std::nullopt;
}

std::optional<Usuario> UsuarioRepository::findByEmail(const std::string& email) const {
    for (const auto& u : usuarios) if (u.getEmail() == email) return u;
    return std::nullopt;
}

bool UsuarioRepository::emailExiste(const std::string& email) const {
    for (const auto& u : usuarios) if (u.getEmail() == email) return true;
    return false;
}

void UsuarioRepository::add(const Usuario& usuario) {
    if (emailExiste(usuario.getEmail())) return; // evita duplicado por email
    Usuario novo = usuario;
    novo.setId(nextId++);
    usuarios.push_back(novo);
}

bool UsuarioRepository::updateById(int id, const Usuario& novoValor) {
    for (auto& u : usuarios) {
        if (u.getId() == id) {
            // checa duplicidade de email (se trocou)
            if (u.getEmail() != novoValor.getEmail() && emailExiste(novoValor.getEmail()))
                return false;
            u.setNome(novoValor.getNome());
            u.setEmail(novoValor.getEmail());
            u.setAtivo(novoValor.isAtivo());
            return true;
        }
    }
    return false;
}

bool UsuarioRepository::inativarById(int id) {
    for (auto& u : usuarios) {
        if (u.getId() == id) { u.setAtivo(false); return true; }
    }
    return false;
}
