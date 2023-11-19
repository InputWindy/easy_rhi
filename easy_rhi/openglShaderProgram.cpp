#include "OpenGLShaderProgram.h"
#include "OpenGLShader.h"

rhi::OpenGLShaderProgram::~OpenGLShaderProgram()
{
	releaseRHI();
}

bool rhi::OpenGLShaderProgram::isValid()
{
	return glIsProgram(_handle) == GL_TRUE && isLinked();
}

bool rhi::OpenGLShaderProgram::initRHI()
{
	_handle = glCreateProgram();
	return glIsProgram(_handle) == GL_TRUE;
}

bool rhi::OpenGLShaderProgram::releaseRHI()
{
	glDeleteProgram(_handle);
	return !isValid();
}

bool rhi::OpenGLShaderProgram::updateRHI()
{
	return true;
}

void rhi::OpenGLShaderProgram::updateShaderParameters()
{
	//attribute
	{
		GLint numAttributes;
		glGetProgramInterfaceiv(_handle, GL_PROGRAM_INPUT, GL_ACTIVE_RESOURCES, &numAttributes);

		for (GLuint index = 0; index < static_cast<GLuint>(numAttributes); ++index)
		{
			constexpr GLenum props[] =
			{
				GL_NAME_LENGTH,

				GL_LOCATION,
				GL_LOCATION_COMPONENT/*layout(component = xxx)*/,
				GL_TYPE,
				GL_ARRAY_SIZE,

				GL_REFERENCED_BY_VERTEX_SHADER,
				GL_REFERENCED_BY_TESS_CONTROL_SHADER,
				GL_REFERENCED_BY_TESS_EVALUATION_SHADER,
				GL_REFERENCED_BY_GEOMETRY_SHADER,
				GL_REFERENCED_BY_FRAGMENT_SHADER,
				GL_REFERENCED_BY_COMPUTE_SHADER,

				GL_IS_PER_PATCH/*tesselation only*/,

			};

			constexpr GLint size = sizeof(props) / sizeof(GLenum);

			GLint params[size] = {};

			glGetProgramResourceiv(_handle, GL_PROGRAM_INPUT, index, size, props, size, nullptr, params);

			Attribute attribute;
			attribute._location = params[1];
			attribute._component = params[2];
			attribute._type = shaderResourceTypeRevInternal((GLenum)params[3]);
			attribute._arraySize = params[4];

			attribute._refByVertex = params[5] == GL_TRUE ? true : false;
			attribute._refByTessControl = params[6] == GL_TRUE ? true : false;
			attribute._refByTessEvaluation = params[7] == GL_TRUE ? true : false;
			attribute._refByGeometry = params[8] == GL_TRUE ? true : false;
			attribute._refByFragement = params[9] == GL_TRUE ? true : false;
			attribute._refByCompute = params[10] == GL_TRUE ? true : false;

			attribute._isPatch = params[11] == GL_TRUE ? true : false;

			constexpr int bufLength = 256;

			GLchar buf[bufLength] = {};
			GLsizei length;
			glGetProgramResourceName(_handle, GL_PROGRAM_INPUT, index, bufLength, &length, buf);

			attribute._name = buf;

			_shaderParameter._attributes.emplace_back(attribute);
		}
	}
	
	//varying
	{
		GLint numVaryings;
		glGetProgramInterfaceiv(_handle, GL_PROGRAM_OUTPUT, GL_ACTIVE_RESOURCES, &numVaryings);

		for (GLuint index = 0; index < static_cast<GLuint>(numVaryings); ++index)
		{
			constexpr GLenum props[] =
			{
				GL_NAME_LENGTH,

				GL_TYPE,

				GL_ARRAY_SIZE,
				GL_LOCATION,
				GL_LOCATION_INDEX,
				GL_LOCATION_COMPONENT,

				GL_REFERENCED_BY_VERTEX_SHADER,
				GL_REFERENCED_BY_TESS_CONTROL_SHADER,
				GL_REFERENCED_BY_TESS_EVALUATION_SHADER,
				GL_REFERENCED_BY_GEOMETRY_SHADER,
				GL_REFERENCED_BY_FRAGMENT_SHADER,
				GL_REFERENCED_BY_COMPUTE_SHADER,

				GL_IS_PER_PATCH/*tesselation only*/,

			};

			constexpr GLint size = sizeof(props) / sizeof(GLenum);

			GLint params[size] = {};

			glGetProgramResourceiv(_handle, GL_PROGRAM_OUTPUT, index, size, props, size, nullptr, params);

			Varying varying;
			varying._location = params[3];
			varying._index = params[4];
			varying._component = params[5];
			varying._type = shaderResourceTypeRevInternal((GLenum)params[1]);
			varying._arraySize = params[2];

			varying._refByVertex = params[5] == GL_TRUE ? true : false;
			varying._refByTessControl = params[6] == GL_TRUE ? true : false;
			varying._refByTessEvaluation = params[7] == GL_TRUE ? true : false;
			varying._refByGeometry = params[8] == GL_TRUE ? true : false;
			varying._refByFragement = params[9] == GL_TRUE ? true : false;
			varying._refByCompute = params[10] == GL_TRUE ? true : false;

			varying._isPatch = params[11] == GL_TRUE ? true : false;

			constexpr int bufLength = 256;

			GLchar buf[bufLength] = {};
			GLsizei length;
			glGetProgramResourceName(_handle, GL_PROGRAM_OUTPUT, index, bufLength, &length, buf);

			varying._name = buf;

			_shaderParameter._varyings.emplace_back(varying);
		};
	}

	//uniform
	{
		GLint numUniforms;
		glGetProgramInterfaceiv(_handle, GL_UNIFORM, GL_ACTIVE_RESOURCES, &numUniforms);

		for (GLuint index = 0; index < static_cast<GLuint>(numUniforms); ++index)
		{
			constexpr GLenum props[] =
			{
				GL_NAME_LENGTH,

				GL_LOCATION,
				GL_TYPE,
				GL_ARRAY_SIZE,
				GL_OFFSET,
				GL_BLOCK_INDEX,
				GL_ARRAY_STRIDE,
				GL_MATRIX_STRIDE,

				GL_IS_ROW_MAJOR,
				GL_ATOMIC_COUNTER_BUFFER_INDEX,

				GL_REFERENCED_BY_VERTEX_SHADER,
				GL_REFERENCED_BY_TESS_CONTROL_SHADER,
				GL_REFERENCED_BY_TESS_EVALUATION_SHADER,
				GL_REFERENCED_BY_GEOMETRY_SHADER,
				GL_REFERENCED_BY_FRAGMENT_SHADER,
				GL_REFERENCED_BY_COMPUTE_SHADER,

			};

			constexpr GLint size = sizeof(props) / sizeof(GLenum);

			GLint params[size] = {};

			glGetProgramResourceiv(_handle, GL_UNIFORM, index, size, props, size, nullptr, params);

			Uniform uniform;
			uniform._location = params[1];
			uniform._type = shaderResourceTypeRevInternal((GLenum)params[2]);
			uniform._arraySize = params[3];
			uniform._offset = params[4];
			uniform._blockIndex = params[5];
			uniform._arrayStride = params[6];
			uniform._matrixStride = params[7];

			uniform._isRowMajor = params[8] == GL_TRUE ? true : false;

			uniform._atomicCounterBufferIndex = params[9];

			uniform._refByVertex = params[10] == GL_TRUE ? true : false;
			uniform._refByTessControl = params[11] == GL_TRUE ? true : false;
			uniform._refByTessEvaluation = params[12] == GL_TRUE ? true : false;
			uniform._refByGeometry = params[13] == GL_TRUE ? true : false;
			uniform._refByFragement = params[14] == GL_TRUE ? true : false;
			uniform._refByCompute = params[15] == GL_TRUE ? true : false;

			constexpr int bufLength = 256;

			GLchar buf[bufLength] = {};
			GLsizei length;
			glGetProgramResourceName(_handle, GL_UNIFORM, index, bufLength, &length, buf);

			uniform._name = buf;

			_shaderParameter._uniforms.emplace_back(uniform);
		};
	}

	//uniform block
	{
		GLint numUniformBlocks;
		glGetProgramInterfaceiv(_handle, GL_UNIFORM_BLOCK, GL_ACTIVE_RESOURCES, &numUniformBlocks);

		for (GLuint index = 0; index < static_cast<GLuint>(numUniformBlocks); ++index)
		{
			constexpr GLenum props[] =
			{
				GL_NAME_LENGTH,

				GL_BUFFER_BINDING,
				GL_ARRAY_SIZE,

				GL_REFERENCED_BY_VERTEX_SHADER,
				GL_REFERENCED_BY_TESS_CONTROL_SHADER,
				GL_REFERENCED_BY_TESS_EVALUATION_SHADER,
				GL_REFERENCED_BY_GEOMETRY_SHADER,
				GL_REFERENCED_BY_FRAGMENT_SHADER,
				GL_REFERENCED_BY_COMPUTE_SHADER,

			};

			constexpr GLint size = sizeof(props) / sizeof(GLenum);

			GLint params[size] = {};

			glGetProgramResourceiv(_handle, GL_UNIFORM_BLOCK, index, size, props, size, nullptr, params);

			UniformBlock uniformBlock;
			uniformBlock._binding = params[1];
			uniformBlock._dataSize = params[2];

			uniformBlock._refByVertex = params[3] == GL_TRUE ? true : false;
			uniformBlock._refByTessControl = params[4] == GL_TRUE ? true : false;
			uniformBlock._refByTessEvaluation = params[5] == GL_TRUE ? true : false;
			uniformBlock._refByGeometry = params[6] == GL_TRUE ? true : false;
			uniformBlock._refByFragement = params[7] == GL_TRUE ? true : false;
			uniformBlock._refByCompute = params[8] == GL_TRUE ? true : false;

			constexpr int bufLength = 256;

			GLchar buf[bufLength] = {};
			GLsizei length;
			glGetProgramResourceName(_handle, GL_UNIFORM_BLOCK, index, bufLength, &length, buf);

			uniformBlock._name = buf;

			_shaderParameter._uniformBlocks.emplace_back(uniformBlock);
		};
	}

	//ssbo
	{
		GLint numSSBOs;
		glGetProgramInterfaceiv(_handle, GL_SHADER_STORAGE_BLOCK, GL_ACTIVE_RESOURCES, &numSSBOs);

		for (GLuint index = 0; index < static_cast<GLuint>(numSSBOs); ++index)
		{
			constexpr GLenum props[] =
			{
				GL_NAME_LENGTH,

				GL_BUFFER_BINDING,
				GL_ARRAY_SIZE,

				GL_REFERENCED_BY_VERTEX_SHADER,
				GL_REFERENCED_BY_TESS_CONTROL_SHADER,
				GL_REFERENCED_BY_TESS_EVALUATION_SHADER,
				GL_REFERENCED_BY_GEOMETRY_SHADER,
				GL_REFERENCED_BY_FRAGMENT_SHADER,
				GL_REFERENCED_BY_COMPUTE_SHADER,

			};

			constexpr GLint size = sizeof(props) / sizeof(GLenum);

			GLint params[size] = {};

			glGetProgramResourceiv(_handle, GL_SHADER_STORAGE_BLOCK, index, size, props, size, nullptr, params);

			ShaderStorageBuffer ssbo;
			ssbo._binding = params[1];
			ssbo._dataSize = params[2];

			ssbo._refByVertex = params[3] == GL_TRUE ? true : false;
			ssbo._refByTessControl = params[4] == GL_TRUE ? true : false;
			ssbo._refByTessEvaluation = params[5] == GL_TRUE ? true : false;
			ssbo._refByGeometry = params[6] == GL_TRUE ? true : false;
			ssbo._refByFragement = params[7] == GL_TRUE ? true : false;
			ssbo._refByCompute = params[8] == GL_TRUE ? true : false;

			constexpr int bufLength = 256;

			GLchar buf[bufLength] = {};
			GLsizei length;
			glGetProgramResourceName(_handle, GL_SHADER_STORAGE_BLOCK, index, bufLength, &length, buf);

			ssbo._name = buf;

			_shaderParameter._shaderStorageBuffers.emplace_back(ssbo);
		};
	}

	//transform feedback
	{
		GLint numVaryings;
		glGetProgramInterfaceiv(_handle, GL_TRANSFORM_FEEDBACK_VARYING, GL_ACTIVE_RESOURCES, &numVaryings);

		for (int index = 0; index < numVaryings; ++index)
		{
			std::vector<GLchar> nameBuffer(256);
			GLsizei nameLength;

			const GLenum props[] = 
			{ 
				GL_TYPE,
				GL_ARRAY_SIZE,
				GL_OFFSET,

				GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
			};

			constexpr GLint size = sizeof(props) / sizeof(GLenum);

			GLint params[size] = {};

			glGetProgramResourceiv(_handle, GL_TRANSFORM_FEEDBACK_VARYING, index, size, props, size, nullptr, params);
			glGetProgramResourceName(_handle, GL_TRANSFORM_FEEDBACK_VARYING, index,nameBuffer.size(), &nameLength, nameBuffer.data());

			TransformFeedbackVarying transformFeedbackVarying;
			transformFeedbackVarying._name = nameBuffer.data();
			transformFeedbackVarying._type = shaderResourceTypeRevInternal(params[0]);
			transformFeedbackVarying._arraySize = params[1];
			transformFeedbackVarying._offset = params[2];
			transformFeedbackVarying._bufferIndex = params[3];

			_shaderParameter._transformFeedbacks.emplace_back(transformFeedbackVarying);
		}
	}
}

