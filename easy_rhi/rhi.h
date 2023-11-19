#pragma once
#include <string>
#include <vector>
#include <map>
#include <array>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <assert.h>

using std::shared_ptr;
using std::string;
using std::vector;
using std::map;
using std::array;
using std::cout;
using std::endl;

/****************************
*	forward declaration		*
****************************/
namespace rhi
{
	struct INoneCopyable;

	class RHIResource;
	class RHIVertexArray;
	class RHIShader;

	typedef uint32_t RHIResourceType;
	typedef uint32_t RHIShaderType;
	typedef uint32_t RHIDataType;
	typedef uint32_t RHIShaderResourceType;
	typedef uint32_t RHIWrapMode;
	typedef uint32_t RHIFilterMode;
	typedef uint32_t RHICompareMode;
	typedef uint32_t RHICompareFunc;
}



/****************************
*			enum			*
****************************/
namespace
{
	enum RHIResourceType_ :uint32_t
	{
		RHIResourceType_None,

		RHIResourceType_VertexArray,
		RHIResourceType_Shader,
		RHIResourceType_ShaderProgram,
		RHIResourceType_Sampler,

		RHIResourceType_Max,
	};

	enum RHIShaderType_ :uint32_t
	{
		RHIShaderType_None,
		
		RHIShaderType_Vertex,
		RHIShaderType_TessellationControl,
		RHIShaderType_Tessellation_Evaluation,
		RHIShaderType_Geometry,
		RHIShaderType_Fragment,

		RHIShaderType_Compute,
		
		RHIShaderType_Max,
	};

	enum RHIDataType_ :uint32_t
	{
		RHIDataType_None,
		
		RHIDataType_Byte,
		RHIDataType_Unsigned_Byte,
		RHIDataType_Short,
		RHIDataType_Unsigned_Short,
		RHIDataType_Int,
		RHIDataType_Unsigned_Int,
		RHIDataType_Half_Float,
		RHIDataType_Float,
		RHIDataType_Double,
		RHIDataType_Fixed,
		
		RHIDataType_Max
	};

	enum RHIShaderResourceType_ :uint32_t
	{
		RHIShaderResourceType_None,

		//scalar
		RHIShaderResourceType_Float,
		RHIShaderResourceType_Double,
		RHIShaderResourceType_Int,
		RHIShaderResourceType_UnsignedInt,
		RHIShaderResourceType_Short,
		RHIShaderResourceType_UnsignedShort,
		RHIShaderResourceType_Byte,
		RHIShaderResourceType_UnsignedByte,
		RHIShaderResourceType_HalfFloat,
		RHIShaderResourceType_Fixed,

		//vector
		RHIShaderResourceType_FloatVec2,
		RHIShaderResourceType_FloatVec3,
		RHIShaderResourceType_FloatVec4,
		RHIShaderResourceType_IntVec2 ,
		RHIShaderResourceType_IntVec3 ,
		RHIShaderResourceType_IntVec4 ,
		RHIShaderResourceType_UnsignedIntVec2,
		RHIShaderResourceType_UnsignedIntVec3,
		RHIShaderResourceType_UnsignedIntVec4,

		//matrix
		RHIShaderResourceType_FloatMat2,
		RHIShaderResourceType_FloatMat3,
		RHIShaderResourceType_FloatMat4,

		RHIShaderResourceType_FloatMat2x3,
		RHIShaderResourceType_FloatMat3x2,
		RHIShaderResourceType_FloatMat4x3,
		RHIShaderResourceType_FloatMat3x4,
		RHIShaderResourceType_FloatMat2x4,
		RHIShaderResourceType_FloatMat4x2,

		//bool
		RHIShaderResourceType_Bool,
		RHIShaderResourceType_BoolVec2,
		RHIShaderResourceType_BoolVec3,
		RHIShaderResourceType_BoolVec4,


