#include<stdio.h>
#include<stdlib.h>
#include"../../include/cal/cal.h"
#include"../../include/list/ArrayList.h"
#include"../../include/list/SingleList.h"
#include"../../include/str/str.h"

int main(void) {
//	int a = 0;
//	int b = 0;
//	printf("输入两人个整数：");
//	scanf("%d %d", &a, &b);
//	printf("%d + %d = %d\n", a, b, add(a, b));
//
//	arrayListPtr array = array_list_init();
//
//	if ( NULL == array) {
//		puts("未分配空间！");
//		exit(0);
//	}
//	if (array_list_is_empty(array)) {
//		puts("为空");
//	} else {
//		puts("失败！");
//	}
//
//	array_list_append(array, 1);
//	array_list_append(array, 2);
//	array_list_append(array, 3);
//	array_list_append(array, 4);
//	array_list_append(array, 5);
//	array_list_append(array, 6);
//
//	int len = array_list_size(array);
//	printf("长度：%d\n", len);
//
//	int i = 0;
//	for (i = 0; i < len; i++) {
//		printf("%d ", array->data[i]);
//	}
//	putchar('\n');
//
//	array_list_insert(array, 6, 9);
//	len = array_list_size(array);
//	for (i = 0; i < len; i++) {
//		printf("%d ", array->data[i]);
//	}
//	putchar('\n');
//
//	int val = 0;
//	ElemType * e = &val;
//
//	array_list_get_elem(array, 0, e);
//	printf("val = %d\n", val);
//	array_list_get_elem(array, 6, e);
//	printf("val = %d\n", val);
//
//	int index = array_list_index(array, 9);
//	printf("index = %d\n", index);
//	array_list_delete(array, 2, e);
//	printf("val = %d\n", val);
//	len = array_list_size(array);
//	for (i = 0; i < len; i++) {
//		printf("%d ", array->data[i]);
//	}
//	putchar('\n');

//	signleListPtr list = signle_list_init();
//	if ( NULL == list) {
//		puts("失败！");
//		exit(0);
//	}
//	if (signle_list_is_empty(list)) {
//		puts("为空！");
//	}
//
//	int len = signle_list_size(list);
//	printf("len = %d\n", len);
//
//	signle_list_append(list, 1);
//	signle_list_append(list, 2);
//	signle_list_append(list, 3);
//	signle_list_append(list, 4);
//	signle_list_append(list, 5);
//
//	_node * node = list->next;
//
//	while ( NULL != node) {
//		printf("%d ", node->data);
//		node = node->next;
//	}
//
//	putchar('\n');
//	len = signle_list_size(list);
//	printf("len = %d\n", len);
//
//	int val = 0;
//	ElemType * e = &val;
//	signle_list_get_elem(list, 2, e);
//	printf("val = %d\n", val);
//
//	signle_list_insert(list, 3, 9);
//
//	node = list->next;
//	while ( NULL != node) {
//		printf("%d ", node->data);
//		node = node->next;
//	}
//
//	putchar('\n');
//
//	int index = signle_list_index(list, 5);
//	printf("index = %d\n", index);
//
//	signle_list_delete(list, 5, e);
//	printf("val = %d\n", val);
//
//	node = list->next;
//	while ( NULL != node) {
//		printf("%d ", node->data);
//		node = node->next;
//	}
//
//	putchar('\n');
//
//	signle_list_clear(list);
//	if (signle_list_is_empty(list)) {
//		puts("清除成功！");
//
//	}
	
	
	String string = str_assign("hello world");
	printf("**%s**\n",string->data);
	
	String str = str_copy(string);
	printf("**%s**\n",str->data);
	int size = str_size(str);
	printf("size = %d\n",size);
	
	str_clear(str);
	printf("**%s**\n",str->data);
	size = str_size(str);
	printf("size = %d\n",size);
	if(str_is_empty(str)){
		puts("为空");
	}
	
	String str2 = str_assign("This is a C program!");
	int compare = str_compare(string,str2);
	if( compare < 0 ){
		printf("%s < %s\n",string->data,str2->data);
	}else if( compare > 0 ){
		printf("%s > %s\n",string->data,str2->data);
	}else{
		printf("%s = %s\n",string->data,str2->data);
	}
	
	String str3 = str_concat(string,str2);
	printf("**%s**\n",str3->data);
	
	String str4 = str_sub(string,6,5);
	printf("**%s**\n",string->data);
	printf("**%s**\n",str4->data);
	
	String str5 = str_insert(string,11,str4);
	printf("**%s**\n",str5->data);

	
	String str6 = str_delete(string,5,6);
	printf("**%s**\n",str6->data);
	
	String str7 = str_assign("is");
	printf("**%s**\n",str7->data);
	int index = str_index(str2,str7,3);
	printf("index = %d\n",index);

	
	String str8 = str_assign("am");
	String str9 = str_replace(str2,str7,str8);
	printf("**%s**\n",str9->data);
	
	
	
	return 0;
}
