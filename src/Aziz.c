#include <stdio.h>
#include "Aziz.h"
#include <string.h>
#include <gtk/gtk.h>
enum
{
TYPE,
DATEV,
DATEA,
NOMBRE,
REF,
COLUMNS
};
int verif(char log[],char pw[])
{ 
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("utilisateur.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s",ch1,ch2)!=EOF)
{
if((strcmp(ch1,log)==0) && (strcmp(ch2,pw)==0))
trouve=1;
}
fclose(f);
}
return (trouve);
}

void ajouter_Aziz(stock ingred,int unite)
{ 
FILE *f;
char uni[10];

f=fopen("stock.txt","a+");
if (f!=NULL)
{
if(unite==1)
{
strcat(ingred.Nomb_ingred,"Litres");

}
if(unite==2)
{
strcat(ingred.Nomb_ingred,"Kg");

}
if(unite==3)
{
strcat(ingred.Nomb_ingred,"unités");

}


fprintf(f,"%s %s %s %s %s \n",ingred.type_ingred,ingred.date_ajout,ingred.date_valid,ingred.refer,ingred.Nomb_ingred);
fclose(f);
}

}




stock chercher_Aziz(char ref[])
{ FILE *f;
 int trouve=0;
stock ingred1;



  
  f=fopen("stock.txt","r");

  if(f!=NULL)
            {while(fscanf(f,"%s %s %s %s %s \n",ingred1.type_ingred,ingred1.date_ajout,ingred1.date_valid,ingred1.refer,ingred1.Nomb_ingred)!=EOF)
	     {
if (strcmp(ingred1.refer,ref)==0)
	{
fclose(f);
return ingred1;



}

}

}
}
void modifier_Aziz(char ref[],int choix[],stock ingred) //nombre =choix[0], datev=choix[1], datea=choix[2],type=choix[3]
{ FILE *f,*l;
char type_ingred[50]; 
char Nomb_ingred[10];
char date_valid[50];
char date_ajout[50];
char refer[10];
 char ref1[20];


f=fopen("stock.txt","r");
l=fopen("tmp.txt","a+");
if(f==NULL || l==NULL)
{
return;
}
else
{while(fscanf(f,"%s %s %s %s %s \n",type_ingred,date_ajout,date_valid,refer,Nomb_ingred)!=EOF)
{   if(strcmp(ref,refer)!=0)
	{
	fprintf(l,"%s %s %s %s %s \n",type_ingred,date_ajout,date_valid,refer,Nomb_ingred);
	} 
    else
	{
		if(choix[0]==1)
		{ strcpy(Nomb_ingred,ingred.Nomb_ingred);
		 choix[0]=0;
		}		
		 if(choix[1]==1)
		{ strcpy(date_valid,ingred.date_valid);
		  choix[1]=0;
		}	
		 if(choix[2]==1)
		{ strcpy(date_ajout,ingred.date_ajout);
			choix[2]=0;
		}
		 if(choix[3]==1)
		{ strcpy(type_ingred,ingred.type_ingred);
		 choix[3]=0;
		}
		
	}			
}

fprintf(l,"%s %s %s %s %s \n",type_ingred,date_ajout,date_valid,refer,Nomb_ingred);
}
fclose(f);
fclose(l);
remove("stock.txt");
rename("tmp.txt","stock.txt");

}

 void supprimer_Aziz(stock ingred)
{ char type_ingred[50]; 
char Nomb_ingred[10];
char date_valid[50];
char date_ajout[50];
char refer[10];
FILE *f, *l;

f=fopen("stock.txt","r");
l=fopen("tmp.txt","a+");
if(f==NULL || l==NULL )
{
return;
}
else
{
while(fscanf(f,"%s %s %s %s %s \n",type_ingred,date_ajout,date_valid,refer,Nomb_ingred)!=EOF)
{ 
if (strcmp(ingred.type_ingred,type_ingred)!=0 || strcmp(ingred.date_ajout,date_ajout)!=0 || strcmp(ingred.date_valid,date_valid)!=0 || strcmp(ingred.refer,refer)!=0 || strcmp(ingred.Nomb_ingred,Nomb_ingred)!=0)
fprintf(l,"%s %s %s %s %s \n",type_ingred,date_ajout,date_valid,refer,Nomb_ingred);

}
fclose(f);
fclose(l);
remove("stock.txt");
rename("tmp.txt","stock.txt");

}
}
void afficher_Aziz(GtkWidget *liste)
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	 char type_ingred[50]; 
char Nomb_ingred[10];
char date_valid[50];
char date_ajout[50];
char refer[10];
store= NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);  




