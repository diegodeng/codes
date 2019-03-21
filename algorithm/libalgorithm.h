#ifndef _LIBALGORITHM_H_
#define _LIBALGORITHM_H_


#define DBG  1
#define DDBG 1

#define logd printf
#define logi printf
#define loge printf


typedef enum{
	Error = -1,
	Ok = 0
}Status;

/*
 *  List 线性表相关
 */
#define MAXSIZE 20
typedef int ElemType;

typedef struct SqList{
	ElemType data[MAXSIZE];
	int length;
}List;



List * InitList(List *list);
int  isEmptyList(List list);
void ClearList(List *list);
int  GetElem(List list,int pos, ElemType *e);
int	 LocateElem(List list,ElemType e);
int  ListInsert(List *list,int pos,ElemType e);
int  ListDelete(List *list,int pos,ElemType *e);
int  ListLength(List list);

/*
 *  LinkList 链表相关
 */


#endif /*_LIBALGORITHM_H_*/
