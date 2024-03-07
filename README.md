# Parallel Programming Research Repository

Welcome to this repository! It's dedicated to advancing research in the field of parallel programming. For now, the primary languages used are C++ and Python, but there's always room for expansion. This repository is a work in progress, and it's a place for learning, experimenting, and growing.

## Parallel Programming: An Overview

Parallel programming is a type of computation in which many calculations or processes are carried out simultaneously. It's about doing lots of things at once, rather than one at a time. This field is particularly useful for tasks that can be broken down into independent subtasks.

One key aspect of parallel programming is the concept of threads. A thread is the smallest sequence of programmed instructions that can be managed independently by a scheduler. Handling exceptions in multithreaded code can be tricky, as exceptions are generally designed to be handled in a single-threaded context.

## Repository Structure

This repository is organized into three main directories: Ideas, Tasks, and Playground. Each directory has a specific purpose and contains different projects.

### Ideas Directory

The Ideas directory is where new concepts and algorithms are explored. It currently contains four projects:

1. **Odd-Even Sort**: This is a simple sorting algorithm, useful for parallel implementation.
2. **Mandelbrot Set**: This project involves generating and visualizing the Mandelbrot set, a complex fractal.
3. **N-Body Simulation**: This is a simulation of a system of particles, usually under the influence of physical forces like gravity.
4. **Heat Simulation**: This project simulates heat distribution across a 2D surface over time.

### Tasks Directory

The Tasks directory is where specific tasks and challenges are addressed. It contains implementations of the Merge Sort algorithm using different protocols (OMP, MPI, and sequential).

There are also additional tasks categorized by difficulty level:

- **MPI Tasks**: There are 15 tasks, plus an additional five that are considered hard level.
- **OMP Tasks**: This directory contains 15 tasks.

### Playground Directory

The Playground directory is a space for trying out new things without any specific goals. Currently, it contains several C++ projects, including:

- **Declare vs Define**: This project explores the difference between declaration and definition in C++.
- **SYCL Projects**: There are several projects exploring different aspects of SYCL (a high-level programming model for GPUs), including gpu2gpu, kokkos, sycl, template, nbody_multiplegpu, test_sycl4cuda_unnamedlambda, and usm_v_buffer.
- **Overall Template**: This project provides a general template for C++ projects.

## Note

This repository includes work from other contributors. Credits will be shared in the README files located in each directory and sub-directory.

## Useful Resources

- Parallel Programming in C++
- Introduction to Parallel Computing
- OpenMP Official Documentation
- MPI Official Documentation

Happy coding and exploring!
