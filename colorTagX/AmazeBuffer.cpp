#include "AmazeBuffer.h"
#include <stdlib.h>

AmazeBuffer::AmazeBuffer()
	: bufs()
	, width(0)
	, height(0)
{
	alloc(1, 1);
}

AmazeBuffer::~AmazeBuffer()
{
}

//申请内存
void AmazeBuffer::alloc(int width, int height)
{
	int bufsize = width*height;//目标容量
	int chunk_count = 2 + bufsize / AmazeBuffer_ChunkSize;//计算行数
	if (bufs.size() < chunk_count) bufs.resize(chunk_count);//需要申请内存

	this->width = width;
	this->height = height;
}

//扩充宽度
void AmazeBuffer::expand_width_to(int width)
{
	alloc(width, height);
}

//扩充高度
void AmazeBuffer::expand_height_to(int height)
{
	alloc(width, height);
}
