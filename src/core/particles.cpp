#include "particles.h"
#include <cstddef>
#include <random>

void ParticleSystem::init(size_t num_particles) {
  count = num_particles;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<float> dist(-1.0f, 1.0f);

  for (size_t i = 0; i < count; ++i) {
    pos_x[i] = dist(gen) * 10.0f;
    pos_y[i] = dist(gen) * 10.0f;
    pos_z[i] = dist(gen) * 10.0f;

    vel_x[i] = vel_y[i] = vel_z[i] = 0.0f;
    force_x[i] = vel_y[i] = vel_z[i] = 0.0f;
  }
}

void ParticleSystem::apply_forces(float dt) {
  for (size_t i = 0; i < count; ++i) {
    force_y[i] += -9.8f;

    force_x[i] += -0.1f * vel_x[i];
    force_y[i] += -0.1f * vel_y[i];
    force_z[i] += -0.1f * vel_z[i];
  }
}

void ParticleSystem::integrate(float dt) {
  for (size_t i = 0; i < count; i++) {
    vel_x[i] += force_x[i] * dt;
    vel_y[i] += force_y[i] * dt;
    vel_z[i] += force_z[i] * dt;

    pos_x[i] += vel_x[i] * dt;
    pos_y[i] += vel_y[i] * dt;
    pos_z[i] += vel_z[i] * dt;

    force_x[i] = force_y[i] = force_z[i] = 0.0f;
  }
}

void ParticleSystem::update(float dt) {
  apply_forces(dt);
  integrate(dt);
}
