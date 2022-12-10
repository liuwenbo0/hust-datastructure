#include "stdio.h"
#include "stdlib.h"
#include<string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
typedef int status;
typedef int KeyType; 
typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef struct {
         KeyType  key;
         char others[20];
} VertexType; //顶点类型定义
typedef struct ArcNode {         //表结点类型定义
   		 int adjvex;              //顶点位置编号 
    	 struct ArcNode  *nextarc;	   //下一个表结点指针
} ArcNode;
typedef struct VNode{				//头结点及其数组类型定义
   		 VertexType data;       	//顶点信息
    	 ArcNode *firstarc;      	 //指向第一条弧
} VNode,AdjList[MAX_VERTEX_NUM];
typedef  struct {  //邻接表的类型定义
        AdjList vertices;     	 //头结点数组
        int vexnum,arcnum;   	  //顶点数、弧数
        GraphKind  kind;        //图的类型
} ALGraph;
struct ptr{
    void *pused[100],*pfree[100];
    int len_used,len_free;
    } pm;
typedef struct QNode{
	VertexType data;
	struct QNode *next;
}QNode,*Queue;
typedef struct{
	Queue front;
	Queue rear;
}Linkqueue;
void free0(void *p)
{
    pm.pfree[pm.len_free++]=p;
    memset(p,0,sizeof(ArcNode));
    free(p);
}
bool visited[MAX_VERTEX_NUM];
int pd;
void visit(VertexType v)
{
    printf(" %d %s",v.key,v.others);
}
status issame(VertexType V[])//判断顶点重复 
{
	int i=0;
	int mark[100000]={0};
	while(V[i].key!=-1)
	{
		if(mark[V[i].key]>0){return 1;}
		mark[V[i].key]++;
		i++;
	}
	return 0;
}
int Locate (ALGraph G,KeyType VR)
{
    int i=0;
    for(i;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key==VR) return i;
    }
    return -1;
}
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=0,j=0;
    while(V[i].key!=-1)
    {
        for(int k=0;k<i;k++)
        {
            if(V[i].key==V[k].key) return ERROR;
        }
        if(i>=MAX_VERTEX_NUM) return ERROR;
        G.vertices[i].data=V[i];
		G.vertices[i].firstarc=NULL;
		i++;
    }
    if(i==0) return ERROR;
    G.vexnum=i;
    while(VR[j][0]!=-1)
    {
        int a=Locate(G,VR[j][0]),b=Locate(G,VR[j][1]);
        if(!(a>=0&&b>=0)) return ERROR;
        ArcNode *q=(ArcNode*)malloc(sizeof(ArcNode)) ;
        q->adjvex=b;
        q->nextarc=G.vertices[a].firstarc;
        G.vertices[a].firstarc=q;
        q=(ArcNode*)malloc(sizeof(ArcNode)) ;
        q->adjvex=a;
        q->nextarc=G.vertices[b].firstarc;
        G.vertices[b].firstarc=q;
        j++;
    }
    G.arcnum=j;
    /********** End **********/
}

status DestroyGraph(ALGraph &G)
/*销毁无向图G,删除G的全部顶点和边*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    ArcNode *p=NULL,*q=NULL;
    for(int k=0;k<G.vexnum;k++)
    {
        if(G.vertices[k].firstarc!=NULL)
        {
            p=G.vertices[k].firstarc;
            while(p!=NULL)
            {
                q=p->nextarc;
                free(p);
                p=q;
            }
        G.vertices[k].firstarc=NULL;
        }
    }
    G.arcnum=0;
	G.vexnum=0;
    return OK;
    /********** End **********/
}

int LocateVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=0;
    for(i;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key==u) return i;
    }
    return -1;

    /********** End **********/
}
status PutVex(ALGraph &G,KeyType u,VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=0;
    for(i;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key==u) 
        {
            for(int k=0;k<G.vexnum;k++)
            {
                if(G.vertices[k].data.key==value.key) return ERROR;
            }
            G.vertices[i].data=value;  return OK;
        }
    }
    return ERROR;  

    /********** End **********/
}

int FirstAdjVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=0;
    for(i;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key==u) 
        {
            return G.vertices[i].firstarc->adjvex;
        }
    }
    return -1;

    /********** End **********/
}

int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//v对应G的一个顶点,w对应v的邻接顶点；操作结果是返回v的（相对于w）下一个邻接顶点的位序；如果w是最后一个邻接顶点，或v、w对应顶点不存在，则返回-1。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=LocateVex(G,v),j=LocateVex(G,w);
    while(i!=-1&&j!=-1)
    {
        ArcNode *p=G.vertices[i].firstarc;
        while(p->adjvex!=j&&p)
        {
            p=p->nextarc;
        }
        if(p->nextarc)
        {
            return p->nextarc->adjvex;
        }
        else return -1;
    }
    return -1;
    /********** End **********/
}
status InsertVex(ALGraph &G,VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(LocateVex(G,v.key)>=0) return ERROR;
    if(G.vexnum==MAX_VERTEX_NUM) return ERROR;
    G.vertices[G.vexnum].data=v;
    G.vertices[G.vexnum].firstarc=NULL;
    G.vexnum++;
    return OK;
    /********** End **********/
}


status DeleteVex(ALGraph &G,KeyType v)
//在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=LocateVex(G,v),j=-1;
    if(i==-1) return ERROR;
    if(G.vexnum==1 || G.vexnum==0)return ERROR;
    ArcNode *p=G.vertices[i].firstarc;
    ArcNode *q=NULL;
    ArcNode *temp=NULL;
    while(p)
    {  
        j=p->adjvex;
        q=G.vertices[j].firstarc;
        if(q->adjvex==i)
        {
            temp=q;
            G.vertices[j].firstarc=q->nextarc;
            free(temp); 
        }
        else
        {
            while(q->nextarc->adjvex!=i)
            {
                q=q->nextarc;
            }
            temp=q->nextarc;
            q->nextarc=temp->nextarc;
            free(temp);
        }
        temp=p->nextarc;
        free(p);
        p=temp;
        G.arcnum--;
    }
    for(int k=i;k<G.vexnum;k++)
    {
        G.vertices[k]=G.vertices[k+1];
    }
    G.vexnum--;
    for(int k=0;k<G.vexnum;k++)
	{
		p=G.vertices[k].firstarc;
		while(p!=NULL)
		{
			if(p->adjvex>i)
			p->adjvex--;
			p=p->nextarc;
		}
	}
    return OK;
    /********** End **********/
}
status Locatearc(ALGraph G,KeyType v,KeyType w)
{
	ArcNode *p=G.vertices[v].firstarc;
	while(p!=NULL)
	{
		if(p->adjvex==w)
		return OK;
		p=p->nextarc;
	}
	return ERROR;
}
int LocateArc(ALGraph G,KeyType v,KeyType w)
{
    int i=LocateVex(G,v);
    int j=LocateVex(G,w);
    if(i==-1||j==-1) return ERROR;
    ArcNode *p=G.vertices[i].firstarc;
	while(p!=NULL)
	{
		if(p->adjvex==j)
		return OK;
		p=p->nextarc;
	}
	return ERROR;
}
status InsertArc(ALGraph &G,KeyType v,KeyType w)
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=LocateVex(G,v);
    int j=LocateVex(G,w);
    if(i==-1||j==-1) return ERROR;
    if(LocateArc(G,v,w)!=ERROR) return ERROR;
    ArcNode *p=(ArcNode*)malloc(sizeof(ArcNode));
    p->adjvex=j;
    p->nextarc=G.vertices[i].firstarc;
    G.vertices[i].firstarc=p;
    p=(ArcNode*)malloc(sizeof(ArcNode));
    p->adjvex=i;
    p->nextarc=G.vertices[j].firstarc;
    G.vertices[j].firstarc=p;
    G.arcnum++;
    return OK;
    /********** End **********/
}
status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(LocateArc(G,v,w)==ERROR) return ERROR;
    int i=LocateVex(G,v);
    int j=LocateVex(G,w);
    ArcNode *p=G.vertices[i].firstarc;
    ArcNode *temp=NULL;
    if(p->adjvex==j)
    {
        temp=p;
        G.vertices[i].firstarc=p->nextarc;
        free(temp);
    }
    else 
    {
        while(p->nextarc->adjvex!=j)
        {
            p=p->nextarc;
        }
        temp=p->nextarc;
        p->nextarc=p->nextarc->nextarc;
        free(temp);
    }
    p=G.vertices[j].firstarc;
    temp=NULL;
    if(p->adjvex==i)
    {
        temp=p;
        G.vertices[j].firstarc=p->nextarc;
        free(temp);
    }
    else 
    {
        while(p->nextarc->adjvex!=i)
        {
            p=p->nextarc;
        }
        temp=p->nextarc;
        p->nextarc=p->nextarc->nextarc;
        free(temp);
    }
    G.arcnum--;
    return OK;
    /********** End **********/
}
void dfs(ALGraph &G,KeyType v,void(*visit)(VertexType))
{
	visited[v]=TRUE;
	int x=LocateVex(G,v);
	visit(G.vertices[x].data);
	for(int w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,G.vertices[w].data.key)) 
	{
		if(!visited[G.vertices[w].data.key])dfs(G,G.vertices[w].data.key,
		visit);
	}
}
status DFSTraverse(ALGraph &G,void(*visit)(VertexType))
{
	int i;
	for(i=0;i<G.vexnum;i++)
	visited[G.vertices[i].data.key]=FALSE;//标记数组记录关键字 
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[G.vertices[i].data.key])
		{
			dfs(G,G.vertices[i].data.key,visit);
		
		}
	}
	return OK;
 } 
