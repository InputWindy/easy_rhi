#include "openglSampler.h"

rhi::OpenGLSampler::~OpenGLSampler()
{
	releaseRHI();
}

bool rhi::OpenGLSampler::isValid()
{
	return glIsSampler(_handle) == GL_TRUE && _isUpdated;
}

bool rhi::OpenGLSampler::initRHI()
{
	glGenSamplers(1, &_handle);
	return glIsSampler(_handle) == GL_TRUE;
}

bool rhi::OpenGLSampler::releaseRHI()
{
	glDeleteSamplers(1, &_handle);
	_isUpdated = false;
	return !isValid();
}

bool rhi::OpenGLSampler::copyFrom(shared_ptr<RHIResource> sampler)
{
	shared_ptr<OpenGLSampler> openglSampler = std::dynamic_pointer_cast<OpenGLSampler>(sampler);
	if (openglSampler && openglSampler->isValid())
	{
		if (releaseRHI() && initRHI())
		{
			_wrapR = openglSampler->_wrapR;
			_wrapS = openglSampler->_wrapS;
			_wrapT = openglSampler->_wrapT;

			_minFilterMode = openglSampler->_minFilterMode;
			_magFilterMode = openglSampler->_magFilterMode;

			_minMipLevel = openglSampler->_minMipLevel;
			_maxMipLevel = openglSampler->_maxMipLevel;
			_lodBias = openglSampler->_lodBias;

			_borderColor = openglSampler->_borderColor;

			_compareMode = openglSampler->_compareMode;
			_compareFunc = openglSampler->_compareFunc;

			updateRHI();
			return isValid();
		}
	}
	return false;
}

bool rhi::OpenGLSampler::updateRHI()
{
	_isUpdated = true;

	glSamplerParameteri(_handle, GL_TEXTURE_COMPARE_MODE, compareModeInternal(_compareMode));
	glSamplerParameteri(_handle, GL_TEXTURE_COMPARE_FUNC, compareFuncInternal(_compareFunc));
	glSamplerParameteri(_handle, GL_TEXTURE_MIN_LOD, _minMipLevel);
	glSamplerParameteri(_handle, GL_TEXTURE_MAX_LOD, _maxMipLevel);
	glSamplerParameteri(_handle, GL_TEXTURE_LOD_BIAS, _lodBias);
	glSamplerParameteri(_handle, GL_TEXTURE_MIN_FILTER, filterModeInternal(_minFilterMode));
	glSamplerParameteri(_handle, GL_TEXTURE_MAG_FILTER, filterModeInternal(_magFilterMode));
	glSamplerParameteri(_handle, GL_TEXTURE_WRAP_R, rhiWrapModeInternal(_wrapR));
	glSamplerParameteri(_handle, GL_TEXTURE_WRAP_S, rhiWrapModeInternal(_wrapS));
	glSamplerParameteri(_handle, GL_TEXTURE_WRAP_T, rhiWrapModeInternal(_wrapT));


	glSamplerParameterfv(_handle, GL_TEXTURE_BORDER_COLOR,_borderColor.data());
	return isValid();
}