if(store==NULL)
{
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes(" DateA",renderer,"text",DATEA,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes(" DateV",renderer,"text",DATEV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Refer",renderer,"text",REF,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Nombre",renderer,"text",NOMBRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
 
  f=fopen("stock.txt","r");
   if (f==NULL)
   {
return;
}
else
{
f=fopen("stock.txt","a+");
while (fscanf(f,"%s %s %s %s %s \n",type_ingred,date_ajout,date_valid,refer,Nomb_ingred)!= EOF)
    {
	gtk_list_store_append(store,&iter);
	gtk_list_store_set (store,&iter,TYPE,type_ingred,DATEA,date_ajout,DATEV,date_valid,REF,refer,NOMBRE,Nomb_ingred,-1);

    
   }
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste) ,GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
}
stock rupture_Aziz()
{
stock ingred;
FILE *f;

char type_ingred[50];
char Nomb_ingred[10];
char date_valid[50];
char date_ajout[50];
char refer[10];
char comparel[10]="0Litres";
char comparekg[10]="0Kg";
char compareuni[10]="0unités";

  
  f=fopen("stock.txt","r");

  if(f!=NULL)
            {while(fscanf(f,"%s %s %s %s %s \n",type_ingred,date_ajout,date_valid,refer,Nomb_ingred)!=EOF);
	     {
if ( strcmp(Nomb_ingred,comparel)==0 || strcmp(Nomb_ingred,comparekg)==0 || strcmp(Nomb_ingred,compareuni)==0)
	{
strcpy(ingred.type_ingred,type_ingred);


fclose(f);



}
return ingred;
}
}


}
void afficher1_Aziz(GtkWidget *liste,stock ingred)
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	 char type_ingred[50]; 
char Nomb_ingred[10];
char date_valid[50];
char date_ajout[50];
char refer[10];
store= NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);  




if(store==NULL)
{
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes(" DateA",renderer,"text",DATEA,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes(" DateV",renderer,"text",DATEV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Refer",renderer,"text",REF,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Nombre",renderer,"text",NOMBRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
 
  f=fopen("stock.txt","r");
   if (f==NULL)
   {
return;
}
else
{
f=fopen("stock.txt","a+");
gtk_list_store_append(store,&iter);
	gtk_list_store_set (store,&iter,TYPE,ingred.type_ingred,DATEA,ingred.date_ajout,DATEV,ingred.date_valid,REF,ingred.refer,NOMBRE,ingred.Nomb_ingred,-1);

    
   
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste) ,GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
}
stock cherch_type_Aziz(char type[])
{
FILE *f,*l;

stock ingred1;



  
  f=fopen("stock.txt","r");

  if(f!=NULL)
            {while(fscanf(f,"%s %s %s %s %s \n",ingred1.type_ingred,ingred1.date_ajout,ingred1.date_valid,ingred1.refer,ingred1.Nomb_ingred)!=EOF)
	     {
if (strcmp(ingred1.type_ingred,type)==0)
	{
return ingred1;
fclose(f);
}

}
}
}
stock cherch_nomb_Aziz(char nomb[])

{
FILE *f;

stock ingred1;



  
  f=fopen("stock.txt","r");

  if(f!=NULL)
            {while(fscanf(f,"%s %s %s %s %s \n",ingred1.type_ingred,ingred1.date_ajout,ingred1.date_valid,ingred1.refer,ingred1.Nomb_ingred)!=EOF)
	     {
if (strcmp(ingred1.Nomb_ingred,nomb)==0)
	{
return ingred1;
fclose(f);
}

}
}
}
stock cherch_datea_Aziz(char datea[])
{
FILE *f;

stock ingred1;



  
  f=fopen("stock.txt","r");

  if(f!=NULL)
            {while(fscanf(f,"%s %s %s %s %s \n",ingred1.type_ingred,ingred1.date_ajout,ingred1.date_valid,ingred1.refer,ingred1.Nomb_ingred)!=EOF)
	     {
if (strcmp(ingred1.date_ajout,datea)==0)
	{
return ingred1;
fclose(f);
}

}
}
}
stock cherch_datev_Aziz(char datev[])
{
FILE *f;

stock ingred1;



  
  f=fopen("stock.txt","r");

  if(f!=NULL)
            {while(fscanf(f,"%s %s %s %s %s \n",ingred1.type_ingred,ingred1.date_ajout,ingred1.date_valid,ingred1.refer,ingred1.Nomb_ingred)!=EOF)
	     {
if (strcmp(ingred1.date_valid,datev)==0)
	{
return ingred1;
fclose(f);
}

}
}
}

