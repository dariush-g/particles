#pragma once
#include <cstddef>

static constexpr size_t MAX_PARTICLES = 100000;

struct ParticleSystem {
  alignas(32) float pos_x[MAX_PARTICLES];
  alignas(32) float pos_y[MAX_PARTICLES];
  alignas(32) float pos_z[MAX_PARTICLES];

  alignas(32) float vel_x[MAX_PARTICLES];
  alignas(32) float vel_y[MAX_PARTICLES];
  alignas(32) float vel_z[MAX_PARTICLES];

  alignas(32) float force_x[MAX_PARTICLES];
  alignas(32) float force_y[MAX_PARTICLES];
  alignas(32) float force_z[MAX_PARTICLES];

  size_t count;

  void init(size_t num_particles);
  void apply_forces(float dt);
  void integrate(float dt);
  void update(float dt);
};
