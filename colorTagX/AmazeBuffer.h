#pragma once

#define AmazeBuffer_ChunkSize 4096
#include <vector>

//�Զ������ڴ��һά����
class AmazeChunk {
public:
	inline AmazeChunk() { buf = (int*)malloc(sizeof(int)*AmazeBuffer_ChunkSize); }
	inline ~AmazeChunk() {  }

	int& operator[] (int i) { return buf[i]; }

	int *buf;
};

//�Զ������ڴ�Ķ�ά����
class AmazeBuffer
{
public:
	AmazeBuffer();
	~AmazeBuffer();

	std::vector<AmazeChunk> bufs;
	int width;
	int height;

	inline int & operator() (int y, int x) { 
		int offset = y*width + x;//��������
		return bufs[offset / AmazeBuffer_ChunkSize][offset % AmazeBuffer_ChunkSize];//����ָ��λ������
	}

	void alloc(int width, int height);
	
	void expand_width_to(int width);
	void expand_height_to(int height);
};

