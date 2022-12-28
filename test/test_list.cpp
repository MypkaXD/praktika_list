#include <gtest.h>
#include "Forward_List.h"

TEST(List, can_create_list) {
	ASSERT_NO_THROW(List<int> l1);
}

TEST(List, throw_when_create_list_with_negative_size) {
	ASSERT_ANY_THROW(List<int> l1(-10));
}

TEST(List, can_create_list_with_positive_size) {
	ASSERT_NO_THROW(List<int> l1(10));
}

TEST(List, can_create_list_with_positive_size_and_elem) {
	ASSERT_NO_THROW(List<int> l1(10,2));
}

TEST(List, create_list_with_size_and_elem_is_correct) {
	List<int> l1(10,2);
	List<int> l2;
	
	for (size_t count = 0; count < 10; ++count)
		l2.push_front(2);

	ASSERT_EQ(l2, l1);
}

TEST(List, can_create_list_with_initializer_list) {
	List<int> l1({2,2,2});
	List<int> l2;

	for (size_t count = 0; count < 3; ++count) {
		l2.push_front(2);
	}

	ASSERT_EQ(l2,l1);
}

TEST(List, can_create_list_with_move) {
	List<int> l1;

	ASSERT_NO_THROW(List<int>l2=std::move(l1));
}

TEST(List, move_semantics_list_is_equal_to_source_one)
{
	List<int>l1({12,23,31});
	List<int>l2(l1);
	List<int>l3 = std::move(l1);

	EXPECT_EQ(l2, l3);
}

TEST(List, can_compare_list_with_the_same_lenght)
{
	List<int>l1({ 12,23,31 });
	List<int>l2({ 12,23,31 });

	EXPECT_EQ(true, (l2==l1));
}

TEST(List, can_compare_list_with_the_same_lenght_but_different_elemets)
{
	List<int>l1({ 12,23,31 });
	List<int>l2({ 10, 23, 13 });

	EXPECT_EQ(false, (l2 == l1));
}

TEST(List, can_compare_list_with_the_different_lenght)
{
	List<int>l1({ 12,23,31 });
	List<int>l2({ 12,23,31,13,14 });

	EXPECT_EQ(false, (l2 == l1));
}

TEST(List, can_get_size)
{
	List<int>l1({ 12,23,31 });

	EXPECT_EQ(3, l1.size());
}

TEST(List, can_get_size_from_empty_list)
{
	List<int>l1;

	EXPECT_EQ(0, l1.size());
}

TEST(List, can_flip_list)
{
	List<int>l1({1,2,3});
	List<int>l2({ 3,2,1 });

	l1.flip();

	EXPECT_EQ(l2,l1);
}

TEST(List, can_merge_list)
{
	List<int>l1({ 1,2,3 });
	List<int>l2({ 3,2,1 });

	l1.merge(l2);

	List<int>l3({ 1,2,3,3,2,1 });

	EXPECT_EQ(l1, l3);
}

TEST(List, can_pop_front_elem_from_list)
{
	List<int>l1({ 1,2,3 });
	List<int>l2({ 2,3 });

	l1.pop_front();

	EXPECT_EQ(l1, l2);
}

TEST(List, cant_pop_front_elem_from_list_if_list_is_empty)
{
	List<int>l1;

	ASSERT_ANY_THROW(l1.pop_front());
}

TEST(List, can_push_front_elem_in_list)
{
	List<int>l1({ 1,2,3 });
	List<int>l2({ 2,3 });

	l2.push_front(1);

	EXPECT_EQ(l1, l2);
}

TEST(List, can_push_front_elem_in_list_if_list_is_empty)
{
	List<int>l1;
	List<int> l2({ 1 });

	ASSERT_NO_THROW(l1.push_front(1));
	EXPECT_EQ(l1, l2);
}

TEST(List, can_assign_elements_from_list)
{
	List<int>l1({ 1,2,3,4,5,6 });
	List<int> l2;

	l2.assign(l1.begin() + 1, l1.begin() + 4);

	List<int> l3({2,3,4});

	EXPECT_EQ(l2, l3);
}

TEST(List, can_clear_list)
{
	List<int>l1({ 1,2,3,4,5,6 });

	l1.clear();

	EXPECT_EQ(0, l1.size());
}

TEST(List, cant_clear_empty_list)
{
	List<int>l1;

	ASSERT_ANY_THROW(l1.clear());
}

TEST(List, can_insert_elem_in_list_after)
{
	List<int>l1({ 1,2,3,4,5,6 });

	l1.insert_after(l1.begin() + 3, 100);

	List<int>l2({ 1,2,3,4,100,5,6 });

	EXPECT_EQ(l1,l2);
}

TEST(List, can_ierase_elem_from_list)
{
	List<int>l1({ 1,2,3,4,5,6 });

	l1.erase_after(l1.begin() + 3);

	List<int>l2({ 1,2,3,4,6 });

	EXPECT_EQ(l1, l2);
}