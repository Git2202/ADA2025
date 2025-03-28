#include<stdio.h>
void readgraph(int n,int a[10][10])
{
int i,j;
for(i=0;i<n;i++){
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
}}
void findindegree(int n,int a[10][10],int indegree[])
{
int i,j,sum;
for(j=0;j<n;j++){
sum=0;
for(i=0;i<n;i++)
sum+=a[i][j];
indegree[j]=sum;
}}
void topo(int n,int a[10][10])
{
int i,k=0,u,v,top,t[10],indegree[10],s[10];
findindegree(n,a,indegree);
top=-1;
for(i=0;i<n;i++){
if(indegree[i]==0)
s[++top]=i;
while(top!=-1){
u=s[top--];
t[k++]=u;
for(v=0;v<n;v++){
if(a[u][v]==1){
indegree[v]--;
if(indegree[v]==0){
s[++top]=v;
}}}}
printf("The Topological sort sequence is:\n");
for(i=0;i<n;i++)
printf("%d ",t[i]);
}}
void main()
{
int n,a[10][10];
printf("Enter the no of values");
scanf("%d",&n);
printf("Enter the adjacency matrix\n");
readgraph(n,a);
topo(n,a);
}