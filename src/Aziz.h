#include <gtk/gtk.h>
typedef struct {
char type_ingred[50]; //liquide ou solide, viande ou vegetaux etc
char Nomb_ingred[10];
char date_valid[50];
char date_ajout[50];
char refer[10];
}stock;

int verif(char log[],char pw[]);
void ajouter_utilisateur(char login1[],char passw[],char nom[],char prenom[],int role);


void ajouter_Aziz(stock ingred,int unite);
void modifier_Aziz(char ref[],int choix[],stock ingred);
void supprimer_Aziz(stock ingred);

void afficher_Aziz(GtkWidget *liste);
void afficher1_Aziz(GtkWidget *liste,stock ingred);
stock chercher_Aziz(char refer[]);
stock cherch_type_Aziz(char type[]);
stock cherch_nomb_Aziz(char nomb[]);
stock cherch_datea_Aziz(char datea[]);
stock cherch_datev_Aziz(char datev[]);
stock rupture_Aziz();