bool rhi::OpenGLShaderProgram::link() const
{
	glLinkProgram(_handle);
	return isLinked();
}

bool rhi::OpenGLShaderProgram::isLinked() const
{
	GLint linkStatus;
	glGetProgramiv(_handle, GL_LINK_STATUS, &linkStatus);
	return linkStatus == GL_TRUE;
}

void rhi::OpenGLShaderProgram::use() const
{
	glUseProgram(_handle);
}

void rhi::OpenGLShaderProgram::attachShader(shared_ptr<class RHIShader> shader) const
{
	shared_ptr<rhi::OpenGLShader> rhi_shader = std::dynamic_pointer_cast<OpenGLShader>(shader);
	if (rhi_shader)glAttachShader(_handle, rhi_shader->GetHandle());
	else assert(0);
}

void rhi::OpenGLShaderProgram::getShaderProgramInfoLog(string& out) const
{
	if (isLinked())
	{
		GLint logLength;
		glGetProgramiv(_handle, GL_INFO_LOG_LENGTH, &logLength);

		if (logLength > 0) {
			std::vector<char> log(logLength + 1);
			glGetProgramInfoLog(_handle, logLength, NULL, log.data());
			out = log.data();
		}
	}
}

void rhi::OpenGLShaderProgram::setSubroutine(const char* name, uint32_t from, uint32_t to) const
{
	GLuint updateDefaultIndex = glGetSubroutineIndex(_handle, shaderTypeInternal(from), name);
	glUniformSubroutinesuiv(shaderTypeInternal(to), 1, &updateDefaultIndex);
}

