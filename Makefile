##
# KKToken-Client
#
# @file
# @version 0.1

PROJECT_ROOT_DIR = .
CMAKE_BUILD_DIR = cmake-build-debug

build-cmake:
	cmake -S $(PROJECT_ROOT_DIR) -B $(CMAKE_BUILD_DIR)
	ln -s $(CMAKE_BUILD_DIR)/compile_commands.json $(PROJECT_ROOT_DIR) # Creates link for ccls
# end
