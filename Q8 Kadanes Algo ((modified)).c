//Kadanes algo is useful only when atleast one element is positive. 
//If all the elements are negative then it will return 0 which is wrong.
//I have modified it to handle this corner case. In case of a negative array, it returns the smallest negative element as the
//highest sum.

#include<stdio.h>
#include<limits.h> //to use INT_MAX macro

int mod(int a)
{
	int c=0;
	if(a<0)
	{
		c=(-1)*(a);
		return c;
	}
	else
	{
		return a;
	}
}

int main()
{
int a[100],i=0,n,maxSum,sum,start=0,end=0,s=0,count=0;

printf("\t\nKadane's algorithm!");
printf("\n\nHow many elements do you want? => ");
scanf("%d",&n);
printf("\t\nPlz start filling your elements one by one.");                //Time complexity is O(n) bcoz there is only one for
//feeding array                                                           //loop that spans entire array only once!

for(i=0;i<n;i++)
{
		printf("\nElement no. %d => ",i+1);
		scanf("%d",&a[i]);
}

//CORNER CASE
//check if the array is all negative     
for(i=0;i<n;i++)
{
		if(a[i]<0)
		{
			count++;
		}
}
int minElement=INT_MAX;
int p=0; //dummy
if(count==n)  //In case of a negative array, it returns the smallest negative element as the highest sum.
{
	for(i=0;i<n;i++)
	{
		p=mod(a[i]);
		if(p<minElement)  //pata hi hai ki saare negative hai
		{
			minElement=a[i];
		}
	}
	printf("\nAll elements are negative so the maximum sum is %d",minElement);
}
else //nhi to kadanes algo kaam karega aaram se
{
	maxSum=a[0];  //max sum so far
	sum=0;       //current subarray ki sum

	for(i=0;i<n;i++)
	{
		sum+=a[i];
		if(maxSum<sum)
		{
			maxSum=sum;
			start=s;
			end=i;
		}	
		if(sum<0)
		{
			sum=0;
			s=i+1;
		}	
	}
	printf("\nThe subarray with maximum sum is => ");
	for(i=start;i<=end;i++)
	{
		printf("%d ",a[i]);
	}

	printf("\nThe maximum sum is %d",maxSum);
}

return 0;
}