void rhi::OpenGLShaderProgram::setBool1(const char* name, bool data) const
{
	glUniform1i(glGetUniformLocation(_handle, name), data ? 1 : 0);
}

void rhi::OpenGLShaderProgram::setBool2(const char* name, bool data1, bool data2) const
{
	glUniform2i(glGetUniformLocation(_handle, name), data1 ? 1 : 0, data2 ? 1 : 0);
}

void rhi::OpenGLShaderProgram::setBool3(const char* name, bool data1, bool data2, bool data3) const
{
	glUniform3i(glGetUniformLocation(_handle, name), data1 ? 1 : 0, data2 ? 1 : 0, data3 ? 1 : 0);
}

void rhi::OpenGLShaderProgram::setBool4(const char* name, bool data1, bool data2, bool data3, bool data4) const
{
	glUniform4i(glGetUniformLocation(_handle, name), data1 ? 1 : 0, data2 ? 1 : 0, data3 ? 1 : 0, data4 ? 1 : 0);
}

void rhi::OpenGLShaderProgram::setFloat1(const char* name, float data) const
{
	glUniform1f(glGetUniformLocation(_handle, name), data);
}

void rhi::OpenGLShaderProgram::setFloat2(const char* name, float data1, float data2) const
{
	glUniform2f(glGetUniformLocation(_handle, name), data1, data2);
}

