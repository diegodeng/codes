#ifndef _LIBALGORITHM_H_
#define _LIBALGORITHM_H_


#define DBG  1
#define DDBG 1

#define logd printf
#define logi printf
#define loge printf


#define MAXSIZE 20
typedef int ElemType;

/***********************************************************************
 ***************************  基本数据结构  ******************************
 ***********************************************************************/
/*
 *  List 线性表相关
 */
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
void showList(List list);

/*
 *  LinkList 链表相关
 */
typedef struct Node{
	ElemType data;
	struct Node *next;
}Node;

typedef Node* LinkList;

LinkList InitLinkList();
void ClearLinkList(LinkList *L);
void DestoryLinkList(LinkList *L);
int  getElem(LinkList L,int pos, ElemType *e);
int	 locateElem(LinkList L,ElemType e);
int  LinkListInsert(LinkList *L,int pos,ElemType e);
int  LinkListDelete(LinkList *L,int pos,ElemType *e);
int  LinkListLength(LinkList L);
void showLinkList(LinkList L);

/*
 * DoubleList 双向链表 
 */
 
/*
 * CircleList 循环链表 
 */

/*
 * 队列：
 */

/*
 * 栈结构： 
 */
 
/*
 * 树结构
 */
 
/*
 * 图结构 
 */
 
/***********************************************************************
 ****************************  基本算法  ********************************
 ***********************************************************************/
 
 
 
#endif /*_LIBALGORITHM_H_*/
