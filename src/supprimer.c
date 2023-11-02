#include <stdio.h>

#include <string.h>
# include "supprimer.h"

void supprimer(char n_id[],char n_jour [] ,char n_temps[]){
char id [30];  
 char jour[30] ;
  char temps[30];
  char demarrer[30];
  char plat_principal[30];
  char breuvage[30];
  char dessert[30];
char tmp[50];
strcat(n_jour,n_temps);
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
         
            
        if (strcmp(id,n_id)!=0)  
            {
            
        
        
         fprintf(t,"%s %s %s %s %s %s %s \n",id,jour,temps,demarrer,plat_principal,breuvage,dessert);}
         i+=1;} while(fscanf(f,"%s %s %s %s %s %s %s \n",id,jour,temps,demarrer,plat_principal,breuvage,dessert)!= EOF);


fclose(t);
}
fclose(f);
}}
remove("menu.txt");
rename("temp.txt", "menu.txt");

}


