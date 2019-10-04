/** @file Idioma.cc
    @brief Código de la clase Idioma
*/

#include "Idioma.hh"

Idioma::Idioma() {}

Idioma::~Idioma() {}

void Idioma::sumar_taula() {
    t.sumart();
}

void Idioma::codifica(string& text, bool& s) {
    b.codif(text, s);
}

void Idioma::decodifica(string& text, bool& s, int& i) {
    b.decodif(text, s, i);
}

bool Idioma::pertany_codis(string t) const {
    return b.pertany(t);
}

void Idioma::llegir_taula() {
    t.llegirt();
}


void Idioma::obtenir() {
    b.obtenirtc(t);
}

void Idioma::escriure_taula() {
    t.escriuret();
}

void Idioma::escriure_treecode () const {
    b.escriuretc();
}

void Idioma::escriure_codis () const {
    b.escriurecs();
}

void Idioma::escriure_codi(string t) const {
    b.escriurec(t);
}

