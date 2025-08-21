#include "facades/UsuarioFacade.h"

UsuarioFacade::UsuarioFacade() : repository() {}

std::vector<Usuario> UsuarioFacade::listarUsuarios() const {
    return repository.findAll();
}

std::optional<Usuario> UsuarioFacade::buscarPorId(int id) const {
    return repository.findById(id);
}

std::optional<Usuario> UsuarioFacade::buscarPorEmail(const std::string& email) const {
    return repository.findByEmail(email);
}

void UsuarioFacade::cadastrarUsuario(const std::string& nome, const std::string& email) {
    repository.add(Usuario{0, nome, email, true});
}

bool UsuarioFacade::atualizarUsuario(int id, const std::string& nome, const std::string& email, bool ativo) {
    return repository.updateById(id, Usuario{id, nome, email, ativo});
}

bool UsuarioFacade::inativarUsuario(int id) {
    return repository.inativarById(id);
}
