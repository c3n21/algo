#include<stdio.h>
#include<math.h>

typedef struct {
        float raggio;
} Cerchio;

typedef struct {
  float x, y;
} Punto;

typedef struct {
  Punto p1;
  Punto p2;
} Rettangolo;

int main( void ){

  float b, h, area, duep;
  Rettangolo r;
  
//  printf( "RETTANGOLO:\n" );
//  printf( "Inserisci le coordinate del punto in basso a sinistra\n" );
//  scanf( "%f%f" , &r.p1.x, &r.p1.y );
//  printf( "Inserisci le coordinate del punto in alto a destra\n" );
//  scanf( "%f%f", &r.p2.x, &r.p2.y );
  printf( "CERCHIO:\n" );
  printf( "Inserisci le coordinate del centro\n" );
  scanf( "%f%f" , &r.p1.x, &r.p1.y );
  b = r.p2.x - r.p1.x;
  h = r.p2.y - r.p1.y;
  area = b * h;
  duep = 2 * ( b + h );
  printf( "L'area del rettangolo vale %f, il perimetro vale %f\n", area, duep );
  
  return 0;
}
