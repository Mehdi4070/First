#include <stdio.h>
#include <stdlib.h>
typedef struct noeud{
    int val;
    struct noeud* suivent;
}noeud;

typedef noeud* liste;

liste cree(){
    return NULL;
}

void inserer_d(liste* l,int x){
    liste li;
    li = (noeud *)malloc(sizeof(noeud));
    li->val = x;
    li->suivent = *l;
    *l = li;

}

void inserer_f(noeud **l , int x){
    noeud* li,*lm;
    li = (noeud *)malloc(sizeof(noeud));
    li->val = x;
    li->suivent = NULL;
    if(*l == NULL)
        *l = li;
    else{
        lm = *l;
        while (lm->suivent != NULL)
            lm = lm->suivent;
        lm->suivent = li;
    }
}

int longueur(liste l){
    int nb;
    while (l->suivent != NULL){
        nb++;
        l = l->suivent;
    }
    return nb;
}

void aff(liste l){
    while (l != NULL){
        printf("%d ",l->val);
        l = l->suivent;
    }
}

void aff2(liste l){
    if (l->suivent != NULL){
        printf("%d ",l->val);
        aff(l->suivent);
    }
    else
        printf("\n");

}

liste redendence(liste l){
    liste lm;
    if(l == NULL)
        return l;
    lm = l;
    while(lm->suivent != NULL){
        if(lm->val == lm->suivent->val){
            liste tmp = lm->suivent;
            lm->suivent = tmp->suivent;
            free(tmp);
        }
        else
            lm = lm->suivent;
    }
    return l;
}

liste red(liste l){
    if(l == NULL)
        return l;
    else if(l->val == l->suivent->val){
        liste tmp=l->suivent;
        l->suivent = l->suivent->suivent;
        free(tmp);
        l->suivent = red(l);
        return l;
    }
    else{
        l->suivent = red(l->suivent);
        return l;
    }
}
liste invers(liste l){
	liste head=NULL;
	if(l->suivent==NULL){
		return(l);
	}
	head=invers(l->suivent);
	l->suivent->suivent=l;
	l->suivent=NULL;
	return(head);
}




liste inv(liste l){
    liste tmp = l;
    if(l->suivent->suivent == NULL){
        l->suivent->suivent = tmp;
        l = tmp->suivent;
        return l ->suivent;
    }
    else{
        tmp->suivent = inv(l->suivent);
        return l;
    }
}

void inv3(liste l){
    liste q=l,p;
    if(q && q->suivent){
        p = q->suivent;
        inv(l->suivent);
        p ->suivent = q;
        l = q->suivent;
        p ->suivent->suivent = NULL;
    }
}

void main(){
    liste l;
    int i;
    l = cree();
    for(i = 1 ; i<=4 ; i++){
        inserer_f(&l,i);
    }

    aff(l);
    /*l = invers(l);
    printf("\n");
    aff(l);*/
}
