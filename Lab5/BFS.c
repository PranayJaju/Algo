#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

/*int q[50];
int front = -1;
int rear = -1;
int dq(){
if(front == -1) return -1;
else return q[front++];
}
void queue(int n){
if(n==49) printf("FULL");
else q[++rear]=n;
if(front == -1) front++;
}*/

void BFS(int** adjMat, int* vis, int ver, int n)
{
	Queue* q=(Queue*)malloc(sizeof(Queue));
	q->queue=(int*)calloc(50, sizeof(int));
    q->front=-1;
    q->rear=-1;
	enqueue(q,ver);
	while(q->front<=q->rear)
	{
		ver=dequeue(q);
		display(q);
		printf("%dc  ", ver);
		*(vis+ver)=1;
		for(int i=0; i<n; i++)
			if(!*(vis+i) && *(*(adjMat+ver)+i))
			{
				enqueue(q,ver);
				*(vis+i)=1;
			}
	}
}

int** AdjMat(int n)//taking adjacency matrix as input
{
	int** AM=(int**)malloc(sizeof(int*)*n);
	for(int i=0; i<n; i++)
		*(AM+i)=(int*)calloc(n,sizeof(int));
	
	printf("Enter Adjacent Matrix.\n");
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", *(AM+i)+j);

	return AM;
}

int main()
{
	int n, ver;
	printf("Enter no.of vertices.\n");
	scanf("%d", &n);
	int** AM=AdjMat(n);
	int* vis=(int*)calloc(n,sizeof(int));
	printf("Enter vertex to start from.\n");
	scanf("%d", &ver);
	printf("BFS: ");
	BFS(AM,vis,ver,n);
	printf("\n");
}

/*void main(){
int AM[6][6]= {{0, 1, 1, 0, 0, 0},
{1, 0, 0, 0, 1, 0},
{1, 0, 0, 1, 1, 1},
{0, 0, 1, 0, 0, 1},
{0, 1, 1, 0, 0, 1},
{0, 0, 1, 1, 1, 0}};
int vis[6]={0,0,0,0,0,0};
int ver = 2;
queue(ver);
while(front<=rear){
ver = dq();
printf("%d ",ver);
vis[ver]=1;
for(int i=0; i<6; i++){
if(!vis[i] && AM[ver][i]){
queue(i);
vis[i]=1;}
}
}
}*/