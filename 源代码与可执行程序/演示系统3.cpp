#include "stdio.h"
#include "stdlib.h"
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int KeyType;
typedef struct {
     KeyType  key;
     char others[20];
} TElemType; //二叉树结点类型定义

typedef struct BiTNode{  //二叉链表结点的定义
      TElemType  data;
      struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

status CreateBiTree(BiTree &T,TElemType definition[]);
status DestroyBiTree(BiTree &T);
status ClearBiTree(BiTree &T);
status BiTreeEmpty(BiTree &T);
int BiTreeDepth(BiTree T);
BiTNode* LocateNode(BiTree T,KeyType e);
status Assign(BiTree &T,KeyType e,TElemType value);
BiTNode* GetSibling(BiTree T,KeyType e);
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c);
status DeleteNode(BiTree &T,KeyType e);
status PreOrderTraverse(BiTree T,void (*visit)(BiTree));
status InOrderTraverse(BiTree T,void (*visit)(BiTree));
status PostOrderTraverse(BiTree T,void (*visit)(BiTree));
status LevelOrderTraverse(BiTree T,void (*visit)(BiTree));
status MaxPathSum(BiTree T);
BiTNode* LowestCommonAncestor(BiTree T,KeyType e1,KeyType e2);
status InvertTree(BiTree &T);
status SaveBiTree(BiTree T, char FileName[]);
status LoadBiTree(BiTree &T, char FileName[]);
void CTree(BiTree &T,TElemType *&definition);
int check(BiTree T,TElemType value);
void pr(BiTree T,FILE* fout);
void read(BiTree& T,FILE* fin);
int MPS(BiTree T,int &ans);
int max(int x,int y)
{
    return x>y?x:y;
}
void Visit(BiTree T)
{
    printf(" %d,%s",T->data.key,T->data.others);
}
int pd;
TElemType val,definition[100];
/*----------------main----------------*/
int main()
{
	int op=1,flag=0,i,lr;
	KeyType key,key1,key2;

	BiTree T=NULL;
	BiTNode* t;
	char FileName[30],TreeName[30];
	T=NULL; 
	while(op){
		system("cls");	printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("----------------------------------------------------------------\n");
		printf("    	  1. CreateBiTree            2. DestroyBiTree\n");
		printf("    	  3. ClearBiTree             4. BiTreeEmpty\n");
		printf("    	  5. BiTreeDepth             6. LocateNode\n");
		printf("    	  7. Assign                  8. GetSibling\n");
		printf("    	  9. InsertNode              10. DeleteNode\n");
		printf("    	  11. PreOrderTraverse       12. InOrderTraverse\n");
		printf("    	  13. PostOrderTraverse      14. LevelOrderTraverse\n");
		printf("    	  15. MaxPathSum             16. LowestCommonAncestor\n");
		printf("    	  17. InvertTree             18. SaveBiTree\n");
		printf("    	  19. LoadBiTree             0. Exit\n");
		printf("----------------------------------------------------------------\n");
		printf("    请选择你的操作[0~23]:");
		scanf("%d",&op);
	    switch(op){
	    	case 1:
	    		if(pd)  printf("二叉树已存在，创建失败！\n");
                else
                {
                    printf("请输入带空节点的先序遍历！\n");
                    i=0;
                    do
                    {
                        scanf("%d%s",&definition[i].key,definition[i].others);
                    } while (definition[i++].key!=-1);
                    flag=CreateBiTree(T,definition);
                    if(flag==1)printf("二叉树创建成功！\n");
                    else if(flag==0)printf("二叉树创建失败！\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 2:
	    		flag=DestroyBiTree(T);
	    		if(flag==1)printf("二叉树销毁成功！\n");
                else printf("二叉树销毁失败！\n");
	    		getchar();getchar();
	    		break;
	    	case 3:
	    		if(!pd)printf("二叉树不存在！\n");
                else
                {
                    flag=ClearBiTree(T);
                    if(flag==OK)printf("二叉树清空成功！\n");
                    else printf("二叉树清空失败！\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 4:
	    		flag=BiTreeEmpty(T);
	    		if(flag==1)printf("二叉树为空！\n");
                else if(flag==0)printf("二叉树不为空！\n");
                else printf("二叉树不存在！\n");
	    		getchar();printf("输入回车以继续!");getchar();
	    		break;
	    	case 5:
	    		flag=BiTreeDepth(T);
	    		if(flag!=-1) printf("二叉树的深度为%d。\n",flag);
                else printf("二叉树不存在！\n");
	    		getchar();getchar();
	    		break;
	    	case 6:
				if(!pd)printf("二叉树不存在！\n");
                else
                {
                    printf("输入你要查找的结点的关键字：");
                    scanf("%d",&key);
                    t=LocateNode(T,key);
                    if(t)  printf("该结点的值为%s。\n",t->data.others);
                    else   printf("无关键字为%d的结点！\n",key);
                }
	    		getchar();getchar();
	    		break;
	    	case 7:
	    		if(!pd)  printf("二叉树不存在！\n");
                else
                {
                    printf("请输入你要修改结点的关键字以及修改后的关键字和值：");
                    scanf("%d%d%s",&key,&val.key,val.others);
                    flag=Assign(T,key,val);
                    if(flag==1)printf("结点修改成功！\n");
                    else printf("结点修改失败！\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 8:
	    		if(!pd)  printf("二叉树不存在！\n");
                else
                {
                    printf("输入你要获取兄弟结点的关键字：");
                    scanf("%d",&key);
                    t=GetSibling(T,key);
                    if(t)  printf("兄弟结点为(%d,%s)。\n",t->data.key,t->data.others);
                    else printf("无该节点或其无兄弟！\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 9:
	    		if(!pd)  printf("二叉树不存在！\n");
                else
                {
                    printf("输入关键字、插入位置、新结点的关键字、新节点的值：");
                    scanf("%d%d%d%s",&key,&lr,&val.key,val.others);
                    flag=InsertNode(T,key,lr,val);
                    if(flag==1)printf("插入结点成功！\n");
                    else printf("插入结点失败！\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 10:
	    		if(!pd)  printf("二叉树不存在！\n");
                else
                {
                    printf("输入要删除的结点的关键字：");
                    scanf("%d",&key);
                    flag=DeleteNode(T,key);
                    if(flag==1)printf("删除结点成功！\n");
                    else printf("删除节点失败！\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 11:
	    		if(!pd)  printf("二叉树不存在！\n");
                else
                {
                    printf("---------------前序遍历---------------\n");
                    PreOrderTraverse(T,Visit);
                    printf("\n------------------end-----------------\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 12:
	    		if(!pd)  printf("二叉树不存在！\n");
                else
                {
                    printf("---------------中序遍历---------------\n");
                    InOrderTraverse(T,Visit);
                    printf("\n------------------end-----------------\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 13:
	    		if(!pd)  printf("二叉树不存在！\n");
                else
                {
                    printf("---------------后序遍历---------------\n");
                    PostOrderTraverse(T,Visit);
                    printf("\n------------------end-----------------\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 14:
	    		if(!pd)  printf("二叉树不存在！\n");
                else
                {
                    printf("---------------层序遍历---------------\n");
                    LevelOrderTraverse(T,Visit);
                    printf("\n------------------end-----------------\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 15:
	    		if(!pd)  printf("二叉树不存在！\n");
                else
                {
                    printf("最大路径和为：%d。\n",MaxPathSum(T));
                }
	    		getchar();getchar();
	    		break;
	    	case 16:
	    		if(!pd) printf("二叉树不存在！\n");
                else
                {
                    printf("输入你要查找最近公共祖先的两个关键字：");
                    scanf("%d%d",&key1,&key2);
                    t=LowestCommonAncestor(T,key1,key2);
                    if(t)printf("最近公共祖先为(%d,%s)。\n",t->data.key,t->data.others);
                    else printf("查找失败！\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 17:
	    		if(!pd) printf("二叉树不存在！\n");
                else
                {
                    flag=InvertTree(T);
                    if(flag==1)  printf("二叉树翻转成功！\n");
                    else printf("二叉树翻转失败！\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 18:
	    		if(!pd)  printf("二叉树不存在！\n");
                else
                {
                    printf("输入你要存入的文件名：");
                    scanf("%s",FileName);
                    flag=SaveBiTree(T,FileName);
                    if(flag==1)printf("二叉树存入成功！\n");
                    else printf("二叉树存入失败！\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 19:
	    		if(pd)  printf("二叉树已存在，请先销毁！\n");
                else
                {
                    printf("输入你要读取的文件名：");
                    scanf("%s",FileName);
                    flag=LoadBiTree(T,FileName);
                    if(flag==1)printf("二叉树读取成功！\n");
                    else printf("二叉树读取失败！\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 0:
	    		break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
	getchar();getchar();
}//end of main
/*--------------此为分割线---------------*/
status CreateBiTree(BiTree &T,TElemType definition[])
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    static TElemType *p=definition;
    if(p->key==-1)
    {
        T=NULL;
        return OK;
    }
    
        if(!p->key)
        {
            T=NULL;
            p++;
            return OK;
        }
        else
        {
            TElemType *q=definition;
            while(q<p)
            {
                if(q->key==p->key) return ERROR;
                else q++;
            }
            T=(BiTree)malloc(sizeof(BiTNode));
            T->data=*p;
            p++;
            if(CreateBiTree(T->lchild,definition)&&CreateBiTree(T->rchild,definition))
            return OK;
        }
    
    /********** End **********/
}
status ClearBiTree(BiTree &T)
//将二叉树设置成空，并删除所有结点，释放结点空间
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!T) return OK;
    else
    {
        ClearBiTree(T->lchild);
        ClearBiTree(T->rchild);
        free(T);
        T=NULL;
        return OK;
    }
    /********** End **********/
}
status DestroyBiTree(BiTree &T)
//销毁二叉树
{
	if(!pd)  return -1;
	pd=0;
	ClearBiTree(T);
	return 1;
}
status BiTreeEmpty(BiTree &T)
//判空二叉树
{
	if(!pd)  return -1;
	if(T==NULL) return 1;
    else  return 0;
}
int BiTreeDepth(BiTree T)
//求二叉树T的深度
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!T) return 0;
    int d=0,dr=0,dl=0;
    dl=BiTreeDepth(T->lchild);
    dr=BiTreeDepth(T->rchild);
    d=dl>dr?dl:dr;
    return d+1;
    /********** End **********/
}

BiTNode* LocateNode(BiTree T,KeyType e)
//查找结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!T) return NULL;
    if(T->data.key==e) return T;
    BiTNode *p=NULL;
    p=LocateNode(T->lchild,e);
    if(p) return p;
    p=LocateNode(T->rchild,e);
    if(p) return p;
    return NULL;
    /********** End **********/
}
int check(BiTree T,TElemType value){
//查重
    if(!T)  return 0;
    if(T->data.key==value.key)  return 1;
    return check(T->lchild,value)||check(T->rchild,value);
}
status Assign(BiTree &T,KeyType e,TElemType value)
//实现结点赋值。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(LocateNode(T,value.key)&&(value.key!=e)) return ERROR;
    BiTree p=LocateNode(T,e);
    if(p)
    {
        p->data=value;
        return OK;
    }    
    return ERROR;
    /********** End **********/
}
BiTNode* GetSibling(BiTree T,KeyType e)
//实现获得兄弟结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!(T->lchild&&T->rchild)) return NULL;
    if((T->lchild)->data.key==e)
    {
        return T->rchild;
    }
    if((T->rchild)->data.key==e)
    {
        return T->lchild;
    }
    BiTree p=NULL;
    p=GetSibling(T->lchild,e);
    if(p) return p;
    p=GetSibling(T->rchild,e);
    if(p) return p;
    return NULL;
    /********** End **********/
}
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//插入结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    BiTree root=LocateNode(T,e);
    if(!root) return ERROR;
    switch(LR)
    {
        case 0:
        {
            BiTNode *temp=root->lchild;
            root->lchild=(BiTNode*)malloc(sizeof(BiTNode));
            if(!root->lchild) return ERROR;
            root->lchild->data=c;
            root->lchild->lchild=NULL;
            root->lchild->rchild=temp;
            break;
        }
                case 1:
        {
            BiTNode *temp=root->rchild;
            root->rchild=(BiTNode*)malloc(sizeof(BiTNode));
            if(!root->rchild) return ERROR;
            root->rchild->data=c;
            root->rchild->lchild=NULL;
            root->rchild->rchild=temp;
            break;
        }
                case -1:
        {
            BiTNode *temp=root;
            root=(BiTNode*)malloc(sizeof(BiTNode));
            if(!root) return ERROR;
            root->data=c;
            root->lchild=NULL;
            root->rchild=temp;
            break;
        }
        default:
        return ERROR;
    }
    return OK;
    /********** End **********/
}
status DeleteNode(BiTree &T,KeyType e)
//删除结点
{
    if(!T)  return 0;
    if(T->data.key==e)
    {
        BiTree p=T;
        if(!T->lchild&&!T->rchild)
            T=NULL;
        else if(!T->rchild)
            T=T->lchild;
        else if(!T->lchild)
            T=T->rchild;
        else
        {
            T=T->lchild;
            BiTree t=T;
            while(t->rchild)
                t=t->rchild;
            t->rchild=p->rchild;
        }
        free(p);
        return OK;
    }
    return DeleteNode(T->lchild,e)||DeleteNode(T->rchild,e);
}
status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//先序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    BiTree a[100];
    int i=-1;
    a[0]=T;
    BiTree p=T;
    while(p||i!=-1)
    {
        while(p)
        {visit(p);
        a[++i]=p;
        p=p->lchild;
        }
        if(i!=-1)
        {
            p=a[i--];
            p=p->rchild;
        }
    }
    /********** End **********/
}

status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//中序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!T) return ERROR;
    InOrderTraverse(T->lchild,visit);
    visit(T);
    InOrderTraverse(T->rchild,visit);
    return OK;
    /********** End **********/
}

status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//后序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!T) return ERROR;
    PostOrderTraverse(T->lchild,visit);
    PostOrderTraverse(T->rchild,visit);
    visit(T);
    return OK;
    /********** End **********/
}

status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//按层遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    BiTree a[100];
    int come=0,go=0;
    a[come++]=T;
    while(come>go)
    {
        
        if(a[go]) 
        {
            visit(a[go]);
            a[come++]=a[go]->lchild;
            a[come++]=a[go]->rchild;
        }
        go++;
    }
    /********** End **********/
}
void fpr(BiTree T,FILE* fout)
{
    if(!T)
    {
        fprintf(fout,"0 null ");
        return;
    }
    fprintf(fout,"%d %s ",T->data.key,T->data.others);
    fpr(T->lchild,fout);
    fpr(T->rchild,fout);
    return;
}
void fread(BiTree& T,FILE* fin)
{
    int key;
    char s[20];
    fscanf(fin,"%d %s",&key,s);
    if(key==0)
    {
        T=NULL;
        return;
    }
    if(key==-1)  return;
    T=(BiTree)malloc(sizeof(BiTNode));
    T->data.key=key;
    strcpy(T->data.others,s);
    fread(T->lchild,fin);
    fread(T->rchild,fin);
    return;
}
status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件FileName中
{
    FILE* fout=fopen(FileName,"w");
    fpr(T,fout);
    fprintf(fout,"-1 null");
    fclose(fout);
    return OK;
}
status LoadBiTree(BiTree &T,  char FileName[])
//读入文件FileName的结点数据，创建二叉树
{
    FILE* fin=fopen(FileName,"r");
    if(fin==NULL)return 0;
    fread(T,fin);
    pd=1;
    fclose(fin);
    return OK;
}
int MPS(BiTree T)
{
	
	if(!T) return 0;
	int l=MPS(T->lchild);
	int r=MPS(T->rchild);
	return max(l,r)+T->data.key;
}
status MaxPathSum(BiTree T)
//最大路径和
{
	int ans=MPS(T);
	return ans;
}

BiTNode* LowestCommonAncestor(BiTree T,KeyType e1,KeyType e2)
//最近公共祖先
{
	if(LocateNode(T->lchild,e1))
    {
		if(LocateNode(T->lchild,e2))  return LowestCommonAncestor(T->lchild,e1,e2);
		return T;
	}
	else
	{
		if(LocateNode(T->rchild,e2))  return LowestCommonAncestor(T->rchild,e1,e2);
		return T;
	}
}
status InvertTree(BiTree &T)
//翻转二叉树
{
	if(!T)  return OK;
	BiTNode*t;
	t=T->lchild;
	T->lchild=T->rchild;
	T->rchild=t;
	InvertTree(T->lchild);
	InvertTree(T->rchild);
	return 1;
}
