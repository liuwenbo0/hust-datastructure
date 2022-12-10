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
	printf("    	  ——————————————————\n");
	printf("    	  13.MaxSubArray    14.SubArrayNum\n");
	printf("    	  15.sortList       16.SaveList\n");
	printf("    	  17.LoadList\n");
	printf("    	  0. Exit\n");
	printf("-------------------------------------------------\n");
	printf("    请选择你的操作[0~12]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
	   	{
		 if(InitList(L)==OK) printf("线性表创建成功！\n");
		 else printf("线性表创建失败！\n");
		 getchar();getchar();
		 break;
		}
	   case 2:
		 if(DestroyList(L)==OK)  printf("线性表销毁成功！\n"); 
		 else printf("线性表销毁失败！\n");   
		 getchar();getchar();
		 break;
	   case 3:
		 if(ClearList(L)==OK)    printf("线性表清空成功！\n"); 
		 else printf("线性表清空失败！\n");
		 getchar();getchar();
		 break;
	   case 4:
		 if(ListEmpty(L)==TRUE)   printf("线性表为空！\n"); 
		 else if(ListEmpty(L)==FALSE) printf("线性表不为空！\n");
		 else printf("线性表判空失败！\n");   
		 getchar();getchar();
		 break;
	   case 5:
	{
    	 if(ListLength(L)!=INFEASIBLE){
		 int Length=0;
		 Length=ListLength(L);
		 printf("计算线性表长度成功！长度为%d\n",Length);}
		 else printf("计算线性表长度失败！\n");
		 getchar();getchar();
		 break;
	}
	   case 6:
	{
		 int i=0; ElemType e=0;
	   	 printf("请输入你想获取第几个元素！\n");
	   	 scanf("%d",&i);
		 if(GetElem(L,i,e)==ERROR)
		 {
		 	printf("i取值不合法！\n");
		 }
		 else if(GetElem(L,i,e)==INFEASIBLE) 
		 {
		 printf("获取线性表元素失败！\n");
		 }
		 else if(GetElem(L,i,e)==OK) 
		 {
		 	printf("获取线性表元素成功！\n");
		 	printf("该元素为%d",e);
		 }     
		 getchar();getchar();
		 break;
	}
	   case 7:
	{   
	    int i=0;
	    ElemType e=0;
	    printf("请输入想要查找的元素！\n");
	    scanf("%d",&e);
	    i=LocateElem(L,e);
	    if(i==INFEASIBLE)
		{
	    	printf("线性表不存在！\n");
		}
		if(i==0)
		{
			printf("该元素不存在！\n");
		}
		if(i!=INFEASIBLE&&i!=0)
		{
			printf("该元素位置为%d\n",i);
		}
		 getchar();getchar();
		 break;
    }
	   case 8:
		{
		 ElemType e=0;
		 printf("请输入你想获得前驱元素的元素!\n");
		 scanf("%d",&e);
		 ElemType pre_e=0;
		 if(PriorElem(L,e,pre_e)==ERROR)
		 {
		 	printf("该元素没有前驱！\n");
		 } 
		 if(PriorElem(L,e,pre_e)==INFEASIBLE)
		 {
		 	printf("该线性表不存在！\n");
		 }
		 if(PriorElem(L,e,pre_e)==OK)
		 {
		 	printf("前驱获得成功！\n");
		 	printf("该前驱为%d",pre_e);
		 }  
		 getchar();getchar();
		 break;
		}
	   case 9:
	   	{
		 ElemType e=0;
		 printf("请输入你想获得后继元素的元素!\n");
		 scanf("%d",&e);
		 ElemType next_e=0;
		 if(NextElem(L,e,next_e)==ERROR)
		 {
		 	printf("该元素没有后继！\n");
		 } 
		 if(NextElem(L,e,next_e)==INFEASIBLE)
		 {
		 	printf("该线性表不存在！\n");
		 }
		 if(NextElem(L,e,next_e)==OK)
		 {
		 	printf("后继获得成功！\n");
		 	printf("该后继为%d",next_e);
		 }   
		 getchar();getchar();
		 break;
		}
	   case 10:
		{int i;
		 ElemType e;
		 scanf("%d%d", &i, &e);
         if(ListInsert(L, i, e)==OK) printf("成功插入！");
         else if(ListInsert(L, i, e)==INFEASIBLE) printf("线性表L不存在！");
         else printf("插入位置不合法！");
		 getchar();getchar();
		 break;
		}

	   case 11:
	   	{
	   	 int i=0,j=0;
	   	 ElemType e=0;
	   	 printf("请输入你想要删除第几个元素！\n");
	   	 scanf("%d",&i);
	   	 j=ListDelete(L,i,e);
	   	 if(j==ERROR)
		 {
	   	 	printf("删除位置不合法！\n");
		 }
		 if(j==INFEASIBLE)
		 {
		 	printf("线性表不存在！\n");
		 }
		 if(j==OK)
		 {
		 	printf("删除成功！\n");
		 	printf("%d",e);
		 }    
		 getchar();getchar();
		 break;
		}
	   case 12:
		 //printf("\n----ListTrabverse功能待实现！\n");     
		 if(!ListTrabverse(L)) printf("线性表是空表！\n");
		getchar();getchar();
		 break;
       case 13:
		{
		 MaxSubArray(L);
		 printf("最大连续子数组和为%d",ans);
		 getchar();getchar();
		 break;
		}
		case 14:
		{
		 int k=0;
		 printf("请输入数字k\n");
		 scanf("%d",&k); 
		 SubArrayNum(L,k);
		 printf("该数组中和为%d的连续子数组的个数为%d！\n",k,ans);
		 getchar();getchar();
		 break;
		}
		case 15:
		{
		 printf("数组已完成升序排列！\n");
		 sortList(L);
		 getchar();getchar();
		 break;
		} 
		case 16:
		{
			char FileName[100];
			printf("请输入文件名\n");
			scanf("%s",&FileName); 
			if(SaveList(L,FileName))
			printf("线性表已保存为txt文件！\n");
			else 
			printf("保存失败！\n");
			getchar();getchar();
		    break;
		}
		case 17:
		{
			char FileName[100];
			printf("请输入文件名\n");
			scanf("%s",&FileName); 
			if(LoadList(L,FileName))
			printf("线性表已由txt文件成功加载！\n");
			else 
			printf("加载失败！\n");
			getchar();getchar();
		    break;
		}
	case 0:
         break;
	}//end of switch
  }//end of while
printf("欢迎下次再使用本系统！\n");
}//end of main()
/*--------page 23 on textbook --------------------*/
status InitList(SqList& L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
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
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
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
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem==NULL)
    {
        return INFEASIBLE;
    }
    else
    {
        FILE *fp=fopen(FileName,"w");
        if(!fp) return ERROR;
       //fprintf(fp,"线性表元素为："); 
	   fprintf(fp,"%d\n",L.length);
        for(int i=0;i<L.length;i++)
        {
        	fprintf(fp,"%d ",L.elem[i]);
		}
        //fprintf(fp,"线性表最大容量为：%d",L.listsize);
        fclose(fp);
        return OK;
    }
    /********** End **********/
}
status  LoadList(SqList &L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
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
       // fscanf(fp,"线性表元素为：%d",&L.elem[0]);
        for(int i=0;i<L.length;i++)
        {
        	fscanf(fp,"%d",&L.elem[i]);
		}
		//fgetchar();
        //fwrite(L.elem,sizeof(ElemType),L.length,fp);
       // fscanf(fp,"线性表长度为：%d",&L.length);
        //fgetchar();
        //fscanf(fp,"线性表最大容量为：%d",&L.listsize);
        fclose(fp);
        return OK;
    }
    /********** End **********/
}

