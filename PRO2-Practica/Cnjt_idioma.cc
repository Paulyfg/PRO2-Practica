/** @file Cnjt_idioma.cc
    @brief Código de la clase Cnjt_idioma
*/

#include "Cnjt_idioma.hh"

Cnjt_idioma::Cnjt_idioma() {}

Cnjt_idioma::~Cnjt_idioma() {}

void Cnjt_idioma::modificar_idioma(string nom) {
    map<string, Idioma>::iterator it = conjt_idiomas.find(nom);
    (*it).second.sumar_taula();
    (*it).second.obtenir();
}

void Cnjt_idioma::afegir_idioma(string nom) {
    Idioma idiom;
    idiom.llegir_taula();
    idiom.obtenir();
    /**taula t
    t.llegir_taula();
    idiom.obtenir(t);*/
    conjt_idiomas.insert(make_pair(nom, idiom));
}

bool Cnjt_idioma::existeix_idioma(string nom) {
    map<string, Idioma>::const_iterator it = conjt_idiomas.find(nom);
    if (it != conjt_idiomas.end()) return true;
    return false;
}

Idioma& Cnjt_idioma::consultar_idioma(string nom) {
    map<string, Idioma>::iterator it = conjt_idiomas.find(nom);
    return (*it).second;
}

/*bool escriure_treecode(const string& nom) const {
    map<string,Idioma>::const_iterator it = conjt_idiomas.find(nom);
    if (it == conjt_idiomas.end()) return false; 
    else {
        it->escriure_treecode();
        return true;
    }
}*/

void Cnjt_idioma::llegir (int n) {
    for (int i = 0; i < n; ++i) {
        string nom;
        cin >> nom; 
        Idioma idiom;
        idiom.llegir_taula();
        idiom.obtenir();
        /**Taula t
        t.llegir_taula();
        idiom.obtenir(t);*/
        
        conjt_idiomas.insert(make_pair(nom, idiom));
    }
}
