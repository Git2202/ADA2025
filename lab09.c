#include<stdio.h>
#define max 100
double cmv(double w,double weight[],double value[],double ratio[],int nitems){
double cw=0;
double cv=0;
printf("\nitems:");
while(cw<w){
int items=getnextitems(weight,value,ratio,nitems);
if(items==-1){
break;
}
printf("Items: %d ",items+1);
if(cw+weight[items]<=w){
cw+=weight[items];
cv+=value[items];
ratio[items]=0;
}
else{
cv+=(ratio[items]*(w-cw));
cw+=(w-cw);
break;
}
}
return cv;
}
int getnextitems(double weight[],double value[],double ratio[],int nitems)
{
double highest=0;
int index=-1;
int i;
for(i=0;i<nitems;i++){
if(ratio[i]>highest){
highest=ratio[i];
index=i;
}
}
return index;
}
int main()
{
int nitems;
double w;
int i;
double weight[max];
double value[max];
double ratio[max];
printf("Enter the no of items:");
scanf("%d",&nitems);
printf("Enter the weight of the items:\n");
for(i=0;i<nitems;i++)
scanf("%lf",&weight[i]);
printf("Enter the values of the items:\n");
for(i=0;i<nitems;i++)
scanf("%lf",&value[i]);
for(i=0;i<nitems;i++)
ratio[i]=value[i]/weight[i];
printf("Enter the capacity of the knapsack");
scanf("%lf",&w);
printf("\nThe max value in a knapsack of capacity: %.2f is: %.2f\n",w,cmv(w,weight,value,ratio,nitems));
return 0;
}

