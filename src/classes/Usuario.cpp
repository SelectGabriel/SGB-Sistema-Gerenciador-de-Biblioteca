#include "Usuario.h"

Usuario::Usuario() : id(0), nome(""), email(""), ativo(true) {}

Usuario::Usuario(int id, std::string nome, std::string email, bool ativo)
    : id(id), nome(std::move(nome)), email(std::move(email)), ativo(ativo) {}

int Usuario::getId() const { return id; }
const std::string& Usuario::getNome() const { return nome; }
const std::string& Usuario::getEmail() const { return email; }
bool Usuario::isAtivo() const { return ativo; }

void Usuario::setId(int id) { this->id = id; }
void Usuario::setNome(const std::string& nome) { this->nome = nome; }
void Usuario::setEmail(const std::string& email) { this->email = email; }
void Usuario::setAtivo(bool ativo) { this->ativo = ativo; }
