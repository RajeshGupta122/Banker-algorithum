#include<stdio.h>
int main()
{

int allocation[5][5],max[5][5],remaning[5][5],avail[5],running[5];
int i,j,n,r,counter=0,ex,k=1,safe=0;
int again=0;
printf("Number of process:");
scanf("%d",&n);
printf("Number of Resource:");
scanf("%d",&r);
	for (i = 0; i < n; i++) 
	{
        	running[i] = 1;
        	counter++;
    	}
for(i=0;i<n;i++)
{
	avail[i]=0;
	//counter++;
}
printf("Enter Allocated Resource table\n");
for (i=0;i<n;i++)
{
	for(j=0;j<r;j++)
	{
		scanf("%d",&allocation[i][j]);
			}
}
printf("Enter Maximum Need table\n");
for (i=0;i<n;i++)
{
	for(j=0;j<r;j++)
	{
		scanf("%d",&max[i][j]);
			}
}
check:
		if(again!=0)
		{
			int y;
			printf("Enter in which process you wish to add resources");
			scanf("%d",&y);
			printf("Enter %d resources for process %d",r,y);
			int i;
			for(i=0;i<r;i++)
			{
			int x;
			scanf("%d",&x);
			allocation[y-1][i]+=x;
			counter=0;
		    }
		    for (i = 0; i < n; i++) 
	{
        	running[i] = 1;
        	counter++;
    	}
		   for(i=0;i<n;i++)
{
	avail[i]=0;
	//counter++;
} 
		}
 	for (i = 0; i < n; i++) 
	{
        	for (j = 0; j < r; j++) 
		{
            		avail[i] += allocation[j][i];
        	}
    	}
 
    	printf("\n====Allocated resources====:");
    	for (i = 0; i < r; i++) 
	{
        	printf("\t%d", avail[i]);
    	}
printf("\n");
printf("Enter Remianing  table\n");
for (i=0;i<n;i++)
{
	for(j=0;j<r;j++)
	{
		remaning[i][j]=max[i][j]-allocation[i][j];
			printf("%d\n",remaning[i][j]);
			}
			
}
for (i=0;i<n;i++)
	for(j=0;j<r;j++)
	{
		if(remaning[i][j]<0)
		{
		printf("DEADLOCK OCCURED");
		exit(0);}
			}
			

printf("======Allocation Resource======\n");
	for(i=0; i<r; i++) 
	{
		for(j=0;j<r;j++)
		{
			printf("\t%d", allocation[i][j]);
		}
	}
	printf("\n");
	printf("Enter available resource");
	for(i=0;i<r;i++)
	{

	scanf("\t%d",&avail[i]);
}

		
	
		
	
		while (counter != 0) 
	{
        	safe=0;
        	for (i = 0; i < n; i++) 
		{
            		if (running[i]) 
			{
                		ex = 1;
                		for (j = 0; j < r; j++) 
				{
                    			if (remaning[i][j] > avail[j]) 
					{
                        			ex = 0;
                        			break;
                    			}
                		}
                		if (ex) 
				{
                    			printf("\nProcess%d is executing\n", i + 1);
                    			running[i] = 0;
                    			counter--;
                    			safe++;
 
                    			for (j = 0; j < r; j++) 
					{
                        			avail[j] += allocation[i][j];
                    			}
			                break;
                		}
            		}
        	}
        }
        
        	if (!safe) 
		{
            		printf("\nThe processes are in unsafe state.\n");
            		//break;
        	} 
		else 
		{
            		printf("\nThe process is in safe state");
            		printf("\nAvailable vector:");
 
            		for (i = 0; i < r; i++) 
			{
                		printf("\t%d", avail[i]);
            		}
 
		        printf("\n");
		        printf("Do you wish to add to allocated resource ,enter 1--YES  2--NO");
		        scanf("%d",&again);
		        if(again==1)
		        goto check;
		        	        
        	}
        	
    	
    	return 0;
}
	
    

