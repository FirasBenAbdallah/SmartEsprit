#include "SEW.h"
#include <stdio.h>
#include <string.h>

void ajouter_sew(char nom[], char prenom[], char login[], char password[], char role[])
{

FILE* f;
f=fopen("utilisateur_w.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s \n",nom,prenom,login,password,role);
fclose(f);
}
}

int verifier_sew (char login[], char password[])
{
int role=0;
FILE* f=NULL;
char ch1[50];
char ch2[50];
char ch3[50];
char ch4[50];
char ch5[50];
f=fopen("utilisateur_w.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s",ch1,ch2,ch3,ch4,ch5)!=EOF)
{
if((strcmp(ch3,login)==0)&&(strcmp(ch4,password)==0)){
	if(strcmp(ch5,"Directeur")==0){role=1;}
	if(strcmp(ch5,"Etudiant")==0){role=2;}
	if(strcmp(ch5,"Technicien")==0){role=3;}
	if(strcmp(ch5,"Agent_de_foyer")==0){role=4;}
	if(strcmp(ch5,"Agent_de_stock")==0){role=5;}
	if(strcmp(ch5,"Nutritionniste")==0){role=6;}
	if(strcmp(ch5,"S.Reclamation")==0){role=7;}
}
}
fclose(f);
}
return role;
}
