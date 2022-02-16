cmake_minimum_required(VERSION 3.20)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(libft)

#add_executable(src/main.c
#                src/long_sort.c
#                src/short_sort.c
#                src/sort_array.c
#                src/lst_utils/new_node.c
#                src/lst_utils/commands.c
#                src/lst_utils/free_list.c
#                src/algo_utils/search.c
#                src/algo_utils/exit.c
#                src/algo_utils/is_sorted.c
#                src/parse_string/string_utils.c
#                src/checker_bonus/correct_enter.)

add_executable(push_swap src/checker_bonus/checker.c
                src/checker_bonus/cmd_reader.c
        src/checker_bonus/get_next_line.c
src/lst_utils/commands.c
src/lst_utils/free_list.c
src/lst_utils/new_node.c
src/algo_utils/exit.c
src/algo_utils/is_sorted.c
src/sort_array.c
src/parse_string/string_utils.c
src/checker_bonus/correct_enter.c
src/checker_bonus/commands_c.c src/checker_bonus/gnl_utils.c)

target_link_libraries(push_swap libft)
