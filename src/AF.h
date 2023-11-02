/************************************************\INCLUDE\************************************************/
#ifndef AF_H_INCLUDED
#define AF_H_INCLUDED

#include <gtk/gtk.h>

/************************************************\STRUCT_FBA\************************************************/
typedef struct
{
  int jour;
  int mois;
  int annee;
}date;
typedef struct
{
  char spec[20];
  int niv;
}classe;
typedef struct
{
  char nom[30];
  char prenom[30];
  date naissance;
  classe niveau;
  char chambre[20];
  int CIN;
  char tel[20];
}Etudiant;

/************************************************\PROTOTYPE_FBA\************************************************/
void ajouter_fba(Etudiant E,char txt_fba[]);
void chercher_fba(char entry [],int rechoix_fba/*char txt_fba[]*/);
void modifier_fba(int choix_fba,Etudiant E,char carte[]);
void supprimer_fba(char ch[]);
void afficher_fba(GtkWidget *liste,char txt_fba[]);
int calcul_fba(int calculfba[],char txt_fba[]);

#endif // AF_H_INCLUDED
