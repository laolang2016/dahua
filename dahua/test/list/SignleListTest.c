/*
 * SignleListTest.c
 *
 *  Created on: 2015年10月24日
 *      Author: laolang
 */

#include <stdio.h>
#include <assert.h>
#include <CUnit/Console.h>

#include"../../include/list/SingleList.h"
#include"../../include/global/global.h"

int InitSuite()
{
  return 0;
} 

int EndSuite()
{
  return 0;
}

void test_signle_list_init(){
	signleListPtr list = signle_list_init();
	CU_ASSERT_NOT_EQUAL(list,NULL);
}

int AddTestListModule()
{
  CU_pSuite pSuite = NULL;

  /***************
   * 1. CU_add_suite 增加一个Suite 
   * 2. Suite名字 : testSuite
   * 3. InitSuite EndSuite：分别是测试单元初始和释放函数，如不需要则NULL传递
   ****************/
  pSuite = CU_add_suite("list模块", InitSuite, EndSuite);  

  //检测注册Suite情况
  if(NULL == pSuite)
    {
      //return 1;
    }
	
  /***************
   * 1. 注册当前Suite下的测试用例　
   * 2. pSuite：用例指针
   * 3. "Test1"： 测试单元名称 
   * 4. Test1：测试函数
   ***************/
  if( NULL == CU_add_test(pSuite, "signle_list_init\t链表初始化", test_signle_list_init))
    {
      return 1;
    }
	

  return 0;
}



int main()
{
   
	//CU_initialize_registry 注册函数注册一个用例返回CUE_系列异常值
	if( CUE_SUCCESS != CU_initialize_registry())
	{
		return CU_get_error();
	}

	//CU_get_registry 返回注册到用例指针 
	assert(NULL != CU_get_registry());
	
	//检测是否在执行 
	assert(!CU_is_test_running()); 

	//调用测试模块完成测试用例
	if (0 != AddTestListModule())
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	//使用console控制交互界面的函数入口 
	CU_console_run_tests();

	/***使用自动产生XML文件的模式********
	CU_set_output_filename("TestMax");
    CU_list_tests_to_file();
	CU_automated_run_tests();
	***********************************/
	
	//调用完毕清除注册信息 
	CU_cleanup_registry();
	
	return 0;
}
