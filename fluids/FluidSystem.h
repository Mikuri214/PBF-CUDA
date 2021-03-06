#pragma once
#include "Simulator.h"
#include "Renderer.h"
#include "ParticleSource.h"

#include <GLFW\glfw3.h>

class FluidSystem
{
public:

	FluidSystem();
	~FluidSystem();

	void initSource();
	void stepSource();
	void stepSimulate();
	void render();

	void setFluidSource();
	void setDt(float);

	void reset();
private:

	/* Working components */
	ParticleSource *m_source;
	Simulator *m_simulator;
	Renderer  *m_renderer;

	/* Parameters */
	float s_dt;
	float s_h;

	/* Particles states */

	/* position: float3 GLBuffer */
	GLuint d_pos, d_npos;
	/* velocity: float3 GLBuffer */
	GLuint d_vel, d_nvel;
	/* initial id: uint GLBuffer */
	GLuint d_iid;

	/* tic: d_pos, toc: d_npos for rendering */
	bool m_tictoc, m_nextFrame;
	int  m_nparticle;

	/* Moving boundary */
	float3 m_ulim, m_llim;
	float3 m_A_ulim, m_A_llim;
	float m_w;
};

