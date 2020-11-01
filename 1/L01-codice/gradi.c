/* 
conversione da gradi Fahrenheit: 
celsius = (fahr - 32) * 5/9 

[1] Output su STDOUT

[2] Prendere input da STDIN

[3] La variabile cels serve per memorizzare il valore della temperatura in celsius. Si può anche omettere sostituendo cels dentro alla printf con l'operazione che lo calcola

[4] Servono per dare la giusta precedenza alle operazioni (quindi in questo caso voglio che la divisione venga fatta solo tra questi due operandi e nessun altro, però nel contesto in cui sono messe nel programma si possono omettere senza che il programma modifichi il suo comportamento originale

[5] In questo caso sì perché la variabile cels è float, quindi viene fatta la conversione implicitamente
*/

#include <stdio.h>

#define FATTORE_SCALA  ( 5.0f / 9.0f )
#define ZERO 32.0f

int main( void ){
	float fahr, cels;
	printf( "Inserisci la temperatura in gradi Fahrenheit: " );
	scanf( "%f", &fahr );
	cels = ( fahr - ZERO ) * FATTORE_SCALA;
	printf( "Gradi Celisus equivalenti: %.1f\n", cels );
	printf( "Gradi Celisus equivalenti: %.1f\n",( fahr - ZERO ) * FATTORE_SCALA);
	return 0;
}
