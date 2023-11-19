#pragma once
#include <glad.h>

#include "rhi.h"

namespace rhi
{
	GLenum shaderTypeInternal(RHIShaderType);
	GLenum dataTypeInternal(RHIDataType);
	GLenum shaderResourceTypeInternal(RHIShaderResourceType);
	GLenum rhiWrapModeInternal(RHIWrapMode);
	GLenum filterModeInternal(RHIFilterMode);
	GLenum compareModeInternal(RHICompareMode);
	GLenum compareFuncInternal(RHICompareFunc);

	RHIShaderType shaderTypeRevInternal(GLenum);
	RHIDataType dataTypeRevInternal(GLenum);
	RHIShaderResourceType shaderResourceTypeRevInternal(GLenum);
	RHIWrapMode rhiWrapModeRevInternal(GLenum);
	RHIFilterMode filterModeRevInternal(GLenum);
	RHICompareMode compareModeRevInternal(GLenum);
	RHICompareFunc compareFuncRevInternal(GLenum);
}

