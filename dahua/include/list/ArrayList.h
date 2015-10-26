/**@file ArrayList.h
 * 顺序表
 *  Created on: 2015年10月22日
 *      Author: laolang
 */

#ifndef LIST_ARRAYLIST_H_
#define LIST_ARRAYLIST_H_

#include"../element/element.h"
#include"../global/global.h"

/** @def 顺序表默认表容量
 * 
 */
#define DEFAULT_LENGTH 20

/** @def 顺序表默认扩充比例
 * 
 */
#define DEFAULT_EXPAND 0.75

/** @struct 顺序表结构
 * 
 */
struct __arrayList{
	/** @brief 数组指针 */
	ElemType * data;
	
	/** @brief 表容量 */
	int length;
	
	/** @brief 数据个数 */
	int size;
	
	/** @brief 默认扩充比例 */
	double expand;
};

/** @brief 顺序表结构
 * 
 */
typedef struct __arrayList _arrayList;

/** @brief 顺序表结构指针
 * 
 */
typedef struct __arrayList * arrayListPtr;

//InitList(*L);         初始化操作，建立一个空的线性表 L。

/** @brief 初始化
 * 
 * @return 指向初始化后的顺序链表
 */
arrayListPtr array_list_init();

/** @brief 顺序表扩容
 * 
 * @pre 顺序表arrayList 存在
 * @param arrayList 要扩容的顺序表
 * @return OK 成功
 * @retval ERROR 失败
 */
STATUS array_list_expand(arrayListPtr arrayList );


/** @brief 判断线性表是否为空
 * 
 * @param arrayList 给定的线性表
 * @retval TRUE 为空
 * @retval FALSE 不为空
 */
BOOL array_list_is_empty(arrayListPtr arrayList );

/** @brief 将顺序表中第ｉ个位置的元素的值返回给ｅ
 * 
 * @pre 顺序表arrayList存在
 * @pre 位置i合法，即i满足 0 <= i < arrayList->size 
 * @param arrayList 顺序表
 * @param i 位置
 * @param e 保存第ｉ个位置元素的值
 * @return
 */
STATUS array_list_get_elem(arrayListPtr arrayList, int i , ElemType * e);


/** @brief 向顺序表中追加一个数据
 * 
 * @pre 顺序表arrayList存在
 * 
 * @param arrayList 顺序表
 * @param e 要追加的元素
 * @retval OK 成功
 * @retval ERROR 失败
 */
STATUS array_list_append(arrayListPtr arrayList , ElemType e);


/** @brief 将给定元素插入指定位置
 * 
 * @pre 顺序表arrayList存在
 * @pre 位置i合法，如果i<0或i>arrayList->size + 1 则为非法
 * 
 * @param arrayList 给定的顺序表
 * @param i 位置
 * @param e 要插入的元素
 * @return
 */
STATUS array_list_insert( arrayListPtr arrayList, int i , ElemType e);


/** @brief 返回给定顺序表的数据长度
 * 
 * @pre 给定的顺序表 arrayList 不为NULL
 * @param arrayList 给定的顺序表
 * @return 顺序表的长度
 */
int array_list_size( arrayListPtr arrayList );



/** @brief 将线性表清空
 * 
 * @pre 线性表存在
 * 
 * @param arrayList 线性表
 * @retval OK 成功
 * @retval ERROR 失败
 */
STATUS array_list_clear(arrayListPtr arrayList );


/** @brief 查找元素ｅ在线性表中的位置
 * 
 * @pre 线性表存在且不为空
 * 
 * @param arrayList 顺序表
 * @param e　要查找的元素
 * @return e　在顺序表中的位置
* @retval ERROR 不在线性表中或线性表为空或线性表不存在
 */
int array_list_index(arrayListPtr arrayList, ElemType e );


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
STATUS array_list_delete(arrayListPtr arrayList, int i, ElemType * e);





#endif /* LIST_ARRAYLIST_H_ */