status InitQueue(Linkqueue &Q)
{
	Q.front=Q.rear=(QNode *)malloc(sizeof(QNode));
	if(!Q.front)return ERROR;
	Q.front->next=NULL;
	return OK;
} 
status QueueEmpty(Linkqueue Q)
{
	if(Q.front==Q.rear)return TRUE;
	else return FALSE;
}
status enQueue(Linkqueue &Q,VertexType value)
{
	Queue p=(Queue)malloc(sizeof(QNode));
	if(!p)return ERROR;
	p->data=value;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
}
status deQueue(Linkqueue &Q,VertexType &value)
{
	if(Q.front==Q.rear)return ERROR;
	Queue p=Q.front->next;
	value=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
	Q.rear=Q.front;
	free(p);
	return OK;
}
status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
	int i=0,j;
	VertexType value;
	Linkqueue Q;
	InitQueue(Q);
	for(i=0;i<G.vexnum;i++)
	{
		visited[G.vertices[i].data.key]=FALSE;
	}
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[G.vertices[i].data.key])
		{
			visited[G.vertices[i].data.key]=TRUE;
			visit(G.vertices[i].data);
			enQueue(Q,G.vertices[i].data);
			while(!QueueEmpty(Q))
			{
				deQueue(Q,value);
				for(int w=FirstAdjVex(G,value.key);w>=0;w=NextAdjVex(G,value.key,G.vertices[w].data.key))
				{
					if(!visited[G.vertices[w].data.key])
					{
						visited[G.vertices[w].data.key]=TRUE;
						visit(G.vertices[w].data);
						enQueue(Q,G.vertices[w].data);
					}
				 } 
			}
		}
	}
	return OK;
}
status SaveGraph(ALGraph G, char FileName[])
//将图的数据写入到文件FileName中
{
    FILE *fp=fopen(FileName,"w");
    fprintf(fp,"%d %d ",G.vexnum,G.arcnum);
    int i=0;
    for(i=0;i<G.vexnum;i++)
   {
	fprintf(fp,"%d,%s ",G.vertices[i].data.key,G.vertices[i].data.others);
	ArcNode *p=G.vertices[i].firstarc;
	while(p!=NULL)
	{
		fprintf(fp,"%d ",p->adjvex);
		p=p->nextarc;
	}
	fprintf(fp,"%d ",-1);
    }
    fclose(fp);
    return OK;
}
#include<string.h>
status LoadGraph(ALGraph &G, char FileName[])
//读入文件FileName的图数据，创建图的邻接表
{
    FILE *fp=fopen(FileName,"r");
    char c,d;
    char other[20];
    int i,j,k;
    fscanf(fp,"%d%d",&G.vexnum,&G.arcnum);
    for(i=0;i<G.vexnum;i++)
    {
    	fscanf(fp,"%d%c%s",&k,&c,other);
    	G.vertices[i].data.key=k;
        strcpy(G.vertices[i].data.others,other);
    	j=0;
    	ArcNode *rear=G.vertices[i].firstarc=NULL;
    	while(j!=-1)
    	{
    		fscanf(fp,"%d",&j);
    		if(j!=-1){
    		ArcNode *p=(ArcNode *)malloc(sizeof(ArcNode));
    		p->adjvex=j;
    		p->nextarc=NULL;
    		if(G.vertices[i].firstarc==NULL)
    		{
    			G.vertices[i].firstarc=p;
    			rear=G.vertices[i].firstarc;
			}
			else{
    		rear->nextarc=p;
    		rear=p;
    	}
    	}
		}
		rear=NULL;
	}
	fclose(fp);
	return OK;
}
int distance[21];
status ShortestPathLength(ALGraph G,KeyType v,KeyType w)//返回顶点v与顶点w的最短路径长度 
{
	int i,j,n;
	VertexType top;
	top.key=v;
	Linkqueue Q;
	InitQueue(Q);
	for(i=0;i<G.vexnum;i++)
	distance[G.vertices[i].data.key]=20;
	distance[v]=0;
	int k=LocateVex(G,v);
	enQueue(Q,G.vertices[k].data);
	while(!QueueEmpty(Q))
	{
		deQueue(Q,top);
		if(top.key==w)break;
		for(j=FirstAdjVex(G,top.key);j>=0;j=NextAdjVex(G,top.key,G.vertices[j].data.key))//返回位序 
		{
			if(distance[G.vertices[j].data.key]==20)
			{
				distance[G.vertices[j].data.key]=distance[top.key]+1;
				enQueue(Q,G.vertices[j].data);
			}
		}
	}
	n=distance[w];
	return n;
}
void VerticesSetLessThank(ALGraph G,KeyType v,KeyType k)//返回与顶点v距离小于k的顶点集合 
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
	{
		j=ShortestPathLength(G,v,G.vertices[i].data.key);
		if(j<k&&G.vertices[i].data.key!=v)
		visit(G.vertices[i].data);
	}
}
bool mark[20];
void dfs(ALGraph &G,KeyType v)
{
	mark[v]=TRUE;
	for(int w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,G.vertices[w].data.key)) 
	{
		if(!mark[G.vertices[w].data.key])dfs(G,G.vertices[w].data.key);
	}
}
status ConnectedComponentsNums(ALGraph G)//求图中连通分量个数 
{
	int count=0,i;
	for(i=0;i<G.vexnum;i++)
	mark[G.vertices[i].data.key]=FALSE;//标记数组记录关键字 
	for(i=0;i<G.vexnum;i++)
	{
		if(!mark[G.vertices[i].data.key])
		{
			dfs(G,G.vertices[i].data.key);
			count++;
		}
	}
	return count;
 } 
