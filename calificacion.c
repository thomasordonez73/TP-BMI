#include <stdio.h>
int main(){
  int n;printf("Ingrese la calificacion: ");
  scanf("%d",&n);
  if(n>=90)printf("Calificacion: A\n");
  else if(n>=80)printf("Calificacion: B\n");
  else if(n>=70)printf("Calificacion: C\n");
  else if(n>=60)printf("Calificacion: D\n");
  else printf("Calificacion: F\n");
  return 0;}