void rhi::OpenGLShaderProgram::setFloat3(const char* name, float data1, float data2, float data3) const
{
	glUniform3f(glGetUniformLocation(_handle, name), data1, data2, data3);
}

void rhi::OpenGLShaderProgram::setFloat4(const char* name, float data1, float data2, float data3, float data4) const
{
	glUniform4f(glGetUniformLocation(_handle, name), data1, data2, data3, data4);
}

void rhi::OpenGLShaderProgram::setFloat1Array(const char* name, size_t cnt, float* data) const
{
	glUniform1fv(glGetUniformLocation(_handle, name), cnt,data);
}

void rhi::OpenGLShaderProgram::setFloat2Array(const char* name, size_t cnt, float* data) const
{
	glUniform2fv(glGetUniformLocation(_handle, name), cnt, data);
}

void rhi::OpenGLShaderProgram::setFloat3Array(const char* name, size_t cnt, float* data) const
{
	glUniform3fv(glGetUniformLocation(_handle, name), cnt, data);
}

void rhi::OpenGLShaderProgram::setFloat4Array(const char* name, size_t cnt, float* data) const
{
	glUniform4fv(glGetUniformLocation(_handle, name), cnt, data);
}

void rhi::OpenGLShaderProgram::setInt1Array(const char* name, size_t cnt, int* data) const
{
	glUniform1iv(glGetUniformLocation(_handle, name), cnt, data);
}

