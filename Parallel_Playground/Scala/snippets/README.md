# Lectures Directory

This directory contains Scala code related to lectures and demonstrations.

## Files

- `TreeMap.scala`: This file defines a `Tree` data structure and provides functions to map over the tree sequentially and in parallel. It also includes a method to create a tree of a specified length and measures the time taken to map over the tree.

## Parallel Programming in Scala

Scala provides several ways to perform parallel programming. Some of the best packages to use for parallel programming tasks in Scala include:

- **Akka**: A powerful toolkit for building concurrent, distributed, and resilient message-driven applications.
- **Scala Parallel Collections**: Provides parallel versions of collections that can automatically parallelize operations.
- **Java Concurrency Utilities**: Scala can easily interoperate with Java, so using Java's `java.util.concurrent` package for concurrency tasks is also a common approach.

## Usage

To run the code in this directory and explore parallel programming in Scala, follow these steps:

1. Open a terminal and navigate to the `main/scala/lectures` directory.
2. Compile the code using the `sbt compile` command.
3. Run the `main` function in the `TreeMap` object by executing the `sbt run` command.
