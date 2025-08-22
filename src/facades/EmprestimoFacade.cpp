#include "facades/EmprestimoFacade.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

EmprestimoFacade::EmprestimoFacade(UsuarioFacade& usuarios, LivroFacade& livros)
    : usuarioFacade(usuarios), livroFacade(livros), repository() {}

std::vector<Emprestimo> EmprestimoFacade::listarTodos() const { return repository.findAll(); }
std::vector<Emprestimo> EmprestimoFacade::listarAtivos() const { return repository.findAtivos(); }
std::vector<Emprestimo> EmprestimoFacade::listarPorUsuario(int usuarioId, bool apenasAtivos) const {
    return repository.findByUsuario(usuarioId, apenasAtivos);
}
std::optional<Emprestimo> EmprestimoFacade::buscarPorId(int id) const { return repository.findById(id); }

int EmprestimoFacade::registrarEmprestimo(int usuarioId, const std::string& isbn, const std::string& dataDevolucaoPrevista) {
    // 1) valida usuário
    auto u = usuarioFacade.buscarPorId(usuarioId);
    if (!u || !u->isAtivo()) return -1;

    // 2) valida livro e estoque
    auto l = livroFacade.buscarPorIsbn(isbn);
    if (!l) return -1;
    if (l->getQuantidadeDisponivel() <= 0) return -1;

    // 3) decrementa estoque do livro
    auto livro = *l;
    livro.setQuantidadeDisponivel(livro.getQuantidadeDisponivel() - 1);
    if (!livroFacade.atualizarLivro(isbn, livro)) return -1;

    // 4) registra empréstimo
    Emprestimo novo{
        0, usuarioId, isbn, hojeYYYYMMDD(), dataDevolucaoPrevista, "", true
    };
    auto salvo = repository.add(novo);
    return salvo.getId();
}

bool EmprestimoFacade::registrarDevolucao(int emprestimoId, const std::string& dataDevolucaoReal) {
    // 1) acha o empréstimo
    auto e = repository.findById(emprestimoId);
    if (!e || !e->isAtivo()) return false;

    // 2) incrementa estoque do livro
    auto l = livroFacade.buscarPorIsbn(e->getIsbn());
    if (!l) return false; // livro sumiu? inconsistente
    auto livro = *l;
    livro.setQuantidadeDisponivel(livro.getQuantidadeDisponivel() + 1);
    if (!livroFacade.atualizarLivro(e->getIsbn(), livro)) return false;

    // 3) marca devolvido
    return repository.marcarDevolvido(emprestimoId, dataDevolucaoReal);
}

std::string EmprestimoFacade::hojeYYYYMMDD() {
    using namespace std::chrono;
    auto now = system_clock::now();
    std::time_t t = system_clock::to_time_t(now);
    std::tm tm{};
#if defined(_WIN32)
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");
    return oss.str();
}
