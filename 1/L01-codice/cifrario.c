/* Programma che riceve in input una chiave numerica k (compresa tra 0 e 26), 
seguita da un messaggio, e stampa quest'ultimo in codice usando 
il cifrario di Cesare con chiave k.  */

#include <stdio.h>
#include <ctype.h>

int main( void ) {

  int k;
  char c; 
  scanf( "%d ", &k );

  while ( ( c = getchar() ) != '.' ) {

    if ( isalpha( c ) )
      //if isupper( c ) 
      if (c > 64 && c < 91) //[4]
        putchar( 'A' + ( c - 'A' + k ) % 26 );
      else
        putchar( 'a' + ( c - 'a' + k ) % 26 );

    else
      putchar( c );
  }

  printf ( "\n" );
  return 0;

}

/*
 * [1] a = 97
 *  l = 108 -> 4 -> 101 -> e
 *  o = 111 -> 7 -> 104 -> h
 *  Z = 90 -> 83
 *  output:
 *  eeh Shh
 *  5
 *
 * [2] riga 24, vengono semplicemente stampati
 * [3] 18 - 21
 * [5] Fa la sottrazione tra c (i char vengono interpretati come interi nelle operazioni aritmetiche) ed 'A' viene convertito implicitamente nel suo relativo valore numeri corrispondente al suo valore tabella ASCII, quindi 65
 * [6] % indica l'operazione modulo. 
 * ( c - 'A' + k ) % 26 significa che al carattere c (che è per forza di cose maiuscolo) sottraggo il carattere 'A', trovando così la posizione assoluta nell'alfabeto del linguaggio naturale, e poi aggiungo k che è la chiave, trovando così il carattere che con cui deve essere criptato. Il modulo serve perché per k molto grandi potrei "sfondare" il limite dell'alfabeto che è 26. Facendo il modulo quindi normalizzo il valore di offset a quello dell'alfabeto del linguaggio naturale.
 * [7] Sommare 'A' all'espressione precedente serve perché con l'espressione precedente troviamo solo l'offset con cui spostarci nell'alfabeto del linguaggio naturale che volendo possiamo visualizzare come un array che parte da 0 (che è A) a 25 (che è Z). Nei calcolatori i caratteri sono rappresentati secondo la tabela ASCII (oppure seguendo la codifica UTF-8), nella quale il carattere 'A' è in posizione 65. Quindi, il nostro "zero" nella tabella ASCII è il 65.
 * [8] Viene tenuto in memoria solo un carattere alla volta e vengono memorizzati tramite la funzione getchar, quindi STDIN
 *
 */
