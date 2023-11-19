#include "openglRHI.h"

using namespace rhi;
GLenum shaderTypeInternal(RHIShaderType type)
{
	switch (type)
	{
	case RHIShaderType_None:
	case RHIShaderType_Vertex:return GL_VERTEX_SHADER;
	case RHIShaderType_TessellationControl:return GL_TESS_CONTROL_SHADER;
	case RHIShaderType_Tessellation_Evaluation:return GL_TESS_EVALUATION_SHADER;
	case RHIShaderType_Geometry:return GL_GEOMETRY_SHADER;
	case RHIShaderType_Fragment:return GL_FRAGMENT_SHADER;
	case RHIShaderType_Compute:return GL_COMPUTE_SHADER;
	case RHIShaderType_Max:
	default:
		break;
	}
};

GLenum dataTypeInternal(RHIDataType type)
{
	switch (type)
	{
		case RHIDataType_None:
		case RHIDataType_Byte:return GL_BYTE;
		case RHIDataType_Unsigned_Byte:return  GL_UNSIGNED_BYTE;
		case RHIDataType_Short:return GL_SHORT;
		case RHIDataType_Unsigned_Short:return GL_UNSIGNED_SHORT;
		case RHIDataType_Int:return GL_INT;
		case RHIDataType_Unsigned_Int:return GL_UNSIGNED_INT;
		case RHIDataType_Half_Float:return GL_HALF_FLOAT;
		case RHIDataType_Float:return GL_FLOAT;
		case RHIDataType_Double:return GL_DOUBLE;
		case RHIDataType_Fixed:return GL_FIXED;
		case RHIDataType_Max:
	default:
		break;
	}
};

