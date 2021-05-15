add_library(buffer SHARED buffer.cpp)

if (ARM_BUILD)
    INSTALL(TARGETS buffer DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
endif()