		//sampler
		RHIShaderResourceType_Sampler1D,
		RHIShaderResourceType_Sampler2D,
		RHIShaderResourceType_Sampler3D,
		RHIShaderResourceType_SamplerCUBE,
		RHIShaderResourceType_Sampler1DShadow,
		RHIShaderResourceType_Sampler2DShadow,
		RHIShaderResourceType_IntSampler1D,
		RHIShaderResourceType_IntSampler2D,
		RHIShaderResourceType_IntSampler3D,
		RHIShaderResourceType_IntSamplerCUBE,
		RHIShaderResourceType_IntSampler1DArray,
		RHIShaderResourceType_IntSampler2DArray,
		RHIShaderResourceType_UnsignedIntSampler1D,
		RHIShaderResourceType_UnsignedIntSampler2D,
		RHIShaderResourceType_UnsignedIntSampler3D,
		RHIShaderResourceType_UnsignedIntSamplerCUBE,
		RHIShaderResourceType_UnsignedIntSampler1DArray,
		RHIShaderResourceType_UnsignedIntSampler2DArray,

		//atomic counter
		//GL_ATOMIC_UINT,
		

		//
		RHIShaderResourceType_Vec2,
		RHIShaderResourceType_Vec3,
		RHIShaderResourceType_Vec4,
		RHIShaderResourceType_Mat2,
		RHIShaderResourceType_Mat3,
		RHIShaderResourceType_Mat4,

		//image
		RHIShaderResourceType_Image1D ,
		RHIShaderResourceType_Image2D ,
		RHIShaderResourceType_Image3D ,
		RHIShaderResourceType_Image2DRect ,
		RHIShaderResourceType_ImageCube ,
		RHIShaderResourceType_ImageBuffer ,
		RHIShaderResourceType_Image1DArray ,
		RHIShaderResourceType_Image2DArray ,
		RHIShaderResourceType_ImageCubemapArray ,
		RHIShaderResourceType_Image2DMultisample ,
		RHIShaderResourceType_Image2DMultisampleArray,
		RHIShaderResourceType_IntImage1D,
		RHIShaderResourceType_IntImage2D,
		RHIShaderResourceType_IntImage3D,
		RHIShaderResourceType_IntImage2DRect,
		RHIShaderResourceType_IntImageCube,
		RHIShaderResourceType_IntImageBuffer,
		RHIShaderResourceType_IntImage1DArray,
		RHIShaderResourceType_IntImage2DArray,
		RHIShaderResourceType_IntImageCubemapArray,
		RHIShaderResourceType_IntImage2DMultisample,
		RHIShaderResourceType_IntImage2DMultisampleArray,
		RHIShaderResourceType_UnsignedIntImage1D,
		RHIShaderResourceType_UnsignedIntImage2D,
		RHIShaderResourceType_UnsignedIntImage3D,
		RHIShaderResourceType_UnsignedIntImage2DRect,
		RHIShaderResourceType_UnsignedIntImageCube,
		RHIShaderResourceType_UnsignedIntImageBuffer,
		RHIShaderResourceType_UnsignedIntImage1DArray,
		RHIShaderResourceType_UnsignedIntImage2DArray,
		RHIShaderResourceType_UnsignedIntImageCubemapArray,
		RHIShaderResourceType_UnsignedIntImage2DMultisample,
		RHIShaderResourceType_UnsignedIntImage2DMultisampleArray,

		RHIShaderResourceType_Max
	};

	enum RHIWrapMode_ :uint32_t
	{
		RHIWrapMode_None,
		
		RHIWrapMode_ClampToEdge,
		RHIWrapMode_ClampToBorder,
		RHIWrapMode_MirroredRepeat,
		RHIWrapMode_Repeat,
		RHIWrapMode_MirrorClampToEdge,
		
		RHIWrapMode_Max
	};

	enum RHIFilterMode_ : uint32_t
	{
		RHIFilterMode_None,
		
		RHIFilterMode_Nearest,
		RHIFilterMode_Linear,
		RHIFilterMode_NearestMipmapNearest,
		RHIFilterMode_NearestMipmapLinear,
		RHIFilterMode_LinearMipmapNearest,
		RHIFilterMode_LinearMipmapLinear,
		
		RHIFilterMode_Max
	};

	enum RHICompareMode_ :uint32_t
	{
		RHICompareMode_None,
		
		RHICompareMode_CompareRefToTexture,
		RHICompareMode_NoneCompare,
		
		RHICompareMode_Max
	};

	enum RHICompareFunc_ :uint32_t
	{
		RHICompareFunc_None,
		
		RHICompareFunc_LessEqual,
		RHICompareFunc_Less,
		RHICompareFunc_Greater,
		RHICompareFunc_Equal,
		RHICompareFunc_NotEqual,
		RHICompareFunc_Always,
		RHICompareFunc_Never,
		
		RHICompareFunc_Max
	};
}



