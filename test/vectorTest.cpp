#include "pch.h"
#include "../headers/Vector.hpp"

TEST(vector, can_create_object)
{
	EXPECT_NO_THROW(mtl::Vector<int> v);
}

TEST(vector, can_push_back)
{
	mtl::Vector<int> v;
	EXPECT_NO_THROW(v.push_back(0));
}

TEST(vector, can_check_size)
{
	mtl::Vector<int> v;
	EXPECT_NO_THROW(v.size());
	EXPECT_EQ(0, v.size());
	v.push_back(0);
	EXPECT_EQ(1, v.size());
	
}

TEST(vector, create_capacity)
{
	mtl::Vector<int> v;
	EXPECT_NO_THROW(v.capacity());
}

TEST(vector, check_remove)
{
	mtl::Vector<int> v;
	v.push_back(1);
	EXPECT_NO_THROW(v.remove(0));
	
}

TEST(vector, check_begin)
{
	mtl::Vector<int> v;
	EXPECT_NO_THROW(v.begin());
}

TEST(vector, check_end)
{
	mtl::Vector<int> v;
	EXPECT_NO_THROW(v.end());
}
