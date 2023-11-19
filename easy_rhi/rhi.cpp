#include "rhi.h"

using namespace rhi;

uint32_t rhi::RHIVertexArray::getResourceType()const
{
	return RHIResourceType_VertexArray;
}

string rhi::RHIVertexArray::getResourceTypeName()const
{
	return "VertexArray";
}


uint32_t rhi::RHIShader::getResourceType()const
{
	return RHIResourceType_Shader;
}

string rhi::RHIShader::getResourceTypeName()const
{
	return "Shader";
}

uint32_t rhi::RHIShader::getShaderType()const
{
	return _shaderType;
};

uint32_t rhi::RHIShaderProgram::getResourceType()const
{
	return RHIResourceType_ShaderProgram;
}

string rhi::RHIShaderProgram::getResourceTypeName()const
{
	return "ShaderProgram";
}

const rhi::RHIShaderProgram::ShaderParameter& rhi::RHIShaderProgram::getActiveShaderParameters() const
{
	return _shaderParameter;
}

RHIResourceType rhi::RHISampler::getResourceType() const
{
	return RHIResourceType_Sampler;
}

string rhi::RHISampler::getResourceTypeName() const
{
	return "Sampler";
}

RHIWrapMode rhi::RHISampler::getWrapR() const
{
	return _wrapR;
}

RHIWrapMode rhi::RHISampler::getWrapS() const
{
	return _wrapS;
}

RHIWrapMode rhi::RHISampler::getWrapT() const
{
	return _wrapT;
}

RHIFilterMode rhi::RHISampler::getMinFilterMode() const
{
	return _minFilterMode;
}

RHIFilterMode rhi::RHISampler::getMagFilterMode() const
{
	return _magFilterMode;
}

uint8_t rhi::RHISampler::getMinMipLevel() const
{
	return _minMipLevel;
}

uint8_t rhi::RHISampler::getMaxMipLevel() const
{
	return _maxMipLevel;
}

float rhi::RHISampler::getLODBias() const
{
	return _lodBias;
}

const vector<float>& rhi::RHISampler::getBorderColor() const
{
	return _borderColor;
}

RHICompareMode rhi::RHISampler::setCompareMode() const
{
	return _compareMode;
}

RHICompareFunc rhi::RHISampler::setCompareFunc() const
{
	return _compareFunc;
}

void rhi::RHISampler::setWrapR(RHIWrapMode mode)
{
	_wrapR = mode;
}

void rhi::RHISampler::setWrapS(RHIWrapMode mode)
{
	_wrapS = mode;
}

void rhi::RHISampler::setWrapT(RHIWrapMode mode)
{
	_wrapT = mode;
}

void rhi::RHISampler::setMinFilterMode(RHIFilterMode mode)
{
	_minFilterMode = mode;
}

void rhi::RHISampler::setMagFilterMode(RHIFilterMode mode)
{
	_magFilterMode = mode;
}

void rhi::RHISampler::setMinMipLevel(uint8_t i)
{
	_minMipLevel = i;
}

void rhi::RHISampler::setMaxMipLevel(uint8_t i)
{
	_maxMipLevel = i;
}

void rhi::RHISampler::setLODBias(float f)
{
	_lodBias = f;
}

void rhi::RHISampler::setBorderColor(float r, float g, float b, float a)
{
	_borderColor[0] = r;
	_borderColor[1] = g;
	_borderColor[2] = b;
	_borderColor[3] = a;
}

void rhi::RHISampler::setCompareMode(RHICompareMode mode)
{
	_compareMode = mode;
}

void rhi::RHISampler::setCompareFunc(RHICompareFunc func)
{
	_compareFunc = func;
}
