#pragma once
#include "openglRHI.h"
namespace rhi
{
	class OpenGLShader final :public RHIShader
	{
	public:
		OpenGLShader() = default;
		virtual ~OpenGLShader();
	public:
		virtual bool isValid() final;
		virtual bool initRHI() final;
		virtual bool releaseRHI() final;

		virtual bool copyFrom(shared_ptr<RHIResource>) final;
		virtual bool updateRHI() final;
	public:
		virtual void setShaderSourceCode(const string&) final;

		virtual void getShaderSourceCode(string&) final;

		virtual void getShaderInfoLog(string&) final;

		virtual bool compile()const final;

		virtual bool isCompiled()const final;
	public:
		GLuint GetHandle()const { return _handle; };
	private:
		GLuint _handle;
	};

};


