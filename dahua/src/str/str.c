/*
 * str.c
 *
 *  Created on: 2015年10月25日
 *      Author: laolang
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../../include/str/str.h"

/** @brief 根据字符串常量chars生成一个串
 * 
 * @param chars 字符串常量
 * @return 返回生成的串
 * @retval NULL 创建串失败
 */
String str_assign(char * chars) {
	String string = (String) malloc(sizeof(_str));
	if ( NULL == string) {
		puts("分配空间失败！");
		exit(0);
	}

	string->size = strlen(chars);
	string->data = (char*) malloc(sizeof(char) * string->size);
	if ( NULL == string->data) {
		puts("分配空间失败！");
		exit(0);
	}

	strcpy(string->data, chars);
	string->data[string->size] = '\0';

	return string;
}

/** @brief 串数组扩容
 * 
 * @pre 串string存在
 * 
 * @param string 要扩容的串
 * @retval OK 扩容成功
 * @retval ERROR 扩容失败
 */
STATUS str_expand(String string) {
	if ( NULL == string || NULL == string->data) {
		puts("串不存在！");
		exit(0);
	}

	string->size = (int) (string->size * (1 + string->expand));
	size_t len = sizeof(char) * string->size;
	string->data = (char*) realloc(string->data, len);

	if ( NULL == string->data) {
		puts("分配空间失败！");
		exit(0);
	}

	return OK;
}

/** @brief 由串string复制得到一个新串
 * 
 * @pre 串string 存在
 * @param string 源串
 * @return 新的串
 * @retval NULL 复制失败
 */
String str_copy(String string) {
	String str = str_assign(string->data);
	str->size = string->size;
	str->data[str->size] = '\0';

	return str;
}

/** @brief 将串string清空
 * 
 * @pre 串string存在
 * @param string 要清空的串
 * @retval OK 操作成功
 * @retval ERROR 操作失败
 */
STATUS str_clear(String string) {
	if ( NULL == string || NULL == string->data) {
		puts("串不存在！");
		exit(0);
	}

	string->size = 0;
	string->data[0] = '\0';

	return OK;

}

/** @brief 判断串string是否为空串
 * 
 * @pre 串string存在
 * 
 * @param string 要判断的串
 * 
 * @retval TRUE 为空
 * @retval FALSE 不为空
 */
