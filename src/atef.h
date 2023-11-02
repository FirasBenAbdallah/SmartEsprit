#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct reclam
{
    int id;
    char prenom[20];
    char nom[20];
    char classe[10];
    int service;
    char desc[500];
}reclam;


void ajouter_atef(reclam u, char *fname);
void supprimer_atef(reclam u, char *fname);
void modifier_atef(reclam u, char *fname);
void afficher_atef(GtkWidget *liste, char *fname);
char* plus_reclame(char *fname);

