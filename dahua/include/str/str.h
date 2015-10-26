/** @file str.h
 * 串结构及操作定义
 *
 *  Created on: 2015年10月25日
 *      Author: laolang
 */

#ifndef STR_STR_H_
#define STR_STR_H_


#include"../../include/global/global.h"


/** @brief 默认数组容量
 * 
 */
//#define DEFAULT_LENGTH 50

/** @brief 默认数组扩充比例
 * 
 */
//#define DEFAULT_EXPAND 0.75

/** @struct 串结构定义
 * 
 */
struct __str{
	/** @brief 串数组指针
	 * 
	 */
	char * data;
	
//	/** @brief 数组容量
//	 * 
//	 */
//	int length;
	
	/** @brief 串数据长度
	 * 
	 */
	int size;
	
	/** @brief 数组扩充比例
	 * 
	 */
	double expand;
};


/** @brief 串结构类型
 * 
 */
typedef struct __str _str;

/** @brief 串结构指针类型
 * 
 */
typedef struct __str * String;

//StrAssign(T,*chars) : 生成一个其值等于字符串常量cahrs的串Ｔ

/** @brief 根据字符串常量chars生成一个串
 * 
 * @param chars 字符串常量
 * @return 返回生成的串
 * @retval NULL 创建串失败
 */
String str_assign( char * chars );

/** @brief 串数组扩容
 * 
 * @pre 串string存在
 * 
 * @param string 要扩容的串
 * @retval OK 扩容成功
 * @retval ERROR 扩容失败
 */
STATUS str_expand( String string );


/** @brief 由串string复制得到一个新串
 * 
 * @pre 串string 存在
 * @param string 源串
 * @return 新的串
 * @retval NULL 复制失败
 */
String str_copy(String string );

/** @brief 将串string清空
 * 
 * @pre 串string存在
 * @param string 要清空的串
 * @retval OK 操作成功
 * @retval ERROR 操作失败
 */
STATUS str_clear(String string );

/** @brief 判断串string是否为空串
 * 
 * @pre 串string存在
 * 
 * @param string 要判断的串
 * 
 * @retval TRUE 为空
 * @retval FALSE 不为空
 */
BOOL str_is_empty(String string );

/** @brief 得到串string的长度
 * 
 * @pre 串string 存在
 * @param string 要计算长度的串
 * @return 串string的长度
 * @retval -1 操作失败
 */
int str_size(String string);

/** @brief 比较两人个串的大小
 * 
 * @param str1 串１
 * @param str2　串２
 * @retval -1 str1 < str2
 * @retval 0 str2 = str2
 * @retval 1 str1 > str2
 */
int str_compare(String str1, String str2);

/** @brief 链接两人个字符串返回新的字符串
 * 
 * @pre 两人个串存在且不为空
 * @param str1 串１
 * @param str2　串２
 * @return 新的串
 * @retval NULL 链接失败！
 */
String str_concat(String str1, String str2 );

/** @brief 从串string中的第pos个字符取出长度为len的子串
 * @pre 串string存在
 * @pre pos 满足：0 <= pos <= string->size - 1
 * @pre len 满足：0 <= len <= string->size - pos
 * @param string 源串
 * @param pos 取子串的起始位置
 * @param len 要取的子串的长度
 * @return 取出的子串
 * @retval NULL 取子串失败
 */
String str_sub( String string, int pos, int len );

/** @brief 在串string的第pos个位置插入串in
 * 
 * @pre 串string和in存在且不为空
 * 
 * @param string 源串
 * @param pos　要在源口中中插入串的位置
 * @param in　要插入的串
 * @return　返回新的串
 * @retval NULL 插入失败
 */
String str_insert(String string, int pos, String in );

/** @brief 在串string中，从第pos个字符开始删除长度为len的子串
 * 
 * @pre 串string存在且不为空
 * @pre pos应满足：0 <= pos && pos <= string->size - 1
 * @pre len 应满足：1 <= len && len <= string->size - pos
 * 
 * @param string 源串
 * @param pos　删除的起始位置
 * @param len　要删除的子串的长度
 * @return　删除子串后的串
 * @retval NULL 删除失败
 */
String str_delete(String string, int pos, int len );

/** @brief 查找串string中第pos个字符后，串t第一次出现的位置
 * 
 * @pre 串string 和 串t存在
 * @pre pos满足 0<= pos && pos <= string->size - t->size
 * @param string 主串
 * @param t　要查找的串
 * @param pos　查找的起始位置
 * @return　t第一次出现的位置
 * @retval 0 未找到
 */
int str_index( String string , String t, int pos );

/** @brief 将串string中所有与串t相等的不重叠的子串替换为串v
 * 
 * @pre 串string,t,v存在且不为空
 * 
 * @param string 主串
 * @param t 被替换的子串
 * @param v 替换的串
 * @return　替换后的新串
 */
String str_replace(String string, String t, String v);


//Replace(S,T,V): 串Ｓ、Ｔ和Ｖ存在，Ｔ是非空串。用Ｖ替换主串Ｓ中出现的所有与串Ｔ相等的不重叠的子串



#endif /* STR_STR_H_ */
