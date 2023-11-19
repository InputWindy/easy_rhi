#pragma once
#include "openglRHI.h"
namespace rhi
{
	class OpenGLVertexArray final :public RHIVertexArray
	{
	public:
		OpenGLVertexArray() = default;
		virtual ~OpenGLVertexArray();
	public:
		virtual bool isValid() final;
		virtual bool initRHI() final;
		virtual bool releaseRHI() final;

		virtual bool copyFrom(shared_ptr<RHIResource>) final;
		virtual bool updateRHI() final;
	public:
		virtual void bind() const final;

		virtual void unBind() const final;

		virtual void enableAttribute(uint8_t)  const final;

		virtual void disableAttribute(uint8_t) const final;

		virtual void setAttributeFormat(uint32_t, int, uint32_t, bool, uint32_t) const final;

		virtual void setAttributeBinding(uint32_t, uint32_t) const final;

		virtual void setVertexBindingDivisor(uint32_t, uint32_t) const final;

		virtual void bindVertexBuffer(uint32_t, shared_ptr<RHIBuffer>) const final;

		virtual void setAttributePointer(uint32_t, int, uint32_t, bool, int, size_t) const final;
	public:
		GLuint GetHandle()const { return _handle; };
	private:
		GLuint _handle;
	};
}


