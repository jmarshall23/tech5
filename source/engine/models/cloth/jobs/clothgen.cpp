#include "models/cloth/jobs/clothgen.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <limits>

namespace {

constexpr float MIN_CLOTH_DISTANCE_SQUARED = 1.0e-20f;

idVec3 TransformDirection(const idMat3& axis, const idVec3& vector) {
    return axis[0] * vector.x + axis[1] * vector.y + axis[2] * vector.z;
}

idVec3 Normalized(const idVec3& vector,
    const idVec3& fallback = idVec3(0.0f, 0.0f, 1.0f)) {
    const float lengthSquared = vector.LengthSqr();
    return lengthSquared > MIN_CLOTH_DISTANCE_SQUARED
        ? vector * (1.0f / std::sqrt(lengthSquared)) : fallback;
}

void ApplyDistanceConstraint(idClothParticle& first,
    idClothParticle& second, float targetLength, float strength) {
    idVec3 delta = second.origin - first.origin;
    const float distanceSquared = delta.LengthSqr();
    if (distanceSquared <= MIN_CLOTH_DISTANCE_SQUARED ||
        targetLength <= 0.0f) {
        return;
    }
    const float distance = std::sqrt(distanceSquared);
    const float correctionScale =
        (distance - targetLength) / distance * strength;
    const idVec3 correction = delta * correctionScale;
    const bool firstFree = first.anchored == 0;
    const bool secondFree = second.anchored == 0;
    if (firstFree && secondFree) {
        first.origin = first.origin + correction * 0.5f;
        second.origin = second.origin - correction * 0.5f;
    } else if (firstFree) {
        first.origin = first.origin + correction;
    } else if (secondFree) {
        second.origin = second.origin - correction;
    }
}

void ApplyPlaneCollision(idClothParticle& particle, const idPlane& plane,
    float collisionFriction) {
    if (particle.anchored != 0) {
        return;
    }
    const float distance = plane.Distance(particle.origin);
    if (distance >= 0.0f) {
        return;
    }
    const idVec3 correction = plane.Normal() * -distance;
    particle.origin = particle.origin + correction;
    const idVec3 movement = particle.origin - particle.lastOrigin;
    const float normalSpeed = movement.Dot(plane.Normal());
    const idVec3 tangent = movement - plane.Normal() * normalSpeed;
    particle.lastOrigin = particle.origin -
        tangent * (1.0f - (std::max)(0.0f,
            (std::min)(1.0f, collisionFriction)));
}

void ApplyWeaponTraces(clothParms_t& parms) {
    for (int traceIndex = 0; traceIndex < parms.numWeaponTraces;
         ++traceIndex) {
        const clothWeaponTrace_t& trace = parms.weaponTraces[traceIndex];
        const idVec3 end = trace.start + trace.dir;
        const float radiusSquared = trace.strength * trace.strength;
        const idVec3 impulseDirection = Normalized(trace.dir,
            idVec3(0.0f, 0.0f, 0.0f));
        for (int particleIndex = 0;
             particleIndex < parms.numClothParticles; ++particleIndex) {
            idClothParticle& particle = parms.cloth[particleIndex];
            if (!SphereLineIntersection(particle.origin, radiusSquared,
                    trace.start, end)) {
                continue;
            }
            if (trace.causesHoles) {
                particle.state |= 1u;
            }
            if (particle.anchored == 0) {
                particle.origin = particle.origin +
                    impulseDirection * trace.strength;
            }
        }
    }
}

void GenerateParticleAxes(clothParms_t& parms) {
    for (int index = 0; index < parms.numClothParticles; ++index) {
        idClothParticle& particle = parms.cloth[index];
        idVec3 tangent = particle.axis[0];
        idVec3 bitangent = particle.axis[1];
        if (parms.width > 1 && parms.height > 1 &&
            index < parms.width * parms.height) {
            const int row = index / parms.width;
            const int column = index % parms.width;
            const int left = row * parms.width + (std::max)(0, column - 1);
            const int right = row * parms.width +
                (std::min)(parms.width - 1, column + 1);
            const int down = (std::max)(0, row - 1) * parms.width + column;
            const int up = (std::min)(parms.height - 1, row + 1) *
                parms.width + column;
            tangent = parms.cloth[right].origin - parms.cloth[left].origin;
            bitangent = parms.cloth[up].origin - parms.cloth[down].origin;
        } else if (parms.numClothParticles > 1) {
            const int previous = (std::max)(0, index - 1);
            const int next = (std::min)(parms.numClothParticles - 1,
                index + 1);
            tangent = parms.cloth[next].origin -
                parms.cloth[previous].origin;
            idVec3 reference = std::fabs(tangent.z) < 0.9f
                ? idVec3(0.0f, 0.0f, 1.0f)
                : idVec3(0.0f, 1.0f, 0.0f);
            bitangent = reference.Cross(tangent);
        }
        tangent = Normalized(tangent, idVec3(1.0f, 0.0f, 0.0f));
        idVec3 normal = Normalized(tangent.Cross(bitangent));
        bitangent = Normalized(normal.Cross(tangent),
            idVec3(0.0f, 1.0f, 0.0f));
        particle.axis[0] = tangent;
        particle.axis[1] = bitangent;
        particle.axis[2] = normal;
    }
}

void WriteVerticesAndBounds(clothParms_t& parms) {
    if (parms.bounds != nullptr) {
        const float maximum = (std::numeric_limits<float>::max)();
        parms.bounds->b[0].Set(maximum, maximum, maximum);
        parms.bounds->b[1].Set(-maximum, -maximum, -maximum);
    }
    for (int index = 0; index < parms.numClothParticles; ++index) {
        const idClothParticle& particle = parms.cloth[index];
        if (parms.vertices != nullptr) {
            idDrawVert& vertex = parms.vertices[index];
            vertex.xyz = particle.origin;
            vertex.SetNormal(particle.axis[2]);
            vertex.SetTangent(particle.axis[0]);
            vertex.SetBiTangent(particle.axis[1]);
            vertex.color[0] = vertex.color[1] = vertex.color[2] = 255;
            vertex.color[3] = (particle.state & 1u) != 0 ? 0 : 255;
        }
        if (parms.bounds != nullptr) {
            for (int component = 0; component < 3; ++component) {
                parms.bounds->b[0][component] = (std::min)(
                    parms.bounds->b[0][component], particle.origin[component]);
                parms.bounds->b[1][component] = (std::max)(
                    parms.bounds->b[1][component], particle.origin[component]);
            }
        }
    }
    if (parms.bounds != nullptr && parms.numClothParticles == 0) {
        parms.bounds->b[0].Set(0.0f, 0.0f, 0.0f);
        parms.bounds->b[1].Set(0.0f, 0.0f, 0.0f);
    }
}

} // namespace

