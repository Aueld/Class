#include "Framework.h"
#include "VertexBuffer.h"

VertexBuffer::~VertexBuffer()
{
	SAFE_RELEASE(buffer);
}

void VertexBuffer::SetIA()
{
	DC->IAGetVertexBuffers(0, 1, &buffer, &stride, &offset);
}
