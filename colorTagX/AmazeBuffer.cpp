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

//�����ڴ�
void AmazeBuffer::alloc(int width, int height)
{
	int bufsize = width*height;//Ŀ������
	int chunk_count = 2 + bufsize / AmazeBuffer_ChunkSize;//��������
	if (bufs.size() < chunk_count) bufs.resize(chunk_count);//��Ҫ�����ڴ�

	this->width = width;
	this->height = height;
}

//������
void AmazeBuffer::expand_width_to(int width)
{
	alloc(width, height);
}

//����߶�
void AmazeBuffer::expand_height_to(int height)
{
	alloc(width, height);
}
