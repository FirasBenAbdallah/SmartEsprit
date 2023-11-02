#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "SEW.h"
#include  "AF.h"
#include "Aziz.h"
#include "atef.h"
#include "capteur.h"


/****************************************************************************************************************/
/*********************************************//*SMART_ESPRIT_W*//***********************************************/
/****************************************************************************************************************/

/************************************************\VAR_GLOBAL_SEW\************************************************/
int Role_Smart=1;

/************************************************\WINDOW_SEW\************************************************/

//Inscription_SEW
void
on_button_inscription_SEW_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *n,*pre,*login,*pw,*ro,*existuser_sew,*existpass_sew,*inscription_sew;
FILE *f;
char nom[50],ch1[50];
char prenom[50],ch2[50];
char login1[50],ch3[50];
char passw[50],ch4[50];
char role[50],ch5[50];
int tr_sew=0,tr_sew1=0,tr_sew2=0;
f=fopen("utilisateur_w.txt","r");
n = lookup_widget(button, "entry_nom_inscription_sew") ;
pre = lookup_widget(button, "entry_prenom_inscription_sew") ;
login = lookup_widget(button, "entry_user_inscription_sew") ;
pw = lookup_widget(button, "entry_pass_inscription_sew") ;
existuser_sew = lookup_widget(button, "label_existe_user_inscription_SEW") ;
existpass_sew = lookup_widget(button, "label_existe_pass_inscription_SEW") ;
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(n)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(pre)));
strcpy(login1,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(passw,gtk_entry_get_text(GTK_ENTRY(pw)));
while(fscanf(f,"%s %s %s %s %s",ch1,ch2,ch3,ch4,ch5)!=EOF)
{
if(strcmp(ch3,login1)==0)
{
gtk_label_set_text(GTK_LABEL(existuser_sew),"*Existe déja");
tr_sew=1;
tr_sew1=1;
}
if(strcmp(ch4,passw)==0)
{
gtk_label_set_text(GTK_LABEL(existpass_sew),"*Existe déja");
tr_sew=1;
tr_sew2=2;
}
}
fclose(f);
if(Role_Smart==1){
strcpy(role,"Directeur");
}
if(Role_Smart==2){
strcpy(role,"Etudiant");
}
if(Role_Smart==3){
strcpy(role,"Technicien");
}
if(Role_Smart==4){
strcpy(role,"Agent_de_foyer");
}
if(Role_Smart==5){
strcpy(role,"Agent_de_stock");
}
if(Role_Smart==6){
strcpy(role,"Nutritionniste");
}
if(Role_Smart==7){
strcpy(role,"S.Reclamation");
}
//ouvrir le fichier
if(tr_sew1!=1){gtk_label_set_text(GTK_LABEL(existuser_sew),"");}
if(tr_sew2!=2){gtk_label_set_text(GTK_LABEL(existpass_sew),"");}
if(tr_sew==0){
ajouter_sew (nom,prenom,login1,passw,role);
inscription_sew=lookup_widget(button,"inscription_SEW");
gtk_widget_destroy(inscription_sew);
}
}


void
on_radiobutton1_inscription_SEW_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
Role_Smart=1;
}


void
on_radiobutton2_inscription_SEW_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
Role_Smart=2;
}


void
on__inscription_SEWradiobutton3_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
Role_Smart=3;
}


void
on_radiobutton4_inscription_SEW_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
Role_Smart=4;
}


void
on_radiobutton5_inscription_SEW_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
Role_Smart=5;
}


void
on_radiobutton6_inscription_SEW_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
Role_Smart=6;
}
void
on_radiobutton7_inscription_SEW_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
Role_Smart=7;
}

void
on_button_connecter_authenti_SEW_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *login_sew,*pw_sew,*Authentification_sew,*Inscription_sew,*fenetre_main,*dashboard,*windowGestionCapteurs;
char user_sew[30];
char pasw_sew[30];
int trouve_sew;
login_sew = lookup_widget(button, "entry_user_authenti_SEW") ;
pw_sew = lookup_widget(button, "entry_pass_authenti_SEW") ;

strcpy(user_sew,gtk_entry_get_text(GTK_ENTRY(login_sew)));
strcpy(pasw_sew,gtk_entry_get_text(GTK_ENTRY(pw_sew)));
trouve_sew=verifier_sew(user_sew,pasw_sew);

if(trouve_sew==2)
{
Inscription_sew=lookup_widget(button,"window_authenti_SEW");
gtk_widget_destroy(Inscription_sew);
Authentification_sew=create_window_Etudiant_SEW();
gtk_widget_show(Authentification_sew);
}
else if(trouve_sew==3)
{
Inscription_sew=lookup_widget(button,"window_authenti_SEW");
gtk_widget_destroy(Inscription_sew);
windowGestionCapteurs = create_windowGestionCapteurs ();
gtk_widget_show (windowGestionCapteurs);
}
else if(trouve_sew==4)
{
Inscription_sew=lookup_widget(button,"window_authenti_SEW");
gtk_widget_destroy(Inscription_sew);
Authentification_sew=create_principale_FBA();
gtk_widget_show(Authentification_sew);
}
else if(trouve_sew==5)
{
Inscription_sew=lookup_widget(button,"window_authenti_SEW");
gtk_widget_destroy(Inscription_sew);
fenetre_main = create_fenetre_main_Aziz ();
gtk_widget_show (fenetre_main);
}
else if(trouve_sew==6)
{
Inscription_sew=lookup_widget(button,"window_authenti_SEW");
gtk_widget_destroy(Inscription_sew);
Authentification_sew=create_window_menu_hedi();
gtk_widget_show(Authentification_sew);
}
else if(trouve_sew==7)
{
Inscription_sew=lookup_widget(button,"window_authenti_SEW");
gtk_widget_destroy(Inscription_sew);
dashboard = create_dashboard ();
gtk_widget_show (dashboard);
}
}


void
on_button_connecter_inscription_SEW_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Inscription_sew;
Inscription_sew=create_window_authenti_SEW();
gtk_widget_show(Inscription_sew);
}


void
on_button_reclamation_etudiant_sew_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dashboard,*Inscription_sew;
Inscription_sew=lookup_widget(button,"window_Etudiant_SEW");
gtk_widget_destroy(Inscription_sew);
dashboard = create_dashboard ();
gtk_widget_show (dashboard);
}

void
on_button_M_menu_Etudiant_SEW_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu_sew,*Inscription_sew;
Inscription_sew=lookup_widget(button,"window_Etudiant_SEW");
gtk_widget_destroy(Inscription_sew);
menu_sew=create_window_menu_etudiant();
gtk_widget_show(menu_sew);
}
void
on_button_retour_etudiant_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu_sew,*Inscription_sew;
Inscription_sew=lookup_widget(button,"window_menu_etudiant");
gtk_widget_destroy(Inscription_sew);
menu_sew=create_window_Etudiant_SEW();
gtk_widget_show(menu_sew);
}


void
on_button_deconnexion_Etudiant_SEW_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Authentification_sew,*Inscription_sew;
Inscription_sew=lookup_widget(button,"window_Etudiant_SEW");
gtk_widget_destroy(Inscription_sew);
Authentification_sew=create_window_authenti_SEW();
gtk_widget_show(Authentification_sew);
}




void
on_button_cncompte_authenti_SEW_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *inscription_SEW;
inscription_SEW = create_inscription_SEW ();
gtk_widget_show (inscription_SEW);
}


/****************************************************************************************************************/
/************************************************//*FIRAS_BA*//**************************************************/
/****************************************************************************************************************/
/************************************************\VAR_GLOBAL_FBA\************************************************/

GtkWidget *principale_FBA,*somme_fba;
int choix_fba,rechoix_fba=1,calculfba[5]={0,0,0,0,0},row=0;
char Nom_fba[100],Prenom_fba[100],Tel_fba[40],so[200],chambr[20],carte[20];
Etudiant E,ET;

/**********************************************\Exit_projet_fba\*************************************************/
void
on_Exit_projet_fba_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Authentification_sew,*Exit_pfba;
Exit_pfba=lookup_widget(button,"principale_FBA");
gtk_widget_destroy(Exit_pfba);
Authentification_sew=create_window_authenti_SEW();
gtk_widget_show(Authentification_sew);
}

/*************************************************\AFFICHER_FBA\*************************************************/

//button_affich_tab
void
on_button_affich_tab_fba_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fba_treeview;
fba_treeview=lookup_widget(button,"treeview_fba");
afficher_fba(fba_treeview,"etudiant_fba.txt");
}

//treeview_row_fba
void
on_treeview_fba_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* ch1;
gchar* ch2;
gchar* nai;
gchar* cat;
gchar* e;
gchar* g;
gchar* h;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path));
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&ch1,1,&ch2,2,&nai,3,&cat,4,&e,5,&g,6,&h,-1);
strcpy(Nom_fba,ch1);
strcpy(Prenom_fba,ch2);
strcpy(chambr,e);
sprintf(carte,"%d",g);
strcpy(Tel_fba,h);
row=1;
}
}


/*************************************************\AJOUTER_FBA\*************************************************/

GtkWidget *Ajouter_FBA;
//button_ajouter_tab_fba
void
on_button_ajouter_tab_fba_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
Ajouter_FBA = create_Ajouter_FBA ();
gtk_widget_show (Ajouter_FBA);
//principale=lookup_widget(button,"principale");
//gtk_widget_destroy(principale);
}

//button_ajouter_aj_fba
void
on_button_ajouter_fba_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
   
GtkWidget *nom,*prenom,*chambre,*cin,*tel,*jour,*mois,*annee,*niveau,*spc,*Carte_in,*valnom;
char x[30];
int validite=0;
nom = lookup_widget(button, "entry_nom_aj_fba") ;
strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(nom)));

prenom = lookup_widget(button, "entry_prenom_aj_fba") ;
strcpy(E.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

jour= lookup_widget(button, "spinbutton_jour_aj_fba");
E.naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

mois= lookup_widget(button, "spinbutton_mois_aj_fba");
E.naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));

annee= lookup_widget(button, "spinbutton_annee_aj_fba");
E.naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

niveau= lookup_widget(button, "combobox_niveau_aj_fba");
strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau)));
E.niveau.niv=atoi(x);

spc= lookup_widget(button, "combobox_spc_aj_fba");
strcpy(E.niveau.spec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(spc)));

chambre= lookup_widget(button, "entry_chambre_aj_fba");
strcpy(E.chambre,gtk_entry_get_text(GTK_ENTRY(chambre)));

cin= lookup_widget(button, "entry_cin_aj_fba");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(cin)));
E.CIN=atoi(x);

