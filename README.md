Hi, I'm Emily and I'm a bunny girl.
What drives bunnies? Well, carrots of course!
So I proudly present:

# Carrots

An open source, ECS game engine written in c++.

## ECS
ECS stands for Entity - Component - System and it's a different architectural
pattern than common game engines you might know use.

### Component
The heart of the ECS is the Component. A component simply holds data, that's
it, nothing more. To reflect that, Components are usually structs, because
that's the way C used to hold data without adding any functionality to it.
You can still add helper methods and because of C++ virtualization table
almost without any overhead.

For example, you might have a Component
```cpp
struct Position
{
    float x;
    float y;
};
```
and a Component

```cpp
struct Velocity
{
    float x;
    float y;

    float sqr_magnitude()
    {
        return x * x + y * y;
    }
};
```

### System
ECS systems take components and do something with them.
```cpp
void update_position(/*...*/)
{
    // for every position and velocity
    // add velocity * delta_time() to the position
}
```

### Entity
Entities are the glue, that binds components together. It is what in a
conventional game engine you might call an object, but in fact it is
almost nothing more than an id that you can use to look up it's stored
components.

### Why ECS?
ECS is an architectural pattern that favors composition over inheritance, thus
aiming to eliminate or minimize interdependencies. It also utilizes the
architecture of the underlying processor to be faster than a regular game engine.

Imagine in a regular game engine, you might have a Player class and you might
have an Enemy class. In an FPS, they both would have a Position and a Rotation.
They'd also have some kind of currently equipped weapon, current health and
maximum health. They also have animation states and animation state machines.
The Player is controlled directly through inputs, while Enemies are controlled
by some kind of stateful AI, which in turn is even more data.
All this data leads to rather large objects. When the processor needs to update
all enemies, it has to copy them from the heap into the cache, which is a
time-expensive operation. If we cannot load all enemies into the cache, we have
to do it in batches, every load taking up some amount of time.

In ECS, we divide everything up into small, self contained components, that
are only a fraction of the size. Thus we can load more of them into the cache,
apply our system and be done with the update quicker.

ECS also forces us to rethink what components actually belong together.
Instead of applying player input directly to the position, we could apply it
to a movement-intent (like velocity), have enemy AI also apply it to the
movement-intent and then update all positions with movement-intent in one go.

There is also the added benefit of multithreading. Internally, Carrots uses a
`ScheduleExecutor` to check, which systems can be run in parallel. Imagine you
have two systems, both with read-only access to a velocity component and
read/write acces to different components, then these systems can be ran in
parallel, thus improving performance further.

## How to use it

### App API

At the start of the API, your entry point, so to say, stands the `App`.
The most minimal example of carrots you can run is
```cpp
#include <carrots.hpp>
using namespace carrots::prelude;

int main()
{
    App::empty().run();
}
```

This minimal example will create an empty app and run it. When executing this
program, it will return with status code 0 and produce no output.

Keep in mind, that `.run()` returns an `int`, so you could do
```cpp
int main()
{
    return App::empty().run();
}
```
to return the reason, the app has exited. In this case, it would still be 0 for
success, but in larger apps, it makes sense to return the exit code. You can
also provide your own custom exit codes to the app that can be returned by
`.run()`.

An empty app does not help us much, so the most common starting point would be
```cpp
#include <carrots.hpp>
using namespace carrots::prelude;

void startup()
{
    // add initialization of your app here
}

void update()
{
    // update your app here
}

int main()
{
    return App::create()
        .add_plugins(DefaultPlugins)
        .add_system(Startup, startup)
        .add_system(Update, update)
        .run();
}
```

This example will open an empty window, run the `startup()` method once and then
run `update()` until the window is closed or the app execution is canceled.

### Plugin API
Now it might be perfectly reasonable for a small app to have all systems
registered in one file, but for larger projects, this will quickly grow out of
hand, which is why the Plugin API is provided. By inheriting from `IPlugin`,
you can create a sub app, that will pull together components and systems.

