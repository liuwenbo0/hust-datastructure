#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef int ElemType;
typedef struct LNode{//单链表（链式结构）结点的定义
    ElemType data;
    struct LNode* next;
}LNode, *LinkList;
status InitList(LinkList& L);
status DestroyList(LinkList& L);
status ClearList(LinkList& L);
status ListEmpty(LinkList L);
status ListLength(LinkList L);
status GetElem(LinkList L, int i, ElemType& e);
status LocateElem(LinkList L, ElemType e);
status PriorElem(LinkList L, ElemType e, ElemType& pre);
status NextElem(LinkList L, ElemType e, ElemType& next);
status ListInsert(LinkList& L, int i, ElemType e);
status ListDelete(LinkList& L, int i, ElemType& e);
status ListTraverse(LinkList L);

status SaveList(LinkList L, char FileName[]);
status LoadList(LinkList& L, char FileName[]);
status AddList(LISTS& lists);
status RemoveList(LISTS& Lists, char name[]);
status LocateList(LISTS Lists, char name[]);
status ReverseList(LinkList &L);
status RemoveNthFromEnd(LinkList L, int n, ElemType& e);
status SortList(LinkList L);

int main()
{
	int op = 1, flag ,length, next, pre, i, e, n;
	LISTS Lists;
	LIST* temp;
	if(!(Lists.head = (LIST *)malloc(sizeof(LIST))))
		exit(OVERFLOW);
	if (!(Lists.head -> head = (LinkList)malloc(sizeof(LNode))))
		exit(OVERFLOW);
	Lists.head -> head -> data = 0;
	Lists.head -> next = NULL;
	char name[25];
	LinkList L = NULL;
	while(op){
		system("cls");	
		printf("\n");	
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("	  1. InitList             2. DestroyList\n");
		printf("	  3. ClearList            4. ListEmpty\n");
		printf("	  5. ListLength           6. GetElem\n");
		printf("	  7. LocateElem           8. PriorElem\n");
		printf("	  9. NextElem             10. ListInsert\n");
		printf("	  11. ListDelete          12. ListTrabverse\n");
		printf("\n"); 
		printf("	  13.SaveList             14. LoadList\n");
		printf("	  15.SortList            16.ReverseList\n");
		printf("	  17.RemoveNthFromEnd\n");
		printf("          0. exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~17]:\n");
		scanf("%d", &op);
		switch(op){
		case 1:	
			if(InitList(L) == OK)
				printf("线性表创建成功\n");
			else
				printf("线性表创建失败\n");
			getchar(); getchar();
			break;
		case 2:	//销毁线性表
			if(DestroyList(L) == OK)
				printf("线性表销毁成功\n");
			else
				printf("线性表不存在\n");
			getchar(); getchar();
			break;
		case 3:	//删除线性表
			if(ClearList(L) == OK)
				printf("线性表清空成功\n");
			else
				printf("线性表不存在\n");
			getchar(); getchar();
			break;
		case 4:	//判空
			flag = ListEmpty(L);
			if(flag == TRUE)
				printf("线性表为空\n");
			else if(flag == FALSE)
				printf("线性表不为空\n");
			else
				printf("线性表不存在!\n");
			getchar(); getchar();
			break;
		case 5:	//求表长
			length = ListLength(L);
			if(length != INFEASIBLE)
				printf("线性表长度为%d\n", length);
			else
				printf("线性表不存在\n");
			getchar(); getchar();
			break;
		case 6:	//获取元素
			if(!L)
				printf("线性表不存在\n");
			else{
				printf("想要获取第几个元素：");
				scanf("%d", &i);
				flag = GetElem(L, i, e);
				if(flag == OK)
					printf("获取元素为%d\n", e);
				else if(flag == ERROR)
					printf("位置不合法\n");
				else
					printf("线性表不存在\n");
			}
			getchar(); getchar();
			break;
		case 7:	//定位元素
			if(!L)
				printf("线性表不存在\n");
			else{
				printf("请输入元素：");
				scanf("%d", &e);
				if((i = LocateElem(L, e)) != 0)
					printf("元素位置为%d\n", i);
				else if (i == ERROR)
					printf("查找元素位置失败\n");
				else
					printf("线性表不存在\n");
			}
			getchar(); getchar();
			break;
		case 8:	//查找前驱
			if(!L)
				printf("线性表不存在\n");
			else{
				printf("请输入元素：");
				scanf("%d", &e);
				flag = PriorElem(L, e, pre);
				if(flag == OK)
					printf("元素的前驱为%d\n", pre);
				else if(flag == ERROR)
					printf("查找前驱失败\n");
				else printf("线性表为空\n");
			}
			getchar(); getchar();
			break;
		case 9:	//查找后继
			if(!L)
				printf("线性表不存在\n");
			else {
				printf("请输入元素：");
				scanf("%d", &e);
				flag = NextElem(L, e, next);
				if(flag == OK)
					printf("元素的后继为%d\n", next);
				else if(flag == ERROR)
					printf("查找后继元素失败\n");
				else
					printf("线性表为空\n");
			}
			getchar(); getchar();
			break;
		case 10:	//插入元素
			if(!L)
				printf("线性表不存在\n");
			else{
				scanf("%d",&i);
				scanf("%d",&e);
				flag = ListInsert(L, i, e);
				if(flag == OK)
					printf("插入成功\n");
				else if(flag == ERROR)
					printf("插入位置不合法\n");
			}
			getchar(); getchar();
			break;
		case 11:	//删除元素
			if(!L)
				printf("线性表不存在\n");
			else{
				printf("想要删除第几个元素：");
				scanf("%d", &i);
				flag = ListDelete(L, i, e);
				if(flag == OK)
					printf("删除成功，被删除的元素为：%d\n", e);
				else if(flag == ERROR)
					printf("删除位置不合法\n");
				else
					printf("线性表为空\n");
			}
			getchar(); getchar();
			break;
		case 12:   // 遍历
			if(!L)
				printf("线性表不存在\n");
			else{
				ListTraverse(L);
				printf("遍历完成\n");
			}
			getchar(); getchar();
			break;
		case 13:	//写入文件
			if(!L)
				printf("线性表不存在\n");
			else{
				printf("请输入文件名:\n");
				scanf("%s", name);
				flag = SaveList(L, name);
				if(flag == OK)
					printf("保存文件成功\n");
				else
					printf("保存文件失败\n");
			}
			getchar(); getchar();
			break;
		case 14:	//读入文件
			if(L)
				printf("该线性表已存在，不可读入");
			else{
				printf("请输入文件名:");
				scanf("%s", name);
				flag = LoadList(L, name);
				if (flag == OK)
					printf("读入文件成功\n");
				else
					printf("读入文件失败\n");
			}
			getchar(); getchar();
			break;
		case 15:
            flag = SortList(L);
            if(flag == INFEASIBLE) printf("线性表不存在\n");
            else if(flag == ERROR) printf("线性表为空\n");
            else{
                SortList(L);
                printf("排序成功\n");
            }
            getchar(); getchar();
            break;
        case 16:
            flag = ReverseList(L);
            if(flag == INFEASIBLE) printf("线性表不存在\n");
            else if(flag == ERROR) printf("线性表为空\n");
            else printf("翻转成功\n");
            getchar(); getchar();
            break;
        case 17:
		    printf("请问你想删除倒数第几个元素：\n");
            scanf("%d", &n);
            flag = RemoveNthFromEnd(L, n, e);
            if(flag == INFEASIBLE) printf("线性表不存在\n");
            else if(flag == ERROR) printf("线性表为空\n");
            else
			{
                printf("删除成功\n");
            }
            getchar(); getchar();
            break;
		case 0:	//结束程序
			break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
	return 0;
}//end of main()


status InitList(LinkList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L) return INFEASIBLE;
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    if(L) return OK;
    /********** End **********/
}

status DestroyList(LinkList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L) return INFEASIBLE;
    LinkList p;
    while(L)
    {
        p=L;
        L=L->next;
        free(p);
    }
    return OK;
    /********** End **********/
}

