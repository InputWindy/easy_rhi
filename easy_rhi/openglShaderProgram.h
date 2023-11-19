#pragma once
#include "openglRHI.h"
namespace rhi
{
	class OpenGLShaderProgram final :public RHIShaderProgram
	{
	public:
		OpenGLShaderProgram() = default;
		virtual ~OpenGLShaderProgram();
	public:
		virtual bool isValid() final;
		virtual bool initRHI() final;
		virtual bool releaseRHI() final;

		virtual bool copyFrom(shared_ptr<RHIResource>) final;
		virtual bool updateRHI() final;
	public:
		virtual void updateShaderParameters() final;

		virtual bool link() const final;

		virtual bool isLinked() const final;

		virtual void use()  const final;

		virtual void attachShader(shared_ptr<class RHIShader>) const final;

		virtual void getShaderProgramInfoLog(string&) const final;

		virtual void setSubroutine(const char*, uint32_t, uint32_t)const final;

		virtual void setShaderBuffer(const char*, shared_ptr<class RHIShaderBuffer>) const final;

		virtual void setTexture(const char*, shared_ptr<class RHITexture>) const final;

		virtual void setTextureImage(const char*, shared_ptr<class RHITextureImage>) const final;

		virtual void setBool1(const char*, bool) const final;
		virtual void setBool2(const char*, bool, bool) const final;
		virtual void setBool3(const char*, bool, bool, bool) const final;
		virtual void setBool4(const char*, bool, bool, bool, bool) const final;

		virtual void setFloat1(const char*, float) const final;
		virtual void setFloat2(const char*, float, float) const final;
		virtual void setFloat3(const char*, float, float, float) const final;
		virtual void setFloat4(const char*, float, float, float, float) const final;

		virtual void setInt1(const char*, int) const final;
		virtual void setInt2(const char*, int, int) const final;
		virtual void setInt3(const char*, int, int, int) const final;
		virtual void setInt4(const char*, int, int, int, int) const final;

		virtual void setUInt1(const char*, uint32_t) const final;
		virtual void setUInt2(const char*, uint32_t, uint32_t) const final;
		virtual void setUInt3(const char*, uint32_t, uint32_t, uint32_t) const final;
		virtual void setUInt4(const char*, uint32_t, uint32_t, uint32_t, uint32_t) const final;

		virtual void setFloat1Array(const char*, size_t, float*) const final;
		virtual void setFloat2Array(const char*, size_t, float*) const final;
		virtual void setFloat3Array(const char*, size_t, float*) const final;
		virtual void setFloat4Array(const char*, size_t, float*) const final;

		virtual void setInt1Array(const char*, size_t, int*) const final;
		virtual void setInt2Array(const char*, size_t, int*) const final;
		virtual void setInt3Array(const char*, size_t, int*) const final;
		virtual void setInt4Array(const char*, size_t, int*) const final;

		virtual void setUInt1Array(const char*, size_t, uint32_t*) const final;
		virtual void setUInt2Array(const char*, size_t, uint32_t*) const final;
		virtual void setUInt3Array(const char*, size_t, uint32_t*) const final;
		virtual void setUInt4Array(const char*, size_t, uint32_t*) const final;

		virtual void setMatrixFloat2x2Array(const char*, size_t, bool, float*) const final;
		virtual void setMatrixFloat3x3Array(const char*, size_t, bool, float*) const final;
		virtual void setMatrixFloat4x4Array(const char*, size_t, bool, float*) const final;
		virtual void setMatrixFloat2x3Array(const char*, size_t, bool, float*) const final;
		virtual void setMatrixFloat3x2Array(const char*, size_t, bool, float*) const final;
		virtual void setMatrixFloat2x4Array(const char*, size_t, bool, float*) const final;
		virtual void setMatrixFloat4x2Array(const char*, size_t, bool, float*) const final;
		virtual void setMatrixFloat3x4Array(const char*, size_t, bool, float*) const final;
		virtual void setMatrixFloat4x3Array(const char*, size_t, bool, float*) const final;
	public:
		GLuint GetHandle()const { return _handle; };
	private:
		GLuint _handle;
	};

}

