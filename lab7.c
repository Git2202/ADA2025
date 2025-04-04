#include<stdio.h>
#define Max 10
int knapSack(int W,int wt[],int val[],int n)
{
int i,j;
int v[Max+1][W+1];

for(i=0;i<=n;i++){
for(j=0;j<=W;j++){
if(i==0 || j==0){
v[i][j]=0;
}
else if(j-wt[i]<0){
v[i][j]=v[i-1][j];
}
else{
v[i][j]=max(v[i-1][j]
,val[i]+v[i-1][j-wt[i]]);
}}}
return v[n][W];
}
int max(int a,int b){
return (a>b)?a:b;
}
int main()
{
int n,i,W,wt[Max],val[Max];
printf("Enter the number of items:");
scanf("%d",&n);
printf("Enter the weights:\n");
for(i=1;i<=n;i++)
scanf("%d",&wt[i]);
printf("Enter the profit/values:\n");
for(i=1;i<=n;i++)
scanf("%d",&val[i]);
printf("Enter the maximum capacity:");
scanf("%d",&W);
int profit=knapSack(W,wt,val,n);
printf("Max Profit is:%d\n",profit);
}