status ClearList(LinkList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L) return INFEASIBLE;
    LinkList p;
    while(L->next)
    {
        p=L->next;
        L->next=p->next;
        free(p);
    }
    return OK;
    /********** End **********/
}

status ListEmpty(LinkList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L) return INFEASIBLE;
    if(!L->next) return TRUE;
    else return FALSE;

    /********** End **********/
}


int ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L) return INFEASIBLE;
    int ans=0;
    LinkList p=L;
    while(p->next)
    {
        ans++;
        p=p->next;
    }
    return ans;
    /********** End **********/
}


status GetElem(LinkList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L) return INFEASIBLE;
    if(i<=0) return ERROR;
    LinkList p=L;
    for(int j=0;j<i;j++)
    {
        p=p->next;
        if(!p) return ERROR;
    }
    e=(*p).data;
    return OK;
    /********** End **********/
}

status LocateElem(LinkList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L) return INFEASIBLE;
    LinkList p=L->next;
    int ans=1;
    while(p)
    {  
        if((*p).data==e) return ans;
        ans++;
        p=p->next;
    }
    return ERROR;
    /********** End **********/
}

status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L) return INFEASIBLE;
    LinkList p=L->next;
    LinkList q=L;
    int ans=0;
    while(p)
    {  
        if((*p).data==e) 
        {
            if(!ans) return ERROR;
            pre=(*q).data;
            return OK;
        }
        ans++;
        p=p->next;
        q=q->next;
    }
    return ERROR;
    /********** End **********/
}


