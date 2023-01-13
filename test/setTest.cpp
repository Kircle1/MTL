#include "pch.h"
#include "../headers/Set.hpp"

TEST(set, can_create_object)
{
	EXPECT_NO_THROW(mtl::Set<int> example);
}
TEST(set, can_insert)
{
	mtl::Set<int> example;
	EXPECT_NO_THROW(example.insert(5));
	EXPECT_EQ(example.root->key, 5);
}
TEST(set, can_setInvec)
{
	mtl::Set<int> example;
	example.insert(3);
	example.insert(5);
	example.insert(7);
	example.insert(2);
	EXPECT_NO_THROW(example.rootInvec(example));
	EXPECT_EQ(example.rootInvec(example)[0], 2);
	EXPECT_EQ(example.rootInvec(example)[1], 3);
	EXPECT_EQ(example.rootInvec(example)[2], 5);
	EXPECT_EQ(example.rootInvec(example)[3], 7);

}
TEST(set, chek_empty)
{
	mtl::Set<int> example;
	EXPECT_EQ(example.empty(), true);
}
TEST(set, chek_size)
{
	mtl::Set<int> example;
	example.insert(3);
	example.insert(5);
	example.insert(7);
	example.insert(2);
	EXPECT_EQ(example.size(), 4);
}
TEST(set, chek_clear)
{
	mtl::Set<int> example;
	example.insert(3);
	example.insert(5);
	example.insert(7);
	example.insert(2);
	EXPECT_NO_THROW(example.clear());
	EXPECT_EQ(example.empty(), true);
}
TEST(set, chek_erase)
{
	mtl::Set<int> example;
	example.insert(3);
	example.insert(5);
	example.insert(7);
	example.insert(2);
	EXPECT_NO_THROW(example.erase(5));
	EXPECT_EQ(example.rootInvec(example)[0], 2);
	EXPECT_EQ(example.rootInvec(example)[1], 3);
	EXPECT_EQ(example.rootInvec(example)[2], 7);
}	
//TEST(set, chek_swap)
//{
//	mtl::Set<int> example;
//	example.insert(3);
//	example.insert(5);
//	example.insert(7);
//	example.insert(2);
//	mtl::Set<int> example2;
//	example2.insert(4);
//	example2.insert(6);
//	example2.insert(1);
//	example2.insert(9);
//	mtl::Set<int> buffex = example;
//	mtl::Set<int> buffex2 = example2;
//	EXPECT_NO_THROW(example.swap(example2));
//	//EXPECT_EQ(buffex, example2);
//	//EXPECT_EQ(buffex2, example);
//
//}
TEST(set, chek_find)
{
	mtl::Set<int> example;
	example.insert(3);
	example.insert(5);
	example.insert(7);
	example.insert(2);
	EXPECT_EQ(example.find(3), true);
	EXPECT_EQ(example.find(5), true);
	EXPECT_EQ(example.find(7), true);
	EXPECT_EQ(example.find(2), true);
}
TEST(set, chek_merge)
{
	mtl::Set<int> example;
	example.insert(3);
	example.insert(5);
	example.insert(7);
	example.insert(2);
	mtl::Set<int> example2;
	example2.insert(4);
	example2.insert(6);
	example2.insert(1);
	example2.insert(9);
	EXPECT_NO_THROW(example.merge(example2));
	EXPECT_EQ(example.find(4), true);
	EXPECT_EQ(example.find(6), true);
	EXPECT_EQ(example.find(1), true);
	EXPECT_EQ(example.find(9), true);
}