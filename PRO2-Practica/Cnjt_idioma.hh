/** @file Cnjt_idioma.hh
    @brief Especificación de la clase Cnjt_idioma
*/

#ifndef CONJT_IDIOMA_HH
#define CONJT_IDIOMA_HH

#include "Idioma.hh"
/*
 * Clase Cnjt_idioma
 */

/**
 * @class Cnjt_idioma
 * @brief Representa un Cnjt_idioma on es fan varies operacions
 */
class Cnjt_idioma {

private:
    
    /** @brief Mapa d'un conjunt d'idiomes. 

    Ordenat alfabèticament */ 
    map<string, Idioma> conjt_idiomas;

public:
    
    //Constructora;
    
    /** @brief Constructora per defecte
     * @pre: Cert
     * @post: El resultat es un conjunt d'idiomes buit
     */
    Cnjt_idioma();
    
    //Destructora
    
    /** @brief Destructora per defecte
     * @pre Cert
     * @post Esbrorra un conjunt d'idiomes
     */
    ~Cnjt_idioma();
    
    //Modificadores
    
    /** @brief Afegeix un idioma
     * @pre Cert
     * @post S'ha afegit l'idioma al conjunt d'idiomes
     */
    void afegir_idioma(string nom);

    /** @brief Modifica un idioma
     * @pre Existeix un idioma el nom del cual és igual al del canal estàndar d'entrada
     * @post S'ha sumat la nova taula de freqüències amb la de l'idioma ja existent, i s'ha obtingut un nou treecode i nous codis
     */
    void modificar_idioma(string nom);
    
    //Consultores
    
    /** @brief Consultora de l'existència d'un idioma
     * @pre Cert
     * @post Si existeix un idioma el nom del cual és igual al del canal estàndar d'entrada retorna true, altre cas retorna false
     */
    bool existeix_idioma(string nom);

    /** @brief Consultora d'un idioma
     * @pre Cert
     * @post Retorna l'idioma el nom del cual és igual al del canal estàndar d'entrada
     */
    Idioma& consultar_idioma(string nom);
    
    //Lectura i escriptura
    
    /** @brief Lectora d'un conjut d'idiomes
     * @pre Cert
     * @post El parametre implicit conte n idiomes llegits
     */
    void llegir (int n);

};

#endif