tel= lookup_widget(button, "entry_tel_aj_fba");
strcpy(E.tel,gtk_entry_get_text(GTK_ENTRY(tel)));


/////////////////


valnom = lookup_widget(button, "label_valid_nom_aj_fba") ; 
if (strlen(E.nom)==0)
{
gtk_label_set_text(GTK_LABEL(valnom),"invalid");}
else {
gtk_label_set_text(GTK_LABEL(valnom),"valide");
validite++;
}

//////////
valnom = lookup_widget(button, "label_valid_preno_aj_fba") ; 
if (strlen(E.prenom)==0)
{
gtk_label_set_text(GTK_LABEL(valnom),"invalid");}
else {
gtk_label_set_text(GTK_LABEL(valnom),"valide");
validite++;
}

////////
valnom = lookup_widget(button, "label_valid_chambre_aj_fba") ; 
if (strlen(E.chambre)==0)
{
gtk_label_set_text(GTK_LABEL(valnom),"invalid");}
else {
gtk_label_set_text(GTK_LABEL(valnom),"valide");
validite++;
}

/////
Carte_in = lookup_widget(button, "label_invalid_cin_aj_fba") ; 
if ((strlen(x)!=8) && (strlen(x)!=7))
{
gtk_label_set_text(GTK_LABEL(Carte_in),"invalid");}
else {
gtk_label_set_text(GTK_LABEL(Carte_in),"valide");
validite++;
}
//////
valnom = lookup_widget(button, "label_valid_tel_aj_fba") ; 
if (strlen(E.tel)==0)
{
gtk_label_set_text(GTK_LABEL(valnom),"invalid");}
else {
gtk_label_set_text(GTK_LABEL(valnom),"valide");
validite++;
}
if(validite==5){ajouter_fba(E,"etudiant_fba.txt");}
}


//button_return_ajouter_fba
void
on_button_return_ajouter_fba_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
Ajouter_FBA=lookup_widget(button,"Ajouter_FBA");
gtk_widget_destroy(Ajouter_FBA);
}


/*************************************************\MODIFIER_FBA\*************************************************/
GtkWidget *modifier_FBA,*nom,*prenom,*chambre,*tel;;
//modif_tab_fba
void
on_button_modifier_tab_fba_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
choix_fba=1;
if (row==1){
principale_FBA=lookup_widget(button,"principale_FBA");
gtk_widget_destroy(principale_FBA);
modifier_FBA = create_modifier_FBA ();
gtk_widget_show (modifier_FBA);}
}

//button_info_modif_fba
on_button_modifier_info_fba_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
//nom
nom = lookup_widget(button, "entry_modif_nom_fba") ;
gtk_entry_set_text(GTK_ENTRY(nom),Nom_fba);
//prenom
prenom = lookup_widget(button, "entry_modif_prenom_fba") ;
gtk_entry_set_text(GTK_ENTRY(prenom),Prenom_fba);
//chambre
chambre = lookup_widget(button, "entry_modif_chambre_fba") ;
gtk_entry_set_text(GTK_ENTRY(chambre),chambr);
//tel
tel = lookup_widget(button, "entry_modif_tel_fba") ;
gtk_entry_set_text(GTK_ENTRY(tel),Tel_fba);
}

                  /*---------Button_Radio_fba---------*/
//radiobutton_modif1_fba
void
on_radiobutton_modif1_fba_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix_fba=1;
}
//radiobutton_modif2_fba
void
on_radiobutton_modif2_fba_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix_fba=2;
}
//radiobutton_modif3_fba
void
on_radiobutton_modif3_fba_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix_fba=3;
}
//radiobutton_modif4_fba
void
on_radiobutton_modif4_fba_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix_fba=4;
}
//radiobutton_modif5_fba
void
on_radiobutton_modif5_fba_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix_fba=5;
}

//button_modif_enregistrer_fba
void
on_button_modif_enregistrer_fba_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
//nom
nom = lookup_widget(button, "entry_modif_nom_fba") ;
strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
//prenom
prenom = lookup_widget(button, "entry_modif_prenom_fba") ;
strcpy(E.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
//chambre
chambre = lookup_widget(button, "entry_modif_chambre_fba") ;
strcpy(E.chambre,gtk_entry_get_text(GTK_ENTRY(chambre)));
//tel
tel = lookup_widget(button, "entry_modif_tel_fba") ;
strcpy(E.tel,gtk_entry_get_text(GTK_ENTRY(tel)));
modifier_fba(choix_fba,E,carte);
}

//button_return_modifier_fba
void
on_button_return_modifier_fba_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
principale_FBA = create_principale_FBA ();
gtk_widget_show (principale_FBA);
modifier_FBA=lookup_widget(button,"modifier_FBA");
gtk_widget_destroy(modifier_FBA);
row=0;
}


/***********************************************\CHERCHER_FBA\*************************************************/
GtkWidget *carte_fba;
//button_chercher_tab_fba
void
on_button_chercher_tab_fba_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
int cn;
char entry[30]; 
remove("chercher_fba.txt");
carte_fba= lookup_widget(button, "entry_chercher_tab_fba");
if (rechoix_fba==1)
{
strcpy(entry,gtk_entry_get_text(GTK_ENTRY(carte_fba)));
chercher_fba(entry,rechoix_fba);
}
if (rechoix_fba==2)
{
strcpy(entry,gtk_entry_get_text(GTK_ENTRY(carte_fba)));
chercher_fba(entry,rechoix_fba);
}

if (rechoix_fba==3)
{
strcpy(entry,gtk_entry_get_text(GTK_ENTRY(carte_fba)));
chercher_fba(entry,rechoix_fba);
}
//appel afficher_fba
GtkWidget *treeviewfba;
treeviewfba=lookup_widget(button,"treeview_fba");
afficher_fba(treeviewfba,"chercher_fba.txt");
}

void
on_radiobutton_cher_nom_fba_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
rechoix_fba=1;
}
void
on_radiobutton_cher_cin_fba_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
rechoix_fba=2;
}
void
on_radiobutton_cher_chambre_fba_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
rechoix_fba=3;
}

/**********************************************\SUPPRIMER_FBA\*************************************************/
GtkWidget *Supprimer_FBA;
//button_supprim_tab_fba
void
on_button_supprim_tab_fba_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
if (row==1){
Supprimer_FBA = create_Supprimer_FBA ();
gtk_widget_show (Supprimer_FBA);
row=0;}
}

//OUI_fba
void
on_button_oui_supprimer_fba_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
supprimer_fba(carte);
Supprimer_FBA=lookup_widget(button,"Supprimer_FBA");
gtk_widget_destroy(Supprimer_FBA);
}

//NON_fba
void
on_button_non_supprimer_fba_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
Supprimer_FBA=lookup_widget(button,"Supprimer_FBA");
gtk_widget_destroy(Supprimer_FBA);
}



/*************************************************\CALCUL_FBA\*************************************************/
GtkWidget *calcul_FBA;
//button_calcul_tab_fba
void
on_button_calcul_tab_fba_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
calcul_FBA = create_calcul_FBA ();
gtk_widget_show (calcul_FBA);
principale_FBA=lookup_widget(button,"principale_FBA");
gtk_widget_destroy(principale_FBA);
}

                      /*---------Casse_à_Cocher_fba---------*/
//checkbutton_calcul_1_fba
void
on_checkbutton_calcul_1_fba_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calculfba[0]=1;
}
else
{calculfba[0]=0;}
}
//checkbutton_calcul_2_fba
void
on_checkbutton_calcul_2_fba_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calculfba[1]=1;
}
else
{calculfba[1]=0;}
}
//checkbutton_calcul_3_fba
void
on_checkbutton_calcul_3_fba_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calculfba[2]=1;
}
else
{calculfba[2]=0;}
}
//checkbutton_calcul_4_fba
void
on_checkbutton_calcul_4_fba_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calculfba[3]=1;}
else
{calculfba[3]=0;}
}
//checkbutton_calcul_5_fba
void
on_checkbutton_calcul_5_fba_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calculfba[4]=1;}
else
{calculfba[4]=0;}
}

//button_calcul_sum_fba
void
on_button_calcul_sum_fba_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
int sum;
somme_fba = lookup_widget(button, "label_calcul_s_fba") ;
sum=calcul_fba(calculfba,"etudiant_fba.txt");
sprintf(so,"%d",sum);
gtk_label_set_text(GTK_LABEL(somme_fba),so);
}

//button_calcul_retour_fba
void
on_button_retour_calcul_fba_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
principale_FBA = create_principale_FBA ();
gtk_widget_show (principale_FBA);
calcul_FBA=lookup_widget(button,"calcul_FBA");
gtk_widget_destroy(calcul_FBA);
}


/****************************************************************************************************************/
/********************************************//*HEDI_Louhichi*//*************************************************/
/****************************************************************************************************************/


int c_hedi[4]={0,0,0,0};
char nid_hedi[30];
char njour_hedi[30];
  char ntemps_hedi[30];
char ndemarrer_hedi[30];
  char nplat_principal_hedi[30];
  char nbreuvage_hedi[30];
  char ndessert_hedi[30];

int hedi=0;
enum{
ID,
JOUR,
TEMPS,
DEMARRER,
PLAT_PRINCIPALE,
BREUVAGE,
DESSERT,
COLUMNS



};



void  afficher_hedi(GtkWidget *liste,char txt[]){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char id_hedi[30];
char jour_hedi[30];
char temps_hedi [30];
char demarrer_hedi[30];
char plat_principal_hedi[30];
char breuvage_hedi[30];
char dessert_hedi [30];
store=NULL ;
FILE *f; 
store=gtk_tree_view_get_model(liste);
if (store==NULL){
renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" temps",renderer,"text",TEMPS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" demarrer",renderer,"text",DEMARRER,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" plat_principale",renderer,"text",PLAT_PRINCIPALE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" breuvage",renderer,"text",BREUVAGE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" dessert",renderer,"text",DESSERT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
G_TYPE_STRING,G_TYPE_STRING,-1);
if (strcmp(txt,"menu.txt")==0){


f=fopen("menu.txt","r");
if(f!=NULL){
f=fopen(txt,"a+");
   while(fscanf(f,"%s %s %s %s %s %s %s \n",id_hedi,jour_hedi,temps_hedi,demarrer_hedi,plat_principal_hedi,breuvage_hedi,dessert_hedi)!= EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,id_hedi,JOUR,jour_hedi,TEMPS,temps_hedi,DEMARRER,demarrer_hedi,PLAT_PRINCIPALE,plat_principal_hedi,BREUVAGE,breuvage_hedi,DESSERT,dessert_hedi,-1);
}
}
fclose(f);}
if( strcmp(txt,"temp.txt")==0){


f=fopen("temp.txt","r");
if(f!=NULL){
f=fopen(txt,"a+");
   while(fscanf(f,"%s %s %s %s %s %s %s \n",id_hedi,jour_hedi,temps_hedi,demarrer_hedi,plat_principal_hedi,breuvage_hedi,dessert_hedi)!= EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,id_hedi,JOUR,jour_hedi,TEMPS,temps_hedi,DEMARRER,demarrer_hedi,PLAT_PRINCIPALE,plat_principal_hedi,BREUVAGE,breuvage_hedi,DESSERT,dessert_hedi,-1);
}
}
fclose(f);}





gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);}}



void
on_button_ajouter_hedi_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *window_menu_hedi;
window_menu_hedi=lookup_widget(button,"window_menu_hedi");
gtk_widget_destroy(window_menu_hedi);
GtkWidget *window_ajouter_hedi;
  window_ajouter_hedi = create_window_ajouter_hedi ();
  gtk_widget_show (window_ajouter_hedi);}

int  choix_hedi;

on_button_comfirmer_hedi_clicked   (GtkWidget    *objet_graphique,  gpointer user_data
  )
                   
{

  char id_hedi[30];
  char jour_hedi[30];
  char temps_hedi[30];
  char demarrer_hedi[30];
  char plat_principal_hedi[30];
  char breuvage_hedi[30];
  char dessert_hedi[30];


GtkWidget* input ;

GtkWidget* output ;
char text_hedi[30];

input = lookup_widget(objet_graphique, "comboboxentry_jour_hedi") ;
strcpy(jour_hedi,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
input = lookup_widget(objet_graphique, "entry_demarrer_hedi") ;
strcpy(demarrer_hedi,gtk_entry_get_text(GTK_ENTRY(input)));
input = lookup_widget(objet_graphique, "entry_plat_hedi") ;
strcpy(plat_principal_hedi,gtk_entry_get_text(GTK_ENTRY(input)));
input = lookup_widget(objet_graphique, "entry_brev_hedi") ;
strcpy(breuvage_hedi,gtk_entry_get_text(GTK_ENTRY(input)));
input = lookup_widget(objet_graphique, "entry_dess_hedi") ;
strcpy(dessert_hedi,gtk_entry_get_text(GTK_ENTRY(input)));
input = lookup_widget(objet_graphique, "entry_id_hedi") ;
strcpy(id_hedi,gtk_entry_get_text(GTK_ENTRY(input)));
char msg_hedi[30];
int test_hedi=0;
if (choix_hedi==0)
strcpy(temps_hedi,"petit_dejuner");
else if (choix_hedi==1) 
strcpy(temps_hedi,"dejuner");
else  if (choix_hedi==2) 
strcpy(temps_hedi,"diner");
output = lookup_widget(objet_graphique, "label_jour_hedi") ; 
if (verfier(jour_hedi)==1){
strcpy(msg_hedi,"valide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);}
else {
strcpy(msg_hedi,"invalide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
test_hedi=+1;}
output = lookup_widget(objet_graphique, "label_temps_hedi") ; 
if (verfier(temps_hedi)==1){
strcpy(msg_hedi,"valide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);}
else {
strcpy(msg_hedi,"invalide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
test_hedi=+1;}
output = lookup_widget(objet_graphique, "label_demarrer_hedi") ; 
if (verfier(demarrer_hedi)==1){
strcpy(msg_hedi,"valide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);}
else {
strcpy(msg_hedi,"invalide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
test_hedi=+1;}
output = lookup_widget(objet_graphique, "label_plat_hedi") ; 
if (verfier(plat_principal_hedi)==1){
strcpy(msg_hedi,"valide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);}
else {
strcpy(msg_hedi,"invalide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
test_hedi=+1;}
output = lookup_widget(objet_graphique, "label_id_hedi") ; 
if (verfier(id_hedi)==1){
strcpy(msg_hedi,"valide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);}
else {
strcpy(msg_hedi,"invalide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
test_hedi=+1;}
output = lookup_widget(objet_graphique, "label_brev_hedi") ; 
if (verfier(breuvage_hedi)==1){
strcpy(msg_hedi,"valide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);}
else {
strcpy(msg_hedi,"invalide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
test_hedi=+1;}
output = lookup_widget(objet_graphique, "label_dess_hedi") ; 
if (verfier(dessert_hedi)==1){
strcpy(msg_hedi,"valide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);}
else {
strcpy(msg_hedi,"invalide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
test_hedi=+1;}
if (test_hedi==0){

ajouter(id_hedi,jour_hedi,temps_hedi,demarrer_hedi,plat_principal_hedi,breuvage_hedi,dessert_hedi);

output=lookup_widget(objet_graphique, "entry_id_hedi") ;
strcpy(msg_hedi,"");
gtk_entry_set_text(GTK_ENTRY(output),msg_hedi);

output=lookup_widget(objet_graphique, "entry_demarrer_hedi") ;
strcpy(msg_hedi,"");
gtk_entry_set_text(GTK_ENTRY(output),msg_hedi);
output=lookup_widget(objet_graphique, "entry_plat_hedi") ;
gtk_entry_set_text(GTK_ENTRY(output),msg_hedi);
output=lookup_widget(objet_graphique, "entry_brev_hedi") ;
gtk_entry_set_text(GTK_ENTRY(output),msg_hedi);
output=lookup_widget(objet_graphique, "entry_dess_hedi") ;
gtk_entry_set_text(GTK_ENTRY(output),msg_hedi);

output=lookup_widget(objet_graphique, "label_jour_hedi") ;
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
output=lookup_widget(objet_graphique, "label_temps_hedi") ;
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
output=lookup_widget(objet_graphique, "label_demarrer_hedi") ;
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
output=lookup_widget(objet_graphique, "label_plat_hedi") ;
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
output=lookup_widget(objet_graphique, "label_brev_hedi") ;
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
output=lookup_widget(objet_graphique, "label_dess_hedi") ;
gtk_label_set_text(GTK_LABEL(output),msg_hedi);}




}

void
on_button_act_hedi_clicked   (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *window_menu_hedi;
GtkWidget *window_ajouter_hedi;
GtkWidget *treeview1;

FILE *f;
f=fopen("menu.txt","r");

window_menu_hedi=lookup_widget(objet,"window_menu_hedi");
gtk_widget_destroy(window_menu_hedi);

  window_ajouter_hedi = create_window_ajouter_hedi ();
  gtk_widget_show (window_ajouter_hedi);
//window2=lookup_widget(objet,"window2");
gtk_widget_destroy(window_ajouter_hedi);

  window_menu_hedi = create_window_menu_hedi ();
  gtk_widget_show (window_menu_hedi);
treeview1=lookup_widget(window_menu_hedi,"treeview1");

afficher_hedi(treeview1,"menu.txt");
}






void
on_button_annuler_hedi_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
FILE *f;
f=fopen("menu.txt","r");
GtkWidget *window_modifier_hedi;
window_modifier_hedi=lookup_widget(objet,"window_modifier_hedi");
gtk_widget_destroy(window_modifier_hedi);

GtkWidget *window_supprimer_hedi;
window_supprimer_hedi=lookup_widget(objet,"window_supprimer_hedi");
gtk_widget_destroy(window_supprimer_hedi);


GtkWidget *window_ajouter_hedi;
window_ajouter_hedi=lookup_widget(objet,"window_ajouter_hedi");
gtk_widget_destroy(window_ajouter_hedi);


GtkWidget *window_menu_hedi;
  window_menu_hedi = create_window_menu_hedi ();
  gtk_widget_show (window_menu_hedi);
GtkWidget *treeview1;
treeview1=lookup_widget(window_menu_hedi,"treeview1");

afficher_hedi(treeview1,"menu.txt");}


int choix_m_hedi;
void
on_checkbutton_demarrer_hedi_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){c_hedi[0]=1;}
}


void
on_checkbutton_brev_hedi_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){c_hedi[2]=1;}
}


void
on_checkbutton_dess_hedi_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){c_hedi[3]=1;}
}


void
on_checkbutton_plat_hedi_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){c_hedi[1]=1;}
}








void
on_button12_clicked   (GtkWidget    *objet_graphique,  gpointer user_data){

//supprimer(jour,temps);

}













void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){choix_hedi=1;}
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){choix_hedi=2;}
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){choix_hedi=0;}
}


void
on_radio_din_hedi_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){choix_hedi=2;}
}


void
on_radio_dej_hedi_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){choix_hedi=1;}
}


void
on_radio_petit_hedi_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){choix_hedi=0;}
}


void
on_treeview1_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data,GtkWidget *objet)
{


GtkWidget *output ;
GtkTreeIter iter;
gchar* id_hedi;
gchar* jour_hedi;
gchar* temps_hedi;
gchar* demarrer_hedi;
gchar* plat_principale_hedi;
gchar* breuvage_hedi;
gchar* dessert_hedi;


GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model, &iter,path)){

gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id_hedi,1,&jour_hedi,2,&temps_hedi,3,&demarrer_hedi,4,&plat_principale_hedi,5,&breuvage_hedi,6,&dessert_hedi,-1);
strcpy(nid_hedi,id_hedi);
strcpy(njour_hedi,jour_hedi);
strcpy(ntemps_hedi,temps_hedi);
strcpy(ndemarrer_hedi,demarrer_hedi);
strcpy(nplat_principal_hedi,plat_principale_hedi);
strcpy(nbreuvage_hedi,breuvage_hedi);
strcpy(ndessert_hedi,dessert_hedi);
hedi=1;
FILE *f;
f=fopen("menu.txt","r");
afficher_hedi(treeview,"menu.txt");
}


}





void
on_button_supprimer_hedi_clicked                     (GtkWidget    *objet ,
                                        gpointer         user_data)
{
if(hedi==1){
//supprimer(nid_hedi,njour_hedi,ntemps_hedi);
GtkWidget *window_menu_hedi;

window_menu_hedi=lookup_widget(objet,"window_menu_hedi");
//gtk_widget_destroy(window_menu_hedi);
GtkWidget *window_supprimer_hedi;
  window_supprimer_hedi = create_window_supprimer_hedi ();
  gtk_widget_show (window_supprimer_hedi);


/*
GtkWidget *treeview1;
treeview1=lookup_widget(window_menu_hedi,"treeview1");

afficher_hedi(treeview1);*/



hedi=0;
}

}



void
on_button_quitter_hedi_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Authentification_sew,*Exit_hedi;
Exit_hedi=lookup_widget(button,"window_menu_hedi");
gtk_widget_destroy(Exit_hedi);
Authentification_sew=create_window_authenti_SEW();
gtk_widget_show(Authentification_sew);
}