int main(){
  int op=1,flag,x;
  ALGraph G;
  G.arcnum=0,G.vexnum=0;
VertexType V[30];
VertexType value;
KeyType VR[100][2];
int i=0,j,e,v,w,k;
char filename[20];
char name[20];
while(op){
	system("cls");	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. CreateGraph                 2. DestroyGraph\n");
	printf("    	  3. LocateVex                   4. PutVex\n");
	printf("    	  5. FirstAdjVex                 6. NextAdjVex \n");
	printf("    	  7. InsertVex                   8. DeleteVex\n");
	printf("    	  9. InsertArc                   10. DeleteArc\n");
	printf("    	  11. DFSTraverse                12. BFSTraverse\n");
	printf("          13.VerticesSetLessThank        14.ShortestPathLength\n");
	printf("          15.ConnectedComponentsNums     16.SaveGraph\n");
	printf("          17.LoadGraph                   18.ArcTraverse\n");
	printf("    	  19.AssignVex\n");
	printf("    	  0.Exit\n");
	printf("-------------------------------------------------\n");
	printf("    请选择你的操作:");
	scanf("%d",&op);
    switch(op){
	   case 1:
	   	i=0;
	   	if(pd)printf("图已存在请先销毁！\n");
	   	else{
	   	printf("请输入无向图的顶点序列和关系对序列,");
	   	printf("并以-1作为结束标记！\n"); 
		  do {
       scanf("%d%s",&V[i].key,V[i].others);
       } while(V[i++].key!=-1);
        i=0;
     do{
        scanf("%d%d",&VR[i][0],&VR[i][1]);
      } while(VR[i++][0]!=-1);
        if(CreateCraph(G,V,VR)==OK)printf("创建无向图成功！\n");
        else printf("创建无向图失败！\n");
    }
		 getchar();getchar();
		 break;
	   case 2:  
	     if(G.vexnum==0)printf("销毁失败，请先创建图！\n");
	     else{
	     if(DestroyGraph(G)==OK)printf("销毁成功！\n");
		 else printf("销毁失败，请先创建图！\n"); 
	}
		 getchar();getchar();
		 break;
	   case 3:
	   	  if(G.vexnum==0)printf("图不存在！\n");
	   	  else{
         printf("请输入要查找顶点的关键字！\n");
         scanf("%d",&e);
          if(LocateVex(G,e)==-1)printf("图中不存在该顶点！\n");
         else 
		 {
		 	x=LocateVex(G,e);
		  printf("该顶点的位序是%d\n",x);
		  printf("其值为 %d %s\n",G.vertices[x].data.key,G.vertices[x].data.others);
	}
     }
		 getchar();getchar();
		 break;
	   case 4:
	   	if(G.vexnum==0)printf("图不存在！\n");
	   	else{
		 printf("请输入要修改顶点的关键字和修改后的关键字和值！\n");
		 scanf("%d",&j);
		 scanf("%d%s",&value.key,value.others);
		  if(LocateVex(G,j)==-1 || LocateVex(G,j)==-2)printf("该顶点不存在！\n"); 
		  else if(PutVex(G,j,value)==OK)printf("修改成功！\n");
		  else printf("修改失败！\n");
	}
		 getchar();getchar();
		 break;
	   case 5:
	   	if(G.vexnum==0)printf("图不存在！\n");
	   	else{
	     printf("请输入要查找第一邻接顶点的关键字！\n");
	     scanf("%d",&e);
	     if(FirstAdjVex(G,e)==-1)printf("查找失败！\n");
	     else{
	     	x=FirstAdjVex(G,e);
		  printf("该顶点的第一邻接顶点的位序为%d\n",x);
		  printf("其值为%d %s\n",G.vertices[x].data.key,G.vertices[x].data.others);
	}
	 }
		 getchar();getchar();
		 break;
	   case 6:
	   	  if(G.vexnum==0)printf("图不存在！\n");
	   	  else{
		  printf("请输入要查找顶点和相对顶点的关键字！\n");
		  scanf("%d%d",&v,&w);  
		   if(NextAdjVex(G,v,w)==-1)printf("查找失败！\n");
		   else {
		   	x=NextAdjVex(G,v,w);
		   printf("顶点%d的邻接顶点相对于%d的下一邻接顶点的位序是%d\n",v,w,x);
		   printf("其值为 %d %s\n",G.vertices[x].data.key,G.vertices[x].data.others); 
	}
	}
		 getchar();getchar();
		 break;
	   case 7:
		  printf("请输入要插入结点的值！\n");
		  scanf("%d%s",&value.key,value.others);
		  if(InsertVex(G,value)==OK)printf("插入成功！\n");
		  else printf("插入失败！\n");
		 getchar();getchar();
		 break;
	   case 8:
	   	   if(G.vexnum==0)printf("图不存在！\n");
	   	   else{
		    printf("请输入要删除顶点的关键字！\n");
		    scanf("%d",&v);
		    if(DeleteVex(G,v)==OK)printf("删除成功！\n");
		    else printf("删除失败！\n");
		}
		 getchar();getchar();
		 break;
	   case 9:
	   	if(G.vexnum==0)printf("图不存在！\n");
	   	else{
		   printf("请输入要插入弧对应的两个顶点！\n");
		   scanf("%d%d",&v,&w);
		   if(InsertArc(G,v,w)==OK)printf("插入弧成功！\n");
		   else printf("插入弧失败！\n");
	}
		 getchar();getchar();
		 break;
	   case 10:
	   	    if(G.vexnum==0)printf("图不存在！\n");
	   	    else{
		     printf("请输入要删除弧对应的两个顶点！\n");
		     scanf("%d%d",&v,&w);
			 if(DeleteArc(G,v,w)==OK)printf("删除弧成功！\n");
			 else printf("删除弧失败！\n"); 
	}
		 getchar();getchar();
		 break;
	   case 11:
	   	if(G.vexnum==0)printf("图不存在！\n");
	   	else{
	    				printf("---------------深度优先遍历---------------\n");
			    		DFSTraverse(G,visit); 
			    		printf("\n------------------end-----------------\n");
		}
		 getchar();getchar();
		 break;
	   case 12:
	   	if(G.vexnum==0)printf("图不存在！\n");
	   	else{
	    				printf("---------------广度优先遍历---------------\n");
			    		BFSTraverse(G,visit); 
			    		printf("\n------------------end-----------------\n");
		}
		getchar();getchar();
		 break;
		case 13:
			printf("请输入顶点的关键字及查找距离！\n");
			scanf("%d%d",&v,&k);
			printf("与顶点距离小于%d的顶点有\n",k);
			VerticesSetLessThank(G,v,k); 
			getchar();getchar();
			break;
		case 14:
			printf("请输入两个顶点的关键字!\n");
			scanf("%d%d",&v,&w);
			k=ShortestPathLength(G,v,w);
			if(k!=20){
			printf("这两个顶点间的最短路径是%d",k);
		}
		else
		printf("这两个顶点之间不存在路！\n");
			getchar();getchar();
			break;
		case 15:
			printf("图的连通分量有%d个！\n",ConnectedComponentsNums(G));
			getchar();getchar();
			break;
		case 16:
			if(G.vexnum==0)printf("请先创建图！\n");
			else{
			printf("请输入文件名！\n");
			scanf("%s",filename);
			if(SaveGraph(G,filename)==OK)printf("图文件读取成功！\n");
			else printf("图文件读取失败！\n");
		}
			getchar();getchar();
			break;
		case 17:
			printf("请输入文件名！\n");
			scanf("%s",filename);
			if(LoadGraph(G,filename)==OK)printf("图写入成功！\n");
			else printf("图写入失败！\n");
			getchar();getchar();
			break;
		case 18:
			if(G.vexnum==0)printf("图不存在！\n");
			else{
			for(i=0;i<G.vexnum;i++)
      {
     ArcNode *p=G.vertices[i].firstarc;
     printf("%d %s",G.vertices[i].data.key,G.vertices[i].data.others);
     while (p)
     {
         printf(" %d",p->adjvex);
         p=p->nextarc;
     }
     printf("\n");
      }
  }
  case 19:
	   	if(G.vexnum==0)printf("图不存在！\n");
	   	else{
		 printf("请输入要修改顶点的关键字和要修改为的关键字和值！\n");
		 scanf("%d",&j);
		 scanf("%d%s",&value.key,value.others);
		  if(LocateVex(G,j)==-1 || LocateVex(G,j)==-2)printf("顶点不存在！\n"); 
		  else if(PutVex(G,j,value)==OK)printf("修改成功！\n");
		  else printf("修改失败！\n");
	}
     getchar();getchar();
	 break; 
        default:
		   printf("输入有误，请重新输入!\n");
		getchar();getchar();
		  break; 
	}//end of switch
  }//end of while
printf("欢迎下次再使用本系统！\n");
}//end of main()