/****************************
*			struct			*
****************************/
namespace rhi
{
	struct INoneCopyable
	{
		INoneCopyable() = default;
		virtual ~INoneCopyable() = default;

		INoneCopyable(const INoneCopyable&) = delete;
		INoneCopyable(INoneCopyable&&) = delete;

		void operator=(const INoneCopyable&) = delete;
		void operator=(INoneCopyable&&) = delete;
	};

	class RHIResource :public INoneCopyable, public std::enable_shared_from_this<RHIResource>
	{
	protected:
		RHIResource() = default;
	public:
		virtual ~RHIResource() = default;
	public:
		/// <summary>
		/// ������Դ���͵�ö��ֵ
		/// </summary>
		virtual RHIResourceType getResourceType()const = 0;

		/// <summary>
		/// ������Դ���͵��ַ���
		/// </summary>
		virtual string getResourceTypeName()const = 0;
	public:
		/// <summary>
		/// ��ѯ��ǰ��Դ�Ƿ����
		/// </summary>
		virtual bool isValid() = 0;

		/// <summary>
		/// ��ʼ��rhi��Դ
		/// </summary>
		virtual bool initRHI() = 0;

		/// <summary>
		/// �ͷ�rhi��Դ
		/// </summary>
		virtual bool releaseRHI() = 0;

		/// <summary>
		/// rhi��Դ���ƣ�������Src��
		/// <param name="Src"></param>
		/// </summary>
		virtual bool copyFrom(shared_ptr<RHIResource>) = 0;

		/// <summary>
		/// ͬ��������Դ
		/// </summary>
		virtual bool updateRHI() = 0;
	};
}

namespace rhi
{
	class RHIVertexArray :public RHIResource
	{
	protected:
		RHIVertexArray() = default;
	public:
		virtual ~RHIVertexArray() = default;
	public:
		/********************************************
		*			resource interface				*
		*********************************************/
		virtual RHIResourceType getResourceType()	const final;
		virtual string	 getResourceTypeName()	const final;
	public:
		virtual bool isValid() = 0;
		virtual bool initRHI() = 0;
		virtual bool releaseRHI() = 0;

		virtual bool copyFrom(shared_ptr<class RHIResource>) = 0;
		virtual bool updateRHI() = 0;
	public:
		/// <summary>
		/// ��vao
		/// </summary>
		virtual void bind()   const = 0;

		/// <summary>
		/// ���vao
		/// </summary>
		virtual void unBind() const = 0;

		/// <summary>
		/// ���ö�������
		/// <param name="InAttribIdx"> ������������ </param>
		/// </summary>
		virtual void enableAttribute(uint8_t)  const = 0;

		/// <summary>
		/// ���ö�������
		/// <param name="InAttribIdx"> ������������ </param>
		/// </summary>
		virtual void disableAttribute(uint8_t) const = 0;

		/// <summary>
		/// ���ö������Ը�ʽ
		/// <param name="������������"></param>
		/// <param name="ͨ����"></param>
		/// <param name="��ͨ����������(ö��ֵ)"></param>
		/// <param name="�Ƿ��һ��"></param>
		/// <param name="��ǰ����������buffer��ƫ����"></param>
		/// </summary>
		virtual void setAttributeFormat(uint32_t, int, RHIDataType, bool, uint32_t) const = 0;
		
		/// <summary>
		/// ���ö������Ը�ʽ
		/// <param name="������������"></param>
		/// <param name="vbo��vao�ڰ󶨵�λ"></param>
		/// </summary>
		virtual void setAttributeBinding(uint32_t, uint32_t) const = 0;

		/// <summary>
		/// ���ö�������ָ����buffer�ڵ��ƶ�Ƶ��
		/// <param name="vbo��vao�ڰ󶨵�λ"></param>
		/// <param name="����Ƶ��"></param>
		/// </summary>
		virtual void setVertexBindingDivisor(uint32_t,uint32_t) const = 0;

		/// <summary>
		/// ���ö�������ָ����buffer�ڵ��ƶ�Ƶ��(RHIShaderResourceTypeVertexArrayVertexBuffer)
		/// <param name="vbo��vao�ڰ󶨵�λ"></param>
		/// <param name="vbo"></param>
		/// </summary>
		virtual void bindVertexBuffer(uint32_t,shared_ptr<class RHIBuffer>) const = 0;

