#include <stdio.h>

#include <string.h>
# include "ajouter.h"

void ajouter(char id [],char jour [] ,char temps[],char demarrer [],char plat_principal [],char breuvage [],char dessert[]){
  FILE* f;
    f=fopen("menu.txt","a+");
if (f!=NULL){ 
fprintf(f,"%s %s %s %s %s %s %s \n",id,jour,temps,demarrer,plat_principal,breuvage,dessert);
        fclose(f);
}
}



