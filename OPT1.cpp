//Optimum Page Replacement 
#include<stdio.h>
#include<conio.h>
int main()
{
	int f,a[100],b[100]={0},i,n,k,j,t=0,h=0,m=0,l=0,p,u=0,e=0,q=0,x=0;
	printf("Enter the number of frames\n");
	scanf("%d",&f);
	e=f;
	printf("Enter the number of pages\n");
	scanf("%d",&n);
	printf("Enter the pages\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	printf("\n");
	for(i=0;i<n;i++)
	{
		if(i<f||u<f)
		{
			for(j=0;j<f;j++)
			{
				if(a[i]==b[j])
				{
					t++;
					h++;
					break;
				}
			}
			if(t==0)
			{
				m++;
				b[l]=a[i];
				u++;
				l++;
			}
			t=0;
		}
		else
		{
			for(j=0;j<f;j++)
			{
				if(a[i]==b[j])
				{
					t++;
					h++;
					break;
				}
			}
			if(t==0)
			{
				m++;
				for(p=0;p<f;p++)
				{
					for(j=i+1;j<n;j++)
					{
						if(b[p]!=a[j] && x==0)
						{
							q++;
						}
						else if(b[p]==a[j])
						{
							e=p;
							x++;
							q=0;
						}
					}
					if(q!=0)
					{
						b[p]=a[i];
						break;
					}
					x=0;
				}
				if(q==0)
					b[e]=a[i];
			}
			t=0;
		}
		if(u<f)
		{
			for(p=0;p<u;p++)
				printf("%d ",b[p]);
		}
		else
		{
			for(p=0;p<f;p++)
				printf("%d ",b[p]);
		}
		printf("\n");
	}

	printf("No of Hits : %d\n",h);
	printf("No of Miss : %d",m);
	return 0;
}
