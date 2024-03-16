cmake_minimum_required(VERSION 3.17)
project(MelodyV2 VERSION 1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)

add_compile_definitions(_ITERATOR_DEBUG_LEVEL=0)

#if(MSVC)
#add_compile_options(
#		$<$<CONFIG:>:/MT> #---------|
#		$<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
#		$<$<CONFIG:Release>:/MT> #--|
#		$<$<CONFIG:RelWithDebInfo>:/MT> #--|
#)
#endif()

#Get the git diff ID thing and make a compile def for it
EXECUTE_PROCESS(
      COMMAND git rev-parse --short HEAD
      WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
      OUTPUT_VARIABLE "MelodyV2_BUILD_VERSION"
      OUTPUT_STRIP_TRAILING_WHITESPACE)

add_compile_definitions(MelodyV2_BUILD_VERSION=${MelodyV2_BUILD_VERSION})
add_compile_definitions(MelodyV2_BUILD_TAG=0.9.2)
add_compile_definitions(DEBUG_WEB=1)
add_compile_definitions(AUTH_DISABLED=1)
#If you work on the client, add your name here!
add_compile_definitions(MelodyV2_AUTHORS="Tony"
						INJECTOR_BUILD_TAG=0.2
						API_HOST="orionfusion.net"
)

#EnTT config values
add_compile_definitions(ENTT_SPARSE_PAGE=2048)
add_compile_definitions(ENTT_PACKED_PAGE=128)

# Add link options for hot-reloadable targets
add_link_options($<$<CONFIG:Debug>:/INCREMENTAL>)
add_compile_options($<$<CONFIG:Debug>:/Zi>)

add_subdirectory(MelodyV2)
add_subdirectory(Shared)