		/// <summary>
		/// ���ö������Ժ�vbo������ʽ
		/// <param name="������������"></param>
		/// <param name="��������ͨ����"></param>
		/// <param name="�����������ͣ�ö��ֵ��"></param>
		/// <param name="�Ƿ��һ��"></param>
		/// <param name="�����������ܴ�С"></param>
		/// <param name="����Ƭ��ƫ��"></param>
		/// </summary>
		virtual void setAttributePointer(uint32_t, int, RHIDataType, bool, int, size_t) const = 0;

	};

	class RHIShader :public RHIResource
	{
	protected:
		RHIShader() = default;
	public:
		virtual ~RHIShader() = default;
	public:
		/********************************************
		*			resource interface				*
		*********************************************/

		virtual RHIResourceType getResourceType()	const final;
		virtual string	 getResourceTypeName()	const final;
	public:
		virtual bool isValid() = 0;
		virtual bool initRHI() = 0;
		virtual bool releaseRHI() = 0;

		virtual bool copyFrom(shared_ptr<class RHIResource>) = 0;
		virtual bool updateRHI() = 0;
	public:
		/********************************************
		*			shader interface				*
		*********************************************/

		/// <summary>
		/// ��ȡShader���ͣ�ö��ֵ��
		/// </summary>
		RHIShaderType getShaderType()const;

		/// <summary>
		/// ������ɫ������
		/// <param name="�����ַ���"></param>
		/// </summary>
		virtual void setShaderSourceCode(const string&) = 0;

		/// <summary>
		/// ������ɫ������
		/// <param name="���ش����ַ���"></param>
		/// </summary>
		virtual void getShaderSourceCode(string&) = 0;

		/// <summary>
		/// ������ɫ����־
		/// <param name="������־�ַ���"></param>
		/// </summary>
		virtual void getShaderInfoLog(string&) = 0;

		/// <summary>
		/// ������ɫ������
		/// </summary>
		virtual bool compile()const = 0;

		/// <summary>
		/// ��ɫ�������Ƿ����
		/// </summary>
		virtual bool isCompiled()const = 0;
	protected:
		RHIShaderType _shaderType = RHIShaderType_None;
	};

	class RHIShaderProgram :public RHIResource
	{
	public:
		struct Attribute
		{
			uint32_t _location;
			uint32_t _component;
			RHIShaderResourceType _type;
			string	 _name;
			uint32_t _arraySize;

			bool _refByVertex;
			bool _refByTessControl;
			bool _refByTessEvaluation;
			bool _refByGeometry;
			bool _refByFragement;
			bool _refByCompute;

			bool _isPatch;
		};

		struct Varying
		{
			uint32_t _location;
			uint32_t _index;
			uint32_t _component;
			RHIShaderResourceType _type;
			string	 _name;
			uint32_t _arraySize;

			bool _refByVertex;
			bool _refByTessControl;
			bool _refByTessEvaluation;
			bool _refByGeometry;
			bool _refByFragement;
			bool _refByCompute;

			bool _isPatch;
		};

		struct Uniform
		{
			string _name;
			uint32_t _location;
			RHIShaderResourceType _type;
			uint32_t _arraySize;
			uint32_t _offset;
			uint32_t _blockIndex;
			uint32_t _arrayStride;
			uint32_t _matrixStride;

			bool _isRowMajor;

			uint32_t _atomicCounterBufferIndex;

			bool _refByVertex;
			bool _refByTessControl;
			bool _refByTessEvaluation;
			bool _refByGeometry;
			bool _refByFragement;
			bool _refByCompute;
		};

		struct UniformBlock
		{
			string _name;
			uint32_t _binding;
			uint32_t _dataSize;
			
			bool _refByVertex;
			bool _refByTessControl;
			bool _refByTessEvaluation;
			bool _refByGeometry;
			bool _refByFragement;
			bool _refByCompute;
		};

		struct ShaderStorageBuffer
		{
			string _name;
			uint32_t _binding;
			uint32_t _dataSize;

			bool _refByVertex;
			bool _refByTessControl;
			bool _refByTessEvaluation;
			bool _refByGeometry;
			bool _refByFragement;
			bool _refByCompute;
		};

		struct TransformFeedbackVarying
		{
			string _name;
			
			RHIShaderResourceType _type;
			uint32_t _arraySize;
			uint32_t _offset;

			uint32_t _bufferIndex;
		};

