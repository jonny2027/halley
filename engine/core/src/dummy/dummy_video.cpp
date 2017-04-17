#include "dummy_video.h"
#include <halley/core/graphics/painter.h>
#include <halley/core/graphics/texture.h>
#include <halley/core/graphics/shader.h>
#include <halley/core/graphics/render_target/render_target_texture.h>
#include "dummy_system.h"

using namespace Halley;

DummyVideoAPI::DummyVideoAPI(SystemAPI&) 
{}

void DummyVideoAPI::startRender()
{
}

void DummyVideoAPI::finishRender()
{
}

void DummyVideoAPI::setWindow(WindowDefinition&& windowDescriptor, bool vsync)
{
	//window = system.createWindow(windowDescriptor);
	window = std::make_shared<DummyWindow>(windowDescriptor);
}

const Window& DummyVideoAPI::getWindow() const
{
	return *window;
}

std::unique_ptr<Texture> DummyVideoAPI::createTexture(Vector2i size)
{
	return std::make_unique<DummyTexture>(size);
}

std::unique_ptr<Shader> DummyVideoAPI::createShader(const ShaderDefinition&)
{
	return std::make_unique<DummyShader>();
}

std::unique_ptr<TextureRenderTarget> DummyVideoAPI::createRenderTarget()
{
	return std::make_unique<DummyTextureRenderTarget>();
}

std::unique_ptr<MaterialConstantBuffer> DummyVideoAPI::createConstantBuffer()
{
	return std::make_unique<DummyMaterialConstantBuffer>();
}

void DummyVideoAPI::init()
{
}

void DummyVideoAPI::deInit()
{
}

std::unique_ptr<Painter> DummyVideoAPI::makePainter(Resources& resources)
{
	return std::make_unique<DummyPainter>(resources);
}

DummyTexture::DummyTexture(Vector2i s)
{
	size = s;
}

void DummyTexture::bind(int textureUnit) const {}

void DummyTexture::load(TextureDescriptor&& descriptor)
{
	doneLoading();
}

bool DummyTextureRenderTarget::isScreen() const
{
	return false;
}

void DummyTextureRenderTarget::bind() {}

void DummyTextureRenderTarget::unbind() {}

int DummyShader::getUniformLocation(const String& name)
{
	return 0;
}

int DummyShader::getBlockLocation(const String& name)
{
	return 0;
}

void DummyMaterialConstantBuffer::update(const MaterialDataBlock& dataBlock) {}

DummyPainter::DummyPainter(Resources& resources)
	: Painter(resources)
{}

void DummyPainter::clear(Colour colour) {}

void DummyPainter::setMaterialPass(const Material& material, int pass) {}

void DummyPainter::doStartRender() {}

void DummyPainter::doEndRender() {}

void DummyPainter::setVertices(const MaterialDefinition& material, size_t numVertices, void* vertexData, size_t numIndices, unsigned short* indices) {}

void DummyPainter::drawTriangles(size_t numIndices) {}

void DummyPainter::setViewPort(Rect4i rect, Vector2i renderTargetSize, bool isScreen) {}

void DummyPainter::setClip(Rect4i clip, Vector2i renderTargetSize, bool enable, bool isScreen) {}

void DummyPainter::setMaterialData(const Material& material) {}
