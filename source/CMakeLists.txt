cmake_minimum_required(VERSION 3.25)

# User-wide Visual Studio vcpkg integration is not part of the recovered
# engine dependency boundary.
set(CMAKE_VS_GLOBALS "VcpkgEnabled=false")

project(tech5 LANGUAGES C CXX)

if(NOT WIN32)
    message(FATAL_ERROR "The recovered idTech 5 host build supports Windows only.")
endif()

if(NOT MSVC)
    message(FATAL_ERROR "The recovered idTech 5 host build currently requires MSVC.")
endif()

if(NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(FATAL_ERROR
        "The recovered Xbox 360 layouts require a Win32 host build. "
        "Configure Visual Studio with -A Win32."
    )
endif()

include(CMakeParseArguments)

get_filename_component(TECH5_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/.." ABSOLUTE)
set(TECH5_SOURCE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")

option(TECH5_ENABLE_DEFERRED_IDLIB
    "Compile the recovery-only analysis client and AMQP idLib units" OFF
)
option(TECH5_ENABLE_INCOMPLETE_GUI
    "Compile the SWF/GUI subsystem, which is not compile-clean yet" OFF
)
option(TECH5_BUILD_STANDALONE_LINKCHECK
    "Create an opt-in executable that forces every engine object through the linker" ON
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${TECH5_ROOT}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${TECH5_ROOT}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
foreach(config Debug Release RelWithDebInfo MinSizeRel)
    string(TOUPPER "${config}" config_upper)
    set("CMAKE_RUNTIME_OUTPUT_DIRECTORY_${config_upper}" "${TECH5_ROOT}/bin")
    set("CMAKE_LIBRARY_OUTPUT_DIRECTORY_${config_upper}" "${TECH5_ROOT}/bin")
    set("CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${config_upper}"
        "${CMAKE_BINARY_DIR}/lib/${config}"
    )
endforeach()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_library(tech5_build_options INTERFACE)
target_include_directories(tech5_build_options INTERFACE
    "${TECH5_SOURCE_ROOT}"
    "${TECH5_SOURCE_ROOT}/engine"
    "${TECH5_SOURCE_ROOT}/shared"
    "${TECH5_SOURCE_ROOT}/shared/idlib"
    "${TECH5_SOURCE_ROOT}/libs"
)
target_compile_definitions(tech5_build_options INTERFACE
    _CRT_SECURE_NO_DEPRECATE
    _CRT_NONSTDC_NO_DEPRECATE
    _USE_32BIT_TIME_T
    NOMINMAX
    WIN32_LEAN_AND_MEAN
)
target_compile_options(tech5_build_options INTERFACE
    "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/MP;/W3;/arch:SSE2;/bigobj;/wd4244;/wd4267;/wd4305;/wd4467;/wd4595;/wd4996>"
)

add_library(tech5_windows INTERFACE)
target_link_libraries(tech5_windows INTERFACE
    advapi32
    d3d9
    d3dcompiler
    dbghelp
    dinput8
    dxguid
    gdi32
    iphlpapi
    ole32
    opengl32
    psapi
    shell32
    user32
    wbemuuid
    windowscodecs
    winmm
    ws2_32
    wsock32
    xaudio2
    xinput
)

# Each component has an object target for the whole-engine link audit and a
# static wrapper that preserves the recovery project's existing target names.
set(TECH5_COMPONENT_OBJECTS)
set(TECH5_COMPONENT_TARGETS)

function(tech5_add_component target)
    set(one_value_args CXX_STANDARD OUTPUT_NAME)
    set(multi_value_args SOURCES DEPENDENCIES COMPILE_DEFINITIONS)
    cmake_parse_arguments(COMP "" "${one_value_args}" "${multi_value_args}" ${ARGN})

    if(NOT COMP_SOURCES)
        message(FATAL_ERROR "Component ${target} has no sources")
    endif()
    if(NOT COMP_CXX_STANDARD)
        set(COMP_CXX_STANDARD 14)
    endif()
    if(NOT COMP_OUTPUT_NAME)
        set(COMP_OUTPUT_NAME "${target}")
    endif()

    add_library(${target}_objects OBJECT ${COMP_SOURCES})
    target_link_libraries(${target}_objects PUBLIC tech5_build_options)
    target_compile_features(${target}_objects PUBLIC cxx_std_${COMP_CXX_STANDARD})
    if(COMP_COMPILE_DEFINITIONS)
        target_compile_definitions(${target}_objects PRIVATE
            ${COMP_COMPILE_DEFINITIONS}
        )
    endif()
    set_property(TARGET ${target}_objects PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
    )
    set_target_properties(${target}_objects PROPERTIES
        FOLDER "Engine/Object Libraries"
    )

    add_library(${target} STATIC $<TARGET_OBJECTS:${target}_objects>)
    add_library(tech5::${target} ALIAS ${target})
    target_link_libraries(${target} PUBLIC
        tech5_build_options
        ${COMP_DEPENDENCIES}
    )
    target_compile_features(${target} PUBLIC cxx_std_${COMP_CXX_STANDARD})
    set_property(TARGET ${target} PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
    )
    set_target_properties(${target} PROPERTIES
        OUTPUT_NAME "${COMP_OUTPUT_NAME}"
        FOLDER "Engine/Components"
    )

    source_group(TREE "${TECH5_SOURCE_ROOT}" PREFIX "Source"
        FILES ${COMP_SOURCES}
    )

    set(component_objects ${TECH5_COMPONENT_OBJECTS})
    list(APPEND component_objects "$<TARGET_OBJECTS:${target}_objects>")
    set(TECH5_COMPONENT_OBJECTS "${component_objects}" PARENT_SCOPE)

    set(component_targets ${TECH5_COMPONENT_TARGETS})
    list(APPEND component_targets ${target})
    set(TECH5_COMPONENT_TARGETS "${component_targets}" PARENT_SCOPE)
endfunction()

# Reconstructed sources are compiler input. The Hex-Rays tree remains evidence
# and is deliberately never added to a target.
file(GLOB_RECURSE IDTECH5_IDLIB_SOURCES CONFIGURE_DEPENDS
    "${TECH5_SOURCE_ROOT}/shared/idlib/*.cpp"
    "${TECH5_SOURCE_ROOT}/shared/idlib/*.h"
)
# The host is Win32. Xenon files are recovery evidence and, when compiled on
# Windows, provide duplicate networking/memory symbols rather than a second
# supported platform backend.
list(FILTER IDTECH5_IDLIB_SOURCES EXCLUDE REGEX "/sys/xenon/")
if(NOT TECH5_ENABLE_DEFERRED_IDLIB)
    list(FILTER IDTECH5_IDLIB_SOURCES EXCLUDE REGEX "/analysisclient\\.")
    list(FILTER IDTECH5_IDLIB_SOURCES EXCLUDE REGEX "/networking/amqp/")
endif()

file(GLOB_RECURSE IDTECH5_FRAMEWORK_SOURCES CONFIGURE_DEPENDS
    "${TECH5_SOURCE_ROOT}/engine/framework/*.cpp"
    "${TECH5_SOURCE_ROOT}/engine/framework/*.h"
)
file(GLOB_RECURSE IDTECH5_DECL_SOURCES CONFIGURE_DEPENDS
    "${TECH5_SOURCE_ROOT}/engine/decls/*.cpp"
    "${TECH5_SOURCE_ROOT}/engine/decls/*.h"
)
file(GLOB_RECURSE IDTECH5_MAPFILE_SOURCES CONFIGURE_DEPENDS
    "${TECH5_SOURCE_ROOT}/engine/mapfile/*.cpp"
    "${TECH5_SOURCE_ROOT}/engine/mapfile/*.h"
)
file(GLOB_RECURSE IDTECH5_CM_SOURCES CONFIGURE_DEPENDS
    "${TECH5_SOURCE_ROOT}/engine/cm/*.cpp"
    "${TECH5_SOURCE_ROOT}/engine/cm/*.h"
)
file(GLOB_RECURSE IDTECH5_AAS2FILE_SOURCES CONFIGURE_DEPENDS
    "${TECH5_SOURCE_ROOT}/engine/aas2file/*.cpp"
    "${TECH5_SOURCE_ROOT}/engine/aas2file/*.h"
)
file(GLOB_RECURSE IDTECH5_GAMELIB_SOURCES CONFIGURE_DEPENDS
    "${TECH5_SOURCE_ROOT}/engine/gamelib/*.cpp"
    "${TECH5_SOURCE_ROOT}/engine/gamelib/*.h"
)
file(GLOB_RECURSE IDTECH5_NETWORK_SOURCES CONFIGURE_DEPENDS
    "${TECH5_SOURCE_ROOT}/engine/network/*.cpp"
    "${TECH5_SOURCE_ROOT}/engine/network/*.h"
)
file(GLOB_RECURSE IDTECH5_MODEL_SOURCES CONFIGURE_DEPENDS
    "${TECH5_SOURCE_ROOT}/engine/models/*.cpp"
    "${TECH5_SOURCE_ROOT}/engine/models/*.h"
)
list(FILTER IDTECH5_MODEL_SOURCES EXCLUDE REGEX "/models/tests/")
file(GLOB_RECURSE IDTECH5_RENDERER_SOURCES CONFIGURE_DEPENDS
    "${TECH5_SOURCE_ROOT}/engine/renderer/*.cpp"
    "${TECH5_SOURCE_ROOT}/engine/renderer/*.h"
)
file(GLOB_RECURSE IDTECH5_SOUND_SOURCES CONFIGURE_DEPENDS
    "${TECH5_SOURCE_ROOT}/engine/sound/*.cpp"
    "${TECH5_SOURCE_ROOT}/engine/sound/*.h"
)
file(GLOB_RECURSE IDTECH5_SYS_SOURCES CONFIGURE_DEPENDS
    "${TECH5_SOURCE_ROOT}/engine/sys/*.cpp"
    "${TECH5_SOURCE_ROOT}/engine/sys/*.h"
)
list(FILTER IDTECH5_SYS_SOURCES EXCLUDE REGEX "/sys/xenon/")
file(GLOB_RECURSE IDTECH5_GUI_SOURCES CONFIGURE_DEPENDS
    "${TECH5_SOURCE_ROOT}/engine/guis/*.cpp"
    "${TECH5_SOURCE_ROOT}/engine/guis/*.h"
)

tech5_add_component(idLib
    SOURCES ${IDTECH5_IDLIB_SOURCES}
    CXX_STANDARD 14
    OUTPUT_NAME idLib
    COMPILE_DEFINITIONS __IDLIB__
)
target_link_libraries(idLib PUBLIC tech5_windows)

tech5_add_component(framework
    SOURCES ${IDTECH5_FRAMEWORK_SOURCES}
    DEPENDENCIES tech5::idLib
)
tech5_add_component(decls
    SOURCES ${IDTECH5_DECL_SOURCES}
    DEPENDENCIES tech5::framework tech5::idLib
)
tech5_add_component(mapfile
    SOURCES ${IDTECH5_MAPFILE_SOURCES}
    DEPENDENCIES tech5::decls tech5::framework tech5::idLib
)
tech5_add_component(cm
    SOURCES ${IDTECH5_CM_SOURCES}
    DEPENDENCIES tech5::framework tech5::idLib
)
tech5_add_component(aas2file
    SOURCES ${IDTECH5_AAS2FILE_SOURCES}
    DEPENDENCIES tech5::framework tech5::idLib
)
tech5_add_component(gameLib
    SOURCES ${IDTECH5_GAMELIB_SOURCES}
    DEPENDENCIES
        tech5::decls
        tech5::aas2file
        tech5::cm
        tech5::mapfile
        tech5::idLib
    OUTPUT_NAME gameLib
)
tech5_add_component(network
    SOURCES ${IDTECH5_NETWORK_SOURCES}
    DEPENDENCIES tech5::framework tech5::idLib
)

# One reconstructed model unit uses std::clamp. Keeping models on C++17 lets
# the legacy system layer retain std::auto_ptr under C++14.
tech5_add_component(models
    SOURCES ${IDTECH5_MODEL_SOURCES}
    DEPENDENCIES tech5::decls tech5::framework tech5::idLib
    CXX_STANDARD 17
)
tech5_add_component(renderer
    SOURCES ${IDTECH5_RENDERER_SOURCES}
    DEPENDENCIES tech5::decls tech5::framework tech5::idLib
)
tech5_add_component(sound
    SOURCES ${IDTECH5_SOUND_SOURCES}
    DEPENDENCIES tech5::decls tech5::framework tech5::idLib
)
tech5_add_component(sys
    SOURCES ${IDTECH5_SYS_SOURCES}
    DEPENDENCIES
        tech5::network
        tech5::sound
        tech5::renderer
        tech5::framework
        tech5::idLib
)

if(TECH5_ENABLE_INCOMPLETE_GUI)
    tech5_add_component(guis
        SOURCES ${IDTECH5_GUI_SOURCES}
        DEPENDENCIES
            tech5::renderer
            tech5::sound
            tech5::framework
            tech5::idLib
    )
else()
    message(STATUS
        "SWF/GUI is excluded: configure with "
        "-DTECH5_ENABLE_INCOMPLETE_GUI=ON to expose its current compile errors."
    )
endif()

# The aggregate archive is useful to future game/tool consumers. Static
# archives permit unresolved references, so tech5_engine_linkcheck below is
# the authoritative link-completeness gate.
add_library(tech5_engine STATIC ${TECH5_COMPONENT_OBJECTS})
add_library(tech5::engine ALIAS tech5_engine)
target_link_libraries(tech5_engine PUBLIC
    tech5_build_options
    tech5_windows
)
target_compile_features(tech5_engine PUBLIC cxx_std_17)
set_target_properties(tech5_engine PROPERTIES
    OUTPUT_NAME tech5_engine
    FOLDER "Engine"
)

add_custom_target(tech5_compile_ready
    DEPENDS tech5_engine ${TECH5_COMPONENT_TARGETS}
)
set_target_properties(tech5_compile_ready PROPERTIES FOLDER "Engine")

if(TECH5_BUILD_STANDALONE_LINKCHECK)
    add_executable(tech5_engine_linkcheck WIN32 EXCLUDE_FROM_ALL
        "${TECH5_SOURCE_ROOT}/engine/standalone/engine_game_stub.cpp"
        "${TECH5_SOURCE_ROOT}/engine/standalone/engine_gamelib_stub.cpp"
        ${TECH5_COMPONENT_OBJECTS}
    )
    target_link_libraries(tech5_engine_linkcheck PRIVATE
        tech5_build_options
        tech5_windows
    )
    target_compile_features(tech5_engine_linkcheck PRIVATE cxx_std_14)
    target_link_options(tech5_engine_linkcheck PRIVATE /INCREMENTAL:NO)
    set_property(TARGET tech5_engine_linkcheck PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
    )
    set_target_properties(tech5_engine_linkcheck PROPERTIES
        OUTPUT_NAME tech5_engine_linkcheck
        FOLDER "Engine/Audit"
    )
endif()

message(STATUS "tech5 source boundary: ${TECH5_SOURCE_ROOT}")
message(STATUS "tech5 archive output: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
