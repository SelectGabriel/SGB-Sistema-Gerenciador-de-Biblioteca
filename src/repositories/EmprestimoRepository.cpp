#include "repositories/EmprestimoRepository.h"

EmprestimoRepository::EmprestimoRepository() : nextId(1) {}

const std::vector<Emprestimo>& EmprestimoRepository::findAll() const noexcept {
    return emprestimos;
}

std::optional<Emprestimo> EmprestimoRepository::findById(int id) const {
    for (const auto& e : emprestimos) if (e.getId() == id) return e;
    return std::nullopt;
}

std::vector<Emprestimo> EmprestimoRepository::findAtivos() const {
    std::vector<Emprestimo> r;
    for (const auto& e : emprestimos) if (e.isAtivo()) r.push_back(e);
    return r;
}

std::vector<Emprestimo> EmprestimoRepository::findByUsuario(int usuarioId, bool apenasAtivos) const {
    std::vector<Emprestimo> r;
    for (const auto& e : emprestimos) {
        if (e.getUsuarioId() == usuarioId && (!apenasAtivos || e.isAtivo()))
            r.push_back(e);
    }
    return r;
}

Emprestimo EmprestimoRepository::add(Emprestimo e) {
    e.setId(nextId++);
    emprestimos.push_back(e);
    return e; // retorna cópia com id
}

bool EmprestimoRepository::marcarDevolvido(int id, const std::string& dataDevolucaoReal) {
    for (auto& e : emprestimos) {
        if (e.getId() == id && e.isAtivo()) {
            e.setAtivo(false);
            e.setDataDevolucaoReal(dataDevolucaoReal);
            return true;
        }
    }
    return false;
}
