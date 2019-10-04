/** @file Idioma.hh
 *  @brief Especificación de la clase Idioma
 */

#ifndef IDIOMA_HH
#define IDIOMA_HH

#include "Treecode.hh"
/*
 * Clase Idioma
 */

/**
 * @class Idioma
 * @brief Representa un Idioma on es fan varies operacions
 */
class Idioma {


private:
    
/** @brief Mapa d'una taula de freqüències. 

      Ordenat alfabèticament */ 
    Taula t;
    
    /** @brief Treecode. 

      Ordenat creixentment i alfabèticament */
    Treecode b;

public:
    
    //Constructora
    
    /** @brief Constructora per defecte
     * @pre: Cert
     * @post: El resultat es un idioma buit
     */
    Idioma();
    
    //Destructora
   
    /** @brief Destructora per defecte
     * @pre Cert
     * @post Esbrorra un idioma
     */
    ~Idioma();
    
    //Modificadores

    /** @brief Modificadora de la taula de freqüències
     * @pre Cert
     * @post El resultat es un idioma amb una taula resultat de la suma de la seva anterior taula de freqüències més la del idioma del canal d'entrada 
     */
    void sumar_taula();
    
    //Traductores
    
    /** @brief Codificadora de textos
     * @pre Cert
     * @post El resultat es la codificació del text si s es true i el primer caràcter que ha fallat si s es fals i no es pot codificar en l'idioma
     */
    void codifica(string& text, bool& s);
    
    /** @brief Decodificadora de textos
     * @pre Cert
     * @post El resultat es la decodificació del text si s es true i la posició de l'últim caràcter que s'ha pogut decodificar si s es fals i no es pot decodificar en l'idioma
     */
    void decodifica(string& text, bool& s, int& i);
    
    //Consultores
    
    /** @brief Consultora de codis
     * @pre Cert
     * @post Retorna true si l'string pertany a als codis, altre cas retorna false 
     */
    bool pertany_codis(string t) const;
    
    //Lectura i escriptura
    
    /** @brief Lectora de taula de freqüències
     * @pre Cert
     * @post El resultat es un idioma amb una taula de freqüències de mida p
     */
    void llegir_taula();
    
    /** @brief Obté el treecode i els codis d'un idioma
     * @pre Cert
     * @post El resultat es un idioma amb treecode i codis
     */
    void obtenir();
    
    /** @brief Escriptora de la taula de freqüències
     * @pre Cert
     * @post El resultat es la taula de frqencies a la sortida de la consola
     */
    void escriure_taula ();

    /** @brief Escriptora del treecode
     * @pre Cert
     * @post El resultat es el treecode en preorde i inordre a la sortida de la consola
     */
    void escriure_treecode () const;

    /** @brief Escriptora del tots els codis
     * @pre Cert
     * @post El resultat son tots els codis d'un idioma a la sortida de la consola
     */
    void escriure_codis () const;

    /** @brief Escriptora d'un codi
     * @pre Cert
     * @post El resultat es el codi amb el string igual a t a la sortida de la consola
     */
    void escriure_codi(string t) const;
    
};

#endif
