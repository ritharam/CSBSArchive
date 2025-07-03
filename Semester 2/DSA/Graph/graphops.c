#include<stdio.h>
#include<stdlib.h>
#include "graph.h"

int constructgraph(vertex G[])
{
	int i,j,n,m,av;
	printf("\nEnter number of Vertices :");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter the name of the vertex %d :",i+1);
		scanf("%s",G[i].name); 
		printf("\nNumber of adjacent vertices of %s :",G[i].name);
		scanf("%d",&G[i].nav);
		G[i].adjptr = NULL;
		NODE *T, *last;
		last = NULL;
		for(j=0;j<G[i].nav;j++)
		{
			printf("\nEnter the index of Adj vertex %d:",j+1);
			scanf("%d",&av);
			T = (NODE*)malloc(sizeof(NODE));
			T-> adjver = av;
			T->link = NULL;
			if(last == NULL)
				G[i].adjptr = T;
			else 
				last ->link = T;
			last = T;
		}
	}
	return n;	
}

void displaygraph(vertex G[],int n)
{
	int i;
	NODE *temp;
	printf("\nName\tAdjacent Vertices\n");
	for(i=0;i<n;i++){
		printf("%s",G[i].name);
		temp = G[i].adjptr;
		while (temp != NULL){
			printf("\t-->%d",temp->adjver);
			temp = temp->link;
		}
		printf("\n");  
	}
	printf("\n-----------------------------------\n");
}

void storegraph(vertex G[],int n, char fname[])
{
	int i;
	NODE *temp;
	FILE *fp;
	fp = fopen(fname,"w");
	fprintf(fp,"%d\n",n);
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%s",G[i].name);
		fprintf(fp,":%d",G[i].nav);
		temp = G[i].adjptr;
		while (temp != NULL)
		{
			fprintf(fp,"\t%d",temp->adjver);
			temp = temp ->link;
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}

int loadgraph(vertex G[], char fname[])
{
	int i,j,n,m,av;
	FILE *fp;
	fp = fopen(fname , "r");
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%s",G[i].name);
		fscanf(fp,"%d",&G[i].nav);
		G[i].adjptr = NULL;
		NODE *T, *last;
		last = NULL;
		for(j=0;j<G[i].nav;j++)
		{
			fscanf(fp,"%d",&av);
			T = (NODE*)malloc(sizeof(NODE));
			T-> adjver = av;
			T->link = NULL;
			if(last == NULL)
				G[i].adjptr = T;
			else 
				last ->link = T;
			last = T;
		}
	}
	fclose(fp);
	return n;
}
