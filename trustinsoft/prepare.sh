#!/bin/bash
############################################################################
#                                                                          #
#  This file is part of TrustInSoft Analyzer.                              #
#                                                                          #
#    Copyright (C) 2023-2024 TrustInSoft                                   #
#                                                                          #
#  All rights reserved.                                                    #
#                                                                          #
############################################################################

set -Eeuo pipefail

# This is the preparation script for this project: a user-editable script
# responsible for building the project, creating a compilation database, and
# generally preparing the project for analysis. Building a project is a
# necessary step prior to conducting analyses on it.
#
# You can execute this script from anywhere within the project through the
# command `tis prepare`. The script is always executed from the root of the
# project.
#
# This script is initially generated with `tis init`. The analyst should fill in
# the contents of the three sections below, as necessary:
#
# - Prepare dependencies
# - Configure the compilation
# - Compile and generate the compilation database
#
# The purpose of each section and typical steps and use cases for each of them
# are described in their respective comments.
#
# The instructions provided to this script are project-specific. Consult your
# project's documentation to learn how to configure and compile your project,
# and how to generate a `compile_commands.json` file for it. The TrustInSoft
# Documentation also provides a section on generating a `compile_commands.json`
# file with `bear`:
#
#   https://man.trust-in-soft.com/man/tis-user-guide/prepare.html#how-to-produce-a-compile-commands-json
#
# If `compile_commands.json` is compiled through a separate process or on a
# different host, leave the functions empty and include the externally generated
# `compile_commands.json` in the project, placing the file at path
# `trustinsoft/compile_commands.json`.
#
# If you cannot a generate a `compile_commands.json` file at all, consult the
# TrustInSoft Documentation to learn how to provide the necessary information
# manually:
#
#   https://man.trust-in-soft.com/man/tis-user-guide/prepare.html

################################################################################
# Prepare dependencies
#
# Download and prepare all the dependencies required by the project. For
# example: download the external libraries, clone submodules, install the
# compilers needed to compile your project.

echo "== Prepare dependencies =="

## Install a specific compiler
#sudo apt-get install arm-gcc

## Download some data
#wget data.company.com:/data.raw

## Download the source for the external libraries
#wget source.server.com:libpng.tgz
#tar zxvf libpng.tgz

## Other installation instructions as required by the project.


################################################################################
# Configure the compilation
#
# Configure the project itself. For example: generate header files required for
# the analysis.
#
# These configuration options impact the perimeter of your analysis. See the
# documentation:
#
#   https://man.trust-in-soft.com/man/tis-user-guide/perimeter.html

echo "== Configure project =="

## autoconf projects
#autoconf
#./configure --no-pthread CC=gcc


################################################################################
# Compile and generate the compilation database
#
# This step is dedicated to the compilation of the project itself (e.g.
# generates header files required for the analysis, ...).
# See
#
#   https://man.trust-in-soft.com/man/tis-user-guide/prepare.html#automatic-preparation

echo "== Compile project and generate database =="

# For makefile based projects.
#make clean # To generate the compilation_commands.json, the compilation must happen.
#bear --output trustinsoft/compile_commands.json -- make

# For CMake based projects
#cd trustinsoft && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..

# For custom compilation scripts
#bear --output trustinsoft/compile_commands.json -- ./compile.sh

# For Visual Studio or other IDE projects see [Doc]

# Run `tis prepare` to test this script and to confirm that
# `compilation_command.json` is successfully generated.