		struct ShaderParameter
		{
			vector<Attribute> _attributes;
			vector<Varying> _varyings;
			vector<Uniform> _uniforms;
			vector<UniformBlock> _uniformBlocks;
			vector<ShaderStorageBuffer> _shaderStorageBuffers;
			vector<TransformFeedbackVarying> _transformFeedbacks;
		};
	protected:
		RHIShaderProgram() = default;
	public:
		virtual ~RHIShaderProgram() = default;
	public:
		/********************************************
		*			resource interface				*
		*********************************************/

		virtual RHIResourceType getResourceType()	const final;
		virtual string	 getResourceTypeName()	const final;
	public:
		virtual bool isValid() = 0;
		virtual bool initRHI() = 0;
		virtual bool releaseRHI() = 0;

		virtual bool copyFrom(shared_ptr<class RHIResource>) = 0;
		virtual bool updateRHI() = 0;
	public:

		/// <summary>
		/// ��ȡ��ɫ���������
		/// </summary>
		const ShaderParameter& getActiveShaderParameters() const;

		/// <summary>
		/// ͬ��������ɫ���������
		/// </summary>
		virtual void updateShaderParameters() = 0;

		/// <summary>
		/// ������ɫ������
		/// </summary>
		virtual bool link() const = 0;

		/// <summary>
		/// ������ɫ������
		/// </summary>
		virtual bool isLinked() const = 0;

		/// <summary>
		/// ����ɫ������
		/// </summary>
		virtual void use()  const = 0;

		/// <summary>
		/// �����ɫ������
		/// <param name="��ɫ��"></param>
		/// </summary>
		virtual void attachShader(shared_ptr<class RHIShader>) const = 0;

		/// <summary>
		/// ��ȡ��ɫ��������־
		/// </summary>
		virtual void getShaderProgramInfoLog(string&) const = 0;

		/********************************************
		*			set complex uniform				*
		*********************************************/


		/// <summary>
		/// ����һ��subroutine�������ͣ������кܶ��ֲ�ͬ�ĺ���ʵ�ַ�ʽ��
		/// ��ʹ��ʱ��������һ��subroutine�������ͣ������øú�����
		/// ͨ��SetSubroutine�������Զ�̬�󶨲�ͬ�ĺ���ʵ�ַ�ʽ
		/// <param name="�ӳ���ʵ������"></param>
		/// <param name="�ӳ�������λ�ã�ö��ֵ��"></param>
		/// <param name="�ӳ���ʹ��λ�ã�ö��ֵ��"></param>
		/// </summary>
		virtual void setSubroutine(const char*,RHIShaderType, RHIShaderType)const = 0;

		/// <summary>
		/// ��buffer�󶨵���Ӧ��uniform����
		/// <param name="unifom����"></param>
		/// <param name="uniform buffer"></param>
		/// </summary>
		virtual void setShaderBuffer(const char*, shared_ptr<class RHIShaderBuffer>) const = 0;
		
		/// <summary>
		/// ��texture�󶨵���Ӧ��uniform����
		/// <param name="unifom����"></param>
		/// <param name="texture"></param>
		/// </summary>
		virtual void setTexture(const char*, shared_ptr<class RHITexture>) const = 0;

		/// <summary>
		/// ��texture image�󶨵���Ӧ��uniform����
		/// <param name="unifom����"></param>
		/// <param name="texture image"></param>
		/// </summary>
		virtual void setTextureImage(const char*, shared_ptr<class RHITextureImage>) const = 0;

		/********************************************
		*			set simple uniform				*
		*********************************************/

		virtual void setBool1(const char*, bool) const = 0;
		virtual void setBool2(const char*, bool, bool) const = 0;
		virtual void setBool3(const char*, bool, bool, bool) const = 0;
		virtual void setBool4(const char*, bool, bool, bool, bool) const = 0;

		virtual void setInt1(const char*, int) const = 0;
		virtual void setInt2(const char*, int, int) const = 0;
		virtual void setInt3(const char*, int, int, int) const = 0;
		virtual void setInt4(const char*, int, int, int, int) const = 0;

		virtual void setUInt1(const char*, uint32_t) const = 0;
		virtual void setUInt2(const char*, uint32_t, uint32_t) const = 0;
		virtual void setUInt3(const char*, uint32_t, uint32_t, uint32_t) const = 0;
		virtual void setUInt4(const char*, uint32_t, uint32_t, uint32_t, uint32_t) const = 0;

