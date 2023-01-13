#include "pch.h"
#include "../headers/List.hpp"

TEST(list, can_create_object)
{
	EXPECT_NO_THROW(mtl::List<int> listNode);
}

TEST(list, can_copy_object)
{
	mtl::List<int> listNode;
	listNode.push_back(1);                        
	listNode.push_back(2);
	EXPECT_NO_THROW(mtl::List<int> example(listNode));
}


TEST(list, chek_front)
{
	mtl::List<int> listNode;
	listNode.insert(0, 1);
	listNode.insert(1, 2);
	EXPECT_NO_THROW(listNode.front());
	EXPECT_EQ(1, listNode.front());
}

TEST(list, chek_back)
{
	mtl::List<int> listNode;
	listNode.insert(0, 1);
	listNode.insert(1, 2);
	EXPECT_NO_THROW(listNode.back());
	EXPECT_EQ(2, listNode.back());
}

TEST(list, chek_empty)
{
	mtl::List<int> listNode;
	EXPECT_EQ(true, listNode.empty());
	listNode.insert(0, 1);
	listNode.insert(1, 2);
	EXPECT_EQ(false, listNode.empty());
}

TEST(list, can_check_size)
{
	mtl::List<int> listNode;
	EXPECT_NO_THROW(listNode.size());
	EXPECT_EQ(0, listNode.size());
	listNode.push_back(0);
	EXPECT_EQ(1, listNode.size());
}

TEST(list, can_clear)
{
	mtl::List<int> listNode;
	listNode.insert(0, 1);
	listNode.insert(1, 2);
	EXPECT_NO_THROW(listNode.clear());
	EXPECT_EQ(0, listNode.size());
}

TEST(list, can_insert)
{
	mtl::List<int> listNode;
	EXPECT_NO_THROW(listNode.insert(0, 1));
	EXPECT_NO_THROW(listNode.insert(1, 2));
	EXPECT_NO_THROW(listNode.insert(2, 3));
	EXPECT_NO_THROW(listNode.insert(3, 4));
	//EXPECT_NO_THROW(listNode.insert(2, 5));
	listNode.insert(2, 5);
	EXPECT_EQ(5, listNode.size());
	EXPECT_EQ(listNode.operator[](0), 1);
	EXPECT_EQ(listNode.operator[](1), 2);
	EXPECT_EQ(listNode.operator[](2), 5);
	EXPECT_EQ(listNode.operator[](3), 3);
	EXPECT_EQ(listNode.operator[](4), 4);
}

TEST(list, can_erase)
{
	mtl::List<int> listNode;
	listNode.insert(0, 1);
	listNode.insert(1, 2);
	listNode.insert(2, 3);
	listNode.insert(3, 4);
	EXPECT_EQ(4, listNode.size());
	listNode.erase(1);
	EXPECT_EQ(3, listNode.size());
	EXPECT_EQ(listNode.operator[](0), 1);
	EXPECT_EQ(listNode.operator[](1), 3);
	EXPECT_EQ(listNode.operator[](2), 4);
}

TEST(list, can_push_back)
{
	mtl::List<int> listNode;
	EXPECT_NO_THROW(listNode.push_back(0));
	EXPECT_EQ(listNode.operator[](0), 0);
	EXPECT_EQ(1, listNode.size());
}

TEST(list, can_push_front)
{
	mtl::List<int> listNode;
	EXPECT_NO_THROW(listNode.push_back(0));
	EXPECT_EQ(listNode.operator[](0), 0);
	EXPECT_EQ(1, listNode.size());
}

TEST(list, can_pop_back)
{
	mtl::List<int> listNode;
	listNode.insert(0, 1);
	listNode.insert(1, 2);
	EXPECT_NO_THROW(listNode.pop_back());
	EXPECT_EQ(1, listNode.size());
}

TEST(list, can_pop_front)
{
	mtl::List<int> listNode;
	EXPECT_NO_THROW(listNode.pop_front());
}

TEST(list, can_swap)
{
	mtl::List<int> listNode;
	listNode.insert(0, 1);
	listNode.insert(1, 2);
	mtl::List<int> listExample;                 
	listExample.insert(0, 2);
	listExample.insert(1, 1);
	EXPECT_NO_THROW(listNode.swap(listExample));
}


TEST(list, can_merge)
{
	mtl::List<int> listNode;
	mtl::List<int> listExample;                         
	EXPECT_NO_THROW(listNode.merge(listExample));
}

TEST(list, can_reverse)
{
	mtl::List<int> listNode;
	
	EXPECT_NO_THROW(listNode.reverse());
}

TEST(list, can_unique)
{
	mtl::List<int> listNode;
	EXPECT_NO_THROW(listNode.unique());
}

TEST(list, can_sort)
{
	mtl::List<int> listNode;
	EXPECT_NO_THROW(listNode.sort());                  // —ƒ≈À¿“‹ ƒÀﬂ œ”—“€’!!!
}





