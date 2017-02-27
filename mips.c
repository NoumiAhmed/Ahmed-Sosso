#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAILLE_BUFFER 100

////////declaration fonctions////////////////////////

//ouvrir fichier d'entre retourne un descipteur
FILE* ouvrirF(char* FichierEntree);
//ouvrir fichier sortie retourne un descripteur
FILE* ouvrirSortie(char* fichierSortie);
//fermer un fichier
int fermerF(FILE* fich);
//recuperer les lignes du fichier

//traduire
int encoderVersBinaire(FILE* FichierEntree , FILE* FichierSortie);

/////////////////////////////////////////////////////
/////////////implementation fonctions///////////////
FILE* ouvrirF(char* FichierEntree)
{
  return fopen(FichierEntree, "r");
}

FILE* ouvrirSortie(char* fichierSortie)
{
  return fopen(fichierSortie, "wb");
}

int fermerF(FILE* fich)
{
  return fclose(fich);
}

 int encoderVersBinaire(FILE* fichier , FILE* fichierSortie)
 {
  FILE *f = fichier;
  FILE *fS= fichierSortie;
  char ligne[TAILLE_BUFFER + 1];
  while ( fgets(ligne, TAILLE_BUFFER, f) )
   {
    fputs("000111",  fS);
    
   }
   return 0;
 }
////////////////////////////////////////////////////
int main (int argc, char** argv)
{

FILE* fichierEntree;
FILE* fichierSortie;

if (argc != 2)
{
  printf("erreur sur le nombre d'arguments %d \n", errno);
  return 1;
}
fichierEntree = ouvrirF(argv[1]);

fichierSortie = ouvrirSortie(strcat(argv[1],".asm"));

if (fichierEntree == NULL)
{
  printf("Erreur d'ouverture de fichier d'entree %d\n", errno);
  return 1;
}

 if (fichierSortie == NULL)
  {
  printf("Erreur d'ouverture de fichier de sortie%d\n", errno);
  return 1;
  }
int i;
i = encoderVersBinaire(fichierEntree , fichierSortie);

 if (fermerF(fichierEntree) != 0)
  {
   printf("Erreur lors de la fermeture du fichier Entree.\n");
   return 1;
  }
 if (fermerF(fichierSortie) != 0)
  {
   printf("Erreur lors de la fermeture du fichier Sortie.\n");
   return 1;
  }

return 0;
}
