#include <iostream>
#include <cstdio>       // Para usar o fflush Link: http://www.cplusplus.com/reference/cstdio/fflush/
#include <string>       // Para usar o getline Link: http://www.cplusplus.com/reference/string/string/getline/
#include <cstdlib>      // Só para usar a função system("cls"), "cls" no windows.
using namespace std;

struct no {
    //int info;  // Não foi usado para fazer o trabalho de editor de texto
    string texto;
    struct no *prox, *ant;
};
typedef struct no * noPtr;

bool listaVazia(noPtr i) {
    if (i) {
        return false;
    }
    else {
        return true;
    }
}

void insere_texto(noPtr *i, noPtr *a, string t, int linfo, int linha){
    noPtr aux, ant, p = new no;
    int contl = 0;
    int dif = 0;
    p->texto = t;
    aux = *i;
    dif = linha - linfo;
    if (listaVazia(*i)) {
        *i = p;
        *a = p;
        p->ant = NULL;
        p->prox = NULL;
    }
    else {
        if (linfo == -1) { //Insere no final.
            ant = *a;
            ant->prox = p;
            p->prox = NULL;
            p->ant = ant;
            *a = p;
        }
        else if (linha == linfo && linfo != -1 ) { //Insere no final.
            ant = *a;
            ant->prox = p;
            p->prox = NULL;
            p->ant = ant;
            *a = p;
        }
        else if (linfo == 0) { //Insere no Início)
            aux->ant = p;
            p->prox = aux;
            p->ant = NULL;
            *i = p;
        }
        else if (linfo < linha && linfo != -1 ){ //Insere final.
            if (linha == 2) {
                aux->prox = p;
                p->prox = NULL;
                p->ant = ant;
                *a = p;
            }
            else if (dif == 2 && linha == 3) { //flinfo == 1 quando linha == 3. Insere entre.
                ant = aux;
                aux = aux->prox;
                p->prox = aux;
                p->ant = ant;
                ant->prox = p;
                aux->ant = p;
            }
            else if (dif >= 2 && linha >= 4) { //Insere entre.
                while (contl < linfo){
                    ant = aux;
                    aux = aux->prox;
                    contl++;
                }
                p->prox = aux;
                p->ant = ant;
                ant->prox = p;
                aux->ant = p;
            }
            else if (dif == 1 && linha == 3 ) { //Insere no final.
                ant = aux->prox;
                p->prox = NULL;
                p->ant = aux->prox;
                ant->prox = p;
            }
            else if (dif == 1 && linha > 3 ) { //Insere no final.
                while(aux->prox != NULL) {
                    ant = aux;
                    aux = aux->prox;
                }
                ant = aux;
                p->prox = NULL;
                p->ant = ant;
                ant->prox = p;
                *a = p;
            }
        }
        else { //Insere no final.
                ant = *a;
                ant->prox = p;
                p->prox = NULL;
                p->ant = ant;
                *a = p;
        }
    }
    cout << '\n' << "Texto foi inserido !!!!" << '\n';
}

void remover_texto(noPtr *i, noPtr *a, int linfo, int linha){
    noPtr del, ant, aux, aux1;
    int contl = 1;
    int dif = 0;
    aux = *i;
    dif = linha - linfo;
    if (linfo == 1 && linha == 1 ) {
        *i = NULL;
    }
    else if(linfo == 1 && linha == 2) {
        aux = aux->prox;
        aux->prox = NULL;
        aux->ant = NULL;
        *i = aux;
        *a = aux;
    }
    else if (dif == 1) {
        while(aux->prox != NULL) {
            ant = aux;
            aux = aux->prox;
        }
        aux1 = ant->ant;
        aux1->prox = aux;
        del = ant;
        aux->ant = aux1;
        delete(del);
    }
    else if (linfo == linha && linha > 2 ) {
        while(aux->prox != NULL) {
            ant = aux;
            aux = aux->prox;
        }
        del = aux;
        ant->prox = NULL;
        *a = ant;
        delete(del);
    }
    else if (dif > 1) {
        while (contl < linfo){
            ant = aux;
            aux = aux->prox;
            contl++;
        }
        del = aux;
        ant->prox = aux->prox;
        aux->ant = ant;
        delete(del);
    }
    cout << '\n' << "Linha: " << linfo << " Removida !!!! \n";
}

