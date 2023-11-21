#include "tqueue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> q(5));
}

TEST(TQueue, throws_when_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(-10));
}

TEST(TQueue, can_copy)
{
	TQueue<int> q(10);

	ASSERT_NO_THROW(TQueue<int> copy(q));
}

TEST(TQueue, can_get_size)
{
	TQueue<int> q(5);

	EXPECT_EQ(5, q.getSize());
}

TEST(TQueue, can_get_start)
{
	TQueue<int> q(5);

	EXPECT_EQ(0, q.getStart());
}

TEST(TQueue, can_get_end)
{
	TQueue<int> q(5);

	EXPECT_EQ(0, q.getEnd());
}

TEST(TQueue, can_push_and_get_count)
{

	TQueue<int> q(5);
	int num = 1;
	q.push(num);

	EXPECT_EQ(1, q.getCount());
}

TEST(TQueue, can_pull_and_get_count)
{
	TQueue<int> q(1);

	int num = 1;
	q.push(num);
	q.pull();

	EXPECT_EQ(0, q.getCount());
}

TEST(TQueue, checks_if_full)
{
	TQueue<int> q(1);

	int num = 1;
	q.push(num);
	EXPECT_EQ(1, q.isFull());
}

TEST(TQueue, checks_if_empty)
{
  TQueue<int> q(1);

	EXPECT_EQ(1, q.isEmpty());
}