GLenum shaderResourceTypeInternal(RHIShaderResourceType type)
{
		
	switch (type)
	{
		case RHIShaderResourceType_Float:							return GL_FLOAT;
		case RHIShaderResourceType_Double:							return GL_DOUBLE;
		case RHIShaderResourceType_Int:								return GL_INT;
		case RHIShaderResourceType_UnsignedInt:						return GL_UNSIGNED_INT;
		case RHIShaderResourceType_Short:							return GL_SHORT;
		case RHIShaderResourceType_UnsignedShort:					return GL_UNSIGNED_SHORT;
		case RHIShaderResourceType_Byte:								return GL_BYTE;
		case RHIShaderResourceType_UnsignedByte:						return GL_UNSIGNED_BYTE;
		case RHIShaderResourceType_HalfFloat:						return GL_HALF_FLOAT;
		case RHIShaderResourceType_Fixed:							return GL_FIXED;
		case RHIShaderResourceType_FloatVec2:						return GL_FLOAT_VEC2;
		case RHIShaderResourceType_FloatVec3:						return GL_FLOAT_VEC3;
		case RHIShaderResourceType_FloatVec4:						return GL_FLOAT_VEC4;
		case RHIShaderResourceType_IntVec2:							return GL_INT_VEC2;
		case RHIShaderResourceType_IntVec3:							return GL_INT_VEC3;
		case RHIShaderResourceType_IntVec4:							return GL_INT_VEC4;
		case RHIShaderResourceType_UnsignedIntVec2:					return GL_UNSIGNED_INT_VEC2;
		case RHIShaderResourceType_UnsignedIntVec3:					return GL_UNSIGNED_INT_VEC3;
		case RHIShaderResourceType_UnsignedIntVec4:					return GL_UNSIGNED_INT_VEC4;
		case RHIShaderResourceType_FloatMat2:						return GL_FLOAT_MAT2;
		case RHIShaderResourceType_FloatMat3:						return GL_FLOAT_MAT3;
		case RHIShaderResourceType_FloatMat4:						return GL_FLOAT_MAT4;
		case RHIShaderResourceType_FloatMat2x3:						return GL_FLOAT_MAT2x3;
		case RHIShaderResourceType_FloatMat3x2:						return GL_FLOAT_MAT3x2;
		case RHIShaderResourceType_FloatMat4x3:						return GL_FLOAT_MAT4x3;
		case RHIShaderResourceType_FloatMat3x4:						return GL_FLOAT_MAT3x4;
		case RHIShaderResourceType_FloatMat2x4:						return GL_FLOAT_MAT2x4;
		case RHIShaderResourceType_FloatMat4x2:						return GL_FLOAT_MAT4x2;
		case RHIShaderResourceType_Bool:								return GL_BOOL;
		case RHIShaderResourceType_BoolVec2:							return GL_BOOL_VEC2;
		case RHIShaderResourceType_BoolVec3:							return GL_BOOL_VEC3;
		case RHIShaderResourceType_BoolVec4:							return GL_BOOL_VEC4;
		case RHIShaderResourceType_Sampler1D:						return GL_SAMPLER_1D;
		case RHIShaderResourceType_Sampler2D:						return GL_SAMPLER_2D;
		case RHIShaderResourceType_Sampler3D:						return GL_SAMPLER_3D;
		case RHIShaderResourceType_SamplerCUBE:						return GL_SAMPLER_CUBE;
		case RHIShaderResourceType_Sampler1DShadow:					return GL_SAMPLER_1D_SHADOW;
		case RHIShaderResourceType_Sampler2DShadow:					return GL_SAMPLER_2D_SHADOW;
		case RHIShaderResourceType_IntSampler1D:						return GL_INT_SAMPLER_1D;
		case RHIShaderResourceType_IntSampler2D:						return GL_INT_SAMPLER_2D;
		case RHIShaderResourceType_IntSampler3D:						return GL_INT_SAMPLER_3D;
		case RHIShaderResourceType_IntSamplerCUBE:					return GL_INT_SAMPLER_CUBE;
		case RHIShaderResourceType_IntSampler1DArray:				return GL_INT_SAMPLER_1D_ARRAY;
		case RHIShaderResourceType_IntSampler2DArray:				return GL_INT_SAMPLER_2D_ARRAY;
		case RHIShaderResourceType_UnsignedIntSampler1D:				return GL_UNSIGNED_INT_SAMPLER_1D;
		case RHIShaderResourceType_UnsignedIntSampler2D:				return GL_UNSIGNED_INT_SAMPLER_2D;
		case RHIShaderResourceType_UnsignedIntSampler3D:				return GL_UNSIGNED_INT_SAMPLER_3D;
		case RHIShaderResourceType_UnsignedIntSamplerCUBE:			return GL_UNSIGNED_INT_SAMPLER_CUBE;
		case RHIShaderResourceType_UnsignedIntSampler1DArray:		return GL_UNSIGNED_INT_SAMPLER_1D_ARRAY;
		case RHIShaderResourceType_UnsignedIntSampler2DArray:		return GL_UNSIGNED_INT_SAMPLER_2D_ARRAY;
		case RHIShaderResourceType_Vec2:								return GL_DOUBLE_VEC2;
		case RHIShaderResourceType_Vec3:								return GL_DOUBLE_VEC3;
		case RHIShaderResourceType_Vec4:								return GL_DOUBLE_VEC4;
		case RHIShaderResourceType_Mat2:								return GL_DOUBLE_MAT2;
		case RHIShaderResourceType_Mat3:								return GL_DOUBLE_MAT3;
		case RHIShaderResourceType_Mat4:								return GL_DOUBLE_MAT4;
		case RHIShaderResourceType_Image1D:							return GL_IMAGE_1D;
		case RHIShaderResourceType_Image2D:							return GL_IMAGE_2D;
		case RHIShaderResourceType_Image3D:							return GL_IMAGE_3D;
		case RHIShaderResourceType_Image2DRect:						return GL_IMAGE_2D_RECT;
		case RHIShaderResourceType_ImageCube:						return GL_IMAGE_CUBE;
		case RHIShaderResourceType_ImageBuffer:						return GL_IMAGE_BUFFER;
		case RHIShaderResourceType_Image1DArray:						return GL_IMAGE_1D_ARRAY;
		case RHIShaderResourceType_Image2DArray:						return GL_IMAGE_2D_ARRAY;
		case RHIShaderResourceType_ImageCubemapArray:				return GL_IMAGE_CUBE_MAP_ARRAY;
		case RHIShaderResourceType_Image2DMultisample:				return GL_IMAGE_2D_MULTISAMPLE;
		case RHIShaderResourceType_Image2DMultisampleArray:			return GL_IMAGE_2D_MULTISAMPLE_ARRAY;
		case RHIShaderResourceType_IntImage1D:						return GL_INT_IMAGE_1D;
		case RHIShaderResourceType_IntImage2D:						return GL_INT_IMAGE_2D;
		case RHIShaderResourceType_IntImage3D:						return GL_INT_IMAGE_3D;
		case RHIShaderResourceType_IntImage2DRect:					return GL_INT_IMAGE_2D_RECT;
		case RHIShaderResourceType_IntImageCube:						return GL_INT_IMAGE_CUBE;
		case RHIShaderResourceType_IntImageBuffer:					return GL_INT_IMAGE_BUFFER;
		case RHIShaderResourceType_IntImage1DArray:					return GL_INT_IMAGE_1D_ARRAY;
		case RHIShaderResourceType_IntImage2DArray:					return GL_INT_IMAGE_2D_ARRAY;
		case RHIShaderResourceType_IntImageCubemapArray:				return GL_INT_IMAGE_CUBE_MAP_ARRAY;
		case RHIShaderResourceType_IntImage2DMultisample:			return GL_INT_IMAGE_2D_MULTISAMPLE;
		case RHIShaderResourceType_IntImage2DMultisampleArray:		return GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY;
		case RHIShaderResourceType_UnsignedIntImage1D:				return GL_UNSIGNED_INT_IMAGE_1D;
		case RHIShaderResourceType_UnsignedIntImage2D:				return GL_UNSIGNED_INT_IMAGE_2D;
		case RHIShaderResourceType_UnsignedIntImage3D:				return GL_UNSIGNED_INT_IMAGE_3D;
		case RHIShaderResourceType_UnsignedIntImage2DRect:			return GL_UNSIGNED_INT_IMAGE_2D_RECT;
		case RHIShaderResourceType_UnsignedIntImageCube:				return GL_UNSIGNED_INT_IMAGE_CUBE;
		case RHIShaderResourceType_UnsignedIntImageBuffer:			return GL_UNSIGNED_INT_IMAGE_BUFFER;
		case RHIShaderResourceType_UnsignedIntImage1DArray:			return GL_UNSIGNED_INT_IMAGE_1D_ARRAY;
		case RHIShaderResourceType_UnsignedIntImage2DArray:			return GL_UNSIGNED_INT_IMAGE_2D_ARRAY;
		case RHIShaderResourceType_UnsignedIntImageCubemapArray:		return GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY;
		case RHIShaderResourceType_UnsignedIntImage2DMultisample:	return GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE;
		case RHIShaderResourceType_UnsignedIntImage2DMultisampleArray: return GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY;
	default:
		break;
	}
};

