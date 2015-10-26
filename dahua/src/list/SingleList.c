/*
 * SingleList.c
 *
 *  Created on: 2015年10月24日
 *      Author: laolang
 */

#include<stdio.h>
#include<stdlib.h>

#include"../../include/list/SingleList.h"

/** @brief 初始化
 * 
 * @return 指向初始化后的链表
 * @retval NULL 创建失败
 */
signleListPtr signle_list_init() {
	signleListPtr list = (signleListPtr) malloc(sizeof(signleList));

	if ( NULL == list) {
		puts("分配内存失败！");
		return NULL;
	}

	list->next = NULL;

	return list;
}

/** @brief 判断线性表是否为空
 * 
 * @pre 链表存在
 * 
 * @param signleList 给定的线性表
 * @retval TRUE 为空
 * @retval FALSE 不为空
 */
BOOL signle_list_is_empty(signleListPtr signleList) {
	if ( NULL == signleList) {
		puts("链表不存在！");
		exit(0);
	}

	if ( NULL == signleList->next) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/** @brief 将表中第ｉ个位置的元素的值返回给ｅ
 * 
 * @pre 表signleList存在
 * @pre 表signleList不为空
 * @pre 位置i合法，即i满足 0 <= i < signleList->size 
 * @param signleList 表
 * @param i 位置
 * @param e 保存第ｉ个位置元素的值
 * @retval OK 查找成功
 * @retval ERROR 查找失败
 */
STATUS signle_list_get_elem(signleListPtr signleList, int i, ElemType * e) {
	if ( NULL == signleList) {
		puts("链表不存在！");
		exit(0);
	}
	if (signle_list_is_empty(signleList)) {
		puts("链表为空！");
		return NULL;
	}

	if (i < 0) {
		puts("位置非法，不能小于０");
		return ERROR;
	}
	_node * node = signleList;

	while (i >= 0 && NULL != node) {
		node = node->next;
		i--;
	}

	if ( NULL == node || i > 0) {
		puts("位置非法，大于链表长度");
		return ERROR;
	}

	*e = node->data;

	return OK;
}

/** @brief 向表中追加一个数据
 * 
 * @pre 表signleList存在
 * 
 * @param signleList 表
 * @param e 要追加的元素
 * @retval OK 成功
 * @retval ERROR 失败
 */
STATUS signle_list_append(signleListPtr signleList, ElemType e) {
	if ( NULL == signleList) {
		puts("链表不存在！");
		exit(0);
	}

	_node * node = signleList;
	while ( NULL != node->next) {
		node = node->next;
	}

	_node * newNode = (_node*) malloc(sizeof(_node));
	newNode->data = e;
	newNode->next = NULL;

	node->next = newNode;

	return OK;
}

/** @brief 将给定元素插入指定位置
 * 
 * @pre 表signleList存在
 * @pre 位置i合法，如果i<0或i>signleList->size + 1 则为非法
 * 
 * @param signleList 给定的表
 * @param i 位置
 * @param e 要插入的元素
 * @return
 */
STATUS signle_list_insert(signleListPtr signleList, int i, ElemType e) {
	if ( NULL == signleList) {
		puts("链表不存在！");
		exit(0);
	}

	if (signle_list_is_empty(signleList)) {
		puts("链表为空！");
		return NULL;
	}

	if (i < 0) {
		puts("位置非法，不能小于０");
		return ERROR;
	}

	_node * node = signleList;
	while ( NULL != node && i > 0) {
		node = node->next;
		i--;
	}

	if ( NULL == node || i > 0) {
		puts("位置非法，大于链表长度");
		return ERROR;
	}

	_node * newNode = (_node *) malloc(sizeof(_node));
	newNode->data = e;
	newNode->next = node->next;
	node->next = newNode;

	return OK;
}

/** @brief 返回给定表的数据长度
 * 
 * @pre 给定的表 signleList 不为NULL
 * @param signleList 给定的表
 * @return 表的长度
 */
int signle_list_size(signleListPtr signleList) {
	if ( NULL == signleList) {
		puts("链表不存在！");
		exit(0);
	}

	_node * node = signleList->next;
	int len = 0;
	while ( NULL != node) {
		len++;
		node = node->next;
	}
	return len;
}


/** @brief 将线性表清空
 * 
 * @pre 线性表存在
 * 
 * @param signleList 线性表
 * @retval OK 成功
 * @retval ERROR 失败
 */
STATUS signle_list_clear(signleListPtr signleList){
	if(NULL == signleList ){
		puts("线性表不存在！");
		exit(0);
	}
	
	_node * node = NULL;
	while( NULL != signleList->next ){
		node = signleList->next;
		signleList->next = node->next;
		free(node);
	}
	
	return OK;
}

/** @brief 查找元素ｅ在线性表中的位置
 * 
 * @pre 线性表存在且不为空
 * 
 * @param signleList 表
 * @param e　要查找的元素
 * @return e　在表中的位置
 * @retval ERROR 不在线性表中或线性表为空或线性表不存在
 */
int signle_list_index(signleListPtr signleList, ElemType e){
	if ( NULL == signleList) {
		puts("链表不存在！");
		exit(0);
	}

	if (signle_list_is_empty(signleList)) {
		puts("链表为空！");
		return NULL;
	}
	
	int index = 0;
	_node * node = signleList->next;
	while( e != node->data ){
		node = node->next;
		index++;
	}
	
	return index;
}

/** @brief 删除线性表L中第ｉ个位置元素，并用ｅ返回其值
 * 
 * @pre 线性表存在
 * @pre 线性表不为空
 * @pre i　的位置合法，即i满足 0 <= i < signleList->size
 * 
 * @param signleList 线性表
 * @param i　要删除的元素的位置
 * @param e　保存删除的元素的值
 * @retval OK 删除成功
 * @retval ERROR 删除失败
 */
STATUS signle_list_delete(signleListPtr signleList, int i, ElemType * e){
	if ( NULL == signleList) {
		puts("链表不存在！");
		exit(0);
	}

	if (signle_list_is_empty(signleList)) {
		puts("链表为空！");
		return NULL;
	}
	
	_node * node = signleList;
	_node * t = NULL;
	if( 0 == i ){
		t = node->next;
		printf("data = %d\n",t->data);
		node->next = t->next;
		printf("data = %d\n",node->next->data);
		*e = t->data;
		free(t);
		return OK;
	}
	while( NULL != node && i > 0 ){
		node = node->next;
		i--;
	}

	t = node->next;
	node->next = t->next;
	*e = t->data;
	free(t);
	
	return OK;
}



