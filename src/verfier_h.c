#include"string.h"
#include<stdio.h>
int  verfier_h(char x[],char y[])
{
char nom[30];
char prenom[30];

int role;
int test=0;
FILE *f =NULL;

f = fopen("utilisateur_hedi.txt","r");
if (f!=NULL){
while(fscanf(f,"%s %s ",nom,prenom)!=EOF){

if ((strcmp(x,nom)==0)&&(strcmp(y,prenom)==0)) test =1 ;}


return test ;
fclose(f);

}
}