void
on_button_rechercher_hedi_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{



GtkWidget* input ;
char idd[30];
input = lookup_widget(objet_graphique, "entry_recherche_hedi") ;
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(input)));
 char id_hedi[30];
  char jour_hedi[30];
  char temps_hedi[30];
  char demarrer_hedi[30];
  char plat_principal_hedi[30];
  char breuvage_hedi[30];
  char dessert_hedi[30];
GtkWidget *window_menu_hedi;
 

window_menu_hedi=lookup_widget(objet_graphique,"window_menu_hedi");
gtk_widget_destroy(window_menu_hedi);






 



//afficher_hedi(treeview1,"/home/hedi/Projets/projet6/src/temp.txt");







int i=0;
char mm[30];
int test =0;
  
FILE* f;
FILE* t ;
  f=fopen("menu.txt","r+");
t=fopen("temp.txt","w");

if(f!=NULL)
 {
   while(fscanf(f,"%s %s %s %s %s %s %s \n",id_hedi,jour_hedi,temps_hedi,demarrer_hedi,plat_principal_hedi,breuvage_hedi,dessert_hedi)!= EOF)
{
   
    if(t!=NULL){
            


       if (strcmp(idd,id_hedi)==0)  
        {
     
         fprintf(t,"%s %s %s %s %s %s %s",id_hedi,jour_hedi,temps_hedi,demarrer_hedi,plat_principal_hedi,breuvage_hedi,dessert_hedi);



fclose(t);
}}}
fclose(f);
}
//afficher_hedi(treeview1,"/home/hedi/Projets/projet6/src/temp.txt");



window_menu_hedi = create_window_menu_hedi ();
GtkWidget *treeview1;
treeview1=lookup_widget(window_menu_hedi,"treeview1");
 
 
 


afficher_hedi(treeview1,"temp.txt");

gtk_widget_show (window_menu_hedi);
}
void
on_button_connecter_hedi_clicked                    (GtkWidget
       *objet,
                                        gpointer         user_data)
{
GtkWidget* input ;
char user_hedi[30];
char pass_hedi [30];

input = lookup_widget(objet, "entry_user") ;
strcpy(user_hedi,gtk_entry_get_text(GTK_ENTRY(input)));
input = lookup_widget(objet, "entry_pass") ;
strcpy(pass_hedi,gtk_entry_get_text(GTK_ENTRY(input)));
if (verfier_h(user_hedi,pass_hedi)==1){

GtkWidget *window_connexion_hedi;
window_connexion_hedi=lookup_widget(objet,"window_connexion_hedi");
gtk_widget_destroy(window_connexion_hedi);




GtkWidget *window_menu_hedi;
  window_menu_hedi = create_window_menu_hedi ();
  gtk_widget_show (window_menu_hedi);
GtkWidget *treeview1;
treeview1=lookup_widget(window_menu_hedi,"treeview1");
FILE *f;
f=fopen("menu.txt","r");
afficher_hedi(treeview1,"menu.txt");
}


}



void
on_button_mod_hedi_clicked             (GtkWidget    *objet_graphique,  gpointer user_data)
{
 char id_hedi[30];
 char jour_hedi[30];
  char temps_hedi[30];
  char demarrer_hedi[30];
  char plat_principal_hedi[30];
  char breuvage_hedi[30];
  char dessert_hedi[30];


GtkWidget* input ;

GtkWidget* output ;
char text_hedi[30];
/*input = lookup_widget(objet_graphique, "entry_m_id_hedi") ;
strcpy(id_hedi,gtk_entry_get_text(GTK_ENTRY(input)));*/

input = lookup_widget(objet_graphique, "entry_m_demarrer_hedi") ;
strcpy(demarrer_hedi,gtk_entry_get_text(GTK_ENTRY(input)));




input = lookup_widget(objet_graphique, "entry_m_plat_hedi") ;
strcpy(plat_principal_hedi,gtk_entry_get_text(GTK_ENTRY(input)));


input = lookup_widget(objet_graphique, "entry_m_brev_hedi") ;
strcpy(breuvage_hedi,gtk_entry_get_text(GTK_ENTRY(input)));


input = lookup_widget(objet_graphique, "entry_m_dess_hedi") ;
strcpy(dessert_hedi,gtk_entry_get_text(GTK_ENTRY(input)));

char msg_hedi[30];
int test_hedi=0;
/*if (choix_m==0)
strcpy(temps,"petit_dejuner");
else if (choix_m==1) 
strcpy(temps,"dejuner");
else if(choix_m==2)
strcpy(temps,"diner");
output = lookup_widget(objet_graphique, "label49") ; 
/*if (verfier_j(jour)==1)
{
strcpy(msg,"valide");
gtk_label_set_text(GTK_LABEL(output),msg);}
else {
strcpy(msg,"introuvable");
gtk_label_set_text(GTK_LABEL(output),msg);
test=+1;}*/
//output = lookup_widget(objet_graphique, "label50") ; 
/*if (verfier_t(temps,jour)==1){
strcpy(msg,"valide");
gtk_label_set_text(GTK_LABEL(output),msg);}
else {
strcpy(msg,"introuvable");
gtk_label_set_text(GTK_LABEL(output),msg);
test=+1;}*/
output = lookup_widget(objet_graphique, "label_m_demarrer_hedi") ; 
if (verfier(demarrer_hedi)==1){
strcpy(msg_hedi,"valide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);}
else {
strcpy(msg_hedi,"invalide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
test_hedi+=1;}
output = lookup_widget(objet_graphique, "label_m_plat_hedi") ; 
if (verfier(plat_principal_hedi)==1){
strcpy(msg_hedi,"valide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);}
else {
strcpy(msg_hedi,"invalide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
test_hedi+=1;}
output = lookup_widget(objet_graphique, "label_m_brev_hedi") ; 
if (verfier(breuvage_hedi)==1){
strcpy(msg_hedi,"valide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);}
else {
strcpy(msg_hedi,"invalide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
test_hedi+=1;}
output = lookup_widget(objet_graphique, "label_m_dess_hedi") ; 
if (verfier(dessert_hedi)==1){
strcpy(msg_hedi,"valide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);}
else {
strcpy(msg_hedi,"invalide");
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
test_hedi=+1;}


if (test_hedi==0){
GtkWidget *window_modifier_hedi;
window_modifier_hedi=lookup_widget(objet_graphique,"window_modifier_hedi");
gtk_widget_destroy(window_modifier_hedi);


GtkWidget *window_menu_hedi;
  window_menu_hedi = create_window_menu_hedi ();
  gtk_widget_show (window_menu_hedi);
GtkWidget *treeview1;
treeview1=lookup_widget(window_menu_hedi,"treeview1");
FILE *f;
f=fopen(".txt","r");
afficher_hedi(treeview1,"menu.txt");

modifier(nid_hedi,njour_hedi,ntemps_hedi,demarrer_hedi,plat_principal_hedi,breuvage_hedi,dessert_hedi);

output=lookup_widget(objet_graphique, "entry_m_demarrer_hedi") ;
strcpy(msg_hedi,"");
gtk_entry_set_text(GTK_ENTRY(output),msg_hedi);
output=lookup_widget(objet_graphique, "entry_m_plat_hedi") ;
gtk_entry_set_text(GTK_ENTRY(output),msg_hedi);
output=lookup_widget(objet_graphique, "entry_m_brev_hedi") ;
gtk_entry_set_text(GTK_ENTRY(output),msg_hedi);
output=lookup_widget(objet_graphique, "entry_m_dess_hedi") ;
gtk_entry_set_text(GTK_ENTRY(output),msg_hedi);




output=lookup_widget(objet_graphique, "label_m_demarrer_hedi") ;
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
output=lookup_widget(objet_graphique, "label_m_plat_hedi") ;
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
output=lookup_widget(objet_graphique, "label_m_brev_hedi") ;
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
output=lookup_widget(objet_graphique, "label_m_dess_hedi") ;
gtk_label_set_text(GTK_LABEL(output),msg_hedi);
//GtkWidget *window_modifier_hedi;
//window_modifier_hedi=lookup_widget(objet_graphique,"window_modifier_hedi");
//gtk_widget_destroy(window_modifier_hedi);




//GtkWidget *window_menu_hedi;
//window_menu_hedi=lookup_widget(objet_graphique,"window_menu_hedi");
//window_menu_hedi = create_window_menu_hedi ();
// gtk_widget_show (window_menu_hedi);
//GtkWidget *treeview1;
//treeview1=lookup_widget(window1,"treeview1");

//afficher(treeview1);
}
}
void
on_button_modifier_hedi_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
if (hedi==1){
GtkWidget *window_menu_hedi;
GtkWidget *output;
GtkWidget *input;
window_menu_hedi=lookup_widget(objet,"window_menu_hedi");
gtk_widget_destroy(window_menu_hedi);
GtkWidget *window_modifier_hedi;
  window_modifier_hedi = create_window_modifier_hedi ();
  gtk_widget_show (window_modifier_hedi);
/*
output=lookup_widget(objet, "label63") ;

gtk_label_set_text(GTK_LABEL(output),ndemarrer_hedi);
output=lookup_widget(objet, "label64") ;

gtk_label_set_text(GTK_LABEL(output),nplat_principal_hedi);
output=lookup_widget(objet, "label65") ;
gtk_label_set_text(GTK_LABEL(output),nbreuvage_hedi);
output=lookup_widget(objet, "label66") ;


gtk_label_set_text(GTK_LABEL(output),ndessert_hedi);*/



//GtkWidget *treeview1;
//treeview1=lookup_widget(window1,"treeview1");

hedi=0;
}
}





void
on_button_annuller2_hedi_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_modifier_hedi;
window_modifier_hedi=lookup_widget(objet,"window_modifier_hedi");
gtk_widget_destroy(window_modifier_hedi);


GtkWidget *window_menu_hedi;
  window_menu_hedi = create_window_menu_hedi ();
  gtk_widget_show (window_menu_hedi);
GtkWidget *treeview1;
treeview1=lookup_widget(window_menu_hedi,"treeview1");
FILE *f;
f=fopen(".txt","r");
afficher_hedi(treeview1,".txt");
}



void
on_button_afficher_hedi_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_menu_hedi;
window_menu_hedi=lookup_widget(objet,"window_menu_hedi");
gtk_widget_destroy(window_menu_hedi);
GtkWidget *window_afficher_hedi;
 window_afficher_hedi = create_window_afficher_hedi ();
  gtk_widget_show (window_afficher_hedi);
}




void
on_button_retour_hedi_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_afficher_hedi;
window_afficher_hedi=lookup_widget(objet,"window_afficher_hedi");
gtk_widget_destroy(window_afficher_hedi);


GtkWidget *window_menu_hedi;
  window_menu_hedi = create_window_menu_hedi ();
  gtk_widget_show (window_menu_hedi);
GtkWidget *treeview1;
treeview1=lookup_widget(window_menu_hedi,"treeview1");
FILE *f;
f=fopen("menu.txt","r");
afficher_hedi(treeview1,"menu.txt");
}


void
on_button13_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *output;
GtkWidget *input;
output=lookup_widget(objet, "label63") ;

gtk_label_set_text(GTK_LABEL(output),ndemarrer_hedi);
output=lookup_widget(objet, "label64") ;

gtk_label_set_text(GTK_LABEL(output),nplat_principal_hedi);
output=lookup_widget(objet, "label65") ;
gtk_label_set_text(GTK_LABEL(output),nbreuvage_hedi);
output=lookup_widget(objet, "label66") ;


gtk_label_set_text(GTK_LABEL(output),ndessert_hedi);

input = lookup_widget(objet, "entry_m_demarrer_hedi") ;
gtk_entry_set_text(GTK_ENTRY(input),ndemarrer_hedi);
input = lookup_widget(objet, "entry_m_plat_hedi") ;
gtk_entry_set_text(GTK_ENTRY(input),nplat_principal_hedi);
input = lookup_widget(objet, "entry_m_brev_hedi") ;
gtk_entry_set_text(GTK_ENTRY(input),nbreuvage_hedi);
input = lookup_widget(objet, "entry_m_dess_hedi") ;
gtk_entry_set_text(GTK_ENTRY(input),ndessert_hedi);

}








void
on_button_supp_hedi_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
supprimer(nid_hedi,njour_hedi,ntemps_hedi);
GtkWidget *window_supprimer_hedi;
window_supprimer_hedi=lookup_widget(objet,"window_supprimer_hedi");
gtk_widget_destroy(window_supprimer_hedi);
}
void
on_button_annuler0_hedi_clicked        (GtkWidget       *objet,
                                        gpointer         user_data){

GtkWidget *window_supprimer_hedi;
window_supprimer_hedi=lookup_widget(objet,"window_supprimer_hedi");
gtk_widget_destroy(window_supprimer_hedi);


}
int est[3]={0,0,0};
void
on_checkbutton_mpd_hedi_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
est[0]=1;
}


void
on_checkbutton_mdi_hedi_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
est[2]=1;
}


void
on_checkbutton_md_hedi_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
est[1]=1;
}


void
on_button_valider_hedi_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget* output ;

int s1,s2,s3;
int j;
bon b;
float vv[30];

bon dd [300];
char xt[10];
char xj[10];
int jour;
int temps;
float val ;
FILE* f;
int k=0;
  f=fopen("dechets.txt","r");
int i;
 if(f!=NULL){

  while(fscanf(f,"%d %d %f \n",&jour,&temps,&val)!=EOF){
 vv[i]=val;

i+=1;}

fclose(f);}

float  min1=vv[0];
do{
if (min1>vv[k+3])  
  {
min1=vv[k+3];}
k+=3;}while(k!=18);

   for ( j=0;j<21;j++){
        if (vv[j]==min1){s1=j;}}
float  min2=vv[1];
k=1;
do{
if (min2>vv[k+3])  
  {
min2=vv[k+3];}
k+=3;}while(k!=19);

   for ( j=0;j<21;j++){
        if (vv[j]==min2){s2=j;}}

float  min3=vv[2];
k=2;
do{
if (min3>vv[k+3])  
  {
min3=vv[k+3];}
k+=3;}while(k!=20);

   for ( j=0;j<21;j++){
        if (vv[j]==min3){s3=j;}}
char chaine_1 [50];
char chaine_2 [50];
char chaine_3 [50];
char id [30];  
char jour0[30] ;
char temps0[30];
char demarrer0[30];
char plat_principal0[30];
char breuvage0[30];
char dessert0[30];
FILE* t;
t=fopen("menu.txt","r+");
int c=0;
if(t!=NULL){
do{
fscanf(t,"%s %s %s %s %s %s %s \n",id,jour0,temps0,demarrer0,plat_principal0,breuvage0,dessert0)!= EOF;
c+=1;}
while (c<s1+1);
fclose(t);
}
if (est[0]==1){
strcpy(chaine_1,demarrer0);
strcat(chaine_1," ");
strcat(chaine_1,plat_principal0);
strcat(chaine_1," ");
strcat(chaine_1,breuvage0);
strcat(chaine_1," ");
strcat(chaine_1,dessert0);
output=lookup_widget(objet, "label_mpd_hedi") ;
gtk_label_set_text(GTK_LABEL(output),chaine_1);
est[0]=0;
}
c=0;
t=fopen("menu.txt","r+");
if(t!=NULL){
do{
fscanf(t,"%s %s %s %s %s %s %s \n",id,jour0,temps0,demarrer0,plat_principal0,breuvage0,dessert0)!= EOF;
c+=1;}
while (c<s2+1);
fclose(t);
}
if (est[1]==1){
strcpy(chaine_2,demarrer0);
strcat(chaine_2," ");
strcat(chaine_2,plat_principal0);
strcat(chaine_2," ");
strcat(chaine_2,breuvage0);
strcat(chaine_2," ");
strcat(chaine_2,dessert0);
output=lookup_widget(objet, "label_md_hedi") ;
gtk_label_set_text(GTK_LABEL(output),chaine_2);
est[1]=0;
}
c=0;
t=fopen("menu.txt","r+");
if(t!=NULL){
do{
fscanf(t,"%s %s %s %s %s %s %s \n",id,jour0,temps0,demarrer0,plat_principal0,breuvage0,dessert0)!= EOF;
c+=1;}
while (c<s3+1);
fclose(t);
}
if (est[2]==1){
strcpy(chaine_3,demarrer0);
strcat(chaine_3," ");
strcat(chaine_3,plat_principal0);
strcat(chaine_3," ");
strcat(chaine_3,breuvage0);
strcat(chaine_3," ");
strcat(chaine_3,dessert0);
output=lookup_widget(objet, "label_mdi_hedi") ;
gtk_label_set_text(GTK_LABEL(output),chaine_3);
est[2]=0;
}
est[0]=0;
est[1]=0;
est[2]=0;
}



/****************************************************************************************************************/
/*********************************************//*AZIZ_TAKTAK*//**************************************************/
/****************************************************************************************************************/

int unite_Aziz=1;
void
on_Exit_projet_aziz_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_main,*Exit_paziz;
Exit_paziz=lookup_widget(button,"fenetre_main_Aziz");
gtk_widget_destroy(Exit_paziz);
fenetre_main = create_window_authenti_SEW ();
gtk_widget_show (fenetre_main);
}

