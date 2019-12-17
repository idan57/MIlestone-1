cmake_minimum_required(VERSION 3.15)
project(Milestone_1)

set(CMAKE_CXX_STANDARD 11)
find_package(Threads)
add_executable(Milestone_1 main.cpp Connection/server.cpp Connection/server.h Connection/client.cpp Connection/client.h Commands/Command.cpp Commands/Command.h Commands/OpenDataServer.cpp Commands/OpenDataServer.h Commands/ConnectCommand.cpp Commands/ConnectCommand.h Commands/DefineVarCommand.cpp Commands/DefineVarCommand.h Expressions/Var.cpp Expressions/Var.h "Extra Methods/Extra.cpp" "Extra Methods/Extra.h" Commands/WhileCommand.cpp Commands/WhileCommand.h Commands/PrintCommand.cpp Commands/PrintCommand.h)
target_link_libraries(Milestone_1 ${CMAKE_THREAD_LIBS_INIT})