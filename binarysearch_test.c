#include "unity.h"
#include "binarysearch.h"

/*
 * Use Unity for unit tests of binary search algorithm
 */

void test_search_should_return_neg_when_empty_array(void)
{
	int test[] = {};
	TEST_ASSERT_EQUAL_INT(-1, binary_search(test, 0, 0, 3));
}

void test_search_should_return_neg_when_key_not_found_greater(void)
{
	int test[4] = {1, 2, 3, 4};
	TEST_ASSERT_EQUAL_INT(-1, binary_search(test, 0, 3, 7));
}

void test_search_should_return_neg_when_key_not_found_less(void)
{
	int test[4] = {8, 9, 10, 11};
	TEST_ASSERT_EQUAL_INT(-1, binary_search(test, 0, 3, 7));
}

void test_search_should_return_neg_when_key_not_found_in_middle(void)
{
	int test[5] = {1, 5, 8, 12, 13};
	TEST_ASSERT_EQUAL_INT(-1, binary_search(test, 0, 4, 11));
}

void test_search_should_return_neg_when_key_not_found_unsorted(void)
{
	int test[4] = {8, 10, 9, 11};
	TEST_ASSERT_EQUAL_INT(-1, binary_search(test, 0, 3, 7));
}

void test_search_should_find_index(void)
{
	int test[4] = {1, 2, 3, 4};
	TEST_ASSERT_EQUAL_INT(2, binary_search(test, 0, 3, 3));
}

void test_search_should_find_index_larger_array(void)
{
	int test[11] = {3, 5, 8, 10, 12, 15, 18, 20, 20, 50, 60};
	TEST_ASSERT_EQUAL_INT(9, binary_search(test, 0, 10, 50));
}

void test_search_should_find_index_largest_array(void)
{
	int test[1000];
	for (int i = 0; i < 1000; i++) {
		test[i] = i;
	}
	TEST_ASSERT_EQUAL_INT(149, binary_search(test, 0, 1000, 150));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_search_should_return_neg_when_empty_array);
	RUN_TEST(test_search_should_return_neg_when_key_not_found_less);
	RUN_TEST(test_search_should_return_neg_when_key_not_found_greater);
	RUN_TEST(test_search_should_return_neg_when_key_not_found_in_middle);
	RUN_TEST(test_search_should_return_neg_when_key_not_found_unsorted);
	RUN_TEST(test_search_should_find_index);
	RUN_TEST(test_search_should_find_index_larger_array);
	return UNITY_END();
}
