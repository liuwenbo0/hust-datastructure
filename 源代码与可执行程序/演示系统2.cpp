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
typedef int ElemType; //����Ԫ�����Ͷ���

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef int ElemType;
typedef struct LNode{//��������ʽ�ṹ�����Ķ���
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
		printf("    ��ѡ����Ĳ���[0~17]:\n");
		scanf("%d", &op);
		switch(op){
		case 1:	
			if(InitList(L) == OK)
				printf("���Ա����ɹ�\n");
			else
				printf("���Ա���ʧ��\n");
			getchar(); getchar();
			break;
		case 2:	//�������Ա�
			if(DestroyList(L) == OK)
				printf("���Ա����ٳɹ�\n");
			else
				printf("���Ա�����\n");
			getchar(); getchar();
			break;
		case 3:	//ɾ�����Ա�
			if(ClearList(L) == OK)
				printf("���Ա���ճɹ�\n");
			else
				printf("���Ա�����\n");
			getchar(); getchar();
			break;
		case 4:	//�п�
			flag = ListEmpty(L);
			if(flag == TRUE)
				printf("���Ա�Ϊ��\n");
			else if(flag == FALSE)
				printf("���Ա�Ϊ��\n");
			else
				printf("���Ա�����!\n");
			getchar(); getchar();
			break;
		case 5:	//���
			length = ListLength(L);
			if(length != INFEASIBLE)
				printf("���Ա���Ϊ%d\n", length);
			else
				printf("���Ա�����\n");
			getchar(); getchar();
			break;
		case 6:	//��ȡԪ��
			if(!L)
				printf("���Ա�����\n");
			else{
				printf("��Ҫ��ȡ�ڼ���Ԫ�أ�");
				scanf("%d", &i);
				flag = GetElem(L, i, e);
				if(flag == OK)
					printf("��ȡԪ��Ϊ%d\n", e);
				else if(flag == ERROR)
					printf("λ�ò��Ϸ�\n");
				else
					printf("���Ա�����\n");
			}
			getchar(); getchar();
			break;
		case 7:	//��λԪ��
			if(!L)
				printf("���Ա�����\n");
			else{
				printf("������Ԫ�أ�");
				scanf("%d", &e);
				if((i = LocateElem(L, e)) != 0)
					printf("Ԫ��λ��Ϊ%d\n", i);
				else if (i == ERROR)
					printf("����Ԫ��λ��ʧ��\n");
				else
					printf("���Ա�����\n");
			}
			getchar(); getchar();
			break;
		case 8:	//����ǰ��
			if(!L)
				printf("���Ա�����\n");
			else{
				printf("������Ԫ�أ�");
				scanf("%d", &e);
				flag = PriorElem(L, e, pre);
				if(flag == OK)
					printf("Ԫ�ص�ǰ��Ϊ%d\n", pre);
				else if(flag == ERROR)
					printf("����ǰ��ʧ��\n");
				else printf("���Ա�Ϊ��\n");
			}
			getchar(); getchar();
			break;
		case 9:	//���Һ��
			if(!L)
				printf("���Ա�����\n");
			else {
				printf("������Ԫ�أ�");
				scanf("%d", &e);
				flag = NextElem(L, e, next);
				if(flag == OK)
					printf("Ԫ�صĺ��Ϊ%d\n", next);
				else if(flag == ERROR)
					printf("���Һ��Ԫ��ʧ��\n");
				else
					printf("���Ա�Ϊ��\n");
			}
			getchar(); getchar();
			break;
		case 10:	//����Ԫ��
			if(!L)
				printf("���Ա�����\n");
			else{
				scanf("%d",&i);
				scanf("%d",&e);
				flag = ListInsert(L, i, e);
				if(flag == OK)
					printf("����ɹ�\n");
				else if(flag == ERROR)
					printf("����λ�ò��Ϸ�\n");
			}
			getchar(); getchar();
			break;
		case 11:	//ɾ��Ԫ��
			if(!L)
				printf("���Ա�����\n");
			else{
				printf("��Ҫɾ���ڼ���Ԫ�أ�");
				scanf("%d", &i);
				flag = ListDelete(L, i, e);
				if(flag == OK)
					printf("ɾ���ɹ�����ɾ����Ԫ��Ϊ��%d\n", e);
				else if(flag == ERROR)
					printf("ɾ��λ�ò��Ϸ�\n");
				else
					printf("���Ա�Ϊ��\n");
			}
			getchar(); getchar();
			break;
		case 12:   // ����
			if(!L)
				printf("���Ա�����\n");
			else{
				ListTraverse(L);
				printf("�������\n");
			}
			getchar(); getchar();
			break;
		case 13:	//д���ļ�
			if(!L)
				printf("���Ա�����\n");
			else{
				printf("�������ļ���:\n");
				scanf("%s", name);
				flag = SaveList(L, name);
				if(flag == OK)
					printf("�����ļ��ɹ�\n");
				else
					printf("�����ļ�ʧ��\n");
			}
			getchar(); getchar();
			break;
		case 14:	//�����ļ�
			if(L)
				printf("�����Ա��Ѵ��ڣ����ɶ���");
			else{
				printf("�������ļ���:");
				scanf("%s", name);
				flag = LoadList(L, name);
				if (flag == OK)
					printf("�����ļ��ɹ�\n");
				else
					printf("�����ļ�ʧ��\n");
			}
			getchar(); getchar();
			break;
		case 15:
            flag = SortList(L);
            if(flag == INFEASIBLE) printf("���Ա�����\n");
            else if(flag == ERROR) printf("���Ա�Ϊ��\n");
            else{
                SortList(L);
                printf("����ɹ�\n");
            }
            getchar(); getchar();
            break;
        case 16:
            flag = ReverseList(L);
            if(flag == INFEASIBLE) printf("���Ա�����\n");
            else if(flag == ERROR) printf("���Ա�Ϊ��\n");
            else printf("��ת�ɹ�\n");
            getchar(); getchar();
            break;
        case 17:
		    printf("��������ɾ�������ڼ���Ԫ�أ�\n");
            scanf("%d", &n);
            flag = RemoveNthFromEnd(L, n, e);
            if(flag == INFEASIBLE) printf("���Ա�����\n");
            else if(flag == ERROR) printf("���Ա�Ϊ��\n");
            else
			{
                printf("ɾ���ɹ�\n");
            }
            getchar(); getchar();
            break;
		case 0:	//��������
			break;
		}//end of switch
	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
	return 0;
}//end of main()


status InitList(LinkList &L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L) return INFEASIBLE;
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    if(L) return OK;
    /********** End **********/
}

status DestroyList(LinkList &L)
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(!L) return INFEASIBLE;
    if(!L->next) return TRUE;
    else return FALSE;

    /********** End **********/
}


int ListLength(LinkList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
//������Ա�L���ڣ���ת���Ա�����OK����������ڣ�����INFEASIBLE��
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
