#include <stdio.h>
#include <time.h>

int counter = 0;

unsigned long f_riter(unsigned long a, unsigned long b, int n){
  counter += 1;
  if ( n == 2 ) {
    return a;
  }
  if ( n == 1 ) {
    return b;
  }
  return f_riter( a + b, a, n - 1 );
}


unsigned long f_iter1(int n){
  unsigned long f, f1 = 1, f2 = 1;
  counter += 1;
  if ( n == 2 | n == 1 ) {
    return 1;
  }
  while (n-- >= 3){
    f = f1 + f2;
    f1 = f2;
    f2 = f;
  }
  return f;
}

unsigned long f_rec(int n){
  counter += 1;
  if ( n == 1 || n == 2 ){
    return 1;
  }
  return f_rec( n - 1 ) + f_rec( n - 2 );
}

unsigned long f_siter(unsigned long a, unsigned long b,
                        unsigned long p, unsigned long q,
                        int n){
  counter += 1;
  if ( n == 0 ) {
    return b;
  }
  if ( n % 2 == 0 ){
    return f_siter( a, b, q*q + p*p, q*q + 2*p*q, n / 2 );
  }
  return f_siter( b*q + a*q + a*p, b*p + a*q, p, q, n - 1 );
}

unsigned long f_iter2(int n){
  unsigned long f, f1 = 1, f2 = 1, i;
  counter += 1;
  if ( n == 2 | n == 1 ) {
    return 1;
  }

  for ( i = 2; i <= n; i++ ) {
    f = f1 + f2;
    f1 = f2;
    f2 = f;
  }
  return f;
}





int main(){
  clock_t start, end;
  double cpu_time_used = 0;
  int N = 30, i;
  int TIMES = 100;


  cpu_time_used = 0;
  for (i=0; i < TIMES; i++) {
    counter = 0;
    start = clock();
    fprintf(stderr, "f(%d) = %lu\n", N, f_riter(1, 1, N));
    end = clock();
    cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
  }
  printf("Tempo medio riter: %g (%d passi)\n", cpu_time_used/TIMES, counter);

  cpu_time_used = 0;
  for (i=0; i < TIMES; i++) {
    counter = 0;
    start = clock();
    fprintf(stderr, "f(%d) = %lu\n", N, f_iter1(N));
    end = clock();
    cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
  }
  printf("Tempo medio iter: %g (%d passi)\n", cpu_time_used/TIMES, counter);


  cpu_time_used = 0;
  for (i=0; i < TIMES; i++) {
    counter = 0;
    start = clock();
    fprintf(stderr, "f(%d) = %lu\n", N, f_siter(1,0,0,1,N));
    end = clock();
    cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
  }
  printf("Tempo medio riteropt: %g (%d passi)\n", cpu_time_used/TIMES, counter);

  cpu_time_used = 0;
  for (i=0; i < TIMES; i++) {
    counter = 0;
    start = clock();
    fprintf(stderr, "f(%d) = %lu\n", N, f_rec(N));
    end = clock();
    cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
  }
  printf("Tempo medio rec: %g (%d passi)\n", cpu_time_used/TIMES, counter);



}
