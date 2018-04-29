//Round Robin Process Scheduling
#include<stdio.h>
#include<conio.h>
int main()
{
	int n,b[100],w[100],t[100],i,j,avgw=0,avgt=0,p[100],k=0,g,q,l[100],v=0,z[100];
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	k=n-1;
	printf("Enter the burst time of the processes\n");
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
		scanf("%d",&b[i]);
	}
	printf("Enter the time quantum\n");
	scanf("%d",&q);
	printf("\n");
	w[0]=0;
	for(i=0;i<=k;i++)
	{
		if(b[i]>q)
		{
			k++;
			w[i+1]=w[i]+q;
			b[k]=b[i]-q;
			p[k]=p[i];
		}
		else
			w[i+1]=w[i]+b[i];
	}
	
	for(g=0;g<n;g++)
	{
		for(i=0;i<=k;i++)
		{
			if((g+1)==p[i])
			{
				v++;
				z[g]=v;
			}
		}
		v=0;
	}

	for(g=0;g<n;g++)
	{
		for(i=0;i<=k;i++)
		{
			if((g+1)==p[i] && z[g]!=0)
			{
				if(z[g]!=1)
				{
					l[g]+=w[i];
					l[g]-=w[i+1];
					z[g]-=1;
				}
				else 
					l[g]+=w[i];
			}
		}
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("Waiting time for Process %d is %d\n",i+1,l[i]);
		avgw+=l[i];
	}
	printf("Average Waiting time is %f\n",(float)avgw/n);
	printf("\n");
	for(i=0;i<n;i++)
	{
		t[i]=l[i]+b[i];
		printf("Turn-around time for Process %d is %d\n",i+1,t[i]);
		avgt+=t[i];
	}
	printf("Average Turn-around time is %f\n",(float)avgt/n);
	printf("\nGantt Chart\n");
	for(i=0;i<=k;i++)
		printf("|   P%d\t", p[i]);
	printf("|");
	printf("\n");
	for(i=0;i<=k+1;i++)
		printf("%d\t", w[i]);
	return 0;
}
