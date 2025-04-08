#!/bin/bash

# シェルスクリプトの実行を中断しないように設定
set -e

# パッケージ管理ツールを特定する関数
identify_package_manager() {
    if command -v brew &> /dev/null; then
        echo "brew"
        return 0
    elif command -v apt-get &> /dev/null; then
        echo "apt-get"
        return 0
    elif command -v yum &> /dev/null; then
        echo "yum"
        return 0
    elif command -v dnf &> /dev/null; then
        echo "dnf"
        return 0
    elif command -v pacman &> /dev/null; then
        echo "pacman"
        return 0
    else
        echo "Unknown"
        return 1
    fi
}

# macOS (Homebrew) でライブラリのディレクトリを探す関数
find_lib_brew() {
    local lib_name="$1"
    local lib_dir
    local lib_path

    lib_path=$(brew ls googletest | grep "$lib_name")

    if [ -n "$lib_path" ]; then
        lib_dir=$(dirname "$lib_path")
        echo "$lib_name found in: $(realpath "$lib_dir")"
        echo "$(realpath "$lib_dir")"
        return 0
    else
        echo "Error: $lib_name not found by brew."
        return 1
    fi
}

# Debian/Ubuntu (apt) でライブラリのディレクトリを探す関数
find_lib_apt() {
    local lib_name="$1"
    local lib_path

    lib_path=$(dpkg -L libgtest-dev | grep "$lib_name")

    if [ -n "$lib_path" ]; then
        lib_dir=$(dirname "$lib_path")
        echo "$lib_name found in: $(realpath "$lib_dir")"
        echo "$(realpath "$lib_dir")"
        return 0
    else
        echo "Error: $lib_name not found by apt."
        return 1
    fi
}

# Fedora/CentOS/RHEL (yum/dnf) でライブラリのディレクトリを探す関数
find_lib_rpm() {
    local lib_name="$1"
    local lib_path

    if command -v dnf &> /dev/null; then
        lib_path=$(dnf -ql gtest-devel | grep "$lib_name")
    elif command -v yum &> /dev/null; then
        lib_path=$(yum -ql gtest-devel | grep "$lib_name")
    else
        echo "Error: Neither dnf nor yum found."
        return 1
    fi

    if [ -n "$lib_path" ]; then
        lib_dir=$(dirname "$lib_path")
        echo "$lib_name found in: $(realpath "$lib_dir")"
        echo "$(realpath "$lib_dir")"
        return 0
    else
        echo "Error: $lib_name not found by rpm."
        return 1
    fi
}

# メイン関数
main() {
    #local lib_names=("$1" "$2") # 探すライブラリ名を配列で定義
    local lib_names=("libgtest" "libgtest_main")
    local package_manager
    local lib_dir
    local i

    package_manager=$(identify_package_manager)

    if [ $? -ne 0 ]; then
        echo "Error: Could not identify package manager."
        return 1
    fi

    for i in "${lib_names[@]}"; do
        if [ "$package_manager" = "brew" ]; then
            find_lib_dir=$(find_lib_brew "$i")
        elif [ "$package_manager" = "apt-get" ]; then
            find_lib_dir=$(find_lib_apt "$i")
        elif [ "$package_manager" = "yum" ] || [ "$package_manager" = "dnf" ]; then
            find_lib_dir=$(find_lib_rpm "$i")
        else
            echo "Error: Unsupported package manager: $package_manager"
            return 1
        fi

        if [ $? -ne 0 ]; then
            return 1
        fi

        echo "Library directory: $find_lib_dir"
    done

    return 0
}

# スクリプトの実行例
#if [ $# -ne 2 ]; then
#    echo "Usage: $0 <lib_name1> <lib_name2>"
#    exit 1
#fi

#main "$1" "$2"
main

exit $?
