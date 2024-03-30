project(coding_warmup)

file(GLOB C_SOURCES "*.c")  # Find all .c files

find_package(ZLIB REQUIRED)

set(CMAKE_C_STANDARD_LIBRARIES "-lpthread")
set(CMAKE_C_STANDARD_LIBRARIES "-lz")

foreach(SOURCE ${C_SOURCES})
  get_filename_component(TARGET_NAME ${SOURCE} NAME_WE)  # Extract filename without extension
  add_executable(${TARGET_NAME} ${SOURCE})
  set_property(TARGET ${TARGET_NAME} PROPERTY RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")  # Set output to 'bin' subdirectory
endforeach(SOURCE)

