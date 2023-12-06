#!/bin/bash

# 특정 디렉토리 경로
base_directory="./cpp_42/cpp02"

# 현재 디렉토리 경로
current_directory=$(pwd)

# 특정 명령어
command_to_execute="make"
command_to_execute2="make fclean"

# find 명령어를 사용하여 디렉토리 리스트를 가져옴
directories=$(find "$base_directory" -type d -not -path "$current_directory")

# 각 디렉토리에 대해 명령어 실행
for dir in $directories; do
    echo "Executing '$command_to_execute' in $dir"
    (cd "$dir" && "$command_to_execute" && $command_to_execute2 )
done