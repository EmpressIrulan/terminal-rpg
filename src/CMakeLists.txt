# Everything except main.cpp, built as a static library so main.cpp
# stays a thin entry point that links against it. New classes need a
# line here (no glob), so CMake picks up added/removed files on the
# next configure instead of silently going stale.
add_library(terminal-rpg-lib STATIC
    character.cpp
    combatant.cpp
    encounter.cpp
    enemy.cpp
    gui.cpp
    minotaur.cpp
    rng.cpp
    room.cpp
    shop.cpp
    trap.cpp
)

target_include_directories(terminal-rpg-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(terminal-rpg main.cpp)
target_link_libraries(terminal-rpg PRIVATE terminal-rpg-lib)