void
on_Butt_ajouter_Aziz_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)
{ stock ingred;

GtkWidget *input1, *input2, *input3,*input4,*input5;
GtkWidget *fenetre_ajout;

fenetre_ajout=lookup_widget(objet,"fenetre_ajout_Aziz");

input1=lookup_widget(objet,"txt_type_ingred_Aziz");
input2=lookup_widget(objet,"txt_date_ajout_Aziz");
input3=lookup_widget(objet,"txt_date_valid_Aziz");
input4=lookup_widget(objet,"txt_reference_Aziz");
input5=lookup_widget(objet,"txt_nomb_ingred_Aziz");


strcpy(ingred.type_ingred,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(ingred.date_ajout,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(ingred.date_valid,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(ingred.refer,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(ingred.Nomb_ingred,gtk_entry_get_text(GTK_ENTRY(input5)));

ajouter_Aziz(ingred,unite_Aziz);
}





void
on_butt_return_Aziz_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{ GtkWidget *fenetre_main, *fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
gtk_widget_destroy(fenetre_afficher);
fenetre_main=create_fenetre_main_Aziz();
gtk_widget_show(fenetre_main);

}




stock ingred2;
void
on_treeview1_row_activated_Aziz            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
					GtkWidget       *objet,	
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *type;
gchar *datea;
gchar *datev;
gchar *refer;
gchar *nombre;
stock ingred;



GtkWidget *fenetre_main;
GtkWidget *fenetre_recherche;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model, &iter, path)) 
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &type, 1, &datea, 2, &datev, 3, &refer, 4, &nombre, -1);
strcpy(ingred.type_ingred,type);
strcpy(ingred.date_ajout,datea);
strcpy(ingred.date_valid,datev);
strcpy(ingred.Nomb_ingred,nombre);
strcpy(ingred.refer,refer);
strcpy(ingred2.type_ingred,type);
strcpy(ingred2.date_ajout,datea);
strcpy(ingred2.date_valid,datev);
strcpy(ingred2.Nomb_ingred,refer);
strcpy(ingred2.refer,nombre);

fenetre_recherche=create_fenetre_recherche_Aziz();
gtk_widget_show(fenetre_recherche);

}


}








void
on_Return_ajout_clicked_Aziz               (GtkWidget      *objet,
                                        gpointer         user_data)
{                                                                     
 GtkWidget *fenetre_recherche, *fenetre_main;
fenetre_recherche=lookup_widget(objet,"fenetre_recherche_Aziz");
gtk_widget_destroy(fenetre_recherche);
fenetre_main=create_fenetre_main_Aziz();
gtk_widget_show(fenetre_main);


                                                                        //recherche -->ajouter
                                                                          
}


void
on_return_afficher_clicked_Aziz            (GtkWidget       *objet,
                                        gpointer         user_data)  //recherche --> ajouter
								     //ruptre -->recherche								
{
 GtkWidget *fenetre_rupture, *fenetre_main;
fenetre_rupture=lookup_widget(objet,"fenetre_rupture_Aziz");
gtk_widget_destroy(fenetre_rupture);
fenetre_main=create_fenetre_main_Aziz();
gtk_widget_show(fenetre_main);

}




void
on_affich_rupture_clicked_Aziz              (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *output ;
stock ingred;
int trouve;
output=lookup_widget(objet,"label28_Aziz");

ingred=rupture_Aziz();

gtk_label_set_text(GTK_LABEL(output),ingred.type_ingred);



}
void
on_butt_redirect_ajouter_clicked_Aziz       (GtkWidget      *objet,
                                        gpointer         user_data) //afficher --> rupture 
                                                                    //main --> ajouter
{
GtkWidget *fenetre_ajouter, *fenetre_main;
fenetre_main=lookup_widget(objet,"fenetre_main_Aziz");
gtk_widget_destroy(fenetre_main);
fenetre_ajouter=create_fenetre_ajout_Aziz();
gtk_widget_show(fenetre_ajouter);


}




