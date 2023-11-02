#include <stdio.h>

#include <string.h>
# include "modifier.h"

void modifier(char n_id [],char n_jour [] ,char n_temps[],char n_demarrer [],char n_plat_principal[],char n_breuvage [],char n_dessert[]){
 char id[30]; 
 char jour[30] ;
  
  char temps[30];
  char demarrer[30];
  char plat_principal[30];
  char breuvage[30];
  char dessert[30];
int i =0;
FILE* f;
FILE* t;
f=fopen("menu.txt","r+");
       t=fopen("temp.txt","w");


if(f!=NULL)
 {
   while(fscanf(f,"%s %s %s %s %s %s %s \n",id,jour,temps,demarrer,plat_principal,breuvage,dessert)!= EOF)
{
    // strcpy(mm[i].temps,E.temps);
    if(t!=NULL){
            do{


        if (strcmp(id,n_id)==0)  //&& (strcmp(dd[i].jour,jour_m)==0))
            {
         
        
        
         fprintf(t,"%s %s %s %s %s %s %s \n",n_id,n_jour,n_temps,n_demarrer,n_plat_principal,n_breuvage,n_dessert);
         i+=1;}

   else fprintf(t,"%s %s %s %s %s %s %s \n",id,jour,temps,demarrer,plat_principal,breuvage,dessert); i+=1;}
    while(fscanf(f,"%s %s %s %s %s %s %s \n",id,jour,temps,demarrer,plat_principal,breuvage,dessert)!= EOF);


fclose(t);
}
fclose(f);
}}
remove("menu.txt");
rename("temp.txt", "menu.txt");

}


