#include <stdio.h>
int main(){
  float p,a,i;
  printf("Ingrese el peso en kg: ");
  scanf("%f",&p);
  printf("Ingrese la altura en metros: ");
  scanf("%f",&a);
  i=p/(a*a);
  printf("\nSu indice de masa corporal es: %.2f\n\n",i);
  printf("Indice  |  Condicion\n-----------------------------\n  <18.5  |  Bajo peso\n 18.5 a 24.9  |  Normal\n 25.0 a 29.9  |  Sobrepeso\n >=30  |  Obesidad\n\n");
  if(i<18.5)
    printf("Usted se encuentra en la condicion: Bajo peso\n");
  else if(i<25)printf("Usted se encuentra en la condicion: Normal\n");
  else if(i<30)printf("Usted se encuentra en la condicion: Sobrepeso\n");
  else printf("Usted se encuentra en la condicion: Obesidad\n");
  return 0;}
