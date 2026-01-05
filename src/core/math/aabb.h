#pragma once

#include <glm/ext/vector_float3.hpp>
#include <glm/glm.hpp>

inline bool point_in_aabb(const glm::vec3 &p, const glm::vec3 &min,
			  const glm::vec3 &max) {
  return glm::all(glm::greaterThanEqual(p, min)) &&
	 glm::all(glm::lessThanEqual(p, max));
}