void duplicar_linha(noPtr *i, noPtr *a, int linfo, int linha, int lndp) {
    noPtr aux, ant, p = new no;
    int contl = 1;
    int dif = 0;
    aux = *i;
    dif = linha - linfo;
    if (linha == 1) {
        p->texto = aux->texto;
        aux->prox = p;
        p->prox = NULL;
        ant = aux;
        p->ant = ant;
        *a = p;
    }
    else if (linha == 2) {
        if (linfo >= lndp) {
            p->texto = aux->texto;
            aux->prox = p;
            p->prox = NULL;
            p->ant = ant;
            *a = p;
        }
        else if (linfo < lndp && linfo != 0) {
            ant = aux;
            aux = aux->prox;
            p->texto = aux->texto;
            p->prox = aux;
            p->ant = ant;
            ant->prox = p;
            aux->ant = p;
        }
    }
    else if (dif <= 0) {
        while(aux->prox != NULL) {
            ant = aux;
            aux = aux->prox;
        }
        p->texto = aux->texto;
        p->prox = NULL;
        p->ant = aux;
        aux->prox = p;
        *a = p;
    }
    else if (dif >= 1) {
        while (contl < lndp){
            ant = aux;
            aux = aux->prox;
            contl++;
        }
        p->texto = aux->texto;
        contl = 0;
        aux = *i;
        while (contl < linfo){
            ant = aux;
            aux = aux->prox;
            contl++;
        }
        p->prox = aux;
        p->ant = ant;
        ant->prox = p;
        aux->ant = p;
    }
    else {
        cout << "Nao faz sentido escolha novamente!!";
    }
    cout << '\n' << "Linha: " << lndp << " Foi Duplicada apos a linha: "
         << linfo << '\n';
}

void listarParagrafo(noPtr i) {
    if( !listaVazia(i) ) {
         if (i != NULL){
            cout << "\t" << i->texto << '\n';
            listarParagrafo(i->prox);
         }
    }
}

int menu() {
    int opcao;
        cout << "\n\n" << "---- Menu Editor de Texto ----" << "\n\n"
             << '\n' << "(1) Modo Insercao"
             << '\n' << "(2) Modo Exclusao"
             << '\n' << "(3) Modo Duplicar Linha"
             << '\n' << "(4) Modo Impressao"
             << '\n' << "(0) ou Qualquer letra: Sair"
             << "\n\n" << "Digite uma opcao: ";
        cin >> opcao;
        system("cls");
        return opcao;
}

int main() {
	int op, x;
	int linhainfo, lndupl;  // Informa a linha que o usuário escolheu do texto e linha a ser duplicada.
	int linha = 0;  // Informa o quantitativo de linha do texto.
	string text;
	char test;      // Para dar escolha ao usuário se ele quer ou não informar a linha.
	bool veri;
	noPtr inicio = NULL, atual = NULL; // atual usei para idicar o fim da lista.
	do {
        cout << "\n\n"<< " O texto contem: " << linha << " Linha(s)." << "\n\n";
		op = menu();
		switch(op) {
			case 1: // Modo Insercao
                    linha++;
                    cout << "\n\n" << "---- Menu Modo Insercao ---" << "\n\n"
                         << "O texto sera adicionado apos a linha informada. "
                         << "Caso nao queira infomar a linha, o texto sera inserindo no final. "
                         << "Caso queria adicionar no inicio informe o numero de Linha = 0. \n"
                         << "Deseja informar a linha? (s/n): ";
                    cin >> test;
                        if (test == 's') {
                            cout << '\n' << "Digite o numero da linha: ";
                            cin >> linhainfo;
                        }
                        else {
                            linhainfo = -1;
                        }
                    cout << '\n' << "Digite o texto que voce deseja inserir: ";
                    fflush(stdin);
                    getline(cin, text);
                    insere_texto(&inicio, &atual, text, linhainfo, linha);
                    break;
            case 2: //Modo Exclução
                    veri = listaVazia(inicio);
                    if (veri == true) {
                        cout << "Lista Vazia" << '\n';
                    }
                    else {
                        cout << "\n\n" << "---- Menu Modo Exclucao ---" << "\n\n"
                             << "Digita a Linha a ser excluida:  ";
                        cin >> linhainfo;
                        if (linhainfo > linha || linhainfo <= 0){
                            cout << '\n' <<"Linha Informada nao foi preenchida";
                        }
                        else {
                            remover_texto(&inicio, &atual, linhainfo, linha);
                            linha--;
                        }
                    }
                    break;
            case 3: // Modo Duplicação
                    veri = listaVazia(inicio);
                    if (veri == true) {
                        cout << "Lista Vazia" << '\n';
                    }
                    else {
                        cout << "\n\n" << "---- Menu Modo Duplicar linha ---" << "\n\n"
                             << "Informe a linha que queira duplicar: ";
                        cin >> lndupl;
                        cout << "\n" << "Escolha aonde queira adcionar a linha duplicada, "
                             << "informando a linha. Sera inserida apos a linha escolhida." << "\n\n"
                             << "Linha: ";
                        cin >> linhainfo;
                        duplicar_linha(&inicio, &atual, linhainfo, linha, lndupl);
                        linha++;
                    }
                    break;
            case 4:
                    veri = listaVazia(inicio);
                    if (veri == true) {
                        cout << "Lista Vazia" << '\n';
                    }
                    else {
                        cout << '\n' << "Os elementos da lista sao: "
                             << "\n\n" << "inicio: "<< '\n';
                        listarParagrafo(inicio);
                    }
                    break;

			default:
                    if (op == 0) {
                        cout << '\n' << "Saindo" << '\n';
                    }
                    else { system("cls");
                        cout << '\n' << "O numero digitado nao corresponde as opcoes." << '\n';
                    }
		}
    } while (op != 0);
    return 0;
}
