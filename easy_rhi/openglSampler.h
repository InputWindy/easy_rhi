#pragma once
#include "openglRHI.h"
namespace rhi
{
	class OpenGLSampler final :public RHISampler
	{
	public:
		OpenGLSampler() = default;
		virtual ~OpenGLSampler();
	public:
		virtual bool isValid() final;
		virtual bool initRHI() final;
		virtual bool releaseRHI() final;

		virtual bool copyFrom(shared_ptr<RHIResource>) final;
		virtual bool updateRHI() final;
	public:
		GLuint GetHandle()const { return _handle; };
	private:
		GLuint _handle = 0;

		bool _isUpdated = false;
	};
}

