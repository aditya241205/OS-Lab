#include<stdio.h>
int main(){
int n,i;

printf("Enter number of processes:\n");
scanf("%d",&n);

int at[n],bt[n],rem_bt[n];
int ct[n],tat[n],wt[n];

for(int i =0;i<n;i=i+1){
printf("enter arrival time of processess:%d:\n",i+1);
scanf("%d",&at[i]);

printf("enter burst time of processess:%d:\n",i+1);
scanf("%d",&bt[i]);
rem_bt[i] = bt[i];
ct[i] = 0;
tat[i] = 0;
wt[i] = 0;
}
int tq;
printf("Enter time quantum:");
scanf("%d",&tq);

int time =0;
int completed = 0;
while(completed <n){
for(i=0;i<n;i=i+1){
if(at[i] <= time && rem_bt[i] >0){
if(rem_bt[i] <= tq){
time +=rem_bt[i];
rem_bt[i] = 0;
ct[i] = time;
completed = completed +1;
}
else{
time = time + tq;
rem_bt[i] = rem_bt[i] -tq;
}
}
}
int ready = 0;
for(i =0;i<n;i=i+1){
if(at[i] <= time && rem_bt[i] >0){
ready =1;
}
}
if(ready ==0){
time = time + 1;
}
}
for( i =0;i<n;i=i+1){
tat[i] = ct[i] - at[i];
wt[i] = tat[i] -bt[i];
}
float avg_wt = 0;
float avg_tat = 0;

printf("\nprocess\tAT\tBT\tCT\tTAT\tWT\n");
for(i=0;i<n;i=i+1){
printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
avg_wt = avg_wt +wt[i];
avg_tat = avg_tat +tat[i];
}
avg_wt = avg_wt /n;
avg_tat = avg_tat /n;
printf("avg waiting time = %.2f\n",avg_wt);
printf("avg tat =%.2f\n",avg_wt);
}
