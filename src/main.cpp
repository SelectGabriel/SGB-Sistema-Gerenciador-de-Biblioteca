#include <iostream>
using namespace std;

int main() {
    //Menu princiapal do gerenciador de biblioteca
    int operacaoDesejada = 0;
    int menuAtual = 0;


    cout << "Olá, seja bem vindo ao sistema de Biblioteca! \n";
    cout << "************************************************ \n";
    cout << "o que deseja fazer? \n";
    cout << "************************************************ \n";

    cout << "1. Gerenciar livros \n";
    cout << "2. Gerenciar emprestimos \n";
    cout << "3. Gerenciar usuários \n";

    cin >> operacaoDesejada;

    switch(operacaoDesejada) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        cout << "Você está no gerenciamento de usuários \n";
        menuAtual = 3;
        break;
    default:
        cout << "Desculpe, não entendi seu comando \n";
    }
    return 0;
}