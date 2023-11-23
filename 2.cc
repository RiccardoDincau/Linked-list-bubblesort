#include <iostream>
#include <cstdlib>

using namespace std;

struct nodo {
    int d = 0;
    nodo * p = NULL;
};

nodo * ultimo(nodo * s);
void aggiungi_fine(nodo * &s, nodo * nuovo_nodo);
void mostra_lista(nodo *s);
void aggiungi_inizio(nodo * &s, nodo * nuovo_nodo);
void bubble_sort(nodo * &l);
int find_len(nodo * l);
void elimina(nodo * &s);
void scambia_succ(nodo * &n1);

int main() {
    srand(time(NULL));
    nodo * l = NULL;
    for (int i = 0; i < 100; i ++) {
        nodo * n = new nodo {rand()%100};
        aggiungi_fine(l, n);
    }
    mostra_lista(l);

    bubble_sort(l);

    mostra_lista(l);

    elimina(l);

    return 0;
}

void aggiungi_fine(nodo * &s, nodo * nuovo_nodo) {
    if (s == NULL) {
        s = nuovo_nodo;
    } else {
        nodo * ult = ultimo(s);
        if (ult->p == NULL) {
            ult->p = nuovo_nodo;
        } else {
            ult->p->p = nuovo_nodo;
        }
    }
}

void aggiungi_inizio(nodo * &s, nodo * nuovo_nodo) {
    nodo * temp = s;
    s = nuovo_nodo;
    nuovo_nodo->p = temp;
}

nodo * ultimo(nodo * s) {
    nodo * prec = s;
    while (s->p != NULL) {
        prec = s;
        s = s->p;
    } 
    return prec;
}

void mostra_lista(nodo *s) {
    if (s == NULL) {
        cout << "Lista vuota" << endl;
        return;
    }
    while (s->p != NULL) {
        cout << s->d << " ";
        s = s->p;
    }
    cout << s->d << " " << endl;
}

void bubble_sort(nodo * &l) {
    if (l == NULL) {
        cout << "Lista vuota" << endl;
        return;
    } else if (l->p == NULL) {
        return;
    }

    int len = find_len(l);

    for (int i = 0; i < len; i++) {
        if (l->d > l->p->d) {
            scambia_succ(l);
        }

        nodo * prec = l;
        nodo * s = l->p;

        while (s->p != NULL) {
            if (s->d > s->p->d) {
                scambia_succ(prec->p);
                
                s = prec->p->p;
                prec = prec->p;
            } else {
                prec = s;
                s = s->p;
            }
        }
    }
    
    // for (int i = 0; i < len; i++) {
    //     if (l->d > l->p->d) {
    //         nodo * temp = l;
    //         l = l->p;
    //         temp->p = l->p;
    //         l->p = temp;
    //     }

    //     nodo * prec = l;
    //     nodo * s = l->p;

    //     while (s->p != NULL) {
    //         if (s->d > s->p->d) {
    //             nodo * temp = prec->p;
    //             prec->p = s->p;
    //             temp->p = s->p->p;
    //             prec->p->p = temp;
                
    //             s = prec->p->p;
    //             prec = prec->p;
    //         } else {
    //             prec = s;
    //             s = s->p;
    //         }
    //     }
    // }
}

void scambia_succ(nodo * &n1) {
    nodo * temp = n1;
    n1 = n1->p;
    temp->p = n1->p;
    n1->p = temp;
}

int find_len(nodo * l) {
    if (l == NULL) {
        cout << "Lista vuota" << endl;
        return 0;
    }
    int len = 1;
    while (l->p != NULL) {
        l = l->p;
        len++;
    }
    return len;
}

void elimina(nodo * &s) {
    while (s != NULL) {
        nodo * t = s;
        s = s->p;
        delete t;
    }
}