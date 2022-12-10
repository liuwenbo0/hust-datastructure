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
} TElemType; //������������Ͷ���

typedef struct BiTNode{  //����������Ķ���
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
		printf("    ��ѡ����Ĳ���[0~23]:");
		scanf("%d",&op);
	    switch(op){
	    	case 1:
	    		if(pd)  printf("�������Ѵ��ڣ�����ʧ�ܣ�\n");
                else
                {
                    printf("��������սڵ�����������\n");
                    i=0;
                    do
                    {
                        scanf("%d%s",&definition[i].key,definition[i].others);
                    } while (definition[i++].key!=-1);
                    flag=CreateBiTree(T,definition);
                    if(flag==1)printf("�����������ɹ���\n");
                    else if(flag==0)printf("����������ʧ�ܣ�\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 2:
	    		flag=DestroyBiTree(T);
	    		if(flag==1)printf("���������ٳɹ���\n");
                else printf("����������ʧ�ܣ�\n");
	    		getchar();getchar();
	    		break;
	    	case 3:
	    		if(!pd)printf("�����������ڣ�\n");
                else
                {
                    flag=ClearBiTree(T);
                    if(flag==OK)printf("��������ճɹ���\n");
                    else printf("���������ʧ�ܣ�\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 4:
	    		flag=BiTreeEmpty(T);
	    		if(flag==1)printf("������Ϊ�գ�\n");
                else if(flag==0)printf("��������Ϊ�գ�\n");
                else printf("�����������ڣ�\n");
	    		getchar();printf("����س��Լ���!");getchar();
	    		break;
	    	case 5:
	    		flag=BiTreeDepth(T);
	    		if(flag!=-1) printf("�����������Ϊ%d��\n",flag);
                else printf("�����������ڣ�\n");
	    		getchar();getchar();
	    		break;
	    	case 6:
				if(!pd)printf("�����������ڣ�\n");
                else
                {
                    printf("������Ҫ���ҵĽ��Ĺؼ��֣�");
                    scanf("%d",&key);
                    t=LocateNode(T,key);
                    if(t)  printf("�ý���ֵΪ%s��\n",t->data.others);
                    else   printf("�޹ؼ���Ϊ%d�Ľ�㣡\n",key);
                }
	    		getchar();getchar();
	    		break;
	    	case 7:
	    		if(!pd)  printf("�����������ڣ�\n");
                else
                {
                    printf("��������Ҫ�޸Ľ��Ĺؼ����Լ��޸ĺ�Ĺؼ��ֺ�ֵ��");
                    scanf("%d%d%s",&key,&val.key,val.others);
                    flag=Assign(T,key,val);
                    if(flag==1)printf("����޸ĳɹ���\n");
                    else printf("����޸�ʧ�ܣ�\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 8:
	    		if(!pd)  printf("�����������ڣ�\n");
                else
                {
                    printf("������Ҫ��ȡ�ֵܽ��Ĺؼ��֣�");
                    scanf("%d",&key);
                    t=GetSibling(T,key);
                    if(t)  printf("�ֵܽ��Ϊ(%d,%s)��\n",t->data.key,t->data.others);
                    else printf("�޸ýڵ�������ֵܣ�\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 9:
	    		if(!pd)  printf("�����������ڣ�\n");
                else
                {
                    printf("����ؼ��֡�����λ�á��½��Ĺؼ��֡��½ڵ��ֵ��");
                    scanf("%d%d%d%s",&key,&lr,&val.key,val.others);
                    flag=InsertNode(T,key,lr,val);
                    if(flag==1)printf("������ɹ���\n");
                    else printf("������ʧ�ܣ�\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 10:
	    		if(!pd)  printf("�����������ڣ�\n");
                else
                {
                    printf("����Ҫɾ���Ľ��Ĺؼ��֣�");
                    scanf("%d",&key);
                    flag=DeleteNode(T,key);
                    if(flag==1)printf("ɾ�����ɹ���\n");
                    else printf("ɾ���ڵ�ʧ�ܣ�\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 11:
	    		if(!pd)  printf("�����������ڣ�\n");
                else
                {
                    printf("---------------ǰ�����---------------\n");
                    PreOrderTraverse(T,Visit);
                    printf("\n------------------end-----------------\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 12:
	    		if(!pd)  printf("�����������ڣ�\n");
                else
                {
                    printf("---------------�������---------------\n");
                    InOrderTraverse(T,Visit);
                    printf("\n------------------end-----------------\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 13:
	    		if(!pd)  printf("�����������ڣ�\n");
                else
                {
                    printf("---------------�������---------------\n");
                    PostOrderTraverse(T,Visit);
                    printf("\n------------------end-----------------\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 14:
	    		if(!pd)  printf("�����������ڣ�\n");
                else
                {
                    printf("---------------�������---------------\n");
                    LevelOrderTraverse(T,Visit);
                    printf("\n------------------end-----------------\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 15:
	    		if(!pd)  printf("�����������ڣ�\n");
                else
                {
                    printf("���·����Ϊ��%d��\n",MaxPathSum(T));
                }
	    		getchar();getchar();
	    		break;
	    	case 16:
	    		if(!pd) printf("�����������ڣ�\n");
                else
                {
                    printf("������Ҫ��������������ȵ������ؼ��֣�");
                    scanf("%d%d",&key1,&key2);
                    t=LowestCommonAncestor(T,key1,key2);
                    if(t)printf("�����������Ϊ(%d,%s)��\n",t->data.key,t->data.others);
                    else printf("����ʧ�ܣ�\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 17:
	    		if(!pd) printf("�����������ڣ�\n");
                else
                {
                    flag=InvertTree(T);
                    if(flag==1)  printf("��������ת�ɹ���\n");
                    else printf("��������תʧ�ܣ�\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 18:
	    		if(!pd)  printf("�����������ڣ�\n");
                else
                {
                    printf("������Ҫ������ļ�����");
                    scanf("%s",FileName);
                    flag=SaveBiTree(T,FileName);
                    if(flag==1)printf("����������ɹ���\n");
                    else printf("����������ʧ�ܣ�\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 19:
	    		if(pd)  printf("�������Ѵ��ڣ��������٣�\n");
                else
                {
                    printf("������Ҫ��ȡ���ļ�����");
                    scanf("%s",FileName);
                    flag=LoadBiTree(T,FileName);
                    if(flag==1)printf("��������ȡ�ɹ���\n");
                    else printf("��������ȡʧ�ܣ�\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 0:
	    		break;
		}//end of switch
	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
	getchar();getchar();
}//end of main
/*--------------��Ϊ�ָ���---------------*/
status CreateBiTree(BiTree &T,TElemType definition[])
/*���ݴ���֦�Ķ������ȸ���������definition����һ�ö������������ڵ�ָ�븳ֵ��T������OK��
�������ͬ�Ĺؼ��֣�����ERROR����������ͨ������������������ʵ�ֱ�������*/
{
    // �������ﲹ����룬��ɱ�������
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
//�����������óɿգ���ɾ�����н�㣬�ͷŽ��ռ�
{
    // �������ﲹ����룬��ɱ�������
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
//���ٶ�����
{
	if(!pd)  return -1;
	pd=0;
	ClearBiTree(T);
	return 1;
}
status BiTreeEmpty(BiTree &T)
//�пն�����
{
	if(!pd)  return -1;
	if(T==NULL) return 1;
    else  return 0;
}
int BiTreeDepth(BiTree T)
//�������T�����
{
    // �������ﲹ����룬��ɱ�������
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
//���ҽ��
{
    // �������ﲹ����룬��ɱ�������
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
//����
    if(!T)  return 0;
    if(T->data.key==value.key)  return 1;
    return check(T->lchild,value)||check(T->rchild,value);
}
status Assign(BiTree &T,KeyType e,TElemType value)
//ʵ�ֽ�㸳ֵ����������ͨ������������������ʵ�ֱ�������
{
    // �������ﲹ����룬��ɱ�������
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
//ʵ�ֻ���ֵܽ��
{
    // �������ﲹ����룬��ɱ�������
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
//�����㡣��������ͨ������������������ʵ�ֱ�������
{
    // �������ﲹ����룬��ɱ�������
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
//ɾ�����
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
//�������������T
{
    // �������ﲹ����룬��ɱ�������
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
//�������������T
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(!T) return ERROR;
    InOrderTraverse(T->lchild,visit);
    visit(T);
    InOrderTraverse(T->rchild,visit);
    return OK;
    /********** End **********/
}

status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(!T) return ERROR;
    PostOrderTraverse(T->lchild,visit);
    PostOrderTraverse(T->rchild,visit);
    visit(T);
    return OK;
    /********** End **********/
}

status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T
{
    // �������ﲹ����룬��ɱ�������
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
//���������Ľ������д�뵽�ļ�FileName��
{
    FILE* fout=fopen(FileName,"w");
    fpr(T,fout);
    fprintf(fout,"-1 null");
    fclose(fout);
    return OK;
}
status LoadBiTree(BiTree &T,  char FileName[])
//�����ļ�FileName�Ľ�����ݣ�����������
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
//���·����
{
	int ans=MPS(T);
	return ans;
}

BiTNode* LowestCommonAncestor(BiTree T,KeyType e1,KeyType e2)
//�����������
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
//��ת������
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
