#include"../../include/list/ArrayList.h"

#include<stdio.h>
#include<stdlib.h>

/** @brief 初始化
 * 
 * @return 指向初始化后的顺序链表
 */
arrayListPtr array_list_init() {
	arrayListPtr arrayList = (arrayListPtr) malloc(sizeof(_arrayList));
	if ( NULL == arrayList)
		return NULL;
	arrayList->data = (ElemType*) malloc(sizeof(ElemType) * DEFAULT_LENGTH);
	if ( NULL == arrayList->data)
		return NULL;
	arrayList->size = 0;
	arrayList->length = DEFAULT_LENGTH;
	arrayList->expand = DEFAULT_EXPAND;
	return arrayList;
}

/** @brief 顺序表扩容
 * 
 * @pre 顺序表arrayList 存在
 * @param arrayList 要扩容的顺序表
 * @return OK 成功
 * @retval ERROR 失败
 */
STATUS array_list_expand(arrayListPtr arrayList) {
	if ( NULL == arrayList) {
		puts("顺序表不存在！");
		exit(0);
	}

//	printf("length = %d\n",arrayList->length);
	arrayList->length = (int) (arrayList->length * (1 + arrayList->expand));
//	printf("length = %d\n",arrayList->length);
	size_t len = arrayList->length * sizeof(ElemType);
//	printf("len = %d\n",len);
	arrayList->data = (ElemType*) realloc(arrayList->data, len);
	if ( NULL == arrayList->data) {
		puts("未分配空间！");
		exit(0);
	}

	return OK;
}

/** @brief 判断线性表是否为空
 * 
 * @param arrayList 给定的线性表
 * @retval TRUE 为空
 * @retval FALSE 不为空
 */
BOOL array_list_is_empty(arrayListPtr arrayList) {
	if (0 == arrayList->size)
		return TRUE;
	else
		return FALSE;
}

/** @brief 将顺序表中第ｉ个位置的元素的值返回给ｅ
 * 
 * @pre 顺序表arrayList存在
 * @pre 位置i合法，即i满足 0 <= i < arrayList->size 
 * @param arrayList 顺序表
 * @param i 位置
 * @param e 保存第ｉ个位置元素的值
 * @return
 */
STATUS array_list_get_elem(arrayListPtr arrayList, int i, ElemType * e) {
	if ( NULL == arrayList) {
		puts("顺序表不存在!");
		return ERROR;
	}

	if (i < 0 || i >= arrayList->size) {
		printf("不存在位置：%-3d\n", i);
		return ERROR;
	}

	*e = arrayList->data[i];
	return OK;
}

/** @brief 向顺序表中追加一个数据
 * 
 * @pre 顺序表arrayList存在
 * 
 * @param arrayList 顺序表
 * @param e 要追加的元素
 * @retval OK 成功
 * @retval ERROR 失败
 */
STATUS array_list_append(arrayListPtr arrayList, ElemType e) {
	if ( NULL == arrayList) {
		puts("顺序表不存在！");
		exit(0);
	}

	if (arrayList->size >= arrayList->length) {
		array_list_expand(arrayList);
	}

	arrayList->data[arrayList->size] = e;
	arrayList->size++;

	return OK;
}

/** @brief 将给定元素插入指定位置
 * 
 * @pre 顺序表arrayList存在
 * @pre 位置i合法，如果i<0或i>arrayList->size 则为非法
 * 
 * @param arrayList 给定的顺序表
 * @param i 位置
 * @param e 要插入的元素
 * @return
 */
STATUS array_list_insert(arrayListPtr arrayList, int i, ElemType e) {
	if ( NULL == arrayList) {
		puts("顺序表不存在！");
		exit(0);
	}

	if (arrayList->size >= arrayList->length) {
		array_list_expand(arrayList);
	}

	if (i < 0 || i > arrayList->size) {
		printf("位置%d非法，应在0-%d之间！\n", i, arrayList->size + 1);
		return ERROR;
	}

	if (i < arrayList->size) {
		int j = 0;
		for (j = arrayList->size; j >= i; j--) {
			arrayList->data[j + 1] = arrayList->data[j];
		}
	}

	arrayList->data[i] = e;
	arrayList->size++;

	return OK;

	return OK;
}

/** @brief 返回给定顺序表的数据长度
 * 
 * @pre 给定的顺序表 arrayList 不为NULL
 * @param arrayList 给定的顺序表
 * @return 顺序表的长度
 */
int array_list_size(arrayListPtr arrayList) {
	if ( NULL == arrayList) {
		puts("顺序表不存在！");
		exit(0);
	}

	return arrayList->size;

}

/** @brief 将线性表清空
 * 
 * @pre 线性表存在
 * 
 * @param arrayList 线性表
 * @retval OK 成功
 * @retval ERROR 失败
 */
STATUS array_list_clear(arrayListPtr arrayList) {
	if ( NULL == arrayList) {
		puts("线性表不存在！");
		return ERROR;
	}

	arrayList->size = 0;
	return OK;
}

/** @brief 查找元素ｅ在线性表中的位置
 * 
 * @pre 线性表存在且不为空
 * 
 * @param arrayList 顺序表
 * @param e　要查找的元素
 * @return e　在顺序表中的位置
 * @retval ERROR 不在线性表中或线性表为空或线性表不存在
 */
int array_list_index(arrayListPtr arrayList, ElemType e) {
	if ( NULL == arrayList) {
		puts("线性表不存在！");
		return ERROR;
	}

	if (array_list_is_empty(arrayList)) {
		puts("线性表中无任何数据！");
		return ERROR;
	}

	int len = array_list_size(arrayList);
	ElemType tmp;
	ElemType * pe = &tmp;
	int index = -1;
	while (len >= 0) {
		len--;
		array_list_get_elem(arrayList, len, pe);
		if (e == tmp) {
			index = len;
			break;
		}
	}

	return index;
}

/** @brief 删除线性表L中第ｉ个位置元素，并用ｅ返回其值
 * 
 * @pre 线性表存在
 * @pre 线性表不为空
 * @pre i　的位置合法，即i满足 0 <= i < arrayList->size
 * 
 * @param arrayList 线性表
 * @param i　要删除的元素的位置
 * @param e　保存删除的元素的值
 * @retval OK 删除成功
 * @retval ERROR 删除失败
 */
STATUS array_list_delete(arrayListPtr arrayList, int i, ElemType * e) {
	if ( NULL == arrayList) {
		puts("线性表不存在！");
		return ERROR;
	}

	if (array_list_is_empty(arrayList)) {
		puts("线性表中无任何数据！");
		return ERROR;
	}
	
	if( i < 0 || i >= arrayList->size ){
		printf("要删除的元素的位置应在0-%d之间！",arrayList->size - 1);
		return ERROR;
	}
	
	*e = arrayList->data[i];
	int len = array_list_size(arrayList);
	while( i < len ){
		arrayList->data[i] = arrayList->data[i+1];
		i++;
	}
	
	arrayList->size--;
	
	return OK;
}
