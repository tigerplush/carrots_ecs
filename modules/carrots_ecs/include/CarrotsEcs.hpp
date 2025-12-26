#ifndef CARROTS_ECS_HPP_
#define CARROTS_ECS_HPP_

#include "archetype/Archetype.hpp"
#include "component/ComponentId.hpp"
#include "entity/Entity.hpp"
#include "query/Query.hpp"
#include "schedule/Schedule.hpp"
#include "table/Table.hpp"
#include "world/World.hpp"

namespace CarrotsEcs
{
    using namespace CarrotsEcs::Archetype;
    using namespace CarrotsEcs::Component;
    using namespace CarrotsEcs::Entity;
    using namespace CarrotsEcs::Query;
    using namespace CarrotsEcs::Schedule;
    using namespace CarrotsEcs::Table;
    using namespace CarrotsEcs::World;
} // namespace CarrotsEcs


#endif