Image you have an Adventurers log that other systems can access, you'd create
`adventurers_log_plugin.hpp`
```cpp
#include <string>
#include <vector>

#include <carrots.hpp>
using namespace carrots::prelude;

struct AdventurersLog
{
    std::vector<std::string> log_entries;
};

class AdventurersLogPlugin : public IPlugin
{
public:
    void build(IApp &app) override;
}
```

In `adventurers_log_plugin.cpp`
```cpp
#include <carrots.hpp>
using namespace carrots::prelude;

void setup_log()
{
    // here we inject the log into the app
    // so it exists and everyone can access it
}

void update_log()
{
    // Here we can do things on update, e.g.
    // notify the player when they are close
    // to a current objective
}

void AdventurersLogPlugin::build(IApp &app)
{
    app.add_systems(Startup, setup_log)
        .add_systems(Update, update_log);
}
```

and finally in our `main.cpp`
```cpp
#include <carrots.hpp>
using namespace carrots::prelude;

#include "adventurers_log_plugin.hpp"

int main()
{
    return App::create()
        .add_plugins(DefaultPlugins)
        .add_plugins(AdventurersLogPlugin())
        .run();
}
```

Since plugins are classes, they can also have different helper functions or
constructors. You could have a `CameraPlugin` that takes a `CameraSettings`
struct as it's constructor parameter, making the camera essentially agnostic
to runtime configurations.

#### Default Plugins
By now, you have seen the use of `DefaultPlugins` multiple times. It is a static
const instance of the `DefaultPluginGroup`. It too implements the `IPlugin`
interface and adds the most common plugins to your app, such as creating and
managing a window via the `WindowPlugin`, enabling logs via the `LogPlugin` and
many more.

If you want to run your app headless, you can do that by instead using the
`MinimalPlugins` instance, such as
```cpp
#include <carrots.hpp>
using namespace carrots::prelude;

int main()
{
    return App::create()
        .add_plugins(MinimalPlugins)
        .run();
}
```
This will not open a window and fetch no user input from connected devices, but
still give you an app to run (ideal for systems without HID or displays, such
as servers) with the ability to log information to console.

### Commands API
It is finally time to create entities with a few components. For that, we need a
system, that takes a reference to the `Commands` interface like this:

```cpp
void startup(Commands &commands)
{
}
```
With this, you can then create entities, add components to them or despawn them
entirely. The Commands object will automatically be available throught the App
when you request it in a system, this is called dependency injection.
It is important, that you request a **reference** of Commands, otherwise your
code won't compile. Even if it would, you'd have an implicit copy, fill it with
some commands and then drop it when it goes out of scope, thus loosing all your
queued commands.

Imagine you need an entity with a Position and a Velocity, you'd call `.spawn()`
on your commands reference with these structs.

```cpp
#include <carrots.hpp>
using namespace carrots::prelude;

struct Position
{
    float x;
    float y;
};

struct Velocity
{
    float x;
    float y;
};

void startup(Commands &commands)
{
    // This will create an entity with a Position and a Velocity.
    // C++ initialization still applies, so Position and Velocity
    // will have all their fields set to 0.0f.
    commands.spawn(Position {}, Velocity {});

    // You can also create entities with different values of the same structs
    // This will create an entity with it's Position set to 5.0/5.0 and it's
    // Velocity to 1.0/1.0
    commands.spawn(Position { 5.0f, 5.0f }, Velocity { 1.0f, 1.0f });

    // Now there are two entities with both Position and Velocity
}
```

For more complex Components it's sensible to add constructors to make handling
more easy, but regular C++ rules apply.

Keep in mind, that Commands will be applied **deferred**, meaning that only at
the end of a schedule, these commands will executed. That means if you create
an entity during `Startup` and try to access it during `Startup`, it is not
guaranteed that the entity will exist (it might because systems can be ran in
parallel through the `ScheduleExecutor`, but it is not guaranteed).
It is, however, guaranteed that the entity will exist at the beginning of the
next Schedule (e.g. if you spawn an entity in `Update`, it is guaranteed to
exist in `LateUpdate`).

