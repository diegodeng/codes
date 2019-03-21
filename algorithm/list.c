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
	if(pos < 1 || pos > MAXSIZE){
        return -1;
    }
    *e = list.data[pos];
	return 0;
}
int	 LocateElem(List list,ElemType e)
{
	int i =1;
	for(i;i < list.length;i++){
		if(list.data[i] == e){
			return i;
		}
	}
	return 0;
}
int  ListInsert(List *list,int pos,ElemType e)
{
	int i =0 ;
	if(pos < 1 || pos > MAXSIZE){
		loge("ListInsert parameter error\r\n");
		return -1;
	}
//从插入的位置整体后移
//index 0,1,2,3,4,5,6,7 
//array[1,2,3,4,9,5,6,7,8]  5
	for(i = list->length;i >= pos; i--){
		list->data[i] = list->data[i-1]; 
	}
	list->data[i] = e;
	list->length += 1;
	
	if(DBG){logd("ListInsert: pos[%d],e:[%d]\r\n",pos,e);}
	return 0;
}
int  ListDelete(List *list,int pos,ElemType *e)
{
	int i = 0;
	
	if(pos < 1 || pos > list->length){
		loge("ListInsert parameter error\r\n");
		return -1;
	}
	*e = list->data[pos-1];
//向删除的位置前移动 pos 代表线性表的位置 i = index;
//index  0,1,2,3,4,5,6,7
//list  [1,2,3,4,5,6,7,8]
	for(i = pos; i < list->length; i++){
		list->data[i-1] = list->data[i];
	}
	list->length -= 1;
	return 0;
}
int  ListLength(List list)
{
	return list.length;
}

void showList(List list)
{
	int i = 0;
	if(list.length == 0){
		logi("empty Sqlist\r\n");
		return;
	}
	for(i;i < list.length; i++){
		logi("Sqlist: pos[%d], value = [%d]\r\n",i+1,list.data[i]);
	}
	return;
}
