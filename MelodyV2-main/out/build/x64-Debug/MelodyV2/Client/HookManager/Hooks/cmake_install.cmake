# Install script for directory: C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/MelodyV2/Client/HookManager/Hooks

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/MelodyV2/Client/HookManager/Hooks/Actor/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/MelodyV2/Client/HookManager/Hooks/DirectX/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/MelodyV2/Client/HookManager/Hooks/GameMode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/MelodyV2/Client/HookManager/Hooks/Key/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/MelodyV2/Client/HookManager/Hooks/MinecraftUIRenderContext/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/MelodyV2/Client/HookManager/Hooks/Mob/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/MelodyV2/Client/HookManager/Hooks/Others/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/MelodyV2/Client/HookManager/Hooks/ScreenView/cmake_install.cmake")
endif()

