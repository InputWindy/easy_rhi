#include "openglVertexArray.h"
rhi::OpenGLVertexArray::~OpenGLVertexArray()
{
	releaseRHI();
}
bool rhi::OpenGLVertexArray::isValid()
{
	return glIsVertexArray(_handle) == GL_TRUE;
}
bool rhi::OpenGLVertexArray::initRHI()
{
	glGenVertexArrays(1, &_handle);
	return isValid();
}
bool rhi::OpenGLVertexArray::releaseRHI()
{
	glDeleteVertexArrays(1, &_handle);
	return !isValid();
}
bool rhi::OpenGLVertexArray::updateRHI()
{
	return true;
}
//bool rhi::OpenGLVertexArray::copyFrom(shared_ptr<RHIResource> rhs)
//{
//	shared_ptr<OpenGLVertexArray> vao = std::dynamic_pointer_cast<OpenGLVertexArray>(rhs);
//
//	if (vao && vao->isValid())
//	{
//
//	}
//
//	return false;
//}
void rhi::OpenGLVertexArray::bind() const
{
	glBindVertexArray(_handle);
}

void rhi::OpenGLVertexArray::unBind() const
{
	glBindVertexArray(0);
}

void rhi::OpenGLVertexArray::enableAttribute(uint8_t idx) const
{
	glEnableVertexArrayAttrib(_handle, idx);
}

void rhi::OpenGLVertexArray::disableAttribute(uint8_t idx) const
{
	glDisableVertexArrayAttrib(_handle, idx);
}

void rhi::OpenGLVertexArray::setAttributeFormat(uint32_t attribindex, int size, uint32_t type, bool normalized, uint32_t relativeoffset) const
{
	glVertexArrayAttribFormat(_handle, attribindex, size, type, normalized, relativeoffset);
}

void rhi::OpenGLVertexArray::setAttributeBinding(uint32_t attribindex, uint32_t bindingindex) const
{
	glVertexArrayAttribBinding(_handle, attribindex, bindingindex);
}

void rhi::OpenGLVertexArray::setVertexBindingDivisor(uint32_t bindingindex, uint32_t divisor) const
{
	glVertexArrayBindingDivisor(_handle, bindingindex, divisor);
}

void rhi::OpenGLVertexArray::setAttributePointer(uint32_t index, int size, uint32_t type, bool normalized, int stride , size_t pointer) const
{
	glBindVertexArray(_handle);
	glVertexAttribPointer(index,size,type,normalized,stride,(const void*)pointer);
	glBindVertexArray(0);
}
