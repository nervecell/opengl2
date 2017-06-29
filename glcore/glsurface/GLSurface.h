//
//  GLSurface.hpp
//  glsurface
//
//  Created by zhuang yusong on 2017/6/11.
//  Copyright © 2017年 zhuang yusong. All rights reserved.
//

#ifndef GLSurface_hpp
#define GLSurface_hpp

#include <vector>
using namespace std;
#include "GLInterval.h"
#include "glclass/GLBuffer.h"
#include "math/Quaternion.hpp"

class GLCORE GLSurface{
    
public:
    
	virtual int getVertexCount();

	virtual int getLineIndexCount();

	virtual int getTriangleIndexCount();
    
    virtual void generateVertices();
    
    virtual void generateLineIndices();
    
    virtual void generateTriangleIndices();
    
	virtual ~GLSurface();
  
public:

	GLBuffer& getVertexBuffer();

	GLBuffer& getIndexBuffer();

	GLBuffer& getTriangleIndexBuffer();

	ivec2 getLowerLeft();

	ivec2 getViewportSize();

	void setLowerLeft(const ivec2& lowerLeft);

	void setViewportSize(const ivec2& viewportSize);

	void setColor(const vec3& color);

	vec3 getColor();

	Quaternion& getOrientation();

	void setOrientation(const Quaternion& orientation);

protected:
    
	vec2 computeDomain(float x, float y);

    void setInterval(const GLInterval& interval);
    
    virtual vec3 evaluate(const vec2& domain);
    
	virtual bool invertNormal(const vec2& domain);
    
protected:
    ivec2 m_slices;
    ivec2 m_divisions;
    vec2 m_upperBound;
    vec2 m_textureCount;

	ivec2 m_lowerLeft;
	ivec2 m_viewportSize;
	vec3 m_color;
	Quaternion m_orientation;

	GLBuffer m_vertexBuffer;
	GLBuffer m_indexBuffer;
	GLBuffer m_triangleIndexBuffer;
	int m_indexCount;
};

#endif /* GLSurface_hpp */