void
on_butt_redirect_rech_clicked          (GtkWidget      *objet,
                                        gpointer         user_data) //main -->recherche
{GtkWidget *fenetre_recherche, *fenetre_main;
fenetre_main=lookup_widget(objet,"fenetre_main_Aziz");
gtk_widget_destroy(fenetre_main);
fenetre_recherche=create_fenetre_recherche_Aziz();
gtk_widget_show(fenetre_recherche);


}


void
on_Return_aj_Aziz_main_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter, *fenetre_main;
fenetre_ajouter=lookup_widget(objet,"fenetre_ajout_Aziz");
gtk_widget_destroy(fenetre_ajouter);
fenetre_main=create_fenetre_main_Aziz();
gtk_widget_show(fenetre_main);

}


void
on_redirect_main_rup_clicked_Aziz           (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_rupture, *fenetre_main;
fenetre_main=lookup_widget(objet,"fenetre_main_Aziz");
gtk_widget_destroy(fenetre_main);
fenetre_rupture=create_fenetre_rupture_Aziz();
gtk_widget_show(fenetre_rupture);

}


void
on_rbutt_lit_toggled_Aziz                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{ if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
unite_Aziz=1;

}


void
on_rbutt_kg_toggled_Aziz                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
unite_Aziz=2;
}


void
on_rbutt_unite_toggled_Aziz                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
unite_Aziz=3;
}

int choix_Aziz[]={0,0,0,0};
void
on_Nombre_checkb_toggled_Aziz               (GtkToggleButton *togglebutton, //nombre
                                        gpointer         user_data)
{ if(gtk_toggle_button_get_active(togglebutton))
{ choix_Aziz[0]=1;}

}


void
on_datev_checkb_toggled_Aziz                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton))
{ choix_Aziz[1]=1;}


}


void
on_datea_checkb_toggled_Aziz                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton))
{ choix_Aziz[2]=1;}


}


void
on_Type_checkb_toggled_Aziz                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton))
{ choix_Aziz[3]=1;}


}

void
on_Save_Aziz_butt_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{ char ref[20];

GtkWidget *input,*input0,*input1,*input2,*input3;
GtkWidget *nombre;



input=lookup_widget(objet,"ref_search_Aziz");
input0=lookup_widget(objet,"modif_nombre_Aziz");
input1=lookup_widget(objet,"modif_datev_Aziz");
input2=lookup_widget(objet,"modif_datea_Aziz");
input3=lookup_widget(objet,"modif_type_Aziz");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input)));
stock ingred1;
strcpy(ingred1.refer,ref);
strcpy(ingred1.Nomb_ingred,gtk_entry_get_text(GTK_ENTRY(input0)));
strcpy(ingred1.date_valid,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(ingred1.date_ajout,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(ingred1.type_ingred,gtk_entry_get_text(GTK_ENTRY(input3)));


modifier_Aziz(ref,choix_Aziz,ingred1);


}


void
on_Afficher_clicked_Aziz                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_main;
GtkWidget *treeview1;
fenetre_main=lookup_widget(objet,"fenetre_main_Aziz");
treeview1=lookup_widget(fenetre_main,"treeview1_Aziz");
afficher_Aziz(treeview1);


}





void
on_afficher_clicked_Aziz                    (GtkWidget       *objet,
                                        gpointer         user_data)
{ GtkWidget *input1,*input2,*input3,*input4,*input5;

input1=lookup_widget(objet,"modif_nombre_Aziz");
input2=lookup_widget(objet,"modif_type_Aziz");
input3=lookup_widget(objet,"modif_datev_Aziz");
input4=lookup_widget(objet,"modif_datea_Aziz");
input5=lookup_widget(objet,"ref_search_Aziz");
gtk_entry_set_text(GTK_ENTRY(input1),ingred2.Nomb_ingred);
gtk_entry_set_text(GTK_ENTRY(input2),ingred2.type_ingred);
gtk_entry_set_text(GTK_ENTRY(input3),ingred2.date_valid);
gtk_entry_set_text(GTK_ENTRY(input4),ingred2.date_ajout);
gtk_entry_set_text(GTK_ENTRY(input5),ingred2.refer);

}


void
on_search_comb_clicked_Aziz                 (GtkWidget       *objet,
                                        gpointer         user_data)
{ GtkWidget *Combobox;
 GtkWidget *input;
GtkWidget *treeview1;
GtkWidget *fenetre_main;
fenetre_main=lookup_widget(objet,"fenetre_main_Aziz");
treeview1=lookup_widget(fenetre_main,"treeview1_Aziz");
stock ingred;
input=lookup_widget(objet,"search_trig_Aziz");

char type[20];
char nombre[20];
char datea[20];
char datev[20];
Combobox=lookup_widget(objet,"combobox2_Aziz");

if (strcmp("Type",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox)))==0)
{strcpy(type,gtk_entry_get_text(GTK_ENTRY(input))); 
ingred=cherch_type_Aziz(type);
afficher1_Aziz(treeview1,ingred);
}
if(strcmp("Nombre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox)))==0)
{strcpy(nombre,gtk_entry_get_text(GTK_ENTRY(input))); 
ingred=cherch_nomb_Aziz(nombre);
afficher1_Aziz(treeview1,ingred);
}
if(strcmp("Date d'ajout",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox)))==0)
{strcpy(datea,gtk_entry_get_text(GTK_ENTRY(input))); 
ingred=cherch_datea_Aziz(datea);
afficher1_Aziz(treeview1,ingred);
}
if(strcmp("Date de validite",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox)))==0)
{
strcpy(datev,gtk_entry_get_text(GTK_ENTRY(input))); 
ingred=cherch_type_Aziz(datev);
afficher1_Aziz(treeview1,ingred);
}
}


void
on_Refresh_butt_clicked_Aziz                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_main;
fenetre_main=lookup_widget(objet,"fenetre_main_Aziz");
gtk_widget_destroy(fenetre_main);
fenetre_main=create_fenetre_main_Aziz();
gtk_widget_show(fenetre_main);

}


void
on_Delete_butt_clicked_Aziz                 (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *fenetre_suppr;
fenetre_suppr=lookup_widget(objet,"fenetre_suppr_Aziz"); 
supprimer_Aziz(ingred2);
fenetre_suppr=create_fenetre_suppr_Aziz();
gtk_widget_show(fenetre_suppr);



}


void
on_Return_main_clicked_Aziz                 (GtkWidget      *objet,
                                        gpointer         user_data)
{ GtkWidget *fenetre_main, *fenetre_suppr,*fenetre_recherche;
//fenetre_main=lookup_widget(objet,"fenetre_main_Aziz");
fenetre_suppr=lookup_widget(objet,"fenetre_suppr_Aziz");
fenetre_recherche=lookup_widget(objet,"fenetre_recherche_Aziz");
gtk_widget_destroy(fenetre_suppr);
gtk_widget_destroy(fenetre_recherche);
fenetre_main=create_fenetre_main_Aziz();
gtk_widget_show(fenetre_main);

}

/****************************************************************************************************************/
/***********************************************//*ATEF_HAREB*//*************************************************/
/****************************************************************************************************************/
void
on_Exit_projet_atef_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dashboard,*Exit_patef;
Exit_patef=lookup_widget(button,"dashboard");
gtk_widget_destroy(Exit_patef);
dashboard = create_window_authenti_SEW ();
gtk_widget_show (dashboard);
}
void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod, *dashboard;
dashboard=lookup_widget(objet,"dashboard");
mod=lookup_widget(objet,"mod");
mod=create_mod();
gtk_widget_show(mod);
}


void
on_button3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af;
//af=lookup_widget(objet,"af");
af=create_af();
gtk_widget_show(af);
treeview=lookup_widget(af,"treeview");
afficher_atef(treeview,"reclamations.txt");
}


void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *pInfo;
char str[1000], ch[1000]="";
strcpy(ch,plus_reclame("reclamations.txt"));
sprintf(str,"%s",ch);
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,str);
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}


void
on_button_mod_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *mod1, *mod2, *mod3, *pInfo, *mod4, *r1, *r2, *r3, *r4, *r5, *r6;
reclam u;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
r1=lookup_widget(objet,"r1");
r2=lookup_widget(objet,"r2");
r3=lookup_widget(objet,"r3");
r4=lookup_widget(objet,"r4");
r5=lookup_widget(objet,"r5");
r6=lookup_widget(objet,"r6");
u.id=atoi(gtk_entry_get_text(GTK_ENTRY(mod1)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(mod2)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(mod3)));
strcpy(u.classe,gtk_entry_get_text(GTK_ENTRY(mod4)));
u.service=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(r1))?0:gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(r2))?1:gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(r3))?2:gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(r4))?3:gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(r5))?4:5;
modifier_atef(u,"reclamations.txt");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Réclamation modifiée avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}

}


void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *pInfo, *mod4, *r1, *r2, *r3, *r4, *r5, *r6;
reclam p;
int a=0, id;
FILE *f;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
r1=lookup_widget(objet,"r1");
r2=lookup_widget(objet,"r2");
r3=lookup_widget(objet,"r3");
r4=lookup_widget(objet,"r4");
r5=lookup_widget(objet,"r5");
r6=lookup_widget(objet,"r6");
id = atoi(gtk_entry_get_text(GTK_ENTRY(mod1)));
f = fopen("reclamations.txt","r");
if(f!=NULL){
while(fscanf(f,"%d %s %s %s %d\n",&(p.id),p.prenom,p.nom,p.classe,&(p.service))!=EOF)
	{
		if(p.id==id){
			a=1;
			break;
                 }
	}
fclose(f);
}
if(a==1){
gtk_entry_set_text(GTK_ENTRY(mod2),p.prenom);
gtk_entry_set_text(GTK_ENTRY(mod3),p.nom);
gtk_entry_set_text(GTK_ENTRY(mod4),p.classe);
p.service==0?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r1),TRUE):p.service==1?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r2),TRUE):p.service==2?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r3),TRUE):p.service==3?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r4),TRUE):p.service==4?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r5),TRUE):gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r6),TRUE);
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Réclamation introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_button_af_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af;
af=lookup_widget(objet,"af");
gtk_widget_destroy(af);
af=lookup_widget(objet,"af");
af=create_af();
gtk_widget_show(af);
treeview=lookup_widget(af,"treeview");
afficher_atef(treeview,"reclamations.txt");
}


