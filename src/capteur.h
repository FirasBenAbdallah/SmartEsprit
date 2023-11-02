#include <gtk/gtk.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
}Installation;

typedef struct
{
    char id[20];
    Installation date_installation;
    char type[20];
    char valeur[20];
    char etage[20];
    char bloc[20];
    char fonc[20];
    char sig[20];
}Capteur;


typedef struct debit debit;
struct debit{
int jour;
int heure;
int numCapteu;
float valeurDebit;
};


typedef struct temp temp;
struct temp{
int jour;
int heure;
int numCapteu;
float valeurTemp;
};

typedef struct FUMEE FUMEE;
struct FUMEE{
int jour;
int heure;
int numCapteu;
int etatF;
};

int i,j,w,v,z;

GtkWidget *acceuil;
  GtkWidget *gestion_Capteur;
  GtkWidget *catalogue;
GtkWidget *etages_contenant_des_pannes;
GtkWidget *capteurs_defectueux;
GtkWidget *liste_des_alarmes;


void  ajouter_capteur(Capteur c);
void afficher_capteur(GtkWidget *liste);
void supprimer_capteur(Capteur c, char id[],char type[]);
void modifier_capteur(Capteur r, char id[]);
void chercher_capteur_supp(Capteur c, char id[20],char type[20],int *ok);
void afficher_capteurModif(GtkWidget *liste);
void afficher_capteur_alarmant(GtkWidget *liste);
int nbre_alarmants(float max1, float min1, float max2, float min2);
void chercher_capteur(Capteur c, char id[20], int *ok);void Capteurtree(GtkWidget* treeview1,char*l);
int ChercherCapteurTree(GtkWidget* treeview1,char*l,char*type);
void Debittree(GtkWidget* treeview1,char*l);
void Temptree(GtkWidget* treeview1,char*l);
void Fumeetree(GtkWidget* treeview1,char*l);