void rhi::OpenGLShaderProgram::setInt2Array(const char* name, size_t cnt, int* data) const
{
	glUniform2iv(glGetUniformLocation(_handle, name), cnt, data);
}

void rhi::OpenGLShaderProgram::setInt3Array(const char* name, size_t cnt, int* data) const
{
	glUniform3iv(glGetUniformLocation(_handle, name), cnt, data);
}

void rhi::OpenGLShaderProgram::setInt4Array(const char* name, size_t cnt, int* data) const
{
	glUniform4iv(glGetUniformLocation(_handle, name), cnt, data);
}

void rhi::OpenGLShaderProgram::setUInt1Array(const char* name, size_t cnt, uint32_t* data) const
{
	glUniform1uiv(glGetUniformLocation(_handle, name), cnt, data);
}

void rhi::OpenGLShaderProgram::setUInt2Array(const char* name, size_t cnt, uint32_t* data) const
{
	glUniform2uiv(glGetUniformLocation(_handle, name), cnt, data);
}

void rhi::OpenGLShaderProgram::setUInt3Array(const char* name, size_t cnt, uint32_t* data) const
{
	glUniform3uiv(glGetUniformLocation(_handle, name), cnt, data);
}

void rhi::OpenGLShaderProgram::setUInt4Array(const char* name, size_t cnt, uint32_t* data) const
{
	glUniform4uiv(glGetUniformLocation(_handle, name), cnt, data);
}

