#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int status; 
typedef int ElemType; 
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct{ 
	ElemType * elem;
	int length;
	int listsize;
}SqList;
status InitList(SqList& L);
status DestroyList(SqList& L);
status ClearList(SqList&L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L,int i,ElemType& e);
status LocateElem(SqList L,ElemType e); 
status PriorElem(SqList L,ElemType cur,ElemType &pre_e);
status NextElem(SqList L,ElemType cur,ElemType &next_e);
status ListInsert(SqList &L,int i,ElemType e);
status ListDelete(SqList&L,int i,ElemType& e);
status ListTrabverse(SqList L); 
status MaxSubArray(SqList L);
status SubArrayNum(SqList L,int k);
status sortList(SqList &L);
status SaveList(SqList L,char Filename[]);
status LoadList(SqList &L,char Filename[]);
/*--------------------------------------------*/
int ans=0,sum=0;
int main(void){
SqList L; L.elem=NULL; int op=1;   int flag=0;
while(op){
	system("cls");	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. InitList       7. LocateElem\n");
	printf("    	  2. DestroyList    8. PriorElem\n");
	printf("    	  3. ClearList      9. NextElem \n");
	printf("    	  4. ListEmpty      10. ListInsert\n");
	printf("    	  5. ListLength     11. ListDelete\n");
	printf("    	  6. GetElem        12. ListTrabverse\n");
	printf("    	  ������������������������������������\n");
	printf("    	  13.MaxSubArray    14.SubArrayNum\n");
	printf("    	  15.sortList       16.SaveList\n");
	printf("    	  17.LoadList\n");
	printf("    	  0. Exit\n");
	printf("-------------------------------------------------\n");
	printf("    ��ѡ����Ĳ���[0~12]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
	   	{
		 if(InitList(L)==OK) printf("���Ա����ɹ���\n");
		 else printf("���Ա���ʧ�ܣ�\n");
		 getchar();getchar();
		 break;
		}
	   case 2:
		 if(DestroyList(L)==OK)  printf("���Ա����ٳɹ���\n"); 
		 else printf("���Ա�����ʧ�ܣ�\n");   
		 getchar();getchar();
		 break;
	   case 3:
		 if(ClearList(L)==OK)    printf("���Ա���ճɹ���\n"); 
		 else printf("���Ա����ʧ�ܣ�\n");
		 getchar();getchar();
		 break;
	   case 4:
		 if(ListEmpty(L)==TRUE)   printf("���Ա�Ϊ�գ�\n"); 
		 else if(ListEmpty(L)==FALSE) printf("���Ա�Ϊ�գ�\n");
		 else printf("���Ա��п�ʧ�ܣ�\n");   
		 getchar();getchar();
		 break;
	   case 5:
	{
    	 if(ListLength(L)!=INFEASIBLE){
		 int Length=0;
		 Length=ListLength(L);
		 printf("�������Ա��ȳɹ�������Ϊ%d\n",Length);}
		 else printf("�������Ա���ʧ�ܣ�\n");
		 getchar();getchar();
		 break;
	}
	   case 6:
	{
		 int i=0; ElemType e=0;
	   	 printf("�����������ȡ�ڼ���Ԫ�أ�\n");
	   	 scanf("%d",&i);
		 if(GetElem(L,i,e)==ERROR)
		 {
		 	printf("iȡֵ���Ϸ���\n");
		 }
		 else if(GetElem(L,i,e)==INFEASIBLE) 
		 {
		 printf("��ȡ���Ա�Ԫ��ʧ�ܣ�\n");
		 }
		 else if(GetElem(L,i,e)==OK) 
		 {
		 	printf("��ȡ���Ա�Ԫ�سɹ���\n");
		 	printf("��Ԫ��Ϊ%d",e);
		 }     
		 getchar();getchar();
		 break;
	}
	   case 7:
	{   
	    int i=0;
	    ElemType e=0;
	    printf("��������Ҫ���ҵ�Ԫ�أ�\n");
	    scanf("%d",&e);
	    i=LocateElem(L,e);
	    if(i==INFEASIBLE)
		{
	    	printf("���Ա����ڣ�\n");
		}
		if(i==0)
		{
			printf("��Ԫ�ز����ڣ�\n");
		}
		if(i!=INFEASIBLE&&i!=0)
		{
			printf("��Ԫ��λ��Ϊ%d\n",i);
		}
		 getchar();getchar();
		 break;
    }
	   case 8:
		{
		 ElemType e=0;
		 printf("������������ǰ��Ԫ�ص�Ԫ��!\n");
		 scanf("%d",&e);
		 ElemType pre_e=0;
		 if(PriorElem(L,e,pre_e)==ERROR)
		 {
		 	printf("��Ԫ��û��ǰ����\n");
		 } 
		 if(PriorElem(L,e,pre_e)==INFEASIBLE)
		 {
		 	printf("�����Ա����ڣ�\n");
		 }
		 if(PriorElem(L,e,pre_e)==OK)
		 {
		 	printf("ǰ����óɹ���\n");
		 	printf("��ǰ��Ϊ%d",pre_e);
		 }  
		 getchar();getchar();
		 break;
		}
	   case 9:
	   	{
		 ElemType e=0;
		 printf("�����������ú��Ԫ�ص�Ԫ��!\n");
		 scanf("%d",&e);
		 ElemType next_e=0;
		 if(NextElem(L,e,next_e)==ERROR)
		 {
		 	printf("��Ԫ��û�к�̣�\n");
		 } 
		 if(NextElem(L,e,next_e)==INFEASIBLE)
		 {
		 	printf("�����Ա����ڣ�\n");
		 }
		 if(NextElem(L,e,next_e)==OK)
		 {
		 	printf("��̻�óɹ���\n");
		 	printf("�ú��Ϊ%d",next_e);
		 }   
		 getchar();getchar();
		 break;
		}
	   case 10:
		{int i;
		 ElemType e;
		 scanf("%d%d", &i, &e);
         if(ListInsert(L, i, e)==OK) printf("�ɹ����룡");
         else if(ListInsert(L, i, e)==INFEASIBLE) printf("���Ա�L�����ڣ�");
         else printf("����λ�ò��Ϸ���");
		 getchar();getchar();
		 break;
		}

	   case 11:
	   	{
	   	 int i=0,j=0;
	   	 ElemType e=0;
	   	 printf("����������Ҫɾ���ڼ���Ԫ�أ�\n");
	   	 scanf("%d",&i);
	   	 j=ListDelete(L,i,e);
	   	 if(j==ERROR)
		 {
	   	 	printf("ɾ��λ�ò��Ϸ���\n");
		 }
		 if(j==INFEASIBLE)
		 {
		 	printf("���Ա����ڣ�\n");
		 }
		 if(j==OK)
		 {
		 	printf("ɾ���ɹ���\n");
		 	printf("%d",e);
		 }    
		 getchar();getchar();
		 break;
		}
	   case 12:
		 //printf("\n----ListTrabverse���ܴ�ʵ�֣�\n");     
		 if(!ListTrabverse(L)) printf("���Ա��ǿձ�\n");
		getchar();getchar();
		 break;
       case 13:
		{
		 MaxSubArray(L);
		 printf("��������������Ϊ%d",ans);
		 getchar();getchar();
		 break;
		}
		case 14:
		{
		 int k=0;
		 printf("����������k\n");
		 scanf("%d",&k); 
		 SubArrayNum(L,k);
		 printf("�������к�Ϊ%d������������ĸ���Ϊ%d��\n",k,ans);
		 getchar();getchar();
		 break;
		}
		case 15:
		{
		 printf("����������������У�\n");
		 sortList(L);
		 getchar();getchar();
		 break;
		} 
		case 16:
		{
			char FileName[100];
			printf("�������ļ���\n");
			scanf("%s",&FileName); 
			if(SaveList(L,FileName))
			printf("���Ա��ѱ���Ϊtxt�ļ���\n");
			else 
			printf("����ʧ�ܣ�\n");
			getchar();getchar();
		    break;
		}
		case 17:
		{
			char FileName[100];
			printf("�������ļ���\n");
			scanf("%s",&FileName); 
			if(LoadList(L,FileName))
			printf("���Ա�����txt�ļ��ɹ����أ�\n");
			else 
			printf("����ʧ�ܣ�\n");
			getchar();getchar();
		    break;
		}
	case 0:
         break;
	}//end of switch
  }//end of while
printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()
/*--------page 23 on textbook --------------------*/
status InitList(SqList& L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L.elem==NULL){
L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
L.length=0;
L.listsize=LIST_INIT_SIZE;
return OK;}
else return INFEASIBLE;

    /********** End **********/
}
status DestroyList(SqList &L)
{
if(L.elem!=NULL){
    free(L.elem);
    L.elem=NULL;
    L.length=0;
    L.listsize=0;
    return OK;
}
else return INFEASIBLE;
}
status ClearList(SqList& L)
{
if(L.elem!=NULL){
    L.length=0;
    return OK;
}
else return INFEASIBLE;
}
status ListEmpty(SqList L)
{
if(L.elem==NULL){return INFEASIBLE;}
else {
    if(L.length==0) return TRUE;
    else return FALSE;
}
}
status ListLength(SqList L)
{
if(L.elem!=NULL){
    return L.length;
}
else return INFEASIBLE;
}
status GetElem(SqList L,int i,ElemType &e)
{
if(L.elem!=NULL){
    if(i<1||i>L.length){
        return ERROR;
    }
    e=L.elem[i-1];
    return OK;
}
else return INFEASIBLE;
}
int LocateElem(SqList L,ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų����ظ���ţ����e�����ڣ�����0�������Ա�L������ʱ������INFEASIBLE����-1����
{
if(L.elem!=NULL)
{
    int i=1;
    while(L.elem[i-1]!=e&&(i-1)<=L.length-1){
        i++;
    }
    if(i>=1&&i<=L.length)
	{
        return i;
    }
    else
	{
        return 0;
    }
}
else return INFEASIBLE;
}
status PriorElem(SqList L,ElemType e,ElemType &pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
if(L.elem!=NULL)
{
    int i=0;
    if(L.elem[i]==e) return ERROR;
    else {i=1;
        while(i<L.length){
            if(L.elem[i]==e) {pre=L.elem[i-1];
            return OK;}
            else i++;
        }
        if(i>=L.length) return ERROR;
    }
}
else return INFEASIBLE;
    /********** End **********/
}
status NextElem(SqList L,ElemType e,ElemType &next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
if(L.elem!=NULL){
    int i=L.length-1;
    if(L.elem[i]==e) return ERROR;
    else{
        i=i-1;
        while(i>=0){
            if(L.elem[i]==e){
                next=L.elem[i+1];
                return OK;
            }
            i--;
        }
        if(i<0) return ERROR;
    }
}
else return INFEASIBLE;
    /********** End **********/
}
status ListInsert(SqList &L,int i,ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L.elem==NULL){return INFEASIBLE;}
    if(L.length>=L.listsize){
        ElemType *newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    }
    if(L.elem!=NULL){
        if(L.length==0){
            L.elem[0]=e;
            L.length++;
            return OK;
        }
        if(1<=i&&i<=L.length+1){
            for(int j=L.length;j>=i;j--){
                L.elem[j]=L.elem[j-1];
            }
            L.elem[i-1]=e;
            L.length++;
            return OK;
        }
        return ERROR;
    }
    /********** End **********/
}
status ListDelete(SqList &L,int i,ElemType &e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
if(L.elem)
{
if((i<1)||(i>L.length)) return ERROR;
int *p;
int *q;
p=&(L.elem[i-1]);
e=*p;
q=L.elem+L.length-1;
for(++p;p<=q;++p) 
{
    *(p-1)=*p;
}
--L.length;
return OK;
}
else return INFEASIBLE;
    /********** End **********/
}
status ListTraverse(SqList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L.elem==NULL){return INFEASIBLE;}
    if(L.length>=L.listsize){
        ElemType *newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    }
    if(L.elem){
        if(L.length){
            for(int i=0;i<L.length;i++){
                if(i != L.length-1) printf("%d ",L.elem[i]);
        else printf("%d",L.elem[i]);
            }
        }
        return OK;
    }
    /********** End **********/
}
status ListTrabverse(SqList L){
int i;
printf("\n-----------all elements -----------------------\n");
for(i=0;i<L.length;i++) printf("%d ",L.elem[i]);
printf("\n------------------ end ------------------------\n");
return L.length;
}
status MaxSubArray(SqList L)
{
	sum=0;
	ans=0;
	if(!L.elem) return ERROR;
	for(int i=0;i<L.length;i++)
	{
		sum+=L.elem[i];
		if(ans<sum) ans=sum;
		if(sum<0) sum=0;
	}
	return OK;
}
status SubArrayNum(SqList L,int k)
{
	ans=0;
	if(!L.elem) return ERROR;
	for(int i=0;i<L.length;i++)
	{
		sum=0;
		for(int j=i;j<L.length;j++)
		{
			sum+=L.elem[j];
			if(sum==k) ans++;
		}
	}
	return OK;
}
status sortList(SqList &L)
{
	if(!L.elem) return ERROR;
	int temp=0;
	
	for(int i=0;i<L.length-1;i++)
	{
		for(int j=0;j<L.length-1-i;j++)
		{
			if(L.elem[j]>L.elem[j+1])
			{
				temp=L.elem[j];
				L.elem[j]=L.elem[j+1];
				L.elem[j+1]=temp; 
			}
		}
	}
	return OK;
}
status  SaveList(SqList L,char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L.elem==NULL)
    {
        return INFEASIBLE;
    }
    else
    {
        FILE *fp=fopen(FileName,"w");
        if(!fp) return ERROR;
       //fprintf(fp,"���Ա�Ԫ��Ϊ��"); 
	   fprintf(fp,"%d\n",L.length);
        for(int i=0;i<L.length;i++)
        {
        	fprintf(fp,"%d ",L.elem[i]);
		}
        //fprintf(fp,"���Ա��������Ϊ��%d",L.listsize);
        fclose(fp);
        return OK;
    }
    /********** End **********/
}
status  LoadList(SqList &L,char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L.elem!=NULL)
    {
        return INFEASIBLE;
    }
    else
    {
    	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
        L.length=0;
        L.listsize=LIST_INIT_SIZE;
        FILE *fp=fopen(FileName,"r");
        if(!fp) return ERROR;
        fscanf(fp,"%d",&L.length);
       // fscanf(fp,"���Ա�Ԫ��Ϊ��%d",&L.elem[0]);
        for(int i=0;i<L.length;i++)
        {
        	fscanf(fp,"%d",&L.elem[i]);
		}
		//fgetchar();
        //fwrite(L.elem,sizeof(ElemType),L.length,fp);
       // fscanf(fp,"���Ա���Ϊ��%d",&L.length);
        //fgetchar();
        //fscanf(fp,"���Ա��������Ϊ��%d",&L.listsize);
        fclose(fp);
        return OK;
    }
    /********** End **********/
}

