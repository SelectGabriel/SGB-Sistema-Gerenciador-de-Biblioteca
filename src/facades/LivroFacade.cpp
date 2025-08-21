#include "LivroFacade.h"

LivroFacade::LivroFacade() : repository() {
    // já inicializa o repositório com os dados "seed"
}

std::vector<Livro> LivroFacade::listarLivros() const {
    return repository.findAll();
}

std::optional<Livro> LivroFacade::buscarPorIsbn(const std::string& isbn) const {
    return repository.findByIsbn(isbn);
}

void LivroFacade::adicionarLivro(const Livro& livro) {
    repository.add(livro);
}

bool LivroFacade::removerLivro(const std::string& isbn) {
    return repository.removeByIsbn(isbn);
}

bool LivroFacade::atualizarLivro(const std::string& isbn, const Livro& novoValor) {
    return repository.updateByIsbn(isbn, novoValor);
}