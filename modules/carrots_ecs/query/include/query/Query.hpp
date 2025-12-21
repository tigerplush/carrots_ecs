#ifndef CARROTS_ECS_QUERY_QUERY_HPP_
#define CARROTS_ECS_QUERY_QUERY_HPP_

#include <set>
#include <vector>

#include "table/Table.hpp"
#include "world/World.hpp"

#include "Components.hpp"
#include "Filters.hpp"
#include "IQuery.hpp"
#include "QueryIterator.hpp"

namespace CarrotsEcs
{
    namespace Query
    {
        template <typename ComponentQuery, typename FilterQuery = Filters<>>
        class Query;

        using Archetype = CarrotsEcs::Archetype::Archetype;
        using Table = CarrotsEcs::Table::Table;
        using TableId = CarrotsEcs::Table::TableId;
        using World = CarrotsEcs::World::World;
        template<typename... ComponentContent, typename... FilterContent>
        class Query<Components<ComponentContent...>, Filters<FilterContent...>> : public IQuery
        {
        public:
            Query(
                World &t_world
            )
            : m_world(t_world)
            {
                extract_components();
                create_cache();
            }
        public:
            size_t count() const
            {
                return iter().count();
            }

            size_t matching_tables() const
            {
                return m_table_ids.size();
            }
        public:
            /// Returns an iterator over all tuples
            /// @return 
            QueryIterator<ComponentContent...> iter() const
            {
                return QueryIterator<ComponentContent...>
                (
                    std::make_unique<Query<Components<ComponentContent...>, Filters<FilterContent...>>>(*this)
                );
            }
        public:
            const size_t table_count() const override
            {
                return m_table_ids.size();
            }

            const size_t row_count(TableId table_id) const override
            {
                return get_table(table_id).entity_count();
            }

            const Table &get_table(TableId table_id) const override
            {
                return m_world.get_tables()[table_id.id()];
            }
        private:
            void extract_components()
            {
                m_archetype = Archetype::from<ComponentContent...>();
            }

            void create_cache()
            {
                // Go over all tables
                for(auto &[archetype, table_id]: m_world.get_archetypes())
                {
                    #pragma message("With iter().all() this all could be much more readable")
                    // If they do have all the components
                    bool contain_all = true;
                    #pragma message("archetype_index should really be ComponentId")
                    for(auto archetype_index: m_archetype.get_signature())
                    {
                        if(!archetype.contains(archetype_index))
                        {
                            contain_all = false;
                            break;
                        }
                    }
                    if(!contain_all)
                    {
                        continue;
                    }
                    // and all the filters (omitted for now)
                    // add them to our cache
                    m_table_ids.push_back(table_id);
                }
            }

        private:
            World &m_world;
            Archetype m_archetype;
            std::vector<TableId> m_table_ids;
        };
    } // namespace Query
} // namespace CarrotsEcs

#endif