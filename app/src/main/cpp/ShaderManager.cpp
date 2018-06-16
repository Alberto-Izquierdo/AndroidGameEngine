#include "ShaderManager.h"
#include "Render/Shader.h"

ShaderManager &ShaderManager::getInstance()
{
	static ShaderManager shaderManager;
	return shaderManager;
}

ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager()
{
}

std::shared_ptr<Shader> ShaderManager::getProgram(const char *_vertexSource, const char *_fragmentSource)
{
	std::string completeShader = std::string(_vertexSource) + std::string(_fragmentSource);
	auto it = m_programs.find(completeShader);
	if (it != m_programs.end()) {
		return it->second;
	}
	return loadShader(_vertexSource, _fragmentSource);
}

std::shared_ptr<Shader> ShaderManager::loadShader(const char *_vertexSource, const char *_fragmentSource)
{
	std::shared_ptr<Shader> shader = std::make_shared<Shader>(_vertexSource, _fragmentSource);
	m_programs[std::string(_vertexSource) + std::string(_fragmentSource)] = shader;
	return shader;
}
