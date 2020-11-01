    int c, f[10] = {0};
    
    c = getchar();
    while ( c != '.' ) {
        if ( isdigit( c ) ) 
	    f[ c - '0' ]++;
	c = getchar();
    }

/*
 * [1] Sottrae il valore int associato al carattere '0' a c
 * [2] Serve per avere il giusto indice per l'array
 * [3] In che senso? <------
 * [4] contatore
 * [5] printf("Finché il carattere inserito è diverso da '.' se leggi un carattere che è una cifra allora aumenta il suo contatore.")
 * [6] Finché il carattere inserito è diverso da '.' se leggi un carattere che è una cifra allora aumenta il suo contatore.
