# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/menum-src"
  "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/menum-build"
  "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/menum-subbuild/menum-populate-prefix"
  "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/menum-subbuild/menum-populate-prefix/tmp"
  "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/menum-subbuild/menum-populate-prefix/src/menum-populate-stamp"
  "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/menum-subbuild/menum-populate-prefix/src"
  "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/menum-subbuild/menum-populate-prefix/src/menum-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/menum-subbuild/menum-populate-prefix/src/menum-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/tony/Downloads/OrionFusion-Cmake/MelodyV2-main/out/build/x64-Debug/_deps/menum-subbuild/menum-populate-prefix/src/menum-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