status NextElem(LinkList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L) return INFEASIBLE;
    LinkList p=L->next;
    if(!p) return ERROR;
    LinkList q=p->next;
    while(q)
    {  
        if((*p).data==e) 
        {
            next=(*q).data;
            return OK;
        }
        p=p->next;
        q=q->next;
    }
    return ERROR;
    /********** End **********/
}

status ListInsert(LinkList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L) return INFEASIBLE;
    LinkList p=L,q;
    if(!L->next)
	{
		if(i!=1) return ERROR;
		p->next=(LNode*)malloc(sizeof(LNode));
		p=p->next;
		(*p).data=e;
		p->next=NULL;
		return OK;
	 } 
	q=L->next;
    if(i<=0) return ERROR;
    for(int ans=1;ans<i;ans++)
    {  
        p=p->next;
        if(q) q=q->next;
        else return ERROR;
    }
    p->next=(LNode*)malloc(sizeof(LNode));
    p=p->next;
    (*p).data=e;
    p->next=q;
    return OK;
    /********** End **********/
}

status ListDelete(LinkList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L) return INFEASIBLE;
    LinkList p=L,q;
    int ans=1;
    if(L->next) q=L->next;
    if(i<=0) return ERROR;
    for(ans;ans<i;ans++)
    {  
        p=p->next;
        if(q->next) q=q->next;
        else return ERROR;
    }
    p->next=q->next;
    e=(*q).data;
    free(q);
    return OK;
    /********** End **********/
}

status ListTraverse(LinkList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!L) return INFEASIBLE;
    LinkList p=L;
    while(p->next)
    {
        p=p->next;
        printf("%d ",(*p).data);
    }
    return OK;
    /********** End **********/
}

status SaveList(LinkList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
   if(!L)
    {
        return INFEASIBLE;
    }
    else
    {
        LinkList p=L;
        FILE *fp=fopen(FileName,"w+");
        if(!fp) return ERROR;
        while(p->next)
        {
            p=p->next;
        	fprintf(fp,"%d ",(*p).data);
		}
        fclose(fp);
        return OK;
    }
    /********** End 1 **********/
}

status LoadList(LinkList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    if(L) return INFEASIBLE;
    L=(LNode*)malloc(sizeof(LNode));
    FILE *fp=fopen(FileName,"r");
    if(!fp) return ERROR;
    ElemType e;
    LinkList p=L;
    while((fscanf(fp,"%d",&e))==1)
    {
        p->next=(LNode*)malloc(sizeof(LNode));
        p=p->next;
        (*p).data=e;
    }
    p->next=NULL;
    fclose(fp);
    return OK;
    /********** End 2 **********/
}

status ReverseList(LinkList &L)
//如果线性表L存在，翻转线性表，返回OK；如果不存在，返回INFEASIBLE。
{
    if(L)
    {
        LinkList p,q;
        if(L -> next == NULL)  return ERROR;
        p = L -> next;
        q = L -> next -> next;
        while(q != NULL)
        {
            p -> next = q -> next;
            q -> next = L -> next;
            L -> next = q;
            q = p -> next;
        }
        return OK;
    }
    else  return INFEASIBLE;
}

status RemoveNthFromEnd(LinkList L, int n, ElemType& e)
{
    if(!L) return INFEASIBLE;
    else
	{
		int k,j; 
        if(L->next==NULL) return ERROR;
        k = ListLength(L);
        j = k - n + 1;
        ListDelete(L, j, e);
        return OK;
    }
}

status SortList(LinkList L)
{
    LinkList p, q;
    if(!L) return INFEASIBLE;
    else{
        if(L->next==NULL) return ERROR;
        int n = ListLength(L);
        int i, j, temp;
        for(i = 0,p = L -> next; i < n-1; i++,p = p -> next){
            for(j = i + 1,q = p -> next; j < n; j++,q = q -> next){
                if(p -> data > q -> data)
				{
                    temp = p -> data;
                    p -> data = q -> data;
                    q -> data = temp;
                }
            }
        }
        return OK;
    }
}
