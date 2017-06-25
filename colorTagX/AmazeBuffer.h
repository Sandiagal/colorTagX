#pragma once

#define AmazeBuffer_ChunkSize 4096
#include <vector>

//自动开辟内存的一维数组
class AmazeChunk {
public:
	inline AmazeChunk() { buf = (int*)malloc(sizeof(int)*AmazeBuffer_ChunkSize); }
	inline ~AmazeChunk() {  }

	int& operator[] (int i) { return buf[i]; }

	int *buf;
};

//自动开辟内存的二维数组
class AmazeBuffer
{
public:
	AmazeBuffer();
	~AmazeBuffer();

	std::vector<AmazeChunk> bufs;
	int width;
	int height;

	inline int & operator() (int y, int x) { 
		int offset = y*width + x;//计算容量
		return bufs[offset / AmazeBuffer_ChunkSize][offset % AmazeBuffer_ChunkSize];//返回指定位置内容
	}

	void alloc(int width, int height);
	
	void expand_width_to(int width);
	void expand_height_to(int height);
};

