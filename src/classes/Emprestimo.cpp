#include "classes/Emprestimo.h"

Emprestimo::Emprestimo()
    : id(0), usuarioId(0), isbn(""),
      dataEmprestimo(""), dataDevolucaoPrevista(""),
      dataDevolucaoReal(""), ativo(true) {}

Emprestimo::Emprestimo(int id, int usuarioId, std::string isbn,
                       std::string dataEmprestimo,
                       std::string dataDevolucaoPrevista,
                       std::string dataDevolucaoReal,
                       bool ativo)
    : id(id), usuarioId(usuarioId), isbn(std::move(isbn)),
      dataEmprestimo(std::move(dataEmprestimo)),
      dataDevolucaoPrevista(std::move(dataDevolucaoPrevista)),
      dataDevolucaoReal(std::move(dataDevolucaoReal)),
      ativo(ativo) {}

int Emprestimo::getId() const { return id; }
int Emprestimo::getUsuarioId() const { return usuarioId; }
const std::string& Emprestimo::getIsbn() const { return isbn; }
const std::string& Emprestimo::getDataEmprestimo() const { return dataEmprestimo; }
const std::string& Emprestimo::getDataDevolucaoPrevista() const { return dataDevolucaoPrevista; }
const std::string& Emprestimo::getDataDevolucaoReal() const { return dataDevolucaoReal; }
bool Emprestimo::isAtivo() const { return ativo; }

void Emprestimo::setId(int v) { id = v; }
void Emprestimo::setUsuarioId(int v) { usuarioId = v; }
void Emprestimo::setIsbn(const std::string& v) { isbn = v; }
void Emprestimo::setDataEmprestimo(const std::string& v) { dataEmprestimo = v; }
void Emprestimo::setDataDevolucaoPrevista(const std::string& v) { dataDevolucaoPrevista = v; }
void Emprestimo::setDataDevolucaoReal(const std::string& v) { dataDevolucaoReal = v; }
void Emprestimo::setAtivo(bool v) { ativo = v; }