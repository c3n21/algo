/*
 * [1] Un qualsiasi carattere che non sia '.'
 * [2] Si deve inserire il carattere '.'
 * [3] getchar legge da STDIN che di default usa il line buffering, perciò ogni volta che si inserisce LF il buffer è pronto per essere letto. Inoltre, se prima di LF c'è un '.' la stringa viene tagliata fino alla sua prima occorrenza.
 * [4] viene usato per capire se il carattere è una lettera dell'alfabeto
 * [5] I caratteri letti volta per volta vengono salvati in una variabile char e poi stampata a schermo.
 * [6] Dipende dal STDIN, su Linux dovrebbe essere di 4096 caretteri
 * https://stackoverflow.com/questions/13833628/how-to-increase-the-stdin-buffersize
 * [7] Il programma legge da standard input una serie di caratteri fino a quando non incontra un '.' Per ogni carattere controlla se è una lettera dell'alfabeto, e quindi procede a a stamparlo in stampatello, altrimenti lo stampa direttamente
 */

#include <stdio.h>
#include <ctype.h>

int main( void ) {
  char c;

  while ( ( c = getchar() ) != '.' ) {
    if ( isalpha( c ) )
      putchar( toupper( c ) );
    else
      putchar( c );
  }

  printf ( "\n" );
  return 0;
}
