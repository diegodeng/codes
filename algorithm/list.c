#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libalgorithm.h"
/*
 *  List 线性表的基本函数
 */

List * InitList(List *list)
{
	if(list == NULL){
		loge("InitList parameter error\r\n");
		goto error;
	}
	memset(list,0,sizeof(List));
	logi("InitList ok\r\n");
	return list;
error:
	return NULL;
}
int isEmptyList(List list)
{
	if(list.length == 0){
		return 1;
	}
	else{
		return 0;
	}
}
void ClearList(List *list)
{
	return;
}
int  GetElem(List list,int pos, ElemType *e)
{
	int i =1;
	if(pos < 1 || pos > MAXSIZE){
        return -1;
    }
    *e = list.data[pos];
	return 0;
}
int	 LocateElem(List list,ElemType e)
{
	return 0;
}
int  ListInsert(List *list,int pos,ElemType e)
{
	return 0;
}
int  ListDelete(List *list,int pos,ElemType *e)
{
	return 0;
}
int  ListLength(List list)
{
	return list.length;
}

