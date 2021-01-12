cmake_minimum_required(VERSION 3.16)
project(maman_23_preprocessor C)

set(CMAKE_C_STANDARD 90)

add_executable(maman_23_preprocessor preprocessor.c file_setup_util.c file_setup_util.h comment_remover.c comment_remover.h header_writer.c header_writer.h errors.h input_test_1.c)