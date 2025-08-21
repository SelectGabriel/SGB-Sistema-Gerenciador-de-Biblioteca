#ifndef LIVRO_H
#define LIVRO_H

#include <string>

class Livro {
private:
    std::string titulo;
    std::string autor;
    std::string isbn;
    std::string anoDePublicacao;
    int quantidadeDisponivel;

public:
    Livro(std::string titulo, std::string autor, std::string isbn,
         std::string anoDePublicacao, int quantidadeDisponivel);

    Livro();

    std::string getTitulo() const;
    std::string getAutor() const;
    std::string getIsbn() const;
    std::string getAnoDePublicacao() const;
    int getQuantidadeDisponivel() const;

    void setTitulo(const std::string& titulo);
    void setAutor(const std::string& autor);
    void setIsbn(const std::string& isbn);
    void setAnoDePublicacao(const std::string& anoDePublicacao);
    void setQuantidadeDisponivel(int quantidadeDisponivel);
};

#endif