bool SphereLineIntersection(const idVec3& sphereOrigin,
    float radiusSquared, const idVec3& start, const idVec3& end) {
    const idVec3 segment = end - start;
    const float segmentLengthSquared = segment.LengthSqr();
    float fraction = 0.0f;
    if (segmentLengthSquared > MIN_CLOTH_DISTANCE_SQUARED) {
        fraction = (sphereOrigin - start).Dot(segment) /
            segmentLengthSquared;
        fraction = (std::max)(0.0f, (std::min)(1.0f, fraction));
    }
    const idVec3 closest = start + segment * fraction;
    return (closest - sphereOrigin).LengthSqr() < radiusSquared;
}

void MakeRotationMat(idMat3& orientation, const idVec3& rotationVector,
    float angle) {
    const idVec3 axis = Normalized(rotationVector,
        idVec3(1.0f, 0.0f, 0.0f));
    const float halfAngle = angle * 0.5f;
    const float sine = std::sin(halfAngle);
    const float cosine = std::cos(halfAngle);
    const float x = axis.x * sine;
    const float y = axis.y * sine;
    const float z = axis.z * sine;
    const float xx = 2.0f * x * x;
    const float yy = 2.0f * y * y;
    const float zz = 2.0f * z * z;
    const float xy = 2.0f * x * y;
    const float xz = 2.0f * x * z;
    const float yz = 2.0f * y * z;
    const float xw = 2.0f * x * cosine;
    const float yw = 2.0f * y * cosine;
    const float zw = 2.0f * z * cosine;
    orientation = idMat3(
        1.0f - yy - zz, xy - zw, xz + yw,
        xy + zw, 1.0f - xx - zz, yz - xw,
        xz - yw, yz + xw, 1.0f - xx - yy);
}

void idClothParticle::Reset() {
    origin.Zero();
    lastOrigin.Zero();
    velocity.Zero();
    force.Zero();
    axis = idMat3(1.0f);
    mass = 0.0f;
    std::memset(neighbors, 0, sizeof(neighbors));
    anchored = 0;
    state = 0;
}

bool idClothParticle::Update(float timeDeltaSqr, const idVec3&,
    const idMat3& orientation, const float& friction) {
    if (anchored != 0) {
        force.Zero();
        return false;
    }
    const float inverseMass = mass > 0.0f ? 1.0f / mass : 0.0f;
    velocity = TransformDirection(orientation, force * inverseMass);
    const idVec3 previous = origin;
    origin = origin * (2.0f - friction) -
        lastOrigin * (1.0f - friction) + velocity * timeDeltaSqr;
    lastOrigin = previous;
    force.Zero();
    return true;
}

