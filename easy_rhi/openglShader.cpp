#include "OpenGLShader.h"
#include <glad.h>

rhi::OpenGLShader::~OpenGLShader()
{
	releaseRHI();
}

bool rhi::OpenGLShader::isValid()
{
	return glIsShader(_handle) == GL_TRUE && isCompiled();
}

bool rhi::OpenGLShader::initRHI()
{
	switch (_shaderType)
	{
	case RHIShaderType_None:break;
	case RHIShaderType_Vertex:
	{
		_handle = glCreateShader(GL_VERTEX_SHADER);
		break;
	}
	case RHIShaderType_TessellationControl:
	{
		_handle = glCreateShader(GL_TESS_CONTROL_SHADER);
		break;
	}
	case RHIShaderType_Tessellation_Evaluation:
	{
		_handle = glCreateShader(GL_TESS_EVALUATION_SHADER);
		break;
	}
	case RHIShaderType_Geometry:
	{
		_handle = glCreateShader(GL_GEOMETRY_SHADER);
		break;
	}
	case RHIShaderType_Fragment:
	{
		_handle = glCreateShader(GL_FRAGMENT_SHADER);
		break;
	}
	case RHIShaderType_Compute:
	{
		_handle = glCreateShader(GL_COMPUTE_SHADER);
		break;
	}
	case RHIShaderType_Max:
	default:
		break;
	}
	return glIsShader(_handle) == GL_TRUE;
}

bool rhi::OpenGLShader::releaseRHI()
{
	glDeleteShader(_handle);
	return !isValid();
}

bool rhi::OpenGLShader::copyFrom(shared_ptr<RHIResource> shader)
{
	shared_ptr<OpenGLShader> opengl_shader = std::dynamic_pointer_cast<OpenGLShader>(shader);
	if (opengl_shader && opengl_shader->isValid())
	{
		_shaderType = opengl_shader->getShaderType();
		if (releaseRHI() && initRHI())
		{
			string code;
			opengl_shader->getShaderSourceCode(code);
			setShaderSourceCode(code);
			if (compile())
			{
				string log;
				getShaderInfoLog(log);
				cout << log << endl;
			};
			return isValid();
		};
	}
	_shaderType = RHIShaderType_None;
	return false;
}

bool rhi::OpenGLShader::updateRHI()
{
	return true;
}

void rhi::OpenGLShader::setShaderSourceCode(const string& shaderCode)
{
	const char* shaderSource = shaderCode.data();
	glShaderSource(_handle, 1, &shaderSource, nullptr);
}

void rhi::OpenGLShader::getShaderSourceCode(string& shaderCode)
{
	GLint codeLength;
	glGetShaderiv(_handle, GL_SHADER_SOURCE_LENGTH, &codeLength);

	GLchar* sourceCode = new GLchar[codeLength];

	GLsizei length;
	glGetShaderSource(_handle, codeLength, &length, sourceCode);

	shaderCode = sourceCode;

	delete[] sourceCode;
}

void rhi::OpenGLShader::getShaderInfoLog(string& outInfo)
{
	if (isCompiled())
	{
		GLint logLength;
		glGetShaderiv(_handle, GL_INFO_LOG_LENGTH, &logLength);

		GLchar* log = new GLchar[logLength];
		glGetShaderInfoLog(_handle, logLength, nullptr, log);

		outInfo = log;

		delete[] log;

		return;
	}
	outInfo = "";
}

bool rhi::OpenGLShader::compile() const
{
	glCompileShader(_handle);
	return isCompiled();
}

bool rhi::OpenGLShader::isCompiled() const
{
	GLint compileStatus;
	glGetShaderiv(_handle, GL_COMPILE_STATUS, &compileStatus);
	return compileStatus == GL_TRUE;
}