BOOL str_is_empty(String string) {
	if ( NULL == string || NULL == string->data) {
		puts("串不存在！");
		exit(0);
	}

	if (0 == string->size) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/** @brief 得到串string的长度
 * 
 * @pre 串string 存在
 * @param string 要计算长度的串
 * @return 串string的长度
 * @retval -1 操作失败
 */
int str_size(String string) {
	if ( NULL == string || NULL == string->data) {
		puts("串不存在！");
		exit(0);
	}
	return string->size;
}

/** @brief 比较两人个串的大小
 * 
 * @param str1 串１
 * @param str2　串２
 * @retval -1 str1 < str2
 * @retval 0 str2 = str2
 * @retval 1 str1 > str2
 */
int str_compare(String str1, String str2) {

	if ( NULL == str1 || NULL == str1->data) {
		puts("串不存在！");
		exit(0);
	}

	if ( NULL == str2 || NULL == str2->data) {
		puts("串不存在！");
		exit(0);
	}

	int res = strcmp(str1->data, str2->data);
	return res;
}

/** @brief 链接两人个字符串返回新的字符串
 * 
 * @pre 两人个串存在且不为空
 * @param str1 串１
 * @param str2　串２
 * @return 新的串
 * @retval NULL 链接失败！
 */
String str_concat(String str1, String str2) {
	if ( NULL == str1 || NULL == str1->data) {
		puts("串不存在！");
		exit(0);
	}

	if ( NULL == str2 || NULL == str2->data) {
		puts("串不存在！");
		exit(0);
	}

	if (str_is_empty(str1) || str_is_empty(str2)) {
		puts("串为空，无法链接");
		return NULL;
	}

	String str = (String) malloc(sizeof(_str));
	str->size = str1->size + str2->size + 1;
	str->data = (char*) malloc(sizeof(char) * str->size);
	int i = 0;
	while (i < str1->size) {
		str->data[i] = str1->data[i];
		i++;
	}

	int j = 0;
	while (j < str2->size) {
		str->data[i] = str2->data[j];
		i++;
		j++;
	}

	str->data[i] = '\0';

	return str;
}

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
String str_sub(String string, int pos, int len) {
	if ( NULL == string || NULL == string->data) {
		puts("串不存在！");
		exit(0);
	}

	if (pos < 0 || pos >= string->size) {
		printf("起始位置不合法，pos范围是：0-%d\n", string->size - 1);
	}

	if (len <= 0 || len > (string->size - pos)) {
		printf("长度不合法，len范围是：1-%d\n", string->size - pos);
	}

	String str = (String) malloc(sizeof(_str));
	str->data = (char*) malloc(sizeof(char) * len + 1);
	int end = pos + len - 1;
	int i = 0;
	while (pos <= end) {
		str->data[i] = string->data[pos];
		i++;
		pos++;
	}
	str->data[i] = '\0';
	str->size = len;

	return str;
}

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
String str_insert(String string, int pos, String in) {
	if ( NULL == string || NULL == string->data) {
		puts("源串为空！");
		exit(0);
	}

	if ( NULL == in || NULL == in->data) {
		puts("要插入的串为空！");
		exit(0);
	}

	String str = (String) malloc(sizeof(_str));
	str->size = string->size + in->size + 1;
	str->data = (char*) malloc(sizeof(char) * str->size);

	int i = 0;
	int j = 0;
	for (i = 0; i < str->size; i++) {
		if (i < pos) {
			str->data[i] = string->data[j];
			j++;
			continue;
		}

		if (i == pos) {
			int k = 0;
			while (k < in->size) {
				str->data[i] = in->data[k];
				i++;
				k++;
			}
		}

		str->data[i] = string->data[j];
		j++;
	}

	return str;
}

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
String str_delete(String string, int pos, int len) {
	if ( NULL == string || NULL == string->data) {
		puts("串不存在！");
		exit(0);
	}

	if (pos < 0 || pos >= string->size) {
		printf("起始位置不合法，pos范围是：0-%d\n", string->size - 1);
	}

	if (len <= 0 || len > (string->size - pos)) {
		printf("长度不合法，len范围是：1-%d\n", string->size - pos);
	}

	String str = (String) malloc(sizeof(_str));
	str->size = string->size - len;
	str->data = (char*) malloc(sizeof(char) * str->size);

	int i = 0;
	int j = 0;
	for (i = 0; i < str->size; i++) {
		if (j == pos) {
			j = j + len;
		}

		str->data[i] = string->data[j];
		j++;
	}

	return str;
}

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
int str_index(String string, String t, int pos) {
	if ( NULL == string || NULL == t) {
		puts("串不存在！");
		exit(0);
	}

	if ( NULL == t || NULL == t->data) {
		puts("串不存在！");
		exit(0);
	}

	if (pos < 0 || pos > (string->size - t->size)) {
		printf("起始位置不正确，pos范围：0-%d\n", string->size - t->size);
		exit(0);
	}

	int i = pos;
	int end = string->size - t->size;
	BOOL flag = FALSE;

	while (i <= end) {
		if (string->data[i] == t->data[0]) {
			int j = i;
			int k = 0;
			flag = TRUE;
			while (k < t->size) {
				if (string->data[j] != t->data[k]) {
					flag = FALSE;
					break;
				}
				j++;
				k++;
			}

			if (FALSE == flag) {
				i++;
				continue;
			} else {
				return i;
			}
		} else {
			i++;
		}
	}

	return 0;
}

/** @brief 将串string中所有与串t相等的不重叠的子串替换为串v
 * 
 * @pre 串string,t,v存在且不为空
 * 
 * @param string 主串
 * @param t 被替换的子串
 * @param v 替换的串
 * @return　替换后的新串
 */
String str_replace(String string, String t, String v) {

	if ( NULL == string || NULL == string->data) {
		puts("串不存在！");
		exit(0);
	}

	if ( NULL == t || NULL == t->data) {
		puts("串不存在！");
		exit(0);
	}

	if ( NULL == v || NULL == v->data) {
		puts("串不存在！");
		exit(0);
	}

	int i = 0;
	int len = 20;
	String str = (String) malloc(sizeof(_str));
	str->data = (char*) malloc(sizeof(char) * len);
	str->size = 0;
	for (i = 0; i < string->size; i++) {
		if (string->data[i] != t->data[0]) {
			if (str->size >= len) {
				len = (int) ((1 + 0.75) * len);
				str->data = (char*) realloc(str->data, sizeof(char) * len);
			}
			str->data[str->size] = string->data[i];
			str->size++;
		} else {
			int index = str_index(string, t, i);
			if (i != index) {
				if (str->size >= len) {
					len = (int) ((1 + 0.75) * len);
					str->data = (char*) realloc(str->data, sizeof(char) * len);
				}
				str->data[str->size] = string->data[i];
				str->size++;
			}else{
				int k = 0;
				for( k = 0; k < v->size; k++){
					if (str->size >= len) {
						len = (int) ((1 + 0.75) * len);
						str->data = (char*) realloc(str->data, sizeof(char) * len);
					}
					str->data[str->size] = v->data[k];
					str->size++;
				}
				i += t->size - 1;
			}
		}
	}

	str->data[str->size] = '\0';
	return str;
}

