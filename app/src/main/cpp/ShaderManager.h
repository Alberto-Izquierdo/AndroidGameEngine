#pragma once

#include <memory>
#include <unordered_map>
#include <string>

class Shader;

class ShaderManager
{
public:
	static ShaderManager& getInstance();

	std::shared_ptr<Shader> getProgram(const char *_vertexSource, const char *_fragmentSource);

private:
	std::unordered_map<std::string, std::shared_ptr<Shader>> m_programs;

	std::shared_ptr<Shader> loadShader(const char *_vertexSource, const char *_fragmentSource);

	ShaderManager();
	~ShaderManager();
};
