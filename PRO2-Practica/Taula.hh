/** @file Taula.hh
 *  @brief Especificación de la clase Taula
 */

#ifndef TAULA_HH
#define TAULA_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#endif
using namespace std; 
/*
 * Clase Taula
 */

/**
 * @class Taula
 * @brief Representa una Taula on es fan varies operacions
 */
class Taula {
    
private:
    
    /** @brief Mapa d'una taula de freqüències. 

      Ordenat alfabèticament */ 
    map<string, int> taula;
    
    /** @brief Iterador d'una taula de freqüències.
     */
    map<string, int> ::const_iterator it;
    
public:
    
    //Constructora
    
    /** @brief Constructora per defecte
     * @pre: Cert
     * @post: El resultat es una taula buida
     */
    Taula();
    
    //Destructora
   
    /** @brief Destructora per defecte
     * @pre Cert
     * @post Esbrorra un taula buida
     */
    ~Taula();
    
    //Modificadores
    
    /** @brief Modificadora de la taula de freqüències
     * @pre Cert
     * @post El resultat es un idioma amb una taula resultat de la suma de la seva anterior taula de freqüències més la del idioma del canal d'entrada 
     */
    void sumart();
    
    //Lectura i escriptura
    
    /** @brief Lectora de taula de freqüències
     * @pre Cert
     * @post El resultat es una taula de freqüències de mida p
     */
    void llegirt();
    
    /** @brief Escriptora de la taula de freqüències
     * @pre Cert
     * @post El resultat es la taula de frqencies a la sortida de la consola
     */
    void escriuret();
    
    //Iteradors
    
    /** @brief Iteradora d'inici
     * @pre Cert
     * @post Estableix l'iterador a l'inici de la taula
     */
    void inici();
    
    /** @brief Iteradora per avançar
     * @pre L'iterador no apunta al final de la taula
     * @post Augmenta l'iterador en una posició
     */
    void avanca();
    
    /** @brief Consultora de l'iterador
     * @pre L'iterador no apunta al final de la taula
     * @post Retorna la posició l'iterador dins de la taula
     */
    pair<string, int> actual() const;
    
    /** @brief Iteradora de fi
     * @pre Cert
     * @post Retorna cert si l'iterador es al final de la taula, altre cas retorna fals
     */
    bool fi() const;
    
};

#endif
