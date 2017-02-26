#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAILLE_BUFFER 80

//ouvrir fichier d'entre retourne un descipteur
FILE* ouvrirF(char* FichierEntree);
//ouvrir fichier sortie retourne un descripteur
FILE* ouvrirSortie(char* fichierSortie);
//fermer un fichier
int fermerF(FILE* fich);


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

int main (int argc, char** argv)
{

FILE* fichier1;
FILE* fichier2;

if (argc != 3)
{
  printf("erreur sur le nombre d'arguments %d \n", errno);
  return 1;
}
fichier1 = ouvrirF(argv[1]);
fichierSortie = ouvrirSortie(argv[2]);

if (fichier1 == NULL)
{
  printf("Erreur d'ouverture de fichier d'entree %d\n", errno);
  return 1;
}

 if (fichierSortie == NULL)
  {
  printf("Erreur d'ouverture de fichier de sortie%d\n", errno);
  return 1;
  }

return 0;
}
