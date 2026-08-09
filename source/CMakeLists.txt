cmake_minimum_required(VERSION 3.25)

set(CMAKE_VS_GLOBALS "VcpkgEnabled=false")
project(tech5 LANGUAGES C CXX)

if(NOT WIN32)
    message(FATAL_ERROR "The recovered idTech 5 PC port currently supports Windows only.")
endif()

if(NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(FATAL_ERROR
        "The recovered Xbox 360 layouts require a Win32 host build. Configure with -A Win32."
    )
endif()

get_filename_component(TECH5_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/.." ABSOLUTE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${TECH5_ROOT}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${TECH5_ROOT}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${TECH5_ROOT}/build/lib")
foreach(config Debug Release RelWithDebInfo MinSizeRel)
    string(TOUPPER "${config}" config_upper)
    set("CMAKE_RUNTIME_OUTPUT_DIRECTORY_${config_upper}" "${TECH5_ROOT}/bin")
    set("CMAKE_LIBRARY_OUTPUT_DIRECTORY_${config_upper}" "${TECH5_ROOT}/bin")
    set("CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${config_upper}"
        "${TECH5_ROOT}/build/lib/${config}"
    )
endforeach()

# This list is intentionally sourced only from the reconstructed tree. The
# Hex-Rays tree is evidence, never compiler input.
file(GLOB_RECURSE IDTECH5_IDLIB_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/shared/idlib/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/shared/idlib/*.h"
)

# These recovered subsystems remain outside the current PC build boundary.
set(IDTECH5_DEFERRED_PATTERNS
    "/analysisclient\."
    "/networking/amqp/"
    "/typeinfo/typeinfofile\.cpp$"
)
foreach(pattern IN LISTS IDTECH5_DEFERRED_PATTERNS)
    list(FILTER IDTECH5_IDLIB_SOURCES EXCLUDE REGEX "${pattern}")
endforeach()

add_library(idLib STATIC ${IDTECH5_IDLIB_SOURCES})
add_library(tech5::idLib ALIAS idLib)
target_include_directories(idLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/shared")
target_compile_features(idLib PUBLIC cxx_std_14)
target_compile_definitions(idLib PRIVATE
    __IDLIB__
    _CRT_SECURE_NO_DEPRECATE
    _CRT_NONSTDC_NO_DEPRECATE
    _USE_32BIT_TIME_T
)
target_link_libraries(idLib PUBLIC ws2_32 psapi)
set_property(TARGET idLib PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)
set_target_properties(idLib PROPERTIES OUTPUT_NAME "idLib")

if(MSVC)
    target_compile_options(idLib PRIVATE
        /MP /W3 /arch:SSE2
        /wd4244 /wd4267 /wd4305 /wd4467 /wd4595 /wd4996
    )
endif()

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "Source"
    FILES ${IDTECH5_IDLIB_SOURCES}
)

# Minimal framework resource ownership needed by recovered engine resources.
set(IDTECH5_FRAMEWORK_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/framework/resource.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/framework/resource.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/framework/resourcelist.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/framework/resourcelist.h"
)

add_library(framework STATIC ${IDTECH5_FRAMEWORK_SOURCES})
add_library(tech5::framework ALIAS framework)
target_include_directories(framework PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/engine"
    "${CMAKE_CURRENT_SOURCE_DIR}/shared"
)
target_compile_features(framework PUBLIC cxx_std_14)
target_compile_definitions(framework PRIVATE
    _CRT_SECURE_NO_DEPRECATE
    _CRT_NONSTDC_NO_DEPRECATE
    _USE_32BIT_TIME_T
)
target_link_libraries(framework PUBLIC tech5::idLib)
set_property(TARGET framework PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)
if(MSVC)
    target_compile_options(framework PRIVATE
        /MP /W3 /arch:SSE2
        /wd4244 /wd4267 /wd4305 /wd4467 /wd4595 /wd4996
    )
endif()
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "Source"
    FILES ${IDTECH5_FRAMEWORK_SOURCES}
)

# Recovered declaration/resource system. Only manually reconstructed sources
# are compiler inputs; the Hex-Rays tree remains implementation evidence.
file(GLOB_RECURSE IDTECH5_DECL_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/decls/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/decls/*.h"
)

add_library(decls STATIC ${IDTECH5_DECL_SOURCES})
add_library(tech5::decls ALIAS decls)
target_include_directories(decls PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/engine"
    "${CMAKE_CURRENT_SOURCE_DIR}/shared"
)
target_compile_features(decls PUBLIC cxx_std_14)
target_compile_definitions(decls PRIVATE
    _CRT_SECURE_NO_DEPRECATE
    _CRT_NONSTDC_NO_DEPRECATE
    _USE_32BIT_TIME_T
)
target_link_libraries(decls PUBLIC tech5::framework tech5::idLib)
set_property(TARGET decls PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)
set_target_properties(decls PROPERTIES OUTPUT_NAME "decls")
if(MSVC)
    target_compile_options(decls PRIVATE
        /MP /W3 /arch:SSE2
        /wd4244 /wd4267 /wd4305 /wd4467 /wd4595 /wd4996
    )
endif()
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "Source"
    FILES ${IDTECH5_DECL_SOURCES}
)

# Collision model recovery is a separate engine library. As with idLib and
# GameLib, only reconstructed files under source/ are compiler inputs.
file(GLOB_RECURSE IDTECH5_CM_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/cm/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/cm/*.h"
)

add_library(cm STATIC ${IDTECH5_CM_SOURCES})
add_library(tech5::cm ALIAS cm)
target_include_directories(cm PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/engine"
    "${CMAKE_CURRENT_SOURCE_DIR}/shared"
)
target_compile_features(cm PUBLIC cxx_std_14)
target_compile_definitions(cm PRIVATE
    _CRT_SECURE_NO_DEPRECATE
    _CRT_NONSTDC_NO_DEPRECATE
    _USE_32BIT_TIME_T
)
target_link_libraries(cm PUBLIC tech5::framework tech5::idLib)
set_property(TARGET cm PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)
set_target_properties(cm PROPERTIES OUTPUT_NAME "cm")

if(MSVC)
    target_compile_options(cm PRIVATE
        /MP /W3 /arch:SSE2
        /wd4244 /wd4267 /wd4305 /wd4467 /wd4595 /wd4996
    )
endif()

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "Source"
    FILES ${IDTECH5_CM_SOURCES}
)

# Recovered AAS2 file/resource layer.  The decompiler tree remains evidence;
# only the manually reconstructed PC sources below are compiled.
file(GLOB_RECURSE IDTECH5_AAS2FILE_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/aas2file/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/aas2file/*.h"
)

add_library(aas2file STATIC ${IDTECH5_AAS2FILE_SOURCES})
add_library(tech5::aas2file ALIAS aas2file)
target_include_directories(aas2file PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/engine"
    "${CMAKE_CURRENT_SOURCE_DIR}/shared"
)
target_compile_features(aas2file PUBLIC cxx_std_14)
target_compile_definitions(aas2file PRIVATE
    _CRT_SECURE_NO_DEPRECATE
    _CRT_NONSTDC_NO_DEPRECATE
    _USE_32BIT_TIME_T
)
target_link_libraries(aas2file PUBLIC tech5::framework tech5::idLib)
set_property(TARGET aas2file PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)
set_target_properties(aas2file PROPERTIES OUTPUT_NAME "aas2file")
if(MSVC)
    target_compile_options(aas2file PRIVATE
        /MP /W3 /arch:SSE2
        /wd4244 /wd4267 /wd4305 /wd4467 /wd4595 /wd4996
    )
endif()
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "Source"
    FILES ${IDTECH5_AAS2FILE_SOURCES}
)

# GameLib follows the same evidence boundary as idLib: only reconstructed
# files under source/ are compiler inputs. The Hex-Rays tree is never built.
file(GLOB_RECURSE IDTECH5_GAMELIB_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/gamelib/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/gamelib/*.h"
)

add_library(gameLib STATIC ${IDTECH5_GAMELIB_SOURCES})
add_library(tech5::gameLib ALIAS gameLib)
target_include_directories(gameLib PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/engine"
    "${CMAKE_CURRENT_SOURCE_DIR}/shared"
)
target_compile_features(gameLib PUBLIC cxx_std_14)
target_compile_definitions(gameLib PRIVATE
    _CRT_SECURE_NO_DEPRECATE
    _CRT_NONSTDC_NO_DEPRECATE
    _USE_32BIT_TIME_T
)
target_link_libraries(gameLib PUBLIC
    tech5::decls tech5::aas2file tech5::cm tech5::idLib
)
set_property(TARGET gameLib PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)
set_target_properties(gameLib PROPERTIES OUTPUT_NAME "gameLib")

if(MSVC)
    target_compile_options(gameLib PRIVATE
        /MP /W3 /arch:SSE2
        /wd4244 /wd4267 /wd4305 /wd4467 /wd4595 /wd4996
    )
endif()

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "Source"
    FILES ${IDTECH5_GAMELIB_SOURCES}
)
