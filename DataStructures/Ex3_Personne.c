#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

struct dateNaissance
{
    unsigned j;
    unsigned m;
    unsigned a;
};

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

struct personne
{
    char *nom;
    char *prenom;
    struct dateNaissance dn;
};

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

struct liste
{
    struct personne *first;
};

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void initialiser(struct liste *l)
{
    l->first=NULL;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void ajouter(struct liste *l,struct personne *P)
{
    struct personne *p;
    p=l->first;
    if(p==NULL)
    	{
    		p=P;
    		l->first=p;
		}
	else
	{
		
		while (p->next != NULL)
    	{
        	p=p->next;
    	}		
    	p->next=E;
	}
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void remplir_tab_personnes(struct liste *l,int n)
{
    char ch[100];
    struct personne *P;
    int i;
    for(i=0;i<n;i++)
    {
        printf("*********Personne %d\n",i+1);
        P=(struct personne*)malloc(sizeof(struct personne));
        printf("nom: ");
        fflush(stdin);
        gets(ch);
        P->nom=(char*)malloc(sizeof(char)*(strlen(ch)+1));
        strcpy(P->nom,ch);
        printf("prenom: ");
        gets(ch);
        P->prenom=(char*)malloc(sizeof(char)*(strlen(ch)+1));
        strcpy(P->prenom,ch);

        printf("donner la date de naissance de l'étudiant:ETD[i]= \t",i);
          do
          {
              printf("donner l'année de naissance \t");
              scanf("%d",&P->dn.a);
          } while (P->dn.a<=1980 && P->dn.a>=2003);
          do
          {
              printf("donner le mois de naissance \t");
              scanf("%d",&P->dn.m);
          } while (P->dn.m<0 && P->dn.m>=12);
          if (P->dn.m==2)
            {
                if(P->dn.a%4==0)
                  {
                      do
                           {
                               printf("donner le jour de naissance \t");
                               scanf("%d",&P->dn.j);
                           } while (P->dn.j<0 && P->dn.j>=29);
                  }
                else
                 {
                      do
                           {
                               printf("donner le jour de naissance \t");
                               scanf("%d",&P->dn.j);
                           } while (P->dn.j<0 && P->dn.j>=28); 
                 }  
            }
          if(P->dn.m==1 || P->dn.m==3 || P->dn.m==5 || P->dn.m==7 || P->dn.m==8 || P->dn.m==10 || P->dn.m==12)
            {
                do
                {
                    printf("donner le jour de naissance \t");
                    scanf("%d",&P->dn.j);
                } while (P->dn.j<0 && P->dn.j>=31);
                
            }
          else
           {
                 do
                {
                    printf("donner le jour de naissance \t");
                    scanf("%d",&P->dn.j);
                } while (P->dn.j<0 && P->dn.j>=30);   
           } 
    P->next=NULL;
    ajouter(l,P);
    }
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void affiche_tab_personnes(struct liste *l)
{
    struct personne *p;
    p=l->first;
    int i;
    while(p!=NULL)
    {
        printf("*********Personne %d\n",i+1);
        printf("nom: %s\n",p->nom);
        printf("prenom: %s\n",p->prenom);
        printf("matricule: %d\n",p->matricule);
        printf("Date de naissance : %u/%u/%u\n",p->dn.j,p->dn.m,p->dn.a);
        p=p->next;
    }
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void trier(struct liste *l)
{
    int tmp;
	while(l<l->suivant)
	{
        tmp=l;
        l=l->suivant;
        l->suivant=tmp;	
	}
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

// void tri_insertion_personnes(personne T[],int n, int (*oper)(personne,personne))
// {
//     int i,j;
//     personne v;
//     for(i=1;i<n;i++)
//     {
//         v=T[i];
//         j=i-1;
//         while(j>=0 && (*oper)(T[j],v)>0)//strcmp(T[j].nom,v.nom)>0)
//         {
//             T[j+1]=T[j];
//             j--;
//         }
//         T[j+1]=v;
//     }
// }

// /*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

// int compare_personne_nom(personne p1,personne p2)
// {
//     return strcmp(p1.nom,p2.nom);
// }

// /*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

// int compare_personne_prenom(personne p1,personne p2)
// {
//     return strcmp(p1.prenom,p2.prenom);
// }

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void main()
{
    int n;
    struct liste *L;
    
    do
    {
        printf("n=");
        scanf("%d",&n);
    }while(n<=0 || n>100);

    L=(struct liste*)malloc(sizeof(struct liste));
    initialiser(L);
    remplir_tab_pointeurs_personnes(L,n);
    affiche_tab_pointeurs_personnes(L);

    trier(L);
    affiche_tab_pointeurs_personnes(L);
}