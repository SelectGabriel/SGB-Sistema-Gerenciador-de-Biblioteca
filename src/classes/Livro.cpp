#include "Livro.h" 
#include <string> 

Livro::Livro() {
    
}

Livro::Livro(std::string titulo, std::string autor, std::string isbn,
             std::string anoDePublicacao, int quantidadeDisponivel)
    : titulo(std::move(titulo)),
      autor(std::move(autor)),
      isbn(std::move(isbn)),
      anoDePublicacao(std::move(anoDePublicacao)),
      quantidadeDisponivel(quantidadeDisponivel) {}

std::string Livro::getTitulo() const
{
    return this->titulo;
}

std::string Livro::getAutor() const {
    return this->autor;
}

std::string Livro::getIsbn() const {
    return this->isbn;
}

std::string Livro::getAnoDePublicacao() const {
    return this->anoDePublicacao;
}

int Livro::getQuantidadeDisponivel() const {
    return this->quantidadeDisponivel;
}


void Livro::setTitulo(const std::string& titulo) {
    this->titulo = titulo;
}

void Livro::setAutor(const std::string& autor) {
    this->autor = autor;
}

void Livro::setIsbn(const std::string& isbn) {
    this->isbn = isbn;
}

void Livro::setAnoDePublicacao(const std::string& anoDePublicacao) {
    this->anoDePublicacao = anoDePublicacao;
}

void Livro::setQuantidadeDisponivel(int quantidadeDisponivel) {
    this->quantidadeDisponivel = quantidadeDisponivel;
}