void idClothParticle::Collide(const idSphere* sphere,
    float radiusSquared) {
    if (sphere == nullptr || anchored != 0) {
        return;
    }
    idVec3 delta = origin - sphere->origin;
    const float distanceSquared = delta.LengthSqr();
    if (distanceSquared >= radiusSquared) {
        return;
    }
    if (distanceSquared <= MIN_CLOTH_DISTANCE_SQUARED) {
        delta.Set(0.0f, 0.0f, 1.0f);
    } else {
        delta = delta * (1.0f / std::sqrt(distanceSquared));
    }
    origin = sphere->origin + delta * sphere->radius;
}

bool idClothParticle::Simulate(float timeDelta, float frictionFactor) {
    if (anchored != 0) {
        return false;
    }
    const idVec3 movement =
        (origin - lastOrigin) * (1.0f - frictionFactor);
    lastOrigin = origin;
    origin = origin + movement + force * (timeDelta * timeDelta);
    return true;
}

idClothSpring::idClothSpring()
    : springLength(0.0f), slSquared(0.0f), friction(0.0f),
      maxLengthMultiplier(0.0f), p1(0), p2(0), band(false), edge(false) {
}

void idClothSpring::Init(float springFriction,
    idClothParticle* particles, int firstParticle, int secondParticle,
    bool isBand, bool isEdge) {
    p1 = firstParticle;
    p2 = secondParticle;
    friction = springFriction;
    band = isBand;
    edge = isEdge;
    springLength = particles != nullptr
        ? (particles[p2].origin - particles[p1].origin).Length() : 0.0f;
    if (band) {
        springLength *= 1.15f;
    }
    slSquared = springLength * springLength;
    maxLengthMultiplier = 0.0f;
}

void idClothSpring::Init2(int firstParticle, int secondParticle,
    float restLength, float springFriction, float lengthMultiplier) {
    p1 = firstParticle;
    p2 = secondParticle;
    springLength = restLength;
    slSquared = restLength * restLength;
    friction = springFriction;
    maxLengthMultiplier = lengthMultiplier;
    band = false;
    edge = false;
}

void idClothSpring::Constrain(idClothParticle* particles) {
    if (particles == nullptr || p1 < 0 || p2 < 0) {
        return;
    }
    ApplyDistanceConstraint(particles[p1], particles[p2], springLength,
        1.0f);
}

void idClothSpring::Constrain2(idClothParticle* particles) {
    if (particles == nullptr || p1 < 0 || p2 < 0) {
        return;
    }
    float targetLength = springLength;
    if (maxLengthMultiplier > 0.0f) {
        const float currentLength =
            (particles[p2].origin - particles[p1].origin).Length();
        if (currentLength <= springLength * maxLengthMultiplier) {
            return;
        }
        targetLength = springLength * maxLengthMultiplier;
    }
    ApplyDistanceConstraint(particles[p1], particles[p2], targetLength,
        0.5f);
}

void RopeGen(clothParms_t& clothParms) {
    ClothGenJob(clothParms);
}

void ClothGenJob(clothParms_t& parms) {
    if (parms.cloth == nullptr || parms.numClothParticles <= 0) {
        WriteVerticesAndBounds(parms);
        return;
    }
    const float timeDelta = (std::max)(0.0f, parms.timeDelta);
    const float timeDeltaSquared = timeDelta * timeDelta;
    for (int index = 0; index < parms.numClothParticles; ++index) {
        idClothParticle& particle = parms.cloth[index];
        const float particleMass = particle.mass > 0.0f
            ? particle.mass : 1.0f;
        particle.force = particle.force + parms.gravity * particleMass;
        particle.force = particle.force + parms.windDirection;
        particle.Update(timeDeltaSquared, parms.org, parms.axis,
            parms.friction);
    }

    ApplyWeaponTraces(parms);
    const int iterations = (std::max)(1, parms.numIterations);
    for (int iteration = 0; iteration < iterations; ++iteration) {
        for (int springIndex = 0; springIndex < parms.numSprings;
             ++springIndex) {
            idClothSpring& spring = parms.springs[springIndex];
            if (spring.maxLengthMultiplier > 0.0f) {
                spring.Constrain2(parms.cloth);
            } else {
                spring.Constrain(parms.cloth);
            }
        }
        for (int particleIndex = 0;
             particleIndex < parms.numClothParticles; ++particleIndex) {
            idClothParticle& particle = parms.cloth[particleIndex];
            for (int collisionIndex = 0;
                 collisionIndex < parms.numCollisions; ++collisionIndex) {
                const idSphere& sphere = parms.collisions[collisionIndex];
                particle.Collide(&sphere, sphere.radius * sphere.radius);
            }
            if (parms.hasCollisionPlane) {
                ApplyPlaneCollision(particle, parms.collisionPlane,
                    parms.collisionFriction);
            }
        }
    }

    GenerateParticleAxes(parms);
    WriteVerticesAndBounds(parms);
}