void
on_button_aj_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj1, *aj2, *aj3, *aj4, *aj5, *aj6;
reclam u;
aj1=lookup_widget(objet,"aj1");
aj2=lookup_widget(objet,"aj2");
aj3=lookup_widget(objet,"aj3");
aj4=lookup_widget(objet,"aj4");
aj5=lookup_widget(objet,"aj5");
aj6=lookup_widget(objet,"aj6");
u.id=atoi(gtk_entry_get_text(GTK_ENTRY(aj1)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(aj2)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(aj3)));
strcpy(u.classe,gtk_entry_get_text(GTK_ENTRY(aj4)));
u.service=gtk_combo_box_get_active(GTK_COMBO_BOX(aj5));
strcpy(u.desc,gtk_entry_get_text(GTK_ENTRY(aj6)));
ajouter_atef(u,"reclamations.txt");
}


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint id;
	reclam u;
	char str[100];
	GtkWidget *pInfo;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
	u.id=id;
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer cette réclamation?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
	supprimer_atef(u,"reclamations.txt");
	sprintf(str,"%d.txt",u.id);
	remove(str);
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo);
	break;
}	
}
}


void
on_buttonAtef_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj, *dashboard;
dashboard=lookup_widget(objet,"dashboard");
aj=lookup_widget(objet,"aj");
aj=create_aj();
gtk_widget_show(aj);
}

/****************************************************************************************************************/
/**********************************************//*SKANDER_SKON*//************************************************/
/****************************************************************************************************************/
void
on_Exit_projet_skander_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowGestionCapteurs,*Exit_pskander;
Exit_pskander=lookup_widget(button,"windowGestionCapteurs");
gtk_widget_destroy(Exit_pskander);
windowGestionCapteurs = create_window_authenti_SEW ();
gtk_widget_show (windowGestionCapteurs);
}

void
on_buttonAcceuilCap_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *windowAjoutCapteur;
GtkWidget *windowModifier;
GtkWidget *windowListeCapteurs;
GtkWidget *windowCapteurAlarmants;


windowModifier = lookup_widget(button, "windowModifierCapteur");
gtk_widget_destroy(windowModifier);

windowAjoutCapteur = lookup_widget(button, "windowAjoutCapteur");
gtk_widget_destroy(windowAjoutCapteur);


windowListeCapteurs = lookup_widget(button, "windowListeCapteurs");
gtk_widget_destroy(windowListeCapteurs);

windowCapteurAlarmants = lookup_widget(button,"window1");
gtk_widget_destroy(windowCapteurAlarmants);

windowMenu = create_windowGestionCapteurs();
gtk_widget_show(windowMenu);
}

void on_buttonAjoutCapteur_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAjout;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button,"windowGestionCapteurs");
gtk_widget_destroy(windowMenu);

windowAjout = lookup_widget(button,"windowAjoutCapteur");
windowAjout = create_windowAjoutCapteur();
gtk_widget_show(windowAjout);
}


void
on_buttonListeCapteurs_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *listecap;
GtkWidget *window;
listecap = create_windowListeCapteurs();
gtk_widget_show(listecap);
treeview = lookup_widget(listecap, "treeview");
afficher_capteur(treeview);
window = lookup_widget(button,"windowGestionCapteurs");
gtk_widget_destroy(window);
}


void
on_buttonSupprimeCapteur_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *windowConfirmation;
	GtkTreeSelection *selection;
        GtkTreeIter iter;
	GtkTreeModel *model;
        GtkWidget *label;
        GtkWidget* p;
   	gchar *id;
	gchar *bloc;
	gchar *type;
	gchar *valeur;
	gchar *etage;
	gchar *fonc;
	gchar *sig;
	gchar *date_installation;
	Capteur c ;
        //label=lookup_widget(objet,"label78");
        p=lookup_widget(button,"treeviewRechercher");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        (gtk_tree_selection_get_selected(selection, &model, &iter)) ;
        gtk_tree_model_get (model,&iter,0,&id,1,&valeur,2,&type,3,&date_installation,4,&etage,5,&bloc,6,&fonc,7,&sig, -1);
        gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
	supprimer_capteur(c,id,type);
	windowConfirmation = create_windowSupSucc();
	gtk_widget_show(windowConfirmation);
}


void
on_buttonModifCapteur_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowModifier;
GtkWidget *windowMenu;
GtkWidget *treeview;
windowMenu = lookup_widget(button, "windowGestionCapteurs");
gtk_widget_destroy(windowMenu);
windowModifier = create_windowModifierCapteur();
gtk_widget_show(windowModifier);
treeview = lookup_widget (windowModifier, "treeview2");
afficher_capteur(treeview);
}

int choixsk[] = {0,0,0,0,0}; 
int choix1sk[] = {0,0,0,0,0};
int choix2sk[] = {0,0}; 
int choix3sk[] = {0,0}; 
 
void
on_buttonAjouterCap_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
{
Capteur c;
Capteur r;
FILE *fp1;
int fail=0;
fp1 = fopen("capteurs.bin", "rb");



GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *windowRemplir;
GtkWidget *windowConfirmation;
GtkWidget *windowErreur;
GtkWidget *Etage;
GtkWidget *Bloc;
GtkWidget *Sig;
GtkWidget *dialog;
input1 = lookup_widget(button, "entryIdCap");
input2 = lookup_widget(button, "entry2Cap");
Jour = lookup_widget(button, "spinbuttonSkJours");
Mois = lookup_widget(button, "spinbuttonSkMois");
Annee = lookup_widget(button, "spinbuttonSkAnnees");
Etage = lookup_widget(button, "combobox1sk");
Bloc = lookup_widget(button, "combobox2sk");
Sig = lookup_widget(button, "combobox3sk");
strcpy(c.bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Bloc)));
strcpy(c.sig,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Sig)));
strcpy(c.etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Etage)));
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(input2)));







if (choix1sk[0]==1)
strcpy(c.type,"Temperature");
else if (choix1sk[1]==1)
strcpy(c.type,"Humidite");
else if (choix1sk[2]==1)
strcpy(c.type,"Debit");
else if (choix1sk[3]==1)
strcpy(c.type,"Mouvement");
else if (choix1sk[4]==1)
strcpy(c.type,"Fumee");

if (choix2sk[0]==1)
strcpy(c.fonc,"Passif");
else if (choix2sk[1]==1)
strcpy(c.fonc,"Acif");

c.date_installation.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
c.date_installation.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
c.date_installation.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));


if (  
((choix2sk[0]==1) && (choix2sk[1]==1)) || ((choix2sk[0]==0) && (choix2sk[1]==0)) || (strcmp(c.id,"")==0) || (strcmp(c.valeur,"")==0)  || ((choix1sk[0]==1) && (choix1sk[1]==1) && (choix1sk[2]==1) && (choix1sk[3]==1) && (choix1sk[4]==1)) || ( (choix1sk[0]==0) && (choix1sk[1]==0) && (choix1sk[2]==0) && (choix1sk[3]==0) && (choix1sk[4]==0)) 
) 
{
windowErreur = create_windowRemplir();
gtk_widget_show(windowErreur);
fail=1;
}


fp1 = fopen("capteurs.bin", "rb");
if(fp1==NULL)
{
	return;
}
else
{
while (fread(&r, sizeof(r), 1, fp1))
{
	if(strcmp(c.id, r.id)==0)
	{
		dialog = create_windowID();
		gtk_widget_show(dialog);
		fail = 1;
		break;
	}
}
fclose(fp1);
}



if (fail==0)
{
ajouter_capteur(c);
windowConfirmation = create_windowAjoutSucc();
gtk_widget_show(windowConfirmation);
}
}

}


char tmps[30];
void
on_buttonModifCap_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
Capteur c;
GtkWidget *input1;
GtkWidget *windowModification;
FILE *fp;
fp = fopen("temp1.bin", "rb");
input1 = lookup_widget(button, "entryIDCap");
strcpy(tmps,gtk_entry_get_text(GTK_ENTRY(input1)));
windowModification = create_ModifierCapteur();
gtk_widget_show(windowModification);

GtkWidget *output1, *output2, *output3, *output4, *output5, *output6, *output7, *output8, *output9 ;
if(fp!=NULL)
{
while (fread(&c, sizeof(c), 1, fp))
{
	output1 = lookup_widget(windowModification, "entryMOdifierIdCap");
	gtk_entry_set_text(GTK_ENTRY(output1), c.id);

	output2 = lookup_widget(windowModification, "entryModifierValeurCap");
	gtk_entry_set_text(GTK_ENTRY(output2), c.valeur);

	output3 = lookup_widget(windowModification, "entryModifierEtageCap");
	gtk_entry_set_text(GTK_ENTRY(output3), c.etage);

	output4 = lookup_widget(windowModification, "spinbuttonJours");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output4), c.date_installation.jour);


	output5 = lookup_widget(windowModification, "spinbuttonMois");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5), c.date_installation.mois);


	output6 = lookup_widget(windowModification, "spinbuttonAnnees");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6), c.date_installation.annee);

	output7 = lookup_widget(windowModification, "combobox4Cap");
	gtk_entry_set_text(GTK_ENTRY(output7), c.bloc);

	output8 = lookup_widget(windowModification, "combobox5Cap");
	gtk_entry_set_text(GTK_ENTRY(output8), c.sig);

	

}
}
fclose(fp);
}





void
on_buttonConfirmerModifCap_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
Capteur c;
FILE *fp1;
fp1 = fopen("capteurs.bin", "rb");


GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *windowErreur;
GtkWidget *windowSuccees;
GtkWidget *ModifierCapteur;
GtkWidget *Bloc;
GtkWidget *Sig;

Bloc = lookup_widget(button, "combobox4Cap");
Sig = lookup_widget(button, "combobox5Cap");
input1 = lookup_widget(button, "entryMOdifierIdCap");
input2 = lookup_widget(button, "entryModifierValeurCap");
input3 = lookup_widget(button, "entryModifierEtageCap");
Jour = lookup_widget(button, "spinbuttonJours");
Mois = lookup_widget(button, "spinbuttonMois");
Annee = lookup_widget(button, "spinbuttonAnnees");

strcpy(c.bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Bloc)));
strcpy(c.sig,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Sig)));
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.etage,gtk_entry_get_text(GTK_ENTRY(input3)));









if (choixsk[0]==1)
strcpy(c.type,"Temperature");
else if (choixsk[1]==1)
strcpy(c.type,"Humidite");
else if (choixsk[2]==1)
strcpy(c.type,"Debit");
else if (choixsk[3]==1)
strcpy(c.type,"Mouvement");
else if (choixsk[4]==1)
strcpy(c.type,"Fumee");



c.date_installation.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
c.date_installation.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
c.date_installation.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));

if (choix3sk[0]==1)
strcpy(c.fonc,"Passif");
else if (choix3sk[1]==1)
strcpy(c.fonc,"Actif");

