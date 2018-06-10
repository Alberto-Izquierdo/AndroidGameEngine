#include "Shaders.h"

const char* Shaders::spritesVertexSource =
	"attribute vec2 aPos;\n"
	"attribute vec2 aTexCoord;\n"
	"uniform vec4 uPos;\n"
	"uniform mat4 uTransformationMatrix;\n"
	"varying vec2 vTexCoord;\n"
	"void main () {\n"
		"gl_Position = uTransformationMatrix * vec4(aPos, 0.0, 1.0) + uPos;\n"
		"vTexCoord = aTexCoord;\n"
	"}\n\0";

const char* Shaders::spritesFragmentSource =
	"precision mediump float;\n"
	"uniform sampler2D uTexture;\n"
	"uniform float uYMaxTexCoord;\n"
	"varying vec2 vTexCoord;\n"
	"float yCoord;\n"
	"void main () {\n"
		"yCoord = vTexCoord.y* 10.0;\n"
		"while (yCoord > uYMaxTexCoord) {;\n"
			"yCoord -= uYMaxTexCoord;\n"
		"}\n"
		"gl_FragColor = texture2D(uTexture, vec2(vTexCoord.x, yCoord));\n"
"}\n\0";
