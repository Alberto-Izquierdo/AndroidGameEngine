#pragma once

#include <string>
#include <unordered_map>
#include "../Math.h"

enum GLShader
{
	VERTEX,
	FRAGMENT
};

class Shader
{
public:
	Shader(const char* _pVertexSource, const char* _pFragmentSource);
	~Shader();

	unsigned int GetRendererID() const { return m_iRendererID; };

	void Bind();
	void Unbind();

	void SetUniform1i(const std::string& _sName, int _iV);
	void SetUniform1f(const std::string& _sName, float _fV);
	void SetUniform2f(const std::string& _sName, float _fV1, float _fV2);
	void SetUniform4f(const std::string& _sName, float _fV1, float _fV2, float _fV3, float _fV4);
	void SetUniformMatrix4f(const std::string &_sName, const math::mat4f &_matrix);

protected:
	unsigned int m_iRendererID;
	std::unordered_map<std::string, int> m_mUniformLocations;

	unsigned int CreateShader(const char* _pVertexSource, GLShader _eShaderType);
	void CreateProgram(unsigned int _iVertexShader, unsigned int _iFragmentShader);
	int GetUniformLocation(const std::string& _sName);
};