### Query API
Now that you have seen how to create entities and their components, it is time
to learn how to access them. For that, we use the `Query` interface like this:
```cpp
void update(Query<Components<Position&, const Velocity&>> query)
{
}
```
This might look intimidating, but it's easy to understand once we break it down.
In this example, we request a `Query` from the App, which will automatically
be injected into our system and we query for two Components: a non-const
reference to `Position` and a const reference to `Velocity`.
This means, that when accessing this query, we can change the `Position`
component, but we can never change the `Velocity` component (this is just how
C++ works, I wish it was the other way round. const should be the standard).
At the worst case, this query is empty, so this call will never fail, it might
just not produce any values.

Within this system, we can then access any results for example like this:
```cpp
void update(Query<Components<Position&, const Velocity&>> query)
{
    for(auto [pos, vel]: query.iter())
    {
        pos += vel;
    }
}
```

Calling `.iter()` on a query will return a QueryIterator, which allows us to
unpack the requested tuple into different variables and access them easily.
We can also do fancy stuff on the Iterator like filter for specific predicates
etc, but more on that later.

#### Filters
By now you might have realized, that we specify `Components` for querying them,
when we could just have done `Query<Position&, const Velocity&>`, but there is a
second use case for this syntax. Consider this example:

```cpp
struct Position
{
    /* ... */
};

struct Velocity
{
    /* ... */
};

struct Enemy;

void update(Query<Components<Position&, const Velocity&>, Filters<With<Enemy>>> query)
{
    for(auto [pos, vel]: query.iter())
    {
        pos += vel;
    }
}
```

In this example, we crate a so called unit uype named `Enemy`. It is an empty
struct that holds no data. Think of it as a tag - you can tag entities with unit
structs and then later do operations on them, like filtering.
This example would be similiar to
`Query<Components<Position&, const Velocity&, const Enemy&>`
but since Enemy holds no data, it would just make our query iteration
`for(auto [pos, vel, _enemy]: query.iter())` more complex and less readable.

Keep in mind that filters are evaluated with logic AND, so
`Filters<With<Enemy>, With<Weapon>>` has to be read as "any entity that has an
Enemy component AND a Weapon component". If you want to filter for entities that
have either an Enemy component OR a Weapon component, you have to do
`Filters<Or<With<Enemy>, With<Weapon>>>`.
Of course, you can also filter for non-unit type structs, the `Filters` API is
agnostic to the actual implementation or data a filtered Component might hold.

#### Single variant
Sometimes, you only have a single instance of a set of components, e.g. a
highscore. There will only ever be one highscore during a game. Sure after a
game highscores of previous games might be compared, but during the game or
level, you might only need a single instance of highscore. For these cases,
it would be bothersome to write

```cpp
struct HighScore
{
    int points;
};

void update(Query<Components<HighScore&>> query)
{
    for(auto [highscore]: query.iter())
    {
        /* do something to the highscore */
    }
}
```

because we iterate over a collection that we know has only one entry.
For that case, the `Single` API has been provided:
```cpp
struct HighScore
{
    int points;
};

void update(Single<Components<HighScore&>> single)
{
    HighScore &highscore = single.into_inner();
}
```

It is almost the exact same as the `Query` API, but instead of iterating over
it, you can unpack it's elements by calling `into_inner()`.
If there is more than one result, the `Single` API will throw an `assert` and
the program will abort!

#### Shorthands
There are some functionalities that need to be used over and over, for example
Time.
In a lot of cases, you need to know how much time has passed since the last
frame, e.g. for timer updates or to keep movement logic the same on every
device the app is run.
For these cases there are some shorthands introduced. You can query for the
Time component like this:
```cpp
void update(const Time& time)
{
    INFO << "Since the last frame " << time.delta_time() << "s have passed;
}
```

Internally, this is resolved to `Single<Components<const Time&>>` but you don't
have to write
```cpp
void update(Single<Components<const Time&>> single)
{
    const Time& time = single.into_inner();
    INFO << "Since the last frame " << time.delta_time() << "s have passed;
}
```
in every system you want to use it.