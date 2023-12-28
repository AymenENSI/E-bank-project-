#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#define Nb_max_client  2000
int nb_client ;
typedef struct Date{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct email{    // email de la forme : enom.eprenom@gmail.com
    char enom[20];
    char eprenom[20];
}email;


typedef struct client{
    int ID_client ;      // Identifiant unique du client
    char Nom[20];       //nom du client
    char Prenom[20];    //prenom du client
    char adresse ;
    int Tel[8];
    char profession[30];
    email email;
    Date date_naissance;
    int num_ajout;        // c'est le num�ro d'ajout du client (Exemple : le premier adh�rent a le num�ro 1)

}client;

typedef struct Compte {
    int num_compte;       // Num�ro unique du compte
    int ID_client;           // Identifiant du client associ� � ce compte
    char type_compte[20];    // Type de compte (exemples:�pargne,courant,etc.)
    float solde;             // Solde du compte
    struct Date date_creation ;    // date de cr�ation du compte
    client prop_compte;            //Client propri�taire du compte

}compte;

compte tab_Compte[Nb_max_client];  // Tableau qui contient tous les comptes cr�es dans la banque
client tab_client[Nb_max_client];  // Tableau qui contient tous les clients de la banque


int choix;
void menu_secondaire(int choix);

void menu()
{   int lang,cx;
    /*printf("1:Anglais     2:Français\n");
    scanf("%d",&lang);
    if (lang==2){*/
        printf("Menu:\n");
        printf("1: Gestion des clients\n");
        printf("2: Gestion des comptes\n");
        printf("3: Gestion des operations\n");
        printf("4: Parametre\n");
        printf("5: Deconnexion\n");
        printf("Quel est votre choix :\n");
        scanf("%d", &cx);
        menu_secondaire(cx);
    /*}else if (lang==1){
        printf("Menu:\n");
        printf("1: Client Management\n");
        printf("2: Account Management\n");
        printf("3: Operations Management\n");
        printf("4: Setting\n");
        printf("5: Deconnexion\n");
        printf("Tap your choice :");
        scanf("%d", &cx);
        menu_secondaire(cx);
    }else{
        printf("Error!!Choice one of this :1:Anglais     2:Français\n");

    }*/
}
void menu_client(){
            int chx;
            printf("Menu client:\n");
            printf("1: Ajouter\n");
            printf("2: Modification des information du client\n");
            printf("3: Supprimer\n");
            printf("4: Afficher\n");
            printf("5: Revenir au menu principale\n");
            printf("Quel est votre choix : ");
            scanf("%d", &chx);
            cmd_client(chx);
}
void menu_compte(){
            int chx;
            printf("Menu compte:\n");
            //printf("1: Cr�artion d'un compte \n");
            printf("1: Recherche\n");
            printf("2: Consultation du solde \n");
            printf("3: Fermeture du compte \n");
            printf("4: Revenir au menu principale\n");
            printf("Quel est votre choix : \n");
            scanf("%d", &chx);
            cmd_compte(chx);
}
void menu_operation(){
            int chx;
            printf("1: Retrait\n");
            printf("2: Versement d'argent\n");
            printf("3: Revenir au menu principale\n");
            printf("Quel est votre choix :\n ");
            scanf("%d", &chx);
            cmd_operation(chx);
}
void parametre(){
            int chx;
            printf("1:changer la langue\n");
            printf("2:changer le mot de passe\n");
            printf("3: Revenir au menu principale\n");
            printf("Quel est votre choix : \n");
            scanf("%d",&chx);
}
void menu_secondaire(int choix){
    switch(choix){
        int chx;
        case 1:  //Gestion de client
            menu_client();
            /*printf("1: Ajouter\n");
            printf("2: Modification des information du client\n");
            printf("3: Supprimer\n");
            printf("4: Afficher\n");
            printf("5: Revenir au menu principale\n");
            printf("Quel est votre choix : ");
            scanf("%d", &chx);
            cmd_client(chx);*/
            break;
        case 2:   // Gestion du compte
            menu_compte();
            /*printf("1: Cr�artion d'un compte \n");
            printf("2: Recherche\n");
            printf("3: Consultation du solde \n");
            printf("4: Fermeture du compte \n");
            printf("5: Revenir au menu principale\n");
            printf("Quel est votre choix : \n");
            scanf("%d", &chx);
            //cmd_compte(chx);*/
            break;
        case 3:   // Gestion des op�rations
            menu_operation();
            /*printf("1: Retrait\n");
            printf("2: Versement d'argent\n");
            printf("3: Revenir au menu principale\n");
            printf("Quel est votre choix :\n ");
            scanf("%d", &chx);
            //gerer_operation(chx);*/
            break;
        case 4:     // Param�tre
            parametre();
            /*printf("1:changer la langue\n");
            printf("2:changer le mot de passe\n");
            printf("3: Revenir au menu principale\n");
            printf("Quel est votre choix : \n");
            scanf("%d",&chx);*/
            //gerer_parametre(chx);
            break;
        case 5:
            printf("Au revoir");
            return 0;
            break;
        default:
            printf("Choix invalide");
            menu();
        }
}

void Ajout_client(){
    client cl;
        FILE *fichier_client;

        //Les coordonnees du client
        printf("Mettez ID client\n:");
        scanf("%d",&cl.ID_client);
        printf("Nom client :\n");
        scanf("%s",&cl.Nom);
        printf("Prenom client\n");
        scanf("%s",&cl.Prenom);
        printf("L'adresse du client:\n");
        scanf("%s",&cl.adresse);
        printf("NumTeldu client:\n");
        scanf("%d",&cl.Tel);
        printf("Profession du client:\n");
        scanf("%s",&cl.profession);
        printf("Adresse electronique:\n");
        scanf("%s",&cl.email);
        printf("Date de naissance:\n");
        printf("Jour de naissance:\n");
        scanf("%d",&cl.date_naissance.jour);
        printf("Mois de naissance:\n");
        scanf("%d",&cl.date_naissance.mois);
        printf("Annee de naissance:\n");
        scanf("%d",&cl.date_naissance.annee);
        //Utilisation du fichier : Base des donnees
        fichier_client=fopen("liste des_clients.dat","a");
        if (fichier_client== NULL ){
            printf("Erreur:echec d'ouverture du fichier\n");
        }else{
            printf("L'operation d'enregistrement du client est faite\n ");
        }
        fwrite(&cl,sizeof(client),1,fichier_client);
        fclose(fichier_client);
        nb_client++;
        tab_client[nb_client-1]=cl;
        printf("l'ajout d'un client exige une ouverture de compte\n"); //***************
        creer_compte( cl );


}

void update_fichier(char nomfich){
    FILE*fich_clients2;
    fich_clients2=fopen("client2.dat","ab");  //ouverture du nouveau fichier BD
    for (int i=0 ;i<nb_client;i++){
        fwrite(&tab_client[i],sizeof(client),1,fich_clients2);
    }
    fclose(fich_clients2);
    remove(nomfich);
    rename("fich_clients2.dat",nomfich);

}








void cmd_client(int chx){                        //---------------------------interface client -------------------------------------
switch (chx){
    case 1:   //Ajout client
        Ajout_client();
        /*client cl;
        FILE *fichier_client;

        //Les coordonn�es du client
        printf("Mettez ID client\n:");
        scanf("%d",&cl.ID_client);
        printf("Nom client :\n");
        scanf("%s",&cl.Nom);
        printf("Prenom client\n");
        scanf("%s",&cl.Prenom);
        printf("L'adresse du client:\n");
        scanf("%s",&cl.adresse);
        printf("NumTeldu client:\n");
        scanf("%d",&cl.Tel);
        printf("Profession du client:\n");
        scanf("%s",&cl.profession);
        printf("Adresse electronique:\n");
        scanf("%s",&cl.email);
        printf("Date de naissance:\n");
        printf("Jour de naissance:\n");
        scanf("%d",&cl.date_naissance.jour);
        printf("Mois de naissance:\n");
        scanf("%d",&cl.date_naissance.mois);
        printf("Annee de naissance:\n");
        scanf("%d",&cl.date_naissance.annee);
        //Utilisation du fichier : Base des donnees
        fichier_client=fopen("liste des_clients.dat","a");
        if (fichier_client== NULL ){
            printf("Erreur:echec d'ouverture du fichier\n");
        }else{
            printf("L'op�ration d'enregistrement du client est faite\n ");
        }
        fwrite(&cl,sizeof(client),1,fichier_client);
        fclose(fichier_client);
        nb_client++;
        tab_client[nb_client-1]=cl;
        printf("l'ajout d'un client exige une ouverture de compte\n"); //***************
        creer_compte(cl);*/                                              //***************
        menu_client();
        break;

        //Modification des informations des clients
        case 2:
            int x,numc,IDc;
            client nvcl;
            FILE*fich_clients2;

            printf("Donner ID du client:\n");
            scanf("%d",&IDc);
            for(int j=0 ;j<nb_client;j++){
                if (tab_client[j].ID_client== IDc){
                        printf("Choisissez le champ à modifier\n");
                        printf("1:Changer num_cin\n:\n");
                        printf("2:Changer Nom client :\n");
                        printf("3:Changer Prenom client\n");
                        printf("4:Changer l'adresse du client:\n");
                        printf("5:Changer Num Tel du client:\n");
                        printf("6:Changer la profession du client:\n");
                        printf("7:Changer l'adresse electronique:\n");
                        scanf("%d",&x);
                        switch (x){
                            case 1:
                                    printf("Nouveau ID_client\n:");
                                    scanf("%d",&nvcl.ID_client);
                                    break;

                            case 2:
                                    printf("Nouveau Nom client :\n"); //Changement du nom Possible apr�s le passage devant le juge
                                    scanf("%s",&nvcl.Nom);
                                    break;
                            case 3:
                                    printf("Nouveau Prenom client\n");
                                    scanf("%s",&nvcl.Prenom);
                                    break;
                            case 4:
                                    printf("Nouvelle l'adresse du client:\n");
                                    scanf("%s",&nvcl.adresse);
                                    break;
                            case 5:
                                    printf("Nouveau Num Tel du client:\n");
                                    scanf("%d",&nvcl.Tel);
                                    break;
                            case 6:
                                    printf("Nouvelle Profession du client:\n");
                                    scanf("%s",&nvcl.profession);
                                    break;
                            case 7:
                                    printf("Nouvelle l'adresse �lectronique:");
                                    scanf("%s",&nvcl.email);
                                    break;
                            default:
                                    printf("Erreur choix!!!");
                            }

                            fich_clients2=fopen("client2.dat","ab");  //ouverture du nouveau fichier BD
                            for (int i=0 ;i<nb_client;i++){
                                fwrite(&tab_client[i],sizeof(client),1,fich_clients2);
                            }
                            fclose(fich_clients2);
                            remove("liste des_clients.dat");
                            rename("fich_clients2.dat","fichier_client.dat");

                }else{
                    printf("Cet ID n'existe pas ");

                }
            }
            break;

        case 3: // Supression d'un client
            int IC;

            printf("Donner le ID du client à supprimer:\n");
            scanf("%d",IC);
            for (int i=0 ;i<nb_client;i++){
                if (tab_client[i].ID_client==IC){
                    for (int j=i;j<nb_client-i-1;j++){
                        tab_client[j]=tab_client[j+1];
                    }
                    nb_client--;
                    FILE*fich_inter;
                    fich_inter=fopen("fichier_client.dat","ab");
                    for (int k=0;k<nb_client;k++){
                        fwrite(&tab_client[k],sizeof(client),1,fich_inter);
                    }
                    fclose(fich_inter);
                    remove("fichier_client.dat");
                    rename("fich_inter.dat","fichier_client.dat");

                }else{
                    printf("Le client n'est pas un adh�rant de la banque");
                }
            }
            break;
        case 4:    //affichage de tous les clients
            FILE*fichier;
            client cli;
            fichier=fopen("fichier_client.dat","rb");
            while(fread(&cli,sizeof(client),1,fichier)!= EOF){
                    printf(fread(&cli,sizeof(client),1,fichier));

            }
            fclose(fichier);
            break;
        case 5:    //Revenir au menu principale
            menu();

        }
}

void creer_compte(client cl){
    compte cpt;
    Date dt;
    time_t temps_actuel;         // cr�ation dune varaible de type time_t
    time(&temps_actuel);         //// extraire le temps actuel en secondes depuis l'�poque (1er janvier 1970)
    struct tm *date_locale = localtime(&temps_actuel); //convertir le temps (exprim� en secondes depuis l'�poque) stock� dans la variable temps_actuel en une structure tm repr�sentant la date et l'heure locales

    printf("donner le numero de compte :\n");   // num�ro de compte entr� � la main
    scanf("%d",&cpt.num_compte);
    cpt.ID_client=cl.ID_client;
    printf("Type de compte que vous voulez ouvrir:\n");
    scanf("%s",&cpt.type_compte);

    //la date de création
    cpt.date_creation.jour=date_locale->tm_mday;
    cpt.date_creation.mois=date_locale->tm_mon;
    cpt.date_creation.annee=date_locale->tm_year;
    //Mettre le solde  10 dt
    cpt.solde=10;

    cpt.prop_compte=cl;    // Mettre le propri�taire de compte
    tab_Compte[nb_client-1]=cpt;     //j'ai ajout� -1 car l'incr�mentation du nombre des client et avant l'ajout du compte au tab_compte

    printf(" Succès Opération \n");


}








void cmd_compte(int chx ){                        //-----------------------------------interface compte ----------------------------
    switch(chx){
        case 1:
            //Recherche d'un client
            int id,ok=0;
            printf("donner le Id du client que vous cherchez son compte: ");
            scanf("%d",&id);
            for (int i=0 ;i<nb_client;i++){
                if (tab_Compte[i].ID_client==id){
                    ok=1;
                }
            }
            if (ok=1){
                printf("Compte existant\n");
            }else{
                printf("Le compte n'existe pas\n");
            }
            menu_compte();
            update_fichier("fichier_client.dat");  // mise à jour de fichier où je stocke les clients
            break;
        case 2:
            //Consultation du solde
            int idcl;
            int i = 0;
            int p;
            int f;
            printf("Entrez l'ID du client dont vous voulez consulter le solde :\n");
            scanf("%d", &idcl);

            for (int i=0 ;i<nb_client;i++){
                if (tab_Compte[i].ID_client==idcl){
                    ok=1;
                    p=i;
                }
            }
            if (ok=1){
                printf("Solde : %.2lf\n", tab_Compte[i].solde);
            }else{
                printf("Le compte n'existe pas\n");
            }

            //printf("Solde : %.2lf\n", tab_Compte[].solde);
            menu_compte();
            update_fichier("fichier_client.dat");  // mise à jour de fichier où je stocke les clients
            break;
        case 3://fermeture du compte
            int ic ;
            int contole=0;
            int inter;
            printf("donner le id du client que veut fermer sont compte:\n");
            scanf("%d",ic);

            for (int f=0 ;f<nb_client;f++){
                if (tab_Compte[f].ID_client==id){
                    contole=1;
                    inter=f;
                }
            }
            if (contole=1){
                for (int j=inter;j<nb_client;j++){
                        tab_client[j]=tab_client[j+1];
                        tab_Compte[j]=tab_Compte[j+1];
                }
            }else{
                printf("Le compte n'existe pas\n");
            }
            printf("Succès de l'opération de fermeture \n ");
            menu_compte();
            update_fichier("liste des_clients.dat");  // mise à jour de fichier où je stocke les clients
            break;
        case 4://revenir au menu principale
            menu();
            break;
        default:
            printf("Votre choix n'existe pas\n");
            menu_compte();

    }

}


void cmd_operation(int vch){
    switch(vch){
        case 1://Retrait d'argent
            int numcp;
            int mr , indice ;
            printf("Retrait d'argent\n");
            printf("Donner le num�ro de compte:\n");
            scanf("%d",numcp);
            printf("Donner le montant � retirer\n");
            scanf("%f",mr);

            for (int i=0 ;i<nb_client;i++){
                if (tab_Compte[i].num_compte==numcp){
                    indice= i ;
                }
            }
            tab_Compte[indice].solde-=mr;
            printf("Op�ration faite avec succ�s");
            menu_operation();
            update_fichier("fichier_clients");
            update_fichier("fichier_client.dat");  // mise à jour de fichier où je stocke les clients
            break;

        case 2:   //Versement d'argent
            int mv , indice2;
            int numct;
             printf("Versement d'argent\n");
            printf("Donner le num�ro de compte:\n");
            scanf("%d",numct);
            printf("Donner le montant � verser \n");
            scanf("%f",mv);
            for (int j=0 ;j<nb_client;j++){
                if (tab_Compte[j].num_compte==numct){
                    indice2=j  ;
                }
            }
            tab_Compte[indice2].solde+=mv;
            printf("Op�ration faite avec succes");
            menu_operation();
            update_fichier("fichier_clients");
            update_fichier("fichier_client.dat");  // mise à jour de fichier où je stocke les clients
            break;
        case 3:
            menu();
            break;
        default:
            printf("Votre choix n'existe pas\n");
            menu_compte();

    }

}

void cmd_setting(int choice){
switch(choice){
    case 1://changer la langue             // j'ai décider de ne pas terminer cette fonctionalité ,mais je l'ai entamé car j'ai des idées de developpement de code après la fin de remise de projet
        break;
    case 2:
        break;


}
}











/*int main(){
    menu();
}*/
int main() {
    menu();
    /*FILE *fichier;
    char nom_fichier[50];

    // Demander � l'utilisateur le nom du fichier
    printf("Entrez le nom du fichier binaire : ");
    scanf("%s", nom_fichier);

    // Ouvrir le fichier en mode lecture binaire
    fichier = fopen(nom_fichier, "rb");

    // V�rifier si le fichier est ouvert avec succ�s
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1;  // Quitter le programme avec code d'erreur
    }

    // Lire et afficher le contenu du fichier octet par octet
    int octet;
    while ((octet = fgetc(fichier)) != EOF) {
        printf("%02X ", octet);  // Afficher l'octet en format hexad�cimal
    }

    // Fermer le fichier
    fclose(fichier);*/

    return 0;
}


