#include <stdio.h>
#include "libalgorithm.h"


int main(void)
{
	int i = 0;
	List list;
	ElemType e ;
	printf("Test SqList Function\r\n");
	InitList(&list);
	showList(list);
	
	for(i = 1;i < 10 ;i ++){
		ListInsert(&list,1,i*3);
	}
	showList(list);
	
	ListDelete(&list,3,&e);
	showList(list);
	
	printf("SqList length: %d\r\n",ListLength(list));
    return 0;
}
