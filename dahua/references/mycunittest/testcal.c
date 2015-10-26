#include <stdio.h>
#include <assert.h>
#include <CUnit/Console.h>
#include "cal.h"

int InitSuite()
{
  return 0;
} 

int EndSuite()
{
  return 0;
}

int test_add(int a, int b, int real)
{
  int result;

  result = add(a, b);
  if(result == real)
    {
      return 1;
    }
  return 0;
}

int test_minus(int a, int b, int real)
{
  int result;

  result = minus(a, b);
  if(result == real)
    {
      return 1;
    }
  return 0;
}

void TestAdd()
{
  //	CU_ASSERT(test_add(3, 4, 7));
  int result = add(3, 4);
  int real = 7;
  CU_ASSERT_EQUAL(result,real);
}

void TestMinus()
{
  //	CU_ASSERT(test_minus(4, 5, -1));
  int result = minus(3, 4);
  int real = 1;
  CU_ASSERT_EQUAL(result,real);
}

/*0 表示成功，1表示失败*/
int AddTestCalModule()
{
  CU_pSuite pSuite = NULL;

  /***************
   * 1. CU_add_suite 增加一个Suite 
   * 2. Suite名字 : testSuite
   * 3. InitSuite EndSuite：分别是测试单元初始和释放函数，如不需要则NULL传递
   ****************/
  pSuite = CU_add_suite("cal模块", InitSuite, EndSuite);  

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
  if( NULL == CU_add_test(pSuite, "add(加)", TestAdd) ||
      NULL == CU_add_test(pSuite, "minus(减)", TestMinus))
    {
      return 1;
    }
	
  /***另外一种测试方式***************/
  /*
    CU_TestInfo testcases[] = {
    {"Test1:", Test1},
    {"Test2:", Test2},
    CU_TEST_INFO_NULL
    };

    CU_SuiteInfo suites[] = {
    {"Testing the function cal_num:", InitSuite, EndSuite, testcases},
    CU_SUITE_INFO_NULL
    };

    if(CUE_SUCCESS != CU_register_suites(suites))
    {
    return 1;
    }
  */
  /************************************/

  return 0;
}