if(((choix3sk[0]==1) && (choix3sk[1]==1)) && ((choix3sk[0]==0) && (choix3sk[1]==0)) && (strcmp(c.id,"")==0) && (strcmp(c.valeur,"")==0) && (strcmp(c.etage,"")==0) )
{
windowErreur = create_windowRemplir();
gtk_widget_show(windowErreur);
}
else
{
modifier_capteur(c,tmps);
windowSuccees = create_windowModifSucc();
gtk_widget_show(windowSuccees);
ModifierCapteur = lookup_widget(button, "ModifierCapteur");
gtk_widget_destroy(ModifierCapteur);
}
}


void
on_actualiserCap_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *listecap;
listecap = create_windowListeCapteurs();
treeview = lookup_widget(listecap, "treeview");
afficher_capteur(treeview);
}


void
on_okbutton1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowAjoutSucc");
gtk_widget_destroy(window);
}


void
on_okbutton2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowModifSucc");
gtk_widget_destroy(window);

}


void
on_okbutton3_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowSupSucc");
gtk_widget_destroy(window);

}


void
on_okbutton4_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowRemplir");
gtk_widget_destroy(window);

}


void
on_buttonRechercherCap_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *liste1;
GtkWidget *input;
GtkWidget *input1;
GtkWidget *buttonEnable;
GtkWidget *window;
int ok;
char type[20]; 
Capteur r;
char id[20];
input = lookup_widget(button, "entryIDCap");
input1 = lookup_widget(button, "comboboxentry2");
buttonEnable = lookup_widget(button, "buttonModifCap"); 
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
window = lookup_widget(button, "windowModifierCapteur");
treeview1 = lookup_widget(window, "treeview1");
chercher_capteur_supp(r,id,type, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); 
else
gtk_widget_set_sensitive(buttonEnable, FALSE); 


afficher_capteurModif(treeview1);

}



void
on_consulter1_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *liste;
GtkWidget *window1;
Capteur c;
window1=lookup_widget(button,"window1");
liste = lookup_widget(window1, "treeview5");
 afficher_capteur_alarmant (liste);
}


void
on_button22_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowalarmant;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button,"windowGestionCapteurs");
gtk_widget_destroy(windowMenu);

windowalarmant = lookup_widget(button,"window1");
windowalarmant = create_window1();
gtk_widget_show(windowalarmant);
}


gboolean
on_treeview_start_interactive_search   (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_buttonMarque_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}

void
on_checkbuttonTemperature_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[0] = 1;
else
choixsk[0] = 0;

}


void
on_checkbuttonHumudite_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[1] = 1;
else
choixsk[1] = 0;

}
void
on_checkbuttonFumee_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[4] = 1;
else
choixsk[4] = 0;
}


void
on_checkbuttonDebit_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[2] = 1;
else
choixsk[2] = 0;
}


void
on_checkbuttonMouvement_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[3] = 1;
else
choixsk[3] = 0;
}


void
on_radiobutton1Tem_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[0] = 1;
else
choixsk[0] = 0;
}


void
on_radiobutton2Hum_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[1] = 1;
else
choixsk[1] = 0;
}


void
on_radiobutton3Debit_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[2] = 1;
else
choixsk[2] = 0;
}


void
on_radiobutton4Mouv_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[3] = 1;
else
choixsk[3] = 0;
}


void
on_radiobutton5Fumee_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[4] = 1;
else
choixsk[4] = 0;
}


gboolean
on_treeview6_start_interactive_search  (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1sk[0] = 1;
else
choix1sk[0] = 0;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1sk[1] = 1;
else
choix1sk[1] = 0;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1sk[2] = 1;
else
choix1sk[2] = 0;
}


void
on_radiobutton4sk_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1sk[3] = 1;
else
choix1sk[3] = 0;
}


void
on_radiobutton5sk_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1sk[4] = 1;
else
choix1sk[4] = 0;
}




void
on_RefreshCap_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *listecap;
GtkWidget *window;
listecap = create_windowListeCapteurs();
treeview = lookup_widget(listecap, "treeview6");
afficher_capteur(treeview);
}


void
on_checkbuttonSkander1_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix2sk[0] = 1;
else
choix2sk[0] = 0;
}


void
on_checkbuttonSkander2_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix2sk[1] = 1;
else
choix2sk[1] = 0;
}


void
on_buttonMenuCap_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *windowAjoutCapteur;
GtkWidget *windowModifier;
GtkWidget *windowListeCapteurs;
GtkWidget *windowCapteurAlarmants;
windowSupprimer = lookup_widget(button, "windowSupprimeCapteur");
gtk_widget_destroy(windowSupprimer);

windowModifier = lookup_widget(button, "windowModifierCapteur");
gtk_widget_destroy(windowModifier);

windowAjoutCapteur = lookup_widget(button, "windowAjoutCapteur");
gtk_widget_destroy(windowAjoutCapteur);


windowListeCapteurs = lookup_widget(button, "windowListeCapteurs");
gtk_widget_destroy(windowListeCapteurs);

windowCapteurAlarmants = lookup_widget(button,"window1");
gtk_widget_destroy(windowCapteurAlarmants);

windowMenu = create_windowGestionCapteurs();
gtk_widget_show(windowMenu);

}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix3sk[0] = 1;
else
choix3sk[0] = 0;
}


void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix3sk[1] = 1;
else
choix3sk[1] = 0;
}





void
on_treeview7_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowGestionCapteurs,*listecap;
listecap = create_windowListeCapteurs();
tree=lookup_widget(listecap,"treeview7");

afficher_capteur(tree);

gtk_widget_hide(windowGestionCapteurs);
gtk_widget_show(windowGestionCapteurs);
}


void
on_AfficherCap__clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowGestionCapteurs,*listecap;
listecap = create_windowListeCapteurs();
tree=lookup_widget(listecap,"treeview7");

afficher_capteur(tree);

gtk_widget_hide(windowGestionCapteurs);
gtk_widget_show(windowGestionCapteurs);
}


void
on_RechercherCap_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeviewRechercher;
GtkWidget *liste1;

GtkWidget *input2;
GtkWidget *buttonEnable;
GtkWidget *window;
Capteur r;
int ok; 
char id[30];
input2 = lookup_widget(button, "entryIDrechercherCap");
buttonEnable = lookup_widget(button, "RechercherCap");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input2)));

window = lookup_widget(button, "windowGestionCapteurs");
treeviewRechercher = lookup_widget(window, "treeviewRechercher");

chercher_capteur(r, id, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); 
else
gtk_widget_set_sensitive(buttonEnable, FALSE); 


afficher_capteurModif(treeviewRechercher);
}


void
on_okbutton444_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowRemplir");
gtk_widget_destroy(window);
}


void
on_button24_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowID");
gtk_widget_destroy(window);
}


void
on_buttonAjouterCapteur_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAjout;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button,"windowGestionCapteurs");
gtk_widget_destroy(windowMenu);

windowAjout = lookup_widget(button,"windowAjoutCapteur");
windowAjout = create_windowAjoutCapteur();
gtk_widget_show(windowAjout);
}


void
on_treeviewRechercher_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar *id;
	gchar *bloc;
	gchar *type;
	gchar *valeur;
	gchar *etage;
	gchar *fonc;
	gchar *sig;
	gchar *date_installation;
	Capteur c;
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model, &iter, path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&id,1,&valeur,2,&type,3,&date_installation,4,&etage,5,&bloc,6,&fonc,7,&sig, -1);
	strcpy(c.id,id);
	strcpy(c.valeur,valeur);
	strcpy(c.type,type);

	strcpy(c.etage,etage);
	strcpy(c.bloc,bloc);	
	strcpy(c.fonc,fonc);	
	strcpy(c.sig,sig);	
	afficher_capteur(treeview);
	}
}


void
on_AfficheCapteur_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *snumero,*cap;
cap=lookup_widget(button,"windowGestionCapteurs");
snumero=lookup_widget(button,"treeviewRechercher");
afficher_capteur(snumero);
}

void
on_capteurs_defectueux_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *p3;
GtkWidget *window2;
FILE*f1=NULL;

temp t;
GtkWidget *windowalarmant;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button,"windowGestionCapteurs");
gtk_widget_destroy(windowMenu);
GtkWidget *windowGestionCapteurs;
gtk_widget_hide (windowGestionCapteurs);
window2 = create_window2 ();
p3=lookup_widget(window2,"treeviewdeff");

v=0;
Temptree(p3,"temperature.txt");

gtk_widget_show (window2);

}





void
on_les_panes_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowalarmant;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button,"windowGestionCapteurs");
gtk_widget_destroy(windowMenu);
GtkWidget *windowGestionCapteurs;
GtkWidget *p2;
FILE*f1=NULL;
debit d;
gtk_widget_hide (windowGestionCapteurs);
etages_contenant_des_pannes = create_window3 ();
p2=lookup_widget(etages_contenant_des_pannes,"treeview666");

i=0;
Debittree(p2,"debit.txt");


gtk_widget_show (etages_contenant_des_pannes);
}


void
on_Retourrr_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *windowMenu;
GtkWidget *windowCapteurAlarmants;



windowCapteurAlarmants = lookup_widget(button,"window4");
gtk_widget_destroy(windowCapteurAlarmants);

windowMenu = create_windowGestionCapteurs();
gtk_widget_show(windowMenu);
}





void
on_buttonAlarme_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowalarmant;
GtkWidget *windowMenu;
GtkWidget *window4;
windowMenu = lookup_widget(button,"windowGestionCapteurs");
gtk_widget_destroy(windowMenu);
GtkWidget *windowGestionCapteurs;
/*preparation du treeView*/
GtkWidget *p4;
FILE*f1=NULL;
//temp t;
FUMEE F;
gtk_widget_hide (acceuil);
window4 = create_window4 ();
p4=lookup_widget(window4,"treeview667");

v=0;
/*Temptree(p3,"temperature.txt");*/
Fumeetree(p4,"fumee.txt");


gtk_widget_show (window4);
}


void
on_Afficherrrr_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *liste;
GtkWidget *window1;
Capteur c;
window1=lookup_widget(button,"window1");
liste = lookup_widget(window1, "treeview5");
 afficher_capteur_alarmant (liste);
}


void
on_Retouuurrr_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowMenu;
GtkWidget *windowCapteurAlarmants;



windowCapteurAlarmants = lookup_widget(button,"window3");
gtk_widget_destroy(windowCapteurAlarmants);

windowMenu = create_windowGestionCapteurs();
gtk_widget_show(windowMenu);
}


void
on_Reeeeeetour_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowMenu;
GtkWidget *windowCapteurAlarmants;



windowCapteurAlarmants = lookup_widget(button,"window2");
gtk_widget_destroy(windowCapteurAlarmants);

windowMenu = create_windowGestionCapteurs();
gtk_widget_show(windowMenu);
}