RHIShaderType rhi::shaderTypeRevInternal(GLenum type)
{
	switch (type)
	{
	case GL_VERTEX_SHADER:return RHIShaderType_Vertex;
	case GL_TESS_CONTROL_SHADER:return RHIShaderType_TessellationControl;
	case GL_TESS_EVALUATION_SHADER:return RHIShaderType_Tessellation_Evaluation;
	case GL_GEOMETRY_SHADER:return RHIShaderType_Geometry;
	case GL_FRAGMENT_SHADER:return RHIShaderType_Fragment;
	case GL_COMPUTE_SHADER:return RHIShaderType_Compute;
	default:
		break;
	}
	return RHIShaderType_None;
}

RHIDataType rhi::dataTypeRevInternal(GLenum type)
{
	switch (type)
	{
	case GL_BYTE:return RHIDataType_Byte;
	case GL_UNSIGNED_BYTE:return RHIDataType_Unsigned_Byte;
	case GL_SHORT:return RHIDataType_Short;
	case GL_UNSIGNED_SHORT:return RHIDataType_Unsigned_Short;
	case GL_INT:return RHIDataType_Int;
	case GL_UNSIGNED_INT:return RHIDataType_Unsigned_Int;
	case GL_HALF_FLOAT:return RHIDataType_Half_Float;
	case GL_FLOAT:return RHIDataType_Float;
	case GL_DOUBLE:return RHIDataType_Double;
	case GL_FIXED:return RHIDataType_Fixed;
	default:
		break;
	}

	return RHIDataType_None;
}

