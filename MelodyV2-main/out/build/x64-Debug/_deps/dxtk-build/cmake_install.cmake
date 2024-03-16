# Install script for directory: C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src

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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/lib/DirectXTK.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/directxtk/DirectXTK-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/directxtk/DirectXTK-targets.cmake"
         "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-build/CMakeFiles/Export/a11a99d19d8d3c8432b0fa94ef825414/DirectXTK-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/directxtk/DirectXTK-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/directxtk/DirectXTK-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/directxtk" TYPE FILE FILES "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-build/CMakeFiles/Export/a11a99d19d8d3c8432b0fa94ef825414/DirectXTK-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/directxtk" TYPE FILE FILES "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-build/CMakeFiles/Export/a11a99d19d8d3c8432b0fa94ef825414/DirectXTK-targets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/directxtk" TYPE FILE FILES
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/BufferHelpers.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/CommonStates.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/DDSTextureLoader.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/DirectXHelpers.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/Effects.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/GeometricPrimitive.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/GraphicsMemory.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/Model.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/PostProcess.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/PrimitiveBatch.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/ScreenGrab.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/SpriteBatch.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/SpriteFont.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/VertexTypes.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/WICTextureLoader.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/GamePad.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/Keyboard.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/Mouse.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/SimpleMath.h"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/SimpleMath.inl"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-src/Inc/Audio.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/directxtk" TYPE FILE FILES
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-build/directxtk-config.cmake"
    "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-build/directxtk-config-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/dxtk-build/DirectXTK.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/bin/xwbtool.exe")
endif()