void rhi::OpenGLShaderProgram::setMatrixFloat2x2Array(const char* name, size_t cnt, bool transpose, float* data) const
{
	glUniformMatrix2fv(glGetUniformLocation(_handle, name), cnt, transpose, data);
}

void rhi::OpenGLShaderProgram::setMatrixFloat3x3Array(const char* name, size_t cnt, bool transpose, float* data) const
{
	glUniformMatrix3fv(glGetUniformLocation(_handle, name), cnt, transpose, data);
}

void rhi::OpenGLShaderProgram::setMatrixFloat4x4Array(const char* name, size_t cnt, bool transpose, float* data) const
{
	glUniformMatrix4fv(glGetUniformLocation(_handle, name), cnt, transpose, data);
}

void rhi::OpenGLShaderProgram::setMatrixFloat2x3Array(const char* name, size_t cnt, bool transpose, float* data) const
{
	glUniformMatrix2x3fv(glGetUniformLocation(_handle, name), cnt, transpose, data);
}

void rhi::OpenGLShaderProgram::setMatrixFloat3x2Array(const char* name, size_t cnt, bool transpose, float* data) const
{
	glUniformMatrix3x2fv(glGetUniformLocation(_handle, name), cnt, transpose, data);
}

void rhi::OpenGLShaderProgram::setMatrixFloat2x4Array(const char* name, size_t cnt, bool transpose, float* data) const
{
	glUniformMatrix2x4fv(glGetUniformLocation(_handle, name), cnt, transpose, data);
}

void rhi::OpenGLShaderProgram::setMatrixFloat4x2Array(const char* name, size_t cnt, bool transpose, float* data) const
{
	glUniformMatrix4x2fv(glGetUniformLocation(_handle, name), cnt, transpose, data);
}

void rhi::OpenGLShaderProgram::setMatrixFloat3x4Array(const char* name, size_t cnt, bool transpose, float* data) const
{
	glUniformMatrix3x4fv(glGetUniformLocation(_handle, name), cnt, transpose, data);
}

void rhi::OpenGLShaderProgram::setMatrixFloat4x3Array(const char* name, size_t cnt, bool transpose, float* data) const
{
	glUniformMatrix4x3fv(glGetUniformLocation(_handle, name), cnt, transpose, data);
}

void rhi::OpenGLShaderProgram::setInt1(const char* name, int data1) const
{
	glUniform1i(glGetUniformLocation(_handle, name), data1);
}

void rhi::OpenGLShaderProgram::setInt2(const char* name, int data1, int data2) const
{
	glUniform2i(glGetUniformLocation(_handle, name), data1, data2);
}

void rhi::OpenGLShaderProgram::setInt3(const char* name, int data1, int data2, int data3) const
{
	glUniform3i(glGetUniformLocation(_handle, name), data1, data2, data3);
}

void rhi::OpenGLShaderProgram::setInt4(const char* name, int data1, int data2, int data3, int data4) const
{
	glUniform4i(glGetUniformLocation(_handle, name), data1, data2, data3, data4);
}

void rhi::OpenGLShaderProgram::setUInt1(const char* name, uint32_t data1) const
{
	glUniform1ui(glGetUniformLocation(_handle, name), data1);
}

void rhi::OpenGLShaderProgram::setUInt2(const char* name, uint32_t data1, uint32_t data2) const
{
	glUniform2ui(glGetUniformLocation(_handle, name), data1, data2);
}

void rhi::OpenGLShaderProgram::setUInt3(const char* name, uint32_t data1, uint32_t data2, uint32_t data3) const
{
	glUniform3ui(glGetUniformLocation(_handle, name), data1, data2, data3);
}

void rhi::OpenGLShaderProgram::setUInt4(const char* name, uint32_t data1, uint32_t data2, uint32_t data3, uint32_t data4) const
{
	glUniform4ui(glGetUniformLocation(_handle, name), data1, data2, data3, data4);
}