RHIShaderResourceType rhi::shaderResourceTypeRevInternal(GLenum type)
{
	switch (type)
	{
	case GL_FLOAT:									return RHIShaderResourceType_Float;
	case GL_DOUBLE:									return RHIShaderResourceType_Double;
	case GL_INT:									return RHIShaderResourceType_Int;
	case GL_UNSIGNED_INT:							return RHIShaderResourceType_UnsignedInt;
	case GL_SHORT:									return RHIShaderResourceType_Short;
	case GL_UNSIGNED_SHORT:							return RHIShaderResourceType_UnsignedShort;
	case GL_BYTE:									return RHIShaderResourceType_Byte;
	case GL_UNSIGNED_BYTE:							return RHIShaderResourceType_UnsignedByte;
	case GL_HALF_FLOAT:								return RHIShaderResourceType_HalfFloat;
	case GL_FIXED:									return RHIShaderResourceType_Fixed;
	case GL_FLOAT_VEC2:								return RHIShaderResourceType_FloatVec2;
	case GL_FLOAT_VEC3:								return RHIShaderResourceType_FloatVec3;						
	case GL_FLOAT_VEC4:								return RHIShaderResourceType_FloatVec4;						
	case GL_INT_VEC2:								return RHIShaderResourceType_IntVec2;							
	case GL_INT_VEC3:								return RHIShaderResourceType_IntVec3;							
	case GL_INT_VEC4:								return RHIShaderResourceType_IntVec4;							
	case GL_UNSIGNED_INT_VEC2:						return RHIShaderResourceType_UnsignedIntVec2;					
	case GL_UNSIGNED_INT_VEC3:						return RHIShaderResourceType_UnsignedIntVec3;					
	case GL_UNSIGNED_INT_VEC4:						return RHIShaderResourceType_UnsignedIntVec4;					
	case GL_FLOAT_MAT2:								return RHIShaderResourceType_FloatMat2;						
	case GL_FLOAT_MAT3:								return RHIShaderResourceType_FloatMat3;						
	case GL_FLOAT_MAT4:								return RHIShaderResourceType_FloatMat4;						
	case GL_FLOAT_MAT2x3:							return RHIShaderResourceType_FloatMat2x3;						
	case GL_FLOAT_MAT3x2:							return RHIShaderResourceType_FloatMat3x2;						
	case GL_FLOAT_MAT4x3:							return RHIShaderResourceType_FloatMat4x3;						
	case GL_FLOAT_MAT3x4:							return RHIShaderResourceType_FloatMat3x4;						
	case GL_FLOAT_MAT2x4:							return RHIShaderResourceType_FloatMat2x4;						
	case GL_FLOAT_MAT4x2:							return RHIShaderResourceType_FloatMat4x2;						
	case GL_BOOL:									return RHIShaderResourceType_Bool;
	case GL_BOOL_VEC2:								return RHIShaderResourceType_BoolVec2;							
	case GL_BOOL_VEC3:								return RHIShaderResourceType_BoolVec3;							
	case GL_BOOL_VEC4:								return RHIShaderResourceType_BoolVec4;							
	case GL_SAMPLER_1D:								return RHIShaderResourceType_Sampler1D;						
	case GL_SAMPLER_2D:								return RHIShaderResourceType_Sampler2D;						
	case GL_SAMPLER_3D:								return RHIShaderResourceType_Sampler3D;						
	case GL_SAMPLER_CUBE:							return RHIShaderResourceType_SamplerCUBE;
	case GL_SAMPLER_1D_SHADOW:						return RHIShaderResourceType_Sampler1DShadow;					
	case GL_SAMPLER_2D_SHADOW:						return RHIShaderResourceType_Sampler2DShadow;					
	case GL_INT_SAMPLER_1D:							return RHIShaderResourceType_IntSampler1D;						
	case GL_INT_SAMPLER_2D:							return RHIShaderResourceType_IntSampler2D;						
	case GL_INT_SAMPLER_3D:							return RHIShaderResourceType_IntSampler3D;						
	case GL_INT_SAMPLER_CUBE:						return RHIShaderResourceType_IntSamplerCUBE;
	case GL_INT_SAMPLER_1D_ARRAY:					return RHIShaderResourceType_IntSampler1DArray;				
	case GL_INT_SAMPLER_2D_ARRAY:					return RHIShaderResourceType_IntSampler2DArray;				
	case GL_UNSIGNED_INT_SAMPLER_1D:				return RHIShaderResourceType_UnsignedIntSampler1D;				
	case GL_UNSIGNED_INT_SAMPLER_2D:				return RHIShaderResourceType_UnsignedIntSampler2D;				
	case GL_UNSIGNED_INT_SAMPLER_3D:				return RHIShaderResourceType_UnsignedIntSampler3D;				
	case GL_UNSIGNED_INT_SAMPLER_CUBE:				return RHIShaderResourceType_UnsignedIntSamplerCUBE;
	case GL_UNSIGNED_INT_SAMPLER_1D_ARRAY:			return RHIShaderResourceType_UnsignedIntSampler1DArray;		
	case GL_UNSIGNED_INT_SAMPLER_2D_ARRAY:			return RHIShaderResourceType_UnsignedIntSampler2DArray;		
	case GL_DOUBLE_VEC2:							return RHIShaderResourceType_Vec2;								
	case GL_DOUBLE_VEC3:							return RHIShaderResourceType_Vec3;								
	case GL_DOUBLE_VEC4:							return RHIShaderResourceType_Vec4;								
	case GL_DOUBLE_MAT2:							return RHIShaderResourceType_Mat2;								
	case GL_DOUBLE_MAT3:							return RHIShaderResourceType_Mat3;								
	case GL_DOUBLE_MAT4:							return RHIShaderResourceType_Mat4;								
	case GL_IMAGE_1D:								return RHIShaderResourceType_Image1D;							
	case GL_IMAGE_2D:								return RHIShaderResourceType_Image2D;							
	case GL_IMAGE_3D:								return RHIShaderResourceType_Image3D;							
	case GL_IMAGE_2D_RECT:							return RHIShaderResourceType_Image2DRect;
	case GL_IMAGE_CUBE:								return RHIShaderResourceType_ImageCube;
	case GL_IMAGE_BUFFER:							return RHIShaderResourceType_ImageBuffer;
	case GL_IMAGE_1D_ARRAY:							return RHIShaderResourceType_Image1DArray;
	case GL_IMAGE_2D_ARRAY:							return RHIShaderResourceType_Image2DArray;
	case GL_IMAGE_CUBE_MAP_ARRAY:					return RHIShaderResourceType_ImageCubemapArray;
	case GL_IMAGE_2D_MULTISAMPLE:					return RHIShaderResourceType_Image2DMultisample;
	case GL_IMAGE_2D_MULTISAMPLE_ARRAY:				return RHIShaderResourceType_Image2DMultisampleArray;
	case GL_INT_IMAGE_1D:							return RHIShaderResourceType_IntImage1D;						
	case GL_INT_IMAGE_2D:							return RHIShaderResourceType_IntImage2D;						
	case GL_INT_IMAGE_3D:							return RHIShaderResourceType_IntImage3D;						
	case GL_INT_IMAGE_2D_RECT:						return RHIShaderResourceType_IntImage2DRect;
	case GL_INT_IMAGE_CUBE:							return RHIShaderResourceType_IntImageCube;
	case GL_INT_IMAGE_BUFFER:						return RHIShaderResourceType_IntImageBuffer;
	case GL_INT_IMAGE_1D_ARRAY:						return RHIShaderResourceType_IntImage1DArray;					
	case GL_INT_IMAGE_2D_ARRAY:						return RHIShaderResourceType_IntImage2DArray;					
	case GL_INT_IMAGE_CUBE_MAP_ARRAY:				return RHIShaderResourceType_IntImageCubemapArray;
	case GL_INT_IMAGE_2D_MULTISAMPLE:				return RHIShaderResourceType_IntImage2DMultisample;
	case GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY:			return RHIShaderResourceType_IntImage2DMultisampleArray;
	case GL_UNSIGNED_INT_IMAGE_1D:					return RHIShaderResourceType_UnsignedIntImage1D;				
	case GL_UNSIGNED_INT_IMAGE_2D:					return RHIShaderResourceType_UnsignedIntImage2D;				
	case GL_UNSIGNED_INT_IMAGE_3D:					return RHIShaderResourceType_UnsignedIntImage3D;				
	case GL_UNSIGNED_INT_IMAGE_2D_RECT:				return RHIShaderResourceType_UnsignedIntImage2DRect;
	case GL_UNSIGNED_INT_IMAGE_CUBE:				return RHIShaderResourceType_UnsignedIntImageCube;
	case GL_UNSIGNED_INT_IMAGE_BUFFER:				return RHIShaderResourceType_UnsignedIntImageBuffer;
	case GL_UNSIGNED_INT_IMAGE_1D_ARRAY:			return RHIShaderResourceType_UnsignedIntImage1DArray;
	case GL_UNSIGNED_INT_IMAGE_2D_ARRAY:			return RHIShaderResourceType_UnsignedIntImage2DArray;
	case GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY:		return RHIShaderResourceType_UnsignedIntImageCubemapArray;
	case GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE:		return RHIShaderResourceType_UnsignedIntImage2DMultisample;
	case GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY:return RHIShaderResourceType_UnsignedIntImage2DMultisampleArray;
	default:
		break;
	}

	return RHIShaderResourceType_None;
}

