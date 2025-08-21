#include "LivroRepository.h"

// Construtor com alguns dados iniciais
LivroRepository::LivroRepository() {
    livros.emplace_back("Clean Code", "Robert C. Martin", "9780132350884", "2008", 3);
    livros.emplace_back("O Senhor dos Anéis", "J.R.R. Tolkien", "9780261102385", "1954", 2);
    livros.emplace_back("Dom Casmurro", "Machado de Assis", "9788520933120", "1899", 5);
}

const std::vector<Livro>& LivroRepository::findAll() const noexcept {
    return livros;
}

std::optional<Livro> LivroRepository::findByIsbn(const std::string& isbn) const {
    for (const auto& l : livros) {
        if (l.getIsbn() == isbn) {
            return l;
        }
    }
    return std::nullopt;
}

void LivroRepository::add(const Livro& livro) {
    for (const auto& l : livros) {
        if (l.getIsbn() == livro.getIsbn()) {
            return; // já existe, não adiciona duplicado
        }
    }
    livros.push_back(livro);
}

bool LivroRepository::removeByIsbn(const std::string& isbn) {
    for (auto it = livros.begin(); it != livros.end(); ++it) {
        if (it->getIsbn() == isbn) {
            livros.erase(it);
            return true;
        }
    }
    return false;
}

bool LivroRepository::updateByIsbn(const std::string& isbn, const Livro& novoValor) {
    for (auto& l : livros) {
        if (l.getIsbn() == isbn) {
            l.setTitulo(novoValor.getTitulo());
            l.setAutor(novoValor.getAutor());
            l.setAnoDePublicacao(novoValor.getAnoDePublicacao());
            l.setQuantidadeDisponivel(novoValor.getQuantidadeDisponivel());
            return true;
        }
    }
    return false;
}