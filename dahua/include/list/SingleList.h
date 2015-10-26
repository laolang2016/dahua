/** @file SingleList.h
 *
 *  Created on: 2015年10月24日
 *      Author: laolang
 */

#ifndef LIST_SINGLELIST_H_
#define LIST_SINGLELIST_H_

#include"../element/element.h"
#include"../global/global.h"

/** @struct 线性表的链式表结构
 * 
 */
struct __signlelsit {
	/** @brief 数据域
	 * 
	 */
	ElemType data;

	/** @brief 指针域
	 * 
	 */
	struct __signlelsit *next;
};

/** @brief 结点类型
 * 
 */
typedef struct __signlelsit _node;

/** @brief 链表类型
 * 
 */
typedef struct __signlelsit signleList;

/** @brief 链表指针类型
 * 
 */
typedef struct __signlelsit * signleListPtr;

/** @brief 初始化
 * 
 * @return 指向初始化后的链表
 * @retval NULL 创建失败
 */
signleListPtr signle_list_init();


/** @brief 判断线性表是否为空
 * 
 * @pre 链表存在
 * 
 * @param signleList 给定的线性表
 * @retval TRUE 为空
 * @retval FALSE 不为空
 */
BOOL signle_list_is_empty(signleListPtr signleList);

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
STATUS signle_list_get_elem(signleListPtr signleList, int i, ElemType * e);

/** @brief 向表中追加一个数据
 * 
 * @pre 表signleList存在
 * 
 * @param signleList 表
 * @param e 要追加的元素
 * @retval OK 成功
 * @retval ERROR 失败
 */
STATUS signle_list_append(signleListPtr signleList, ElemType e);

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
STATUS signle_list_insert(signleListPtr signleList, int i, ElemType e);

/** @brief 返回给定表的数据长度
 * 
 * @pre 给定的表 signleList 不为NULL
 * @param signleList 给定的表
 * @return 表的长度
 */
int signle_list_size(signleListPtr signleList);

/** @brief 将线性表清空
 * 
 * @pre 线性表存在
 * 
 * @param signleList 线性表
 * @retval OK 成功
 * @retval ERROR 失败
 */
STATUS signle_list_clear(signleListPtr signleList);

/** @brief 查找元素ｅ在线性表中的位置
 * 
 * @pre 线性表存在且不为空
 * 
 * @param signleList 表
 * @param e　要查找的元素
 * @return e　在表中的位置
 * @retval ERROR 不在线性表中或线性表为空或线性表不存在
 */
int signle_list_index(signleListPtr signleList, ElemType e);

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
STATUS signle_list_delete(signleListPtr signleList, int i, ElemType * e);

#endif /* LIST_SINGLELIST_H_ */
