#include "capteur.h"
#include "callbacks.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

enum{
ID,
VALEUR,
DATE_INSTALLATION,
TYPE,
ETAGE,
BLOC,
FONC,
SIG,
COLUMNS
};

GtkListStore *store;/*creation du modele de type liste*/
GtkTreeViewColumn *column;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;
////////////////////////////////AjouterCapteur///////////////////////
void ajouter_capteur(Capteur c)
{
    FILE *fp;
    fp = fopen("capteurs.bin", "ab+");
    if (fp!=NULL)
    {
        

        fwrite(&c, sizeof(c), 1, fp);
        
    }
    else
    {
        printf("\n non trouver");
    }
fclose(fp);
}
/////////////////////////////////////AfficherCapteur////////////////////////////////////////
void afficher_capteur(GtkWidget *liste)
{
Capteur c;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store = NULL;
FILE *fp;


store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Valeur",renderer,"text",VALEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date d'installation",renderer,"text",DATE_INSTALLATION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Etage",renderer,"text",ETAGE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Bloc",renderer,"text",BLOC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Fonctionnement",renderer,"text",FONC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Signale",renderer,"text",SIG,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	fp = fopen("capteurs.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("capteurs.bin", "ab+");	
		while(fread(&c, sizeof(c), 1, fp))
		{
		sprintf(DATE, "%d/%d/%d", c.date_installation.jour,c.date_installation.mois,c.date_installation.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ID, c.id, VALEUR, c.valeur,DATE_INSTALLATION, DATE, TYPE, c.type,  ETAGE, c.etage,BLOC,c.bloc,FONC,c.fonc,SIG,c.sig,-1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}
/////////////////////////////////////SupprimerCapteur////////////////////////////////////
void supprimer_capteur(Capteur c, char id[], char type[])
{

FILE *fp1, *fp2;
    fp1 = fopen("capteurs.bin", "rb");
    fp2 = fopen("temp.bin", "ab+");
    if (fp1==NULL)
    {
        printf("\nEchec lors de l'ouverture du fichier 'capteurs.bin'");
    }
    else
    {
        while (fread(&c, sizeof(c), 1, fp1))
        {
            if ((strcmp(id, c.id)!=0) && (strcmp(type, c.type)!=0))
                fwrite(&c, sizeof(c), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("capteurs.bin");
    rename("temp.bin", "capteurs.bin");
}

/////////////////////////////////////Afficher capteur a modifier ////////////////////////////////
void afficher_capteurModif(GtkWidget *liste)
{
Capteur c;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store = NULL;

FILE *fp;



store = gtk_tree_view_get_model(liste);

if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Valeur",renderer,"text",VALEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date d'installation",renderer,"text",DATE_INSTALLATION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Etage",renderer,"text",ETAGE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Bloc",renderer,"text",BLOC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Fonctionnement",renderer,"text",FONC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Signale",renderer,"text",SIG,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	fp = fopen("temp1.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("temp1.bin", "ab+");	
		while(fread(&c, sizeof(c), 1, fp))
		{
		sprintf(DATE, "%d/%d/%d", c.date_installation.jour,c.date_installation.mois,c.date_installation.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ID, c.id, VALEUR, c.valeur, TYPE, c.type, DATE_INSTALLATION, DATE, ETAGE, c.etage,BLOC,c.bloc,FONC,c.fonc,SIG,c.sig,-1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}

///////////////////////////////////// capteur a modifier ///////////////////////////////////////////
void modifier_capteur(Capteur r, char id[])
{
FILE *fp1, *fp2;
Capteur c;
fp1 = fopen("capteurs.bin", "rb");
fp2 = fopen("tmpp.bin","ab+");
if (fp1==NULL)
{
	return ;
}
else
{
	while (fread(&c,sizeof(c),1,fp1))
	{
		if (strcmp(c.id,id)!=0)
			fwrite(&c,sizeof(c),1,fp2);
		else
		{
			fwrite(&r,sizeof(r),1,fp2);			
		}
	}
}
fclose(fp1);
fclose(fp2);
remove("capteurs.bin");
rename("tmpp.bin", "capteurs.bin");

}
/////////////////////////////////////Afficher capteur alarmant ////////////////////////////////////////
void afficher_capteur_alarmant(GtkWidget *liste)
{
Capteur c;
float max1=50, min1=10;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store = NULL;
FILE *fp;


store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Valeur",renderer,"text",VALEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date d'installation",renderer,"text",DATE_INSTALLATION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Etage",renderer,"text",ETAGE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Bloc",renderer,"text",BLOC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Fonctionnement",renderer,"text",FONC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Signale",renderer,"text",SIG,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	fp = fopen("capteurs.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("capteurs.bin", "ab+");	
		while(fread(&c, sizeof(c), 1, fp))
		{
		 if( ((strcmp(c.type,"Temperature")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1)))||((strcmp(c.type,"Humidite")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1))) || ((strcmp(c.type,"Debit")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1))) || ((strcmp(c.type,"Fumee")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1))) || ((strcmp(c.type,"Mouvement")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1))) ){
		sprintf(DATE, "%d/%d/%d", c.date_installation.jour,c.date_installation.mois,c.date_installation.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ID, c.id, VALEUR, c.valeur,DATE_INSTALLATION, DATE, TYPE, c.type,  ETAGE, c.etage,BLOC,c.bloc,FONC,c.fonc,SIG,c.sig,-1);
		}
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}


/////////////////////////////////////chercher capteur a supprimer ///////////////////////////////////////////
void chercher_capteur_supp(Capteur c, char id[20],char type[20], int *ok)
{
FILE *fp ,*fp1;
fp = fopen("capteurs.bin", "rb");
fp1 = fopen("temp1.bin", "wb");
*ok=0;

if(fp==NULL)
{
return;
}
else
{
while(fread(&c, sizeof(c), 1, fp))
{
	if  ((strcmp(id, c.id)==0) && (strcmp(type, c.type)==0))
	{
		fwrite(&c, sizeof(c), 1, fp1);
		*ok=1; 
	}

}
}
fclose(fp);
fclose(fp1);
}
/////////////////////////////////////nombre  capteur alarmants ////////////////////////////////////////
int nbre_alarmants(float max1, float min1, float max2, float min2)
{
Capteur c;
float max11=50, min11=10;
FILE *f1;
int nbr=0;
f1 = fopen("capteurs.bin", "rb");
if(f1==NULL)
{
return;
}
else
{
while(fread(&c, sizeof(c), 1, f1))
{
if( ((strcmp(c.type,"Temperature")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1)))||((strcmp(c.type,"Humidite")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1))) || ((strcmp(c.type,"Debit")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1))) || ((strcmp(c.type,"Fumee")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1))) || ((strcmp(c.type,"Mouvement")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1))))
{
nbr++;
}
}
fclose(f1);
return nbr;
}
}
/////////////////////////////////////chercher un capteur  //////////////////////////////////////
void chercher_capteur(Capteur c, char id[20], int *ok)
{
FILE *fp ,*fp1;
fp = fopen("capteurs.bin", "rb");
fp1 = fopen("temp1.bin", "wb");
*ok=0;

if(fp==NULL)
{
return;
}
else
{
while(fread(&c, sizeof(c), 1, fp))
{
	if  ((strcmp(id, c.id)==0) )
	{
		fwrite(&c, sizeof(c), 1, fp1);
		*ok=1; 
	}

}
}
fclose(fp);
fclose(fp1);
}


void Debittree(GtkWidget* treeview1,char*l)
{

debit d;


        /* Creation du modele */
        store = gtk_list_store_new(4,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
				     G_TYPE_FLOAT);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%d %d %d %f\n",&d.jour,&d.heure,&d.numCapteu,&d.valeurDebit)!=EOF)
        {
	if(d.valeurDebit>25){

	GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(store, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(store, &pIter,
                            0,d.jour,
                            1,d.heure,
                            2,d.numCapteu,
                            3,d.valeurDebit,-1);}
}
        fclose(f);

	/* Creation de la 1ere colonne */
if(i==0)
	{cellad = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("JOUR",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("HEURE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NUM CAPTEUR",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);


	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("VALEUR DEBIT",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);

	


	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(store)  );

}

void Temptree(GtkWidget* treeview1,char*l)
{

temp t;



        /* Creation du modele */
        store = gtk_list_store_new(4,
                                     G_TYPE_INT,
				     G_TYPE_INT,
				     G_TYPE_INT,
                                     G_TYPE_FLOAT
			             );
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%d %d %d %f\n",&t.jour,&t.heure,&t.numCapteu,&t.valeurTemp)!=EOF)
        {
if(t.valeurTemp>50||t.valeurTemp<0){
	GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(store, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(store, &pIter,
                            0,t.jour,
                            1,t.heure,
                            2,t.numCapteu,
                            3,t.valeurTemp,-1);}
}
        fclose(f);

	/* Creation de la 1ere colonne */
if(v==0)
	{cellad = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("JOUR",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("HEURE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NUM CAPTEUR",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);


	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("VALEUR TEMPERATURE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);

	


	v++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(store)  );

}

void Fumeetree(GtkWidget* treeview1,char*l)
{













FUMEE F;


        /* Creation du modele */
        store = gtk_list_store_new(4,
                                     G_TYPE_INT,
				     G_TYPE_INT,
				     G_TYPE_INT,
                                     G_TYPE_INT
			             );
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%d %d %d %d\n",&F.jour,&F.heure,&F.numCapteu,&F.etatF)!=EOF)
        {
	if(F.etatF==1){

	GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(store, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(store, &pIter,
                            0,F.jour,
                            1,F.heure,
                            2,F.numCapteu,
                            3,F.etatF,-1);}
}
        fclose(f);

	/* Creation de la 1ere colonne */
if(v==0)
	{cellad = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("JOUR",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("HEURE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NUM CAPTEUR",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);


	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ETAT",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);

	


	v++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(store)  );

}



