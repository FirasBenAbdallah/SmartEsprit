#include <stdio.h>

#include <string.h>
# include "verfier_j.h"

int verfier_t(char x[],char y[]){
char jour[30];
char temps[30];
char demarrer [30];
char plat_principal[30];
char breuvage [30];
char dessert [30];
int test=0;
int j=0;
int i=0;

char mm[30];
FILE *f =NULL;

f = fopen("menu.txt","r");
if (f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s ",jour,temps,demarrer,plat_principal,breuvage
,dessert)!=EOF){

if ((strcmp(x,temps)==0)&&(strcmp(y,jour)==0))
 test =1 ;}


return test ;
fclose(f);
}}

