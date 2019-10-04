/** @file Treecode.hh
 *  @brief Especificación de la clase Treecode
 */

#ifndef Treecode_HH
#define Treecode_HH

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <set>
#endif

#include "Taula.hh"
/*
 * Clase Treecode
 */

/**
 * @class Treecode
 * @brief Representa un Treecode on es fan varies operacions
 */
class Treecode {
    
private:
    
    /** @brief Mapa d'una taula de freqüències. 

      Ordenat alfabèticament */ 
    Taula t;
    
    /** @brief Mapa d'uns codis. 

      Ordenat alfabèticament */ 
    map<string, string> codis;
    
    /** @brief Mapa d'una Treecode de freqüències. 

      Ordenat alfabèticament */ 
    BinTree<pair<string, int> > bin;
    
    /** @brief Mapa d'un conjunt de treecodes. 

      Ordenat creixentment i alfabèticament */
    set<BinTree<pair<string, int> > > conjt_bin;
    
public:
    
    //Constructora
    
    /** @brief Constructora per defecte
     * @pre: Cert
     * @post: El resultat es una taula buida
     */
    Treecode();
    
    //Destructora
   
    /** @brief Destructora per defecte
     * @pre Cert
     * @post Esbrorra un taula buida
     */
    ~Treecode();
    
    //Modificadores
    
     /** @brief Modifica l'string per poder fer una búsqueda al treecode
     * @pre i=I < s.length() es la primera posicion de un caracter de s
     * @post out es el caracter que comienza en s[I]; si out es normal retorna true y i=I+1, si es especial retorna false y i=I+2 
     */
    void next_symbol(const string& s, int& i, string& out);
    
    //Traductores
    
    /** @brief Codificadora de textos
     * @pre Cert
     * @post El resultat es la codificació del text si s es true i el primer caràcter que ha fallat si s es fals i no es pot codificar en l'idioma
     */
    void codif(string& text, bool& s);

    /** @brief Decodificadora de textos
     * @pre Cert
     * @post El resultat es la decodificació del text si s es true i la posició de l'últim caràcter que s'ha pogut decodificar si s es fals i no es pot decodificar en l'idioma
     */
    void decodif(string& text, bool& s, int& i);
    
    //Consultores
    
    /** @brief Consultora de codis
     * @pre Cert
     * @post Retorna true si l'string pertany a als codis, altre cas retorna false 
     */
    bool pertany(string t) const;
    
    //Lectura i escriptura
    
    /** @brief Obté el treecode i els codis d'un idioma
     * @pre Cert
     * @post El resultat són un treecode i uns codis
     */
    void obtenirtc(Taula t);
    
    /** @brief Escriptora del treecode
     * @pre Cert
     * @post El resultat es el treecode en preorde i inordre
     */
    void escriuretc() const;
    
    /** @brief Escriptora del tots els codis
     * @pre Cert
     * @post El resultat son tots els codis d'un idioma
     */
    void escriurecs() const;
    
    /** @brief Escriptora d'un codi
     * @pre Cert
     * @post El resultat es el codi amb el string igual a t
     */
    void escriurec(string t) const;
    

private:
    
    /** @brief Creadora del treecode
     * @pre Cert
     * @post El resultat es el treecode de l'idioma
     */
     void obtenir_treecode(set<BinTree<pair<string, int> > >& conjt_bin);
     
     /** @brief Creadora dels codis
     * @pre Cert
     * @post El resultat són els codis de l'idioma
     */
    static void obtenir_codis(const BinTree <pair<string, int> >& bin, string cami, map<string, string>& codis);
    
    /** @brief Escriptora del treecode en preorde
     * @pre Cert
     * @post El resultat es el treecode en preorde
     */
    static void escriure_preordre(const BinTree<pair<string, int> >& bin);
    
    /** @brief Escriptora del treecode en inordre
     * @pre Cert
     * @post El resultat es el treecode en inordre
     */
    static void escriure_inordre(const BinTree<pair<string, int> >& bin);
    
    /** @brief Consulta la posible codificació en el idioma
     * @pre Cert
     * @post Retorna true i la decodificació del text si el text es por codificar en el idioma, altre cas retorna fals i la posició de l'últim caràcter que s'ha pogut decodificar
     */
    void decod(const BinTree<pair<string, int> >& b, const string& text, string& result, int& n, int& i, bool& s);    
    
};

#endif