		virtual void setFloat1(const char*, float) const = 0;
		virtual void setFloat2(const char*, float, float) const = 0;
		virtual void setFloat3(const char*, float, float, float) const = 0;
		virtual void setFloat4(const char*, float, float, float, float) const = 0;

		virtual void setFloat1Array(const char*, size_t, float*) const = 0;
		virtual void setFloat2Array(const char*, size_t, float*) const = 0;
		virtual void setFloat3Array(const char*, size_t, float*) const = 0;
		virtual void setFloat4Array(const char*, size_t, float*) const = 0;

		virtual void setInt1Array(const char*, size_t, int*) const = 0;
		virtual void setInt2Array(const char*, size_t, int*) const = 0;
		virtual void setInt3Array(const char*, size_t, int*) const = 0;
		virtual void setInt4Array(const char*, size_t, int*) const = 0;

		virtual void setUInt1Array(const char*, size_t, uint32_t*) const = 0;
		virtual void setUInt2Array(const char*, size_t, uint32_t*) const = 0;
		virtual void setUInt3Array(const char*, size_t, uint32_t*) const = 0;
		virtual void setUInt4Array(const char*, size_t, uint32_t*) const = 0;

		virtual void setMatrixFloat2x2Array(const char*, size_t, bool, float*) const = 0;
		virtual void setMatrixFloat3x3Array(const char*, size_t, bool, float*) const = 0;
		virtual void setMatrixFloat4x4Array(const char*, size_t, bool, float*) const = 0;
		virtual void setMatrixFloat2x3Array(const char*, size_t, bool, float*) const = 0;
		virtual void setMatrixFloat3x2Array(const char*, size_t, bool, float*) const = 0;
		virtual void setMatrixFloat2x4Array(const char*, size_t, bool, float*) const = 0;
		virtual void setMatrixFloat4x2Array(const char*, size_t, bool, float*) const = 0;
		virtual void setMatrixFloat3x4Array(const char*, size_t, bool, float*) const = 0;
		virtual void setMatrixFloat4x3Array(const char*, size_t, bool, float*) const = 0;
	
	protected:
		ShaderParameter _shaderParameter;
	};

	class RHISampler :public RHIResource
	{
	protected:
		RHISampler() = default;
	public:
		virtual ~RHISampler() = default;
	public:
		/********************************************
		*			resource interface				*
		*********************************************/

		virtual RHIResourceType getResourceType()	const final;
		virtual string	 getResourceTypeName()	const final;
	public:
		virtual bool isValid() = 0;
		virtual bool initRHI() = 0;
		virtual bool releaseRHI() = 0;

		virtual bool copyFrom(shared_ptr<class RHIResource>) = 0;
		virtual bool updateRHI() = 0;
	public:
		RHIWrapMode getWrapR()const;
		RHIWrapMode getWrapS()const;
		RHIWrapMode getWrapT()const;

		RHIFilterMode getMinFilterMode()const;
		RHIFilterMode getMagFilterMode()const;

		uint8_t getMinMipLevel()const;
		uint8_t getMaxMipLevel()const;
		float   getLODBias()const;

		const vector<float>& getBorderColor()const;

		RHICompareMode setCompareMode()const;
		RHICompareFunc setCompareFunc()const;

		void setWrapR(RHIWrapMode);
		void setWrapS(RHIWrapMode);
		void setWrapT(RHIWrapMode);
			 
		void setMinFilterMode(RHIFilterMode);
		void setMagFilterMode(RHIFilterMode);
			 
		void setMinMipLevel(uint8_t);
		void setMaxMipLevel(uint8_t);
		void setLODBias(float);
			 
		void setBorderColor(float, float, float, float);
			 
		void setCompareMode(RHICompareMode);
		void setCompareFunc(RHICompareFunc);
	protected:
		RHIWrapMode _wrapR;
		RHIWrapMode _wrapS;
		RHIWrapMode _wrapT;

		RHIFilterMode _minFilterMode;
		RHIFilterMode _magFilterMode;

		uint8_t _minMipLevel = 0;
		uint8_t _maxMipLevel = 0;
		float   _lodBias  = 0;

		vector<float> _borderColor = { 0,0,0,0 };

		RHICompareMode _compareMode;
		RHICompareFunc _compareFunc;
	};

};