#include<stdio.h>
int main()
{
	int n, m, i, j, k, avail[10], alloc[10][10], max[10][10], need[10][10];
	int req_p;
	int req[10];
	printf("Enter number of processes: ");
	scanf("%d", &n);
	printf("Enter the numbers of resources: ");
	scanf("%d", &m);
	printf("Enter the number of available resources: \n");
	for(i = 0; i < m; i++)
	{
  	  printf("Resource%d: ",i);
  	  scanf("%d", &avail[i]);
	}
	printf("\nEnter maximum resource demand of each process:\n");
	for(i = 0; i < n; i++)
	{
  	  printf("Process %d:\n",i);
  	  for(j = 0; j < m; j++)
  	  {
  		  scanf("%d", &max[i][j]);
  	  }
	}
	printf("\nEnter already allocated resources of each process: \n");
	for(i = 0; i < n; i++)
	{
  	  printf("Process %d: ",i);
  	  for(j = 0; j < m; j++)
  	  {
  		  scanf("%d", &alloc[i][j]);
  	  }
	}
	printf("Enter the process which requests: ");
	scanf("%d", &req_p);
	printf("Enter the request of each resource: ");
	for(i = 0;i < m; i++)
	{
      	scanf("%d",&req[i]);
	}
	int f[n], ans[n], ind = 0;
	for(k = 0; k < n; k++)
	{
  	  f[k] = 0;
	}
	for(i = 0; i < n; i++)
	{
  	  for(j = 0; j < m; j++)
  	  {
  		  need[i][j] = max[i][j] - alloc[i][j];
  	  }
	}
	for(k = 0; k < m; k++)
	{
     need[req_p][k] -= req[k];
     alloc[req_p][k] += req[k];
     avail[k] -= req[k];
	}
	int y = 0;
	for(k = 0; k < n; k++)
	{
  	  for(i = 0; i < n; i++)
  	  {
  		  if(f[i] == 0)
  		  {
  			  int flag = 0;
  			  for(j = 0; j < m; j++)
  			  {
  				  if(need[i][j] > avail[j])
  				  {
  					  flag = 1;
  					  break;
  				  }
  			  }
  			  if(flag == 0)
  			  {
  				  ans[ind++] = i;
  				  for(y = 0; y < m; y++)
  				  {
  					  avail[y] += alloc[i][y];
  				  }
  				  f[i] = 1;
  			  }
  		  }
  	  }
	}
	int flag = 1;
	for(int i = 0; i < n; i++)
	{
  	  if(f[i] == 0)
  	  {
  		  flag = 0;
  		  printf("The request cannot be granted as it will lead to deadlock\n");
  		  break;
  	  }
	}
	if(flag == 1)
	{
  	  printf("The request is granted\nFollowing is the safe sequence\n");
  	  for(i = 0; i < n-1; i++)
  	  {
  		  printf("P%d ->", ans[i]);
  	  }
  	  printf("P%d", ans[n-1]);
     printf("\n");
	}
	return 0;
}
