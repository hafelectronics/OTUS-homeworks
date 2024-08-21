cmake_minimum_required(VERSION 3.5)
cmake -G "Visual Studio 16 2019" .. -DBoost_DEBUG=ON
set (BOOST_ROOT "C:/win64libs/boost/") # Путь к библиотеке Boost
set (CMAKE_CXX_STANDARD 20) 
set (Boost_NO_SYSTEM_PATHS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME OFF)
set (BOOST_ALL_DYN_LINK OFF)


# Подключаем необходимые модули. Для примера подключим program_options
find_package (Boost REQUIRED COMPONENTS program_options REQUIRED) 
  
# Если библиотека найдена, то
if (Boost_FOUND)
    include_directories (SYSTEM ${Boost_INCLUDE_DIR}) # подключаем заголовочные файлы
    add_executable (Boost_test "main.cpp") # Создаем исполняемый файл для нашего проекта
    target_link_libraries (Boost_test ${Boost_LIBRARIES}) # подключаем библиотеку
endif ()


set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VESRION})

# find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)
add_library(helloworld lib.cpp)
add_executable(test_version test_version.cpp)

set_target_properties(helloworld_cli helloworld test_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
# target_include_directories(helloworld
#     PRIVATE "${CMAKE_BINARY_DIR}"
# )
# set_target_properties(test_version PROPERTIES
#     COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#     INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
# )

# target_link_libraries(helloworld_cli PRIVATE
#     helloworld
# )
# target_link_libraries(test_version
#     ${Boost_LIBRARIES}
#     helloworld
# )

# if (MSVC)
#     target_compile_options(helloworld_cli PRIVATE
#         /W4
#     )
#     target_compile_options(helloworld PRIVATE
#         /W4
#     )
#     target_compile_options(test_version PRIVATE
#         /W4
#     )
# else ()
#     target_compile_options(helloworld_cli PRIVATE
#         -Wall -Wextra -pedantic -Werror
#     )
#     target_compile_options(helloworld PRIVATE
#         -Wall -Wextra -pedantic -Werror
#     )
#     target_compile_options(test_version PRIVATE
#         -Wall -Wextra -pedantic -Werror
#     )
# endif()



# install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

# set(CPACK_GENERATOR DEB)

# set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
# set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

# set(CPACK_PACKAGE_CONTACT example@example.com)

# include(CPack)

# enable_testing()

# add_test(test_version test_version)
