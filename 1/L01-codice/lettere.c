/*
 * [1] Un carattere
 * [2] Serve ad includere la il file header ctype
 * [3] a -> è una vocale dell'alfabeto italiano
 *     b -> è una consonante dell'alfabeto italiano
 *     y -> non è una lettera dell'alfabeto italiano
 * [4] non è una lettera dell'alfabeto italiano
 * [5] non è una lettera dell'alfabeto italiano
 * [6] ritorna un boolean e verifica se il parametro è una lettera dell'alfabeto
 * [7] il programma prende in input da STDIN un carattere qualsiasi, verifica che questo non sia una lettera dell'alfabeto stampando "non è una lettera dell'alfabeto italiano" in caso affermativo, altrimenti verifica se è una vocale o consonante dell'alfabeto italiano, oppure se è una lettera che non appartiene all'alfabeto italiano (ma che è comunque una lettera dell'alfabeto internazionale)
 */

#include <stdio.h>
#include <ctype.h>

int main( void ) {

  char c;

  printf( "Inserisci un carattere: " );
  scanf( "%c", &c );

  if ( !isalpha (c) )
    printf( "%c non e` una lettera dell'alfabeto italiano\n", c );
  else {
    switch ( tolower( c ) ) {
      case 'a': case 'e': case 'i': case 'o': case 'u':
          printf( "%c e` una vocale dell'alfabeto italiano\n", c );
          break;
  
      case 'x': case 'y': case 'w': case 'j': case 'k':
        printf( "%c non e` una lettera dell'alfabeto italiano\n", c );
        break;
  
      default:
        printf( "%c e` una consonante dell'alfabeto italiano\n", c );
        break;
    }
  }

  return 0;
}