GLenum rhi::rhiWrapModeInternal(RHIWrapMode mode)
{
	switch (mode)
	{
	case RHIWrapMode_None:
	case RHIWrapMode_ClampToEdge:return GL_CLAMP_TO_EDGE;
	case RHIWrapMode_ClampToBorder:return GL_CLAMP_TO_BORDER;
	case RHIWrapMode_MirroredRepeat:return GL_MIRRORED_REPEAT;
	case RHIWrapMode_Repeat:return GL_REPEAT;
	case RHIWrapMode_MirrorClampToEdge:return GL_MIRROR_CLAMP_TO_EDGE;
	case RHIWrapMode_Max:
	default:
		break;
	}
}

GLenum rhi::filterModeInternal(RHIFilterMode mode)
{
	switch (mode)
	{
	case RHIFilterMode_None:
	case RHIFilterMode_Nearest:return GL_NEAREST;
	case RHIFilterMode_Linear:return GL_LINEAR;
	case RHIFilterMode_NearestMipmapNearest:return GL_NEAREST_MIPMAP_NEAREST;
	case RHIFilterMode_NearestMipmapLinear:return GL_NEAREST_MIPMAP_LINEAR;
	case RHIFilterMode_LinearMipmapNearest:return GL_LINEAR_MIPMAP_NEAREST;
	case RHIFilterMode_LinearMipmapLinear:return GL_LINEAR_MIPMAP_LINEAR;
	case RHIFilterMode_Max:
	default:
		break;
	}
}

GLenum rhi::compareModeInternal(RHICompareMode mode)
{
	switch (mode)
	{
	case RHICompareMode_None:
	case RHICompareMode_CompareRefToTexture:return GL_COMPARE_REF_TO_TEXTURE;
	case RHICompareMode_NoneCompare:return GL_NONE;
	case RHICompareMode_Max:
	default:
		break;
	}
}

GLenum rhi::compareFuncInternal(RHICompareFunc func)
{
	switch (func)
	{
	case RHICompareFunc_None:
	case RHICompareFunc_LessEqual:return GL_LEQUAL;
	case RHICompareFunc_Less:return GL_LESS;
	case RHICompareFunc_Greater:return GL_GREATER;
	case RHICompareFunc_Equal:return GL_EQUAL;
	case RHICompareFunc_NotEqual:return GL_NOTEQUAL;
	case RHICompareFunc_Always:return GL_ALWAYS;
	case RHICompareFunc_Never:return GL_NEVER;
	case RHICompareFunc_Max:
	default:
		break;
	}
}
